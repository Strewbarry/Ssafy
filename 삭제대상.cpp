#include <iostream>

#include <vector>

#include <algorithm>

#include <string>

using namespace std;
int N, K, S;
int arr[101][2];
vector <int> in[101];
int used[101];

void dfs1(int now) { // 전위 순회 : 일반적인 dfs
    for (int i = in[now].size() - 1; i >= 0; i--) // 노드 번호가 큰 순서이므로 순서를 반전
    {
        int to = in[now][i];
        if (used[to] == 1)
        {
            continue;
        }
        used[to] = 1;
        cout << to << ' '; // 진행하면서 출력해야 하므로 재귀 전에 출력
        dfs1(to);
    }
}

void dfs2(int now) { // 후위 순회 : 맨 아래 자식 노드부터 시작해서 루트까지
    for (int i = in[now].size() - 1; i >= 0; i--) // 마찬가지로 큰 노드 번호 순으로
    {
        int to = in[now][i];
        if (used[to] == 1)
        {
            continue;
        }
        used[to] = 1;
        dfs2(to);
        cout << to << ' '; // 맨 밑에까지 도달한 후에 재귀를 빠져나오면서 출력 해야하므로 재귀 후에 출력
    }
}

int main()
{
    cin >> N >> K >> S;
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < K; i++)
    {
        in[arr[i][0]].push_back(arr[i][1]);
    }
    for (int i = 0; i < K; i++) // 인접 리스트로 노드 번호 오름차순으로 정렬
    {
        sort(in[i].begin(), in[i].end());
    }
    used[S] = 1;
    cout << S << ' '; // 전위 순회 시작 노드
    dfs1(S);
    cout << '\n';
    fill_n(used, 101, 0); // used 초기화
    used[S] = 1;
    dfs2(S);
    cout << S; // 후위 순회의 루트는 마지막에 출력
    return 0;
}





#include <iostream>

#include <vector>

#include <algorithm>

#include <string>

using namespace std;
int n;
vector<int> v[1001];
vector<int> pt1;
vector<int> pt2;
vector<int> pt3;
int visited[1001];

void dfs(int now) {
    pt2.push_back(now); // 전위 순회 : 이렇게 하는게 2번 보다 더 편할거같습니당
    for (int i = 0; i < v[now].size(); i++) // 왼쪽부터 오른쪽 순으로
    {
        int to = v[now][i];
        if (to == -1) // 처음 : 왼쪽으로 쭉 타고 내려가다가 막혔을때
        {
            if (visited[now] == 0)
            {
                pt1.push_back(now); 
                visited[now] = 1; // 벡터에 넣고 체크
            }
            continue; // 뒤로
        }
        dfs(to);
        if (visited[now] == 0)
        {
            pt1.push_back(now);
            visited[now] = 1; // 나오면서 벡터에 넣고 체크
        }
    }
    pt3.push_back(now); // 후위순회 : 전위순회랑 마찬가지
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int from, to1, to2;
        cin >> from >> to1 >> to2;
        v[from].push_back(to1);
        v[from].push_back(to2);
    }
    dfs(1);
    for (int i = 0; i < pt1.size(); i++)
    {
        cout << pt1[i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < pt2.size(); i++)
    {
        cout << pt2[i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < pt3.size(); i++)
    {
        cout << pt3[i] << ' ';
    }
    return 0;
}```