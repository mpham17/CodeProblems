#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t-- > 0){
        int size = 0;
        cin >> size;
        long long arr[size] = {};
        for(int i = 0; i < size; i++){
            cin >> arr[i];
        }
        long long newAdd[size] = {};
        long long newTotal[size] = {};
        long long res1 = 0l;
        long long res2 = 0l;
        for(int i = 1; i < size-1; i++){
            //make it a cool;
            long long pre1 = 0l;
            long long pre2 = 0l;
            if(i - 2 >= 0){
                pre1 = newAdd[i-2];
                pre2 = newTotal[i-2];
            }
            long long add = max(max(arr[i-1],arr[i+1])+1 - arr[i],0ll);
            if(pre2 + 1 > res2){
                res2 = pre2+1;
                res1 = add + pre1;
            }
            
            else if(pre2 + 1 == res2 &&  add + pre1 < res1){
                res1 = add + pre1;
            }
            
            if(newTotal[i-1] > pre2+1){
                newTotal[i] = newTotal[i-1];
                newAdd[i] = newAdd[i-1];
            }
            else if(newTotal[i-1] == pre2+1 && newAdd[i-1] < pre1+add){
                newTotal[i] = pre2+1;
                newAdd[i] = newAdd[i-1];
            }
            else{
                newTotal[i] = pre2+1;;
                newAdd[i] = pre1+add;
            }
        }
         cout << res1 << endl;
        // for(int i = 0; i < size; i++){
        //     printf("%d %d \n",newTotal[i],newAdd[i]);
        // }
    }
    return 0;
}