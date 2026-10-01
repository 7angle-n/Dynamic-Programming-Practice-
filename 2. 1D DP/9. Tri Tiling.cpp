// Problem: http://poj.org/problem?id=2663
#include <bits/stdc++.h>
using namespace std;

vector<long long> memo;
long long f(int n){
    if(n % 2 != 0) return 0;
    if(n == 0) return 1;
    if(n == 2) return 3;
    if(memo[n] != -1) return memo[n];
    long long ans = 4 * f(n - 2) - f(n - 4);
    return memo[n] = ans;
}

int main() {
    while(true){
        int n; cin >> n;
        if(n == -1) break;
        memo.clear();
        memo.resize(n + 1, -1);
        cout << f(n) << endl;
    }
}
