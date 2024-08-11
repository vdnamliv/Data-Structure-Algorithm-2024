// Cho một dãy A
//  gồm N
//  số nguyên và số nguyên K
// . Đếm số lượng cặp số nguyên trong dãy A có chênh lệch bằng K
// .

// Đầu vào
// Dữ liệu vào từ bàn phím gồm 2
//  dòng. Dòng đầu tiên chứa 2 số nguyên N
//  và K
//  (0<N≤105,0≤K≤109)
// . Dòng thứ 2 chứa N
//  số nguyên ai
//  thuộc dãy A
//  (ai<231−1
// ).

// Đầu ra
// In ra màn hình một dòng duy nhất chứa số lượng cặp số nguyên có chênh lệch là K
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


int main()
{
    int n, k;
    cin >> n >> k;
    int* arr = new int[n];


    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    int count = 0;
    for (int i=0; i< n-1; i++){
        int value = arr[i] + k;

        int idx = binarySearch(arr, 0, n-1, value);

        if(idx != -1){
            count ++;
        }
    }

    cout << count;

    return 0;
}


