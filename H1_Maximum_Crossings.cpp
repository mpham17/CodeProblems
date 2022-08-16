#include <bits/stdc++.h>
using namespace std;

int get(vector<int>& vec,int pos){
    pos += 1;
    int res = 0;
    while(pos > 0){
        res += vec.at(pos);
        pos -= pos & -pos;
    }
   // cout << res << endl;
    return res;
}

void update(vector<int>& vec,int pos){
    pos += 1;
    while(pos < vec.size()){
        vec.at(pos) += 1;
        pos += pos & -pos;
    }
}

int main(){
    int t;
    scanf("%d",&t);
    while(t-- > 0){
        int len;
        scanf("%d",&len);
        vector<int> vec;
        for(int i = 0; i < len; i++){
            int temp;
            scanf("%d",&temp);
            vec.push_back(temp);
        }
        // for(int c : vec){
        //     printf("%d %d %d \n",c,len,t);
        // }
        vector<int> pos;
        for(int i = 0; i < len+1; i++){
            pos.push_back(0);
        }
        int res = 0;
        for(int i = 0; i < len; i++){
            res += i - get(pos,vec.at(i)-1) ;
            update(pos,vec.at(i));
        }
        printf("%d \n",res);
    }
    return 0;
}