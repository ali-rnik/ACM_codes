// link to this problem : https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0

include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <limits.h>

using namespace std;

int main()
{
	//freopen("a.in", "r", stdin);
	int T;
	cin >> T;
	for(int t = 0; t < T; t++)
	{
		int n;
		cin >> n;
		
		long long maxx = 0, tmp_maxx = 0, maxx_neg = LLONG_MIN;
		for(int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			
			tmp_maxx += a;
			
			if(a <= 0 && a > maxx_neg)
				maxx_neg = a;
				
			if(tmp_maxx < 0)
				tmp_maxx = 0;
				
			if(tmp_maxx > maxx)
				maxx = tmp_maxx;
		}
		
		if(maxx == 0)
			cout << maxx_neg;
		if(maxx != 0)
			cout << maxx;
		cout << endl;
		
	}
	
}

