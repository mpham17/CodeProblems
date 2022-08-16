#include <bits/stdc++.h>
using namespace std;
vector<int> parent;

int find(int pos){
 //   cout << "In the loop" << endl;
    if(parent.at(pos) != pos){
        parent.at(pos) = find(parent.at(pos));
    }
    return parent.at(pos);
}

int main(){
    int t;
    scanf("%d",&t);
    while(t-- > 0){
        parent.clear();
        int len;
        scanf("%d", &len);
        vector<int> vec1;
        vector<int> vec2;
        for(int i = 0; i <= len; i++){
            parent.push_back(i);
        }
        for(int i = 0; i < len; i++){
            int val1;
            scanf("%d", &val1);
            vec1.push_back(val1);
        }
    //    cout << "It good at here 1" << endl;
        for(int i = 0; i < len; i++){
            int val1;
            scanf("%d", &val1);
            vec2.push_back(val1);
        }
    //    cout << "It good at here 2" << endl;
        for(int i = 0; i < len; i++){
            int p1 = find(vec1.at(i));
            int p2 = find(vec2.at(i));
            parent.at(p1) = p2;
     //       printf("In the take %d",i);
        }
     //   cout << "It good at here 3" << endl;
        set<int> dif;
        for(int i = 1; i <= len; i++){
            dif.insert(find(i));
       //     printf("find %d %d",i,find(i));
        }

        for(int i = 0; i < len; i++){
            int val1;
            scanf("%d", &val1);
            if(val1 != 0){
                int p = find(val1);
                if(dif.find(p) != dif.end()){
                    dif.erase(p);
                }
            }
            else if(vec1.at(i) == vec2.at(i)){
                dif.erase(vec1.at(i));
            }
        }
        
        int left = dif.size();
        long long mod = 1000000007l;
        long long temp = 1l;
        for(int i = 0; i < left; i++){
            temp = (temp * 2l) %mod;
        }

        printf("%ld \n",temp);
    }

    return 0;
}