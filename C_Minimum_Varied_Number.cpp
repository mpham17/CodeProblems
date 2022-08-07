#include <iostream>
#include<vector>
using namespace std;

string ss;
bool checked = false;
int pos, len, minVal, cur,target;
vector<string> l;


void solve(){
    if(checked){
        return;
    }
    // cout << ss << endl;
    if(minVal > 9){
        return;
    }
    if(pos + 1 == len){
        int left = target - cur;
        if(left <= 9){
            ss.append(to_string(left));
            string k = ss;
            l.push_back(k);
            checked = true;
        }
        return;
    }
    int pre = minVal;
    for(int i = minVal; i <= 9; i++){
        if(cur + i <= target){
            ss.append(to_string(i));
            minVal = i+1;
            cur += i;
            pos += 1;
            solve();
            if(checked){
                return;
            }
            cur -= i;
            pos -= 1;
            ss = ss.substr(0,ss.length()-1);
        }
    }
    minVal = pre;

}

int main(){
    int tests,num;
    cin >> tests;
    for(int i = 0; i < tests;i++){
        cin >> num;
        for(len = 1;len <= 9; len++){
            pos = 0;
            minVal = 1;
            cur = 0;
            target = num;
            solve();
            if(checked){
                break;
            }            
        }
        checked = false;
        ss = "";
    }
    for(string k : l){
        cout << k << endl;
    }
    return 0;
}

