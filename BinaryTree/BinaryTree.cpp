#include <iostream>
#include <queue>
using namespace std;

class Node {
public: 
    int data;
    Node *left;
    Node *right;
    Node (int data) {
        this->data = data;
        this->left = this->right = nullptr;
    }
    ~Node() {
        cout<<"~"<<data<<" ";
    }
};

void preorder (Node * root) {
    if (root == nullptr)
        return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder (Node * root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder (Node * root) {
    if (root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void levelOrder(Node *root) {
    if(root == nullptr)
     return;
    queue<Node*>q;
    int size = 0, height = 0;
    q.push(root);
    q.push(nullptr);
    while(q.empty() == false) {
        Node * temp = q.front(); q.pop();
        if(temp == nullptr) {
            if (!q.empty()) {
                q.push(nullptr);
            }
            height++;
            continue;
        } else {
            cout<< temp->data<<" ";
            size++;
        }
        if(temp->left != nullptr) {
            q.push(temp->left);
        }
        if(temp->right != nullptr) {
            q.push(temp->right);
        }
    }
    cout<<"|Size "<<size<<"|Height "<<height;
}

int TreeSize(Node *root) {
    if(root == nullptr) {
        return 0;
    }
    return 1+ TreeSize(root->left)+ TreeSize(root->right);
}

int height(Node *root) {
    if(root== nullptr) {
        return 0;
    }
    int left, right;
    left = height(root->left);
    right = height(root->right);
    if(left > right) {
        return left+1;
    } else {
        return right+1;
    }
}
 
void DeleteTree (Node * root) {
    if (root == nullptr)
        return;
    DeleteTree(root->left);
    DeleteTree(root->right);
    delete root;
    root = nullptr;
}


int main() {
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);

    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->left->right->left = new Node(80);

    root->right->left = new Node(60);
    root->right->right = new Node(70);
    cout<<"Preorder "; preorder(root); cout<<endl;
    cout<<"Inorder "; inorder(root); cout<<endl;
    cout<<"PostOrder "; postorder(root); cout<<endl;
    cout<<"LevelOrder "; levelOrder(root); cout<<endl;
    cout<<"Size "<<TreeSize(root); cout<<endl;
    cout<<"Height "<<height(root); cout<<endl;
    cout<<"Deleting the tree "; DeleteTree(root); cout<<endl;
    return 0;
}

