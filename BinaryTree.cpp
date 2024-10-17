#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) 
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node* insertNode(Node* root) 
{
    int value;
    cin >> value;

    if (value == -1) 
    {
        return nullptr;
    }
    root = new Node(value);
    cout << "Enter left child of " << value << " (-1 for no node): ";
    root->left = insertNode(root->left);
    cout << "Enter right child of " << value << " (-1 for no node): ";
    root->right = insertNode(root->right);
    return root;
}

void inorderTraversal(Node* root) {
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
void preorderTraversal(Node* root) {
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    inorderTraversal(root->left);
    inorderTraversal(root->right);
}
void postorderTraversal(Node* root) {
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    inorderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = nullptr;
    cout << "Enter value for root node (-1 for no node): ";
    root = insertNode(root);
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;
    cout << "preorder Traversal: ";
    preorderTraversal(root);
    cout << endl;
    cout << "postorder Traversal: ";
    postorderTraversal(root);
    cout << endl;
    return 0;
}
