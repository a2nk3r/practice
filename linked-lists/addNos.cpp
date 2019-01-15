// same number of digits
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
Node* insertHead(Node* head, int x){
    Node* new_node = newNode(x);
    new_node->next = head;
    return new_node;
}
void printReverse(Node* head){
    if(!head)
        return;
    printReverse(head->next);
    cout << head->data << " ";
}
Node* readList(Node* head, int n){
    int x;    
    Node *prev;
    for(int i = 1;i <= n;i++){
        cin >> x;
        if(!head){
            head = newNode(x);
            prev = head;
        }
        else{
            prev->next = newNode(x);
            prev = prev->next;
        } 
    }
    return head;
}
Node* addLists(Node* num1, Node* num2){
    Node* result = NULL;
    Node* prev;
    while(num1 && num2){
        if(!result){
            result = newNode(num1->data + num2->data);
            prev = result;
        }
        else{
            prev->next = newNode(num1->data + num2->data);
            prev = prev->next;
        }
        num1 = num1->next;
        num2 = num2->next;
    }
    return result;
}
Node* addRecursively(Node* num1, Node* num2, int* carry){
    if(!num1 || !num2)
        return 0;
    int sum = 0;
    Node* result = new Node();
    result->next = addRecursively(num1->next, num2->next, carry);
    sum = num1->data + num2->data + *carry;
    *carry = sum/10;
    sum = sum % 10;
    result->data = sum;
    return result;
}
Node* addListsC(Node* num1, Node* num2){
    
}
Node* reverseList(Node *head){
    Node *past, *present, *future;
    present = head;
    past = NULL;
    while(present != NULL){
        future = present->next;
        present->next = past;
        past = present;
        present = future;
    }
    return past;
}
int main(){
    Node* num1 = NULL;
    Node* num2 = NULL;
    Node* result = NULL;
    int n;
    cin >> n;
    num1 = readList(num1, n);
    num2 = readList(num2, n);
    int carry = 0;
    result = addRecursively(num1, num2, &carry);
    printList(result);
}