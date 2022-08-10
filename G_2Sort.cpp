#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t-- > 0){
        int len, k;
        cin >> len >> k;
        int arr[len];
        for(int i = 0; i < len; i++){
            cin >> arr[i]; 
        }
        int res = 0;
        for(int i = 0; i < len - 1; i++){
            if(arr[i+1] *2 > arr[i]){
                int start = i;
                int pos = i+1;
                while(pos+1 < len){
                    if(arr[pos+1] * 2 > arr[pos]){
                        pos += 1;
                    }
                    else{
                        break;
                    }
                }
                int len = pos - start + 1;
                res += max(0,len - k);
                i = pos;
            }
        }
        cout << res << endl;
    }
    return 0;
}