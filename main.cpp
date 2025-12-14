#include "raylib.h"
#ifndef RAYMATH_H
#define RAYMATH_IMPLEMENTATION
#include "raymath.h"
#endif
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include <iostream>
#include <vector>
#include <stack>
#include <random>
#include <array>
#include <fstream>
#define hei 80
#define wei 80
using namespace std;
int level = 0;

namespace put_Chinese{
	int fileSize;
	unsigned char *fontFileData = LoadFileData("resource/LXGWWenKai-Regular.ttf", &fileSize);
	Image img=GenImageColor(800,600,WHITE);
	void ch_text(const char text[],Vector2 xy,float space,float size,Color color){//中文打印函数
		int codepointsCount;
		int *codepoints=LoadCodepoints(text,&codepointsCount);
		Font font = LoadFontFromMemory(".ttf",fontFileData,fileSize,32,codepoints,codepointsCount);
		UnloadCodepoints(codepoints);
		DrawTextEx(font,text,xy,size,space,color);
	}
}using put_Chinese::ch_text;

class maze {
	static const int N = 100;
	bool grid[N+5][N+5];
	
	Texture2D wall;
	bool flag;
	
	struct Region {
		int mnx, mny, mxx, mxy;
	};
	
	void init_grid() {
		stack<Region> st;
		st.push({1, 1, N, N});
		
		while (!st.empty()) {
			Region r = st.top();
			st.pop();
			
			int mnx = r.mnx, mny = r.mny, mxx = r.mxx, mxy = r.mxy;
			if (mxx - mnx < 2 || mxy - mny < 2) continue;
			
			int range_x = max(0, (mxx - mnx - 2) / 2);
			int range_y = max(0, (mxy - mny - 2) / 2);
			
			int spx = mnx + 2 + (range_x > 0 ? GetRandomValue(0, range_x) * 2 : 0);
			int spy = mny + 2 + (range_y > 0 ? GetRandomValue(0, range_y) * 2 : 0);
			
			spx = min(max(spx, mnx + 1), mxx - 1);
			spy = min(max(spy, mny + 1), mxy - 1);
			
			for (int i = mnx; i <= mxx; i++) {
				if (spy >= 1 && spy <= N && i >= 1 && i <= N) {
					grid[spy][i] = true;
				}
			}
			for (int i = mny; i <= mxy; i++) {
				if (spx >= 1 && spx <= N && i >= 1 && i <= N) {
					grid[i][spx] = true;
				}
			}
			
			if (mnx >= 1 && mny >= 1 && mxx <= N && mxy <= N && spx >= 1 && spx <= N && spy >= 1 && spy <= N) {
				mk_hole(mnx, mny, mxx, mxy, spx, spy);
			}
			
			if (spx - 1 > mnx && spy - 1 > mny)
				st.push({mnx, mny, spx - 1, spy - 1});
			if (mxx > spx + 1 && spy - 1 > mny)
				st.push({spx + 1, mny, mxx, spy - 1});
			if (spx - 1 > mnx && mxy > spy + 1)
				st.push({mnx, spy + 1, spx - 1, mxy});
			if (mxx > spx + 1 && mxy > spy + 1)
				st.push({spx + 1, spy + 1, mxx, mxy});
		}
	}
	
	void mk_hole(int mnx, int mny, 
		int mxx, int mxy, int spx, 
		int spy) {
			int r1 = max(0, spy - mny - 2);
			int r2 = max(0, mxy - spy - 2);
			int r3 = max(0, spx - mnx - 2);
			int r4 = max(0, mxx - spx - 2);
			
			int hole1_y = mny + 1 + (r1 > 0 ? GetRandomValue(0, r1) : 0);
			int hole2_y = spy + 1 + (r2 > 0 ? GetRandomValue(0, r2) : 0);
			int hole3_x = mnx + 1 + (r3 > 0 ? GetRandomValue(0, r3) : 0);
			int hole4_x = spx + 1 + (r4 > 0 ? GetRandomValue(0, r4) : 0);
			
			array<pair<int,int>, 4> hole = {
				pair<int,int>{spx, hole1_y},
				pair<int,int>{spx, hole2_y},
				pair<int,int>{hole3_x, spy},
				pair<int,int>{hole4_x, spy}
			};
			int keep = GetRandomValue(0, 3);
			for (int i = 0; i < 4; i++) {
				if (i != keep) {
					int x = hole[i].first;
					int y = hole[i].second;
					if (x >= 1 && x <= N && y >= 1 && y <= N) {
						grid[y][x] = false;
					}
				}
			}
		}
public:
	maze() {
		memset(grid, 0, sizeof(grid));
		for (int i = 1; i <= N; i++) {
			grid[1][i] = true;
			grid[N][i] = true;
			grid[i][1] = true; 
			grid[i][N] = true;
		}
		init_grid();
		flag = false;
		wall.id = 0;
	}
	
	void loadTexture() {
		flag = FileExists("resource/brik.png");
		if (flag) {
			wall = LoadTexture("resource/brik.png");
			if (wall.id == 0) flag = false;
		}
	}
	~maze() {
		if (flag && wall.id != 0) UnloadTexture(wall);
	}
	int size() {
		return N;
	}
	bool check(int x, int y) {
		if (x < 1 || x > N || y < 1 || y > N) return false;
		return !grid[y][x];
	}
	void draw() {
		for (int y = 1; y <= N; y++) {
			for (int x = 1; x <= N; x++) {
				if (grid[y][x]) {
					Rectangle rect = {
						(x - 1.0f) * 9.0f,
						(y - 1.0f) * 9.0f,
						9.0f,
						9.0f
					};
					if (flag && wall.id != 0) {
						DrawTexturePro(
							wall,
							(Rectangle){0, 0, (float)wall.width, (float)wall.height},
							rect,
							(Vector2){0, 0},
							0.0f,
							WHITE
							);
					} else {
						DrawRectangleRec(rect, BLACK);
					}
				}
			}
		}
	}
} mz;

bool win = false;
bool fail = false;
bool start = true;
class player {
public:
	Vector2 pos = {50.0f, 50.0f};
	float rad = 3.0f;
	
	void draw() {
		DrawCircle(pos.x * 9 - 4.5, pos.y * 9 - 4.5, rad, BLUE);
	}
	
	void update() {
		Vector2 newp = pos;
		float v = 0.05f;
		
		if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) {
			newp.y -= v;
		}
		if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) {
			newp.y += v;
		}
		if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) {
			newp.x -= v;
		}
		if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) {
			newp.x += v;
		}
		
		newp.x = max(1.1f, min((float)(mz.size() - 1) + 0.9f, newp.x));
		newp.y = max(1.1f, min((float)(mz.size() - 1) + 0.9f, newp.y));
		
		int stx = static_cast<int>(newp.x + 0.5f);
		int sty = static_cast<int>(newp.y + 0.5f);
		if (mz.check(stx, sty)) {
			pos = newp;
		}
	}
} p;

int head = 0;
int cnte = 0;
bool kill_mode = false;
class enemy {
public:
	Vector2 pos;
	float rad = 2.0f;
	bool die = false;
	double attackTime = 0.0;
	bool attack = false;
	bool success = false;
	double timer = 0.0;
	double moves = 0.0;
	int dir = 0;
	const int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	mt19937 rng;
	uniform_int_distribution<int> dist;
	enemy() {
		pos = {GetRandomValue(1, 10), GetRandomValue(1, 10)};
		random_device rd;
		rng = mt19937(rd());
		dist = uniform_int_distribution<int>(0, 3);
	}
	
	void draw() {
		if (die) return;
		DrawCircle(pos.x * 9 - 4.5, pos.y * 9 - 4.5, rad, RED);
		
		if (attack && !die) {
			ch_text("按空格反击！", {pos.x * 9 - 20, pos.y * 9 - 20}, 0, 10, YELLOW);
		}
	}
	
	void update() {
		if (die) return;
		if (success) {
			double tp = GetTime();
			if (tp - timer >= 1.0) {
				success = false;
			}
			return;
		}
		if (Vector2Distance(p.pos, pos) < 1.0f && !attack && !die && !success) {
			attack = true;
			attackTime = GetTime();
		}
		if (attack) {
			double tp = GetTime();
			double space = tp - attackTime;
			if (IsKeyPressed(KEY_SPACE)) {
				success = true;
				timer = GetTime();
				die = true;
				++ head;
				attack = false;
				return;
			}
			if (space >= 0.3) {
				if (kill_mode && head) {
					success = true;
					die = true;
					-- head;
					attack = false;
					return;
				} else {
					fail = true;
					attack = false;
					return;
				}
			}
		}
		if (die) return;
		Vector2 newp = pos;
		float v = 0.1f;
		if (moves >= 1e-8) {
			moves -= v;
			newp.x += dirs[dir][0] * v;
			newp.y += dirs[dir][1] * v;
		} else {
			int rnd = dist(rng);
			if (rnd == 0) {
				moves = 1;
				dir = 0;
			}
			if (rnd == 1) {
				moves = 1;
				dir = 1;
			}
			if (rnd == 2) {
				moves = 1;
				dir = 2;
			}
			if (rnd == 3) {
				moves = 1;
				dir = 3;
			}
		}
		newp.x = max(1.1f, min((float)(mz.size() - 1) + 0.9f, newp.x));
		newp.y = max(1.1f, min((float)(mz.size() - 1) + 0.9f, newp.y));
		int stx = static_cast<int>(newp.x + 0.5f);
		int sty = static_cast<int>(newp.y + 0.5f);
		if (mz.check(stx, sty)) {
			pos = newp;
		}
	}
};
vector<enemy> enm;

class Exit {
	Texture2D door;
	Texture2D arrow;
public:
	Vector2 pos;
	void rand_pos() {
		int mx;
		if (level == 0) mx = 10;
		else if (level == 1) mx = 20;
		else if (level == 2) mx = 40;
		else if (level == 3) mx = 60;
		else if (level == 4) mx = 80;
		else mx = mz.size();
		int mx2 = (mx / 2) * 2 - 1; 
		if (mx2 < 1) mx2 = 1;
		for (int i = 0; i < 100; i++) {
			int idx = GetRandomValue(0, (mx2 + 1) / 2 - 1);
			int idy = GetRandomValue(0, (mx2 + 1) / 2 - 1);
			int r_x = idx * 2 + 1;
			int r_y = idy * 2 + 1;
			if (r_x >= 1 && r_x <= mz.size() && r_y >= 1 && r_y <= mz.size()) {
				if (mz.check(r_x, r_y)) {
					pos = {(float)r_x, (float)r_y};
					return;
				}
			}
		}
		for (int y = 1; y <= mx; y++) {
			for (int x = 1; x <= mx; x++) {
				if (mz.check(x, y)) {
					pos = {(float)x, (float)y};
					return;
				}
			}
		}
		for (int y = 1; y <= mz.size(); y++) {
			for (int x = 1; x <= mz.size(); x++) {
				if (mz.check(x, y)) {
					pos = {(float)x, (float)y};
					return;
				}
			}
		}
		pos = {2.0f, 2.0f};
	}
	void loadTexure() {
		if (FileExists("resource/door.png")) {
			door = LoadTexture("resource/door.png");
		}
		
		if (FileExists("resource/arrow.png")) {
			arrow = LoadTexture("resource/arrow.png");
		} else {
			Image img = GenImageColor(32, 32, BLANK);
			for (int i = 0; i < 32; i++) {
				for (int j = 0; j < 32; j++) {
					if ((j >= 12 && j <= 20 && i >= 6) || 
						(i >= 22 && i <= 26 && j >= 10 && j <= 22)) {
						ImageDrawPixel(&img, j, i, RED);
					}
				}
			}
			arrow = LoadTextureFromImage(img);
			UnloadImage(img);
		}
	}
	void draw() {
		Rectangle rect = {
			(pos.x - 1.0f) * 9.0f,
			(pos.y - 1.0f) * 9.0f,
			9.0f,
			9.0f
		};
		
		DrawTexturePro(
			door,
			(Rectangle){0, 0, (float)door.width, (float)door.height},
			rect,
			(Vector2){0, 0},
			0.0f,
			DARKGREEN
			);
	}
	void drawArrow() {
		Vector2 dir = Vector2Subtract(pos, p.pos);
		if (Vector2Length(dir) < 0.1f) return;
		
		dir = Vector2Normalize(dir);
		float ang = atan2(dir.y, dir.x) * RAD2DEG;
		
		float cntx = hei * 1.5f;
		float cnty = wei * 1.5f;
		float dis = 50.0f;
		
		Vector2 apos = {
			cntx + dir.x * dis,
			cnty + dir.y * dis
		};
		
		Rectangle rect = {
			apos.x,
			apos.y,
			30.0f,
			30.0f
		};
		
		DrawTexturePro(
			arrow,
			(Rectangle){0, 0, (float)arrow.width, (float)arrow.height},
			rect,
			(Vector2){15.0f, 15.0f},
			ang,
			DARKGREEN
			);
	}
	bool check(Vector2 targ) {
		int cnt = 0;
		if (kill_mode) {
			for (enemy v : enm) {
				cnt += v.die;
			}
		}
		return Vector2Distance(targ, pos) < 0.5 || (cnt >= enm.size() && kill_mode);
	}
	
	~Exit() {
		if (door.id != 0) UnloadTexture(door);
		if (arrow.id != 0) UnloadTexture(arrow);
	}
} ext;

void readL() {
	ifstream ifs("resource/level.in");
	if (ifs) {
		ifs >> level;
	}
}

void writeL() {
	ofstream ofs("resource/level.in");
	if (ofs) {
		ofs << level;
	}
}

bool over = false;

void game() {
	SetRandomSeed(time(0));
	enm.push_back(enemy());
	enm.push_back(enemy());
	enm.push_back(enemy());
	InitWindow(hei * 3, wei * 3, "MAZE_PUZZLE");
	SetTargetFPS(60);
	readL();
	SetRandomSeed(level);
	
	maze tmpm;
	tmpm.loadTexture();
	Exit tmpe;
	SetRandomSeed(level);
	tmpe.loadTexure();
	mz = tmpm;
	ext = tmpe;
	
	bool flag = false;
	int stx = static_cast<int>(p.pos.x + 0.5f);
	int sty = static_cast<int>(p.pos.y + 0.5f);
	if (!mz.check(stx, sty)) {
		for (int y = 2; y < mz.size(); y++) {
			for (int x = 2; x < mz.size(); x++) {
				if (mz.check(x, y)) {
					p.pos = {(float)x + 0.5f, (float)y + 0.5f};
					flag = true;
					break;
				}
			}
			if (flag) break;
		}
	}
	if (!flag) {
		p.pos = {2.5f, 2.5f};
	}
	
	Camera2D cam = {0};
	cam.target = {p.pos.x * 9 - 4.5f, p.pos.y * 9 - 4.5f};
	cam.offset = {hei * 1.5f, wei * 1.5f};
	cam.zoom = 2.0f;
	ext.rand_pos();
	int times = 0;
	
	while (!WindowShouldClose()) {
		if (WindowShouldClose()) {
			if (start) {
				over = true;
				CloseWindow();
				exit(0);
			} else {
				start = true;
			}
		}
		cam.target = {p.pos.x * 9 - 4.5f, p.pos.y * 9 - 4.5f};
		
		BeginDrawing();
		ClearBackground(LIGHTGRAY);
		if (fail)
			ClearBackground(SKYBLUE);
		if (win)
			ClearBackground(GOLD);
		
		BeginMode2D(cam);
		mz.draw();
		p.draw();
		ext.draw();
		for (enemy& e : enm)
			e.draw();
		EndMode2D();
		
		string lv = "第" + to_string(level) + "关";
		ch_text(lv.c_str(), {10, 10}, 5.0, 20, DARKGREEN);
		if (!win && !fail && !start) {
			if (kill_mode) {
				ch_text("杀手模式 ", {10, 35}, 0, 18, RED);
				int deadCount = 0;
				for (enemy v : enm) {
					if (v.die) deadCount++;
				}
				string progress = "已击败: " + to_string(deadCount) + "/" + to_string(enm.size());
				ch_text(progress.c_str(), {10, 58}, 0, 16, ORANGE);
			}
			p.update();
			for (enemy& e : enm)
				e.update();
			ext.drawArrow();
		} else if (win) {
			ch_text("你赢了！", {hei * 1.5f - 60, wei * 1.5f - 60}, 2.0, 50, GREEN);
			if (IsKeyPressed(KEY_ENTER)) {
				win = false;
				fail = false;
				start = true;
				level++;
				writeL();
				break;
			}
		} else if (fail) {
			ch_text("你输了！", {hei * 1.5f - 60, wei * 1.5f - 60}, 2.0, 40, RED);
			if (IsKeyPressed(KEY_ENTER)) {
				win = false;
				fail = false;
				start = true;
				break;
			}
		}else if (start) {
			const char* title = "MazePuzzle";
			int titleX = hei * 1.5f - 120;
			int titleY = wei * 1.5f - 70;
			int titleSize = 40;
			DrawText(title, titleX + 4, titleY + 4, titleSize, GRAY);
			DrawText(title, titleX + 3, titleY + 3, titleSize, GRAY);
			DrawText(title, titleX + 2, titleY + 2, titleSize, LIGHTGRAY);
			DrawText(title, titleX + 1, titleY + 1, titleSize, LIGHTGRAY);
			DrawText(title, titleX, titleY, titleSize, WHITE);
			DrawText(title, titleX - 1, titleY - 1, titleSize, Fade(WHITE, 0.3f));
			DrawText("by slch", titleX + 60, titleY + 50, 12, YELLOW);
			ch_text("敌人数量   ", {hei * 1.5f - 120, wei * 1.5f + 20}, 0, 20, BLACK);
			static bool edit = false;
			Rectangle rect = { hei * 1.5f - 40, wei * 1.5f + 20, 100, 30 };
			if (GuiValueBox(rect, NULL, &cnte, 1, 10, edit)) {
				edit = !edit;
			}
			times %= 7;
			cam.rotation += 1.0f;
			const char* startPrompt = "按Enter开始 ";
			int promptSize = 20;
			int promptX = hei * 3 - MeasureText(startPrompt, promptSize) - 20;
			int promptY = wei * 3 - promptSize - 20;
			ch_text(startPrompt, Vector2{promptX, promptY}, 0, promptSize, MAROON);
			
			if (IsKeyPressed(KEY_ENTER)) {
				start = false;
				win = false;
				fail = false;
				enm.clear();
				for (int i = 0; i < cnte; i++) {
					enm.push_back(enemy());
				}
				cam.rotation = 0.0f;
				if (enm.size() >= 50)
					kill_mode = true;
			}
		} else if (IsKeyDown(KEY_E)) {
			exit(0);
		}
		if (ext.check(p.pos)) {
			win = true;
		}
		EndDrawing();
		if (WindowShouldClose()) {
			if (start) {
				over = true;
				CloseWindow();
				exit(0);
			} else {
				start = true;
			}
		}
	}
	
	CloseWindow();
	return;
}

int main() {
	while (1) {
		if (over)
			return 0;
		game();
	}
	return 0;
}
