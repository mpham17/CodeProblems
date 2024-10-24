#include <bits/stdc++.h>
using namespace std;

struct Compare {
    bool operator()(vector<int>& a, vector<int>& b) {
        return a[0] < b[0]; // Min-heap based on age
    }
};


bool compare(vector<int>& v1, vector<int>& v2, int n){
    for(int i = 0; i < n; i++){
        if(v1[i] != v2[i]){
            return false;
        }
    }
    return true;
}

bool compare(vector<vector<int>>& v1, vector<vector<int>>& v2, int n, int m){
    vector<vector<int>> temp1;
    vector<vector<int>> temp2;
    vector<vector<int>> temp3;
    vector<vector<int>> temp4;

    for(int i = 0; i < n; i++){
        vector<int> temp;
        for(int j = 0; j < m; j++){
            temp.push_back(v1[i][j]);
        }
        sort(temp.begin(), temp.end());
        temp1.push_back(temp);
    }

    for(int i = 0; i < n; i++){
        vector<int> temp;
        for(int j = 0; j < m; j++){
            temp.push_back(v2[i][j]);
        }
        sort(temp.begin(), temp.end());
        temp2.push_back(temp);
    }

    sort(temp1.begin(), temp1.end(), [](vector<int>& a, vector<int>& b){return a[0] < b[0];});
    sort(temp2.begin(), temp2.end(), [](vector<int>& a, vector<int>& b){return a[0] < b[0];});
    for(int i = 0; i < n; i++){
        if(!compare(temp1[i], temp2[i], m)){
            return false;
        }
    }

    for(int i = 0; i < m; i++){
        vector<int> temp;
        for(int j = 0; j < n; j++){
            temp.push_back(v1[j][i]);
        }
        sort(temp.begin(), temp.end());
        temp3.push_back(temp);
    }

    for(int i = 0; i < m; i++){
        vector<int> temp;
        for(int j = 0; j < n; j++){
            temp.push_back(v2[j][i]);
        }
        sort(temp.begin(), temp.end());
        temp4.push_back(temp);
    }

    sort(temp3.begin(), temp1.end(), [](vector<int>& a, vector<int>& b){return a[0] < b[0];});
    sort(temp4.begin(), temp2.end(), [](vector<int>& a, vector<int>& b){return a[0] < b[0];});

    for(int i = 0; i < m; i++){
        if(!compare(temp1[i], temp2[i], n)){
            return false;
        }
    }
    return true;
}



int main(){
    int t;
    scanf("%d",&t);
    int n, m;
    while(t-- > 0){
        cin >> n >> m;
        vector<vector<int>> vec1;
        vector<vector<int>> vec2;
        for(int i = 0; i < n; i++){
            vector<int> temp;
            vec1.push_back(temp);
            for(int j = 0; j < m; j++){
                int k;
                cin >> k;
                temp.push_back(k);
            }
        }

        for(int i = 0; i < n; i++){
            vector<int> temp;
            vec2.push_back(temp);
            for(int j = 0; j < m; j++){
                int k;
                cin >> k;
                temp.push_back(k);
            }
        }
        
        if(compare(vec1,vec2,n,m)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }


    }
    return 0;
}