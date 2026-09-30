// Problem: https://www.spoj.com/problems/ACODE/
#include <bits/stdc++.h>
using namespace std;

string s;
vector<int> memo;

long long dp(int index){
    if(index == s.size()) return 1;
    if(memo[index] != -1) return memo[index];
    long long ans = 0;
    // When digit between 1 to 9
    if(s[index] >= '1' && s[index] <= '9'){
        ans += dp(index + 1);
    }
    // When number between 10 to 19
    if(index + 1 < s.size() && s[index] == '1'){
        ans += dp(index + 2);
    }
    // When number between 20 to 26
    if(index + 1 < s.size() && s[index] == '2' && s[index + 1] <= '6'){
        ans += dp(index + 2);
    }
    return memo[index] = ans;
}

int main() {
	while(1){
	    cin >> s;
	    if(s[0] == '0') break;
	    memo.clear();
	    memo.resize(s.size() + 1, -1);
	    cout << dp(0) << endl;
	}
}
