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

int main()
{
	int nodeCnt, edgeCnt;
	cin >> nodeCnt >> edgeCnt;
	// 2. 인접리스트
	vector<int> v[6];  //v[from] : from에서 갈 수 있는 to 들을 저장할 vector 생성
	// vector<저장할 데이터 type> 벡터이름[form 개수]

	for (int i = 0; i < edgeCnt; i++)
	{
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		// 벡터이름[from.index] 의 제일 뒤에 공간만들어서 value(to) 집어넣기 
	}

	// 특정 form에서 갈 수 있는 모든 to 찾기 
	int node = 1;
	for (int i = 0; i < v[node].size(); i++)
					//v[index].size() : vector가 갖고있는 data 개수
	{
		int to = v[node][i];
		cout << to << " ";
	}

	return 0;
}