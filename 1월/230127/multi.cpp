#include <iostream>

using namespace std;
// 각 행에서 하나씩 뽑아서 곱한 결과값의 최대/최소 찾기
int map[4][4] = {
	3,1,4,-2,
	1,1,-1,1,
	2,3,1,4,
	5,1,0,3
};

char path[10];
int mult;
int mx=0;
int mn=100;

void run(int lev, int mul) {
	if (lev == 4) {
		if (mul > mx)
			mx = mul;
		else if (mul < mn)
			mn = mul;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		path[lev] = i;
		run(lev + 1, mul * map[lev][i]);
		path[lev] = 0;
	}
}

int main()
{
	run(0, 1);
	cout << mx << ' ' << mn;
}








