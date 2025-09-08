#include <iostream>
using namespace std ;

class Node{
    public:
    int data ;
    Node* next ;

    Node(int value){
        data = value ;
        next = NULL ;
    }

};

void insertHead(int value, Node* &head, Node* &tail){
    Node* newnode = new Node(value);
    if(head == NULL){
        head = newnode ;
        tail = newnode ;
    }
    else{
        Node* newnode = new Node(value) ;
        newnode->next = head ;
        head = newnode ;
    }
}

void display(Node* head){
    Node* temp = head ;
    while (temp != NULL){
        cout << temp->data;
        if(temp->next) cout<<"->";
        temp = temp->next ;
    }
}

void insertTail(int value, Node* &head, Node* &tail){
    Node* newnode = new Node(value);
    if( tail == NULL){
        head = newnode ;
        tail = newnode ;
    }
    else{
        Node* newnode = new Node(value);
        tail->next = newnode ;
        tail = newnode ;
    }
}

int getlength(Node* head){
    int length = 0 ;
    Node* temp = head ;

    while(temp != NULL){
        length++ ;
        temp = temp->next ;
    }

    return length ;
}

bool search(int target, Node* head){

    Node* temp = head ;
    while(temp != NULL){

        if(temp->data == target){
            return true ;
        }
        else{
            temp = temp->next ;
        }
    }return false ;
}

void deleteatHead(Node* &head, Node* &tail ){
    Node* temp = head ;
    if(head == tail){
        head = NULL ;
        tail = NULL ;
        delete temp ;
    }
    else{
        head = temp->next ;
        temp->next = NULL ;
        
        delete temp ;
    }
}

void deleteAtTail(Node* &head, Node* &tail){

    if(head == NULL){
        cout << "Link is empty" ;
        return ;
    }
    if(head == tail){
        delete head ;
        head = NULL ;
        tail = NULL ;
    }
    Node* temp = head ;

    while(temp->next != tail){
        temp = temp->next ;
    }
    delete tail ;
    tail = temp ;
    temp->next = NULL ;
}


void insertAtposition(int position,int value, Node* &head, Node* &tail){
    if(position == 1){
        insertHead(value,head,tail);
        return ;
    }
    int length = getlength(head);
    if(position == length+1){
        insertTail(value,head,tail);
        return ;
    }

    if(position > length+1){
        cout << "invalid Position";
    }
    else{

    Node* temp = head ;
    Node* newnode = new Node(value);
    for(int i=1; i<=position-2;i++){
        temp = temp->next ;

    }
    newnode->next = temp->next ;
    temp->next = newnode ;
}

}

void deleteAtPosition(int position, Node* &head,Node* &tail){
    if(position == 1){
        deleteatHead(head,tail);
        return ;
    }
    int length = getlength(head);
    if(position > length){
        cout << "Invalid Bound ";
        return ;
    }
    else{
        Node* prev = head ;
        for(int i=0; i<position-2; i++){
            prev = prev->next ;
        }
        Node* current = prev->next ;
        Node* forword = current->next ;

        current->next = NULL ;
        prev->next = forword ;
        delete current ;

    }



}

int main(){

    Node* head=NULL ;
    Node* tail=NULL ;

    insertHead(10,head,tail);
    insertHead(20,head,tail);
    insertHead(30,head,tail);
    insertHead(40,head,tail);
    insertTail(80,head,tail);

    //insertAtposition(5,500,head,tail);

    //cout<<"length of list is:- "<< getlength(head)<<endl ;
    //cout << search(10, head)<<endl;

    // deleteatHead(head,tail);
    // deleteatHead(head,tail);
    //deleteAtTail(head,tail);
    deleteAtPosition(5,head,tail);

    display(head) ;
    
   


    return 0 ;
}
