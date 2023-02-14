#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>	 
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

using namespace std;

int n;
int gold[1000];

struct node {
	int weight;	  // 무게 
	bool isGold;  // 돌, 금 확인 -> 두개뿐이니 간편하게 bool이용
};

struct cmp {
	bool operator()(node left, node right) {
		// 조건 1. 무게가 작은 것이 앞으로 
		if (left.weight < right.weight)
			return false;
		if (left.weight > right.weight)
			return true;

		// 조건 2. 돌보다 금이 앞으로
		if (left.isGold == true && right.isGold == false)
			return false;
		if (left.isGold == false && right.isGold == true)
			return true;

		return false;
	}
};

priority_queue<node, vector<node> ,cmp> pq;
int cnt;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int w;
		cin >> w;
		pq.push({ w,true });
	}
	while (1) 
	{
		// 첫번째 돌을 꺼내고 pq목록에서 삭제
		node first = pq.top(); pq.pop();
		// 꺼낸 것이 돌이면 while 중단
		if (first.isGold == false)break;
		cnt++;

		// 두번째 돌을 꺼내고 pq목록에서 삭제
		node second = pq.top(); pq.pop();
		// 꺼낸 것이 돌이면 while 중단
		if (second.isGold == false)break;
		cnt++;

		// 두번째 꺼낸 금.무게 * 2 짜리 돌 집어넣기
		pq.push({ 2 * second.weight ,false });


	}
	cout << cnt;

	
	


	return 0;
}

