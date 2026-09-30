// Given a number n, count minimum steps to minimize it to 1 according to the following criteria:
// If n is divisible by 2 then we may reduce n to n/2.
// If n is divisible by 3 then you may reduce n to n/3.
// Decrement n by 1.
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int memo[N];

int dp(int n){
    if(n == 1) return 0;
    int &ans = memo[n];
    if(ans != -1) return ans;
    ans = INT_MAX;
    if(n % 2 == 0) ans = min(ans, dp(n/2));
    if(n % 3 == 0) ans = min(ans, dp(n/3));
    ans = min(ans, dp(n - 1));
    ans += 1;
    return ans;
}

int main() {
	int n; cin >> n;
	memset(memo, -1, sizeof(memo));
	cout << dp(n) << endl;
}
