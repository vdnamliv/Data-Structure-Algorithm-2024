// An có 2
//  dãy số A
//  và B
// , B
//  là hoán vị của A
// . Do sơ suất, An đã xóa đi một số phần tử trong dãy A
// . Bạn hãy giúp An xác định nhưng con số bị mất này nhé.

// Đầu vào: Dòng đầu tiên chứa số nguyên n
//  là số phần tử của dãy A
//  sau khi đã bị xóa. Dòng thứ 2 chứa n
//  phần tử của dãy A
// , dòng thứ 3 chứa số nguyên m
//  là số phần tử của dãy B
// . Dòng thứ 4 chứa m
//  phần tử của dãy B
// . (n,m≤2×105,
//  các phần thử ≤104)
// .

// Đầu ra: In ra các phần tử bị xóa theo thứ tự tăng dần, nếu có nhiều phần tử bị xóa có giá trị bằng nhau, chỉ in ra giá trị đấy 1 lần.

// Dữ liệu vào nhập từ bàn phím và kết quả được in ra màn hình.

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
    int n, m;
    cin >> n;
    int* a = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> m;
    int* b = new int[m];

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    mergeSort(a, 0, n - 1);
    mergeSort(b, 0, m - 1);

//    for (int i = 0; i < m; i++) {
//        cout << b[i] << endl;
//    }

    int i=0;
    int j=0;
    while (i < n){
        if(a[i] == b[j]){
            i++;
            j++;
        }
        else if(a[i] != b[j]){
            cout << b[j] << " ";
            j++;
            while(a[i] != b[j]){
                if(b[j] != b[j-1]){
                    cout << b[j] << " ";
                }
                j++;
            }
        }
    }
    if(j < m){
        cout << b[j] << " ";
        j++;
    }
    while(j < m){
        if(b[j] != b[j-1]){
            cout << b[j] << " ";
        }
        j++;
    }


    return 0;
}


