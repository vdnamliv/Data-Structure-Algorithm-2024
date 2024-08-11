// Tuyến phố thông minh Anna có n
//  tòa nhà, tòa nhà thứ i
//  có khoảng cách xi
//  mét so với đầu của tuyến phố. Thành phố quyết định sẽ đặt các trạm phát sóng wifi miễn phí tại các tòa nhà dọc theo tuyến phố thông minh. Mỗi thiết bị phát wifi có thể phủ sóng trong phạm vi k
//  mét, tức là các tòa nhà có khoảng cách đến thiết bị không vượt quá k
//  mét thì sẽ sử dụng được wifi từ thiết bị này. Bạn hãy viết chương trình tìm cách đặt các trạm wifi để số lượng trạm wifi là ít nhất và tất cả các tòa nhà đều có thể sử dụng wifi.

// Đầu vào
// Dữ liệu vào từ bàn phím gồm 2 dòng. Dòng đầu tiên chứa 2
//  số nguyên n,k
//   (n,k≤105)
// . Dòng thứ hai chứa n
//  số nguyên xi
//  (xi≤105)
// . Hai số nguyên trên cùng một dòng cách nhau bởi một dấu cách.

// Đầu ra
// In ra  màn hình số lượng thiết bị phát wifi ít nhất để tất cả các tòa nhà đều có thể sử dụng wifi.


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
    int n, k;
    cin >> n >> k;
    int* arr = new int[n];


    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    int i = 0;
    int rsl = 0;

    while (i < n){
        int idx = upper_bound(arr, i, n-1, arr[i] + k);

        i = idx - 1;
        rsl ++;

        idx = upper_bound(arr, i, n-1, arr[i] + k);
        i = idx;
    }



    cout << rsl;




    return 0;
}


