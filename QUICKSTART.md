# 🚀 Quick Start Guide

Get your competitive programming solutions deployed in minutes!

## Instant Deployment (Recommended)

**Option 1: One-Click Docker Deployment**
```bash
# Clone the repository
git clone <your-repository-url>
cd C-c

# Deploy with our automated script
./deploy.sh docker
```

**Option 2: Docker Compose**
```bash
docker-compose up -d
```

## Your Application Will Include:

✅ **Interactive Web Interface** - Browse 39+ solved problems  
✅ **Search & Filter** - Find problems by difficulty, language, or number  
✅ **Syntax Highlighting** - Beautiful code display  
✅ **Mobile Responsive** - Works on all devices  
✅ **RESTful API** - Programmatic access to solutions  

## Access Your Deployed Application

Once deployed, open: **http://localhost:3000**

- 📊 **Dashboard**: View all problems and statistics
- 🔍 **Search**: Filter by Easy/Medium/Hard or C++/JavaScript  
- 👆 **Click any problem**: View description and solution code
- 📱 **Mobile-friendly**: Access from anywhere

## Deployment Options

| Method | Use Case | Command |
|--------|----------|---------|
| 🐳 Docker | Production ready | `./deploy.sh docker` |
| 🔧 Development | Local development | `./deploy.sh dev` |
| 🌐 Production | With Nginx proxy | `./deploy.sh production` |
| ☁️ Cloud | Deploy to cloud | Follow cloud-specific guides |

## Troubleshooting

**Container not starting?**
```bash
./deploy.sh logs
```

**Port already in use?**
```bash
./deploy.sh stop
./deploy.sh docker 8080  # Use different port
```

**Need to rebuild?**
```bash
docker-compose down
docker-compose up --build
```

## Next Steps

1. **Customize**: Edit `public/` files to modify the interface
2. **Add Problems**: Create new `{number}-{name}/` directories  
3. **Deploy to Cloud**: Use Railway, Heroku, or DigitalOcean
4. **Share**: Your solutions are now showcased professionally!

---

**Need help?** Check the full [README.md](README.md) for detailed documentation.