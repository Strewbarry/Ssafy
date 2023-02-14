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
		int mincost = 21e8; // 지금 가장 작은 가중치를 가진 간선의 값
		int now = -1; // 내가 지금 가려고 하는 노드 
		// 지금 가장 가중치가 작은 간선을 찾을것 
		for (int j = 0; j < N; j++) {
			// j번째 노드에 기록된 후보지가 최소값보다 작으면 -> 갱신 
			if (dist[j] >= mincost)
				continue; 
			// 이미 확정된 노드라면 -> 다시 갈 필요 X
			if (visited[j] == 1)
				continue; 
			// 새로운 최소값을 찾았다! 
			mincost = dist[j];
			now = j; 
		}
		// now까지의 최단 거리 = 확정
		visited[now] = 1; 
		for (int j = 0; j < al[now].size(); j++) {
			Edge next = al[now][j]; 
			// 다음 노드까지의 비용 = 지금 확정된 노드까지의 비용(거리) + next까지 가는 비용
			int ncost = dist[now] + next.cost; 
			// 새로운 경로를 찾았다
			// 하지만, 이미 기록된 후보지보다 더 오래걸리는 경로면 쓸모 없다 
			if (dist[next.to] <= ncost)
				continue; // 새로운 후보지로 등록하지 않는다. 
			dist[next.to] = ncost; 
		}
	}
	for (int i = 0; i < N; i++) {
		cout << i << " 까지의 최단 거리 : " << dist[i] << '\n';
	}
}
/*
** Dijkstra는 인접 리스트로 구성 
준비 단계
#1. priority queue 준비
->시작 Edge를 일단 삽입(시작 노드, 0)
#2. dist 준비
->모두 아주 큰값으로 채운 후
->시작 노드까지의 최단 거리를 초기값 설정(0)
#3. visited 준비
구현 단계
#1. 더이상 갈 후보지가 없을때까지 반복
#2. 가장 가중치가 작은 간선 채택 -> (top) = now
->이 노드를 확정!
#3. now로부터 갈수 있는 간선들 확인하면서
->dist 기록 갱신
->pq에 후보지 삽입
*/
// PQ를 사용한 dijkstra 시간복잡도 : 
// 최소 모든 간선 한번씩 : O(E)
// 이 모든 간선이 최소 한번씩은 PQ에 삽입 -> O(logE)
// E개의 간선이 PQ에서 heapify를 한다 -> O(ElogE)
// ** 1. pq를 쓴다 2. 그래프의 구성은 인접 리스트다
void dijkstra(int start) {
	// priority queue
	priority_queue<Edge>pq;
	// 시작 노드를 삽입 
	pq.push({ start, 0 });
	// dist
	int dist[100] = { 0, };
	int MAX = 21e8;
	for (int i = 0; i < N; i++)
		dist[i] = MAX;
	dist[start] = 0; 
	// visited
	//int visited[100] = { 0, }; 
	// 구현 단계
	// 더이상 갈 후보지가 없을떄 까지 반복 
	while (!pq.empty()) {
		// 후보지 중 가장 가중치가 낮은 간선을 뽑아옵니다. 
		// priority queue -> cost를 기준으로 MINHEAP
		Edge now = pq.top();
		pq.pop(); 
		// 이미 확정된 노드라면 이 노드에 대해서는 아무것도 안해도 된다!
		//if (visited[now.to] == 1)
			//continue; 
		// now까지의 최단거리 확정된다! 
		//visited[now.to] = 1; 
		// 이미 now로 나왔던 노드 -> 첫번쨰 나왔을때 거리가 확정
		// 이후에 나온 now와 같은번 노드 = 절대 dist에 기록된 값보다 작을일 없다. 
		// 만약 now랑 같은 번호가 다시 나왔는데, 이게 dist에 기록된것보다 크면 -> 
		// 이 전에 이미 확정된 노드이니 -> 여기서부터 더 볼 필요 없다! 
		if (dist[now.to] < now.cost)
			continue;
		// now로부터 갈수 있는 간선들을 확인
		for (int i = 0; i < al[now.to].size(); i++) {
			Edge next = al[now.to][i];
			// ncost = next번까지의 최종 비용
			int ncost = dist[now.to] + next.cost; 
			// 만약 지금 최종 비용이 이미 기록되어있는 후보 경로의 비용보다 크거나 같으면
			if (dist[next.to] <= ncost)
				continue; // 쓸모없는 경로 
			// next까지 가기 위한 새로운 최단 거리  찾음!~
			dist[next.to] = ncost; 
			// 새로운 후보지로 등록 
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