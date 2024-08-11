// Cho một dãy số A
// , bạn có thể thực hiên 3
//  loại lệnh sau với dãy số.

// 1 x: Thêm phần tử x
//  vào cuối dãy số.
// 2: Xóa phần tử đầu tiên của dãy số.
// 3: In ra phần tử đầu tiên của dãy số.
// Bạn hãy viết chương trình thực hiện N
//  truy vấn trên dãy số A
// . Ban đầu dãy số A
//  không chứa phần tử nào.

// Đầu vào
// Dữ liệu vào gồm nhiều dòng từ bàn phím:

// Dòng thứ nhất chứa số nguyên N
// .
//  N
//  dòng tiếp theo, mỗi dòng tương ứng với một trong 3 loại lệnh như trê. 
// (N≤105,x≤109
// )
// Đầu ra
//  Với mỗi lệnh loại 3, in ra màn hình phần tử đầu tiên trong dãy số

#include<iostream>

using namespace std;

class Queue{
    struct Node {
    int data;
    Node *next;
    };

    Node *head, *rear;
    int queue_size;

    public: Queue() {
        head = nullptr;
        rear = nullptr;
        queue_size = 0;
    }

    bool isEmpty(){
        if (queue_size == 0)
            return true;
        else
            return false;
    }

    void push(int x){
        Node* newnode = new Node;
        newnode->data = x;
        newnode->next = nullptr;

        if (isEmpty()){
            head = newnode;
            rear = newnode;
        }
        else {
            rear->next = newnode;
            rear = newnode;
        }

        queue_size ++;
    }

    int pop(){
        if (isEmpty()){
            cout << "Hang doi rong" << endl;
            return -1;
        }
        else {
            int x = head->data;
            if (queue_size == 1){
                head = nullptr;
                rear = nullptr;
            }
            else {
                Node*tmp = head;
                head = head->next;
                delete tmp;
            }
            queue_size --;
            return x;
        }
    }

    int top() {
        if (isEmpty()){
            cout << "Hang doi rong" << endl;
            return -1;
        }
        else {
            int x = head->data;
            return x;
        }
    }

    int back() {
        if (isEmpty()){
            cout << "Hang doi rong" << endl;
            return -1;
        }
        else {
            int x = rear->data;
            return x;
        }
    }

    int size() {
        return queue_size;
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
    Queue myQueue;

    int N;
    cin >> N;
    int x, y;
    for(int i = 0; i <N; i++){
        cin>>x;
        if (x == 1){
            cin >> y;
            myQueue.push(y);
        }
        else if (x == 2){
            myQueue.pop();
        }
        else if (x == 3){
            cout << myQueue.top() << endl;
        }
    }

    return 0;
}
