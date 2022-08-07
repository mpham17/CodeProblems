#include <bits/stdc++.h>


using namespace std;
#define sz(v) (int)sizeof(v)/sizeof(v[0]);

int change(int a){
    if(a == 0){
        return 0;
    }
    return change(a-1);
}

int main(){
    int val = 9;
    cout << change(val) << endl;
    cout << val;
} 