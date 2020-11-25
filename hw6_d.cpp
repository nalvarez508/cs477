//Compiled using https://www.onlinegdb.com/online_c++_compiler
//Nick Alvarez, CS477, F2020

#include <iostream>
#include <algorithm>
using namespace std;
#define N 4 //Number of days
int P[N] = {0}; //Optimal data processing array
int Reboot[N] = {0}; //Reboot days

void jobMaximize(int x[], int s[], int P[], int &r, int i){
  switch (i)
  {
    case 0: //First day
    {
      P[i] = min(x[0], s[0]);
      r++;
      jobMaximize(x, s, P, r, ++i);
      break;
    }
    case 1: //Second day
    {
      
      if (min(x[1], s[1]) <= min(x[2], s[0])) //Reboot
      {
        r = 0;
        Reboot[i] = 1;
        P[i] = P[i-1];
        jobMaximize(x, s, P, r, ++i);
      }
      else //No reboot
      {
        r++;
        P[i] = max(P[i-1] + min(x[1], s[1]), P[i-1] + min(x[2], s[0]));
        jobMaximize(x, s, P, r, ++i);
      }
      break;
    }
    case N: //No more days
      break;

    default:
    {
      if (P[i-2] + min(x[i+1], s[0]) >= P[i-1] + min(x[i], s[r])) //Reboot
      {
        r = 0;
      }
      else //No reboot
        r++;
      P[i] = max(P[i-1] + min(x[i], s[r]), P[i-2] + min(x[i], s[0]));
      jobMaximize(x, s, P, r, ++i);
      break;
    }
  }
}

int main(){
  int s[4] = {8, 4, 2, 1}, r = 1, x[4] = {10, 1, 7, 7}; //Data processing capacity, days since reboot, data to be processed
  int P_optimal = 0;
  jobMaximize(x, s, P, r, 0);
  cout << "Max data processed is " << P[N-1] << " megabytes" << endl;
  cout << "Day | total processed" << endl;
  for (int z=0; z<N; z++)
    cout << z+1 << "   | " << P[z] << endl;

  cout << endl << "The system should be rebooted on day (";
  for (int z=0; z<N; z++)
    if (Reboot[z]) {cout << z+1;}
  cout << ")" << endl;
  return 0;
}