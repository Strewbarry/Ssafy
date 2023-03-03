#include<iostream>
using namespace std;
int N, X;
int MAP[20][20];
void input()
{
	cin >> N >> X;
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
		{
			cin >> MAP[row][col];
		}
	}
}
int validCheck(int arr[20]) {
	int marked[20] = { 0 };
	for (int i = 0; i < N - 1; i++) {
		if (abs(arr[i + 1] - arr[i]) > 1)
			return 0;
		if (arr[i + 1] == arr[i]) continue;
		if (arr[i] < arr[i + 1]) {
			for (int j = i; j > i - X; j--)
			{
				if (j < 0) {
					return 0;
				}
				if (arr[i] != arr[j]) {
					return 0;
				}
				if (marked[j] == 1)
					return 0;
				marked[j] = 1;
			}
		}
		else if (arr[i] > arr[i + 1]) {
			for (int j = i + 1; j <= i + X; j++)
			{
				if (j >= N) return 0;
				if (arr[i + 1] != arr[j]) {
					return 0;
				}
				if (marked[j] == 1)
					return 0;
				marked[j] = 1;
			}
		}
	}
	return 1;
}
int main()
{
	//freopen_s(new FILE*, "text활주로.txt", "r", stdin); 
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		input();
		int cnt = 0;
		for (int row = 0; row < N; row++) {
			int temp[20];
			for (int col = 0; col < N; col++) {
				temp[col] = MAP[row][col];
			}
			if (validCheck(temp))
			{
				cnt++;
			}
		}
		for (int col = 0; col < N; col++) {
			int temp[20];
			for (int row = 0; row < N; row++) {
				temp[row] = MAP[row][col];
			}
			if (validCheck(temp))
			{
				cnt++;
			}
		}
		cout << "#" << tc << " " << cnt << endl;
	}
	return 0;
}

