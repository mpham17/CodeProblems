#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t-- > 0){
        long long a,b,c,d;
        scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
        long long val1 = a * d;
        long long val2 = b * c;
        if(val1 == val2){
            printf("%d \n",0);
        }
        if(val1 > val2){
            if(val2 == 0ll ||val1 % val2 == 0){
                printf("%d \n",1);
            }
            else{
                printf("%d \n",2);
            }
        }

        if(val2 > val1){
            if(val1 == 0ll ||val2 % val1 == 0){
                printf("%d \n",1);
            }
            else{
                printf("%d \n",2);
            }
        }
    }
    return 0;
}