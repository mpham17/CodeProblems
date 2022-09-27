#include <bits/stdc++.h>
using namespace std;

int parent[200001];
int arr[200001];
int find(int x){
    if(parent[x] != x){
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

int main(){
    int t;
    scanf("%d",&t);
    while(t-- > 0){
        int len;
        scanf("%d",&len);
        for(int i = 0; i < 200001; i++){
            parent[i] = i;
            arr[i] = 0;
        }
        
        vector<vector<int>> list;
        bool wrong = false;
        for(int i = 0; i < len; i++){
            int val1,val2;
            scanf("%d %d",&val1,&val2);
            vector<int> vec;
            vec.push_back(val1);
            vec.push_back(val2);
            list.push_back(vec);
            arr[val1] += 1;
            arr[val2] += 1;
            if(val1 == val2){
                wrong = true;
            }
            if(arr[val1] > 2){
                wrong = true;
            }
            
            if(arr[val2] > 2){
                wrong = true;
            }
        }
        if(wrong){
            cout << "No" << endl;
            continue;
        }

        
        for(vector<int> c : list){
            int p1 = find(c.at(0));
            int p2 = find(c.at(1));
            parent[p1] = p2;
        }
        map<int,int> m;
        for(vector<int> c : list){
            int p1 = find(c.at(0));
            m[p1] += 1;
        }

        for(auto c : m){
            if(c.second % 2 != 0 && c.second > 1){
                wrong = true;
                break;
            }
        }

        if(wrong){
            cout << "No" << endl;
        }
        else{
            cout << "Yes" << endl;
        }

    }
    return 0;
}