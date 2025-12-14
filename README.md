# MazePuzzle - 迷宫冒险游戏
**导航 / Navigation**: [English](#english) | [中文](#中文)

---

## English

### 🎮 Game Introduction

Welcome to MazePuzzle! This game has been in development for nearly 1-2 months and features a level system, an enemy system, and dual modes: Stealth and Killer. The maze is procedurally generated using a recursive division algorithm.

The initial development and iterations of this project were primarily conducted within the Luogu team [MOLI Game Studio](https://luogu.com.cn). Future updates will also be prioritized and synchronized there first. You're welcome to join the team for early access.

### 🖥️ Start Menu

As shown below:

![](https://img.cdn1.vip/i/693e76154e87a_1765701141.webp)

The design draws inspiration from **Minecraft**, featuring a rotating level background and a pseudo-3D title. The yellow text "by asd3494" is displayed below. The input box next to "敌人数量" (Enemy Count) allows you to set the number of enemies, defaulting to `1`. Press Enter when ready to begin.

**Note**: Closing the window from the start menu will exit the application directly.

### 🎯 In-Game

#### Modes

##### 🚶‍♂️ Stealth Mode
The standard gameplay mode. Your objective is to locate the exit and reach it. An on-screen arrow constantly points toward the exit, serving as your guide.

##### 🔪 Killer Mode
**Trigger Condition**: Number of enemies **≥ 50**

Screenshot:

![](https://img.cdn1.vip/i/693e7767cfe63_1765701479.png)

You can win by either defeating all enemies or meeting the Stealth Mode victory condition. Additionally, each enemy you defeat manually grants you one "auto-defeat" charge. This charge is consumed only if you fail a counter-attack against an enemy.

#### ☠️ Enemies

Enemies are hostile entities in the game. Some lie in wait within walls, attacking as you pass by, while others roam randomly until you get too close.

They appear as red circles slightly smaller than your character:

![](https://img.cdn1.vip/i/693e7bf00ff55_1765702640.png)

They initiate an attack when you come within a distance of 1.0 unit. The attack has a 0.3-second wind-up period, during which you can press the **SPACE** bar to counter-attack. Here is how they look when attacking:

![](https://img.cdn1.vip/i/693c09514e035_1765542225.png)

Pressing SPACE successfully will defeat all enemies currently attacking you. However, if an enemy completes its attack and damages you, it's fatal, and you will lose the game immediately.

## 🚀 Quick Start

This game is built using **Raylib**. If you haven't installed it yet, follow the instructions below:

### Installing Raylib

*   **Linux (Ubuntu/Debian)**:
    ```bash
    sudo apt install libraylib-dev
    ```
*   **macOS**:
    First, ensure you have [Homebrew](https://brew.sh/) installed. Then run:
    ```bash
    brew install raylib
    ```
*   **Windows & Others**:
    1.  Go to the [Raylib Releases page](https://github.com/raysan5/raylib/releases).
    2.  Download the pre-compiled library package for your system (e.g., `raylib-x.x.x_win64_mingw-w64.zip` for Windows).

Alternatively, you can use the **RedPanda Dev C++** IDE, which comes with Raylib pre-configured.
1.  [Download RedPanda Dev C++](https://wwe.lanzoui.com/b01os0mwd).
2.  Open the project file with this IDE to compile and run.

**Compiler**: GCC, Clang, or MSVC with the GCC toolchain should work.

**Before you start playing, please read the `MazePuzzle食用指南.pdf` file included in the project for detailed gameplay instructions and controls.**

## 🤝 Contributing

If you discover any bugs, please feel free to [submit an issue](https://github.com/你的用户名/MazePuzzle/issues)!

We also welcome suggestions related to gameplay, features, or improvements.

Let's make MazePuzzle better together!

---

## 中文

欢迎你浏览迷宫冒险游戏(`MazePuzzle`)！

## 🎮游戏介绍

这个游戏开发历程将近1~2个月，包含关卡系统、敌人系统、潜伏/杀手双模式。采用递归分割法生成迷宫。游戏由我自己本人完成。此游戏之前的开发和迭代均在Luogu团队[MOLI摸鱼游戏公司](https://luogu.com.cn)中实现，之后的项目也会优先同步在此团队，如果想尽快尝试可以加入。

### 开始页面

如图：

![](https://img.cdn1.vip/i/693e76154e87a_1765701141.webp)

这里的设计参考了**Minecraft**，用旋转的关卡背景+伪3D标题，下方有用黄字标注的**by asd3494**，同时，“敌人数量”后面的输入框是用来设定敌人数的。默认值为`1`，当你确认无误想要开始时按下Enter即可。

在开始页面退出窗口会直接退出。

### 游戏中

#### 模式

##### 🚶‍♂️潜行模式

一般的游玩模式，你需要找到出口并走到那里，在游玩时会有一个箭头时刻指向出口，你可以以此做参照。

##### 🔪杀手模式

触发条件：**敌人数≥50**

图片

![](https://img.cdn1.vip/i/693e7767cfe63_1765701479.png)

击败所有敌人或者达成潜伏模式的通关条件都可以通关。同时你每手动击败一个敌人都会赠送一个自动击败敌人的机会，但这次机会只会在你反击失败的时候消耗。

#### ☠️敌人

敌人在这个游戏里是一种敌对实体，它们有的会一直潜伏在墙里等待你经过的时候把你干掉，有的会在地图中随机游荡直到你与它距离过近。

它的外貌为一个比你的角色稍小的红色小球，如图：

![](https://img.cdn1.vip/i/693e7bf00ff55_1765702640.png)

当你与它的距离不足1时它们会对你发动攻击，但它们攻击从开始到完成需要0.3s的时间，在此期间你可以按空格反击它们，如下是它们攻击时的样子：

![](https://img.cdn1.vip/i/693c09514e035_1765542225.png)

按下空格后，所有正在攻击你的敌人就会倒下。但如果它们已经伤害到了你，那是致命的，你会直接输掉整局游戏。

## 🎗️提示

这个游戏是基于RayLib的，如果你还没有这个库。那么你可以按照如下方式安装：

如果你是Linux及其衍生系统用户，那么如下输入如下命令可以下载：
```bash
sudo apt install libraylib-dev
```

如果你是MacOS用户，你必须先安装Homebrew，然后输入如下命令
```command
brew install raylib
```

如果你是Windows用户或其它，那么按照如下方式下载：

1. [进入此链接](https://github.com/raysan5/raylib/releases)
2. 选择一个你喜欢的版本下载。

或者你可以使用RedPandaDevC++这个IDE来运行，它自带RayLib。

1. [前往此处下载](https://wwe.lanzoui.com/b01os0mwd)
2. 用它打开此文件即可运行

对于编译器，GCC、Clang或者带GCC的MSVC都可以。

**在开始游玩前，请务必阅读项目内的 `MazePuzzle食用指南.pdf` 文件，以了解具体的操作方法和游玩指南。**

如果你发现了Bug，欢迎提交issue！

也可以提一些游戏相关的建议。

让我们把MazePuzzle变得越来越好！
