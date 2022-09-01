#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    long long mod = 1000000007;
    while(t-- > 0){
        int len,qu;
        scanf("%d %d",&len,&qu);
        long long val = 0ll;
        for(int i = 0; i < qu; i++){
            long long a,b,c;
            scanf("%lld %lld %lld",&a,&b,&c);
            val = val | c;
        }
        for(int i = 0; i < len-1; i++){
            val = (val * 2ll) %mod;
        }
        val = val % mod;
        printf("%lld \n",val);

    }
    return 0;
}