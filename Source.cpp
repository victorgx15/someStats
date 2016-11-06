#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	vector<int> X; int N = 0;
	while (N < 10 || N > 2500) cin >> N;
	for (int i = 0; i < N; i++)
	{
		int xi = -1;
		while (xi < 0 || xi > 10e5)	cin >> xi;
		X.push_back(xi);
	}

	sort(X.begin(), X.end());
	double mean = accumulate(X.begin(), X.end(), 0) / double(N);
	double median = (N % 2 == 0) ? (X[N / 2 - 1] + X[N / 2]) / 2.0 : X[N / 2];

	map<int, int> f; int mode = 0;
	for (int e : X)	f[e]++;
	for (auto e : f) if (e.second > f[mode]) mode = e.first;

	cout << mean << endl;
	cout << median << endl;
	cout << mode << endl;
	return 0;
}
