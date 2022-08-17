#include <bits/stdc++.h>
using namespace std;
map<long long,vector<vector<long long>>> m;
long long res = 0ll;
int row,col;

void process(vector<long long>& vec){
    sort(vec.begin(), vec.end());
    // for(int c : vec){
    //     printf("%d ",c);
    // }
    long long cur = 0ll;
    for(int i = 1; i < vec.size(); i++){
        cur += (vec.at(i) - vec.at(0));
    }
    res += cur;
    for(int i = 1; i < vec.size(); i++){
        cur -= (vec.at(i) - vec.at(i-1)) * (long long)(vec.size() - i);
        res += cur;
    }
    // if(res > 2000000000){
    //     printf("b");
    // }
}

void solve(){
    for(auto &[i, j]:m){
        vector<long long> vec1;
        vector<long long> vec2;
        for(vector<long long> k : m[i]){
            vec1.push_back(k.at(0));
            vec2.push_back(k.at(1));
        }
        process(vec1);
        process(vec2);
    }
    
}

int main(){
    scanf("%d %d",&row,&col);
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            long long val;
            scanf("%lld",&val);
            m[val].push_back({i,j});
        }
    }
    solve();
    printf("%lld",res);
    return 0;
}