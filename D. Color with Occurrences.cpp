#include <bits/stdc++.h>
using namespace std;
map<string,int> m;
// use dynamic programming
vector<vector<int>> travel(string str, int val){
    vector<vector<int>> res;
    int start = 0;
    vector<int> vec;
    while(val > 0){
        if(val % 2== 1){
            vec.push_back(start);
        }
        start += 1;
        val /= 2;
    }
    vec.push_back(str.length());
    bool wrong = false;
    for(int i = 0; i < vec.size() - 1; i++){
        int start = vec.at(i);
        //cout << vec.at(i) << endl;
        int len = vec.at(i+1) - vec.at(i);
        for(auto &[s, j]:m) {
            if(start + s.length() <= str.length() && s.compare(str.substr(start,s.length())) == 1){
                vector<int> temp;
                temp.push_back(j);
                temp.push_back(start);
                res.push_back(temp);
                break;
            }
        }
    }
    if(res.size() != vec.size()-1){
        res.clear();
    }
    return res;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t-- > 0){
        m.clear();
        string str;
        cin >> str;
        int len;
        cin >> len;
        for(int i = 0; i < len; i++){
            string k;
            cin >> k;
            m.insert(pair<string, int>(k, m.size()));
        }

        vector<vector<int>> res;
        for(int i = 1 ; i <= (1 << str.length())-1; i+=2){
            vector<vector<int>> tempRes = travel(str,i);
            if(tempRes.size() > 0 && (res.size() == 0 || res.size() > tempRes.size())){
          //     printf("This is %d %d \n",i,tempRes.size());
                res = tempRes;
            }
        }
        
        if(res.size() == 0){
            printf("-1 \n");
        }
        else{
            printf("%d \n",res.size());
            for(vector<int> v : res){
                printf("%d %d \n",v.at(0),v.at(1));
            }
        }

        
    }
    return 0;
}