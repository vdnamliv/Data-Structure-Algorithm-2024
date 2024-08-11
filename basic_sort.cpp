#include <iostream>
#include<vector>

using namespace std;
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int a[], int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j] > a[j+1])
                swap(a[j], a[j+1]);
        }
    }
}

void selectionSort(int a[],int n){
    int min = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1; j<n;j++){
            if(a[j] < a[min]) min = j;
        }
        if(a[i] != a[min]) swap(a[i], a[min]);
    }
}

void insertionSort(int a[],int n){
    for(int i=1;i<n;i++){
        int key = a[i];
        int j = i-1;
        while(j>=0 && a[j] > key){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}
/*
void quickSort(int a[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(a, low, high);
        quickSort(a, low, pivotIndex - 1);
        quickSort(a, pivotIndex + 1, high);
    }
}

int partition(int a[], int low, int high) {
    // Choose the middle element as the pivot
    int pivot = a[(low + high) / 2];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}
*/

//tron 2 day con: 
void merge(int a[],int l, int m, int r){
    vector<int> x(a+l, a+m+1) ;
    vector<int> y(a+m+1,a+r+1);
    int i=0, j=0;
    while(i < x.size() && j<y.size()){
        if(x[i] <= y[j]) {
            a[l] = x[i];
            l++;
            i++;
        }
        else{
            a[l] = y[j];
            l++;
            j++;
        }
    }
    while(i < x.size()){
        a[l] = x[i]; l++; i++;
    }
    while(j < y.size()){
        a[l] = y[j]; l++; j++;
    }
}

void mergeSort(int a[], int l, int r){
    if(l>=r) return;
    int m = (l+r) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m+1, r);
    merge(a, l, m, r);
}

void mergeSort(int a[], int n){
    if (n == 1) return;
}


int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    mergeSort(a, 0, n-1);
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    return 0;
}
