#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node *left;
        node *right;
    node(int d){
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};
node *createTree(node *root){
    cout << "Enter the data: " << endl;
    int data; cin >> data;
    root = new node(data);
    if (data == -1) return NULL;
    cout << "Enter data for inserting in left of " << data << endl;
    root -> left = createTree(root -> left);
    cout << "Enter data for inserting in right of " << data << endl;
    root -> right = createTree(root -> right);
    return root;
}
int main(){
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    node *root = NULL;
    root = createTree(root);
    
    return 0;
}