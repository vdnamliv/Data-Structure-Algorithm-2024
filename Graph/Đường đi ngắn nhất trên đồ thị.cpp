// Có N
//  điạ điểm trong một thành phố được đánh số từ 1
//  đến N
// , có M
//  đường đi nối các địa điểm này với nhau. Tìm đường đi ngắn nhất của tất cả các cặp đỉnh trên đồ thị.
// Đầu vào
// Đầu vào từ bàn phím gồm M+1
//  dòng. Dòng đầu tiên chứa 2 số nguyên N,M
//  (N≤100,M≤5000)
// . M
//  dòng tiếp theo, mỗi dòng chứa 3 số nguyên u,v,w
// , thể hiện có đường đi giữa u
//  và v
//  với độ dài w
//  (w≤100)
// .

// Đâu ra
// In ra màn hình n
//  dòng N
//  dòng, mỗi dòng gồm N
//  số cách nhau bởi một dấu cách. Số thứ j
//  thuộc dòng thứ i
//  là độ dài đường đi ngắn nhất của từ địa điểm i
//  đến địa điểm j
//  ( nếu không tồn tại đường đi từ i
//  đến j
// , ghi ra "-1"\).


//tham khao https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/

#include <iostream>

using namespace std;

#define INF 999

void floyd(int dist[100][100], int n)
{

	for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if ((dist[i][k] + dist[k][j]) < dist[i][j] && dist[k][j] != INF && dist[i][k] != INF)
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
}



int main()
{
    int n, m;
    cin >> n >> m;

    int a[100][100];

    for(int i=0; i< n; i++){
        for(int j=0; j< n; j++){
            if(i==j){
                a[i][j] = 0;
            }
            else {
                a[i][j] = INF;
            }
        }
    }



    for(int i =0; i< m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        a[x-1][y-1] = min(a[x-1][y-1], z);
        a[y-1][x-1] = min(a[y-1][x-1], z);
    }


	floyd(a, n);

	for(int i=0; i< n; i++){
        for(int j=0; j< n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }


	return 0;
}

