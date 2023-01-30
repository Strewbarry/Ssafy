#include <iostream>

using namespace std;

// 주사위 게임
// 나올 수 있는 모든 경우

// 입력 : 정수 1개 
// 출력 : 해당 주사위들로 나올 수 있는 주사위 눈의 모든 경우

char path[10] = { 0 };
int visitied[10] = { 0 };		// 주사위 눈을 뽑았는지 확인하기 위한 dat (0:뽑은적없음 , 1:뽑은적있음)

void bbq(int lev,int N) {
	if (lev == N )						// << 같은눈 체크시 여기(끝)에서 해도 되지만 
										        //    중간에서 같은값이 있을때 컷하는게 더 효율적이다
	{
		cout << path << '\n';
		return;
	}

	for (int i = 1; i <= 6; i++)
	{
		if (visitied[i] == 1)				//i가 뽑힌적이 있으면
			continue;						//i는 스킵하고 다음으로 넘어가자. for의 다음시작점(i+1)으로 이동
		path[lev] = '0' + i;			// << path 뽑자 마자 확인하여 진행을 멈추는 것이 
                              //	  데이터를 많이 아낄 수 있다	
		visitied[i] = 1;					//i가 뽑힌적이 있다는 마스킹
		bbq(lev + 1, N);
		path[lev] = 0;
	}
}

int main()
{
	int N;
	cin >> N;
	bbq(0,N);
}








