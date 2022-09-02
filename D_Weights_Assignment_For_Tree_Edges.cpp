#include <bits/stdc++.h>
using namespace std;

class Node{
    public:  
        vector<Node> next;
        int val;
        int point;
        void toString(){
            printf("%d \n",val);
        }
};
vector<Node> tree;
bool travel(int pos, vector<int>& result){
    Node root = tree.at(pos);
    for(Node d : root.next){
        if(tree.at(d.val-1).point <= tree.at(root.val - 1).point){
          //  printf("val wrong is %d %d",d.val,root.val);
            return false;
        }
        bool temp = travel(d.val-1,result);
        if(!temp){
            return false;
        }
        
        result.at(d.val-1) =- (tree.at(root.val-1).point - tree.at(d.val-1).point);
    }
    return true;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t-- > 0){
        tree.clear();
        int len;
        scanf("%d",&len);
        vector<int> list;
        vector<int> result;
        for(int i = 1; i <= len; i++){
            Node temp;
            temp.val = i;
            temp.point = -1;
            tree.push_back(temp);
            result.push_back(0);
         //   printf("Val is %d \n",tree.at(i-1).val);
        }
        // for(int i = 0; i < len; i++){
        //     printf("Val is %d \n",tree.at(i).val);
        // }
        Node* head = NULL;
        bool bad = false;
        for(int i = 1; i <= len; i++){
            int val;
            scanf("%d",&val);
            if(val == i){
                if(head != NULL){
                    bad = true;
                    break;
                }
              //  printf("Head is %d \n",i);
                head = &tree.at(i-1);
                continue;
              //  printf("Head is %d \n",head->val);
            }
            tree.at(val-1).next.push_back(tree.at(i-1));
        }
        if(bad || head == NULL){
          //  cout << "head is null" << endl;
            printf("-1 \n");
            continue;
        }
        
        for(int i = 0; i < len; i++){
            int val;
            scanf("%d",&val);
            tree.at(val-1).point = i;
        }
        
        if(head->point != 0){
          //  cout << "head is not 0" << endl;
            printf("-1 \n");
            continue;
        }

        bool res = travel(head->val-1,result);
        if(!res){
         //   cout << "wrong tree" << endl;
            printf("-1 \n");
            continue;
        }
        else{
            for(int i = 0; i < len; i++){
                printf("%d ",result.at(i));
            }
            printf("\n");
        }



    }
    return 0;
}