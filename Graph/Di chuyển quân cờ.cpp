// Cho một bàn cờ có kích thước m×n
//  và một quân cờ được đặt ở vị trí x,y
// , ( các hàng được đánh số từ 0
//  đến m−1
//  và các cột được đánh số từ 0
//  đến n−1)
// . Mỗi bước, bạn có thể duy chuyển quân cờ đến một trong bốn ô kề nó. Tuy nhiên, bạn chỉ có thể di chuyển tối đa k
//  bước. Tính số cách di chuyển quân cờ ra khỏi bàn cờ.

// Đầu vào
// Đầu vào từ bàn phím gồm một dòng duy nhất chứa năm số nguyên m,n,x,y,k
//  cách nhau bởi một dấu cách.(m,n,k≤50)
// .

// Đầu ra
// In ra màn hình số cách di chuyển quân cờ ra khỏi bàn cờ. Vì kết quả có thể rất lớn nên bạn chỉ cần in ra phần dư của kết quả với 109+7
// .

#include<iostream>

using namespace std;


long long explore(int m, int n, int x, int y, int k, long long mem[55][55][55]){


    if ((x <0 || x >= m || y <0 || y>=n) && k >= 0){
        return 1;
    }

    if(k<0){
        return 0;
    }

    if (mem[x][y][k] != -1){
        return mem[x][y][k];
    }



    long long total = 0;

    total = (total + explore(m, n, x+1, y, k-1, mem))%1000000007;
    total = (total + explore(m, n, x-1, y, k-1, mem))%1000000007;
    total = (total + explore(m, n, x, y+1, k-1, mem))%1000000007;
    total = (total + explore(m, n, x, y-1, k-1, mem))%1000000007;

    mem[x][y][k] =  total;

    return mem[x][y][k];


}



int main()
{
    int m, n, x, y, k;
    long long mem[55][55][55];

    for (int u = 0; u < 55; u++) {
        for (int v = 0; v < 55; v++) {
            for (int w = 0; w < 55; w++) {
                mem[u][v][w] = -1;
            }
        }
    }


    cin >> m >> n >> x >> y >> k;

    cout << explore(m, n, x, y, k, mem);

}

