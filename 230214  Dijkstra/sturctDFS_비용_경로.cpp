#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct Edge {
	int node; 
	int cost; 
};
int N, T; 
vector<Edge> adj[8]; 
void input() {
	cin >> N >> T; 
	for (int i = 0; i < T; i++)
	{
		int a, b, cost; 
		cin >> a >> b >> cost; 
		adj[a].push_back({ b,cost });
	}
}
int cnt = 0; 
int visited[8]; // 경로상에 중복 등장하지 않도록 막기
void dfs(int now,int accSum,string path)
{
	if (now == 6) { // 1 ~~~~>6
		cnt++;
		cout << "경로 발견!" << accSum << " " << path << "\n";
		return; 
	}
	for (Edge next : adj[now])
	{
		if (visited[next.node] == 1) continue; 
		visited[next.node] = 1; // 이후 경로에서 등장 x 
		dfs(next.node, accSum + next.cost, path + to_string(next.node) + "->"); // 1 ~~~~>
		visited[next.node] = 0;
	}
}
int main() {
	input(); 
	visited[1] = 1; // 1번지점은 이후에 다시 등장 안한다.
	dfs(1,0,"1->");
	cout << cnt; 
	return 0;
}