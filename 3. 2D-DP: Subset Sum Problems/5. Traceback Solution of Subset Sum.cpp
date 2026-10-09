#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> memo;

int SubSetSum(int i, int sum, vector<int> &a, int n){
    if(i == n) return (sum == 0);
    if(memo[i][sum] != -1) return memo[i][sum];
    int ans = 0;
    if(sum >= a[i]) ans |= SubSetSum(i + 1, sum - a[i], a, n);
    ans |= SubSetSum(i + 1, sum, a, n);
    return memo[i][sum] = ans;
}

void printSubset(int i, int sum, vector<int> &a, int n){
    if(i == n) return;
    if(SubSetSum(i + 1, sum - a[i], a, n)){
        cout << a[i] << " ";
        printSubset(i + 1, sum - a[i], a, n);
    }
    else if(SubSetSum(i + 1, sum, a, n)){
        printSubset(i + 1, sum, a, n);
    }
}

int main() {
	int n, sum; cin >> n >> sum;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	memo.resize(n, vector<int>(sum + 1, -1));
	cout << SubSetSum(0, sum, a, n) << endl;
	printSubset(0, sum, a, n);
}
