\# MazePuzzle - 迷宫冒险游戏



\*\*导航 / Navigation\*\*: \[English](#english) | \[中文](#中文)



---



\## English



\### 🎮 About The Game

\*\*MazePuzzle\*\* is a rogue-like maze adventure game built with \*\*Raylib\*\*. It features procedurally generated mazes, real-time enemy encounters, and a unique dual-gameplay system.



\### ✨ Key Features

\*   \*\*Procedural Generation\*\*: Every run creates a unique 100x100 maze using a recursive division algorithm.

\*   \*\*Dual Game Modes\*\*:

&nbsp;   \*   \*\*Stealth Mode\*\*: Avoid enemies and find the exit.

&nbsp;   \*   \*\*Killer Mode\*\* (unlocked with 50+ enemies): Eliminate all enemies to win.

\*   \*\*Quick-Time Combat\*\*: When an enemy catches you, press SPACE within 0.3 seconds to counterattack!

\*   \*\*Progressive Difficulty\*\*: 5 levels that affect exit placement and maze complexity.

\*   \*\*Scalable Challenge\*\*: The number of enemies is theoretically limited only by your system's memory, offering extreme challenges for powerful hardware \*(performance degrades with very high counts)\*.

\*   \*\*Localized UI\*\*: Chinese text display with fallback to English.



\### 🚀 Quick Start



\#### Prerequisites

\*   \*\*C++ Compiler\*\* (GCC, Clang, MSVC with MinGW)

\*   \*\*Raylib Development Library\*\*



\#### Installation \& Build



\*\*1. Install Raylib\*\*

\*   \*\*Ubuntu/Debian\*\*: `sudo apt install libraylib-dev`

\*   \*\*macOS\*\*: `brew install raylib`

\*   \*\*Windows\*\*: Download from \[Raylib Releases](https://github.com/raysan5/raylib/releases)

\*   \*\*All Platforms\*\*: See \[Official Raylib Installation](https://www.raylib.com/)



\*\*2. Clone \& Compile\*\*

```bash

\# Clone the repository

git clone https://github.com/your-username/MazePuzzle.git

cd MazePuzzle



\# Compile the game (Linux/macOS/Windows MinGW example)

g++ -o maze\_puzzle main.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11



\# Run the game

./maze\_puzzle

```

\*Note: Linker flags may vary slightly by system. Refer to Raylib documentation for your specific platform.\*



\#### 🎯 Basic Controls

\*   \*\*Movement\*\*: `WASD` or Arrow Keys

\*   \*\*Counterattack\*\*: `SPACE` (when prompted)

\*   \*\*Menu Navigation\*\*: `ENTER`, `ESCAPE`



\### 🧩 Project Structure

```

MazePuzzle/

├── main.cpp              # Main game source code

├── resource/             # Game assets (fonts, textures)

│   ├── LXGWWenKai-Light.ttf

│   ├── brik.png

│   ├── door.png

│   └── ...

├── README.md            # This file

└── LICENSE              # MIT License

```



\### 📄 License

This project is licensed under the \*\*MIT License\*\* - see the \[LICENSE](LICENSE) file for details.



\*\*Raylib\*\* is used under its own \[zlib/libpng license](https://github.com/raysan5/raylib/blob/master/LICENSE).



---



\## 中文



\### 🎮 游戏简介

\*\*MazePuzzle\*\* 是一款使用 \*\*Raylib\*\* 开发的Roguelike迷宫冒险游戏。游戏包含随机生成的迷宫、实时敌人遭遇战和独特的双模式玩法。



\### ✨ 核心特色

\*   \*\*随机迷宫生成\*\*：采用递归分割算法，每次游戏生成独一无二的100x100迷宫。

\*   \*\*双游戏模式\*\*：

&nbsp;   \*   \*\*潜行模式\*\*：躲避敌人，寻找出口。

&nbsp;   \*   \*\*杀手模式\*\*（敌人≥50时解锁）：击败所有敌人方可获胜。

\*   \*\*即时反击战斗\*\*：被敌人抓住时，在0.3秒内按下空格键进行反击！

\*   \*\*渐进难度\*\*：5个关卡等级，影响出口位置和迷宫复杂度。

\*   \*\*可扩展的挑战\*\*：敌人数量在理论上仅受系统内存限制，为追求极限的玩家提供了可能性（注意：数量极高时会导致性能下降）。

\*   \*\*本地化界面\*\*：支持中文显示，失败时自动回退到英文。



\### 🚀 快速开始



\#### 环境准备

\*   \*\*C++编译器\*\*（GCC、Clang 或带MinGW的MSVC）

\*   \*\*Raylib开发库\*\*



\#### 安装与编译



\*\*1. 安装Raylib\*\*

\*   \*\*Ubuntu/Debian\*\*: `sudo apt install libraylib-dev`

\*   \*\*macOS\*\*: `brew install raylib`

\*   \*\*Windows\*\*: 从 \[Raylib发布页面](https://github.com/raysan5/raylib/releases) 下载

\*   \*\*所有平台\*\*：参考 \[Raylib官方安装指南](https://www.raylib.com/)



\*\*2. 下载与编译\*\*

```bash

\# 克隆仓库

git clone https://github.com/your-username/MazePuzzle.git

cd MazePuzzle



\# 编译游戏（Linux/macOS/Windows MinGW示例）

g++ -o maze\_puzzle main.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11



\# 运行游戏

./maze\_puzzle

```

\*注意：链接器参数可能因系统略有不同，请根据你的平台参考Raylib文档。\*



\#### 🎯 基本操作

\*   \*\*移动\*\*：`WASD` 或 方向键

\*   \*\*反击\*\*：`空格键`（当提示出现时）

\*   \*\*菜单导航\*\*：`回车键`，`ESC键`



\### 🧩 项目结构

```

MazePuzzle/

├── main.cpp              # 游戏主源代码

├── resource/             # 游戏资源（字体、纹理）

│   ├── LXGWWenKai-Light.ttf

│   ├── brik.png

│   ├── door.png

│   └── ...

├── README.md            # 本文件

└── LICENSE              # MIT 许可证

```



\### 🤝 参与贡献

欢迎提交 Issue 和 Pull Request！

1\.  Fork 本仓库

2\.  创建功能分支 (`git checkout -b feature/AmazingFeature`)

3\.  提交更改 (`git commit -m 'Add some AmazingFeature'`)

4\.  推送到分支 (`git push origin feature/AmazingFeature`)

5\.  开启一个 Pull Request



\### 📄 许可证

本项目采用 \*\*MIT 许可证\*\* - 查看 \[LICENSE](LICENSE) 文件了解详情。



\*\*Raylib\*\* 在其自身的 \[zlib/libpng 许可证](https://github.com/raysan5/raylib/blob/master/LICENSE) 下使用。



\### ❓ 常见问题

\*\*Q：编译时提示“找不到 -lraylib”怎么办？\*\*  

A：这表示Raylib未正确安装。请确保完全按照官方指南为你操作系统完成了安装。



\*\*Q：字体显示为方块或乱码？\*\*  

A：确保 `resource/` 文件夹包含 `LXGWWenKai-Light.ttf` 字体文件。如果缺失，游戏将自动回退到系统默认字体。



\*\*Q：如何选择敌人数量？\*\*  

A：在游戏开始菜单中，使用方向键或鼠标调整“敌人数量”选框（1-10个）。



\*\*Q：游戏最多能设置多少个敌人？会很卡吗？\*\*  

A：从代码逻辑上讲，敌人数量可以达到C++ `int` 类型的上限（约21亿），但这只是一个理论值。实际上，当敌人数量过多（例如超过100个）时，会显著增加CPU和内存负担，导致游戏帧率下降。建议根据自己电脑的性能，在开始菜单中设置一个合理的数量（通常10-50个）以获得流畅体验。



---



\*\*祝你在迷宫中冒险愉快！\*\* 🎮



\[返回顶部 ↑](#mazepuzzle---迷宫冒险游戏)

