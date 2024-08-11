// Cho 2
//  ngăn xếp chứa các số nguyên không âm A=[a1,a2,⋅,an],B=[b1,b2,⋅,bm]
// , phần tử đầu tiên là đỉnh của ngăn xếp. Pete chơi một trò chơi trên hai ngăn xếp này như sau:

// Ở mỗi lượt chơi, Pete loại bỏ một số phần tử ở đỉnh của một trong hai hàng đợi.
// Pete tính tổng của các phần tử đã được loại bỏ và tính tổng của chúng.
// Trò chơi kết thúc khi tổng của các phần tử được loại bỏ lớn hơn một số nguyên x
//  cho trước.
// Điểm mà Pete nhận được bằng với số phần tử đã được loại bỏ.
// Bạn hãy giúp Pete tính số điểm lớn nhất mà anh ấy có thể đạt được.
// Đầu vào
// Đầu vào từ bàn phím gồm 3
//  dòng. Dòng đầu tiên chứa 3 số nguyên n,m,x
//  (n,m≤105,x≤106)
// . Dòng thứ 2 chứa n
//  số nguyên ai
// . Dòng thứ 3 chứa m
//  số nguyên bi
//  (ai,bi≤105)
// . Các số nguyên trên cùng một dòng cách nhau bởi một dấu cách

// Đầu ra
// In ra màn hình một số nguyên duy nhất là điểm số lớn nhất mà Pete có thể đạt được



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

    int sum() {
        Node* curr = top;
        int sum = 0;
        while(curr!=nullptr){
            sum = sum + curr->data;
            curr = curr->next;
        }
        return sum;
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
    Stack stackA;
    Stack stackB;


    int n, m, x;
    cin >> n >> m >> x;

    int* a = new int[n];
    int* b = new int[m];

    for(int i = 0; i<n; i++){
        cin >> a[i];
    }

    for(int i = 0; i<m; i++){
        cin >> b[i];
    }


    int sum = 0;
    for (int i = 0; i < n && (sum + a[i] <= x); i++){
        stackA.push(a[i]);
        sum = sum + a[i];
    }

    int result = stackA.size();

    int i = 0;

    while(i < m && stackA.size() >= 0){
        stackB.push(b[i]);
        sum = sum + b[i];

        while(sum > x && stackA.size() > 0){
            int tmp = stackA.pop();
            sum = sum - tmp;
        }


        if(sum <= x){
            int tmp = stackA.size() + stackB.size();
            if (result < tmp){
                result = tmp;
            }
        }
        else {
            break;
        }


        i++;

    }

    cout << result << endl;

    return 0;
}
