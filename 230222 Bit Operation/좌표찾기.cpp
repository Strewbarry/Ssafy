#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;

int mapp[100][100];
struct node {
	int y;
	int x;
};
unordered_map<int, vector<node>> um;

/*
3
15 11 -7
55 -7 11
-7 -55 -9
*/
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> mapp[i][j];
		}
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			um[mapp[i][j]].push_back( { i,j });
		}
	}

	int a;
	cin >> a;

	if (um.count(a) > 0) {
		for (int i = 0; i < um[a].size(); i++)
		{
			cout << um[a][i].y << ' ' << um[a][i].x << '\n';
		}
	}







	return 0;
}