#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>	 
#include <queue>

using namespace std;

int n;
int m;

int mat[10][10];

//7 6
//0 1
//0 2
//1 3
//1 4
//4 5
//4 6



void bfs(int start) {
	// #1. queue 준비
	queue<int> q;
	// #1-1. 시작노드 삽입
	q.push(start);


	// q가 비어있지 않는 동안 반복
	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		cout << now << ' ';

		for (int next = 0; next < n; next++)
		{
			// now 에서 next로 갈 수 없다면 continue;
			if (mat[now][next] == 0) continue;

			// next로 갈 수 있다면 queue 삽입
			q.push(next);
		}
	}
}

int main()
{
	////queue 사용법
	//queue<int> q;	//queue 생성
	//// 1. 삽입
	//q.push(1); // { 1 }
	//q.push(2); // { 1, 2 }
	//q.push(3); // { 1, 2, 3 }
	//// #2. peek >> queue의 맨 앞의 값 확인 
	//cout << q.front() << '\n'; //{ 1 } 출력
	//// #3. size() >> queue의 요소 갯수
	//cout << q.size() << '\n';
	//// #4. empty() >> queue 가 비어있으면 true ,  아니면 false
	//cout << q.empty() << '\n';
	//// #5. pop() >> 제일 앞 요소 삭제
	//q.pop();
	//cout << q.front() << '\n';	// { 2, 3 } 출력




	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int from, to;
		cin >> from >> to;

		mat[from][to] = 1;
	}

	bfs(0);

	return 0;
}