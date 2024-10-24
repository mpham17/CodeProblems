#include <bits/stdc++.h>
using namespace std;

// Custom comparator: Compare by age
struct Compare {
    bool operator()(vector<long long>& a, vector<long long>& b) {
        return a[1] > b[1]; // Min-heap based on age
    }
};

int main(){
    int t;
    scanf("%d",&t);
    int h,a;
    while(t-- > 0){
        cin >> h;
        cin >> a;
        int dame[a];
        int cool[a];
        for(int i = 0; i < a; i++){
            int k;
            cin >> k;
            dame[i] = k;
        }    
        for(int i = 0; i < a; i++){
            int k;
            cin >> k;
            cool[i] = k;
        }  
        priority_queue<vector<long long>, vector<vector<long long>>, Compare> pq;  
        for(int i = 0; i < a; i++){
            pq.push({dame[i],1,cool[i]});
        }  
        long long count = 1ll;
     //   cout << pq.top()[0] << endl;
        while(h > 0){                    
            while(pq.top()[1] <= count && h > 0){               
                vector<long long> temp = pq.top();
                h-= temp[0];
                temp[1] += temp[2];
                pq.pop();
                pq.push(temp);
            //    cout << temp[1] << endl;
            }
            if(h <= 0){
                break;
            }
            count = max(count+1, pq.top()[1]);
        }
        cout << count<< endl;
    }
    return 0;
}