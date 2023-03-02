#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
10 13
0 1 1
0 3 4
0 2 5
1 4 3
1 5 6
2 5 8
2 7 10
2 6 9
7 6 11
6 9 2
6 8 13
7 8 12
5 6 7
*/
struct Edge {
	int to; // 어디로 향하는 간선이고?
	int cost; // 가중치
	bool operator < (Edge next) const {
		// 내가 원하는 상황 
		if (cost < next.cost)
			return false;
		if (cost > next.cost)
			return true;
		// 항상 무지성 false 
		return false; 
	}
};
int N, M; // N : 노드의 개수, M : 간선의 개수
vector<Edge>al[100]; 
// 시간복잡도 : O(V^2)
void dijkstra_for(int start) {
	// dist 준비
	int dist[100] = { 0, };
	// 모두 아주 큰 값이 들어가도록 세팅
	int MAX = 21e8; 
	for (int i = 0; i < N; i++)
		dist[i] = MAX; 
	// 출발지까지는 가중치 = 0
	dist[start] = 0; 
	// visited 준비
	// index: 노드, value: 지금 이 노드의 최단 거리가 확정이 되었는가? 
	int visited[100] = { 0, }; 
	// dijkstra 동작을 구현 
	// 노드의 개수만큼 반복 -> 한번 돌때마다 하나의 노드의 최단 거리가 확정
	// 즉, 모든 노드의 최단거리가 확정될때까지 
	for (int i = 0; i < N; i++) {
		int mincost = 21e8; 
		int now = -1; 
		for (int j = 0; j < N; j++) {
			if (dist[j] >= mincost)
				continue; 
			if (visited[j] == 1)
				continue; 
			mincost = dist[j];
			now = j; 
		}
		visited[now] = 1; 
		for (int j = 0; j < al[now].size(); j++) {
			Edge next = al[now][j]; 
			int ncost = dist[now] + next.cost;
			if (dist[next.to] <= ncost)
				continue; 
			dist[next.to] = ncost; 
		}
	}
	for (int i = 0; i < N; i++) {
		cout << i << " 까지의 최단 거리 : " << dist[i] << '\n';
	}
}

void dijkstra(int start) {
	priority_queue<Edge>pq;
	pq.push({ start, 0 });
	// dist
	int dist[100] = { 0, };
	int MAX = 21e8;
	for (int i = 0; i < N; i++)
		dist[i] = MAX;
	dist[start] = 0; 
	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop(); 
		if (dist[now.to] < now.cost)
			continue;
		for (int i = 0; i < al[now.to].size(); i++) {
			Edge next = al[now.to][i];
			int ncost = dist[now.to] + next.cost;
			if (dist[next.to] <= ncost)
				continue; 
			dist[next.to] = ncost;
			pq.push({ next.to, ncost });
		}
	}
	for (int i = 0; i < N; i++) {
		cout << i << " 까지의 최단 거리 : " << dist[i] << '\n';
	}
}
int main() {
	cin >> N >> M;
	// 간선 정보 입력
	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost; 
		al[from].push_back({ to, cost });
		al[to].push_back({ from, cost });
	}
	dijkstra(0); 
}