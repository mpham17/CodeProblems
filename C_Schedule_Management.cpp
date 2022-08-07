#include <bits/stdc++.h>
using namespace std;

bool solve(long long arr[], long long val, int size){
    long long left = 0;
   // printf("check val %ld \n",val);
    for(int i = 0; i < size; i++){
        if(arr[i] > val){
      //      printf("add val %d \n",i);
            left += arr[i] - val;
        }
    }

    for(int i = 0; i < size; i++){
        if(arr[i] < val){
   //         printf("resolve val %d \n",i);
            long long dis = val - arr[i];
            left -= dis/2;
        }
    }
  //  printf("left is %ld",left);
    return left <= 0l;
}

int main(){
    int t;
    cin >> t;
    while(t-- > 0){
        int man,taskLen;
        cin >> man;
        cin >> taskLen;
        long long arr[man] = {};
        long long minVal = 1l;
        long long maxVal = 0l;
        for(int i = 0; i < taskLen; i++){
            int num;
            cin >> num;
            arr[num-1] += 1;
            maxVal = max(maxVal,arr[num-1]);
        }
        //cout << maxVal << endl;
        while(minVal < maxVal){
            long long mid = minVal + (maxVal - minVal)/2;
            if(minVal + 1 == maxVal){
                if(solve(arr,minVal,man)){
                    break;
                }
                minVal = maxVal;
                break;
            }
            if(solve(arr,mid,man)){
                maxVal = mid;
            }
            else{
                minVal = mid + 1;
            }
        }
      //  cout << solve(arr,2l,man);
        cout << minVal << endl;
    }
    return 0;
}