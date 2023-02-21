#include<iostream>
#include<queue>
using namespace std; 
const int MAXN = 1000;
struct Node {
	int row, col;
	int accCost;
};
struct cmp
{
	bool operator()(Node& left, Node& right)
	{
		return left.accCost > right.accCost; 
	}
};
int dr[] = { -1,1,0,0 }; 
int dc[] = { 0,0,-1,1 }; 
int N; 
int MAP[MAXN][MAXN]; 
Node start; 
bool isOut(int r, int c) {
	return r < 0 || c < 0 || r >= N || c >= N; 
}
void input()
{
	cin >> start.row >> start.col; 
	cin >> N; 
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
		{
			cin >> MAP[row][col]; 
		}
	}
	start.accCost = MAP[start.row][start.col]; 
}
int dist[MAXN][MAXN];
void dijkstra()
{
	const int INF = 1e9;
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
		{
			dist[row][col] = INF;
		}
	}
	priority_queue<Node, vector<Node>, cmp> pq; 
	dist[start.row][start.col] = start.accCost; 
	pq.push(start); 
	while (!pq.empty())
	{
		Node now = pq.top(); pq.pop(); 
		if (dist[now.row][now.col] < now.accCost)continue; 
		for (int t = 0; t < 4; t++)
		{
			int nr = now.row + dr[t]; 
			int nc = now.col + dc[t]; 
			if (isOut(nr, nc))continue; 
			if (MAP[nr][nc] == -1)continue; 
			int newCost = now.accCost + MAP[nr][nc]; 
			if (newCost < dist[nr][nc])
			{
				dist[nr][nc] = newCost;
				pq.push({nr, nc, newCost });
			}
		}
	}
}
int main()
{
	input(); 
	dijkstra();
	int maxValue = -1; 
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
		{
			if (maxValue < dist[row][col] && MAP[row][col] != -1)
			{
				maxValue = dist[row][col];
			}
		}
	}
	cout << maxValue; 
	return 0; 
}