#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>	 

using namespace std;

//6 8 3
//0 0 1 0 1 0 0 1
//0 1 0 0 0 1 1 1
//0 1 1 1 0 0 0 0
//1 1 1 1 0 0 0 1
//0 1 1 0 1 0 0 1
//1 0 1 0 1 1 0 1

int D; //두께
int W; // 가로크기
int K;	// 합격지준 (K개 만큼 연속으로 연결된 구간이 있어야 한다)
int film[20][20];
int Copy[20][20];
int injectioncnt=0; // 약품 주입횟수
int ans = 21e8; //최소 횟수


bool test() {
	// 세로 방향으로 K개 이상 연결된 A또는 B가 있는가?
	for (int i = 0; i < W; i++)
	{	// 지금 보는 열의 맨 위에 있는 값 >> 기준
		int base = Copy[0][i];
		int cnt = 0;
		// 현재 열의 유효성 검사
		int flag = 0; // 0>> 유효 X   1>> 유효 O
		for (int j = 0; j < D; j++)
		{
			// 지금 내가 보고 있는 칸 (i,j)의 값이 base와 동일하다면
			// 연속된 동일한 약품을 찾았으니 카운트++
			if (base == Copy[j][i]) {
				cnt++;
				// cnt를 늘리는 순간 >> K이상구간이 되었는지 검사
				if (cnt >= K) {
					flag = 1;
					break; // 현재 열은 유효하니, 다음 열로 넘어가세요
				}
			}
			else {
				// base를 교체 >> 
				base = Copy[j][i];
				// base가 바뀌었으니 카운트로 새로 시작해야함
				cnt = 1;
			}
		}
		// 현재 열의 모든 검사 종료
		// 그래도 유효하지 않다?(flag==0)
		if (flag == 0)
			return false;
	}
	// 모든 열과 모든 행의 검사 종료
	return true;
}


void func(int lev)
{
	// 기저 조건 -- > D번 행까지 도달하면
	if (lev == D) {
		//성능테스트
		if (test() == true) {
			if (injectioncnt < ans)
				ans = injectioncnt;
		}
		//최소 약품 주입횟수 
		return;
	}
	// backtracking >> 만약 지금 투입한 약품의 수가 ans보다 많다면
	// 현재 길은 이미 최소값 탈락이니 돌아가라
	if (injectioncnt > ans)
		return;

	// 재귀 구성 >> 3가지 갈래로 내려갈 수 있다.
	// #1. 아무것도 안한다
	//  >> 진입할때 동작하는 구간 (변화)
	func(lev + 1);


	// #2. A로 바꾼다 >> lev층 행의 값을 모두 0으로 바꾼다
	for (int i = 0; i < W; i++)
		Copy[lev][i] = 0;		// film 을 바로 바꾸면 복구가 불가능 하기때문에 복사해놓은 배열을 이용한다
	injectioncnt++;
	func(lev + 1);
	for (int i = 0; i < W; i++)
	{
		Copy[lev][i] = film[lev][i];	// 원본을 저장해둔 film을 이용해 copy 원상복구
	}
	injectioncnt--;


	// #3. B로 바꾼다 >>
	for (int i = 0; i < W; i++)
		Copy[lev][i] = 1;		
	injectioncnt++;
	func(lev + 1);
	for (int i = 0; i < W; i++)
	{
		Copy[lev][i] = film[lev][i];	
	}
	injectioncnt--;
	
}


int main()
{
	freopen("input.txt", "r", stdin);

	int T; // testcase
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{	// reset : 전역에서 설정한 모든 변수, 배열등을 초기화 
		// #1. 첫번째 tx는 답 잘 나오는데 뒤에서 부터 이상하다
		// #2. 중간거만 넣으면 또 잘나온다  
		// 무조건 reset 문제이다 
		injectioncnt = 0;
		ans = 21e8;
		memset(film, 0, sizeof(film));
		memset(Copy, 0, sizeof(Copy));
		
		
		// input
		cin >> D >> W >> K;

		for (int i = 0; i < D; i++)
		{
			for (int j = 0; j < W; j++)
			{
				cin >> film[i][j];
				Copy[i][j] = film[i][j];
			}
		}
		// solve
		// 애초부터 안해봐도 되는 경우도 제거
		//  >> 아무것도 안넣어도 통과하는 경우
		if (test())
			ans = 0;
		else
			func(0); // 0번행에서 시작하는 재귀

		//output
		cout << "#" << tc << " " << ans << '\n';


	}

	return 0;
}