# FlappyBird

## Overview
A classic FlappyBird game implementation created as a test assignment. The project demonstrates core game mechanics, level generation, and scoring systems while showcasing clean architecture and efficient implementation.

## Features
- **Core Mechanics**: Smooth bird jump physics with realistic gravity
- **Obstacle System**: Dynamically generated pipes with adjustable difficulty
- **Death Handling**: Collision detection with appropriate game over sequence
- **Multi-Level Design**: Three distinct levels with increasing complexity
- **Score System**: Real-time score tracking and display
- **Procedural Generation**: Randomized level generation for unique gameplay sessions
- **Optimized Performance**: Efficient code implementation for smooth gameplay

## Technologies Used
- Unreal Engine 4.26.2
- C++
- Blueprint Visual Scripting
- Unreal Physics System

## Project Structure
The game follows a modular architecture with clear separation of concerns:
- Bird controller with physics implementation
- Obstacle generation system
- Level management
- Scoring mechanism
- Game state handling

## Build and Installation Instructions for Windows

### Prerequisites
1. **Unreal Engine 4.26.2**
   - Download and install the Epic Games Launcher from [Epic Games website](https://www.epicgames.com/store/en-US/download)
   - In the Epic Games Launcher, go to the Unreal Engine tab and install version 4.26.2

2. **Visual Studio 2019 with Build Tools**
   - Download and install Visual Studio 2019 from [Microsoft's website](https://visualstudio.microsoft.com/vs/older-downloads/)
   - During installation, select the "Game development with C++" workload
   - Make sure to include the Windows 10 SDK

### Development Setup
1. **Clone the repository**
   ```
   git clone https://github.com/yourusername/FlappyBird.git
   cd FlappyBird
   ```

2. **Generate Visual Studio project files**
   - Right-click on the FlappyBird.uproject file
   - Select "Generate Visual Studio project files"

3. **Build the solution**
   - Open the generated .sln file with Visual Studio 2019
   - Set the configuration to Development Editor and Win64
   - Build the solution (F7 or Ctrl+Shift+B)

### Running the Project
- Double-click the FlappyBird.uproject file to open the project in Unreal Engine Editor
- Press Play in the editor to test the game

### Quick Start (Pre-built Version)
For those who want to try the game without building from source:
- Download the pre-built version from [Google Drive](https://drive.google.com/drive/folders/1UcSbo_4KD3HGrhT1pZ7RK5S_7szMDJT_?usp=drive_link)
- Extract the archive
- Run the executable file

## Gameplay Instructions
- Press the spacebar or left mouse button to make the bird jump
- Navigate through the pipes to score points
- Avoid collisions with pipes and the ground
- Try to achieve the highest score possible

## Future Improvements
- Additional levels with unique themes
- Power-up system
- Difficulty settings
- Global leaderboard integration
- Mobile platform support
