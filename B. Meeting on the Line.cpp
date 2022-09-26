#include <bits/stdc++.h>
using namespace std;

struct MyStruct
{
    int key;
    int val;

};

int main(){
    int t;
    scanf("%d",&t);
    while(t-- > 0){
        int len;
        scanf("%d",&len);
        if(len == 1){
            int val,val2;
            scanf("%d %d",&val,&val2);
            printf("%d \n",val);
            continue;
        }

        vector<int> vec1;
        vector<int> vec2;
        for(int i = 0; i < len; i++){
            int val;
            scanf("%d",&val);
            vec1.push_back(val);
        }

        for(int i = 0; i < len; i++){
            int val;
            scanf("%d",&val);
            vec2.push_back(val);
        }

        double minVal = 1000000000.0;
        double maxVal = -1000000000.0;
        for(int i = 0; i < len; i++){
            minVal = min(minVal,(vec1.at(i)-vec2.at(i))*1.0);
            maxVal = max(maxVal,(vec1.at(i)+vec2.at(i))*1.0);
        }

        printf("%f \n",(maxVal + minVal)/2.0);
    }
    return 0;
}