// link to this problem : https://practice.geeksforgeeks.org/problems/permutation-with-spaces/0
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

const int max_t = 150000;

string s;
vector<char> ans[max_t];
vector<char> curAns;
int cntAns;

void bt(int ind, bool space);

int main()
{
	//freopen("a.in", "r", stdin);
	int T;
	cin >> T;
	for(int t = 0; t < T; t++)
	{
		for(int i = 0; i < max_t; i++) ans[i].clear();
		cntAns = 0;
		s.clear();
		
		cin >> s;
		
		curAns.clear();
		bt(0, true);
		
		for(int i = 0; i < cntAns; i++)
		{
			cout << "(";
			for(int j = 0; j < ans[i].size(); j++)
				cout << ans[i][j];
			cout << ")";
		}
		cout << endl;
		
	}
}

void bt(int ind, bool space)
{
	if(space == true && ind != 0)
		curAns.push_back(' ');
	curAns.push_back(s[ind]);
	
	if(ind == s.size()-1)
	{
		for(int i = 0; i < curAns.size(); i++)
			ans[cntAns].push_back(curAns[i]);
		cntAns++;
		curAns.pop_back();
		if(space == true)
			curAns.pop_back();
		return;
	}
	
	if(ind+1 <= s.size()-1)
	{
		bt(ind+1, true);
		bt(ind+1, false);
	}
	
	curAns.pop_back();
	if(space == true)
		curAns.pop_back();
	
}









