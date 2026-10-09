// Given n positive integers and a sum. 
//Find if there exists any sub-array whose sum of elements will be equal to given sum
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> memo;

int SubSetSumWithRepeating(int i, int sum, vector<int> &a, int n){
    if(i == n) return (sum == 0);
    if(memo[i][sum] != -1) return memo[i][sum];
    int ans = 0;
    if(sum >= a[i]) ans |= SubSetSumWithRepeating(i, sum - a[i], a, n);
    ans |= SubSetSumWithRepeating(i + 1, sum, a, n);
    return memo[i][sum] = ans;
}

int main() {
	int n, sum; cin >> n >> sum;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	memo.resize(n, vector<int>(sum + 1, -1));
	cout << SubSetSumWithRepeating(0, sum, a, n) << endl;
}
