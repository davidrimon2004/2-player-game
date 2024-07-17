#include <iostream>
#include <conio.h>
using namespace std;
void CoutMatToScreen(char X[][200], int rstart, int rend, int cstart, int cend)
{
	system("cls");
	for (int r = rstart; r < rend; r++)
	{
		for (int c = cstart; c < cend; c++)
		{
			cout << X[r][c];
		}
	}
}
void scrolling(int rHero, int cHero, int& rstart, int& rend, int& cstart, int& cend)
{
	if (rHero + 12 < 50 || rHero - 12 > 50)
	{
		rstart = rHero - 12;
		rend = rHero + 12;
	}

	if (rHero + 12 > 50)
	{
		rstart = 50 - 24;
		rend = 50;
	}
	if (rHero - 12 < 0)
	{
		rstart = 0;
		rend = 24;
	}
	if (cHero + 40 < 200 || cHero - 40 > 0)
	{
		cstart = cHero - 40;
		cend = cHero + 40;
	}
	if (cHero + 40 > 200)
	{
		cstart = 200 - 80;
		cend = 200;
	}
	if (cHero - 40 < 0)
	{
		cstart = 0;
		cend = 80;
	}
}
void MoveLaser(int& rBoat, int& cBoat, int& XdirBoat)
{
	cBoat--;
	if (cBoat == 124)
	{
		cBoat = 197;
		rBoat = 26;
	}
}
void DrawLaser(int rBoat, int cBoat, char X[][200])
{
	for (int i = 0; i < 2; i++)
	{
		X[rBoat][cBoat + i] = '<';
	}
}
void Damagelazer(int& rHero, int& cHero, int& rHero2, int& cHero2, int& rlaser, int& claser, int& lives, int& lives2, int& rstart, int& rend, int& cstart, int& cend)
{
	if (rHero == 23 && (cHero + 1 == claser || cHero == claser))
	{
		lives--;
		cHero = 25;
		scrolling(rHero, cHero, rstart, rend, cstart, cend);
	}
	if (rHero2 == 23 && (cHero2 + 1 == claser || cHero2 == claser))
	{
		lives2--;
		cHero2 = 25;
		scrolling(rHero2, cHero2, rstart, rend, cstart, cend);
	}
}
void movePlatform(int& cPlatform, int& rPlatform, int& XdirPlatform, int& cHero, int& rHero)
{

	if (XdirPlatform == -1)
	{
		if (cPlatform == 2)
		{
			XdirPlatform *= -1;
		}
		cPlatform--;
	}
	else
	{
		if ((cPlatform + 7) == 75)
		{
			XdirPlatform *= -1;
		}
		cPlatform++;

	}
	if (rHero + 5 == rPlatform && cHero == cPlatform)
	{
		cHero++;
	}
}
void DrawPLatform(int rPlatform, int cPlatform, char X[][200])
{
	int c = 0;
	for (; c < 5; c++)
	{
		X[rPlatform][cPlatform] = 196;
		cPlatform++;
	}
	cPlatform -= 5;
	X[rPlatform][cPlatform] = 218;
	X[rPlatform][cPlatform + 5] = 191;
	c = 0;
	for (; c < 5; c++)
	{
		X[rPlatform + 1][cPlatform] = 196;
		(cPlatform)++;
	}
	cPlatform -= 5;
	X[rPlatform + 1][cPlatform] = 192;
	X[rPlatform + 1][cPlatform + 5] = 217;
}
void MoveHero(int& rHero, int& cHero, char UserDes, char X[][200], int& rHero2, int& cHero2, int& flag, int ctjump, int& dirHero, int& dirplayer2, int& flagT)
{
	if (UserDes == 'w')
	{
		flagT = 1;
		if (X[rHero+4][cHero]!=' ')
		{
			rHero -= 3;
		}
	}
	if (UserDes == 's')
	{
		flagT = 1;
		if (X[rHero + 4][cHero] == '-')
		{
			rHero++;
		}
	}
	if (UserDes == 'a')
	{
		flagT = 1;
		if ((unsigned char)(X[rHero][cHero - 2]) != 186 && (X[rHero + 1][cHero - 2]) != 186 && (X[rHero + 2][cHero - 2]) != 186 && (X[rHero + 3][cHero - 2]) != 186)
		{
			cHero -= 2;
		}
		dirHero = -1;
	}
	if (UserDes == 'd')
	{
		flagT = 1;
		if ((unsigned char)(X[rHero][cHero + 2]) != 186 && (X[rHero + 1][cHero + 2]) != 186 && (X[rHero + 2][cHero + 2]) != 186 && (X[rHero + 3][cHero + 2]) != 186)
		{
			cHero += 2;
		}
		dirHero = 1;

	}
	if (UserDes == 'e')
	{
		flagT = 1;
		if (X[rHero + 4][cHero] != ' ')
		{
			cHero += 3;

			rHero -= 3;
		}
	}

	if (UserDes == 'q')
	{
		flagT = 1;
		if (X[rHero + 4][cHero] != ' ')
		{
			cHero -= 3;

			rHero -= 3;
		}
	}

	if (UserDes == 'u')
	{
		flagT = 2;
		if (X[rHero2 + 4][cHero2] != ' ')
		{
			rHero2 -= 2;
		}
	}

	if (UserDes == 'j')
	{
		flagT = 2;
		if (X[rHero2 + 4][cHero2] == '-')
		{
			rHero2++;
		}
	}
	if (UserDes == 'h')
	{
		flagT = 2;
		if ((unsigned char)(X[rHero2][cHero2 - 2]) != 186)
		{
			cHero2 -= 2;
			dirplayer2 = -1;
		}
	}
	if (UserDes == 'k')
	{
		flagT = 2;
		if ((unsigned char)(X[rHero2][cHero2 + 2]) != 186)
		{
			cHero2 += 2;
		}
		dirplayer2 = 1;

	}
	if (UserDes == 'i')
	{
		flagT = 2;
		if (X[rHero2 + 4][cHero2] != ' ')
		{
			cHero2 += 3;
			rHero2 -= 3;
		}
	}
	if (UserDes == 'y')
	{
		flagT = 2;
		if (X[rHero2 + 4][cHero2] != ' ')
		{
			cHero2 -= 3;
			rHero2 -= 3;
		}
	}

	if (rHero == 45 && cHero == 195)
	{
		flag *= -2;
	}
	if (rHero2 == 45 && cHero2 == 195)
	{
		flag *= -1;
	}
	if (rHero == 31 && cHero == 160)
	{
		flag = 3;
	}
	if (rHero2 == 31 && cHero2 == 160)
	{
		flag = 3;
	}
}
void ClearAndDrawFixedObject(char X[][200])
{
	int r, c;
	for (r = 0; r < 50; r++)
	{
		for (c = 0; c < 200; c++)
		{
			X[r][c] = ' ';
		}
	}
	for (r = 1; r < 49; r++)
	{
		X[r][0] = 186;
	}
	for (r = 1; r < 49; r++)
	{
		X[r][199] = 186;
	}
	for (c = 1; c < 199; c++)
	{
		X[0][c] = 205;
	}
	for (c = 1; c < 199; c++)
	{
		X[49][c] = 205;
	}
	//ladder 1;
	for (r = 48; r > 41; r--)
	{
		X[r][120] = '|';
	}
	for (r = 48; r > 41; r--)
	{
		X[r][125] = '|';
	}
	for (r = 48; r > 41; r--)
	{
		for (c = 124; c > 120; c--)
		{
			X[r][c] = '-';
		}
	}
	//lader 2;
	for (r = 48; r > 42; r--)
	{
		X[r][180] = '|';
	}
	for (r = 48; r > 42; r--)
	{
		X[r][185] = '|';
	}
	for (r = 48; r > 42; r--)
	{
		for (c = 184; c > 180; c--)
		{
			X[r][c] = '-';
		}
	}
	//lader 3;
	for (r = 42; r > 35; r--)
	{
		X[r][188] = '|';
	}
	for (r = 42; r > 35; r--)
	{
		X[r][193] = '|';
	}
	for (r = 42; r > 35; r--)
	{
		for (c = 192; c > 188; c--)
		{
			X[r][c] = '-';
		}
	}
	//level 1 
	for (c = 170; c < 188; c++)
	{
		X[37][c] = 205;
	}
	for (c = 194; c < 199; c++)
	{
		X[37][c] = 205;
	}
	for (c = 11; c < 170; c++)
	{
		X[35][c] = 205;
	}
	X[35][170] = 187;
	X[36][170] = 186;
	X[37][170] = 200;
	for (c = 194; c < 199; c++)
	{
		X[37][c] = 205;
	}
	for (c = 11; c < 170; c++)
	{
		X[36][c] = 205;
	}
	//level 1.5
	for (c = 80; c < 120; c++)
	{
		X[42][c] = 205;
	}
	for (c = 126; c < 157; c++)
	{
		X[42][c] = 205;
	}
	for (c = 186; c < 120; c++)
	{
		X[42][c] = 205;
	}
	//wallish
	for (r = 36; r < 42; r++)
	{
		X[r][80] = 186;
	}
	X[35][80] = 203;
	X[42][80] = 200;
	for (r = 36; r < 43; r++)
	{
		X[r][78] = 186;
	}
	X[35][78] = 203;
	X[43][78] = 200;
	for (c = 79; c < 120; c++)
	{
		X[43][c] = 205;
	}
	for (c = 126; c < 157; c++)
	{
		X[43][c] = 205;
	}
	X[43][157] = 188;
	X[42][157] = 187;

	//extention level 1
	for (c = 1; c < 6; c++)
	{
		X[35][c] = 205;
	}
	for (c = 1; c < 6; c++)
	{
		X[36][c] = 205;
	}
	//elev button 1
	X[47][198] = 124;
	X[48][198] = 192;
	X[46][198] = 218;
	//elev button 2
	X[34][160] = '-';
	X[34][161] = 191;
	X[34][159] = 218;
	//level 2
	for (c = 1; c < 199; c++)
	{
		X[27][c] = 205;
	}
	for (c = 1; c < 199; c++)
	{
		X[28][c] = 205;
	}
	X[27][120] = 202;
	X[26][120] = 201;
	X[26][121] = 205;
	X[26][122] = 187;
	X[27][122] = 202;

	//teleportal
	for (r = 34; r > 30; r--) //starts at c=100 and ends at c=108 & r starts at 34 and ends at r=29
	{
		X[r][100] = 179;
	}
	X[35][100] = 202;
	X[30][100] = 201;
	for (c = 101; c < 109; c++)
	{
		X[30][c] = 196;
	}
	X[30][109] = 187;
	for (r = 34; r > 30; r--)
	{
		X[r][109] = 179;
	}
	X[35][109] = 202;
	for (c = 101; c < 109; c++)
	{
		for (r = 34; r > 30; r--)
		{
			X[r][c] = 176;
		}
	}
	//teleportal 2
	for (r = 26; r > 22; r--) //starts at c=100 and ends at c=108 & r starts at 34 and ends at r=29
	{
		X[r][18] = 179;
	}
	X[27][8] = 202;
	X[22][8] = 201;
	for (c = 9; c < 18; c++)
	{
		X[22][c] = 196;
	}
	X[22][18] = 187;
	for (r = 26; r > 22; r--)
	{
		X[r][8] = 179;
	}
	X[27][18] = 202;
	for (c = 9; c < 18; c++)
	{
		for (r = 26; r > 22; r--)
		{
			X[r][c] = 176;
		}
	}
	//level3
	for (c = 130; c < 199; c++)
	{
		X[15][c] = 205;
	}
	for (c = 130; c < 199; c++)
	{
		X[16][c] = 205;
	}
	X[15][129] = 201;
	X[16][129] = 200;
	//end gate
	for (r = 14; r > 10; r--) //starts at c=100 and ends at c=108 & r starts at 34 and ends at r=29
	{
		X[r][150] = 179;
	}
	X[15][140] = 202;
	X[10][140] = 201;
	for (c = 9; c < 18; c++)
	{
		X[10][c] = 196;
	}
	X[10][150] = 187;
	for (r = 14; r > 10; r--)
	{
		X[r][140] = 179;
	}
	X[15][150] = 202;
}
void DrawElevator(int relevator, char X[][200])
{
	for (int c = 7; c < 10; c++)
	{
		X[relevator][c] = 196;
	}
	X[relevator][6] = 218;
	X[relevator][10] = 191;
	for (int c = 7; c < 10; c++)
	{
		X[relevator + 1][c] = 196;
	}
	X[relevator + 1][6] = 192;
	X[relevator + 1][10] = 217;
}
void MoveElevatorup(int& relevator, int flag, int& rHero, int& cHero, int& rHero2, int cHero2)
{
	if (flag == 1)
	{
		if (relevator > 35)
		{
			relevator--;
			if ((cHero == 9 || cHero == 10 || cHero == 8 || cHero == 7 || cHero == 11))
			{
				rHero--;
			}
			if (relevator == 35)
			{
				if ((cHero == 9 || cHero == 10 || cHero == 8))
				{
					rHero -= 3;
				}
			}
		}
	}
	if (flag == 2)
	{
		if (relevator > 35)
		{
			relevator--;
			if ((cHero2 == 9 || cHero2 == 10 || cHero2 == 8 || cHero2 == 7 || cHero2 == 11))
			{
				rHero2--;
			}
			if (relevator == 35)
			{

				if ((cHero2 == 9 || cHero2 == 10 || cHero2 == 8))
				{
					rHero2 -= 3;
				}
			}
		}
	}
}
void MoveElevatorDown(int& flag, int& relev)
{
	if (flag == 3)
	{
		if (relev >= 34 && relev < 48)
		{
			relev++;
		}
	}
	if (relev == 48)
	{
		flag = -1;
	}
}
void DrawElevator2(int relevator, char X[][200])
{
	for (int c = 125; c < 130; c++)
	{
		X[relevator][c] = 196;
	}
	X[relevator][124] = 218;
	X[relevator][130] = 191;
	for (int c = 124; c < 130; c++)
	{
		X[relevator + 1][c] = 196;
	}
	X[relevator + 1][124] = 192;
	X[relevator + 1][130] = 217;
}
void MoveElevatorup2(int& relevator, int flag, int& rHero, int& cHero, int& rHero2, int cHero2)
{
	if (flag == 1)
	{
		if (relevator > 15)
		{
			relevator--;
			if ((cHero == 125 || cHero == 126 || cHero == 127 || cHero == 128 || cHero == 129))
			{
				rHero--;
			}
			if (relevator == 15)
			{
				if ((cHero == 126 || cHero == 127 || cHero == 128))
				{
					rHero -= 3;
				}
			}
		}
	}
	if (flag == 2)
	{
		if (relevator > 15)
		{
			relevator--;
			if ((cHero2 == 125 || cHero2 == 126 || cHero2 == 127 || cHero2 == 128 || cHero2 == 129))
			{
				rHero2--;
			}
			if (relevator == 15)
			{
				if ((cHero2 == 126 || cHero2 == 127 || cHero2 == 128))
				{
					rHero -= 3;
				}
			}
		}
	}
}
void MoveElevatorDown2(int& flag, int& relev)
{
	if (flag == 3)
	{
		if (relev >= 34 && relev < 48)
		{
			relev++;
		}
	}
	if (relev == 48)
	{
		flag = -1;
	}
}
void DrawHero(int rHero, int cHero, char X[][200], char move, int rHero2, int cHero2)
{
	X[rHero][cHero] = 126;
	X[rHero + 1][cHero - 2] = '(';
	X[rHero + 1][cHero + 2] = ')';
	X[rHero + 1][cHero + 1] = 233;
	X[rHero + 1][cHero - 1] = 233;
	X[rHero + 1][cHero] = 248;
	X[rHero + 2][cHero] = 177;
	X[rHero + 2][cHero - 1] = '/';
	X[rHero + 2][cHero + 1] = '\\';
	X[rHero + 3][cHero - 1] = 186;
	X[rHero + 3][cHero + 1] = 186;
	X[rHero2][cHero2] = ' ';
	X[rHero2 + 1][cHero2 - 2] = '[';
	X[rHero2 + 1][cHero2 + 2] = ']';
	X[rHero2 + 1][cHero2 + 1] = 224;
	X[rHero2 + 1][cHero2 - 1] = 227;
	X[rHero2 + 1][cHero2] = '^';
	X[rHero2 + 2][cHero2] = 177;
	X[rHero2 + 2][cHero2 - 1] = '/';
	X[rHero2 + 2][cHero2 + 1] = '\\';
	X[rHero2 + 3][cHero2 - 1] = '/';
	X[rHero2 + 3][cHero2 + 1] = '\\';
}
void Teleport1(int& c, int& r, int& flag)
{
	if (c > 100 && c < 109)
	{
		if (r == 31)
		{
			c = 10;
			r = 23;
			flag = 1;
		}
	}
}
void teleport2(int& c, int& r)
{
	if (c > 8 && c < 17)
	{
		if (r == 23)
		{
			c = 103;
			r = 31;
		}
	}
}
void DrawBullet1(int& cbullet, int& rbullet, char x[][200], int dir, int& move)
{
	if (dir == -1)
	{
		cbullet -= 2;
	}
	else
	{
		cbullet += 2;
	}
	if (x[rbullet][cbullet + 2] != ' ')
	{
		x[rbullet][cbullet] = ' ';
		move = 0;
	}
	if (cbullet <= 0 || cbullet >= 199)
	{
		x[rbullet][cbullet] = ' ';
		move = 0;
	}
	x[rbullet][cbullet] = 207;
}
void shoot1(int& cBullet, int& rBullet, int dirHero, char X[][200], int cHero, int rHero, int& move)
{
	move = 1;
	if (dirHero == -1)
	{
		cBullet = cHero - 4;
		rBullet = rHero + 2;
	}
	if (dirHero == 1)
	{
		cBullet = cHero + 4;
		rBullet = rHero + 2;
	}
	if (X[rBullet][cBullet + 1] != ' ')
	{
		move = 0;
	}
	if (cBullet <= 0 || cBullet >= 199)
	{
		move = 0;
	}
}
void DrawBullet2(int& cbullet, int& rbullet, char x[][200], int dir, char& move)
{
	if (dir == -1)
	{
		cbullet -= 2;
	}
	else
	{
		cbullet += 2;
	}
	x[rbullet][cbullet] = 207;
	if (x[rbullet][cbullet + 1] != ' ')
	{
		x[rbullet][cbullet] = ' ';
		move = 'n';
	}
	if (cbullet <= 0 || cbullet >= 199)
	{
		x[rbullet][cbullet] = ' ';
		move = 'n';
	}

}
void shoot2(int& cBullet, int& rBullet, int dirHero, char X[][200], int cHero, int rHero, char& move)
{
	move = 'y';
	if (dirHero == -1)
	{
		cBullet = cHero - 4;
		rBullet = rHero + 2;
	}
	if (dirHero == 1)
	{
		cBullet = cHero + 4;
		rBullet = rHero + 2;
	}
	if (X[rBullet][cBullet + 2] != ' ')
	{
		move = 'n';
	}
	if (cBullet <= 0 || cBullet >= 199)
	{
		move = 'n';
	}
}
void drawMB(int c[], int r[], char x[][200], int a, int& zoed, int& move)
{
	move = 1;
	for (int i = 0; i < zoed; i++)
	{
		x[r[1]][c[i]] = 207;
	}
	if (zoed == a)
	{
		move = 0;
		zoed = 0;
	}
	zoed++;
}
void shootMB(int dirHero, int cHero, int rHero, char x[][200], int c[], int r[], int& a)
{
	a = 0;
	if (dirHero == -1)
	{
		for (int i = cHero - 4; x[rHero + 2][i] == ' ' && i > 0; i -= 2)
		{
			c[a] = i;
			a++;
		}
		r[0] = rHero + 1;
		r[1] = rHero + 2;
		r[2] = rHero + 3;
	}
	if (dirHero == 1)
	{
		for (int i = cHero + 4; x[rHero + 2][i] == ' ' && i < 199; i += 2)
		{
			c[a] = i;
			a++;
		}
		r[0] = rHero + 1;
		r[1] = rHero + 2;
		r[2] = rHero + 3;
	}
}
void DrawEnemy1(char X[][200], int renemy1, int cenemy1)
{
	cenemy1 = 20;
	renemy1 = 47;
	X[renemy1][cenemy1] = '~';
	X[renemy1][cenemy1 - 1] = '-';
	X[renemy1][cenemy1 + 1] = '-';
	X[renemy1 + 1][cenemy1] = '.';
	X[renemy1 + 1][cenemy1 + 2] = '^';
	X[renemy1 + 1][cenemy1 - 2] = '^';
	X[renemy1 + 1][cenemy1 - 3] = '(';
	X[renemy1 + 1][cenemy1 - 4] = '(';
	X[renemy1 + 1][cenemy1 + 3] = ')';
	X[renemy1 + 1][cenemy1 + 4] = ')';
}
void DamageEnemy1(int& lives, int& lives2, int& cHero, int& rHero, int& cHero2, int& rHero2, int& isdead)
{
	int c;
	for (c = 20; c < 25; c++)
	{
		if (rHero == 45 && (cHero == c || cHero + 1 == c || cHero - 1 == c))
		{
			rHero = 43;
			cHero = 50;
			lives--;
		}
	}
	for (c = 20; c < 25; c++)
	{
		if (rHero2 == 45 && (cHero2 == c || cHero2 + 1 == c || cHero2 - 1 == c))
		{
			rHero2 = 43;
			cHero2 = 50;
			lives2--;
		}
	}
	if (rHero == 43 && (cHero == 20 || cHero == 21 || cHero == 22 || cHero == 23 || cHero == 24 || cHero == 19 || cHero == 18 || cHero == 17))
	{
		isdead = 1;
	}
	if (rHero2 == 43 && (cHero2 == 20 || cHero2 == 21 || cHero2 == 22 || cHero2 == 23 || cHero2 == 24 || cHero2 == 19 || cHero2 == 18 || cHero2 == 17))
	{
		isdead = 1;
	}
}
void DrawEnemy2(char x[][200], int renemy, int cenemy)
{
	x[renemy][cenemy] = 196;
	x[renemy][cenemy + 1] = 196;
	x[renemy][cenemy + 2] = '/';
	x[renemy][cenemy + 3] = 92;
	x[renemy + 1][cenemy + 3] = ')';
	x[renemy + 1][cenemy + 4] = 196;
	x[renemy + 1][cenemy + 5] = 196;
	x[renemy + 2][cenemy + 5] = 231;
	x[renemy + 2][cenemy + 4] = 231;
	x[renemy + 2][cenemy + 1] = '^';
	x[renemy + 2][cenemy] = '^';
	x[renemy + 1][cenemy + 1] = 42;
	x[renemy + 1][cenemy] = 42;
	x[renemy][cenemy - 2] = '/';
	x[renemy][cenemy - 1] = 92;
	x[renemy + 1][cenemy - 2] = '(';
	x[renemy + 1][cenemy - 3] = 196;
	x[renemy + 1][cenemy - 4] = 196;
	x[renemy + 2][cenemy - 3] = 231;
	x[renemy + 2][cenemy - 4] = 231;
}
void damageEnemy2(int& rHero, int& cHero, int& rHero2, int& cHero2, int& lives, int& lives2, int rstart, int rend, int cstart, int cend, int cenemy2)
{
	if (rHero == 31 && (cHero + 1 == cenemy2 || cHero == cenemy2))
	{
		lives--;
		cHero = 50;
		rHero = 43;
		scrolling(rHero, cHero, rstart, rend, cenemy2, cend);
	}
	if (rHero2 == 31 && (cHero2 + 1 == cenemy2 || cHero2 == cenemy2))
	{
		lives2--;
		cHero2 = 50;
		rHero2 = 43;
		scrolling(rHero2, cHero2, rstart, rend, cstart, cend);
	}
}
void MoveEnemy2(int& renemy, int& cenemy, int rHero, int cHero, int rHero2, int cHero2)
{
	if (((cHero - cenemy) <= 20 && (cHero - cenemy) > 0) && rHero == renemy)
	{
		cenemy++;
	}
	if (((cenemy - cHero) <= 20 && (cenemy - cHero) > 0) && rHero == renemy)
	{
		cenemy--;
	}
	if (((cHero2 - cenemy) <= 20 && (cHero2 - cenemy) > 0) && rHero2 == renemy)
	{
		cenemy++;
	}
	if (((cenemy - cHero2) <= 20 && (cenemy - cHero2) > 0) && rHero2 == renemy)
	{
		cenemy--;
	}
}
void KillEnemy(char X[][200], int& rEnemy, int& cEnemy, int& isdead, int rbullet, int cbullet)
{
	if ((rEnemy + 2 == rbullet && cEnemy - 6 == cbullet) || (rEnemy + 2 == rbullet && cEnemy + 6 == cbullet))
	{
		isdead++;
	}
}
void KillEnemy2(char X[][200], int& rEnemy, int& cEnemy, int& isdead, int rbullet, int cbullet)
{
	if (rEnemy + 2 == rbullet && cEnemy - 5 == cbullet || rEnemy + 2 == rbullet && cEnemy - 6 == cbullet)
	{
		isdead++;
	}
}
void DrawEnemy3(int rWhitch, int cWhitch, char X[][200])
{
	X[rWhitch][cWhitch] = '/';
	X[rWhitch][cWhitch + 1] = '\\';
	X[rWhitch][cWhitch - 1] = '_';
	X[rWhitch][cWhitch + 2] = '_';
	X[rWhitch + 1][cWhitch + 3] = '\\';
	X[rWhitch + 1][cWhitch + 4] = '\\';
	X[rWhitch + 1][cWhitch + 5] = '\\';
	X[rWhitch + 1][cWhitch - 2] = '/';
	X[rWhitch + 1][cWhitch - 3] = '/';
	X[rWhitch + 1][cWhitch - 1] = '`';
	X[rWhitch + 1][cWhitch + 1] = '`';
	X[rWhitch + 1][cWhitch] = '<';
	X[rWhitch + 1][cWhitch + 2] = '.';
	X[rWhitch + 2][cWhitch - 4] = '-';
	X[rWhitch + 2][cWhitch - 3] = '-';
	X[rWhitch + 2][cWhitch - 2] = '-';
	X[rWhitch + 2][cWhitch - 1] = '(';
	X[rWhitch + 2][cWhitch] = '_';
	X[rWhitch + 2][cWhitch + 1] = '_';
	X[rWhitch + 2][cWhitch + 2] = '_';
	X[rWhitch + 2][cWhitch + 3] = ')';
	X[rWhitch + 2][cWhitch + 4] = '-';
	X[rWhitch + 2][cWhitch + 5] = '-';
	X[rWhitch + 2][cWhitch + 6] = '<';
	X[rWhitch + 3][cWhitch + 1] = 'J';
	X[rWhitch + 3][cWhitch + 2] = 'J';
}
void MoveWhitch(int& cHero, int& rHero, int& rHero2, int& cHero2, int& renemy, int& cenemy)
{
	if (((cHero - cenemy) <= 20 && (cHero - cenemy) > 0) && rHero == renemy)
	{
		cenemy++;
	}
	if (((cenemy - cHero) <= 20 && (cenemy - cHero) > 0) && rHero == renemy)
	{
		cenemy--;
	}
	if (((cHero2 - cenemy) <= 20 && (cHero2 - cenemy) > 0) && rHero2 == renemy)
	{
		cenemy++;
	}
	if (((cenemy - cHero2) <= 20 && (cenemy - cHero2) > 0) && rHero2 == renemy)
	{
		cenemy--;
	}
}
void damagewhitch(int& rHero, int& cHero, int renemy, int cenemy, int rend, int rstart, int cend, int cstart, int& lives, int& lives2, int& cHero2, int& rHero2)
{
	if (rHero == 23 && (cHero + 1 == cenemy || cHero == cenemy))
	{
		lives--;
		cHero = 10;
		rHero = 23;
		scrolling(rHero, cHero, rstart, rend, cenemy, cend);
	}
	if (rHero2 == 23 && (cHero2 + 1 == cenemy || cHero2 == cenemy))
	{
		lives2--;
		cHero2 = 10;
		rHero2 = 23;
		scrolling(rHero2, cHero2, rstart, rend, cstart, cend);
	}
}
void Gravity(char x[][200], int& rhero, int chero)
{
	if (x[rhero + 4][chero] == ' ')
	{
		rhero++;
	}
}
void drawspikes(char X[][200])
{
	int c;
	for (c = 152; c < 157; c++)
	{
		X[49][c] = '^';
	}
}
void Spikesdamage(int& rHero, int& cHero, int& rHero2, int& cHero2, int& lives, int& lives2)
{
	int c;
	for (c = 152; c < 157; c++)
	{
		if (rHero == 45 && (cHero == c || cHero + 1 == c || cHero - 1 == c))
		{
			rHero = 43;
			cHero = 50;
			lives--;
		}
	}
	for (c = 152; c < 157; c++)
	{
		if (rHero2 == 45 && (cHero2 == c || cHero2 + 1 == c || cHero2 - 1 == c))
		{
			rHero2 = 43;
			cHero2 = 50;
			lives2--;
		}
	}
}
void GameOver(char y[][80])
{
	for (int r = 0; r < 24; r++)
	{
		for (int c = 0; c < 80; c++)
		{
			y[r][c] = ' ';
		}
	}
	y[12][36] = 'G';
	y[12][37] = 'a';
	y[12][38] = 'm';
	y[12][39] = 'e';
	y[12][40] = ' ';
	y[12][41] = 'O';
	y[12][42] = 'v';
	y[12][43] = 'e';
	y[12][44] = 'r';
	y[12][45] = '!';
	y[14][40] = 'G';
	y[14][41] = 'G';
}
void MainMenu(char X[][80])
{
	for (int r = 0; r < 24; r++)
	{
		for (int c = 0; c < 80; c++)
		{
			X[r][c] = ' ';
		}
	}
	//wellcome
	int c = 35;
	X[3][c] = 'w';
	X[3][++c] = 'e';
	X[3][++c] = 'l';
	X[3][++c] = 'c';
	X[3][++c] = 'o';
	X[3][++c] = 'm';
	X[3][++c] = 'e';
	//press s to start
	c = 29;
	X[20][c] = 'p';
	X[20][++c] = 'r';
	X[20][++c] = 'e';
	X[20][++c] = 's';
	X[20][++c] = 's';
	X[20][++c] = ' ';
	X[20][++c] = 's';
	X[20][++c] = 'p';
	X[20][++c] = 'a';
	X[20][++c] = 'c';
	X[20][++c] = 'e';
	X[20][++c] = ' ';
	X[20][++c] = 't';
	X[20][++c] = 'o';
	X[20][++c] = ' ';
	X[20][++c] = 's';
	X[20][++c] = 't';
	X[20][++c] = 'a';
	X[20][++c] = 'r';
	X[20][++c] = 't';
	//charcter 1
	int rHero = 10, cHero = 20;
	X[rHero][cHero] = 126;
	X[rHero + 1][cHero - 2] = '(';
	X[rHero + 1][cHero + 2] = ')';
	X[rHero + 1][cHero + 1] = 233;
	X[rHero + 1][cHero - 1] = 233;
	X[rHero + 1][cHero] = 248;
	X[rHero + 2][cHero] = 177;
	X[rHero + 2][cHero - 1] = '/';
	X[rHero + 2][cHero + 1] = '\\';
	X[rHero + 3][cHero - 1] = 186;
	X[rHero + 3][cHero + 1] = 186;
	X[rHero - 1][cHero - 2] = 'L';
	X[rHero - 1][cHero - 1] = 'y';
	X[rHero - 1][cHero] = 'd';
	X[rHero - 1][cHero + 1] = 'i';
	X[rHero - 1][cHero + 2] = 'a';
	//charcter 2
	rHero = 10; cHero = 60;
	X[rHero][cHero] = ' ';
	X[rHero + 1][cHero - 2] = '[';
	X[rHero + 1][cHero + 2] = ']';
	X[rHero + 1][cHero + 1] = 224;
	X[rHero + 1][cHero - 1] = 227;
	X[rHero + 1][cHero] = '^';
	X[rHero + 2][cHero] = 177;
	X[rHero + 2][cHero - 1] = '/';
	X[rHero + 2][cHero + 1] = '\\';
	X[rHero + 3][cHero - 1] = '/';
	X[rHero + 3][cHero + 1] = '\\';
	X[rHero - 1][cHero - 2] = 'D';
	X[rHero - 1][cHero - 1] = 'a';
	X[rHero - 1][cHero] = 'v';
	X[rHero - 1][cHero + 1] = 'i';
	X[rHero - 1][cHero + 2] = 'd';
}
void CoutMenuToScreen(char X[][80])
{
	system("cls");
	for (int r = 0; r < 24; r++)
	{
		for (int c = 0; c < 80; c++)
		{
			cout << X[r][c];
		}
	}
}
void HowToPlay(char X[][80])
{
	for (int r = 0; r < 24; r++)
	{
		for (int c = 0; c < 80; c++)
		{
			X[r][c] = ' ';
		}
	}
	//charcter 1
	int rHero = 10, cHero = 60;
	X[rHero][cHero] = 126;
	X[rHero + 1][cHero - 2] = '(';
	X[rHero + 1][cHero + 2] = ')';
	X[rHero + 1][cHero + 1] = 233;
	X[rHero + 1][cHero - 1] = 233;
	X[rHero + 1][cHero] = 248;
	X[rHero + 2][cHero] = 177;
	X[rHero + 2][cHero - 1] = '/';
	X[rHero + 2][cHero + 1] = '\\';
	X[rHero + 3][cHero - 1] = 186;
	X[rHero + 3][cHero + 1] = 186;
	X[rHero - 1][cHero - 2] = 'L';
	X[rHero - 1][cHero - 1] = 'y';
	X[rHero - 1][cHero] = 'd';
	X[rHero - 1][cHero + 1] = 'i';
	X[rHero - 1][cHero + 2] = 'a';
	int c = 3, r = 3;
	X[r][++c] = 'C';
	X[r][++c] = 'o';
	X[r][++c] = 'n';
	X[r][++c] = 't';
	X[r][++c] = 'r';
	X[r][++c] = 'o';
	X[r][++c] = 'l';
	X[r][++c] = 's';
	X[r][++c] = ' ';
	X[r][++c] = 'o';
	X[r][++c] = 'f';
	X[r][++c] = ' ';
	X[r][++c] = 't';
	X[r][++c] = 'h';
	X[r][++c] = 'e';
	X[r][++c] = ' ';
	X[r][++c] = 'f';
	X[r][++c] = 'i';
	X[r][++c] = 'r';
	X[r][++c] = 's';
	X[r][++c] = 't';
	X[r][++c] = ' ';
	X[r][++c] = 'H';
	X[r][++c] = 'e';
	X[r][++c] = 'r';
	X[r][++c] = 'o';
	X[r][++c] = ' ';
	X[r][++c] = ':';
	c = 4;
	r += 2;
	X[r][c] = 'A';
	X[r][++c] = ':';
	X[r][++c] = ' ';
	X[r][++c] = 'T';
	X[r][++c] = 'o';
	X[r][++c] = ' ';
	X[r][++c] = 'G';
	X[r][++c] = 'o';
	X[r][++c] = ' ';
	X[r][++c] = 'l';
	X[r][++c] = 'e';
	X[r][++c] = 'f';
	X[r][++c] = 't';
	c = 4;
	r += 2;
	X[r][c] = 'W';
	X[r][++c] = ':';
	X[r][++c] = ' ';
	X[r][++c] = 'T';
	X[r][++c] = 'o';
	X[r][++c] = ' ';
	X[r][++c] = 'J';
	X[r][++c] = 'm';
	X[r][++c] = 'p';
	X[r][++c] = 'u';
	X[r][++c] = ' ';
	X[r][++c] = 'u';
	X[r][++c] = 'p';
	c = 4;
	r += 2;
	X[r][c] = 'S';
	X[r][++c] = ':';
	X[r][++c] = ' ';
	X[r][++c] = 'T';
	X[r][++c] = 'o';
	X[r][++c] = ' ';
	X[r][++c] = 'G';
	X[r][++c] = 'o';
	X[r][++c] = ' ';
	X[r][++c] = 'D';
	X[r][++c] = 'o';
	X[r][++c] = 'w';
	X[r][++c] = 'n';
	c = 4;
	r += 2;
	X[r][c] = 'D';
	X[r][++c] = ':';
	X[r][++c] = ' ';
	X[r][++c] = 'T';
	X[r][++c] = 'o';
	X[r][++c] = ' ';
	X[r][++c] = 'G';
	X[r][++c] = 'o';
	X[r][++c] = ' ';
	X[r][++c] = 'R';
	X[r][++c] = 'i';
	X[r][++c] = 'g';
	X[r][++c] = 'h';
	X[r][++c] = 't';
	c = 4;
	r += 2;
	X[r][c] = 'Q';
	X[r][++c] = ':';
	X[r][++c] = ' ';
	X[r][++c] = 'T';
	X[r][++c] = 'o';
	X[r][++c] = ' ';
	X[r][++c] = 'J';
	X[r][++c] = 'u';
	X[r][++c] = 'm';
	X[r][++c] = 'p';
	X[r][++c] = ' ';
	X[r][++c] = 'L';
	X[r][++c] = 'e';
	X[r][++c] = 'f';
	X[r][++c] = 't';
	c = 4;
	r += 2;
	X[r][c] = 'E';
	X[r][++c] = ':';
	X[r][++c] = ' ';
	X[r][++c] = 'T';
	X[r][++c] = 'o';
	X[r][++c] = ' ';
	X[r][++c] = 'J';
	X[r][++c] = 'u';
	X[r][++c] = 'm';
	X[r][++c] = 'p';
	X[r][++c] = ' ';
	X[r][++c] = 'R';
	X[r][++c] = 'i';
	X[r][++c] = 'g';
	X[r][++c] = 'h';
	X[r][++c] = 't';
}
void HowToPlay2(char X[][80])
{
	for (int r = 0; r < 24; r++)
	{
		for (int c = 0; c < 80; c++)
		{
			X[r][c] = ' ';
		}
	}
	//charcter 2
	int rHero = 10; int cHero = 60;
	X[rHero][cHero] = ' ';
	X[rHero + 1][cHero - 2] = '[';
	X[rHero + 1][cHero + 2] = ']';
	X[rHero + 1][cHero + 1] = 224;
	X[rHero + 1][cHero - 1] = 227;
	X[rHero + 1][cHero] = '^';
	X[rHero + 2][cHero] = 177;
	X[rHero + 2][cHero - 1] = '/';
	X[rHero + 2][cHero + 1] = '\\';
	X[rHero + 3][cHero - 1] = '/';
	X[rHero + 3][cHero + 1] = '\\';
	X[rHero - 1][cHero - 2] = 'D';
	X[rHero - 1][cHero - 1] = 'a';
	X[rHero - 1][cHero] = 'v';
	X[rHero - 1][cHero + 1] = 'i';
	X[rHero - 1][cHero + 2] = 'd';
	int c = 3, r = 3;
	X[r][++c] = 'C';
	X[r][++c] = 'o';
	X[r][++c] = 'n';
	X[r][++c] = 't';
	X[r][++c] = 'r';
	X[r][++c] = 'o';
	X[r][++c] = 'l';
	X[r][++c] = 's';
	X[r][++c] = ' ';
	X[r][++c] = 'o';
	X[r][++c] = 'f';
	X[r][++c] = ' ';
	X[r][++c] = 't';
	X[r][++c] = 'h';
	X[r][++c] = 'e';
	X[r][++c] = ' ';
	X[r][++c] = 's';
	X[r][++c] = 'e';
	X[r][++c] = 'c';
	X[r][++c] = 'o';
	X[r][++c] = 'n';
	X[r][++c] = 'd';
	X[r][++c] = ' ';
	X[r][++c] = 'H';
	X[r][++c] = 'e';
	X[r][++c] = 'r';
	X[r][++c] = 'o';
	X[r][++c] = ' ';
	X[r][++c] = ':';
	c = 4;
	r += 2;
	X[r][c] = 'H';
	X[r][++c] = ':';
	X[r][++c] = ' ';
	X[r][++c] = 'T';
	X[r][++c] = 'o';
	X[r][++c] = ' ';
	X[r][++c] = 'G';
	X[r][++c] = 'o';
	X[r][++c] = ' ';
	X[r][++c] = 'l';
	X[r][++c] = 'e';
	X[r][++c] = 'f';
	X[r][++c] = 't';
	c = 4;
	r += 2;
	X[r][c] = 'U';
	X[r][++c] = ':';
	X[r][++c] = ' ';
	X[r][++c] = 'T';
	X[r][++c] = 'o';
	X[r][++c] = ' ';
	X[r][++c] = 'J';
	X[r][++c] = 'm';
	X[r][++c] = 'p';
	X[r][++c] = 'u';
	X[r][++c] = ' ';
	X[r][++c] = 'u';
	X[r][++c] = 'p';
	c = 4;
	r += 2;
	X[r][c] = 'J';
	X[r][++c] = ':';
	X[r][++c] = ' ';
	X[r][++c] = 'T';
	X[r][++c] = 'o';
	X[r][++c] = ' ';
	X[r][++c] = 'G';
	X[r][++c] = 'o';
	X[r][++c] = ' ';
	X[r][++c] = 'D';
	X[r][++c] = 'o';
	X[r][++c] = 'w';
	X[r][++c] = 'n';
	c = 4;
	r += 2;
	X[r][c] = 'J';
	X[r][++c] = ':';
	X[r][++c] = ' ';
	X[r][++c] = 'T';
	X[r][++c] = 'o';
	X[r][++c] = ' ';
	X[r][++c] = 'G';
	X[r][++c] = 'o';
	X[r][++c] = ' ';
	X[r][++c] = 'R';
	X[r][++c] = 'i';
	X[r][++c] = 'g';
	X[r][++c] = 'h';
	X[r][++c] = 't';
	c = 4;
	r += 2;
	X[r][c] = 'Y';
	X[r][++c] = ':';
	X[r][++c] = ' ';
	X[r][++c] = 'T';
	X[r][++c] = 'o';
	X[r][++c] = ' ';
	X[r][++c] = 'J';
	X[r][++c] = 'u';
	X[r][++c] = 'm';
	X[r][++c] = 'p';
	X[r][++c] = ' ';
	X[r][++c] = 'L';
	X[r][++c] = 'e';
	X[r][++c] = 'f';
	X[r][++c] = 't';
	c = 4;
	r += 2;
	X[r][c] = 'I';
	X[r][++c] = ':';
	X[r][++c] = ' ';
	X[r][++c] = 'T';
	X[r][++c] = 'o';
	X[r][++c] = ' ';
	X[r][++c] = 'J';
	X[r][++c] = 'u';
	X[r][++c] = 'm';
	X[r][++c] = 'p';
	X[r][++c] = ' ';
	X[r][++c] = 'R';
	X[r][++c] = 'i';
	X[r][++c] = 'g';
	X[r][++c] = 'h';
	X[r][++c] = 't';

}
void HowToPlay3(char X[][80])
{
	for (int r = 0; r < 24; r++)
	{
		for (int c = 0; c < 80; c++)
		{
			X[r][c] = ' ';
		}
	}
	int r = 3, c = 28;
	X[r][c] = 'T';
	X[r][++c] = 'h';
	X[r][++c] = 'e';
	X[r][++c] = 's';
	X[r][++c] = 'e';
	X[r][++c] = ' ';
	X[r][++c] = 'A';
	X[r][++c] = 'r';
	X[r][++c] = 'e';
	X[r][++c] = ' ';
	X[r][++c] = 'O';
	X[r][++c] = 'u';
	X[r][++c] = 'r';
	X[r][++c] = ' ';
	X[r][++c] = 'E';
	X[r][++c] = 'n';
	X[r][++c] = 'e';
	X[r][++c] = 'm';
	X[r][++c] = 'i';
	X[r][++c] = 'e';
	X[r][++c] = 's';
	X[r][++c] = ' ';
	X[r][++c] = ':';
	r += 7;
	c = 9;
	int cenemy1 = 14;
	int renemy1 = 12;
	X[renemy1][cenemy1] = '~';
	X[renemy1][cenemy1 - 1] = '-';
	X[renemy1][cenemy1 + 1] = '-';
	X[renemy1 + 1][cenemy1] = '.';
	X[renemy1 + 1][cenemy1 + 2] = '^';
	X[renemy1 + 1][cenemy1 - 2] = '^';
	X[renemy1 + 1][cenemy1 - 3] = '(';
	X[renemy1 + 1][cenemy1 - 4] = '(';
	X[renemy1 + 1][cenemy1 + 3] = ')';
	X[renemy1 + 1][cenemy1 + 4] = ')';
	X[r][c] = 'M';
	X[r][++c] = 'r';
	X[r][++c] = '.';
	X[r][++c] = ' ';
	X[r][++c] = 'P';
	X[r][++c] = 'u';
	X[r][++c] = 'm';
	X[r][++c] = 'k';
	X[r][++c] = 'i';
	X[r][++c] = 'n';
	r = 16;
	c = 7;
	X[r][c] = 'M';
	X[r][++c] = 'r';
	X[r][++c] = '.';
	X[r][++c] = ' ';
	X[r][++c] = 'P';
	X[r][++c] = 'u';
	X[r][++c] = 'm';
	X[r][++c] = 'k';
	X[r][++c] = 'i';
	X[r][++c] = 'n';
	X[r][++c] = ' ';
	X[r][++c] = 'h';
	X[r][++c] = 'a';
	X[r][++c] = 't';
	X[r][++c] = 'e';
	X[r][++c] = 's';
	X[r][++c] = ' ';
	r++, c = 7;
	X[r][++c] = 't';
	X[r][++c] = 'o';
	X[r][++c] = ' ';
	X[r][++c] = 'b';
	X[r][++c] = 'e';
	X[r][++c] = ' ';
	X[r][++c] = 's';
	X[r][++c] = 't';
	X[r][++c] = 'o';
	X[r][++c] = 'o';
	X[r][++c] = 'd';
	X[r][++c] = ' ';
	X[r][++c] = 'o';
	X[r][++c] = 'n';
	X[r][++c] = '.';
	int renemy = 12, cenemy = 38;
	X[renemy][cenemy] = 196;
	X[renemy][cenemy + 1] = 196;
	X[renemy][cenemy + 2] = '/';
	X[renemy][cenemy + 3] = 92;
	X[renemy + 1][cenemy + 3] = ')';
	X[renemy + 1][cenemy + 4] = 196;
	X[renemy + 1][cenemy + 5] = 196;
	X[renemy + 2][cenemy + 5] = 231;
	X[renemy + 2][cenemy + 4] = 231;
	X[renemy + 2][cenemy + 1] = '^';
	X[renemy + 2][cenemy] = '^';
	X[renemy + 1][cenemy + 1] = 42;
	X[renemy + 1][cenemy] = 42;
	X[renemy][cenemy - 2] = '/';
	X[renemy][cenemy - 1] = 92;
	X[renemy + 1][cenemy - 2] = '(';
	X[renemy + 1][cenemy - 3] = 196;
	X[renemy + 1][cenemy - 4] = 196;
	X[renemy + 2][cenemy - 3] = 231;
	X[renemy + 2][cenemy - 4] = 231;
	r = 10, c = 35;
	X[r][c] = 'V';
	X[r][++c] = 'a';
	X[r][++c] = 'm';
	X[r][++c] = 'p';
	X[r][++c] = 'y';
	X[r][++c] = 'r';
	X[r][++c] = 'a';
	r = 16, c = 33;
	X[r][c] = 'D';
	X[r][++c] = 'o';
	X[r][++c] = 'n';
	X[r][++c] = '`';
	X[r][++c] = 't';
	X[r][++c] = ' ';
	X[r][++c] = 'g';
	X[r][++c] = 'e';
	X[r][++c] = 't';
	X[r][++c] = ' ';
	X[r][++c] = 't';
	X[r][++c] = 'o';
	X[r][++c] = 'o';
	r++, c = 32;
	X[r][++c] = 'c';
	X[r][++c] = 'l';
	X[r][++c] = 'o';
	X[r][++c] = 's';
	X[r][++c] = 'e';
	X[r][++c] = ' ';
	X[r][++c] = 'o';
	X[r][++c] = 'r';
	X[r][++c] = ' ';
	X[r][++c] = 'e';
	X[r][++c] = 'l';
	X[r][++c] = 's';
	X[r][++c] = 'e';
	int rWhitch = 12, cWhitch = 65;
	X[rWhitch][cWhitch] = '/';
	X[rWhitch][cWhitch + 1] = '\\';
	X[rWhitch][cWhitch - 1] = '_';
	X[rWhitch][cWhitch + 2] = '_';
	X[rWhitch + 1][cWhitch + 3] = '\\';
	X[rWhitch + 1][cWhitch + 4] = '\\';
	X[rWhitch + 1][cWhitch + 5] = '\\';
	X[rWhitch + 1][cWhitch - 2] = '/';
	X[rWhitch + 1][cWhitch - 3] = '/';
	X[rWhitch + 1][cWhitch - 1] = '`';
	X[rWhitch + 1][cWhitch + 1] = '`';
	X[rWhitch + 1][cWhitch] = '<';
	X[rWhitch + 1][cWhitch + 2] = '.';
	X[rWhitch + 2][cWhitch - 4] = '-';
	X[rWhitch + 2][cWhitch - 3] = '-';
	X[rWhitch + 2][cWhitch - 2] = '-';
	X[rWhitch + 2][cWhitch - 1] = '(';
	X[rWhitch + 2][cWhitch] = '_';
	X[rWhitch + 2][cWhitch + 1] = '_';
	X[rWhitch + 2][cWhitch + 2] = '_';
	X[rWhitch + 2][cWhitch + 3] = ')';
	X[rWhitch + 2][cWhitch + 4] = '-';
	X[rWhitch + 2][cWhitch + 5] = '-';
	X[rWhitch + 2][cWhitch + 6] = '<';
	X[rWhitch + 3][cWhitch + 1] = 'J';
	X[rWhitch + 3][cWhitch + 2] = 'J';
	r = 10, c = 60;
	X[r][c] = 'T';
	X[r][++c] = 'h';
	X[r][++c] = 'e';
	X[r][++c] = ' ';
	X[r][++c] = 'e';
	X[r][++c] = 'v';
	X[r][++c] = 'i';
	X[r][++c] = 'l';
	X[r][++c] = ' ';
	X[r][++c] = 'W';
	X[r][++c] = 'h';
	X[r][++c] = 'i';
	X[r][++c] = 't';
	X[r][++c] = 'c';
	X[r][++c] = 'h';
	r = 16, c = 33;
	X[r][c] = 'D';
	X[r][++c] = 'o';
	X[r][++c] = 'n';
	X[r][++c] = '`';
	X[r][++c] = 't';
	X[r][++c] = ' ';
	X[r][++c] = 'g';
	X[r][++c] = 'e';
	X[r][++c] = 't';
	X[r][++c] = ' ';
	X[r][++c] = 't';
	X[r][++c] = 'o';
	X[r][++c] = 'o';
	r = 16, c = 60;
	X[r][++c] = 'I';
	X[r][++c] = 's';
	X[r][++c] = ' ';
	X[r][++c] = 'r';
	X[r][++c] = 'e';
	X[r][++c] = 'a';
	X[r][++c] = 'd';
	X[r][++c] = 'y';
	X[r][++c] = ' ';
	X[r][++c] = 't';
	X[r][++c] = 'o';
	X[r][++c] = ' ';
	r++, c = 55;
	X[r][++c] = 'c';
	X[r][++c] = 'a';
	X[r][++c] = 's';
	X[r][++c] = 't';
	X[r][++c] = ' ';
	X[r][++c] = 'h';
	X[r][++c] = 'e';
	X[r][++c] = 'r';
	X[r][++c] = ' ';
	X[r][++c] = 's';
	X[r][++c] = 'p';
	X[r][++c] = 'e';
	X[r][++c] = 'l';
	X[r][++c] = 'l';
	X[r][++c] = ' ';
	X[r][++c] = 'o';
	X[r][++c] = 'n';
	X[r][++c] = ' ';
	X[r][++c] = 'Y';
	X[r][++c] = 'O';
	X[r][++c] = 'U';
}
void detectwin(int rHero, int rHero2, int cHero, int cHero2, int& win, int& flagelev2)
{
	if (cHero == 142 || cHero == 143 || cHero == 144 || cHero == 145 || cHero == 146 || cHero == 147 || cHero == 148 || cHero == 149 || cHero == 141)
	{
		if (rHero == 11)
		{
			win = 1;
		}
	}
	if (cHero2 == 142 || cHero2 == 143 || cHero2 == 144 || cHero2 == 145 || cHero2 == 146 || cHero2 == 147 || cHero2 == 148 || cHero2 == 149 || cHero2 == 141)
	{
		if (rHero2 == 11)
		{
			win = 1;
		}
	}
	if (rHero == 21)
	{
		if (cHero == 126 || cHero == 127 || cHero == 128 || cHero == 129)
		{
			flagelev2 *= -1;
		}
	}
	if (rHero2 == 21)
	{
		if (cHero2 == 126 || cHero2 == 127 || cHero2 == 128 || cHero2 == 129)
		{
			flagelev2 *= -2;
		}
	}
}
void GameOverwin(char y[][80])
{
	for (int r = 0; r < 24; r++)
	{
		for (int c = 0; c < 80; c++)
		{
			y[r][c] = ' ';
		}
	}
	y[12][36] = 'Y';
	y[12][37] = 'o';
	y[12][38] = 'u';
	y[12][39] = ' ';
	y[12][41] = 'W';
	y[12][42] = 'o';
	y[12][43] = 'n';
	y[12][44] = ' ';
	y[12][45] = '!';
	y[14][40] = 'G';
	y[14][41] = 'G';
}
void coutgameover(char y[][80])
{
	system("cls");
	for (int r = 0; r < 24; r++)
	{
		for (int c = 0; c < 80; c++)
		{
			cout << y[r][c];
		}
	}
}
void main()
{
	char mainmenu[24][80];
	char X[50][200];
	char htp[24][80];
	int cMultipleB[200];
	int rMultipleB[3];
	int rlaser = 26, claser = 198, Xdirlaser = -2;
	int rplayer2 = 43;
	int cplayer2 = 65;
	int rArrow = 45, cArrow = 10, dir = 1, ct = 0;
	int rHero = 43, cHero = 45;
	char uMove = ' ';
	int cBullet = 0, rBullet = 0;
	int flag = -1;
	int relevator = 48;
	int cstart, cend, rstart, rend;
	int rPlatform = 10;
	int cPlatform = 64;
	int XdirPlatform = -1;
	int ctscrolling = 0;
	int ctjump = 0;
	int lastpos = 0;
	cstart = 0;
	cend = 80;
	rstart = 26;
	rend = 50;
	int lives = 3;
	int lives2 = 3;
	char Y[24][80];
	char s = 's';
	int relev2 = 25;
	int flagelev2 = -1;
	int dirHero = -1, dirplayer2 = -1, renemy = 31, cenemy = 60, flagTele = 1, flagenter = 0, flagbullet1 = 0;
	char flagbullet2 = 'n';
	int renemy1, cenemy1;
	cenemy1 = 20;
	renemy1 = 46;
	int enemy1Dead = 0, enemy2dead = 0, enemy3dead = 0;
	int rWhitch = 23, cWhitch = 60;
	int fMB = 0;
	int win = 0;
	int more = 1;
	for (;;)
	{
		MainMenu(mainmenu);
		CoutMenuToScreen(mainmenu);
		s = _getch();
		if (s == ' ')
		{
			break;
		}
	}
	for (;;)
	{
		HowToPlay(htp);
		CoutMenuToScreen(htp);
		s = _getch();
		if (s == ' ')
		{
			break;
		}
	}
	for (;;)
	{
		HowToPlay2(htp);
		CoutMenuToScreen(htp);
		s = _getch();
		if (s == ' ')
		{
			break;
		}
	}
	for (;;)
	{
		HowToPlay3(htp);
		CoutMenuToScreen(htp);
		s = _getch();
		if (s == ' ')
		{
			break;
		}
	}
	for (;;)
	{
		for (; !_kbhit();)
		{
			ClearAndDrawFixedObject(X);
			DrawElevator(relevator, X);
			MoveElevatorup(relevator, flag, rHero, cHero, rplayer2, cplayer2);
			MoveElevatorDown(flag, relevator);
			DrawElevator2(relev2, X);
			MoveElevatorup2(relev2, flagelev2, rHero, cHero, rplayer2, cplayer2);
			MoveElevatorDown2(flagelev2, relev2);
			MoveLaser(rlaser, claser, Xdirlaser);
			DrawLaser(rlaser, claser, X);
			Damagelazer(rHero, cHero, rplayer2, cplayer2, rlaser, claser, lives, lives2, rstart, rend, cstart, cend);
			DrawHero(rHero, cHero, X, uMove, rplayer2, cplayer2);
			if (enemy1Dead != 1)
			{
				DrawEnemy1(X, renemy1, cenemy1);
				DamageEnemy1(lives, lives2, cHero, rHero, cplayer2, rplayer2, enemy1Dead);
			}
			Gravity(X, rHero, cHero);
			Gravity(X, rplayer2, cplayer2);
			drawspikes(X);
			Spikesdamage(rHero, cHero, rplayer2, cplayer2, lives, lives2);

			if (fMB == 1)
			{
				drawMB(cMultipleB, rMultipleB, X, lastpos, more, fMB);
			}
			if (flagbullet1 == 1)
			{
				DrawBullet1(cBullet, rBullet, X, dirHero, flagbullet1);
			}
			if (flagbullet2 == 'y')
			{
				DrawBullet2(cBullet, rBullet, X, dirplayer2, flagbullet2);
			}
			KillEnemy2(X, rWhitch, cWhitch, enemy3dead, rBullet, cBullet);
			if (enemy3dead < 4)
			{
				MoveWhitch(cHero, rHero, rplayer2, cplayer2, rWhitch, cWhitch);
				DrawEnemy3(rWhitch, cWhitch, X);
				damagewhitch(rHero, cHero, rWhitch, cWhitch, rend, rstart, cend, cstart, lives, lives2, cplayer2, rplayer2);
			}
			KillEnemy(X, renemy, cenemy, enemy2dead, rBullet, cBullet);
			if (enemy2dead < 4)
			{
				DrawEnemy2(X, renemy, cenemy);
				damageEnemy2(rHero, cHero, rplayer2, cplayer2, lives, lives2, rstart, rend, cstart, cend, cenemy);
				MoveEnemy2(renemy, cenemy, rHero, cHero, rplayer2, cplayer2);
			}
			CoutMatToScreen(X, rstart, rend, cstart, cend);
		}
		uMove = _getch();
		MoveHero(rHero, cHero, uMove, X, rplayer2, cplayer2, flag, ctjump, dirHero, dirplayer2, flagTele);
		DrawHero(rHero, cHero, X, uMove, rplayer2, cplayer2);
		if (uMove == 'c')
		{
			ctscrolling++;
		}
		if (ctscrolling % 2 != 0)
		{
			scrolling(rplayer2, cplayer2, rstart, rend, cstart, cend);
			flagTele = 2;
		}
		else
		{
			scrolling(rHero, cHero, rstart, rend, cstart, cend);
			flagTele = 1;
		}
		Gravity(X, rHero, cHero);
		Gravity(X, rplayer2, cplayer2);
		if (uMove == 't')
		{
			flagenter = 0;
			if (flagTele == 1)
			{
				Teleport1(cHero, rHero, flagenter);
				if (flagenter == 0)
				{
					teleport2(cHero, rHero);
				}
				scrolling(rHero, cHero, rstart, rend, cstart, cend); 
			}
			if (flagTele == 2)
			{
				Teleport1(cplayer2, rplayer2, flagenter);
				if (flagenter == 0)
				{
					teleport2(cplayer2, rplayer2);
				}
				scrolling(rplayer2, cplayer2, rstart, rend, cstart, cend);
			}
		}
		if (uMove == 'f')
		{
			shoot1(cBullet, rBullet, dirHero, X, cHero, rHero, flagbullet1);

		}
		if (uMove == 'g')
		{
			shoot2(cBullet, rBullet, dirplayer2, X, cplayer2, rplayer2, flagbullet2);
		}
		if (uMove == 'r')
		{
			shootMB(dirHero, cHero, rHero, X, cMultipleB, rMultipleB, lastpos);
			fMB = 1;
		}
		ctjump++;
		if (lives == 0 || lives2 == 0)
		{
			break;
		}
		detectwin(rHero, rplayer2, cHero, cplayer2, win, flagelev2);
		if (win == 1)
		{
			break;
		}
	}
	if (win == 0)
	{
		for (;;)
		{
			GameOver(Y);
			coutgameover(Y);
		}
	}
	if (win == 1)
	{
		for (;;)
		{
			GameOverwin(Y);
			coutgameover(Y);
		}
	}
}