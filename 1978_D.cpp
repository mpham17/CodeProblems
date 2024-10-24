#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    int n, c;
    while(t-- > 0){
        cin >> n >> c;
        vector<long long> v1(n);
        vector<long long> v2(n);
        for(long long& i : v1){
            cin >> i;
        }
        v1[0] += c;

        long long max = v1[n-1];
        for(int i = n-1; i >= 0; i--){
            max = std::max(v1[i], max);
            v2[i] = max;
        }

        long long cur = 0l;
        max = -1l;
        for(int i = 0; i < n; i++){
            if(v1[i] > max){
                max = v1[i];
                if(v2[i] > v1[i]){
                    long long temp = cur + v1[i];
                    if(temp >= v2[i]){
                        cout << i<< " ";
                    }
                    else{
                        cout << i+1 << " ";
                    }
                }
                else{
                        cout << 0 << " ";
                }
            }
            else{
                long long temp = cur + v1[i];
                if(temp >= v2[i]){
                    cout << i<< " ";
                }
                else{
                    cout << i+1 << " ";
                }
            }
            cur += v1[i];
        }
        cout << endl;
    }
    return 0;
}