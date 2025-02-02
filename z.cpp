#include <bits/stdc++.h>
using namespace std;
int seq = 0;
int r = 0;
int c = 0;
void z(int n, int x, int y){
	if (x==c && y == r){
		cout<<seq;
		return;
	}
	else if(c < x + n && c >= x && r < y + n && r >= y){
		z(n/2, x, y);
		z(n/2, x+n/2, y);
		z(n/2, x, y + n/2);
		z(n/2, x+n/2, y+n/2);
	}
	else seq += n*n;

}
int main(void){
	int n = 0;
	int x = 0;
	int y = 0;
	cin>>n>>r>>c;
	z((1<<n),0,0);
}
