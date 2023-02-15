#include <iostream>
using namespace std;
/*
// A의 부모는 B다 
18 15
3 0 
6 3 
9 6
10 6
11 6
4 1
7 4
12 7
13 7
14 7
5 2
8 5
15 8
16 8
17 8
*/
// Find : 소속을 찾아가는 알고리즘 
// #1. 정보 (부모 정보)를 저장할 parent가 필요
int parent[101]; 
int N, M;
// Find의 시간복잡도 : O(N)
// 경로 압축 후의 Find의 시간복잡도 : O(A(N))
// 장점 : 시간의 효율성의 대폭 상승한다
// 단점 : 돌이킬수가 없음
int Find(int now) {
    // 종료 조건 
    // now의 부모가 나랑 같다면 -> 소속을 찾았다!
    if (now == parent[now])
        return now;
    cout << now << "의 부모 : " << parent[now] << "\n";
    
    // 재귀 구성
    // 내가 대장이 아니면 -> 나의 부모를 찾아가라!
    // path compresssion 
    // 돌아왔을떄-> 소속을 "아는 상태"로 가지고 돌아오니까
    // 나의 부모(소속)은 = 돌아올때 가지고 있던 값이다 
    return parent[now] = Find(parent[now]); 
}
int main() {
    // cin >> N >> M;
    // parent는 항상 자기 자신이 대장이다! 
    // 즉, 본인은, 개별적인 노드이다! 라는 상태에서 시작
    for (int i = 0; i < N; i++)
        parent[i] = i; // 나의 부모는 나다! 
    //for (int i = 0; i < M; i++) {
    //    int A, B;
    //    cin >> A >> B;
    //    // A의 부모는 B다 
    //    parent[A] = B; 
    //}
    for (int i = 0; i < 100; i++)
        parent[i + 1] = i; 
    int num;
    cin >> num;
    cout << num << " 의 소속은 : " << Find(num) << '\n'; 
    cout << "=======\n";
    cout << num << " 의 소속은 : " << Find(num);
    cout << '\n';
    for (int i = 0; i < 100; i++)
        cout << parent[i] << " ";
}



