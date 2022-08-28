#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t-- > 0){
        int len;
        scanf("%d",&len);
        vector<int> vec;
        for(int i = 0; i < len; i++){
            int val;
            scanf("%d",&val);
            vec.push_back(val);
        }
        int start = 0;
        vector<int> res;
        vector<int> temp;
        set<int> hs;
        for(int i = len - 1; i >= 0; i--){
            hs.insert(vec.at(i));
            while(hs.count(start) == 1){
                start += 1;
            }
            temp.push_back(start);
        }
        reverse(temp.begin(),temp.end());
        
        for(int i = 0; i < len; i++){
            start = 0;
            hs.clear();
            int index = i;
            while(index < len && start <  temp.at(i)){
                hs.insert(vec.at(index));
                while(hs.count(start) == 1){
                    start += 1;
                }
                index += 1;
            }
            i = index -1;
            res.push_back(start);
        }
        printf("%d \n",res.size());
        for(int c : res){
            printf("%d ",c);
        }
        printf("\n");
    }
    return 0;
}