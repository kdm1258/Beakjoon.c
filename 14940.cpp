#include <bits/stdc++.h>
using namespace std;
int n, m, G[1010][1010], D[1010][1010], C[1010][1010];
queue<pair<int,int>> Q;
void BFS(int x, int y){
	Q.push({x,y});
	C[x][y] = 1;

	while(!Q.empty()){
		auto [i,j] = Q.front(); Q.pop();
		if (G[i-1][j] == 1 && C[i-1][j] == 0){
			Q.push({i-1,j});
			D[i-1][j] = D[i][j]+1;
			C[i-1][j] = 1;
		}	
		if (G[i][j-1] == 1 && C[i][j-1] == 0){
			Q.push({i,j-1});
			D[i][j-1] = D[i][j]+1;
			C[i][j-1] = 1;
		}	
		if (G[i+1][j] == 1 && C[i+1][j] == 0){
			Q.push({i+1,j});
			D[i+1][j] = D[i][j]+1;
			C[i+1][j] = 1;
		}	
		if (G[i][j+1] == 1 && C[i][j+1] == 0){
			Q.push({i,j+1});
			D[i][j+1] = D[i][j]+1;
			C[i][j+1] = 1;
		}	
	}
}
int main(void){
	cin>>n>>m;
	int destx, desty;
	for (int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= m ; j++){
			int tmp;cin>>tmp;
			if(tmp == 2) destx = i, desty = j; 
			G[i][j] = tmp;
		}
	}
	BFS(destx, desty);
	for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (G[i][j] == 0) {
                cout << 0 << " ";
            } else if (C[i][j] == 0) {
                cout << -1 << " ";
            } else {
                cout << D[i][j] << " ";
            }
        }
        cout << "\n";
    }
}
