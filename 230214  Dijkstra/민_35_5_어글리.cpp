#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>	 
#include <queue>
#include <algorithm>

using namespace std;

struct cmp {
	bool operator() (int left, int right) {
		return left > right;
	}
};

priority_queue<long long, vector<long long>, greater<long long>> un;
long long prevv;
long long order[1501];
int out[1500];
int mul[3] = {2,3,5};
int cnt;


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> out[i];
	}

	un.push(1);
	while (cnt <= 1500) {
		long long now = un.top(); un.pop();
		if (now == prevv) continue;
		order[cnt] = now;
		cnt++;
		for (int i = 0; i < 3; i++)
		{
			un.push(now * mul[i]);
		}
		prevv = now;
	}

	for (int i = 0; i < n; i++)
	{
		cout << order[out[i]-1] << ' ';
	}



	return 0;
}

