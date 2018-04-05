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

vector<int> vec;
vector<int> curAns;
vector<int> ans[max_t];
int cntAns;
int heap;
int n;
bool vis[max_t];
map<string, bool> mp;

void bt(int ind, int sum);

int main()
{
	//freopen("a.in", "r", stdin);
	int T;
	cin >> T;
	for(int t = 0; t < T; t++)
	{
		for(int i = 0; i < max_t; i++) ans[i].clear(), vis[i] = false;
		vec.clear();
		cntAns = 0;
		

		cin >> n;
		for(int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			vec.push_back(a);
		}
		sort(vec.begin(), vec.end());
		
		cin >> heap;
		
		for(int i = 0; i < n; i++)
		{
			curAns.clear();
			if(vec[i] <= heap && vis[vec[i]] == false)
			{
				vis[vec[i]] = true;
				bt(i, vec[i]);
			}
		}
		
		if(cntAns == 0)
		{
			cout << "Empty" << endl;
			continue;
		}
		
		mp.clear();
				
		for(int i = 0; i < cntAns; i++)
		{
			string tmp;
			tmp.clear();
			for(int j = 0; j < ans[i].size(); j++)
				tmp += char(ans[i][j]);
			
			mp[tmp] = false;
		}
		
		for(int i = 0; i < cntAns; i++)
		{
			string tmp;
			tmp.clear();
			for(int j = 0; j < ans[i].size(); j++)
				tmp += char(ans[i][j]);
			
			if(mp[tmp] == false)	
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
			
			mp[tmp] = true;
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
	
	for(int newInd = ind+1; newInd < n; newInd++)
	{
		if(sum+vec[newInd] <= heap)
			bt(newInd, sum+vec[newInd]);
	}
	
	curAns.pop_back();
	
}


