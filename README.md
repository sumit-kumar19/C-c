# 🏆 Competitive Programming Solutions Showcase

A modern web application to showcase competitive programming solutions from LeetCode, Codeforces, and other platforms. This application transforms your collection of algorithm solutions into an interactive, searchable web interface.

![Screenshot](docs/screenshot.png)

## 🌟 Features

- **📊 Interactive Dashboard**: Browse all problems with search and filtering
- **💻 Syntax Highlighting**: Beautiful code display with Prism.js
- **📱 Responsive Design**: Works perfectly on desktop and mobile
- **🔍 Advanced Search**: Filter by difficulty, language, or problem name
- **📈 Statistics**: Overview of solved problems and languages used
- **🚀 Easy Deployment**: Docker and docker-compose ready

## 🏗️ Architecture

The application consists of:
- **Frontend**: Vanilla JavaScript SPA with modern CSS
- **Backend**: Node.js/Express API server
- **Data**: File system based (no database required)
- **Deployment**: Docker containers with optional Nginx proxy

## 📋 Prerequisites

- **Node.js** 16+ (for local development)
- **Docker** and **Docker Compose** (for deployment)
- Your competitive programming solutions organized in numbered directories

## 🚀 Quick Start

### Method 1: Docker Compose (Recommended)

1. **Clone and navigate to the repository**:
   ```bash
   git clone <your-repo>
   cd C-c
   ```

2. **Start the application**:
   ```bash
   docker-compose up -d
   ```

3. **Access the application**:
   - Open http://localhost:3000 in your browser
   - The app will automatically scan and load your solutions

### Method 2: Local Development

1. **Install dependencies**:
   ```bash
   npm install
   ```

2. **Start the development server**:
   ```bash
   npm run dev
   ```

3. **Open your browser**:
   - Navigate to http://localhost:3000

## 📁 Project Structure

```
C-c/
├── public/                 # Frontend assets
│   ├── index.html         # Main HTML file
│   ├── styles.css         # Styling
│   └── app.js            # Frontend JavaScript
├── server.js              # Backend server
├── package.json           # Node.js dependencies
├── Dockerfile            # Container definition
├── docker-compose.yml    # Multi-container setup
├── nginx.conf            # Reverse proxy config
├── 1-two-sum/            # Problem directory
│   ├── README.md         # Problem description
│   ├── two-sum.cpp       # C++ solution
│   └── two-sum.js        # JavaScript solution
├── 2741-function-composition/
│   ├── README.md
│   └── function-composition.js
└── ...                   # More problem directories
```

## 🔧 Configuration

### Environment Variables

Create a `.env` file for custom configuration:

```bash
# Server configuration
PORT=3000
NODE_ENV=production

# Optional: Add custom settings
MAX_UPLOAD_SIZE=10mb
RATE_LIMIT_REQUESTS=100
RATE_LIMIT_WINDOW=900000
```

### Problem Directory Format

The application expects problems in this format:
```
{number}-{problem-name}/
├── README.md           # Problem description (markdown)
├── solution.cpp        # C++ solution
└── solution.js         # JavaScript solution (optional)
```

Example: `2741-function-composition/`

## 🐳 Deployment Options

### Option 1: Simple Docker

```bash
# Build the image
docker build -t competitive-programming .

# Run the container
docker run -p 3000:3000 competitive-programming
```

### Option 2: Docker Compose (Development)

```bash
# Start the application
docker-compose up

# Run in background
docker-compose up -d

# Stop the application
docker-compose down
```

### Option 3: Docker Compose with Nginx (Production)

```bash
# Start with production profile
docker-compose --profile production up -d

# This includes:
# - Application server on port 3000
# - Nginx reverse proxy on port 80
# - Rate limiting and security headers
```

### Option 4: Cloud Deployment

#### Deploy to Railway

1. Connect your GitHub repository to Railway
2. Add environment variable: `PORT=3000`
3. Deploy automatically on push

#### Deploy to Heroku

```bash
# Install Heroku CLI and login
heroku login

# Create app
heroku create your-app-name

# Deploy
git push heroku main
```

#### Deploy to DigitalOcean App Platform

1. Create new app from GitHub repository
2. Set build command: `npm install`
3. Set run command: `npm start`
4. Deploy

## 🔒 Security Considerations

The application includes several security measures:

- **Rate limiting**: Prevents API abuse
- **Security headers**: CORS, XSS protection, etc.
- **Non-root user**: Docker container runs as non-privileged user
- **Input validation**: Prevents path traversal attacks
- **Health checks**: Monitor application status

## 📊 API Endpoints

| Endpoint | Method | Description |
|----------|--------|-------------|
| `/api/problems` | GET | List all problems |
| `/api/problems/:id/description` | GET | Get problem description |
| `/api/problems/:id/solution/:language` | GET | Get solution code |
| `/api/stats` | GET | Get repository statistics |
| `/api/health` | GET | Health check |

## 🛠️ Development

### Adding New Features

1. **Frontend changes**: Edit files in `public/`
2. **Backend changes**: Edit `server.js`
3. **Styling**: Update `public/styles.css`

### Local Development Setup

```bash
# Install dependencies
npm install

# Start development server with auto-reload
npm run dev

# The server will restart automatically when files change
```

### Adding New Problem Solutions

1. Create directory: `{number}-{name}/`
2. Add `README.md` with problem description
3. Add solution files (`.cpp`, `.js`, etc.)
4. Restart server to scan new problems

## 🔍 Troubleshooting

### Common Issues

**Port already in use**:
```bash
# Find and kill process using port 3000
lsof -ti:3000 | xargs kill -9
```

**Docker permission issues**:
```bash
# Add user to docker group
sudo usermod -aG docker $USER
# Log out and back in
```

**Problems not loading**:
- Check that problem directories follow the naming convention
- Ensure README.md files exist
- Check server logs: `docker-compose logs app`

### Logs and Debugging

```bash
# View application logs
docker-compose logs -f competitive-programming-app

# View nginx logs (if using production profile)
docker-compose logs -f nginx

# Debug mode (local development)
DEBUG=* npm run dev
```

## 📈 Performance Optimization

- **Static file caching**: Nginx serves static assets with long cache headers
- **Gzip compression**: Reduces bandwidth usage
- **CDN integration**: Use for Prism.js and other external assets
- **Image optimization**: Compress any screenshots or assets

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch: `git checkout -b feature-name`
3. Make changes and test
4. Commit: `git commit -m "Add feature"`
5. Push: `git push origin feature-name`
6. Create a Pull Request

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🆘 Support

- **Issues**: Report bugs or request features on GitHub Issues
- **Documentation**: Check this README and inline code comments
- **Community**: Discuss in GitHub Discussions

## 🚀 What's Next?

- [ ] Code execution sandbox for running solutions
- [ ] User authentication and personal dashboards
- [ ] Problem submission interface
- [ ] Integration with competitive programming platforms
- [ ] Advanced analytics and progress tracking
- [ ] Mobile app version

---

**Made with ❤️ for the competitive programming community**