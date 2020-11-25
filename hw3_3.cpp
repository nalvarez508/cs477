//Compiled using https://www.onlinegdb.com/online_c++_compiler
//Nick Alvarez, CS477, F2020

#include <iostream>
using namespace std;

/*void printArray(int array[], int x)
{
  cout << x << ": [ ";
  for (int i=0; i<11; i++)
  {
    cout << array[i] << ", ";
  }
  cout << "]" << endl;
}*/

void merge_noRecursion(int *array, int lo, int mid, int hi)
{
  int x, y, z;
  int left = mid-lo+1;
  int right = hi-mid;
  int L[left], R[right];

  for (x=0; x<left; x++)
  {
    L[x] = *(array+(lo+x));
  }
  for (y=0; y<right; y++)
  {
    R[y] = *(array+(mid+1+y));
  }
  
  x=0;
  y=0;
  z=lo;
  
  while (x<left && y<right)
  {
    if (L[x] <= R[y])
    {
      *(array+z) = L[x];
      x++;
    }
    else
    {
      *(array+z) = R[y];
      y++;
    }
    z++;
  }

  //printArray(array, 1);
  while (x<left)
  {
    *(array+z) = L[x];
    x++;
    z++;
  }

  //printArray(array, 2);
  while (y<right)
  {
    *(array+z) = R[y];
    y++;
    z++;
  }
  //printArray(array, 3);
}

void mergeSort_noRecursion(int *array, int n)
{
  //cout << "Wow, we're inside a function!" << endl;
  //Merging adjacent pairs, then pairs of adjacent pairs
  for (int x = 1; x<=n; x*=2) //Size of array subsection, increasing by 2*(prev_size) each time
  {
    for (int lo = 0; lo<n; lo+=(x*2)) //Determine where to start searching in A[]
    {
      int mid = ((lo+(x-1) < n) ? (lo+(x-1)) : n); //Finds midpoint of left subsection
      int hi = ((lo + (2*x-1) < n) ? (lo + (2*x-1)) : n);
      merge_noRecursion(array, lo, mid, hi);
    }
  } // A[] = {1,2,3,3,4,4,5,6,7,9,9,9}
}

int main()
{
  int A[12] = {1,4,9,3,4,9,5,6,9,3,7,2};
  int sizeOfArray = sizeof(A)/sizeof(A[0]);
  mergeSort_noRecursion(A, sizeOfArray-1);
  cout << "Size: " << sizeOfArray << ", Array: [ ";
  for (int i=0; i<sizeOfArray; i++)
    cout << A[i] << " ";
  cout << "]" << endl;
  return 0;
}