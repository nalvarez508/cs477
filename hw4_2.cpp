//Compiled using https://www.onlinegdb.com/online_c++_compiler
//Nick Alvarez, CS477, F2020

#include <iostream>
using namespace std;

void flip(int array[], int lo, int hi) //Flips entire array
{
  //cout << "Entered flip(), " << lo << " " << hi << endl;
  int temp;
  if (lo < hi)
  {
    //cout << "Comparison" << endl;
    temp = array[lo];
    array[lo] = array[hi];
    array[hi] = temp;
    //cout << "Comparison complete." << endl;
    flip(array, ++lo, --hi);
  }
}

void mergeAndFlip(int array[], int lo, int mid, int hi) //"Creates" two subarrays, finds a negative, flips that subarray
{
  //cout << "Entered mergeAndFlip()" << endl;
  int x, y;
  x = lo;
  y = mid+1;

  while (x <= mid && array[x] < 0) //x stops at negative element or midpoint
    x++;
  while (y <= hi && array[y] < 0) //y stops at negative element or end
    y++;
  
  flip(array, x, mid); //Flips first subarray
  flip(array, mid+1, y-1); //Flips second subarray
  flip(array, x, y-1);
}


void negativeArrange(int array[], int lo, int hi)
{
  //cout << "Entered negativeArrange()" << endl;
  if (lo < hi)
  {
    int mid = lo+(hi-lo)/2;
    negativeArrange(array, lo, mid); //Creating smaller and smaller subarrays until we are at a pair
    negativeArrange(array, mid+1, hi);
    mergeAndFlip(array, lo, mid, hi);
  }
}

int main()
{
  int A[12] = {4,3,-2,0,2,9,-1,10,0,5,23,-4};
  int sizeOfArray = sizeof(A)/sizeof(A[0]);
  negativeArrange(A, 0, sizeOfArray-1);
  cout << "[ ";
  for (int i=0; i<n; i++)
  {
    cout << A[i] << " ";
  }
  cout << "]" << endl;
}