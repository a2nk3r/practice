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
Node* reverseAltK(Node* head, int k){
    Node* oldHead = head;
    Node *past, *present, *future;
    present = head;
    past = NULL;
    int count = k;
    while(present != NULL && count--){
        future = present->next;
        present->next = past;
        past = present;
        present = future;        
    }
    oldHead->next = present;
    count = k;
    count--;
    while(count-- && present != NULL) present = present->next;
    if(present) present->next = reverseAltK(present->next, k);
    return past;
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
    cin >> k;
    head = reverseAltK(head, k);
    printList(head);
}