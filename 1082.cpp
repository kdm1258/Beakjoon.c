#include<bits/stdc++.h>
using namespace std;
int n,m;
vector <pair<int, int>> P;
vector <int> copy_P;
bool compare(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second){
        return a.first > b.first;
    }
    return a.second < b.second;
}
bool compare2(int a, int b){
    return a>b;
}
void sol(int m){
    vector <int> v;
    if(P[0].first==0){
        if(P.size()>1 && P[1].second <= m){
            v.push_back(P[1].first);
            m-=P[1].second;
        }
        else{
            cout<<0;
            return;
        }
    }
    for(int i = 0 ; i < n ; i++){
        if(m>= P[i].second){ 
            int q = m/P[i].second;
            m %= P[i].second;
            for(int j = 0 ; j < q ; j++) v.push_back(P[i].first);
        }
    }
    sort(v.begin(), v.end(), compare2);

    for(int i = 0 ; i < v.size() ; i++){
        for(int j = n-1 ; j>0 ; j--){
            if(v[i]<j && m+copy_P[v[i]]-copy_P[j]>=0){
                m = m + copy_P[v[i]]-copy_P[j];
                v[i] = j;
                break;
            }
        }
    } 
    for(int i = 0 ; i <v.size() ; i++){
        cout<<v[i];
    }
} 
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;

    //숫자 : 가격순으로 저장
    for(int i = 0 ; i < n ; i++){
        int p; cin>>p;
        P.push_back({i, p});
        copy_P.push_back(p);
    }
    sort(P.begin(), P.end(), compare);
    cin>>m;
    sol(m);
}
