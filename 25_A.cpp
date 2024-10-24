#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    int arr[t];
    int a;
    int pos = 0;
    int count1 = 0;
    int count2 = 0;
    while(t-- > 0){
        cin >> a;
        arr[pos++] = a;
        if(a % 2 == 1){
            count1 += 1;
        }
        else{
            count2 += 1;
        }
    }
    pos = 1;
    if(count2 > count1){
        for(int c : arr){
            if(c % 2 == 1){
                cout << pos << endl;
                break;
            }
            pos++;
        }
    }
    else{
        for(int c : arr){
            if(c % 2 == 0){
                cout << pos << endl;
                break;
            }
            pos++;
        }
    }

    return 0;
}