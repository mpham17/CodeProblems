#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t-- > 0){
        int len;
        scanf("%d",&len);
        map<long long,int> m;
        long long total = 0l;
        stack<long long> st;
        for(int i = 0; i < len; i++){
            long long val;
            scanf("%ld",&val);
            m[val] += 1;
            total += (long long)val;
        }
        bool complete = true;
        st.push(total);
        while(st.size() > 0){
            long long temp = st.top();
            st.pop();
            if(m[temp] > 0){
                m[temp] -= 1;
            }
            else{
                long long val1 = temp/2;
                long long val2 = (temp + 1l)/2l;
                if(m[val2] > 0){
                    m[val2] -= 1;
                }
                else{
                    st.push(val2);
                }

                if(m[val1] > 0){
                    m[val1] -= 1;
                }
                else{
                    st.push(val1);
                }                
            }
            if(st.size() > len){
                complete = false;
                break;
            }
        }
        if(complete){
            printf("YES \n");
        }
        else{
            printf("NO \n");
        }
    }
    return 0;
}