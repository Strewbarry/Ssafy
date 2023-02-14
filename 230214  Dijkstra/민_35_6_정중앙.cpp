#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>	 
#include <queue>
#include <algorithm>
using namespace std;

int n;
struct cmp {
	bool operator()(int left, int right) {
		return left > right;
	}
};
priority_queue<int> sm;
priority_queue<int, vector<int>, cmp> bg;




int main() {
	cin >> n;
	sm.push(500);
	int now = sm.top(); sm.pop();
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a < now)
			sm.push(a);
		else
			bg.push(a);
		if (b < now)
			sm.push(b);
		else
			bg.push(b);
		int ss = sm.size();
		int sb = bg.size();
		if ((ss - sb) >= 2) {
			int tm = sm.top(); sm.pop();
			bg.push(now);
			now = tm;
		}
		else if ((ss - sb) <= -2) {
			int tm = bg.top(); bg.pop();
			sm.push(now);
			now = tm;
		}
		cout << now << '\n';
	}



	return 0;
}

