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

int main()
{
	int nodeCnt, edgeCnt;
	cin >> nodeCnt >> edgeCnt;
	// 1. 인접행렬
	int adj[6][6] = { 0 };
	for (int i = 0; i < edgeCnt; i++)
	{
		int from, to;
		cin >> from >> to;
		adj[from][to] = 1;
	}
	int de = 1;

	// 특정 from에서 갈 수 있는 모든 to 찾기
	int node = 1;  // 보고싶은 from값
	for (int to = 0; to < 6; to++)
	{
		if (adj[node][to] == 0) continue;  // 못가는 to값 패스
		cout << to << " ";	// 갈 수 있는 곳은 출력
	}
	

	return 0;
}