#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>	 
#include <queue>
#include <algorithm>
using namespace std;

/*
7 11
1 3 20
1 2 60
1 5 50
2 7 10
3 4 10
4 2 20
4 6 50
5 2 10
5 7 10
6 2 10
7 6 10
*/
struct road {
	int to;
	int price;
};
int node;
int branch;
vector<road> inp[100];
int start;
int goal;
int cnt;
int used[100];	//경로상에 중복등장 방지

void run(int now) {
	if (now == 6) {
		cout << "도착" << '\n';
		cnt++;
		return;
	}
	for (road next : inp[now])
	{
		if(used[next.to] == 1) continue;
		used[next.to] = 1;
		run(next.to);
		used[next.to] = 0;

	}
}

int main() {
	cin >> node >> branch;
	for (int i = 0; i < branch; i++)
	{
		int from, to, p;
		cin >> from >> to >> p;
		inp[from].push_back({to,p});
	}
	
	used[1] = 1;		//1번 출발이니 미리 used 체크
	run(1);
	cout << cnt;



	return 0;
}

