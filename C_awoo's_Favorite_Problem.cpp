#include <bits/stdc++.h>
using namespace std;

long count(long arr[], long pos){
    long res = 0l;
    while(pos > 0l){
        res += arr[pos];
        pos -= pos & -pos;
    }
    return  res;
}

void update(long arr[], long pos, long len){
    while(pos <= len){
     //   printf("value pre  add %ld",arr[pos]);
        arr[pos] += (long)1;
     //   printf("value afeter add %ld %ld",arr[pos],pos);
        pos += pos & -pos;
    }
}

void update1(long arr[], long pos, long len){
    while(pos <= len){
    //    printf("value pre  minus %ld",arr[pos]);
        arr[pos] -= (long)1;
    //    printf("value afeter minus %ld %ld",arr[pos],pos);
        pos += pos & -pos;
    }
}

int main(){
    int t;
    cin >> t;
    while(t-- > 0){
        long len;
        cin >> len;
        string s,q;
        cin >> s;
        cin >> q;
        long arr [3][len+1];
        for(int i = 0; i < 3; i++){
            for(int j = 0; j <= len ; j++){
                arr[i][j] = 0l;
            }
        }
        queue<long> list[3];
        for(int i = 0; i < len; i++){
            long val = s.at(i) == 'a'? 0 : s.at(i) == 'b'?1 : 2;
            list[val].push(i+1);
            update(arr[val],i+1,len);
        }
      //  printf("This is len %d \n",len);
        bool success = true;
        for(int i = 0; i < len; i++){
         //   printf("%d \n",i);
            long val = q.at(i) == 'a'? 0 : q.at(i) == 'b'?1 : 2;
            if(list[val].empty()){
             //   printf("Failed at empty");
                success = false;
                break;
            }
            long firstPos = list[val].front();
            list[val].pop();
            if(val == 0){
                // printf("Go into  a \n");
                // printf("This is the b pre val %ld \n",count(arr[1],firstPos));
                // printf("This is the c pre val %ld \n",count(arr[2],firstPos));
                if(count(arr[1],firstPos) == 0l && count(arr[2],firstPos) == 0l){
                    update1(arr[0],firstPos,len);
                }
                else{

             //       printf("When into a case");
                    success = false;
                    break;
                }
            }
            else if(val == 1){
             //   printf("Go into  b \n");
              //  printf("This is the c pre val %ld \n",count(arr[2],firstPos));
                if(count(arr[2],firstPos) == 0){
                    update1(arr[1],firstPos,len);
                }
                else{
                    success = false;
                    break;
                }
            }
            else{
                // printf("Go into  c \n");
                // printf("This is the a pre val %ld \n",count(arr[0],firstPos));
                if(count(arr[0],firstPos) == 0){
                    update1(arr[2],firstPos,len);
                }
                else{
                //    printf("When into a case");
                    success = false;
                    break;
                }
            }

            // for(int i = 0; i <= len; i++){
            //     cout << arr[0][i] << endl;
            // }
            // for(int i = 0; i <= len; i++){
            //     cout << arr[1][i] << endl;
            // }
            // for(int i = 0; i <= len; i++){
            //     cout << arr[1][i] << endl;
            // }
        }
        if(success){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}