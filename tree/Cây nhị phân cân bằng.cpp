// Cây nhị phân cân bằng là cây nhị phân có độ cao lớn nhất của các đỉnh lá (độ sâu của cây) là nhỏ nhất có thể. Viết chương trình nhập vào một cây có N
//  đỉnh và kiểm tra đó có phải là cây nhị phân cân bằng hay không (các đỉnh của cây được đánh số từ 0
//  đến N−1
//  và gốc của cây là đỉnh 0
// ).

// Đầu vào
// Đầu vào từ bàn phím gồm N
//  dòng. Dòng đầu tiên chứa số nguyên N
//  là số đỉnh của cây (N≤1000)
// , N−1
//  dòng tiếp theo mỗi dòng chứa 2 số nguyên cách nhau bởi một dấu cách, biểu diễn một cạnh của cây .

// Đầu ra
// In ra màn hình "yes" nếu đó là cây nhị phân cân bằng và "no" nếu ngược lại.

#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    //constructor
    Node (int d){
        data = d;
        left = nullptr;
        right = nullptr;
    }

};

Node* findNode(Node *node, int parent){
    if(node == nullptr){
        return nullptr;
    }
    if (node->data == parent){
        return node;
    }
    Node *node1 = findNode(node->left, parent);
    if(node1 != nullptr){
        return node1;
    }
    Node *node2 = findNode(node->right, parent);
    return node2;
}



bool insertNode(Node*& root, int parent, int child){
    if(root == nullptr){
        Node *newP = new Node(parent);
        Node *newC = new Node(child);

        newP -> left = newC;
        root = newP;

    }
    else {
        Node *p = findNode(root, parent);
        if (p != nullptr){
            Node *newC = new Node(child);

            if (p->left == nullptr){
                p->left = newC;
            }
            else if (p->left != nullptr && p->right == nullptr){
                p->right = newC;
            }
            else { // left, right != null
                return false;
            }
        }
    }
    return true;

}


int height(Node* node) {
   if(node == nullptr){
        return 0;
   }
   else {
        return 1 + max(height(node->left), height(node->right));
   }
}


bool checkAVL(Node *root){
    int left_h;
    int right_h;
    if(root == NULL)
        return true;
    left_h = height(root->left); // left height
    right_h = height(root->right); // right height
    if(abs(left_h - right_h) <= 1 && checkAVL(root->left) && checkAVL(root->right)) return true;
    return false;
}


void  travelTree(Node *root){
    if(root != nullptr){
        travelTree(root -> left);
        cout << root->data << " ";
        travelTree(root -> right);
    }

}


int main(){
    Node *root = nullptr;

    int n;
    cin >> n;

    for (int i=0; i<n-1; i++){
        int x, y;
        cin >> x >> y;

        insertNode(root, x, y);

    }
    bool rsl = checkAVL(root);

    if (rsl){
        cout << "yes";
    }
    else {
        cout << "no";
    }
    //travelTree(root);
    return 0;
}
