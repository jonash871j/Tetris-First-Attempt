/*  GAME LOGIC  */
//////////////////

void Logic()
{
	if (startUp == true) tetrisScore = 0;
	ScoreBoard();

	/*IF FIGURE CLIPS OUT OF ROOM, WHILE ROATATING*/
	for (int checkY = 0; checkY < roomHeight; checkY++)
	{
		if (xy[checkY][13 + roomXOffset] == blockChar) collisionOutOfRoomCheckLine = 3;
		else if (xy[checkY][12 + roomXOffset] == blockChar) collisionOutOfRoomCheckLine = 2;
		else if (xy[checkY][11 + roomXOffset] == blockChar) collisionOutOfRoomCheckLine = 1;
		else if (xy[checkY][-2 + roomXOffset] == blockChar) collisionOutOfRoomCheckLine = -3;
		else if (xy[checkY][-1 + roomXOffset] == blockChar) collisionOutOfRoomCheckLine = -2;
		else if (xy[checkY][0 + roomXOffset] == blockChar) collisionOutOfRoomCheckLine = -1;

		xy[checkY][0 + roomXOffset] = ' ';
		xy[checkY][-1 + roomXOffset] = ' ';
		xy[checkY][-2 + roomXOffset] = ' ';
		xy[checkY][11 + roomXOffset] = ' ';
		xy[checkY][12 + roomXOffset] = ' ';
		xy[checkY][13 + roomXOffset] = ' ';
	}
	if (collisionOutOfRoomCheckLine == -3) { xF += 3; collisionOutOfRoomCheckLine = 0; UpdateScreen(); }
	if (collisionOutOfRoomCheckLine == -2) { xF += 2; collisionOutOfRoomCheckLine = 0; UpdateScreen(); }
	if (collisionOutOfRoomCheckLine == -1) { xF += 1; collisionOutOfRoomCheckLine = 0; UpdateScreen(); }
	if (collisionOutOfRoomCheckLine == 1) { xF -= 1; collisionOutOfRoomCheckLine = 0; UpdateScreen(); }
	if (collisionOutOfRoomCheckLine == 2) { xF -= 2; collisionOutOfRoomCheckLine = 0; UpdateScreen(); }
	if (collisionOutOfRoomCheckLine == 3) { xF -= 3; collisionOutOfRoomCheckLine = 0; UpdateScreen(); }

	/*CHECK IF FIGURE IS AT THE BUTTOM*/
	if (downTimer <= 0)
	{
		for (int y = 0; y < roomHeight-1; y++)
		{
			for (int x = 0; x < 15; x++)
			{
				if (xy[roomHeight-1][x] == blockChar) Static();
			}
		}
		downTimer = resetTimer;
	}

	if (drawState == true)
	{
		/*UPDATE MAIN 2D ARRAY*/
		for (int y = 0; y < roomHeight; y++)
		{
			for (int x = 0; x < 15; x++)
			{
				if (xy[y][x] != blockStaticChar) xy[y][x] = ' ';
				if ((startUp == true) && (x < 10)) xyColor[y][x] = '0';
			}
		}


		/*UPDATE MAIN 2D ARRAY WITH 2D FIGURE*/
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				//FIGRUE BOX TO THE RIGHT
				if (nextFigure == 0) showFigure[i][j] = T01_F01[i][j];
				if (nextFigure == 1) showFigure[i][j] = T02_F01[i][j];
				if (nextFigure == 2) showFigure[i][j] = T03_F01[i][j];
				if (nextFigure == 3) showFigure[i][j] = T04_F01[i][j];
				if (nextFigure == 4) showFigure[i][j] = T05_F02[i][j];
				if (nextFigure == 5) showFigure[i][j] = T06_F04[i][j];
				if (nextFigure == 6) showFigure[i][j] = T07_F02[i][j];


				if (showFigure[i][j] == blockChar) showFigure[i][j] = showFigureChar;

				//UPDATE MAIN 2D ARRAY
				if (xy[i + yF][j + xF] != blockStaticChar)
				{
					switch (currentFigure)
					{
					case 0:
						if (roatateFigure == 0) xy[i + yF][j + xF] = T01_F01[i][j];
						if (roatateFigure == 1) xy[i + yF][j + xF] = T01_F02[i][j];
						if (roatateFigure == 2) xy[i + yF][j + xF] = T01_F03[i][j];
						if (roatateFigure == 3) xy[i + yF][j + xF] = T01_F04[i][j];
						break;
					case 1:
						if (roatateFigure == 0) xy[i + yF][j + xF] = T02_F01[i][j];
						if (roatateFigure == 1) xy[i + yF][j + xF] = T02_F02[i][j];
						if (roatateFigure == 2) xy[i + yF][j + xF] = T02_F03[i][j];
						if (roatateFigure == 3) xy[i + yF][j + xF] = T02_F04[i][j];
						break;
					case 2:
						if (roatateFigure == 0) xy[i + yF][j + xF] = T03_F01[i][j];
						if (roatateFigure == 1) xy[i + yF][j + xF] = T03_F02[i][j];
						if (roatateFigure == 2) xy[i + yF][j + xF] = T03_F03[i][j];
						if (roatateFigure == 3) xy[i + yF][j + xF] = T03_F04[i][j];
						break;
					case 3:
						if (roatateFigure == 0) xy[i + yF][j + xF] = T04_F01[i][j];
						if (roatateFigure == 1) xy[i + yF][j + xF] = T04_F01[i][j];
						if (roatateFigure == 2) xy[i + yF][j + xF] = T04_F01[i][j];
						if (roatateFigure == 3) xy[i + yF][j + xF] = T04_F01[i][j];
						break;
					case 4:
						if (roatateFigure == 0) xy[i + yF][j + xF] = T05_F01[i][j];
						if (roatateFigure == 1) xy[i + yF][j + xF] = T05_F02[i][j];
						if (roatateFigure == 2) xy[i + yF][j + xF] = T05_F01[i][j];
						if (roatateFigure == 3) xy[i + yF][j + xF] = T05_F02[i][j];
						break;
					case 5:
						if (roatateFigure == 0) xy[i + yF][j + xF] = T06_F01[i][j];
						if (roatateFigure == 1) xy[i + yF][j + xF] = T06_F02[i][j];
						if (roatateFigure == 2) xy[i + yF][j + xF] = T06_F03[i][j];
						if (roatateFigure == 3) xy[i + yF][j + xF] = T06_F04[i][j];
						break;
					case 6:
						if (roatateFigure == 0) xy[i + yF][j + xF] = T07_F01[i][j];
						if (roatateFigure == 1) xy[i + yF][j + xF] = T07_F02[i][j];
						if (roatateFigure == 2) xy[i + yF][j + xF] = T07_F01[i][j];
						if (roatateFigure == 3) xy[i + yF][j + xF] = T07_F02[i][j];
						break;
					default: break;
					}
				}
			}
		}
		/* Check rows if they are full */
		for (int y = 0; y < roomHeight; y++)
		{
			if ((xyColor[y][0] != '0') && (xyColor[y][1] != '0') && (xyColor[y][2] != '0') && (xyColor[y][3] != '0') &&
				(xyColor[y][4] != '0') && (xyColor[y][5] != '0') && (xyColor[y][6] != '0') && (xyColor[y][7] != '0') &&
				(xyColor[y][8] != '0') && (xyColor[y][9] != '0'))
			{
				for (int x = 0; x < 10; x++)
				{
					xyColor[y][x] = '8';
					//xy[y][x + 5] = '=';
					tetrisScore += 1 * scoreBonus;
				}
				if (lineCount == 5) lineCount = 0;
				scoreBonus += 1 + lineCount;
				lineCount += 1;
				bonusGetState = true;
			}
		}
		while (lineCount != 5)
		{
			if (lineCount == 1) SoundPlay("sound/1line.wav");
			else if (lineCount == 2) SoundPlay("sound/2line.wav");
			else if (lineCount == 3) SoundPlay("sound/3line.wav");
			else if (lineCount == 4) SoundPlay("sound/4line.wav");
			ScoreBoard();
			UpdateScreen();
			Draw();
			delay(100);
			
			for (int y = 0; y < roomHeight; y++)
			{
				if ((xyColor[y][0] == '8') && (xyColor[y][1] == '8') && (xyColor[y][2] == '8') && (xyColor[y][3] == '8') &&
					(xyColor[y][4] == '8') && (xyColor[y][5] == '8') && (xyColor[y][6] == '8') && (xyColor[y][7] == '8') &&
					(xyColor[y][8] == '8') && (xyColor[y][9] == '8'))
				{
					for (int yDown = roomHeight; yDown > 0; yDown--)
					{
						if (y > yDown - 1)
						{ 
							for (int x = 0; x < 10; x++)
							{
								xy[yDown][x + 5] = xy[yDown - 1][x + 5];
								xyColor[yDown][x] = xyColor[yDown - 1][x];
							}
						}
					}
				}
			}
			UpdateScreen();
			system("cls");
			lineCount = 5;
		}
		/* Check for lose*/
		for (int x = 0; x < 15 + roomXOffset; x++)
		{
			if (xy[0][x] == blockStaticChar) loseState = true;
		}
	}
}

void GameOver()
{
	while (!GetAsyncKeyState(VK_RETURN) & 0x0001) 
	{
		//Start:
		if (loseState == true)
		{
			loseState = false;

			/*GAME STATS*/
			DrawHeader();
			delay(100);
			Color(D_GREY, D_RED); cout << "\n\n      GAME OVER   ";
			delay(100);
			Color(D_GREY, WHITE); cout << "\n\n        SCORE\n";
			delay(100);
			if (tetrisScore > tetrisHighScore) delay(1900);
			if (tetrisScore > tetrisHighScore) { Color(D_GREY, CUSTOM); }
			cout << "       " << scoreArray[0] << scoreArray[1] << scoreArray[2] << scoreArray[3] << scoreArray[4] << scoreArray[5] << scoreArray[6];
			if (tetrisScore > tetrisHighScore) { cout << "\n    ! HIGHSCORE !";  delay(5000); }
			Color(D_GREY, WHITE);
			delay(100);
			UpdateScreen();
		}
		delay(500);
		cout << "\n\n\n\n\n\n\n\n\n\n\nPress ENTER to replay";
		UpdateScreen();
		delay(500);
		cout << "\n\n\n\n\n\n\n\n\n\n\n                     ";
		UpdateScreen();

	}; //STOP

	/*RESET*/
	if (tetrisScore > tetrisHighScore) tetrisHighScore = tetrisScore;
	xF = 8;
	yF = -3;
	scoreBonus = 1;
	tetrisScore = 0;
	currentFigure = 0;
	oldCurrentFigure = -1;
	nextFigure = 1;
	storeFigure = -1;

	for (int y = 0; y < roomHeight; y++)
	{
		for (int x = 0; x < 20; x++)
		{
			xy[y][x] = ' ';
			if (x < 10) xyColor[y][x] = '0';
		}
	}

	/* Update Scoreboard */
	scoreArray[6] = tetrisScore % 10;
	scoreArray[5] = tetrisScore / 10 % 10;
	scoreArray[4] = tetrisScore / 100 % 10;
	scoreArray[3] = tetrisScore / 1000 % 10;
	scoreArray[2] = tetrisScore / 10000 % 10;
	scoreArray[1] = tetrisScore / 100000 % 10;
	scoreArray[0] = tetrisScore / 1000000 % 10;

	UpdateScreen();
}