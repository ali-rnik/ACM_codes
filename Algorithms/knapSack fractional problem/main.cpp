//link to this problem : https://practice.geeksforgeeks.org/problems/fractional-knapsack/0

#include <iostream>
#include <limits.h>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	//freopen("a.in", "r", stdin);
	int T;
	cin >> T;
	
	for(int t = 0; t < T; t++)
	{
	  int n, c;
		cin >> n >> c;
		vector<pair<double, int> > vec;
		vec.clear();
		
		for(int i = 0; i < n; i++)
		{
			double val, w;
			cin >> val >> w;
			vec.push_back(make_pair(val/w, w));
		}
			
		sort(vec.begin(), vec.end());
		reverse(vec.begin(), vec.end());
		
		double ans = 0;
		
		for(int i = 0; i < n; i++)
		{
			if(vec[i].second <= c)
			{
				c -= vec[i].second;
				ans += (vec[i].second*vec[i].first);
				if(c == 0)
					break;
				continue;
			}
			
			if(vec[i].second > c)
			{
				ans += (double(c)*vec[i].first);
				break;
			}
		}
		
		printf("%0.2f\n", ans);
	}
}
