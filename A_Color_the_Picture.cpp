#include <bits/stdc++.h>
using namespace std;

bool check(vector<int>& vec,int val){
    int pos = 0;
    while(pos < vec.size()&& val > 1){
        val -= vec.at(pos++);
    }
    if(val == 0){
        return true;
    }
    if(pos == vec.size()){
        return false;
    }
    val -= vec.at(vec.size()-1) - vec.at(0);
    return val <= 0; 
}

int main(){
    int t;
    scanf("%d",&t);
    while(t-- > 0){
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);
        vector<int> vec;
        for(int i = 0; i < k; i++){
            int val;
            scanf("%d",&val);
            vec.push_back(val);
        }
        sort(vec.begin(), vec.end());
        // case 1: tripe row
        vector<int> temp;
        for(int c : vec){
            int k = c / (n);
            if(k >= 2){
                temp.push_back(k);
            }
        }
        
        if(check(vec,m)){
            printf("Yes \n");
            continue;
        }

        for(int c : vec){
            int k = c / (m);
            if(k >= 2){
                temp.push_back(k);
            }
        }

        if(check(vec,n)){
            printf("Yes \n");
            continue;
        }
        else{
            printf("No \n");
        }
    }
    return 0;
}