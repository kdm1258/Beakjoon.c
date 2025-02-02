#include <iostream>
#include <vector>
using namespace std;
int n = 0;
int m = 0;
vector<int> use(9);
vector<int> arr(8);
void f (int choose){
	if (m==choose) {
		for (int i = 0 ; i < m  ; i++) cout<<arr[i]<<" ";
		cout<<"\n";
		return;
	}
	for (int i = 1 ; i<= n ; i++){
		if (choose == 0 || i > arr[choose-1]){
			arr[choose] = i;
			f(choose +1);
		}
	}
}
int main(void){
	cin>>n>>m;
	f(0);
}
