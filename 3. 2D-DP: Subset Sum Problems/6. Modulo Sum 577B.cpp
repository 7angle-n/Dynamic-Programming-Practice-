// Problem Link: https://codeforces.com/contest/577/problem/B
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; cin >> n >> m;
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	if(n > m) cout << "YES" << endl;
	else{
	    vector<bool> dp(m, false);
	    for(int i = 0; i < n; i++){
	        vector<bool> temp_dp = dp;
	        int x = v[i] % m;
	        temp_dp[x] = 1;
	        for(int j = 0; j < m; j++){
	            if(dp[j]){
	                temp_dp[(j + x) % m] = 1;
	            }
	        }
	        dp = temp_dp;
	    }
	    if(dp[0]) cout << "YES" << endl;
	    else cout << "NO" << endl;
	}
}
