#include<iostream>
#include<queue>
using namespace std; 
struct Node {
	int row, col; 
};
int N, M; 
int MAP[100][100]; 
void input()
{
	cin >> N >> M; 
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < M; col++)
		{
			cin >> MAP[row][col];
		}
	}
}
int visited[100][100] = { 0 };
int dr[] = { -1,1,0,0 }; 
int dc[] = { 0,0,-1,1 }; 
bool isOut(int r, int c) {
	return r < 0 || c < 0 || r >= N || c >= M; 
}
void bfs(int row, int col)
{
	queue<Node> qu; 
	visited[row][col] = 1; // 이후에 다시 (row, col)을 queue에 등록하지 못하도록
	qu.push({ row,col }); 
	while (!qu.empty())
	{
		Node now = qu.front(); 
		qu.pop(); 
		for (int t = 0; t < 4; t++)
		{
			int nr = now.row + dr[t]; 
			int nc = now.col + dc[t]; 
			if (isOut(nr, nc))continue; 
			if (MAP[nr][nc] == 0)continue; 
			if (visited[nr][nc] == 1) continue; // 이미 큐에 등록된적 있는경우 
			visited[nr][nc] = 1; 
			qu.push({ nr,nc }); 
		}
	}
}
int main()
{
	input(); 
	int cnt = 0; 
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < M; col++)
		{
			if (visited[row][col] == 0 && MAP[row][col] == 1)
			{
				bfs(row, col); // (row,col) 을 시작점으로 연결된 요소들 visited 처리
				cnt++; 
			}
		}
	}
	cout << cnt; 
	return 0; 
}