// circular linked list
#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* createNode(int x){
    Node* node = new Node();
    node->data = x;
    node->next = node;
    return node;
}
Node* insertAtEnd(Node* head, int x){
    Node* new_node = createNode(x);
    if(!head) return new_node;
    new_node->next = head;
    Node* temp = head;
    while(temp->next != head)
        temp = temp->next;
    temp->next = new_node;
    return head;
}
void deleteNode(Node** head, Node* p){
    Node* temp = p->next;
    if(*head == p || p->next == *head){
        p->data = temp->data;
        p->next = temp->next;
        *head = p;
        delete temp;
        return;
    }
    p->data = temp->data;
    p->next = temp->next;
    delete temp;
}
void printList(Node* head){
    Node* temp = head;
    Node* temp2 = NULL;
    while(temp != temp2){
        temp2 = head;
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    int t, n, m, o;
    cin >> t;
    while(t--){
        cin >> n >> m >> o;
        Node* head = NULL;
        for(int i = 1;i <= n;i++)
            head = insertAtEnd(head, i);
        Node* curr = head;
        for(int i = 1;i < m;i++)
            curr = curr->next;
        printList(head);
        Node* temp1 = curr;
        Node* temp2 = curr;
        while(temp1->next != temp1){
            int count = 0;
            while(count != o){
                temp2 = temp1;
                temp1 = temp1->next;
                count++;
            }
            temp2->next = temp1->next;
            temp1 = temp2->next;
            printList(head);
        }
        // do{
        //     for(int i = 1;i < o;i++)
        //         curr = curr->next;
        //     deleteNode(&head, curr);
        //     printList(head);
        // }while(head->next != head);
        cout << temp1->data << endl;
        
    }
    
}