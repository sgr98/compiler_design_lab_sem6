#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>
#include <cstdlib>

// #include <chrono>
// #include <thread>

using namespace std;

int main() {
    int **mat = new int *[5];
    for(int i = 0; i < 5; i++)
        mat[i] = new int [3];

    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 3; j++)
            mat[i][j] = 3 * i + j;

    cout.flush();
    Sleep(1000);

    // this_thread::sleep_for(chrono::milliseconds(2000));

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 3; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }            

    return 0;
}