#include<iostream>
#include<queue>
using namespace std;

struct Node {
    int row, col; 
};
int N, M; 
char MAP[20][20];
Node S, C, D; 
int dr[] = { -1,1,0,0 }; 
int dc[] = { 0,0,-1,1 };
void input(); 
void findNode();
bool isOut(int r, int c); 
// A노드 ~~~~> B노드까지의 
// 최소 이동횟수 리턴 
int bfs(Node start, Node goal)
{
    // 이동 횟수 기록 + 큐에 등록된적 
    int    cnt[20][20] = { 0 };
    int visited[20][20] = { 0 }; 
    
    queue<Node> qu; 
    visited[start.row][start.col] = 1; 
    cnt[start.row][start.col] = 0; 
    qu.push(start); 

    while (!qu.empty())
    {
        Node now = qu.front(); qu.pop(); 
        // 뽑을 때 탐색 
        if (now.row == goal.row && now.col == goal.col)
            return cnt[now.row][now.col];
        for (int t = 0; t < 4; t++)
        {
            int nr = now.row + dr[t]; 
            int nc = now.col + dc[t];
            if (isOut(nr, nc))continue; 
            if (MAP[nr][nc] == 'x')continue; 
            if (visited[nr][nc] == 1) continue; 
            visited[nr][nc] = 1; 
            cnt[nr][nc] = cnt[now.row][now.col] + 1; 
            qu.push({ nr,nc });
        }
    }
    return -1; 
}


int main() {
    input(); 
    findNode(); 
    cout << bfs(S, C) + bfs(C, D); 
}

void input()
{
    cin >> N >> M;
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < M; c++)
        {
            cin >> MAP[r][c];
        }
    }
}

void findNode()
{
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < M; c++)
        {
            if (MAP[r][c] == 'S')
            {
                S = { r,c };
            }
            if (MAP[r][c] == 'D')
            {
                D = { r, c }; 
            }
            if (MAP[r][c] == 'C')
            {
                C = { r,c }; 
            }
        }
    }
}

bool isOut(int r, int c) {
    return r < 0 || c < 0 || r >= N || c >= M; 
}