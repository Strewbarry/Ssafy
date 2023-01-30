#include <iostream>

using namespace std;

// 주사위 게임
// 나올 수 있는 모든 경우

// 입력 : 정수 1개 
// 출력 : 해당 주사위들로 나올 수 있는 주사위 눈의 모든 경우

char path[10] = { 0 };
int visitied[10] = { 0 };			
int sum;    // 합 변수 선언

void bbq(int lev,int N) {
	// 지금 lev 번째 주사위 눈을 뽑을 차례
	//0~N-1 번 주사위 까진 정상
	//N 번 주사위부터는 존재 X
	if (lev == N )					
	{
		cout << path << " = " << sum << '\n';     //합 출력
		return;
	}

	for (int i = 1; i <= 6; i++) 
	{
		if (visitied[i] == 1)			
			continue;					

		path[lev] = '0' + i;		
		visitied[i] = 1;				
		sum += i;           // i만큼 sum에 더하기

		bbq(lev + 1, N);

		visitied[i] = 0;			
		path[lev] = 0;
		sum -= i;           // 눈이 바뀌기 전에 i를 지워서 다시 초기화
	}
}

int main()
{
	int N;
	cin >> N;
	bbq(0,N);
}








