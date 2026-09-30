// Problem: https://www.codechef.com/practice/course/dynamic-programming/INTDP01/problems/ZCO14004
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> v(n), f(n);
	long long sum = 0;
	for(int i = 0; i < n; i++){
	    cin >> v[i];
	    sum += v[i];
	    if(i < 3){
	        f[i] = v[i];
	    }
	    else{
	        f[i] = v[i] + min(f[i - 1], min(f[i - 2], f[i - 3]));
	    }
	}
	cout << sum - min(f[n - 1], min(f[n - 2], f[n - 3])) << endl;
}
