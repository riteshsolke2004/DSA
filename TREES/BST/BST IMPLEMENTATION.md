# BST IMPLEMENTATION 

```cpp


#include <iostream>
#include <queue> 
using namespace std ;


class Node {
    public:
    
    int data ;
    Node* left ;
    Node* right ;
    
    Node(int val) {
        
        data = val ;
        left = NULL ;
        right = NULL ;
    }
    
};

Node* buildBST(Node* root, int val) {
    
    if(root == NULL) {
        
        root = new Node(val) ;
        return root ;
    }
    
    if(root->data < val) {
        
        root->right = buildBST(root->right , val) ;
        
    }
    else{
        root->left = buildBST(root->left , val) ;
    }
    return root ;
}

Node* createBST(Node* root) {
    
    int value ;
    cout << "Enter value for the Node" << endl ;
    cin >> value ;
    
    while(value != -1) {
        root = buildBST(root , value) ;
        cout << "Enter value for the Node"<< endl ;
        cin >> value ;
    }
    
    return root ;
}

void preorder(Node* root) {
    if(root == NULL) return ;
    
    //NLR 
    cout << root->data << " " ;
    
    preorder(root->left) ;
    
    preorder(root->right) ;
}


void inorder(Node* root) {
    if(root == NULL) return ;
    
    //LNR 
    inorder(root->left) ;
    
    cout << root->data << " " ;
    
    inorder(root->right) ;
}

void postorder(Node* root) {
    
    if(root == NULL ) return ;
    
    postorder(root->left) ;
    postorder(root->right) ;
    
    cout << root->data << " " ;
}

void levelorderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* front = q.front();
        q.pop();
        if(front == NULL) {
            cout << endl;
            if(!q.empty()) {
                q.push(NULL);
            }    
        }
        else {
            cout << front->data << " ";
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
    }
}

int getMin(Node* root) {
    if(root == NULL) return -1;
    while(root->left != NULL) {
        root = root->left;
    }
    return root->data;
}

int getMax(Node* root) {
    if(root == NULL) return -1;
    while(root->right != NULL) {
        root = root->right;
    }
    return root->data;
}

bool searchBST(Node* root, int target) {
    if(root == NULL) return false;
    if(root->data == target) return true;
    else if(target > root->data) return searchBST(root->right, target);
    else return searchBST(root->left, target);
}


int main()
{
    Node* root = NULL ;
    root = createBST(root) ;
    cout << endl ;
    cout <<endl << "Printing Preorder :- " ;
    preorder(root) ;
    
    cout << endl << "Printing inorder:- " ;
    inorder(root) ;
    
    cout << endl << "Printing Postorder:- " ;
    postorder(root) ;
    
    cout << endl << "Level wise Printing :- " ;
    levelorderTraversal(root) ;
    
    cout << endl << "Printing Minimum Number" ;  
    cout << getMin(root) ;
    
    cout << endl << "Printing Maximum Number" ;  
    cout << getMax(root) ;
    
    cout << endl << " target ans:- " ;
    cout <<searchBST(root , 60);
    

    return 0;
}

```
