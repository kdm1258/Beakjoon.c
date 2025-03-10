#include <bits/stdc++.h>
using namespace std;
int n, cnt;
int Map[20][20];
void DFS(pair<int,int> c1, pair<int, int> c2){
    if(c2.first<=n && c2.second <= n){
        if(c2.first==n && c2.second==n){
            cnt++;
            return;
        }
        //파이프가 가로로 배치
        if(c1.first==c2.first && c1.second+1 == c2.second){
            if(!Map[c2.first][c2.second+1]){
                DFS(c2,{c2.first, c2.second+1});
                if(!Map[c2.first+1][c2.second+1]&&!Map[c2.first+1][c2.second]){
                    DFS(c2, {c2.first+1, c2.second+1});
                }
            }
        }
        //파이프가 대각으로 배치
        else if(c1.first+1 == c2.first && c1.second+1 == c2.second){
            //다음 파이프가 가로
            if(!Map[c2.first][c2.second+1]){
                DFS(c2,{c2.first, c2.second+1});
            }
            //대각
            if(!Map[c2.first][c2.second+1] && !Map[c2.first+1][c2.second] && !Map[c2.first+1][c2.second+1]){
                DFS(c2,{c2.first+1, c2.second+1});
            }
            //세로
            if(!Map[c2.first+1][c2.second]){
                DFS(c2, {c2.first+1, c2.second});
            }
        }
        //파이프가 세로로 배치
        else if(c1.second == c2.second && c1.first+1 == c2.first){
            //세로
            if(!Map[c2.first+1][c2.second]){
                DFS(c2,{c2.first+1, c2.second});
                if(!Map[c2.first+1][c2.second+1] && !Map[c2.first][c2.second+1]){
                    DFS(c2, {c2.first+1, c2.second+1});
                }
            }
        }

    }       
}
int main(void){
    cin>>n;
    for(int i = 1 ; i <= n ; i++){
        for (int j = 1 ; j <=n ; j++){
            cin>>Map[i][j];
        }
    }
    DFS({1,1},{1,2});
    cout<<cnt;
}