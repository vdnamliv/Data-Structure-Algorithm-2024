// Cho n
//  xâu kí tự, bạn hãy viết chương trình sắp xếp các xâu kí tự này theo thứ tự độ dài tăng dần, nếu có nhiều xâu có độ dài bằng nhau, sắp xếp các xâu này theo thứ tự từ điển.

// Đầu vào
// Dữ liệu vào từ bàn phím gồm n+1
//  dòng. Dòng đầu tiên chứa số nguyên n
//  (n≤104)
// . n
//  dòng tiếp theo mỗi dòng chứa một xâu kí tự có độ dài không vượt quá 20
// .

// Đầu ra
// In ra màn hình các xâu sau khi đã sắp xếp, mỗi xâu trên một dòng.

#include<iostream>
using namespace std;

bool compareString(string a, string b){
    if(a.length() < b.length()){
        return true;
    }
    else if (a.length() == b.length()){
        if (a.compare(b) < 0){
            return true;
        }
    }
    return false;
}


void selection_sort(string*arr, int N){
    for(int i = 0; i< N -1; i++){
        int min_index = i;
        for(int j = i+1; j<N; j++){
            if(compareString(arr[min_index], arr[j]) == false){
                min_index = j;
            }
        }
        if(i != min_index){
            //swap
            string tmp_str = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = tmp_str;
        }
    }

}



int main(){
    int N;
    cin >> N;
    string* arr = new string[N];


    for (int i = 0; i< N; i++){
        cin >> arr[i];
    }

    selection_sort(arr,N);

    for (int i = 0; i< N; i++){
        cout << arr[i] << endl;
    }



    return 0;
}
