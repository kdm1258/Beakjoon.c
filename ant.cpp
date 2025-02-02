#include <iostream>
using namespace std;
int main(void){
	int n = 0;
	cin>>n;
	for (int i = 0 ; i<n ; i++){
		int l = 0 ;
		int num = 0;
		cin >>l>>num;
		int minTime = 0;
		int maxTime = 0;
		for (int j = 0 ; j < num ; j++){
			int tmp;
			cin>>tmp;

			int sht = min(tmp, l-tmp);
			int lng = max(tmp, l-tmp);
			minTime = max(minTime, sht);
			maxTime = max(maxTime, lng);
		}
		cout<<minTime<<' '<<maxTime<<'\n';
	}
}
