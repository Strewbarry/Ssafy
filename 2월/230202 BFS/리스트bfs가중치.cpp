#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>	 
#include <queue>

using namespace std;


struct Node {   //구조체를 사용하여 가중치를 적용한다
	int n;
	int price;
};


vector<vector<Node>> alist(4);    //구조체를 벡터의 type으로 설정
int used[4];
int cnt;

void run(int now, int sum) {  // 경로의 가중치 합산을 위해 sum 설정
	if (now == 3) {             // 3에 도착하면 
		cout << sum << endl;      // 가중치 합산 출력
		return;
	}

	for (int i = 0; i < alist[now].size(); i++)
	{
		Node next = alist[now][i];
		if (used[next.n] == 1)continue;
		used[next.n] = 1;
		run(next.n, sum + next.price);
		used[next.n] = 0;
	}
}

int main()
{
	alist[0] = { {1,5},{2,7},{3,10} };
	alist[1] = { {2,2},{3,1} };
	alist[2] = { {3,1},{0,90} };

	used[0] = 1;
	run(0,0);

	


	return 0;
}