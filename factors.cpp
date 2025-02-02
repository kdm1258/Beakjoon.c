#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int INF = 1000000;
vector<ll> fact(1010101);
using namespace std;
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n = 0;
	int m = 0;
	int t = 0;
	for (int i = 1; i<=INF ; i++){
		for (int j = 1 ; i*j <= INF ; j++){
			fact[i*j] += i;
		}
	}
	for (int i = 1 ; i <=INF ; i++){
		fact[i] += fact[i-1];
	}	
	cin>>n;
	for (int i = 0 ; i<n ; i++){
		cin>>m;
		cout<<fact[m]<<'\n';
	}
}
