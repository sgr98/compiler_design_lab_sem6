#include <stdio.h>
#include <inttypes.h>

int64_t three_max(int64_t, int64_t, int64_t);

int main(){
	printf("%ld\n",three_max(4,3,12));
	printf("%ld\n",three_max(4,3,0));
	printf("%ld\n",three_max(-4,-3,-12));
	printf("%ld\n",three_max(0,0,0));
}