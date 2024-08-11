// Thầy Long viết n
//  bài báo  khoa học, mỗi bài báo của thầy Long được một số người đọc và trích dẫn tham khảo. Mức độ ảnh hưởng của các nhà khoa học có thể được đánh gia thông qua chỉ số h-index. Chỉ số h-index càng cao, thì mức độ ảnh hưởng càng cao.  Chỉ số h-index của một nhà khoa học là k
//  nếu như nhà khoa học đó có ít nhât k
//  bài báo, mà mỗi bài báo được trích dẫn ít nhất k
//  lần.  Cho một dãy n
//  số biểu diễn số lần các bài báo khoa học của thầy Long được trích dẫn, bạn hãy viết chương trình tính chỉ số h-index lớn nhất của thầy Long nhé. 

// Đầu vào
// Dữ liệu vào từ bàn phím gồm 2
//  dòng. Dòng đầu tiên chứa số nguyên n
//  là số lượng bài báo của thầy Long (n≤104)
// . Dòng thứ hai chứa n
//  số nguyên, cách nhau bởi một dấu cách, là số lượng trích dẫn của từng bài báo  số lượng trích dẫn của từng bài báo và không vượt quá 105
// .

// Đầu ra 
// In ra màn hình chỉ số h-index của thầy Long.



#include<iostream>
using namespace std;

void selection_sort(int*arr, int N){
    for(int i = 0; i< N; i++){
        int min_index = i;
        for(int j = i+1; j<N; j++){
            if(arr[min_index] > arr[j]){
                min_index = j;
            }
        }
        //swap
        int tmp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = tmp;
    }

}

void bubble_sort(int*arr, int N){
    for(int i = 0; i< N; i++){
        for(int j = N-1; j>i; j--){
            if(arr[j] < arr[j-1]){
                //swap
                int tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;
            }
        }


    }

}

void insertion_sort(int*arr, int N){
    for(int i=1; i<N; i++){
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}



int main(){
    int N;
    cin>> N;

    int* a = new int[N];

    for(int i = 0; i< N; i++){
        cin >> a[i];
    }

    selection_sort(a, N);


    int h_index = 1;
    for(int i = N-1; i >= 0; i--){
        if (a[i] >= h_index){
            h_index ++;
        };
    }
    cout << --h_index;

}
