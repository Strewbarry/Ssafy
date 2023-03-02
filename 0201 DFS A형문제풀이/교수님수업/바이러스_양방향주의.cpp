#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>	 

using namespace std;

int graph[101][101];
int used[150];
int com;

int cnt;
int goal;
int ccnt;

void run(int now) {
	if (cnt) return;
	if (now == goal) {
		cnt = 1;
		return;
	}
	
	for (int to = 0; to < com; to++)
	{
		if (graph[now][to] == 0)continue;
		if (used[to] == 1)continue;
		used[to] = 1;
		run(to);
	}
}


int main()
{
	int n = 0; // 입력 데이터 갯수
	int y = 0;	// 입력 좌표
	int x = 0;
	cin >> com;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> y >> x;
		graph[y-1][x-1] = 1;
		graph[x - 1][y - 1] = 1;		
		//양방향으로 왕복이 전염이 가능하므로 역주행이 가능하게 넣어주어야 한다.
	}

	for (int i = 0; i < com; i++)
	{
		memset(used, 0, sizeof(used));
		cnt = 0;
		goal = i;
		used[0] = 1;
		run(0);
		if (cnt == 1)
			ccnt += 1;
	}
	cout << ccnt-1;

	return 0;
}