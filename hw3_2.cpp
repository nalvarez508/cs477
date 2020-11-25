//Compiled using https://www.onlinegdb.com/online_c++_compiler
//Nick Alvarez, CS477, F2020

#include <iostream>
using namespace std;

void find_min_max(int array[], int a, int b, int &min, int &max)
{
  if (a == b) //We are at a single element in the array
    min = max = array[a]; //Set our min/maxes to that element, later compared as left/right Min/Max variables
  else
  {
    int mid = (a+b)/2; //Finds midpoint of current subsection
    int leftMin, rightMin, leftMax, rightMax;

    find_min_max(array, a, mid, leftMin, leftMax); //Finds Min/Max of left side
    find_min_max(array, mid+1, b, rightMin, rightMax); //Finds Min/Max of right side

    min = (leftMin < rightMin) ? leftMin : rightMin; //Sets Min for current subsection, which is then compared to following subsections (pass-by-reference)
    max = (leftMax > rightMax) ? leftMax : rightMax; //Sets Max for current subsection, which is then compared to following subsections (pass-by-reference)
  }
}
int main()
{
  int A[11] = {1,4,9,3,4,9,5,6,9,3,7};
  int arrMin, arrMax;
  int sizeOfArray = sizeof(A)/sizeof(A[0]);
  find_min_max(A, 0, sizeOfArray-1, arrMin, arrMax);
  cout << "Size: " << sizeOfArray << ", Min: " << arrMin << ", Max: " << arrMax << endl;
  return 0;
}