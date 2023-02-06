#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>	 

using namespace std;

int graph[4][4] = {
	0,50,60,300,
	0,0,7,0,
	30,0,0,10,
	0,0,0,0
};
int used[4];
int sum;
int mini=21e8;
void run(int now, int sum) {

		if (now == 3) {
			if (mini > sum)
				mini = sum;
			return;
		}
	for (int to = 0; to < 4; to++)
	{
		if (graph[now][to] == 0)continue;
		if (used[to] == 1) continue;
		used[to] = 1;
		run(to, sum + graph[now][to]);
		used[to] = 0;
		

	}
	
}

int main()
{
	run(0, 0);
	cout << mini;



	return 0;
}