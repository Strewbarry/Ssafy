#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>	 

using namespace std;

int graph[4][4] = {
	0,1,1,1,
	0,0,1,1,
	1,0,0,1,
	0,0,0,0
};

int used[4];
int cnt;

void run(int now) {
	for (int to = 0; to < 4; to++)
	{
		if (now == 3) {
			cnt++;
			return;
		}
		if (graph[now][to] == 0)continue;
		if (used[to] == 1)continue;
		used[to] = 1;
		run(to);
		used[to] = 0;  //복구 X : 연결된 노드를 1회씩만 모두 탐색한다  // 연결이 가능한가?
					   //복구 O : 모든 경로를 탐색한다				   // 모든 경로 출력 or 카운트
	}
}

int main()
{
	used[0] = 1;
	run(0);
	cout << cnt;

	return 0;
}