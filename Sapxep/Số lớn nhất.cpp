// Cho một dãy gồm n
//  số nguyên không âm, bạn hãy viết chương trình sắp xếp dãy số này sao cho khi nối các số  lại với nhau thì ta thu được một số nguyên có giá trị lớn nhất.

// Gợi ý: Bạn có thể sắp xếp các số đã cho theo thứ tự: a
//  đừng trước b
//  nếu như ab¯¯¯¯¯>ba¯¯¯¯¯
// . Sau đó nối các phần tử thuộc dãy số đã sắp xếp lại với nhau để có được kết quả.

// Đầu vào
// Dữ liệu vào từ bàn phím gồm 2
//  dòng. Dòng đầu tiên chứa số nguyên n
// . Dòng thứ hai chứa n
//  số nguyên của dãy số cách nhau bởi một dấu cách. Giới hạn: (n≤105,
//  các số nguyến trong dãy số không vượt quá 109)
// .

// Đầu ra
// In ra màn hình số nguyên lớn nhất có thể đạt được.

#include<iostream>
using namespace std;

bool compare(string a, string b){
    if((a+b) > (b+a)){
        return true;
    }
    else {
        return false;
    }
}


void selection_sort(string*arr, int N){
    for(int i = 0; i< N; i++){
        int min_index = i;
        for(int j = i+1; j<N; j++){
            if(compare(arr[min_index], arr[j]) == true){
                min_index = j;
            }
        }
        if(i != min_index){
            //swap
            string tmp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = tmp;
        }
    }

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
        if (compare(L_arr[i],R_arr[j])==true) {
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
    int N;
    cin>> N;

    string* a = new string[N];

    for(int i = 0; i< N; i++){
        cin >> a[i];
    }

//    selection_sort(a, N);
    mergeSort(a, 0, N-1);


    for(int i = 0; i< N; i++){
        cout << a[i];
    }

}
