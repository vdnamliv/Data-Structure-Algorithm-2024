// Cho n
//  số nguyên,  bạn hãy viết chương trình sắp xếp các số này theo thứ tự  tổng các chữ số tăng dần. Tức là, tổng các chữ số của số đứng trước nhỏ hơn hoặc bằng tổng các chữ số của số đứng sau. Nếu hai số có tổng các chữ số bằng nhau, thì số nhỏ hơn sẽ đứng trước.

// Đầu vào
// Dữ liệu vào từ bàn phím gồm n+1
//  dòng. Dòng đầu tiên chứa số nguyên n
//  (n≤104)
// . n
//  dòng tiếp theo mỗi dòng chứa một số nguyên không vượt quá 107
// .

// Đầu ra
// In ra màn hình các số sau khi đã sắp xếp, các số phân tách nhau bởi một dấu cách.



#include<iostream>
using namespace std;




int getSum(int n){
    int sum = 0;
    while(n>0)
    {
        int m=n%10;
        sum=sum+m;
        n=n/10;
    }
    return sum;
}

int compare(int x, int y){
    int sum_x = getSum(x);
    int sum_y = getSum(y);
    if (sum_x > sum_y) {
        return 1;
    }
    else if (sum_x == sum_y){
        if (x > y) {
            return 1;
        }
    }
    return 0;

}

void selection_sort(int*a, int N){
    for(int i = 0; i< N -1; i++){
        int min_index = i;
        for(int j = i+1; j<N; j++){
            if(compare(a[min_index], a[j]) == 1){
                min_index = j;
            }

        }
        if(i != min_index){
            //swap
            int tmp = a[i];
            a[i] = a[min_index];
            a[min_index] = tmp;

        }
    }

}

int main(){
    int N;
    cin >> N;
    int* a = new int[N];

    for (int i = 0; i< N; i++){
        cin >> a[i];
    }

    selection_sort(a, N);

    for (int i = 0; i< N; i++){
        cout << a[i] << endl;
    }



    return 0;
}
