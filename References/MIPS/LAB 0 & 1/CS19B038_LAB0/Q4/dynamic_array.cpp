/**
 * CS2292 Lab 0
 *
 */
#include <iostream>
#include <chrono> 
#include <cstdlib>
#include <ctime>

using namespace std::chrono;
using namespace std;

int main() {
  srand((unsigned) time(0));
  int N = 10000;

  int* a = new int[N];
  for(int i = 0; i < N; i++)
    a[i] = rand();

  int temp = -1;
  while (temp <= 1 || temp >= 15000)
      temp = rand();
  int M = temp;
  cout << "New Size = " << M << endl;

  auto start = high_resolution_clock::now();
  
  if(M == N)
    cout << "Its the same size";
  else if(M < N) {
    //shrinking
    int* b = new int[M];
    for(int i = 0; i < M; i++)
        b[i] = a[i];
    delete[] a;
  }
  else {
    //expanding
    int* b = new int[M];
    for(int i = 0; i < M; i++) {
      if(i >= N) {
        b[i] = rand();
      }
      else {
        b[i] = a[i];
      }
    }
    delete[] a;
  }

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << duration.count() << endl;
  return 0;
}