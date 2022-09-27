#include <bits/stdc++.h>
using namespace std;

class Node
{
  public:
    int data;
    int valLeft;
    int valRight;
    Node* left;
    Node* right;
};

int travel(Node* root){
    if(root == NULL){
        return 0;
    }

    int tempLeft = travel(root->left);
    int tempRight = travel(root->right);

    root->valLeft = tempLeft;
    root->valRight = tempRight;
    return tempLeft + tempRight + 1;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t-- > 0){
        int len;
        scanf("%d", &len);
        Node* arr[300001];
        for(int i = 0; i < len; i++){
            int val1, val2;
            scanf("%d %d",&val1,&val2);
            if(arr[val1] == NULL){
                Node temp;
                temp.data = val1;
            }

            if(arr[val2] == NULL){
                Node temp;
                temp.data = val1;
            }

            if(arr[val1]->left == NULL){
                arr[val1]->left = arr[val2];
            }
            else{
                arr[val1]->right = arr[val2];
            }
        }

        travel(arr[1]);
        int res = 0;
        Node* temp = arr[1];
        while(temp != NULL){
            if(temp->valLeft > temp->valRight){
                res += temp->valLeft - 1;
                temp = temp->right;
            }
            else{
                res += temp->valRight - 1;
                temp = temp->left;
            }
        } 
        cout << res << endl;
    }
    return 0;
}