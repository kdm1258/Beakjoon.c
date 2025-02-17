#include <stdio.h>
int main(void){
    int n = 0;
    int arr[500001] = {0};
    int point[500001] = {-1};
    scanf("%d", &n);
    for (int i = 1 ;i <= n ; i++){   //주어진 정수 배열 만들
        scanf("%d", &arr[i]);
    }
    for (int i = 1 ; i <= n ; i++){  //포인터 배열 채우기
        point[arr[i]] = i ;
    }

    int Dist[500001] = {0}; //거리를 나타내는 배열 생성
    for (int j = 1 ; j <= n ; j++){
        if (arr[j] == j) continue;  //올바른 위치

        Dist[arr[j]] += point[j]-j;
        Dist[j] += point[j]-j;

        arr[point[j]] = arr[j];  //위치 바꾸기
        arr[j] = j;

        point[arr[point[j]]] = point[j]; //pointer 배열 위치 바꾸기
        point[j]=j;

    }
    for (int i = 1 ; i <=n ; i++){
        printf("%d ", Dist[i]);
    }
    return 0;

}

//일반적인 삽입 정렬 알고리즘대로 코딩을하면 시간복잡도가 O(n^2)가 되므로 시간초과 에러가 뜬다. 이 문제에서는 주어지는 배열의 인자는 1~n까지임을 알고 있으므로 우리는 정렬된 배열의 결과를 알고 있다. 
//따라서 포인터를 나타내주는 배열을 새로 만들면 시간복잡도를 O(n)까지 낮출 수 있다
