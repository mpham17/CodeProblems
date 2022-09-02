#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        Node *next[26];
        Node(){
            for(int i = 0; i < 26; i++){
                this->next[i] = nullptr;
            }
        }
};

int main(){
    Node* head = new Node();
    for(Node* k : head->next){
        cout << k->next << endl;
    }
    return 0;
} 