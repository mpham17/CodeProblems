#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t-- > 0){
        int len, k;
        cin >> len >> k;
        string s;
        cin >> s;
        int ones = 0, first, last;
        first = -1;
      //  printf("ones is %d",ones);
        for(int i = 0; i < len ; i++){
            if(s.at(i) == '1'){
                if(first == -1){
                    first = i;
                }
                last = i;
            //    printf("ones is %d \n",ones);
                ones += 1;
           //     printf("ones is %d \n",ones);
            }
        }
        int add = 0;
      //  printf("ones is %d \n",ones);
        if(ones >= 1 && k >= (len - 1 - last)){
            ones -= 1;
            add += 1;
            k -= len - 1 - last;
        }
        if(ones >= 1 && k >= first){
            ones -= 1;
            add += 10;
        }
      //  printf("ones is %d \n",ones);
      //  printf("value is %d \n",11 * ones + add);
        cout << 11 * ones + add << "\n";
    }
    return 0;
}