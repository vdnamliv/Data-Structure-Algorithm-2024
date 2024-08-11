// Cho hai xâu kí tự s
//  và t
//  chỉ gồm các chữ cái in thường. Xâu s
//  được gọi là hoán vị của xâu t
//  nếu có thể thu được xâu s
//  từ xâu t
//  bằng cách đổi chỗ một số kí tự trong xâu t
// . Bạn hãy viết chương trình kiểm tra hai xâu có phải là hoán vị của nhau hay không.

// Đầu vào
// Dữ liệu vào từ bàn phím gồm 2T+1
//  dòng. Dòng đầu tiên chứa số nguyên T
//  là số lượng cặp xâu cần kiểm tra. 2T
//  dòng tiếp theo, mỗi 2
//  dòng chứa 2
//  xâu s,t
//  trên từng dòng.  Giới hạn: T≤10
//  độ dài xâu không vượt quá 104
// .

// Đầu ra
// Với mỗi cặp xâu, in ra màn hình ra yes
//  nếu 2
//  xâu này là hoán vị của nhau và no
//  nếu ngược lại.

#include<iostream>
using namespace std;


bool compare(string &s1, string &s2){
    int N = s1.length();
    int N2 = s2.length();
    if (N != N2){
        return false;
    }
    else {
        for(int i = 0; i< N; i++){

            for(int j = i; j < N; j ++){
                if (s1[i] == s2[j]){
                    char tmp = s2[i];
                    s2[i] = s2[j];
                    s2[j] = tmp;
                    break;
                }
            }
            if (s1[i] != s2[i]){
                return false;
            }
        }
        return true;
    }
}



int main(){
    int N;
    cin >> N;
    string s1;
    string s2;

    for (int i=0; i<N; i++){
        cin >> s1;
        cin >> s2;

        bool rsl = compare(s1, s2);

        if (rsl == true){
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }


    return 0;
}
