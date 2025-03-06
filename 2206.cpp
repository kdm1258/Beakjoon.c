#include <bits/stdc++.h>
using namespace std;
int n, m;
int Map[1010][1010];
int visited[1010][1010][2];
int arrow[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int BFS(){
    queue<pair<pair<int, int>,int>> q;   //x,y,wall을 부순여부
    q.push({{1,1},0});
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int wall = q.front().second;
        if(x==n && y==m) return visited[n][m][wall];
        q.pop();
        visited[1][1][0] = 1;
        for (int i = 0 ; i <4 ; i++){
            int nx = x+arrow[i][0];
            int ny = y+arrow[i][1];
            if(nx<1 || nx>n || ny<1 || ny>m) continue;
            if(Map[nx][ny] == 0 && wall == 0 && visited[nx][ny][0] == 0){
                q.push({{nx, ny},0});
                visited[nx][ny][0] = visited[x][y][0]+1;
            }
            else if(Map[nx][ny] == 0 && wall == 1 && visited[nx][ny][1] == 0){
                q.push({{nx,ny},1});
                visited[nx][ny][1] = visited[x][y][1]+1;
            }
            else if(Map[nx][ny] == 1 && wall == 0 && visited[nx][ny][0] == 0){
                q.push({{nx,ny},1});
                visited[nx][ny][1] = visited[x][y][0]+1;
            }
        }
    }
    return -1;
}
int main(void){
    cin>>n>>m;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            scanf("%1d",&Map[i][j]);
        }
    }
    cout<<BFS();
}