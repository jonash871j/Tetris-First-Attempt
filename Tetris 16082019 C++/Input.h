void Input()
{
	/*  GAME INPUT  */
	//////////////////

	//Reset states
	if (startUp == false) drawState = false;

	//Key input and DrawState
	if (!GetAsyncKeyState(VK_UP)) checkUpState = false;
	if (!GetAsyncKeyState(VK_LEFT)) checkLeftState = false;
	if (!GetAsyncKeyState(VK_RIGHT)) checkRightState = false;

	if (GetAsyncKeyState(VK_DOWN) & 0x8000) downTimer -= 10;
	else if (GetAsyncKeyState(VK_RIGHT) && (checkRightState == false))
	{
		enableRightState = true;
		checkRightState = true;
		for (int y = 0; y < roomHeight; y++)
		{
			for (int x = 0; x < 20; x++)
			{
				if (xy[y][14] != blockChar) collisionCheckLine = 1;
				if (xy[y][14] == blockChar)
				{
					collisionCheckLine = 0;
					x = 20;
					y = roomHeight;
				}
			}
		}
		Collision(1, 0, -1, 0, 1);
		if ((collisionCheckLine == 1) && (enableRightState == true))
		{
			xF += 1;
			UpdateScreen();
		}
	}
	else if (GetAsyncKeyState(VK_LEFT) && (checkLeftState == false))
	{
		enableLeftState = true;
		checkLeftState = true;
		for (int y = 0; y < roomHeight; y++)
		{
			for (int x = 0; x < 20; x++)
			{
				if (xy[y][5] != blockChar) collisionCheckLine = 0;
				if (xy[y][5] == blockChar)
				{
					collisionCheckLine = 1;
					x = 20;
					y = roomHeight;
				}
			}
		}
		Collision(-1, 0, 1, 0, 0);
		if ((collisionCheckLine == 0) && (enableLeftState == true))
		{
			xF -= 1;
			UpdateScreen();
		}
	}
	else if (GetAsyncKeyState(VK_UP) && (checkUpState == false))
	{
		SoundPlay("sound/s09_wtBlink.wav");
		checkUpState = true;
		if (roatateFigure < 3) roatateFigure += 1;
		else roatateFigure = 0;
		UpdateScreen();
	}
	/*else if (GetAsyncKeyState('S') & 0x0001) //DEBUG ONLY
	{
		if (currentFigure < 6) currentFigure += 1;
		else currentFigure = 0;
		UpdateScreen();
	}*/
	else if (GetAsyncKeyState('Z') & 0x0001) //DEBUG ONLY
	{
		if (fontSize < 80) fontSize += 8;
		setFont(L"Terminal", fontSize, fontSize, false);
		ScreenSize(26, 22);
		system("cls");
		UpdateScreen();
	}
	else if (GetAsyncKeyState('X') & 0x0001) //DEBUG ONLY
	{
		if (fontSize > 8) fontSize -= 8;
		setFont(L"Terminal", fontSize, fontSize, false);
		ScreenSize(26, 22);
		system("cls");
		UpdateScreen();
	}

	/*STORE FIGURE*/
	if ((GetAsyncKeyState(VK_RETURN) & 0x0001) && (enterState == false))
	{
		SoundPlay("sound/tohold.wav");
		enterState = true;
		if (storeFigure >= 0)
		{
			oldCurrentFigure = currentFigure;
			currentFigure = storeFigure;
			storeFigure = oldCurrentFigure;
		}
		else
		{
			storeFigure = currentFigure;
			currentFigure = nextFigure;
			RandFigure();
		}
		xF = 8;
		yF = -3;
		UpdateScreen();
	}

	if (downTimer <= 0)
	{
		Collision(0, 1, 0, -1, -1);
		yF += 1;
		UpdateScreen();
	}

	/*CHANGES THE FIGURE TO STATIC & RESETS THE POSITION*/
	/*
	if (GetAsyncKeyState(VK_RETURN) & 0x0001) //DEBUG ONLY
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
					yF = 1;
					xF = 7;
				}
			}
		}
	}*/
}