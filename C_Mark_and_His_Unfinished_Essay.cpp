#include <bits/stdc++.h>
using namespace std;

long long find(long long pos,long long arr[], long long len){
    for(int i = 0; i <= len; i++){
        if(arr[i] >= pos){
            return i;
        }
    }
    return -1;
}

long long solve(long long pos, long long arr[],long long add[][2], long long len){
    long long next = find(pos,arr,len);
  //  printf("this is next %d \n",next);
    while(next > 0){
        long long dis = pos - arr[next-1];
        pos = add[next][0] + dis-1;
        next = find(pos,arr,len);
    }
  //  printf("this is pos %d \n", pos-1);
    return pos - 1;
}



int main(){
    int t;
    cin >> t;
    while(t-- > 0){
        long long l,c,q;
        string s = "";
        cin >> l;
        cin >> c;
        cin >> q;
        cin >> s;
        long long arr[c+1];
        long long add[c+1][2];
        arr[0] = l;
        for(int i = 1; i <= c; i++){
            cin >> add[i][0];
            cin >> add[i][1]; 
            arr[i] = arr[i-1] + (add[i][1] - add[i][0]+1);
        }

        for(int i = 0; i < q; i++){
            long long pos;
            cin >> pos;
          //  printf("this is pos when input %d \n", pos-1);
            cout << s.at(solve(pos,arr,add,c)) << endl;
        }
    }
    return 0;
}