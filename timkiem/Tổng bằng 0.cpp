// Cho hai dãy số A,B
//  chứa các số nguyên. Bạn hãy viết chương trình đếm số lượng cặp chỉ số i,j
//  sao cho Ai+Bj=0
// .

// Đầu vào
// Dữ liệu vào từ bàn phìm gồm ba dòng. Dòng đầu tiên chứa 2
//  số nguyên m,n
//  là số lượng phần tử trong hai dãy số A,B
// . Dòng thứ hai chứa m
//  số nguyên trong dãy số A
// . Dòng thứ ba chứa n
//  số nguyên trong dãy số B
// . Giới hạn: n,m≤105,|Ai|,|Bi|≤106
// . Các số nguyên trên cùng một dòng cách nhau bởi một dấu cách.

// Đầu ra
// In ra màn hình số lượng cặp chỉ số i,j
//  thỏa mãn điều kiện Ai+Bj=0
// .

#include <iostream>
using namespace std;


void merge(int* arr,int left,int mid,int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L_arr = new int[n1];
    int *R_arr = new int[n2];

    for (int i = 0; i < n1; i++)
        L_arr[i] = arr[left + i];
    for (auto j = 0; j < n2; j++)
        R_arr[j] = arr[mid + 1 + j];

    int i = 0; //index left arr
    int j = 0; //index right arr
    int k = left; // index merge arr

    while (i < n1 && j < n2) {
        if (L_arr[i] <= R_arr[j]) {
            arr[k] = L_arr[i];
            i++;
        }
        else {
            arr[k] = R_arr[j];
            j++;
        }
        k++;
    }


    while (i < n1) {
        arr[k] = L_arr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R_arr[j];
        j++;
        k++;
    }

    delete[] L_arr;
    delete[] R_arr;
}


void mergeSort(int* arr,int left,int right){
    if (left >= right)
        return;

    int mid = (left+right)/2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}


int binarySearch(int* arr, int left, int right, int x){
    if (left <= right) {
        int mid = (left+right) / 2;

        if (arr[mid] == x){
            return mid;
        }
        else if (arr[mid] > x){
            return binarySearch(arr, left, mid - 1, x);
        }
        else if (arr[mid] < x){
            return binarySearch(arr, mid + 1, right, x);
        }


    }

    return -1;

}

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


int main()
{
    int m, n;
    cin >> m >> n;
    int* a = new int[m];
    int* b = new int[n];


    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    mergeSort(a, 0, m - 1);
    mergeSort(b, 0, n - 1);


    long count = 0;
    for (int i=0;i<m;i++){
        int opp = 0 - a[i];

        count = count + (upper_bound(b, 0, n-1, opp) - lower_bound(b, 0, n-1, opp));

    }

    cout << count;





    return 0;
}


