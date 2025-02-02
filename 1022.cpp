#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_R = 55, MAX_C = 10;  // 여유있게 크기 설정
ll Map[MAX_R][MAX_C];
ll maxi;

int next_r[4] = {0, -1, 0, 1};
int next_c[4] = {1, 0, -1, 0};

void my_print(int r1, int c1, int r2, int c2) {
    ll cnt = 1;
    int gap = 1;
    int r = 0, c = 0;
    int dir = 0;
    ll max_cnt = (ll)(r2-r1+1) * (c2-c1+1);  // 최대 반복 횟수 설정

    while (cnt <= max_cnt) {
        for (int i = 0; i < gap; i++) {
            if (r1 <= r && r <= r2 && c1 <= c && c <= c2) {
                int local_r = r - r1;
                int local_c = c - c1;
                if (local_r >= 0 && local_r < MAX_R && local_c >= 0 && local_c < MAX_C) {
                    Map[local_r][local_c] = cnt;
                    maxi = max(maxi, cnt);
                }
            }
            r += next_r[dir];
            c += next_c[dir];
            cnt++;
            if (cnt > max_cnt) return;  // 모든 필요한 위치를 채웠으면 종료
        }
        dir = (dir + 1) % 4;
        if (dir == 0 || dir == 2) gap++;
    }
}

void pretty(int r1, int c1, int r2, int c2) {
    int width = to_string(maxi).length();
    for (int i = 0; i <= r2-r1; i++) {
        for (int j = 0; j <= c2-c1; j++) {
            cout << setw(width) << Map[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    my_print(r1, c1, r2, c2);
    pretty(r1, c1, r2, c2);

    return 0;
}
