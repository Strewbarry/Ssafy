#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>	// 벡터 호출 

using namespace std;

vector<int> v;  

int main()
{
	vector<int> v(5, 2); // 2로 초기화된 5칸짜리 벡터 v 생성
						 // 5의 capacity를 가지는 벡터 v 생성 모든 원소는 2로 초기화 

	v.push_back(3);		// v의 마지막에 칸 만들고 3 추가
	v.push_back(4);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	v.pop_back();	// 마지막 칸& 데이터 삭제

	cout << v.front(); // 첫번재 원소 출력

	cout << '\n';

	cout << v.back(); // 마지막 원소 출력 
	

	return 0;
}