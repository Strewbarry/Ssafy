//flood fill

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int y, x;

struct Node {
    int y;
    int x;
};

void bfs(int y, int x) {
    //#1. queue 준비
    queue<Node>q;
    Node st;

q.push({ y,x });

//#2. visited 준비
int visited[5][5] = {0,};
visited[y][x] = 1;

//#3. 방향 배열
int ydir[] = { -1,1,0,0 };
int xdir[] = { 0,0,-1,1 };

//#4. BFS 동작 (flood fill)
while (!q.empty()) {
    //queue (대기열의) 맨 앞에 있는 노드를 추출
    Node now = q.front();
    q.pop();

    //now로부터 갈 수 있는 노드들을 확인하고, 그리고 queue에 삽입
    //갈 수 있는 방향 -> 문제에서 주어진다 ->상하좌우로 퍼진다
    for (int i = 0; i < 4; i++)
    {
        //다음 갈 수 잇는 좌표를 일단 본다
        int ny = now.y + ydir[i];
        int nx = now.x + xdir[i];

        //범위 체크 무조건 #1
        if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5)
            continue; //여기는 못간다

        //(ny,nx) 이미 방문했거나, 방문이 예약된 상태라면
        if (visited[ny][nx] >= 1) //if(visited[ny][nx]!=0)
            continue;

        //---내가 (ny,nx)를 갈 수 있다! 라는게 확정
        //방문 기록 (예약)
        //다음 좌표까지의 경로= 현재 위치까지의 경로에서 +1번 더 퍼져나간경로
        visited[ny][nx] = visited[now.y][now.x]+1;
        q.push({ ny,nx});
    }
}

for (int i = 0; i < 5; i++)
{
    for (int j = 0; j < 5; j++)
    {
        cout << visited[i][j]-1 << " ";
    }
    cout << endl;
}
}

int main() {
    cin >> y >> x;

//bfs(시작 노드)
//bfs(시작 좌표)=>bfs(y,x)

bfs(y, x);
}