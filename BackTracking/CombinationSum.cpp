//link to this problem : https://practice.geeksforgeeks.org/problems/combination-sum/0
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

const int max_t = 100000;
int n;
vector<int> vec;
vector<int> ans[max_t];
vector<int> curAns;
int cntAns;
int heap;

void bt(int ind, int sum);

int main()
{
	//freopen("a.in", "r", stdin);
	int T;
	cin >> T;
	for(int t = 0; t < T; t++)
	{
		for(int i = 0; i < max_t; i++) ans[i].clear();
		cntAns = 0;
		vec.clear();
			
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			int a;		
			cin >> a;
			vector<int>::iterator p = find(vec.begin(), vec.end(), a);
			if(p == vec.end())
				vec.push_back(a);
		}
		sort(vec.begin(), vec.end());
		
		cin >> heap;		
		
		for(int i = 0; i < vec.size(); i++)
			if(vec[i] <= heap)
			{
				int num = vec[i];
				bt(i, num);
			}	
		
		if(cntAns == 0)
		{
			cout << "Empty" << endl;
			continue;
		}
		
		for(int i = 0 ; i < cntAns; i++)
		{
			cout << "(";
			for(int j = 0; j < ans[i].size(); j++)
			{
				cout << ans[i][j];
				if(j+1 != ans[i].size())
					cout << " "; 
			}
			cout << ")";	
		}
		cout << endl;
	}
}


void bt(int ind, int sum)
{
	
	curAns.push_back(vec[ind]);
	
	if(sum == heap)
	{
		for(int i = 0; i < curAns.size(); i++)
			ans[cntAns].push_back(curAns[i]);
		cntAns++;
		
		curAns.pop_back();
		return;
	}
	
	for(int curInd = ind; curInd < vec.size(); curInd++)
	{
		if(sum+vec[curInd] <= heap)
		{
			int curSum = sum+vec[curInd];
			bt(curInd, curSum);
		}
	}
		
	curAns.pop_back();
	
}

















