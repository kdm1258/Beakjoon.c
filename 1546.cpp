#include <bits/stdc++.h>
using namespace std;
int n;
double tot, Max, new_tot;
double score[1010];
int main(void){
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cin>>score[i];
		tot+=score[i];
		if(Max<score[i]) Max = score[i];
	}
	for(int i = 0 ; i < n ; i++){
		new_tot += score[i]/Max*100;
	}
	cout<<fixed<<setprecision(10)<<new_tot / n;
}
