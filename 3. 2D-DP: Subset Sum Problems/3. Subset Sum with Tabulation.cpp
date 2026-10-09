#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, sum; cin >> n >> sum;
	vector<int> a(n + 1);
	a[0] = 0;
	for(int i = 1; i <= n; i++) cin >> a[i];
	vector<vector<int>> dp;
	dp.resize(n + 1, vector<int>(sum + 1, 0));
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++){
	    for(int j = 0; j <= sum; j++){
	        dp[i][j] = dp[i - 1][j];
	        if(j - a[i] >= 0){
	            dp[i][j] |= dp[i - 1][j - a[i]];
	        }
	    }
	}
	for(int i = 0; i <= n; i++){
	    for(int j = 0; j <= sum; j++){
	        cout << dp[i][j] << " ";
	    }
	    cout << endl;
	}
}
