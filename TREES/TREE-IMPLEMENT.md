### TREE TRAVERSALS
1. PREORDER
2. INORDER
3. POSTORDER


```cpp

#include <iostream>
using namespace std ;

class Node {
    public:
    
    int data ;
    Node* left ;
    Node* right ;
    
    Node(int value){
        
        data = value ;
        left = NULL ;
        right = NULL ;
        
    }
    
};

Node* buildtree() {
    int val;
    cout << "Enter value (-1 for NULL): ";
    cin >> val;

    if(val == -1) return NULL;

    Node* root = new Node(val);

    cout << "Enter left of " << val << endl;
    root->left = buildtree();

    cout << "Enter right of " << val << endl;
    root->right = buildtree();

    return root;
}

void preOrder(Node* root) {
    
    // NLR TECHNIQUE
    // N = print Node 
    // L = move on Left side
    // R = move on right side 
    
    if(root == NULL) {
        return ;
    }
    
    // N = print Node
    cout << root->data << " " ; 
    
    // L = move on Left side
    preOrder(root->left) ;
    // R = move on right side
    preOrder(root->right) ;
    
}


void inOrder(Node* root) {
    
    // LNR TECHNIQUE
    // N = print Node 
    // L = move on Left side
    // R = move on right side 
    
    if(root == NULL) {
        return ;
    }
    
    // L = move on Left side
    inOrder(root->left) ;
    
    // N = print Node
    cout << root->data << " " ; 
    
    
    // R = move on right side
    inOrder(root->right) ;
    
}

void postOrder(Node* root) {
    
    // LRN TECHNIQUE
    // N = print Node 
    // L = move on Left side
    // R = move on right side 
    
    if(root == NULL) {
        return ;
    }
    
    // L = move on Left side
    postOrder(root->left) ;
    // R = move on right side
    postOrder(root->right) ;
    
    // N = print Node
    cout << root->data << " " ;
}


int main()
{
    
    cout<<"------------*****Tree Implementation*****-------------";
    cout << endl ;
    Node* root = buildtree() ;
    
    cout << "preOrder printing :- ";
    cout << endl ;
    
    preOrder(root) ;
    cout << endl ;
    
    cout << "inOrder printing :- " ;
    cout << endl ;
    inOrder(root) ;
    cout << endl ;
    
    cout << "postOrder printing :- " ;
    cout << endl ;
    postOrder(root) ;
    
    
    
    return 0;
}

```
