#include <iostream>
#include <queue>
#include <stack>
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

void preorderIterative(Node *root) {
      stack<Node *> s;
      while(true) {
          while (root != nullptr) {
              cout<<root->data<<" ";
              s.push(root);
              root = root->left;
          }
          if(s.empty()) break;
          root = s.top(); s.pop();
          root = root->right;
      }
}

void inorder (Node * root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void inorderIterative(Node *root) {
    stack<Node *> s;
    while(true) {
        while(root != nullptr) {
            s.push(root);
            root = root->left;
        }
        if(s.empty()) break;
        root = s.top(); s. pop();
        cout<<root->data<<" ";
        root = root->right;
    }
}

void postorder (Node * root) {
    if (root == nullptr)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void postorderIterative(Node *root) {
    stack<Node *>s;
    while(true) {
        while(root != nullptr) {
            s.push(root);
            s.push(root);
            root = root->left;
        }
        if(s.empty()) break;
        root = s.top(); s.pop();
        if(!s.empty() && root == s.top()) 
         root = root->right;
        else {
         cout<<root->data<<" ";
         root = nullptr;
        }
    }
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

int Diameter(Node *root) {
    if (root == nullptr) 
     return 0;

    int f = height(root->left) + height(root->right) +1;
    int lD = Diameter(root->left);
    int rD = Diameter(root->right);
    return max(f, max(lD, rD)); 
}

int maxSum(Node *root) {
    if (root == nullptr) {
       return 0;
    }
    int max_sum = 0, currentSum=0;
    std::queue<Node *> queue;
    queue.push(root);
    queue.push(nullptr);
    while(queue.empty() ==  false) {
        Node *temp = queue.front(); queue.pop();
        if (temp == nullptr) {
            max_sum = max(max_sum, currentSum);
            currentSum = 0;
            if(!queue.empty()) {
                queue.push(nullptr);
            }
        } else {
            if (temp != nullptr) {
                currentSum += temp->data;
            }

            if (temp->left) {
                queue.push(temp->left);
            }
            if(temp->right) {
                queue.push(temp->right);
            }
        }
    }
    return max_sum;
}

void DeleteTree (Node * root) {
    if (root == nullptr)
        return;
    DeleteTree(root->left);
    DeleteTree(root->right);
    delete root;
    root = nullptr;
}

Node * LCA(Node *root, Node *s1, Node *s2) {
    if (root == nullptr)
        return nullptr;

    if ( root == s1 || root == s2) {
        return root;
    }

    Node *left = LCA(root->left, s1, s2);
    Node *right = LCA(root->right, s1, s2);
    if(left && right) {
        return root;
    }
    return left ? left :right;
}

bool PrintAllAncestors(Node *root , Node *s) {
    if ( root == nullptr) {
        return false;
    }
    if (root->left == s || root ->right ==  s || PrintAllAncestors(root->left,s) || PrintAllAncestors(root->right,s)) {
        cout<<root->data<<" ";
        return true;
    }
    return false;
}

int main() {
    Node *s1, *s2;
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = s1 = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = s2 =new Node(10);
    root->left->right->right = new Node(11);
    root->right->left->left = new Node(12);
    root->right->left->right = new Node(13);
    root->right->right->left = new Node(14);
    root->right->right->right = s2 = new Node(15);
    cout<<"Preorder "; preorder(root); cout<<endl;
    cout<<"Inorder "; inorder(root); cout<<endl;
    cout<<"PostOrder "; postorder(root); cout<<endl;
    cout<<"Preorder Iterative "; preorderIterative(root); cout<<endl;
    cout<<"Inorder Iterative "; inorderIterative(root); cout<<endl;
    cout<<"Postorder Iterative "; postorderIterative(root); cout<<endl;
    cout<<"LevelOrder "; levelOrder(root); cout<<endl;
    cout<<"Size "<<TreeSize(root); cout<<endl;
    cout<<"Height "<<height(root); cout<<endl;
    cout<<"Diameter "<<Diameter(root)<<endl;
    cout<<"Max Sum "<<maxSum(root)<<endl;
    // print constructed binary tree
    cout<<"Common Ancestor "<<LCA(root, s1, s2)->data<<endl;
    cout<<"PrintAllAncestors "<<PrintAllAncestors(root, s2)<<endl;
    cout<<"Deleting the tree "; DeleteTree(root); cout<<endl;

    return 0;
}

