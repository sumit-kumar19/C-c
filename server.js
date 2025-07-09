const express = require('express');
const cors = require('cors');
const fs = require('fs-extra');
const path = require('path');
const { marked } = require('marked');

const app = express();
const PORT = process.env.PORT || 3000;

// Middleware
app.use(cors());
app.use(express.json());
app.use(express.static('public'));

// Store for problems data
let problemsCache = null;

// Helper function to extract problem info from directory name
function parseProblemDirectory(dirName) {
    const match = dirName.match(/^(\d+)-(.+)$/);
    if (match) {
        return {
            number: match[1],
            title: match[2].split('-').map(word => 
                word.charAt(0).toUpperCase() + word.slice(1)
            ).join(' ')
        };
    }
    return null;
}

// Helper function to extract difficulty from README
function extractDifficultyFromReadme(readmeContent) {
    const easyMatch = readmeContent.match(/Difficulty-Easy-brightgreen/);
    const mediumMatch = readmeContent.match(/Difficulty-Medium-orange/);
    const hardMatch = readmeContent.match(/Difficulty-Hard-red/);
    
    if (easyMatch) return 'Easy';
    if (mediumMatch) return 'Medium';
    if (hardMatch) return 'Hard';
    return 'Unknown';
}

// Helper function to scan directory for problems
async function scanProblemsDirectory() {
    const problems = [];
    const rootDir = __dirname;
    
    try {
        const entries = await fs.readdir(rootDir, { withFileTypes: true });
        
        for (const entry of entries) {
            if (entry.isDirectory() && entry.name.match(/^\d+-/)) {
                const problemInfo = parseProblemDirectory(entry.name);
                if (!problemInfo) continue;
                
                const problemDir = path.join(rootDir, entry.name);
                const files = await fs.readdir(problemDir);
                
                // Find solution files
                const languages = [];
                const solutions = {};
                
                for (const file of files) {
                    if (file.endsWith('.cpp')) {
                        languages.push('cpp');
                        solutions.cpp = file;
                    } else if (file.endsWith('.js')) {
                        languages.push('js');
                        solutions.js = file;
                    }
                }
                
                // Extract difficulty from README if available
                let difficulty = 'Unknown';
                let description = `Problem ${problemInfo.number}: ${problemInfo.title}`;
                
                const readmePath = path.join(problemDir, 'README.md');
                if (await fs.pathExists(readmePath)) {
                    try {
                        const readmeContent = await fs.readFile(readmePath, 'utf-8');
                        difficulty = extractDifficultyFromReadme(readmeContent);
                        
                        // Extract description (first paragraph after title)
                        const lines = readmeContent.split('\n');
                        for (let i = 0; i < lines.length; i++) {
                            if (lines[i].includes('<p>') && !lines[i].includes('class="example"')) {
                                description = lines[i].replace(/<[^>]*>/g, '').trim();
                                break;
                            }
                        }
                    } catch (error) {
                        console.warn(`Error reading README for ${entry.name}:`, error.message);
                    }
                }
                
                if (languages.length > 0) {
                    problems.push({
                        id: entry.name,
                        number: problemInfo.number,
                        title: problemInfo.title,
                        difficulty,
                        languages,
                        solutions,
                        description
                    });
                }
            }
        }
        
        // Sort by problem number
        problems.sort((a, b) => parseInt(a.number) - parseInt(b.number));
        
    } catch (error) {
        console.error('Error scanning problems directory:', error);
    }
    
    return problems;
}

// Initialize problems cache
async function initializeProblems() {
    console.log('Scanning for problems...');
    problemsCache = await scanProblemsDirectory();
    console.log(`Found ${problemsCache.length} problems`);
}

// API Routes

// Get all problems
app.get('/api/problems', (req, res) => {
    res.json(problemsCache || []);
});

// Get problem description
app.get('/api/problems/:id/description', async (req, res) => {
    const { id } = req.params;
    const readmePath = path.join(__dirname, id, 'README.md');
    
    try {
        if (await fs.pathExists(readmePath)) {
            const readmeContent = await fs.readFile(readmePath, 'utf-8');
            
            // Convert markdown to HTML
            const htmlContent = marked(readmeContent);
            res.send(htmlContent);
        } else {
            res.status(404).send('<p>Problem description not found.</p>');
        }
    } catch (error) {
        console.error(`Error reading description for ${id}:`, error);
        res.status(500).send('<p>Error loading problem description.</p>');
    }
});

// Get solution code
app.get('/api/problems/:id/solution/:language', async (req, res) => {
    const { id, language } = req.params;
    
    try {
        const problem = problemsCache.find(p => p.id === id);
        if (!problem || !problem.solutions[language]) {
            return res.status(404).send('Solution not found');
        }
        
        const solutionPath = path.join(__dirname, id, problem.solutions[language]);
        
        if (await fs.pathExists(solutionPath)) {
            const solutionCode = await fs.readFile(solutionPath, 'utf-8');
            res.type('text/plain').send(solutionCode);
        } else {
            res.status(404).send('Solution file not found');
        }
    } catch (error) {
        console.error(`Error reading solution for ${id}/${language}:`, error);
        res.status(500).send('Error loading solution');
    }
});

// Compile and run C++ solution (optional feature)
app.post('/api/problems/:id/run/:language', async (req, res) => {
    const { id, language } = req.params;
    const { input } = req.body;
    
    if (language !== 'cpp') {
        return res.status(400).json({ error: 'Only C++ compilation is supported' });
    }
    
    try {
        const problem = problemsCache.find(p => p.id === id);
        if (!problem || !problem.solutions[language]) {
            return res.status(404).json({ error: 'Solution not found' });
        }
        
        // This is a basic implementation - in production, you'd want proper sandboxing
        // For now, we'll just return a placeholder response
        res.json({ 
            output: 'Code compilation and execution is not implemented in this demo.\nThis feature would require proper sandboxing for security.',
            error: null,
            executionTime: 0
        });
        
    } catch (error) {
        console.error(`Error running solution for ${id}/${language}:`, error);
        res.status(500).json({ error: 'Error executing solution' });
    }
});

// Get repository statistics
app.get('/api/stats', (req, res) => {
    const stats = {
        totalProblems: problemsCache.length,
        languageBreakdown: {},
        difficultyBreakdown: {},
        recentProblems: problemsCache.slice(-5)
    };
    
    problemsCache.forEach(problem => {
        // Count languages
        problem.languages.forEach(lang => {
            stats.languageBreakdown[lang] = (stats.languageBreakdown[lang] || 0) + 1;
        });
        
        // Count difficulties
        stats.difficultyBreakdown[problem.difficulty] = (stats.difficultyBreakdown[problem.difficulty] || 0) + 1;
    });
    
    res.json(stats);
});

// Health check endpoint
app.get('/api/health', (req, res) => {
    res.json({ 
        status: 'healthy', 
        timestamp: new Date().toISOString(),
        problems: problemsCache ? problemsCache.length : 0
    });
});

// Serve index.html for any non-API routes (SPA support)
app.get('*', (req, res) => {
    if (!req.url.startsWith('/api')) {
        res.sendFile(path.join(__dirname, 'public', 'index.html'));
    } else {
        res.status(404).json({ error: 'API endpoint not found' });
    }
});

// Error handling middleware
app.use((error, req, res, next) => {
    console.error('Server error:', error);
    res.status(500).json({ error: 'Internal server error' });
});

// Start server
async function startServer() {
    await initializeProblems();
    
    app.listen(PORT, () => {
        console.log(`🚀 Competitive Programming Showcase running on port ${PORT}`);
        console.log(`📊 Serving ${problemsCache.length} problems`);
        console.log(`🌐 Open http://localhost:${PORT} to view the application`);
    });
}

startServer().catch(error => {
    console.error('Failed to start server:', error);
    process.exit(1);
});