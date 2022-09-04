#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t-- > 0){
        string str;
        cin >> str;
        int len;
        scanf("%d",&len);
        map<string,int> s;
        for(int i = 0; i < len; i++){
            string k;
            cin >> k;
            s.insert({k,i+1});
        }
        vector<int> vec1;
        vector<int> vec2;
        vector<int> vec3;
        vec1.push_back(-1);
        vec2.push_back(10000);
        vec3.push_back(-1);
        for(int i = 0; i < str.length(); i++){
            vec1.push_back(-1);
            vec2.push_back(0);
            vec2.push_back(-1);
        }
        for(int i = 0; i < str.length(); i++){
            int val = 10000;
            for(int j = 0; i - j >= 0 && j <= 9; j++){
                string k = str.substr(i-j,j+1);
                if(s.count(k)){
                    int pre = i - j;
                    if(pre == 0){
                        val = 1;
                        vec1.at(i+1) = 0;
                        vec3.at(i+1) = s.at(k);
                        break;
                    }
                    else if(vec2.at(pre) > 0){
                        if(vec2.at(pre) + 1 < val){
                            val = vec2.at(pre)+1;
                            vec1.at(i+1) = pre;
                            vec3.at(i+1) = s.at(k);
                        }
                    }
                }
            }
            vec2.at(i+1) = val;
            for(int j = i;j > vec1.at(i+1); j--){
                if(vec2.at(j) > vec2.at(i+1)){
                    vec2.at(j) = vec2.at(i+1);
                    vec1.at(j) = vec1.at(i+1);
                    vec3.at(j) = vec3.at(i+1);
                }
            }
        }
        
        // cout << vec1.size() << endl;
        // for(int i = 0; i < vec1.size(); i++){
        //     printf("%d ",vec1.at(i));
        // }
        // cout << ""<<endl;
        
        if(vec1.at(str.length()) == -1){
            printf("%d \n",-1);
        }
        else{
            printf("%d \n",vec2.at(str.length()));
            vector<string> res;
            int cur = str.length();
            while(cur > 0){
               // cout << cur << endl;
                // cout << s.at(str.substr(vec1.at(cur),cur - vec1.at(cur))) << endl;
                string a = to_string(vec3.at(cur));
                string b = to_string(vec1.at(cur)+1);
                string m = a +" "+b;
                res.push_back(m);
                cur = vec1.at(cur);
            }
            for(int i = res.size()-1; i >= 0 ; i--){
                printf("%s \n",res.at(i));
            }
        }
        
    }
    return 0;
}