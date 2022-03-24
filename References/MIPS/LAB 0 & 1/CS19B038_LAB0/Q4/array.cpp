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

  const int N = 10000;
  
  auto start = high_resolution_clock::now();

  int a[N];
  for(int i = 0; i < N; i++)
    a[i] = rand();
  
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << duration.count() << endl;
  return 0;
}

