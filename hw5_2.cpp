//Compiled using https://www.onlinegdb.com/online_c++_compiler
//Nick Alvarez, CS477, F2020

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void printHeap(int heap[], int x)
{
  for (int i=0; i<x; i++)
    cout << heap[i] << " ";
  cout << endl;
}

void heapify(int heap[], int x, int i)
{
  int max = i;
  int left = 2*i+1;
  int right = 2*i+2;

  if (left < x && heap[left] > heap[max])
    max = left;
  if (right < x && heap[right] > heap[max])
    max = right;
  if (max != i)
  {
    int temp;
    temp = heap[i];
    heap[i] = heap[max];
    heap[max] = temp;
    heapify(heap, x, max);
  }
}

void deleteMin(int heap[], int &x)
{
  int index = x/2;
  int minVal = heap[x/2];
  for (int i=1+(x/2); i<x; i++)
    if (minVal > heap[i])
    {
      minVal = heap[i];
      index = i;
    }
    //minVal = ((minVal < heap[i]) ? minVal : heap[i]);
  cout << "Minimum element is " << minVal << " at index " << index << " of " << x << " total elements" << endl;

  int temp; //Swapping smallest element with last element
  temp = heap[index];
  //cout << temp << ", ";
  heap[index] = heap[x-1];
  heap[x-1] = temp;
  x--; //Removing the last node
  //printHeap(heap, x);
  for (int i=(x/2)-1; i>=0; i--) //Rebuilding heap
    heapify(heap, x, i);
  printHeap(heap, x);
}

int main()
{
  int nodes = 6;
  int A[nodes] = {9,6,8,2,5,7}; //Creates heap
  printHeap(A, nodes);
  deleteMin(A, nodes);
  return 0;
}