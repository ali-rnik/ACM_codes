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

const int max_t = 1500;

vector<int> orib[max_t][max_t];
vector<int> ans[max_t];
vector<int> curAns;
bool colRowVis[max_t];
bool oribVis[max_t];
int xmv[] = {1,  1, -1, -1};
int ymv[] = {1, -1,  1, -1};
int n, cntAns;


void btOrib(int x, int y, int path, int mark);
void makeOribAndCol();
void bt(int x, int y, int finish);

int main()
{
	//freopen("a.in", "r", stdin);
	int T;
	cin >> T;
	for(int t = 0; t < T; t++)
	{
		cin >> n;
		makeOribAndCol();
		cntAns = 0;
		for(int i = 0; i < n; i++)
			bt(0, i, 0);
		
		if(cntAns == 0)
		{
			cout << -1 << endl;
			continue;
		}
		
		for(int i = 0; i < cntAns; i++)
		{
			cout << "[";
			for(int j = 0; j < ans[i].size(); j++)
				cout << ans[i][j]+1 << " ";
			cout << "] ";
		}
		cout << endl;
		
	}
	
	return 0;
	
}

void bt(int x, int y, int finish)
{

	curAns.push_back(y);
	colRowVis[y] = true;
	for(int i = 0; i < orib[x][y].size(); i++)
	{
		int tmp = orib[x][y][i];
		oribVis[tmp] = true;
	}
	
	if(finish == n-1)
	{
		for(int i = 0; i < n; i++)
			ans[cntAns].push_back(curAns[i]);
		cntAns++;
		curAns.pop_back();
		colRowVis[y] = false;
		for(int i = 0; i < orib[x][y].size(); i++)
		{
			int tmp = orib[x][y][i];
			oribVis[tmp] = false;
		}
		return;
	}
	
	for(int i = 0; i < n; i++)
	{
		//just checking vis	
		int r = x+1;
		int c = i;
		bool curCol = false, curOribF = false, curOribS = false, inGrid = true; 
		curCol = colRowVis[c];
		for(int j = 0; j < orib[r][c].size(); j++)
		{
			int tar = orib[r][c][j];
			if(oribVis[tar] == true && j == 0)
				curOribF = true;
			if(oribVis[tar] == true && j == 1)
				curOribS = true;
		}
		if(r >= 0 && c >= 0 && r < n && c < n)
			inGrid = false;
		
		if( (curCol | curOribF | curOribS | inGrid) == false )
			bt(r, c, finish+1);
		
	}	
	
	curAns.pop_back();
	colRowVis[y] = false;
	for(int i = 0; i < orib[x][y].size(); i++)
	{
		int tmp = orib[x][y][i];
		oribVis[tmp] = false;
	}
	
}

void makeOribAndCol()
{
	curAns.clear();
	
	for(int i = 0; i < max_t; i++)
		for(int j = 0; j < max_t; j++)
			orib[i][j].clear();
			
	for(int i = 0; i < max_t; i++) colRowVis[i] = false, ans[i].clear(), oribVis[i] = false;
	
	int mark = 0;
	int rightDown = 0;
	int leftDown  = 1;
	int upRight   = 2;
	int upLeft    = 3;
	
	orib[0][0].push_back(mark++);
	btOrib(0, 0, rightDown, mark-1);

	orib[0][n-1].push_back(mark++);
	btOrib(0, n-1, leftDown, mark-1);
	
	for(int i = 1; i < n-1; i++)
	{
		orib[0][i].push_back(mark++);
		btOrib(0, i, rightDown, mark-1);
		
		orib[0][i].push_back(mark++);
		btOrib(0, i, leftDown, mark-1);
	}
	
	for(int i = 1; i < n-1; i++)
	{
		orib[n-1][i].push_back(mark++);
		btOrib(n-1, i, upRight, mark-1);
		
		orib[n-1][i].push_back(mark++);
		btOrib(n-1, i, upLeft, mark-1);
	}

}

void btOrib(int x, int y, int path, int mark)
{
	int r = x + xmv[path];
	int c = y + ymv[path];
		
	if(r >= 0 && c >= 0 && r < n && c < n)
	{
		orib[r][c].push_back(mark);	
		btOrib(r, c, path, mark);
	}
}

void gdb()
{
	cout << endl;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k < orib[i][j].size(); k++)
				cout << orib[i][j][k];
			cout << "    ";
		}
		cout << endl;
	}
}


