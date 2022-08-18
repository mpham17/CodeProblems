#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t-- > 0){
        long long len, a,res;
        scanf("%lld %lld %lld",&len,&a,&res);
        int odd = 0;
        int even = 0;
        for(int i = 0; i < len;i ++){
            int val;
            scanf("%d", &val);
            if(val % 2 == 0){
                even += 1;
            }
            else{
                odd += 1;
            }
        }
        if(odd % 2 == 0){
            if(a % 2 == 0){
                if(res % 2ll==0ll){
                    printf("Alice \n");
                }
                else{
                    printf("Bob \n");
                }
            }
            else{
                if(res % 2ll==1ll){
                    printf("Alice \n");
                }
                else{
                    printf("Bob \n");
                }
            }
        }
        else {
            if(a % 2 == 0){
                if(res % 2ll==1ll){
                    printf("Alice \n");
                }
                else{
                    printf("Bob \n");
                }
            }
            else{
                if(res % 2ll==0ll){
                    printf("Alice \n");
                }
                else{
                    printf("Bob \n");
                }
            }
        }
        

        
    }
    return 0;
}