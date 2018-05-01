#include <iostream>

using namespace std;

void merge(int *arr, int l, int m, int r);
void mergeSort(int *arr, int l, int r);

int main()
{
	int n;
	cin >> n;
	
	int arr[2000] = {};
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	mergeSort(arr, 0, n-1);
	
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
		
}

void mergeSort(int *arr, int l, int r)
{
	if(l < r)
	{
		int m = (l+r)/2;
		
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);
		merge(arr, l, m, r);
	}
}

void merge(int *arr, int l, int m, int r)
{
	int tmp_l[1000] = {}, tmp_r[1000] = {};
	int sz_r = 0, sz_l = 0;
	
	for(int i = l; i <= m; i++) tmp_l[sz_l++] = arr[i];
	for(int i = m+1; i <= r; i++) tmp_r[sz_r++] = arr[i]; 
	
	int ind_r = 0, ind_l = 0;
	int k = l;
	
	while(ind_r < sz_r && ind_l < sz_l)
	{
		if(tmp_l[ind_l] < tmp_r[ind_r])
		{
			arr[k++] = tmp_l[ind_l++];
			continue;
		}
		
		if(tmp_r[ind_r] <= tmp_l[ind_l])
		{
			arr[k++] = tmp_r[ind_r++];
			continue;
		}
	}
	
	while(ind_l < sz_l)
		arr[k++] = tmp_l[ind_l++];
	
	while(ind_r < sz_r)
		arr[k++] = tmp_r[ind_r++];
	
}

