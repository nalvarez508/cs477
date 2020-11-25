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

void deleteValue(int heap[], int &x, int val)
{
  int index = -1;
  try
  {
    for (int i=0; i<x; i++)
      if (heap[i] == val)
        index = i; //Take note of where the value was found
    if (index < 0) //Value not found (index not changed)
      throw;
    cout << "Selected element is " << val << " found at index " << index << " of " << x << " total elements" << endl;

    int temp; //Swapping smallest element with last element
    temp = heap[index];
    //cout << temp << ", ";
    heap[index] = heap[x-1];
    heap[x-1] = temp;
    x--; //Removing the last node
    //printHeap(heap, x);
    for (int i=(x/2)-1; i>=0; i--) //Rebuilding the heap
      heapify(heap, x, i);
    printHeap(heap, x);
  }
  catch(...)
  {
    cout << "Value not found." << endl;
  }
}

int main()
{
  int nodes = 6;
  int A[nodes] = {9,6,8,2,5,7}; //Creates heap
  int valToDelete = 6;
  printHeap(A, nodes);
  deleteValue(A, nodes, valToDelete);
  return 0;
}