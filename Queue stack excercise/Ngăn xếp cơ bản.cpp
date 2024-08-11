// Cho một dãy số A
// , bạn có thể thực hiên 3
//  loại lệnh sau với một dãy số.

// 1 x: Thêm phần tử x
//  vào cuối dãy số.
// 2: Xóa phần tử cuối cùng của dãy số.
// 3: In ra phần tử cuối cùng của dãy số.
// Bạn hãy viết chương trình thực hiện N
//  lệnh trên dãy số A
// . Ban đầu dãy số A
//  không chứa phần tử nào.

// Đầu vào 
// Dữ liệu vào gồm nhiều dòng nhập từ bàn phím:

//  Dòng đầu tiên chứ số nguyên N
// . 
// N
//  dòng tiếp theo, mỗi dòng tương ứng với một trong 3
//  loại lệnh. (N≤105,x≤109
// )
// Đầu ra
// Với mỗi lệnh loại 3, in ra màn hình phần tử cuối cùng trong dãy số



#include<iostream>

using namespace std;

class Stack{
    struct Node {
    int data;
    Node* next;
    };

    Node *top;
    int stack_size;

    public: Stack() {
        top = nullptr;
        stack_size = 0;
    }

    bool isEmpty(){
        if (top==nullptr)
            return true;
        else
            return false;
    }

    void push(int x){
        Node* newnode = new Node;
        newnode->data = x;
        newnode->next = nullptr;

        newnode->next = top;
        top = newnode;
        stack_size ++;
    }

    int pop(){
        if (isEmpty()){
            cout << "Ngan xep rong" << endl;
            return -1;
        }
        else {
            Node*tmp = top;
            int x = top->data;
            top = top->next;
            delete tmp;
            stack_size --;
            return x;
        }
    }

    int head() {
        if (isEmpty()){
            cout << "Ngan xep rong" << endl;
            return -1;
        }
        else {
            int x = top->data;
            return x;
        }
    }

    int size() {
        return stack_size;
    }


    void printAll(){
        Node* curr = top;
        while(curr!=nullptr){
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

};


int main(){
    Stack myStack;

    int N;
    cin >> N;
    int x, y;
    for(int i = 0; i <N; i++){
        cin>>x;
        if (x == 1){
            cin >> y;
            myStack.push(y);
        }
        else if (x == 2){
            myStack.pop();
        }
        else if (x == 3){
            cout << myStack.head() << endl;
        }
    }

    return 0;
}
