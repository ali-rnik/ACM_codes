// binary serach on intervals

int binarySearch(int goal, long long *arr, int s, int e)
{
	int mid = (e-s)/2+s;
	if(mid > e)
		return 0;
	if(goal >= arr[mid] && goal < arr[mid+1])
		return  mid+1;
	if(arr[mid] <= goal)
		return binarySearch(goal, arr, mid+1, e);
	else
		return binarySearch(goal, arr, s, mid-1);
}
