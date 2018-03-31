// recursive binarySearch
int binarySearch(int goal, int *arr, int start, int end)
{
  int mid = (end-start)/2+start;
  if(mid > end)
    return -1;
  if(arr[mid] == goal)
    return  mid;
  if(arr[mid] < goal)
    return binarySearch(goal, arr, mid+1, end);
  else
    return binarySearch(goal, arr, start, mid-1);
}
