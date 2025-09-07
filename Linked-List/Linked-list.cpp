#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }

    static void insertAtHead(int value, Node*& head, Node* &tail){
        Node* newNode = new Node(value);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }

    static void insertAtTail(int value, Node*& head, Node*& tail){
        Node* newNode = new Node(value);
        if(tail == NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        else{
            tail->next = newNode ;
            tail = newNode;
        }
    }

    static void display(Node* head){

        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" -> ";
            temp = temp->next;
        }

    }


};

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    Node::insertAtHead(10, head, tail);
    Node::insertAtHead(20, head, tail);

    Node::insertAtTail(30, head, tail);
    Node::insertAtTail(40, head, tail);

    Node::display(head);
    
    return 0;
}
