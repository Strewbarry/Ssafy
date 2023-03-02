#include<iostream>
#include<cstring>
using namespace std;
int N, W, H;
int MAP[15][15];
int minCnt = 0;
void input(); 
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };
bool isOut(int r, int c) {
	return r < 0 || c < 0 || r >= H || c >= W;
}
void bombBrick(int row, int col, int range) { // 이부분은 BFS 로 교체해도 된다. 
	MAP[row][col] = 0;
	for (int t = 0; t < 4; t++) {
		for (int i = 0; i < range; i++) {
			int nr = row + dr[t] * i;
			int nc = col + dc[t] * i;
			if (isOut(nr, nc))continue;
			if (MAP[nr][nc] == 0)continue; // 이미 터져버렸다능 ?
			bombBrick(nr, nc, MAP[nr][nc]);
		}
	}
}
void dropGusul(int index) {
	// 해당 index 에 구술을 떨어뜨려 MAP의 벽돌을 깬다
	for (int row = 0; row < H; row++) {
		if (MAP[row][index] == 0)continue;
		bombBrick(row, index, MAP[row][index]); // 여기서부터는 시작점으로부터 "연결된" 벽돌들을 파!괴!한다.
		return;
	}
}
void gravity() {
	for (int col = 0; col < W; col++) {
		int t = H - 1;
		for (int row = H - 1; row >= 0; row--) {
			if (MAP[row][col] == 0)continue;
			int tmp = MAP[row][col];
			MAP[row][col] = 0;
			MAP[t--][col] = tmp;
		}
	}
}
int getAliveCnt() {
	int result = 0;
	for (int row = 0; row < H; row++) {
		for (int col = 0; col < W; col++) {
			if (MAP[row][col] == 0)continue;
			result++;
		}
	}
	return result;
}
void dfs(int level)
// W 개의 구슬을 떨어뜨릴 위치중, N 개를 선택하여 나열하는 방법 ( 중복 순열 ) 
{
	if (level == N) {
		// 중복순열의 경우가 하나 만들어졌다. MAP상태도 바꾸면서 진행되었으므로 바뀐 MAP에서 counting을 한다.
		minCnt = min(getAliveCnt(), minCnt);
		return;
	}
	int backup[20][20];
	memcpy(backup, MAP, sizeof(MAP)); 
	for (int i = 0; i < W; i++)
	{
		dropGusul(i); 
		gravity();
		// dropGusul과 gravity 를 실행하면 MAP의 상태가 바뀐다. ->dfs(level + 1); 리턴받고 오면 MAP상태 원상복구해야한다.
		dfs(level + 1);
		// 리턴받고 돌아왔다. MAP의 상태를 원복 시킨다.
		memcpy(MAP, backup, sizeof(MAP)); 
	}
}
int main()
{
	freopen_s(new FILE*, "Text.txt", "r", stdin); 
	// 아래와 같은 방법으로 sample input(문제에서 주어진 그림)에 대한 테스트를 해볼 수 있다.
	dropGusul(2); 
	gravity(); 
	dropGusul(2); 
	gravity(); 
	dropGusul(6); 
	gravity(); 
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		input();
		dfs(0); 
		cout << "#" << tc << " " << minCnt << endl;
	}
// cf) MAP을 파라미터로 넣을 수 없다. DP로 문제를 풀려면 특정파라미터에서 항상 같은값(같은 정답)으로 리턴을 해야하는데,
// 위의 경우는 MAP에 따라서 특정 파라미터에 따른 정답이 달라진다. 만약 MAP을 파라미터로 넘길 수 있고 , MAP의 state를 memoization 을 할 수 있을거 같다면 DP를 고려해볼만하다. 
	return 0;
}
void input() {
	cin >> N >> W >> H;
	for (int row = 0; row < H; row++)
	{
		for (int col = 0; col < W; col++)
		{
			cin >> MAP[row][col];
		}
	}
	minCnt = 1e9;
}