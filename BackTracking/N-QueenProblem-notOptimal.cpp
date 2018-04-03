// link to problem : https://practice.geeksforgeeks.org/problems/n-queen-problem/0
// this solution is not optimal and it will be time limit exceeded.
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

const int max_t = 20;

int mat[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
bool success;
bool curMat[max_t][max_t];
int xmv[] = {0, 1,  0, -1, 1, -1,  1, -1};
int ymv[] = {1, 0, -1,  0, 1, -1, -1,  1};
int n;

bool func();
void bt(int x, int y, int path);

int main()
{
	//freopen("a.in", "r", stdin);
	int T;
	cin >> T;
	for(int t = 0; t < T; t++)
	{

		cin >> n;
		
		bool atLeast = false;
		
		do
		{
			bool res = func();
			if(res == true)
			{
				atLeast = true;
				cout << "[";
				for(int i = 1; i <= n; i++)
					cout << mat[i] << " ";
				cout << "] "; 
			}
		}
		while( next_permutation(mat+1, mat+n+1) );
		
		if(atLeast == true)
			cout << endl;
		if(atLeast == false)
			cout << -1 << endl;
	}
	
	return 0;
	
}

bool func()
{

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			curMat[i][j] = false;

	success = true;
	
	for(int i = 1; i <= n; i++)
	{
		int x = i;
		int y = mat[i];
		curMat[x][y] = true;
		for(int j = 0; j < 8; j++)
		{
			bt(x, y, j);
			if(success == false)
				return false;
		}
	}
	
	return true;
}

void bt(int x, int y, int path)
{
	int r = xmv[path] + x;
	int c = ymv[path] + y;
	
	if(curMat[r][c] == true && r >= 1 && c >= 1 && r <= n && c <= n)
	{
		success = false;
		return;
	}
	
	if(curMat[r][c] == false && r >= 1 && c >= 1 && r <= n && c <= n)
		bt(r, c, path);
	
	if(success == false)
		return;		
}


void gdb()
{
	cout << endl;
	for(int i = 1; i <= n; i++)
	{	
		for(int j = 1; j <= n; j++)
			cout << curMat[i][j] << " ";
		cout << endl;
	}
}

