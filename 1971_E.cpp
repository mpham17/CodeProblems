#include <bits/stdc++.h>
using namespace std;

int findPos(vector<long long>& dis, long long pos){
    int l = 0, r = dis.size()-1;
        while(l <= r)
        {
            int mid = l+r>>1;
            if(dis[mid] > pos)
            {
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
   // cout << start << endl;
    return r;
}

int main(){
    int t;
    scanf("%d",&t);
    int n,k,q;
    while(t-- > 0){
        cin >> n;
        cin >> k;
        cin >> q;
        vector<long long> dis(k+1);
        vector<long long> time(k+1);
        for(int i = 1; i <= k; i++){
            long long p;
            cin >> p;
            dis[i] = p;
        }
        for(int i = 1; i <= k; i++){
            long long p;
            cin >> p;
            time[i] = p;
        }
        
        
        for(int i = 0; i < q; i++){
            long long pos;
            cin >> pos;
            int temp = findPos(dis, pos);
          //  cout << temp << endl;
            if(temp == dis.size() - 1){
                cout << time[temp] << " ";
            }
            else{
                cout << (time[temp+1] - time[temp]) * (pos - dis[temp])/(dis[temp+1] - dis[temp]) + time[temp] ) << " ";
            }
        }
        cout << endl;

    }
    return 0;
}