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
  int N;
  cin >> N;
  srand((unsigned) time(0));

  // Making a random Matrix A
  int** a = new int*[N];
  for(int i = 0; i < N; ++i)
    a[i] = new int[N]; 
  for(int i = 0; i < N; ++i)
    for(int j = 0; j < N; ++j) 
      a[i][j] = (rand() % 50);
  cout << endl << "Matrix A:" << endl;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++)
      cout << a[i][j] << "\t";
    cout << endl;
  }

  // Making a random Matrix B
  int** b = new int*[N];
  for(int i = 0; i < N; ++i)
    b[i] = new int[N];
  for(int i = 0; i < N; ++i)
    for(int j = 0; j < N; ++j)
      b[i][j] = (rand() % 50);
  cout << endl << "Matrix B:" << endl;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++)
      cout << b[i][j] << "\t";
    cout << endl;
  }

  int** c = new int*[N];
  for(int i = 0; i < N; ++i)
    c[i] = new int[N];
  for(int i = 0; i < N; ++i)
    for(int j = 0; j < N; ++j)
      c[i][j] = 0;

  auto start = high_resolution_clock::now();

  for (int i = 0; i < N; i++) {
    for (int k = 0; k < N; k++) {
      for(int j = 0; j < N; j++) {
        c[i][k] += a[i][j] * b[j][k];
      }
    }
  }
  
  cout << endl << "Matrix C:" << endl;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++)
      cout << c[i][j] << "\t";
    cout << endl;
  }

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << duration.count() << endl;
  return 0;
}

