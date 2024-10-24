#include <bits/stdc++.h>
using namespace std;

long long power(long long x, long long y, long long p)
{
 
    // Initialize answer
    long long res = 1l;
 
    // Check till the number becomes zero
    while (y > 0) {
 
        // If y is odd, multiply x with result
        if (y % 2 == 1)
            res = (res * x) % p;
 
        // y = y/2
        y = y >> 1;
 
        // Change x to x^2
        x = (x * x) % p;
    }
    return res % p;
}


int main(){
    int t;
    scanf("%d",&t);
    int l,r,k;
    long long mod = 1000000007l;
    while(t-- > 0){
        cin >> l >> r >> k;
        cout << (power(9/k + 1, r, mod ) - power(9/k + 1, l, mod) + mod ) %mod << endl;
    }
    return 0;
}