#include<iostream>
using namespace std;
char matrix[3][3] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char player = 'X';

void PrintMatrix()
{
	system("cls");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void play()
{
	char pos;
	cout << "enter your position->(" << player << ")--> ";
	cin >> pos;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (matrix[i][j] == pos){ matrix[i][j] = player; }
		}
		cout << endl;
	}
	if (player == 'X')
	{
		player = 'O';
	}
	else
	{
		player = 'X';
	}

}
char win()
{
	int Xc = 0, Oc = 0;
	///////////////////////////
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (matrix[i][j] == 'X') Xc++;
			else if (matrix[i][j] == 'O')Oc++;
			if (Xc == 3 || Oc == 3)
			{
				return Xc > Oc ? 'X' : 'O';
			}
		}
		Xc = 0; Oc = 0;
		cout << endl;
	}
	//////////////////////////////
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (matrix[j][i] == 'X') Xc++;
			else if (matrix[j][i] == 'O')Oc++;
			if (Xc == 3 || Oc == 3)
			{
				return Xc > Oc ? 'X' : 'O';
			}
		}
		Xc = 0; Oc = 0;
		cout << endl;
	}
	//////////////////////////////////////////
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (matrix[0][0] == 'X' &&matrix[1][1] == 'X'&&matrix[2][2] == 'X')return 'X';
			else if (matrix[0][0] == 'O' &&matrix[1][1] == 'O'&&matrix[2][2] == 'O')return 'O';
			else if (matrix[0][2] == 'X' &&matrix[1][1] == 'X'&&matrix[2][0] == 'X')return 'X';
			else if (matrix[0][2] == 'O' &&matrix[1][1] == 'O'&&matrix[2][0] == 'O')return 'O';
		}
		cout << endl;
	}
	//////////////////////////////////////
	int counter = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (matrix[i][j] != 'X' && matrix[i][j] != 'O') counter++;
		}

		cout << endl;
	}
	if (counter == 0) return'F';
	return '.';
}
int main()
{
	while (win() == '.')
	{
		PrintMatrix();
		play();

	}
	char w = win();
	if (w == 'F')cout << "there is on winner \n";
	else
	{
		cout << "this player is winning ->" << w << endl;
	}
	system("pause");
	return 0;
}