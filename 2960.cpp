#include <iostream>
#include <math.h>
using namespace std;
int n, k, cnt;
char seive[128];
void setComposite(int k){
	if((seive[k>>3] &(1<<(k&7)))>0){
	seive[k>>3] &= ~(1<<(k&7));
	cnt++;}
}
bool isPrime(int k){
	return seive[k>>3] & (1<<(k & 7));
}
void era(){
	setComposite(0); setComposite(1);
	cnt = 0;
	int sqrtn = int(sqrt(n));
	for(int i = 2 ; i <= n ; i++){
		if(isPrime(i)){
			cnt++;
			if(cnt == k){
				cout<<i; return;
			}
			for(int j = i*i ; j <= n ; j += i){
				setComposite(j);
				if(cnt == k){
					cout<<j; return;
				}
			}
		}
	}
}
int main(void){
	cin>>n;
	for(int i = 0 ; i <128 ; i++){
		seive[i] = 0b11111111;
	}
	cin>>k;
	era();
}
