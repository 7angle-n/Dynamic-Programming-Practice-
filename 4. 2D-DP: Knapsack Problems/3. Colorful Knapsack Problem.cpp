//You are given 'J' stones labeled from 1 to 'J'. The 'i-th' stone has the weight W[i]. There are 'N' colors labeled by integers from 1 to 'N'. 
//The 'i-th' stone has the color C[i] which is an integer between 1 to 'N', both inclusive.
//You have been required to fill a Knapsack with these stones. The Knapsack can hold a total weight of 'M'.
//You are required to select exactly 'M' stones; one of each color. The sum of the weights of the stones must not exceed 'M'. 
//Since you paid a premium for a Knapsack with capacity 'M', you are required to fill the Knapsack as much as possible. If impossible return -1.
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	int j, n, m; cin >> j >> n >> m;
	vector<ll> a(j);
	vector<vector<ll>> v(105);
	for(ll i = 0; i < j; i++) cin >> a[i];
	//Grouping based on colors, color is 1-based indexing
	for(ll i = 0; i < j; i++){
	    ll color; cin >> color;
	    v[color].push_back(a[i]);
	}
	ll dp[105][10005] = {};
	for(ll x : v[1]){
	    if(x <= m) dp[1][x] = 1;
	}
	//The first row is already initialized, so we do from rest, that's why i + 1
	for(ll i = 1; i < n; i++){
	    for(ll s = 0; s <= m; s++){
	        if(dp[i][s]){
	            for(ll x: v[i + 1]){
	                if(s + x <= m){
	                    dp[i + 1][s + x] = 1;
	                }
	            }
	        }
	    }
	}
	ll ans = 0;
	for(ll s = 1; s <= m; s++){
	    if(dp[n][s]){
	        ans = max(ans, s);
	    }
	}
	cout << (ans == 0 ? -1 : m - ans) << endl;
}

//Sample Test Case:
// 6 3 10
// 2 4 3 5 2 6
// 1 1 2 2 3 3
//Expected Output = 1
