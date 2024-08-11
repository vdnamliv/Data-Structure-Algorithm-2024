// Hệ thống giao thông trong thành phố bao gồm N
//  địa điểm (đánh số từ 1
//  đến N
// ) và M
//  đường đi hai chiều nối các địa điểm.  Cho 2 địa điểm s
//  và t
// , bạn hãy viết chương trình tìm đường đi ngắn nhất từ s
//  đến t
// .

// Đầu vào
// Dữ liệu vào từ bàn phím gồm M+2
//  dòng. Dòng đầu tiên chứa 2 số nguyên N,M
//  (N≤104,M≤5×104)
// . Dòng thứ 2 chứ 2 số nguyên s,t
// . M
//  dòng tiếp theo, mỗi dòng chứa 3 số nguyên u,v,w
// , thể hiện có đường đi giữa u
//  và v
//  với độ dài w
//  (w≤100)
// . Các số nguyên trên cùng một dòng cách nhau bởi một dấu cách.

// Đâu ra
// In ra màn hình một dòng duy nhất chứa độ dài đường đi ngắn nhất từ s
//  đến t
// .


#include <iostream>
using namespace std;

int minDistance(int dist[], bool sptSet[], int V)
{

	int min = 9999, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] < min)
			min = dist[v], min_index = v;

	return min_index;
}

void dijkstra(int** graph, int src, int dst, int V)
{
	int *dist =  new int[V];

	bool *sptSet = new bool[V];

	for (int i = 0; i < V; i++)
		dist[i] = 9999, sptSet[i] = false;

	dist[src] = 0;

	for (int c = 0; c < V - 1; c++) {

		int u = minDistance(dist, sptSet, V);

		sptSet[u] = true;


		for (int v = 0; v < V; v++)


			if ((sptSet[v] == false) && (graph[u][v] != 999) && (dist[u] != 9999) && (dist[u] + graph[u][v] < dist[v]))
				dist[v] = dist[u] + graph[u][v];
	}

	cout << dist[dst];
}

int main()
{

	int n, m;
    cin >> n >> m;
    int s, t;
    cin >> s >> t;

    int **a = new int*[n];
    for(int i = 0; i < n; i++){
        a[i] = new int[n];
        for(int j = 0; j <n ; j++){
            if(i==j){
                a[i][j] = 0;
            }
            else{
                a[i][j] = 999;
            }

        }
    }


    for(int i =0; i< m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        a[x-1][y-1] = min(a[x-1][y-1], z);
        a[y-1][x-1] = min(a[y-1][x-1], z);
    }

	dijkstra(a, s-1, t-1, n);

	return 0;
}
