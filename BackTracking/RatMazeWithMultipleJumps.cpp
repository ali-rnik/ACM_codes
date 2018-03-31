// Link to this question : https://practice.geeksforgeeks.org/problems/rat-maze-with-multiple-jumps/0

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>

using namespace std;

const int max_t = 50;

int mat[max_t][max_t];
int path[max_t][max_t];
bool vis[max_t][max_t];
int n;
int xmove[] = {0, 1, 0, 2, 0, 3, 0, 4, 0, 5};
int ymove[] = {1, 0, 2, 0, 3, 0, 4, 0, 5, 0};
bool success;

void bt(int x, int y);

int main()
{
	//freopen("a.in", "r", stdin);
	
	int T;
	cin >> T;
	
	for(int t = 0; t < T; t++)
	{	
		cin >> n;
		
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
			{
				path[i][j] = 0;
				vis[i][j] = false;
				int a;
				cin >> a;
				mat[i][j] = a;
			}
		
		success = false;
		bt(0, 0);
		
		if(success == true)
			for(int i = 0; i < n; i++)
			{	
				for(int j = 0; j < n; j++)
					cout << path[i][j] << " ";
				cout << endl;
			}
		
		if(success == false)
			cout << -1 << endl;

	}
}

void bt(int x, int y)
{
	vis[x][y] = true;
	path[x][y] = 1;

	if(success == true)
		return;
	
	if(n == 1)
	{
		success = true;
		return;
	}
	
	for(int i = 0; i < 10; i++)
	{
	
		int r = x + xmove[i];
		int c = y + ymove[i];	
			
		if(xmove[i] <= mat[x][y] && ymove[i] <= mat[x][y])
		{
			if(r == n-1 && c == n-1)
				success = true;
			
			if(mat[r][c] != 0 && vis[r][c] == false && r >= 0 && c >= 0 && r < n && c < n)
				bt(r, c);
		}
		
		if(success == true)
		{
			path[r][c] = 1;
			return;
		}
	}
	
	path[x][y] = 0;
}

void gdb()
{
	cout << endl;
	cout << "matrix: " << endl;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}
	
	cout << endl;
	cout << "path: " << endl;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			cout << path[i][j] << " ";
		cout << endl;
	}
	
	cout << endl;
	cout << "vis: " << endl;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			cout << vis[i][j] << " ";
		cout << endl;
	}	
}
