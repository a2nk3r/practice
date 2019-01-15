#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* newNode(int x){
    Node* new_node = new Node();
    new_node->data = x;
    new_node->next = NULL;
    return new_node;
}
void printList(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
Node* swapNodes(Node *head){
    if(!head || !(head->next))
        return head;
    Node *past, *present, *future;
    past = head;
    present = head->next;
    head = present;
    while(true){
        future = present->next;
        present->next = past;
        if(!future || !(future->next)){
            past->next = future;
            return head;
        }

        past->next = future->next;

        past = future;
        present = past->next;
    }
    return head;
}
int main(){
    Node* head = NULL;
    int n, x, k;
    cin >> n;
    Node *prev;
    for(int i = 1;i <= n;i++){
        // cin >> x;
        if(!head){
            head = newNode(i);
            prev = head;
        }
        else{
            prev->next = newNode(i);
            prev = prev->next;
        } 
    }
    printList(head);
    head = swapNodes(head);
    printList(head);
}