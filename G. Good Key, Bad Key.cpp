#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t-- > 0){
        long long len, key;
        scanf("%lld %lld",&len,&key);
        vector<long long> vec;
        for(int i = 0; i < len; i++){
            long long val;
            scanf("%lld",&val);
            vec.push_back(val);
        }
        vector<vector<long long>>num;
        vector<long long> tempList;
        long long temp = 0ll;
        for(int c : vec){
            temp += c - key;
            tempList.push_back(temp);
        }
        long long tempRes = tempList.at(len-1);
        for(int i = len - 1; i >= 0; i--){
            vector<long long> d;
            d.push_back(vec.at(i));
            d.push_back(i);
            num.push_back(d);
            vector<vector<long long>>nextNum;
            for(vector<long long> c : num){
                if(len -c.at(1) >= 30 || pow(2,len -c.at(1))  > c.at(0)){
                    continue;
                }
                else{
                    nextNum.push_back(c);
                }
            }
            long long tempVal = 0ll;
            for(vector<long long> c : nextNum){
                tempVal += c.at(0)/pow(2,len -c.at(1));
            }
            num = nextNum;
            long long  add;
            if(i -1 >= 0){
                add = tempList.at(i-1);
            }
            else{
                add = 0ll;
            }
            tempRes = max(tempRes,add + tempVal);
        }
        printf("%lld \n",tempRes);
    }
    return 0;
}