#include <bits/stdc++.h>
using namespace std;

class Node {
    public: 
    long long val1,val2;
    void set_values(long long a, long long b){
        val1 = a;
        val2 = b;
    }

    void toString(){
        printf("(%ld %ld) \n",val1,val2);
    }
};

deque<Node> change(long arr1[], long size1, long m){
    deque<Node> dq;
    for(long i = 0; i < size1; i++){
        Node next;
        long long temp1 = arr1[i];
        long long temp2 = 1l;
        while(temp1 % m == 0l){
            temp2 *= m;
            temp1 /= m;
        }
        next.set_values(temp1,temp2);
        //   next.toString();
        if(dq.size() > 0 && dq.back().val1 == next.val1){
        //    printf("This is back %ld %ld %ld", dq.back().val1,next.val2,dq.back().val2);
            dq.back().val2 += next.val2;
        }
        else{
            dq.push_back(next);
        }
    }
    return dq;
}

deque<Node> change2(long arr1[], long size1, long m){
    deque<Node> dq;
    for(long i = 0; i < size1; i++){
        Node next;
        long long temp1 = arr1[i];
        long long temp2 = 1l;
        while(temp1 % m == 0l){
            temp2 *= m;
            temp1 /= m;
        }
        next.set_values(temp1,temp2);
        //   next.toString();

        dq.push_back(next);
        
    }
    return dq;
}

int main(){
    int t;
    cin >> t;
    while(t-- > 0){
        long size1,size2,m;
        cin >> size1;
        cin >> m;
        long arr1[size1];
      //  long minVal = 1000000009;
        for(long i = 0; i < size1; i++){
            cin >> arr1[i]; 
        //    minVal = min(minVal,arr1[i]); 
        }
        cin >> size2;
        long arr2[size2];
        for(long i = 0; i < size2; i++){
            cin >> arr2[i];
        }
        
        long index = 0l;
        
        
        // for(Node n : dq){
        //     n.toString();
        // }
        bool che = true;
        deque<Node> dq1 = change(arr1,size1,m);
        deque<Node> dq2 = change2(arr2,size2,m);

        while(dq1.size() > 0 && dq2.size() > 0){
            if(dq1.front().val1 != dq2.front().val1 || dq1.front().val2 < dq2.front().val2){
                break;
            }
            else{
                dq1.front().val2 -= dq2.front().val2;
                if(dq1.front().val2 == 0l){
                    dq1.pop_front();
                }
                dq2.pop_front();
            }
        }
        

        if(dq1.size() == 0 && dq2.size() == 0){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }

     //   cout << minVal << endl;
    }
    return 0;
}