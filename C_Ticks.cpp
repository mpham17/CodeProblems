#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t-- > 0){
        int n,m,k;
        scanf("%d %d %d",&n,&m,&k);
        vector<vector<int>> vec;
        vector<vector<int>> vec1;
        vector<vector<int>> vec2;
        int count = 0;
        for(int i = 0; i < n; i++){
            vector<int> tempV;
            vector<int> tempV1;
            vector<int> tempV2;
            string str;
            cin >> str;
            for(int j = 0; j < m; j++){
                char temp = str.at(j);
                if(temp == '*'){
                    tempV.push_back(1);
                    count += 1;
                }
                else{
                    tempV.push_back(0);
                }
                tempV1.push_back(0);
                tempV2.push_back(0);
            }
            vec.push_back(tempV);
            vec1.push_back(tempV1);
            vec2.push_back(tempV2);
        }
        set<int> a;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(vec.at(i).at(j) == 1){
                    int temp1 = 1;
                    int temp2 = 1;
                    if(i - 1 >= 0 && j - 1 >= 0){
                        temp1 += vec1.at(i-1).at(j-1);
                    }
                    if(i - 1 >= 0 && j + 1 < m){
                        temp2 += vec2.at(i-1).at(j+1);
                    }
                    vec1.at(i).at(j) = temp1;
                    vec2.at(i).at(j) = temp2;
                    int val = min(temp1,temp2);
                    if(val > k){
                        for(int e = 0; e < val; e++){
                            int row1 = i - e;
                            int col1 = j - e;
                            int col2 = j + e;
                            a.insert(row1*m+col1);
                            a.insert(row1*m+col2);
                        }
                    }
                }
            }
        }

        if(a.size() == count){
            printf("YES \n");
        }
        else{
            printf("NO \n");
        }
    }
    return 0;
}