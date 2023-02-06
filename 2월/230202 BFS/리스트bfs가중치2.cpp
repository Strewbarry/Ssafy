#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>	 
#include <queue>

using namespace std;

struct node {
	int n;
	int lev;
};
vector<vector<int>> inp(5);
int used[10];
queue<node> q;

int main()
{
	inp[0] = { 1,2,3 };
	inp[1] = { 2,3 };
	inp[2] = { 3 };
	inp[3] = { 4 };

	int input;
	cin >> input;

	q.push({ input,0 });
	used[input] = 1;
	int cnt = 0;

	while (!q.empty())
	{
		node now = q.front();
		q.pop();
		if (now.n == 4) {
			cout << now.lev;
			break;
		}

		for (int i = 0; i < inp[now.n].size(); i++)
		{
			int next = inp[now.n][i];
			if (used[next] == 1) continue;
			used[next] = 1;
			q.push({ next,now.lev + 1 });



			
		}
	}
	


	return 0;
}