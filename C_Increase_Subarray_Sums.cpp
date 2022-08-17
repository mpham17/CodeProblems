#include <bits/stdc++.h>
using namespace std;

struct my_comparator
{
    // queue elements are vectors so we need to compare those
    bool operator()(std::vector<int> const& a, std::vector<int> const& b) const
    {
        return a[0] < b[0];
    }
};

int main(){
    int t;
    scanf("%d",&t);
    while(t-- > 0){
        int len, x;
        vector<int> vec;
        scanf("%d %d",&len,&x);
        for(int i = 0; i < len; i++){
            int val;
            scanf("%d",&val);
            vec.push_back(val);
        }
        vector<int> tempRes;
        priority_queue<vector<int>,vector<vector<int>>,my_comparator> qu;
        qu.push({0,0});
        for(int temp = 1; temp <= len; temp++){
            int cur = 0;
            for(int i = 0; i < temp; i++){
                cur += vec.at(i);
            }
            int tempMax = cur;
         //   printf("tempMax is %d", tempMax);
            for(int i = temp; i < len; i++){
                cur -= vec.at(i-temp);
                cur += vec.at(i);
                tempMax = max(tempMax,cur);
           //     printf("tempMax is %d", tempMax);
            }
            qu.push({tempMax,temp});
            
         //   printf("This is vector %d %d \n",tempMax,temp);
        }
        int pre = qu.top()[0];
        // for(vector<int> v : qu){
        //     printf("This is vector %d %d",v[0],v[1]);
        // }
        printf("%d ",pre);
        for(int i = 1; i <= len; i++){
            while(qu.size() > 0 && qu.top()[1] < i){
                pre = max(pre,qu.top()[0] + x * min(qu.top()[1],i));
                qu.pop();
            }
            if(qu.top()[1] >= i){
                pre = max(pre,qu.top()[0] + x * i);
            }
            printf("%d ",pre);
        }
        printf("\n");
    }
    return 0;
}