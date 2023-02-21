#include<iostream>
using namespace std;

// 다이나믹 프로그래밍 = 기억하기 프로그래밍 (기록) 
int dp[101]; 

// N번째 피보나치를 구하는 프로그램 
// Top-Down (memoization)
// 큰 문제 -> 작은 문제로 분할하여 해결하는 기법
int fibo(int now) {
    // 기저조건
    if (now <= 2)
        return 1; 

    // 내 기억속에서 now에 대한 문제를 기억하고 있다면
    if (dp[now] != 0)
        return dp[now]; 

    // 재귀 구성
    // now = now - 1 + now - 2 
    // 다시 여기까지 돌아오는 순간
    // = now까지의 정답을 찾았다! 
    // now번째의 정답을 아니까 -> 잊지 안도록 기억(기록)
    return dp[now] = fibo(now - 1) + fibo(now - 2);
}

int main() {
    int N;
    cin >> N;
    // cout << fibo(N); 

    // Bottom-Up (Tabulation) 
    // 아래의(가장 하위의 문제)부터 순차적으로 더 상위 문제를 해결하는 기법
    // * 점화식을 생성할 수 있어야 한다 
    // 가장 작은 문제에 대한 해답을 구해야 한다

    if (dp[N] != 0)
        cout << dp[N]; 

    dp[1] = 1;
    dp[2] = 1; // 알고 있는 가장 작은 문제에 대한 답
    for (int i = 3; i <= N; i++) 
        dp[i] = dp[i - 2] + dp[i - 1]; 
    
    cout << dp[N]; 
}