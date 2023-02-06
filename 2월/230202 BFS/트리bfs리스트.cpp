#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>	 
#include <queue>

using namespace std;

int map[5][5] = {
	0,1,0,0,1,
	0,0,1,1,0,
	0,0,0,0,0,
	0,0,0,0,0,
	0,0,0,0,0
};
vector<vector <int>> inp(5);

char mem[6] = {"ACTSB"};

queue<int> q;


int main()
{

	inp[0] = { 1,4 };
	inp[1] = { 2,3 };

	q.push(0);

	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		cout << mem[now] << ' ';
		for (int i = 0; i < inp[now].size(); i++)
		{
			int next = inp[now][i];
			q.push(next);
		}
	}
	


	return 0;
}