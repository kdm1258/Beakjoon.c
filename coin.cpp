#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
int main(void){
	int n = 0;	//동전 갯수
	int k = 0;	//몇배
	string str;	//동전배열 저장
	long long int maxlen = 0; //최대길이 반환
	vector<long long int> sn(1010101);	//누적합 배열

	cin>>n>>k>>str;
	for (int i = 0 ; i < n ; i++){
		if(str[i]=='R'){
			sn[i+1]=sn[i]+k;	//tail방향이면 k만큼 누적합 증가
		}
		else if (str[i] =='O'){
			sn[i+1]=sn[i]-1;	//head방향이면 1만큼 누적합 감소
		}
	}
	map<int,long long int> m;
	for (int i = 1 ; i <=n ; i++){
		if (m.find(sn[i]) == m.end()){
			m[sn[i]] = i;
		}	
		else if (m.find(sn[i]) != m.end()){
			maxlen = max(maxlen,i-m[sn[i]]);
		}
	}
	
	cout<<maxlen;
}
