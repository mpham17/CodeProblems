#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[26] = {};
    string s;
    int t;
    cin >> t;
    int val;
    int total;
    while(t > 0){
        cin >> s;
        cin >> val;
        arr[26] = {};
        total = 0;
        for(int i = 0; i < s.length(); i++){
         //   printf("%d",s.at(i) - 'a');
            arr[s.at(i) - 'a'] += 1;
            total = total + (int)(s.at(i) - 'a') + 1;
        }
     //   printf("%d",total);
        
        int index = 25;
        while(total > val){
            if(arr[index] > 0){
                arr[index] -= 1;
                total -= index + 1;
            }
            else{
                index -= 1;
            }
        }
     //   cout << total << endl;
        string a;
        for(int i = 0; i < s.length(); i++){
            if(arr[s.at(i) - 'a'] > 0){
                a += s.at(i);
                arr[s.at(i) - 'a'] -= 1;
            }
        }
        cout << a << endl;
        t--;
    }
    return 0;
}