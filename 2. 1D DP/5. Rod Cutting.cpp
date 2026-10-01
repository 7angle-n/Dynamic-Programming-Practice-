// Problem: Given a rod of length n and an array price[]. 
// price[i] denotes the price of a piece of length i. Determine the maximum amount obtained by cutting the rod into pieces and selling the pieces.
// Note: price[0] is always 0
// Input: price[] =  [0, 1, 5, 8, 9, 10, 17, 17, 20]
// Output: 22
// Explanation:  The maximum obtainable value is 22 by cutting in two pieces of lengths 2 and 6, i.e., 5 + 17 = 22.
#include <bits/stdc++.h>
using namespace std;

vector<int> memo;

int rodCutting(int n, vector<int> prices){
    if(n == 0) return 0;
    int ans = 0;
    if(memo[n] != -1) return memo[n];
    for(int i = 1; i <= n; i++){
        ans = max(ans, prices[i] + rodCutting(n - i, prices));
    }
    return memo[n] = ans;
}

int main() {
    int n; cin >> n;
    vector<int> prices(n + 1);
    prices[0] = 0;
    for(int i = 1; i <= n; i++) cin >> prices[i];
    memo.clear();
    memo.resize(n + 1, -1);
    cout << rodCutting(n, prices) << endl;
}
