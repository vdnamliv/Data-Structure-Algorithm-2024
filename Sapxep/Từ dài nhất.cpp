// Cho một xâu s
//  và một bộ từ điển chứa n
//  từ ( các từ chỉ chứa các chữ cái in thường).  Tìm từ có độ dài lớn nhất trong từ điển sao cho có thể tạo thành từ này bằng cách xóa đi một số ký tự trong xâu s
// . Nếu có nhiều từ có độ dài bằng nhau, in ra từ có

// Đầu vào: Dòng đầu tiên chứa xâu s
// . Dòng thứ hai chứa số nguyên n
// . n
//  dòng tiếp theo, mỗi dòng chứa một xâu trong từ điên. (n≤1000,
//  đô dài các xâu không vượt quá 1000)
// .

// Đầu ra: In ra xâu có độ dài lớn nhất thỏa mãn điều kiện. Nếu có nhiều từ có độ dài bằng nhau, in ra từ có thứ tự từ điển nhỏ nhất.

// Dữ liệu vào nhập từ bàn phím và kết quả được in ra màn hình.

#include<iostream>
using namespace std;


int checkString(string a, string b){
    int n = a.length();
    int m = b.length();

    for(int i=0, j=0;i<n;i++){

        if (a[i] == b[j]){
            j ++;
        }
        if (j == m){
            return 1;
        }

    }
    return 0;

}

int compareString(string a, string b){
    if(a.length() >= b.length()){
        return 1;
    }
    return 0;
}

void merge(string* arr,int left,int mid,int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    string *L_arr = new string[n1];
    string *R_arr = new string[n2];

    for (int i = 0; i < n1; i++)
        L_arr[i] = arr[left + i];
    for (auto j = 0; j < n2; j++)
        R_arr[j] = arr[mid + 1 + j];

    int i = 0; //index left arr
    int j = 0; //index right arr
    int k = left; // index merge arr

    while (i < n1 && j < n2) {
        if (compareString(L_arr[i],R_arr[j])==1) {
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


void mergeSort(string* arr,int left,int right){
    if (left >= right)
        return;

    int mid = (left+right)/2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}



int main(){
    string c;
    int n;
    cin >> c >> n;

    string* k = new string[n];

    int idx = 0;
    for(int i = 0; i < n; i++){
        string tmp;
        cin >> tmp;
        if (checkString(c, tmp) == 1){
            k[idx] = tmp;
            idx++;
        }

    }
    mergeSort(k, 0, idx-1);

    cout << k[0];

}


