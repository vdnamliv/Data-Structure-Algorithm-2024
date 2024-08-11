// Cây nhị phân T
//  được gọi là hoàn hảo nếu nó thỏa mãn hai điều kiện sau:

// Mỗi đỉnh của cây T
//  có đúng hai đỉnh con.
// Các đỉnh lá của cây T
//  có độ sâu bằng nhau (độ sâu của một đỉnh được tính bằng số cạnh nằm trên đường đi từ đỉnh gốc đến đỉnh đó).
// Bạn hãy viết chương trình nhập vào một cây có N
//  đỉnh và kiểm tra xem có phải là cây nhị phân hoàn hảo hay không (các đỉnh của cây được đánh số từ 0
//  đến N−1
//  và gốc của cây là đỉnh 0
//  ).
// Đầu vào
// Dữ liệu vào từ bàn phím gồm N
//  dòng. Dòng đầu tiên chứa số nguyên N
//  là số đỉnh của cây (N≤1000)
// . N−1
//  dòng tiếp theo mỗi dòng chứa 2 số nguyên x,y
//   biểu diễn một cạnh của cây trong đó đỉnh y
//  là con của đỉnh x
// .

// Đầu ra
// In ra "yes" nếu đó là cây nhị phân hoàn hảo và "no" nếu ngược lại.

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

int findDepth(Node *node)
{
   int d = 0;
   while (node != nullptr)
   {
      d++;
      node = node->left;
   }
   return d;
}

bool checkPerfectBTree(Node *root, int depth, int level){
    if(root == NULL)
        return true;

    if (root->left == NULL && root->right == NULL){
        return (level+1 == depth);
    }
    if (root->left == NULL || root->right == NULL)
        return false;

    return checkPerfectBTree(root->left, depth, level+1) && checkPerfectBTree(root->right, depth, level+1);
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

    int tree_depth = findDepth(root);
    bool rsl = checkPerfectBTree(root, tree_depth, 0);

    if (rsl){
        cout << "yes";
    }
    else {
        cout << "no";
    }
    //travelTree(root);
    return 0;
}
