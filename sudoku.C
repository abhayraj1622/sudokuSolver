#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bits/stdc++.h>
#include <utility>
#include "validSudoku.h"

using namespace std;

vector<vector < int>> row = vector<vector < int>> (10, vector<int> (10, 0));
vector<vector < int>> column = vector<vector < int>> (10, vector<int> (10, 0));
vector<vector < int>> block = vector<vector < int>> (10, vector<int> (10, 0));
vector<pair<int, int>> tbf;

void sudokuGrid(vector<vector < int>> &board)
{
	int i = 0;
	cout << "\t\t";
	for (i = 0; i <= 9; i++)
		cout << "———";
	cout << endl;
	for (int row = 0; row < 9; row++)
	{
		cout << "\t\t";
		for (int col = 0; col < 9; col++)
		{
			if (col == 3 || col == 6)
				cout << "| ";
			if (col == 0)
				cout << "  | ";
			if(board[row][col] != 0)
				cout << board[row][col] << " ";
			else
				cout << "_ ";
			if (col == 8)
				cout << "| ";
		}

		if (row == 2 || row == 5)
		{
			cout << endl;
			cout << "\t\t";
			for (i = 0; i <= 9; i++)
				cout << "———";
		}

		cout << endl;
	}
	cout << "\t\t";
	for (i = 0; i <= 9; i++)
		cout << "———";
	cout << endl;
}

bool solver(vector<vector < int>> &board, int x)
{
	if (x == tbf.size())
		return true;
	int i = tbf[x].first;
	int j = tbf[x].second;

	for (int k = 1; k < 10; k++)
	{
		if (row[i][k] ||
			column[j][k] ||
			block[i / 3 * 3 + j / 3][k])
			continue;
		board[i][j] = k;
		row[i][k] = 1;
		column[j][k] = 1;
		block[i / 3 * 3 + j / 3][k] = 1;
		if (solver(board, x + 1))
			return true;
		else
		{
			board[i][j] = 0;
			row[i][k] = 0;
			column[j][k] = 0;
			block[i / 3 * 3 + j / 3][k] = 0;
		}
	}

	return false;
}

void solveSudoku(vector<vector < int>> &board)
{
	int i = 0;
	int j = 0;
	int number;
	int x = 1;
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (board[i][j] == 0)
			{
				tbf.push_back(make_pair(i, j));
				continue;
			}

			number = board[i][j];
			row[i][number] = 1;
			column[j][number] = 1;
			block[i / 3 * 3 + j / 3][number] = 1;
		}
	}

	solver(board, 0);
}

int main()
{
	vector<vector < int>> board = {
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0 }
	};

	int check = 1;
	int i = 0;
	int j = 0;
	int number;
	char button;
	
	cout << "\n\t\t\t\tSUDOKU SOLVER\n"<< endl;
	cout << "\t\t\t\t Instructions" << endl;
	cout << "\t\t * Enter character e to solve your sudoku.\n\t\t * Enter character i followed by position and number ( 0-indexed )\n\t\t * EG : To enter the number 8 in row 0 and col 5 \n\t\t\t\t  i 0 5 8"<<endl;
	
		while (check)
		{
			cin >> button;
			switch (button)
			{
				case 'i':
					cin >> i >> j >> number;
					board[i][j] = number;
					break;
				case 'e':
					check = 0;
					break;
			}
		}
	cout << "\t\t\tGIVEN SUDOKU"<<endl;
	sudokuGrid(board);
	cout << endl;
	if(isValidSudoku(board)){
		solveSudoku(board);
		cout << "\t\t\tSOLVED SUDOKU"<<endl;
		sudokuGrid(board);
		cout << endl;
	}
	else{
		cout << "\t\t\tINVALID SUDOKU"<<endl;
	}
	return 0;
}

/*
	TESTCASES: 
	(1)
i 0 3 8
i 0 5 1
i 1 7 4
i 1 8 3
i 2 0 5
i 3 4 7
i 3 6 8
i 4 6 1
i 5 1 2
i 5 4 3
i 6 0 6
i 6 7 7
i 6 8 5
i 7 2 3
i 7 3 4
i 8 3 2
i 8 6 6
e
	(2)
i 0 6 2
i 1 1 8
i 1 5 7
i 1 7 9
i 2 0 6 
i 2 2 2
i 2 6 5
i 3 1 7
i 3 4 6
i 4 3 9
i 4 5 1
i 5 4 2
i 5 7 4
i 6 2 5
i 6 6 6
i 6 8 3
i 7 1 9
i 7 3 4
i 7 7 7
i 8 2 6 
e

*/
