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

const int max_t = 50;

string dic[max_t];
string bog[max_t];
bool success;
int xmv[] = {0,  0, 1, -1, -1, -1, 1,  1};
int ymv[] = {1, -1, 0,  0, -1,  1, 1, -1};
int n, m;
int vis[max_t][max_t];

void bt(int x, int y, int ind, string word);

int main()
{
	//freopen("a.in", "r", stdin);
	
	int T;
	cin >> T;
	
	for(int t = 0; t < T; t++)
	{
		int x;
		cin >> x;
		for(int i = 0; i < x; i++) cin >> dic[i];
		
		map<char, vector<pair<int, int> >  > mp;
		mp.clear();
		
		cin >> n >> m;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
			{
				char s;
				cin >> s;
				bog[i][j] = s;
				vis[i][j] = false;
				mp[s].push_back(make_pair(i, j));
			}
		
		set<string> st;
		st.clear();
		for(int i = 0; i < x; i++)
		{	
			char firstChar = dic[i][0];
			for(int j = 0; j < mp[firstChar].size(); j++)
			{
				for(int p = 0; p < n; p++)
					for(int q = 0; q < m; q++)
						vis[p][q] = false;
				int x = mp[firstChar][j].first;
				int y = mp[firstChar][j].second;
				success = false;
				bt(x, y, 0, dic[i]);
				
				if(success == true || dic[i].size() == 1)
				{
					st.insert(dic[i]);
					break;
				}				
			}
		}
		
		if(st.size() == 0)
			cout << -1 << endl;
			
		if(st.size() != 0)
		{
			set<string>::iterator it;
			for(it = st.begin(); it != st.end(); it++)
				cout << *it << " ";
			cout << endl;
		}
		
	}
}


void bt(int x, int y, int ind, string word)
{
	vis[x][y] = true;
	
	for(int i = 0; i < 8; i++)
	{
		int r = x + xmv[i];
		int c = y + ymv[i];
		
		if(ind+2 == word.size() && bog[r][c] == word[word.size()-1] && vis[r][c] == false && r >= 0 && c >= 0 && r < n && c < m)
		{
			vis[r][c] = true;
			success = true;
			return;
		}
		
		if(bog[r][c] == word[ind+1] && vis[r][c] == false && r >= 0 && c >= 0 && r < n && c < m)
			bt(r, c , ind+1, word);
		
		if(success == true)
			return;		
	}
}


void gdb()
{
	cout << endl;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
			cout << vis[i][j] << " ";
		cout << endl;
	}
}



