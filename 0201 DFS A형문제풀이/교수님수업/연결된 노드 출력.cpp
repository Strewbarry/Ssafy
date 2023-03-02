#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

int mem[4] = { 15,99,88,-77 };
int graph[4][4] = {
	0,1,0,1,
	0,0,0,1,
	1,0,0,1,
	0,0,0,0
};


int main()
{
	int n = 0;
	cin >> n;
	for (int i = 0; i < 4; i++)
	{
		if (graph[n][i] == 0) continue;
		cout << mem[i] << ' ';
	}





	return 0;
}