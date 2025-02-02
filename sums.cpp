#include <iostream>
#include <vector>
using namespace std;
int main(void){
	vector<long int> s(101010);
	int cnt = 0;	//m인 개수
	int n = 0, m = 0; 
	cin>>n>>m;
	int tmp = 0;
	long int sum = 0;  //sum은 최대 300,000,000이므로 long int 사용
	for (int i = 1 ; i <= n ; i++){
		cin>>tmp;
		sum+=tmp;
		if (sum==m) cnt++; 	//sum과 m 이 같으면 숫자 1증가
		s[i] = sum;   //sn의 값 저장
	}
	for (int i = 2 ; i <= n ; i++){
		for (int j = 1 ; j < i ; j++){
			if ((s[i] - s[j])==m) cnt++;
		}
	}
	cout<<cnt;
}
