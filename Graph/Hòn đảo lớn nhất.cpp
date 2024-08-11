// Một vùng biển được biểu diễn thành một ma trận kích thước m×n
//  chỉ gồm các kí tự 0,1
//  với 0
//  đại diện cho vùng biển còn 1
//  đại điện cho vùng đất. Hai ô đất được gọi là liền kề nhau nếu chúng có chung nhau 1 cạnh. Một hòn đảo là tập các vùng đất liền kề nhau. Bạn hãy viết chương trình tìm hòn đảo có điện tích lớn nhất.

// Đầu vào
// Dữ liệu vào từ bàn phím gồm m+1
//  dòng. Dòng đầu tiên chứa 2
//  số nguyên m,n
// , (m,n≤1000)
// . m
//  dòng tiếp theo, mỗi dòng chứa n
//  số nguyên biễu diễn ma trận vùng biển. Các số nguyên trên cùng một dòng cách nhau bởi một dấu cách.

// Đầu ra
// In ra màn hình  kích thước của hòn đảo lớn nhất.

#include<iostream>
using namespace std;


void explore(int **a, int m, int n, int i, int j, int& area){

    if (i < 0 || j < 0 || i > (m - 1) || j > (n - 1) || a[i][j] != 1){
        return;
    }

    if(a[i][j] == 1){
        a[i][j] = 99;
        area = area+1;
        explore(a, m, n, i-1, j, area);
        explore(a, m, n, i+1, j, area);
        explore(a, m, n, i, j-1, area);
        explore(a, m, n, i, j+1, area);
    }



}

int main(){

    int m, n;
    cin >> m >> n;

    int** a = new int*[m];
    for(int i=0; i< m; i++){
        a[i] = new int[n];
    }

    for(int i=0; i< m; i++){
        for(int j=0; j< n; j++){
            cin >> a[i][j];
        }
    }

    int max_area = 0;
    for(int i=0; i< m; i++){
        for(int j=0; j< n; j++){
            if(a[i][j] == 1){
                int area = 0;
                explore(a, m, n, i, j, area);
                max_area = max(max_area, area);
            }
        }
    }

    cout << max_area;

//    for(int i=0; i< m; i++){
//        for(int j=0; j< n; j++){
//            cout << a[i][j] << " ";
//        }
//        cout << endl;
//    }

    return 0;
}
