#include "Functions.h"
#include "Figure.h"
#include "Draw.h"
#include "Input.h"
#include "Logic.h"

//MAIN LOOP
int main()
{
	/*Startup*/
	//soundPlay("music.wav");
	setFont(L"Terminal", 32, 32, false);
	ScreenSize(26, 22);
	//DisableFullScreen();
	Color(D_GREY, WHITE);
	ReplaceSymbol('#', blockChar);
	ShowConsoleCursor(false);
	UseDefaultCustomColorPalette();

	while (1)
	{
		system("cls");
		loseState = false;
		RandFigureStartUp();

		while (loseState == false)
		{	
			Input();
			Logic();
			Draw();
			startUp = false;
			downTimer -= 1;
		}
		SoundPlay("sound/timesup.wav");
		system("cls");
		ShowConsoleCursor(false);
		while (loseState == true) GameOver();
	}
}
