#include <iostream>
#include <ctime> 
#include <Windows.h>

#define D_GREY 0
#define D_BLUE 1
#define D_GREEN 2
#define D_CYAN 3
#define D_RED 4
#define PURPLE 5
#define D_YELLOW 6
#define BLACK 7
#define CUSTOM 8
#define BLUE 9
#define GREEN 10
#define CYAN 11
#define RED 12
#define MAGENTA 13
#define YELLOW 14
#define WHITE 15

using namespace std;

const char cornerUpperLeftChar = 201;
const char cornerUpperRightChar = 187;
const char cornerLowerLeftChar = 200;
const char cornerLowerRightChar = 188;
const char lineHorizontalChar = 205;
const char lineVerticalChar = 186;
const char tLowerChar = 203;
const char tUpperChar = 202;
const char tLeftChar = 204;
const char tRightChar = 185;
const char tMiddleChar = 206;
const char blockChar = 176;
const char blockStaticChar = 254;
const char showFigureChar = 254;

bool drawState = true;
bool startUp = true;
bool loseState = false;
bool enterState = false;
bool enableLeftState = true;
bool enableRightState = true;
bool checkUpState = false;
bool checkLeftState = false;
bool checkRightState = false;
bool bonusGetState = false;

int roatateFigure = 0; //0 = .|, 1 = _, 2 = |., 3 = ¯

const int roomHeight = 18;

//Arays
char showFigure[4][4];
int scoreArray[7];
char xyColor[10][roomHeight + 8];
char xy[20][roomHeight + 8];

int collisionCheckLine = 0;
int collisionOutOfRoomCheckLine = 0;
int tetrisHighScore = 1;
int tetrisScore = 0;
int scoreBonus = 1;
int lineCount = 5;
int currentFigure = 0;
int oldCurrentFigure = -1;
int nextFigure = 1;
int storeFigure = -1;

int xF = 8;
int yF = -3;
int fontSize = 32;
int roomXOffset = 4;
int roomYOffset = 4;

int downTimer = 30000;
int resetTimer = 30000;



void Gotoxy(int x, int y)
{
	COORD p = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void UseDefaultCustomColorPalette()
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFOEX csbiInfo;
	csbiInfo.cbSize = sizeof(csbiInfo);
	GetConsoleScreenBufferInfoEx(hStdout, &csbiInfo);
	csbiInfo.ColorTable[0] = RGB(16, 16, 16);
	csbiInfo.ColorTable[1] = RGB(0, 55, 218);
	csbiInfo.ColorTable[2] = RGB(19, 161, 14);
	csbiInfo.ColorTable[3] = RGB(58, 150, 221);
	csbiInfo.ColorTable[4] = RGB(197, 15, 31);
	csbiInfo.ColorTable[5] = RGB(128, 0, 160);
	csbiInfo.ColorTable[6] = RGB(217, 140, 0);
	csbiInfo.ColorTable[7] = RGB(0, 0, 0);
	csbiInfo.ColorTable[8] = RGB(255, 255, 0);
	csbiInfo.ColorTable[9] = RGB(59, 120, 255);
	csbiInfo.ColorTable[10] = RGB(0, 224, 0);
	csbiInfo.ColorTable[11] = RGB(97, 214, 214);
	csbiInfo.ColorTable[12] = RGB(231, 72, 86);
	csbiInfo.ColorTable[13] = RGB(224, 0, 192);
	csbiInfo.ColorTable[14] = RGB(225, 200, 0);
	csbiInfo.ColorTable[15] = RGB(255, 255, 255);
	SetConsoleScreenBufferInfoEx(hStdout, &csbiInfo);
}

void DisableFullScreen()
{
	HWND hwnd = GetConsoleWindow();
	DWORD style = GetWindowLong(hwnd, GWL_STYLE);
	style &= ~WS_MAXIMIZEBOX;
	SetWindowLong(hwnd, GWL_STYLE, style);
	SetWindowPos(hwnd, NULL, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOMOVE | SWP_FRAMECHANGED);
}

void Color(byte background, byte color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //Handle Color
	byte backgroundColor = 0;
	byte backCol = 0;
	for (byte i = 0; i < 16; i++)
	{
		backgroundColor = i * 16;
		if (background == i) backCol = backgroundColor + color;
	}
	SetConsoleTextAttribute(hConsole, backCol);
}

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

void setFont(const wchar_t* fontType, int sizeX, int sizeY, bool boldState)
{
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = sizeX;
	cfi.dwFontSize.Y = sizeY;
	cfi.FontFamily = FF_DONTCARE;
	if (boldState == true) cfi.FontWeight = FW_BOLD;
	wcscpy_s(cfi.FaceName, fontType);
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

void ScreenSize(int x, int y) {

	COORD coord;
	coord.X = x;
	coord.Y = y+4;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = x - 1;
	Rect.Right = y - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(Handle, coord);
	SetConsoleWindowInfo(Handle, TRUE, &Rect);
}

void UpdateScreen()
{
	ShowConsoleCursor(false);
	Gotoxy(0, 0);
	drawState = true;
}

void delay(int milliseconds)
{
	Sleep(milliseconds);
}

void SoundPlay(const char* sound)
{
	PlaySound(TEXT(sound), NULL, SND_ASYNC);
}

void RandFigure()
{
	srand(time(NULL));
	int figureRand;
	figureRand = (rand() % 7);

	currentFigure = nextFigure;
	nextFigure = figureRand;
}

void RandFigureStartUp()
{
	srand(time(NULL));
	int figureRand1;
	int figureRand2;
	figureRand1 = (rand() % 7);
	figureRand2 = (rand() % 7);

	currentFigure = figureRand1;
	nextFigure = figureRand2;
}

void Static()
{
	for (int y = 0; y < roomHeight; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			if (xy[y][x + 5] == blockChar)
			{
				//SETS A COLORNUMBER TO THE COLOR ARRAY
				for (int asciiTal = 49; asciiTal < 56; asciiTal++)
				{
					if (currentFigure == asciiTal - 49) xyColor[y][x] = (char)asciiTal;
				}
			}

			if (xy[y][x] == blockChar)
			{
				//CHANGES HERE TO STATIC
				xy[y][x] = blockStaticChar;
				UpdateScreen();
				yF = -3;
				xF = 8;
			}
		}
		UpdateScreen();
	}
	SoundPlay("sound/harddrop.wav");

	if ((scoreBonus > 1) && (bonusGetState == false)) scoreBonus -= 1;
	bonusGetState = false;

	//Gives a random figrue
	RandFigure();
	enterState = false;
}

void Collision(int x1, int y1, int x2, int y2, int lOrR)
{
	for (int y = 0; y < roomHeight; y++)
	{
		for (int x = 0; x < 20; x++)
		{
			if ((xy[y][x] == blockChar) && (lOrR == -1) && (xy[y + y1][x + x1] == blockStaticChar)) { xF += x2; yF += y2; Static(); }
			if ((xy[y][x] == blockChar) && (lOrR == 0) && (xy[y + y1][x + x1] == blockStaticChar)) { enableLeftState = false; }
			if ((xy[y][x] == blockChar) && (lOrR == 1) && (xy[y + y1][x + x1] == blockStaticChar)) { enableRightState = false; }
		}
	}
}

void ScoreBoard()
{
	/* Update Scoreboard */
	scoreArray[6] = tetrisScore % 10;
	scoreArray[5] = tetrisScore / 10 % 10;
	scoreArray[4] = tetrisScore / 100 % 10;
	scoreArray[3] = tetrisScore / 1000 % 10;
	scoreArray[2] = tetrisScore / 10000 % 10;
	scoreArray[1] = tetrisScore / 100000 % 10;
	scoreArray[0] = tetrisScore / 1000000 % 10;
}

void DrawHeader()
{
	for (int y = 0; y < 3; y++)
	{
		if (y == 0)
		{
			Color(D_GREY, CYAN); cout << "  " << (char)218 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)180;
			Color(D_GREY, CUSTOM); cout << "C++";
			Color(D_GREY, CYAN); cout << (char)195 << (char)196 << (char)196 << (char)196 << (char)196 << (char)196 << (char)191;
		}
		if (y == 1)
		{
			Color(D_GREY, CYAN); cout << " " << (char)196 << (char)180;
			Color(D_GREY, BLUE); cout << "  T";
			Color(D_GREY, D_YELLOW); cout << "E";
			Color(D_GREY, YELLOW); cout << "T";
			Color(D_GREY, GREEN); cout << "R";
			Color(D_GREY, MAGENTA); cout << "I";
			Color(D_GREY, D_RED); cout << "S";
			Color(D_GREY, WHITE); cout << " v1.1b ";
			Color(D_GREY, CYAN); cout << (char)195 << (char)196;
		}
		if (y == 2)
		{
			Color(D_GREY, CYAN); cout << "  " << (char)192 << "console-edition" << (char)217;
			Color(D_GREY, WHITE);
		}
		cout << endl;
	}
}

