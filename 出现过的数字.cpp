#include <bits/stdc++.h>

using namespace std;

int a[100000 + 4];
int main() {
	int n, m;
	cin >> n >> m;
	int x;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		a[x]++;
	}
	for (int i = 1; i <= m; i++) {
		cin >> x;
		if (a[x]) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}
