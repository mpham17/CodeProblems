#include <bits/stdc++.h>
using namespace std;

int get(vector<int>& arr, int pos){
    
    int res = 0;
    pos += 1;
    // for(int i = 0; i < arr.size(); i++){
    //     printf("%d ",arr.at(i));      
    // }
    // printf("pos is %d %d \n",pos,arr.at(pos));
    while(pos > 0){
        res += arr.at(pos);
        pos = pos - (pos & -pos);
    }
  //  printf("res is %d \n",res,pos);
    return res;
}

void update(vector<int>& arr, int pos,int val){
    pos += 1;
    while(pos < arr.size()){
        arr.at(pos) += val;
        pos = pos + (pos & -pos);
    }
    // for(int i = 0; i < arr.size(); i++){
    //     printf("%d ",arr.at(i));
        
    // }
    //cout << "\n" << endl;
}

int main(){
    int size,t;
    scanf("%d %d",&size,&t);
    vector<int> arr1;
    vector<int> arr2;
    map<int,int> tempMap1;
    map<int,int> tempMap2;
    for(int i = 0; i <= size; i++){
        arr1.push_back(0);
        arr2.push_back(0);
    }
    while(t-- > 0){
        int type;
        cin >> type;
        if(type == 1){
            int row,col;
            scanf("%d %d",&row,&col);
            row -= 1;
            col -= 1;
            if(tempMap1[row] == 0){
                tempMap1[row] += 1;
                update(arr1,row,1);
            }
            else{
                tempMap1[row]+= 1;
            }
            
            if(tempMap2[col] == 0){
                tempMap2[col] += 1;
                update(arr2,col,1);
            }
            else{
                tempMap2[col]+= 1;
            }
        }
        else if(type == 2){
            int row,col;
            scanf("%d %d",&row,&col);
            row -= 1;
            col -= 1;
            tempMap1[row] -= 1;
            if(tempMap1[row] == 0){
                update(arr1,row,-1);
            }
            tempMap2[col] -= 1;
            if(tempMap2[col] == 0){
                update(arr2,col,-1);
            }    
        }
        else{
            int row1,col1,row2,col2;
            scanf("%d %d %d %d",&row1,&col1,&row2,&col2);
            row1 -= 1;
            col1 -= 1;
            row2 -= 1;
            col2 -= 1;
            int res1 = get(arr1,row2) - get(arr1,row1-1);
            int res2 = get(arr2,col2) - get(arr2,col1-1);
            int target1 = row2 - row1 + 1;
            int target2 = col2 - col1 + 1;
            if(res1 == target1 || res2 == target2){
                printf("Yes \n");
            }
            else{
                printf("No \n");
            }
        }
        // for(int i = 0; i < arr1.size(); i++){
        //     printf("%d ",arr1.at(i));      
        // }
        // for(int i = 0; i < arr1.size(); i++){
        //     printf("%d ",arr1.at(i));      
        // }
    }
    return 0;
}



