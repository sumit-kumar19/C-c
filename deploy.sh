#!/bin/bash

# Competitive Programming Solutions Deployment Script
# This script helps deploy the application in different environments

set -e

echo "🏆 Competitive Programming Solutions Deployment"
echo "================================================"

# Function to print colored output
print_status() {
    echo "✅ $1"
}

print_error() {
    echo "❌ $1"
    exit 1
}

print_info() {
    echo "ℹ️  $1"
}

# Check if Docker is available
if ! command -v docker &> /dev/null; then
    print_error "Docker is not installed. Please install Docker first."
fi

# Parse command line arguments
MODE=${1:-"development"}
PORT=${2:-3000}

print_info "Deployment mode: $MODE"
print_info "Port: $PORT"

case $MODE in
    "development"|"dev")
        print_info "Starting development environment..."
        
        # Check if Node.js is available for local development
        if command -v npm &> /dev/null; then
            print_status "Using local Node.js for development"
            npm install
            npm start
        else
            print_info "Node.js not found, using Docker for development"
            docker-compose up
        fi
        ;;
        
    "production"|"prod")
        print_info "Starting production environment with Docker..."
        
        # Build and start production environment
        docker-compose --profile production up -d
        
        # Wait for health check
        print_info "Waiting for application to be ready..."
        sleep 10
        
        # Test health endpoint
        if curl -f http://localhost:$PORT/api/health &> /dev/null; then
            print_status "Application is healthy and running on port $PORT"
            print_info "Access the application at: http://localhost:$PORT"
        else
            print_error "Application failed to start properly"
        fi
        ;;
        
    "docker")
        print_info "Starting with Docker (simple mode)..."
        
        # Build Docker image
        print_info "Building Docker image..."
        docker build -t competitive-programming .
        
        # Stop any existing container
        docker stop competitive-programming-container 2>/dev/null || true
        docker rm competitive-programming-container 2>/dev/null || true
        
        # Run container
        print_info "Starting container..."
        docker run -d \
            --name competitive-programming-container \
            -p $PORT:3000 \
            competitive-programming
        
        # Wait and test
        sleep 5
        if curl -f http://localhost:$PORT/api/health &> /dev/null; then
            print_status "Application is running on port $PORT"
            print_info "Access the application at: http://localhost:$PORT"
        else
            print_error "Application failed to start"
        fi
        ;;
        
    "stop")
        print_info "Stopping all services..."
        docker-compose down 2>/dev/null || true
        docker stop competitive-programming-container 2>/dev/null || true
        docker rm competitive-programming-container 2>/dev/null || true
        print_status "All services stopped"
        ;;
        
    "logs")
        print_info "Showing application logs..."
        docker-compose logs -f competitive-programming-app
        ;;
        
    "status")
        print_info "Checking application status..."
        
        # Check Docker containers
        docker ps --filter "name=competitive-programming" --format "table {{.Names}}\t{{.Status}}\t{{.Ports}}"
        
        # Test health if running
        if curl -f http://localhost:$PORT/api/health &> /dev/null; then
            print_status "Application is healthy"
        else
            print_info "Application is not responding on port $PORT"
        fi
        ;;
        
    "help"|"-h"|"--help")
        echo "Usage: $0 [MODE] [PORT]"
        echo ""
        echo "Modes:"
        echo "  development, dev  - Start in development mode (default)"
        echo "  production, prod  - Start with Docker + Nginx"
        echo "  docker           - Start with simple Docker setup"
        echo "  stop             - Stop all services"
        echo "  logs             - Show application logs"
        echo "  status           - Check application status"
        echo "  help             - Show this help message"
        echo ""
        echo "Examples:"
        echo "  $0 development"
        echo "  $0 production 8080"
        echo "  $0 docker 3000"
        echo "  $0 stop"
        ;;
        
    *)
        print_error "Unknown mode: $MODE. Use '$0 help' for usage information."
        ;;
esac