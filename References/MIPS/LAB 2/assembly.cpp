//g++ -g -O0 -Wa,-aslh assembly.cpp
#include <stdio.h>
int main()
{
  int x;
  int y;
  int z;
  x = 3;
  y = 5;
  z = x + y;
  printf(": %d\n", x);
  return 0;
}
