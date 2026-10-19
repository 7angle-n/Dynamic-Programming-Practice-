// Problem: https://www.spoj.com/problems/KNAPSACK/
#include <bits/stdc++.h>
using namespace std;

const int N = 2001;

vector<int> s(N), v(N);
int memo[N][N];

int Knapsack(int index, int size){
    if(index == 0) return 0;
    int &ans = memo[index][size];
    if(ans != -1) return ans;
    ans = 0;
    if(s[index] <= size){
        ans = v[index] + Knapsack(index - 1, size - s[index]);
    }
    ans = max(ans, Knapsack(index - 1, size));
    return ans;
}

int main() {
	int sz, n; cin >> sz >> n;
	for(int i = 1; i <= n; i++){
	    cin >> s[i] >> v[i];
	}
	memset(memo, -1, sizeof(memo));
	cout << Knapsack(n, sz) << endl;
}
