// Cho một ma trận A
//  có kích thước n×n
//  mà các phần tử trên cùng một hàng hoặc cùng một cột được sắp xếp không giảm (phần tử phía trước nhỏ hơn hoặc bằng phần tử phía sau). Bạn hãy viết chương trình tìm phần tử nhỏ thứ k
//  của ma trận này.

// Đầu vào: 

// Dữ liệu vào từ bàn phím gồm n+1
//  dòng. Dòng đầu tiên chứa hai số nguyên n,k
// . n
//  dòng tiếp theo mỗi dòng chứa n
//  số nguyên biểu diễn các phần tử của ma trận A
//  (n≤1000,1≤k≤n2,Ai,j≤107)
// .

// Đầu ra: 

// In ra màn hình phần tử nhỏ thứ k
//  của ma trận A
// .

#include <iostream>
using namespace std;

// tham khao https://www.geeksforgeeks.org/kth-smallest-element-in-a-row-wise-and-column-wise-sorted-2d-array-set-1/

int lower_bound(int* arr, int left, int right, int x){

    if (left > right) {
        return left;
    }

    int mid = (left + right) / 2;


    if (arr[mid] >= x) {
        return lower_bound(arr, left, mid - 1, x);
    }

    return lower_bound(arr, mid + 1, right, x);
}

int upper_bound(int* arr, int left,int right, int x){

    if (left > right) {
        return left;
    }

    int mid = (left + right) / 2;


    if (arr[mid] > x) {
        return upper_bound(arr, left, mid - 1, x);
    }

    return upper_bound(arr, mid + 1, right, x);
}



int find_kth_ele(int** a, int n, int k){
    int left = a[0][0];
    int right = a[n-1][n-1];


    while (left <= right){

        int mid = (left + right)/2;

        int count = 0;
        for(int i = 0; i< n; i++){
            count = count + upper_bound(a[i], 0, n-1, mid);
        }

        if(k >= count){
            left = mid+1;
        }
        else {
            right = mid-1;
        }


    }

    return right;
}


int main()
{
    int n, k;
    cin >> n >> k;


    int** a = new int*[n];
    for(int i =0; i< n; i++){
        a[i] = new int[n];
    }
    for(int i=0; i< n; i++){
        for(int j=0;j<n;j++){
            cin >> a[i][j];
        }
    }

    int rsl = find_kth_ele(a, n, k);

    cout << rsl;


    return 0;
}


