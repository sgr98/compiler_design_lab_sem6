/**
 * CS2292 Lab 0
 *
 */
#include <iostream>
#include <chrono> 

using namespace std::chrono;
using namespace std;
typedef unsigned long long ull;

const ull N = 10000;
ull a[N][N];

int main() {
  ull sum = 0;
  auto start = high_resolution_clock::now();

  for (ull i = 0; i < N; i++) {
    for (ull j = 0; j < N; j++) {
      sum += a[i][j];
    }
  }
  
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << duration.count() << endl;
  return 0;
}

