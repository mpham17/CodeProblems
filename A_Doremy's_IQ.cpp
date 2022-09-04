#include <bits/stdc++.h>
using namespace std;

int b[100005];
int main(){
    int t;
    scanf("%d",&t);
    while(t-- > 0){
        int n,q;
        scanf("%d %d",&n,&q);
        vector<int> vec;
        for(int i = 0; i < n; i++){
            int a;
            scanf("%d",&a);
            vec.push_back(a);
        }
        int cur = 0;
        for(int i = vec.size()-1; i >= 0;i--){
            if(cur >= vec.at(i)){
                b[i] = 1;
            }
            else if(cur < vec.at(i) && cur < q){
                cur += 1;
                b[i] = 1;
            }
            else{
                b[i] = 0;
            }
        }

        for(int i = 0; i < q; i++){
            printf("%d",b[i]);
        }
        printf("\n");
    }
    return 0;
}