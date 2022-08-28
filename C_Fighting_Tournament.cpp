#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t-- > 0){
        int len,q;
        scanf("%d %d",&len,&q);
        deque<vector<int>> qu;
        map<int,int> m;
        int val;
        // pos power
        for(int i = 0; i < len; i++){
            scanf("%d", &val);
            m[i] = val;
            qu.push_back({i,val});
        }
        vector<int> total;
        for(int i = 0; i < len; i++){
            total.push_back(0);
        }
        // person time
        vector<vector<int>> ask;
        for(int i = 0; i < q; i++){
            int person,time;
            scanf("%d %d",&person,&time);
            ask.push_back({person-1,time,i});
        }

        sort(ask.begin(), ask.end(), 
        [](const vector<int> & a, const vector<int> & b) -> bool
        { 
            return a.at(1) < b.at(1); 
        });

        // for(vector<int> v : ask){
        //     printf("%d %d %d", v.at(0),v.at(1),v.at(2));
        // }

        int start = 0;
        int res[q];
        for(vector<int> v : ask){
            while(start < v.at(1) && qu.front().at(1) < len){
                vector<int> first = qu.front();
                qu.pop_front();
                vector<int> second = qu.front();
                qu.pop_front();
                if(first.at(1) > second.at(1)){
                    total.at(first.at(0)) += 1;
                    qu.push_front(first);
                    qu.push_back(second);
                }
                else{
                    total.at(second.at(0)) += 1;
                    qu.push_front(second);
                    qu.push_back(first);
                }
                start += 1;
            }
            if(start   < v.at(1)){
                int dif = v.at(1) - start;
                start += dif;
                total.at(qu.front().at(0)) += dif;
            }
            res[v.at(2)] = total.at(v.at(0));
        }

        for(int c : res){
            printf("%d \n",c);
        }
    }
    return 0;
}