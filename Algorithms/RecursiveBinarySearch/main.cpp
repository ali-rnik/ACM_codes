#include <iostream>
#include "binarySearch.cpp"

using namespace std;

/**
    Print out an array to command line.

    @param *arr the array to print
    @param size the array size
    @return void
*/
void printArray(int *arr, int size){
  cout << "[";
  for(int i = 0; i < size; i++){
    cout << arr[i];
    
    if (i != size - 1)
      cout << ",";
  }
  cout << "]";
}


/**
    This is a sample cli app which reads a sorted array from STDIN
    and finds an element within in it. 
*/
int main() {
  int size = 0;
  int searchInput = 0;
  
  cout << "Hello world!\n";
  cout << "This is a small app which finds an element in an array of "\
           "integers.\n\n";
  cout << "Let's begin!\n";
  cout << "What is your array size? ";
  cin >> size;
  
  int arr [size];
  
  for(int i = 0; i < size; i++){
    int element = 0;
    cout << "Enter the array element with index of " << i << ": ";
    cin >> element;
    arr[i] = element;
  }
  
  cout << "\n" << "This is your input array: ";
  printArray(arr, size);
  cout << "\n";
  
  char next = 'y';
  while(true) {
    cout << "\n" << "Enter a number: ";
    cin >> searchInput;
    int result = binarySearch(searchInput, arr, 0, size - 1);
    
    if (result == - 1)
      cout << "Snapp! I didn't find your number." << "\n\n";
    else
      cout << "Yess! I found it at index " << result << ".\n\n";
      
    cout << "Would you like to continue? (y/n) ";
    cin >> next;
    if (next == 'n')
      break;
  }
  
  return 0;
}
