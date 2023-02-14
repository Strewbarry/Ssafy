#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>	 
#include <queue>
#include <algorithm>

using namespace std;

int N;
int MAP[1000][1000];
struct Node
{
	int time;
	int row, col;
};
struct cmp
{
	bool operator()(Node& left, Node& right)
	{
		return left.time > right.time;
	}
};
bool isOut(int r, int c) {
	return r < 0 || c < 0 || r >= N || c >= N;
}
int main() {
	priority_queue<Node, vector<Node>, cmp> pq;
	cin >> N;
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
		{
			cin >> MAP[row][col];
			pq.push({ MAP[row][col], row, col });
		}
	}
	int dr[] = { -1,1,0,0 };
	int dc[] = { 0,0,-1,1 };
	int isBombed[1000][1000] = { 0 }; // [row][col] 이 터졌는가? 
	int answer = 0;
	while (!pq.empty())
	{
		Node now = pq.top();
		pq.pop();
		if (isBombed[now.row][now.col] == 1)continue;
		// process 
		answer = MAP[now.row][now.col];
		isBombed[now.row][now.col] = 1;
		for (int t = 0; t < 4; t++)
		{
			int nr = now.row + dr[t];
			int nc = now.col + dc[t];
			if (isOut(nr, nc))continue;
			isBombed[nr][nc] = 1;
		}
	}
	cout << answer << "초";
	return 0;
}

