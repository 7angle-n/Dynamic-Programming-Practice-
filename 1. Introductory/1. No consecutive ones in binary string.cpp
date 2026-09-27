// Problem: Calculate the number of ways of constructing a binary string such that there are no consecutive 1's
#include <bits/stdc++.h>
using namespace std;


int f(int i, int n, bool prev_one){
    if(i == n + 1) return 1; //1 valid arrangement is found
    int ans = 0;
    //Place 1 in the index
    if(prev_one == false){
        ans += f(i + 1, n, true);
    }
    //Or else place 0 on the index
    ans += f(i + 1, n, false);
    return ans;
}

int main() {
    cout << f(1, 5, false) << endl; // Returns 13
}
