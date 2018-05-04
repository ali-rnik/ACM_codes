#include <iostream>
#include <limits.h>

using namespace std;

int maxMid(int *arr, int l, int m, int r);
int maxSub(int *arr, int l, int r);

int main()
{
	int n;
	cin >> n;
	int arr[10000] = {};
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	
	int ans = maxSub(arr, 0, n-1);
	
	cout << ans << endl;
	
}

int maxSub(int *arr, int l, int r)
{
	if(l == r)
		return arr[l];
	
	int m = (l+r)/2;
	
	return max(max(maxSub(arr, l, m), maxSub(arr, m+1, r)), maxMid(arr,l, m, r));
	
}

int maxMid(int *arr, int l, int m, int r)
{
	int sum = 0;
	int left_sum = INT_MIN;
	for(int i = m; i >= l; i--)
	{
		sum += arr[i];
		if(sum > left_sum)
			left_sum = sum; 
	}
	
	sum = 0;
	int right_sum = INT_MIN;
	for(int i = m+1; i <= r; i++)
	{
		sum += arr[i];
		if(sum > right_sum)
			right_sum = sum;
	}
	
	return left_sum + right_sum;
}
