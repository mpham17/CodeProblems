#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    string s;
    while(t-- > 0){
        unordered_map<string, int> map;
        cin >> s;
        if(!map.contains(s)){
            map[s] = 0;
            cout << "OK" << endl;
        }
        else{
            map[s] += 1;
            cout << s<<map[s] << endl;
        }
    }
    return 0;
}