#include <iostream>
#include <math.h>
using namespace std;
bool isBitSet (unsigned long long a, int b){
	return(a&(1ull<<b))>0;
}
int main(void){
	int tmp = 0b101000;
	cout<<__builtin_ctz(tmp)<<"\n";
	cout<<(tmp & -tmp);
	
}

