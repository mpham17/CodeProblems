#include <bits/stdc++.h>
using namespace std;

int get(vector<int>& vec, int pos1, int pos2){
    int len = vec.size();
    int a = vec.at(pos1) - vec.at(pos2);
    int b = pos2 - pos1;
    int count = 0;
    for(int i = 0; i < len; i++){
        if(a*(i - pos1) + b * (vec.at(i) - vec.at(pos1)) != 0){
            count += 1;
        }
    }
    return count;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t-- > 0){
        int len;
        scanf("%d", &len);
        vector<int> vec;
        for(int i = 0; i < len; i++){
            int val;
            scanf("%d",&val);
            vec.push_back(val);
        }
        if(len == 1 || len == 2){
            printf("%d \n",0);
            continue;
        }
        int minVal = len;
        for(int i = 0; i < len; i++){
            for(int j = i + 1; j < len; j++){
                minVal = min(minVal,get(vec,i,j));
            }
        }
        printf("%d \n",minVal);
    }
    return 0;
}