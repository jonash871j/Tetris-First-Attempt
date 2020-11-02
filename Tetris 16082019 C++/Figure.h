#pragma once
/*TETROMINO 01*/
////////////////

char T01_F01[4][4] = {
{' ',' ','#',' '},
{' ',' ','#',' '},
{' ',' ','#',' '},
{' ',' ','#',' '} };
char T01_F02[4][4] = {
{' ',' ',' ',' '},
{' ',' ',' ',' '},
{'#','#','#','#'},
{' ',' ',' ',' '} };

char T01_F03[4][4] = {
{' ','#',' ',' '},
{' ','#',' ',' '},
{' ','#',' ',' '},
{' ','#',' ',' '} };

char T01_F04[4][4] = {
{' ',' ',' ',' '},
{'#','#','#','#'},
{' ',' ',' ',' '},
{' ',' ',' ',' '} };

/*TETROMINO 02*/
////////////////

char T02_F01[4][4] = {
{' ',' ','#',' '},
{' ',' ','#',' '},
{' ','#','#',' '},
{' ',' ',' ',' '} };

char T02_F02[4][4] = {
{' ',' ',' ',' '},
{'#',' ',' ',' '},
{'#','#','#',' '},
{' ',' ',' ',' '} };

char T02_F03[4][4] = {
{'#','#',' ',' '},
{'#',' ',' ',' '},
{'#',' ',' ',' '},
{' ',' ',' ',' '} };

char T02_F04[4][4] = {
{'#','#','#',' '},
{' ',' ','#',' '},
{' ',' ',' ',' '},
{' ',' ',' ',' '} };

/*TETROMINO 03*/
////////////////

char T03_F01[4][4] = {
{' ','#',' ',' ', },
{' ','#',' ',' ', },
{' ','#','#',' ', },
{' ',' ',' ',' '} };

char T03_F02[4][4] = {
{'#','#','#',' '},
{'#',' ',' ',' '},
{' ',' ',' ',' '},
{' ',' ',' ',' '} };

char T03_F03[4][4] = {
{' ','#','#',' '},
{' ',' ','#',' '},
{' ',' ','#',' '},
{' ',' ',' ',' '} };

char T03_F04[4][4] = {
{' ',' ',' ',' '},
{' ',' ','#',' '},
{'#','#','#',' '},
{' ',' ',' ',' '} };

/*TETROMINO 04*/
////////////////
char T04_F01[4][4] = {
{' ',' ',' ',' '},
{' ','#','#',' '},
{' ','#','#',' '},
{' ',' ',' ',' '} };

/*TETROMINO 05*/
////////////////

char T05_F01[4][4] = {
{' ',' ',' ',' '},
{' ','#','#',' '},
{'#','#',' ',' '},
{' ',' ',' ',' '} };

char T05_F02[4][4] = {
{' ', '#',' ',' '},
{' ', '#','#',' '},
{' ', ' ','#',' '},
{' ',' ',' ',' '} };

/*TETROMINO 06*/
////////////////

char T06_F01[4][4] = {
{' ',' ',' ',' '},
{' ','#',' ',' '},
{'#','#','#',' '},
{' ',' ',' ',' '} };

char T06_F02[4][4] = {
{'#',' ',' ',' '},
{'#','#',' ',' '},
{'#',' ',' ',' '},
{' ',' ',' ',' '} };

char T06_F03[4][4] = {
{'#','#','#',' '},
{' ','#',' ',' '},
{' ',' ',' ',' '},
{' ',' ',' ',' '} };

char T06_F04[4][4] = {
{' ',' ','#',' '},
{' ','#','#',' '},
{' ',' ','#',' '},
{' ',' ',' ',' '} };

/*TETROMINO 07*/
////////////////

char T07_F01[4][4] = {
{' ',' ',' ',' '},
{'#','#',' ',' '},
{' ','#','#',' '},
{' ',' ',' ',' '} };

char T07_F02[4][4] = {
{' ',' ','#',' '},
{' ','#','#',' '},
{' ','#',' ',' '},
{' ',' ',' ',' '} };

void ReplaceSymbol(char checkCurrentChar,char symbolChange)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (T01_F01[i][j] == checkCurrentChar) T01_F01[i][j] = symbolChange;
			if (T01_F02[i][j] == checkCurrentChar) T01_F02[i][j] = symbolChange;
			if (T01_F03[i][j] == checkCurrentChar) T01_F03[i][j] = symbolChange;
			if (T01_F04[i][j] == checkCurrentChar) T01_F04[i][j] = symbolChange;

			if (T02_F01[i][j] == checkCurrentChar) T02_F01[i][j] = symbolChange;
			if (T02_F02[i][j] == checkCurrentChar) T02_F02[i][j] = symbolChange;
			if (T02_F03[i][j] == checkCurrentChar) T02_F03[i][j] = symbolChange;
			if (T02_F04[i][j] == checkCurrentChar) T02_F04[i][j] = symbolChange;

			if (T03_F01[i][j] == checkCurrentChar) T03_F01[i][j] = symbolChange;
			if (T03_F02[i][j] == checkCurrentChar) T03_F02[i][j] = symbolChange;
			if (T03_F03[i][j] == checkCurrentChar) T03_F03[i][j] = symbolChange;
			if (T03_F04[i][j] == checkCurrentChar) T03_F04[i][j] = symbolChange;

			if (T04_F01[i][j] == checkCurrentChar) T04_F01[i][j] = symbolChange;

			if (T05_F01[i][j] == checkCurrentChar) T05_F01[i][j] = symbolChange;
			if (T05_F02[i][j] == checkCurrentChar) T05_F02[i][j] = symbolChange;

			if (T06_F01[i][j] == checkCurrentChar) T06_F01[i][j] = symbolChange;
			if (T06_F02[i][j] == checkCurrentChar) T06_F02[i][j] = symbolChange;
			if (T06_F03[i][j] == checkCurrentChar) T06_F03[i][j] = symbolChange;
			if (T06_F04[i][j] == checkCurrentChar) T06_F04[i][j] = symbolChange;

			if (T07_F01[i][j] == checkCurrentChar) T07_F01[i][j] = symbolChange;
			if (T07_F02[i][j] == checkCurrentChar) T07_F02[i][j] = symbolChange;
		}
	}
}