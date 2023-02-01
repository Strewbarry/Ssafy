#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

/*
   5 4 << node 개수 , edge 개수
   1 2 << edge 정보 (from , to)
   1 3
   1 4
   1 5
*/

int nodeCnt, edgeCnt;
int adj[6][6] = { 0 };  //adj[from][to] = 갈수 있는가?

void dfs(int now) {
	// now 지점 도착

	// 2. 기저조건확인 (Option)		아래의 continue가 이미 기저조건 역할을 하고있으므로 option이다
	
	for (int to = 0; to <= nodeCnt; to++)
	{
		//재귀의 가지치기와 비슷한 역할을 한다 (판별 후 진행)
		if (adj[now][to] == 0) continue;  // now>>to 불가능 하면 무시


		cout << now << "에서 " << to << "로 갑니다! \n";

		//1. 재귀의 기본구조 이용
		dfs(to);
	}

}

int main()
{
	cin >> nodeCnt >> edgeCnt;
	// 1. 인접행렬
	for (int i = 0; i < edgeCnt; i++)
	{
		int from, to;
		cin >> from >> to;
		adj[from][to] = 1;
	}
	int de = 1;

	// 특정 from에서 갈 수 있는 모든 to 찾기
	// 
	//int node = 1;  // 보고싶은 from값
	//for (int to = 0; to < 6; to++)
	//{
	//	if (adj[node][to] == 0) continue;  // 못가는 to값 패스
	//	cout << to << " ";	// 갈 수 있는 곳은 출력
	//}

	dfs(1);

	return 0;
}