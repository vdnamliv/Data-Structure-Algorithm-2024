// Mỗi khoảng số nguyên được biểu diễn bởi hai số [a,b]
// , trong đó a là điểm bắt đầu và b là điểm kết thúc của đoạn. Hai khoảng số nguyên [a,b]
//  và [c,d]
//  được gọi là chồng lên nhau nếu chúng có điểm chung.  Hợp của Hai khoảng số nguyên chồng lên nhau [a,b]
//  và [c,d]
//  là một khoảng mới có dạng [min(a,c), max(b,d)]. 

// Cho n
//  khoảng số nguyên, bạn hãy viết chương trình hợp các khoảng số nguyên này lại với nhau.

// Đầu vào
// Dữ liệu đầu vào gồm n+1
//  dòng. Dòng đầu tiên chứa số nguyên n
// . n
//  dòng tiếp theo, mỗi dòng chứa 2
//  số nguyên ai,bi
//  cách nhau bởi một dấu cách là đầu và cuối của các khoảng số nguyên.  Giới hạn: (n≤105,|ai|,|bi|≤109
// .

// Đầu ra
// In ra màn hình các khoảng số nguyên sau khi đã hợp nhất theo thứ tự tăng dần (khoảng [a,b]
//  nhỏ hơn khoảng [c,d]
//  nếu a<c
// ).

#include <iostream>
using namespace std;

struct Element{
    int first;
    int second;
};

bool compareLess(Element a, Element b){
    if(a.first < b.first){
        return true;
    }
    else{
        return false;
    }
}

void merge(Element* arr,int left,int mid,int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Element *L_arr = new Element[n1];
    Element *R_arr = new Element[n2];

    for (int i = 0; i < n1; i++)
        L_arr[i] = arr[left + i];
    for (auto j = 0; j < n2; j++)
        R_arr[j] = arr[mid + 1 + j];

    int i = 0; //index left arr
    int j = 0; //index right arr
    int k = left; // index merge arr

    while (i < n1 && j < n2) {
        if (compareLess(L_arr[i], R_arr[j])) {
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


void mergeSort(Element* arr,int left,int right){
    if (left >= right)
        return;

    int mid = (left+right)/2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}




int main(){
    int n;
    cin >> n;

    Element *arr = new Element[n];

    for(int i=0; i<n; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    mergeSort(arr, 0, n-1);

    Element *rsl = new Element[n];
    int k = 0; //index of result arr
    int i = 0; // index of sorted arr
    rsl[k] = arr[i];

    for(int i=1; i< n; i++){
        if(arr[i].first > rsl[k].second){
            k++;
            rsl[k] = arr[i];
        }
        else if (arr[i].first <= rsl[k].second){
            if (arr[i].second <= rsl[k].second){
                //do nothing
            }
            else if (arr[i].second > rsl[k].second){
                rsl[k].second = arr[i].second;
            }
        }
    }

    for(int j=0; j<=k; j++){
        cout << rsl[j].first << " " << rsl[j].second << endl;
    }


    return 0;
}
