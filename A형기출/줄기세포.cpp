#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

struct Node {
    int row, col;
    int activeTime; // 활성화 시간 (pq 1순위)
    int vital; // 생명력 (pq 2순위)
    int lifeStart;
    int lifeEnd;
};
struct cmp
{
    // 1. 활성화시간이 빠를수록 빨리 뽑힌다.
    // 2. 생명력이 클수록 빨리 뽑힌다
    bool operator()(Node left, Node right) {
        if (left.activeTime > right.activeTime) return true;
        if (left.activeTime < right.activeTime) return false;
        return left.vital < right.vital;
    }
};
int dr[] = { -1,1,0,0 }; 
int dc[] = { 0,0,-1,1 }; 
const int zeroPoint = 350;
const int MAXN = 650;
int N, M, K;
int MAP[MAXN][MAXN];
void input();
priority_queue<Node, vector<Node>, cmp>  initStart() {
    priority_queue<Node, vector<Node>, cmp> pq;
    for (int row = zeroPoint; row < zeroPoint + N; row++)
    {
        for (int col = zeroPoint; col < zeroPoint + M; col++)
        {
            if (MAP[row][col] == 0)continue;
            pq.push({ row,col, MAP[row][col], MAP[row][col], 0, 0 + 2 * MAP[row][col] });
        }
    }
    return pq;
}
bool isAlive(Node t, int day) {
    return t.lifeStart <= day && day < t.lifeEnd; 
}
int main()
{
    //freopen_s(new FILE*, "input.txt", "r", stdin); 
    int TC;
    cin >> TC;
    for (int tc = 1; tc <= TC; tc++)
    {
        input();
        priority_queue<Node, vector<Node>, cmp> pq = initStart();

        int answer = 0;
        while (!pq.empty())
        {
            Node now = pq.top();
            pq.pop();
            if (isAlive(now, K)) { // K 시간에 now 세포가 살았는가?
                answer++;
            }
            if (now.activeTime >= K)continue; // K시간 이후로 만들어지는것은 필요없음 

            // 번식
            for (int t = 0; t < 4; t++)
            {
                int nr = now.row + dr[t];
                int nc = now.col + dc[t];
                if (MAP[nr][nc] != 0)continue;
                MAP[nr][nc] = now.vital;
                int lifeStart = now.activeTime + 1;
                int lifeEnd = lifeStart + 2 * now.vital;
                pq.push({ nr,nc,lifeStart + now.vital ,now.vital, lifeStart, lifeEnd });
            }
        }
        cout << "#" << tc << " " << answer << "\n"; 
    }
}

void input() {
    memset(MAP, 0, sizeof(MAP));
    cin >> N >> M >> K;
    for (int row = zeroPoint; row < zeroPoint + N; row++)
    {
        for (int col = zeroPoint; col < zeroPoint + M; col++)
        {
            cin >> MAP[row][col];
        }
    }
}