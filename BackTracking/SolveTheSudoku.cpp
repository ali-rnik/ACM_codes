// link to this problem : https://practice.geeksforgeeks.org/problems/solve-the-sudoku/0
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <queue>

using namespace std;

const int max_t = 15;

bool part[max_t][max_t];
bool row[max_t][max_t];
bool col[max_t][max_t];
int mat[max_t][max_t];
vector< pair<int, int> > vec;
bool success;

int wichPart(int i, int j);
void bt(int ind, int val);

int main()
{
	//freopen("a.in", "r", stdin);
	int T;
	cin >> T;
	for(int t = 0; t < T; t++)
	{
		vec.clear();
		for(int i = 0; i < max_t; i++)
			for(int j = 0; j < max_t; j++)
				part[i][j] = false, row[i][j] = false, col[i][j] = false;
	
		for(int i = 0; i < 9; i++)
			for(int j = 0; j < 9; j++)
			{
				int num;
				cin >> num;
				int p = wichPart(i, j);
				mat[i][j] = num;
				part[p][num] = true;
				row[i][num] = true;
				col[j][num] = true;
				
				if(num == 0)
					vec.push_back(make_pair(i, j));
			}
			
		for(int i = 1; i <= 9; i++)
		{
			success = false;
			int x = vec[0].first;
			int y = vec[0].second;
			int p = wichPart(x, y);
			if(row[x][i] == false && col[y][i] == false && part[p][i] == false)
				bt(0, i);
			if(success == true)
				break;
		}
		
		for(int i = 0; i < 9; i++)
			for(int j = 0; j < 9; j++)
				cout << mat[i][j] << " ";
		cout << endl;
	}
	
	return 0;
}

void bt(int ind, int val)
{
	int x = vec[ind].first;
	int y = vec[ind].second;
	int p = wichPart(x, y);
	
	row[x][val] = true;
	col[y][val] = true;
	part[p][val] = true;
	mat[x][y] = val;
	
	if(ind == vec.size()-1)
	{
		success = true;
		return;
	}
	
	int r = vec[ind+1].first;
	int c = vec[ind+1].second;
	int pp = wichPart(r, c);
	
	for(int newVal = 1; newVal <= 9; newVal++)
	{
		if(row[r][newVal] == false && col[c][newVal] == false && part[pp][newVal] == false)
			bt(ind+1, newVal);
		
		if(success == true)
			return;
	}
	
	row[x][val] = false;
	col[y][val] = false;
	part[p][val] = false;
	mat[x][y] = 0;
}

int wichPart(int i, int j)
{
	if(i < 3 && j < 3)
		return 0;
	
	if(i < 3 && j < 6)
		return 1;
	
	if(i < 3 && j < 9)
		return 2;
	
	if(i < 6 && j < 3)
		return 3;
		
	if(i < 6 && j < 6)
		return 4;
		
	if(i < 6 && j < 9)
		return 5;
		
	if(i < 9 && j < 3)
		return 6;
		
	if(i < 9 && j < 6)
		return 7;
		
	if(i < 9 && j < 9)
		return 8;
}













