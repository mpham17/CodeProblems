#include <bits/stdc++.h>
using namespace std;


int get(vector<vector<int>>& vec, int row,int col){
    int res = 0;
    if(row  < vec.size() && col < vec.at(row).size() && vec.at(row).at(col) == 1){
        res += 1;
    }

    if(row+1  < vec.size() && col < vec.at(row+1).size() && vec.at(row+1).at(col) == 1){
        res += 1;
    }

    if(row  < vec.size() && col + 1 < vec.at(row).size() && vec.at(row).at(col+1) == 1){
        res += 1;
    }

    if(row + 1  < vec.size() && col + 1 < vec.at(row+1).size() && vec.at(row+1).at(col+1) == 1){
        res += 1;
    }

    return res;
}


int main(){
    int t;
    scanf("%d",&t);
    while(t-- > 0){
        int row, col;
        scanf("%d %d",&row,&col);
        string s;
        int count = 0;
        vector<vector<int>> vec;
        for(int i = 0; i < row; i++){
            cin >> s;
            vec.push_back({});
            for(int j = 0; j < col; j++){
                int val = s.at(j) - '0';
                vec.at(i).push_back(val);
                if(vec.at(i).at(j) == 1){
                    count += 1;
                }
            }
        }

        bool condition = false;
        int tempVal = 0;
        for(int i = 0; i < row-1; i++){
            for(int j = 0; j < col-1; j++){
                int val = get(vec,i,j);
                if(val <= 2 && val > 0){
                    condition = true;
                }
                else if(val > 0 && (tempVal == 0 || val < tempVal)){
                    tempVal = val;
                }
            }
        }
        if(condition){
            printf("%d \n",count);
        }
        else{
            if(tempVal == 4){
                count -= 2;
            }
            else {
                count -=1;
            }
            if(count < 0){
                count = 0;
            }
            printf("%d \n",count);
        }
        
    }
    return 0;
}