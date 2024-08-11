// Bạn có thể thực hiên 3
//  loại truy vấn sau với một dãy số.

// 1 x: thêm phần tử x vào cuối dãy số;
// 2: xóa phần tử cuối cùng của dãy số;
// 3: in ra phần tử nhỏ nhất của dãy số.
// Cho một dãy số rỗng không chứa phần tử nào, bạn hãy viết chương trình thực hiện N
//  truy vấn trên dãy số này.

// Đầu vào
// Dữ liệu vào từ bàn phím gồm N+1
//  dòng. Dòng đầu tiên chứ số nguyên N
// . N
//  dòng tiếp theo, mỗi dòng tương ứng với một trong 3 loại truy vấn. (N≤105,x≤109
// )

// Đầu ra
// Với mỗi truy vấn loại 3 in ra màn hình phần tử nhỏ nhất trong dãy số.


#include<iostream>

using namespace std;

class Stack{
    struct Node {
    int data;
    Node* next;
    };

    Node *head;
    int stack_size;

    public: Stack() {
        head = nullptr;
        stack_size = 0;
    }

    bool isEmpty(){
        if (head==nullptr)
            return true;
        else
            return false;
    }

    void push(int x){
        Node* newnode = new Node;
        newnode->data = x;
        newnode->next = nullptr;

        newnode->next = head;
        head = newnode;
        stack_size ++;
    }

    int pop(){
        if (isEmpty()){
            cout << "Ngan xep rong" << endl;
            return -1;
        }
        else {
            Node*tmp = head;
            int x = head->data;
            head = head->next;
            delete tmp;
            stack_size --;
            return x;
        }
    }

    int top() {
        if (isEmpty()){
            cout << "Ngan xep rong" << endl;
            return -1;
        }
        else {
            int x = head->data;
            return x;
        }
    }

    int size() {
        return stack_size;
    }


    void printAll(){
        Node* curr = head;
        while(curr!=nullptr){
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

};

int main(){
    Stack myStack;
    Stack minStack;

    int N;
    cin >> N;
    int x;
    int y;
    for(int i = 0; i <N; i++){
        cin>>x;

        if (x == 1){
            cin >> y;
            myStack.push(y);

            if (myStack.size() == 1){
                minStack.push(y);
            }
            else {
                if (y <= minStack.top()){
                    minStack.push(y);
                }
            }
        }
        else if (x == 2){
            int tmp = myStack.pop();
            if(tmp == minStack.top()){
                minStack.pop();
            }
        }
        else if (x == 3){

            cout << minStack.top() << endl;
        }
    }

    return 0;


}

