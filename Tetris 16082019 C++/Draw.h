void Draw()
{
	/*  DRAW MAP  */
	////////////////
	if (drawState == true)
	{
		Color(BLACK, WHITE);
		DrawHeader();
		Color(D_GREY, WHITE);
		for (int y = 3; y < roomHeight +roomYOffset + 1; y++)
		{
			if (y >= roomYOffset)
			{
				for (int x = 0; x < 17 + roomXOffset; x++)
				{
					//DRAW LINES
					if (x < roomXOffset) cout << " ";
					if ((x == 0 + roomXOffset) && (y < roomHeight + roomYOffset)) cout << lineVerticalChar;
					if ((x == 11 + roomXOffset) && ((y == 0 + roomYOffset) || (y == 5 + roomYOffset))) cout << (char)204;
					if ((x == 0 + roomXOffset) && (y == roomHeight + roomYOffset)) cout << cornerLowerLeftChar;
					if ((x == 11 + roomXOffset) && (y == roomHeight + roomYOffset)) cout << cornerLowerRightChar;
					if ((x > 11 + roomXOffset) && (x < 16 + roomXOffset) && ((y == 0 + roomYOffset) || (y == 5 + roomYOffset))) cout << lineHorizontalChar;
					if ((x == 16 + roomXOffset) && (y == 0 + roomYOffset)) cout << (char)187;
					if ((x == 16 + roomXOffset) && (y == 5 + roomYOffset)) cout << (char)188;
					if ((x > 0 + roomXOffset) && (x < 11 + roomXOffset) && (y == roomHeight + roomYOffset)) cout << lineHorizontalChar;

					//STATIC FIGURE COLOR
					if ((x > 0 + roomXOffset) && (x < 11 + roomXOffset) && (y < roomHeight + roomYOffset))
					{
						Color(BLACK, WHITE);
						if (xy[y - roomYOffset][x] != ' ')
						{
							if (xyColor[y - roomYOffset][x - 5] == '0')
							{
								/*
								if (currentFigure == 0)Color(D_CYAN, CYAN);
								if (currentFigure == 1)Color(D_BLUE, BLUE);
								if (currentFigure == 2)Color(D_YELLOW, YELLOW);
								if (currentFigure == 3)Color(YELLOW, CUSTOM);
								if (currentFigure == 4)Color(D_GREEN, GREEN);
								if (currentFigure == 5)Color(PURPLE, MAGENTA);
								if (currentFigure == 6)Color(D_RED, RED);*/
							}
							if (xyColor[y - roomYOffset][x - 5] == '1')Color(D_CYAN, CYAN);
							if (xyColor[y - roomYOffset][x - 5] == '2')Color(D_BLUE, BLUE);
							if (xyColor[y - roomYOffset][x - 5] == '3')Color(D_YELLOW, YELLOW);
							if (xyColor[y - roomYOffset][x - 5] == '4')Color(YELLOW, CUSTOM);
							if (xyColor[y - roomYOffset][x - 5] == '5')Color(D_GREEN, GREEN);
							if (xyColor[y - roomYOffset][x - 5] == '6')Color(PURPLE, MAGENTA);
							if (xyColor[y - roomYOffset][x - 5] == '7')Color(D_RED, RED);
							if (xyColor[y - roomYOffset][x - 5] == '8')Color(BLACK, WHITE);

							cout << xy[y - roomYOffset][x];
						}
						else cout << xy[y - roomYOffset][x];
					}
					if ((x == 11 + roomXOffset) && (y < roomHeight + roomYOffset) && (y != 0 + roomYOffset) && (y != 5 + roomYOffset)) cout << lineVerticalChar;
					if ((x == 16 + roomXOffset) && (y > 0 + roomYOffset) && (y < 5 + roomYOffset)) cout << lineVerticalChar;

					//DRAW RIGHT FIGURE BOX WITH COLORS 
					if ((x > 10 + roomXOffset) && (x < 15 + roomXOffset) && (y < 5 + roomYOffset) && (y > 0 + roomYOffset))
					{
						if (showFigure[y - 1 - roomYOffset][x - 11 - roomXOffset] == showFigureChar)
						{
							if (nextFigure == 0)Color(D_CYAN, CYAN);
							if (nextFigure == 1)Color(D_BLUE, BLUE);
							if (nextFigure == 2)Color(D_YELLOW, YELLOW);
							if (nextFigure == 3)Color(YELLOW, CUSTOM);
							if (nextFigure == 4)Color(D_GREEN, GREEN);
							if (nextFigure == 5)Color(PURPLE, MAGENTA);
							if (nextFigure == 6)Color(D_RED, RED);
							cout << showFigure[y - 1 - roomYOffset][x - 11 - roomXOffset];
						}
						else cout << showFigure[y - 1 - roomYOffset][x - 11 - roomXOffset];
					}
					Color(D_GREY, WHITE);
					if ((x == 11 + roomXOffset) && (y == 6 + roomYOffset)) cout << " NEXT";

					//DRAW STORE FIGURE
					if ((x == 11 + roomXOffset) && (y == 7 + roomYOffset)) cout << "S: ";

					switch (storeFigure) {
						case-1: Color(D_GREY, WHITE); if ((x == 11 + roomXOffset) && (y == 7 + roomYOffset)) cout << "  " ; break;
						case 0: Color(D_GREY, CYAN); if ((x == 11 + roomXOffset) && (y == 7 + roomYOffset)) cout << (char)179 << " "; break;
						case 1: Color(D_GREY, D_BLUE); if ((x == 11 + roomXOffset) && (y == 7 + roomYOffset)) cout << (char)192 << (char)196; break;
						case 2: Color(D_GREY, D_YELLOW); if ((x == 11 + roomXOffset) && (y == 7 + roomYOffset)) cout << (char)196 << (char)217; break;
						case 3: Color(D_GREY, YELLOW); if ((x == 11 + roomXOffset) && (y == 7 + roomYOffset)) cout << (char)219 << " "; break;
						case 4: Color(D_GREY, GREEN); if ((x == 11 + roomXOffset) && (y == 7 + roomYOffset)) cout << (char)218 << (char)217; break;
						case 5: Color(D_GREY, PURPLE); if ((x == 11 + roomXOffset) && (y == 7 + roomYOffset)) cout << char(180) << " "; break;
						case 6: Color(D_GREY, D_RED); if ((x == 11 + roomXOffset) && (y == 7 + roomYOffset)) cout << (char)192 << (char)191; break; 
					}   Color(D_GREY, WHITE);
				}
			} cout << endl; //ENDLINE
		}
		cout << "SCORE "; 
		if (tetrisScore > tetrisHighScore) Color(MAGENTA, CUSTOM);
		cout << scoreArray[0] << scoreArray[1] << scoreArray[2] << scoreArray[3] << scoreArray[4] << scoreArray[5] << scoreArray[6];
		Color(D_GREY, WHITE); cout << " ";
		for (int i = 1; i < 14; i++) 
		{
			if (scoreBonus == 1) Color(D_GREY, 15);
			else if (scoreBonus == BLACK) Color(D_GREY, 14);
			else if (scoreBonus == i) Color(D_GREY, i);
			else if (i < scoreBonus) Color(13, 11);
		}
		cout << scoreBonus << (char)158 << " " << endl;
		Color(D_GREY, WHITE);

		/*Color(BLACK, CUSTOM);
		//cout << "X: " << xF << "  Y: " << lineCount << "   ";
													  
		cout << "\nCheckState: " << collisionCheckLine << endl;
		Color(BLACK, WHITE);
		
		for (int y = 0; y < roomHeight + 4; y++)
		{
			for (int x = 0; x < 31; x++)
			{
				if (x < 10)
				{
					cout << xyColor[y][x];
				}
				if (x > 11)
				{
					cout << xy[y][x-11];
				}
			}
			cout << endl;
		}*/
	}
}



