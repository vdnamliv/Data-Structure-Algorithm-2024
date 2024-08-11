// Cho một xâu kí tự chỉ gồm các dấu ngoặc {, }, (, ), [, ].  Một xâu kí tự được định nghĩa là hợp lệ như sau: 

// Một xâu rỗng là một xâu hợp lệ.
// Nếu xâu A là một xâu hợp lệ thì các xâu (A
// ), {A
// }, [A
// ] cũng là các xâu hợp lệ.
// Nếu xâu A
//  và B
//  là xâu hợp lệ thì xâu AB
//  cũng là xâu hợp lệ.
// Bạn hãy viết chương trình kiểm tra xem một xâu kí tự có hợp lệ hay không.
// Đầu vào
// Dữ liệu vào gồm nhiều dòng từ bàn phím:
// Dòng đầu tiên chứa số nguyên T
//  là số lượng xâu kí tự cần kiểm tra. 
// T
//  dòng tiếp theo, mỗi dòng chứa một xâu kí tự cần kiểm tra (T≤10,
//  độ dài xâu không vượt quá 104)
// .
// Đầu ra
// Với mỗi xâu kí tự, in ra  màn hình yes
//  nếu đó là xâu hợp lệ,  in ra no
//  nếu ngược lại .


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

string check(string s){
    int n = s.length();

    Stack myStack;
    for(int i = 0; i<n; i++){

        if (s[i] == '('){
            myStack.push(0);
        }
        if (s[i] == '{'){
            myStack.push(1);
        }
        if (s[i] == '['){
            myStack.push(2);
        }

        if (s[i] == ')'){
            if (myStack.head() == 0){
                myStack.pop();
            }
            else{
                return "no";
            }
        }
        if (s[i] == '}'){
            if (myStack.head() == 1){
                myStack.pop();
            }
            else{
                return "no";
            }
        }
        if (s[i] == ']'){
            if (myStack.head() == 2){
                myStack.pop();
            }
            else{
                return "no";
            }
        }
    }
    if (myStack.isEmpty() == false){
        return "no";
    }

    return "yes";

}

int main(){

    int q;
    cin >> q;

    for(int i = 0; i< q; i++){

        string s;
        cin >> s;

        cout << check(s) << endl;
    }


    return 0;
}
