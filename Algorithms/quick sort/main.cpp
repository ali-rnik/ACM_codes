#include <iostream>
#include <algorithm>

using namespace std;

int partition(int *arr, int l, int r);
void quickSort(int *arr, int l, int r);

int main()
{
	int arr[10000] = {};
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	
	quickSort(arr, 0, n-1);
	
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	
	return 0;	
}

void quickSort(int *arr, int l, int r)
{
	if(l < r)
	{
		int m = partition(arr, l, r);
		quickSort(arr, l, m-1);
		quickSort(arr, m+1, r);
	}
}

int partition(int *arr, int l, int r)
{
	int p = arr[r];
	int m = l;
	for(int i = l; i <= r; i++)
	{
		if(arr[i] < p)
		{
			swap(arr[i], arr[m]);
			m++;
		}
	}
	
	swap(arr[m], arr[r]);
	
	return m;
}
