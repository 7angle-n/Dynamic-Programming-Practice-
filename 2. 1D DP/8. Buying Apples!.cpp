// Problem: https://www.spoj.com/problems/ABA12C/
#include <bits/stdc++.h>
using namespace std;
long long INF = 1e9;
vector<int> memo;

int dp(int w, int k, vector<int> &prices){
    if(w == 0) return 0;
    if(memo[w] != -1) return memo[w];
    int ans = INF;
    for(int i = 1; i <= k; i++){
        if(prices[i] != -1 && w >= i){
            int sub_cost = dp(w - i, k, prices);
            if(sub_cost != INF) ans = min(ans, sub_cost + prices[i]);
        }
    }
    return memo[w] = ans;
}

void solve(){
    int n, k; cin >> n >> k;
    vector<int> prices(k + 1);
    prices[0] = 0;
    for(int i = 1; i <= k; i++) cin >> prices[i];
    memo.clear();
    memo.resize(k + 1, -1);
    int result = dp(k, k, prices);
    if(result == INF) cout << -1 << endl;
    else cout << result << endl;
}

int main() {
    int t; cin >> t;
    while(t--){
        solve();
    }
}
