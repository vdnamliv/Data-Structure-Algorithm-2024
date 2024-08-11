// Cây nhị phân là cây mà mỗi đỉnh có tối đa 2 đỉnh con. Viết chương trình nhập vào một cây có N
//  đỉnh và kiểm tra xem có phải là cây nhị phân hay không (các đỉnh của cây được đánh số từ 0
//  đến N−1
//  và gốc của cây là đỉnh 0
//  ).

// Đầu vào
// Dữ liệu vào từ bàn phím gồm n
//  dòng. Dòng đầu tiên chứa số nguyên N
//  là số đỉnh của cây (N≤1000)
// . N−1
//  dòng tiếp theo mỗi dòng chứa 2 số nguyên dương x,y
//  biểu diễn một cạnh của cây trong đó y
//  là đỉnh con của đỉnh x
//  .

// Đầu ra
// In ra màn hình "yes" nếu đó là cây nhị phân và "no" nếu ngược lại.

#include <iostream>
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

void  travelTree(Node *root){
    if(root != nullptr){
        cout << root->data << " ";
        travelTree(root -> left);
        travelTree(root -> right);
    }

}


int main(){
    Node *root = nullptr;

    int n;
    cin >> n;

    bool rsl = true;
    for (int i=0; i<n-1; i++){
        int x, y;
        cin >> x >> y;
        bool tmp = insertNode(root, x, y);

        if (tmp == false){
            rsl = false;
        }

    }

    if (rsl == true){
        cout << "yes";
    }
    else{
        cout << "no";
    }


    return 0;
}
