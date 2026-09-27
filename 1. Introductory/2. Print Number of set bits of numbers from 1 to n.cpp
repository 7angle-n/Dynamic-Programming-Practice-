// Problem: Print number of set bits of numbers from 1 to n
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
	int dp[n + 1];
	dp[0] = 0;
	for(int i = 1; i <= n; i++){
	    dp[i] = dp[i / 2] + (i & 1);
	    cout << i << " --> " <<dp[i] << endl;
	}
}
