#include <bits/stdc++.h>
using namespace std;

bool check(int nums[], int size){
    int first = nums[0];
    for(int i = 0; i < size;i++){
        if(first != nums[i]){
           //  cout << nums[i] ;
            return false;
        }
    }
    return true;
}

int main(){
    int t,size,temp;
    cin >> t;
    while(t-- > 0){
        cin >> size;
        int nums[size] = {};
        for(int i = 0; i < size; i++){
            cin >> temp;
            nums[i] = temp;
        }
        bool temp = true;
        while(temp){
            temp = false;
            for(int i = 0; i < size; i++){
                int mod = nums[i] % 10;
                if(mod == 0 || mod == 2){
                    continue;
                }
                else{
                    nums[i] += mod;
                    // printf("%d  %d",nums[i],mod);
                    temp = true;
                }
            }
        }
        int initial = nums[0] % 20;
        if(nums[0] % 10 == 0){
            if(check(nums,size)){
                cout << "Yes" << endl;
            }
            else{
                cout << "No" <<  endl;
            }
            continue;
        }
        bool completed = false;
        // for(int k : nums){
        //     printf("%d ",k);

        // }
        for(int i = 1; i < size; i++){
            if(nums[i] % 20 != initial){
                cout << "No" << endl;
                completed = true;
                break;
            }
        }
        if(!completed){
            cout << "Yes" << endl;
        }     
    }
    return 0;
}