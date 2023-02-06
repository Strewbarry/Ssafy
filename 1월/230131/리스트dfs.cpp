#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>	 

using namespace std;

/*
   5 4 << node 개수 , edge 개수
   1 2 << edge 정보 (from , to)
   1 3
   1 4
   1 5
*/

// 5까지 도착하는 경로 출력하기

vector<int> v[6];  //v[from] : from에서 갈 수 있는 to 들을 저장할 vector 생성
int used[6]; // used, visited  >> 해당 번호를 들린적이 있는가?
vector<int> path;	//경로 기록을 위한 vector



void dfs(int now) {
	//2. 기저조건 확인 (option)
	if (now == 5) { // now == index : index 지점까지만 탐사하고 싶다.
		for (int i = 0; i < path.size(); i++)
		{
			cout << path[i] << " ";
		}
		return;
	}
	
	for (int i = 0; i < v[now].size(); i++)
	{
		int	to = v[now][i];
		// 4. 가지치기 & 판별
		if (used[to] == 1) continue; // 갔던 점이면 무시

		//3. 기록 및 처리		
		//인접행렬 사용할 때와 달리 리스트로 쓸때는 used를 이용하여 기록해주어야 루프가 발생하지 않는다.
		cout << now << "에서 " << to << " 로 갑니다 \n";
		used[to] = 1; // to로 가는 것 기록
		path.push_back(to); // path에도 기록

		//1. 재귀 시작
		dfs(to);
		path.pop_back(); // 돌아왓으니 기록 삭제
	}
}


int main()
{
	int nodeCnt, edgeCnt;
	cin >> nodeCnt >> edgeCnt;
	// 2. 인접리스트
	// vector<저장할 데이터 type> 벡터이름[form 개수]

	for (int i = 0; i < edgeCnt; i++)
	{
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		// 벡터이름[from.index] 의 제일 뒤에 공간만들어서 value(to) 집어넣기 
	}

	//// 특정 form에서 갈 수 있는 모든 to 찾기 
	//int node = 1;
	//for (int i = 0; i < v[node].size(); i++)
	//	//v[index].size() : vector가 갖고있는 data 개수
	//{
	//	int to = v[node][i];
	//	cout << to << " ";
	//}

	// 0. 재귀 호출   시 사용지점 기록
	used[1] = 1;
	path.push_back(1);
	dfs(1);

	return 0;
}