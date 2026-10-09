#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, sum; cin >> n >> sum;
	vector<int> a(n + 1);
	a[0] = 0;
	for(int i = 1; i <= n; i++) cin >> a[i];
	vector<int> dp(sum + 1, 0);
	dp[0] = 1;
	for(int i = 1; i <= n; i++){
	    for(int j = sum; j >= 0; j--){
	        if(j - a[i] >= 0){
	            dp[j] |= dp[j - a[i]];
	        }
	    }
	}
	cout << dp[sum] << endl;
}
