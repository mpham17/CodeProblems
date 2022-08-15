#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t-- > 0){
        int n;
        cin >> n;
        map<int, int> mp;
        for(int i=1;i<=n;++i) {
            int x;
            cin >> x;
            ++mp[x];
        }
        int single = 0, doble = 0;
        for(auto &[i, j]:mp) {
            single += j == 1;
            doble += j > 1;
        }
        cout << doble + (single + 1) / 2 << "\n";
    }
    return 0;
}