// Cho một cây T
// , độ sâu của một đỉnh trong cây T
//  bằng số cạnh nằm trên đường đi từ đỉnh gốc đến đỉnh đó. Chiều cao của cây T
//  được tính bằng độ sâu lớn nhất của các đỉnh trong T
// . 

// Bạn hãy viết chương trình tính chiều cao của một cây có N
//  đỉnh (các đỉnh của cây được đánh số từ 0
//  đến N−1
//  và gốc của cây là đỉnh 0
//  ).

// Đầu vào
// Dữ liệu vào từ bàn phím gồm N
//  dòng. Dòng đầu tiên chứa số nguyên N
//  là số đỉnh của cây (N≤1000)
// . N−1
//  dòng tiếp theo mỗi dòng chứa 2 số x,y
//  biểu diễn một cạnh của cây trong đó đỉnh y
//  là con của đỉnh x
//  .

// Đầu ra
// In ra màn hình chiều cao của cây.


#include<iostream>

using namespace std;

struct Node {
    int data;
    Node *next;

    Node(){
    }

    Node(int val){
        data = val;
        next = nullptr;
    }
};

struct Graph {
    int numVertices;
    Node **lists;

    Graph(){
    }

    Graph(int vertices){
        numVertices = vertices;
        lists = new Node*[numVertices];

        for (int i = 0; i < numVertices; i++){
            lists[i] = new Node(i);
        }

    }

    void addEdge(int s, int d){
        Node *newNode = new Node(d);
        newNode->next = lists[s]->next;
        lists[s]->next = newNode;

    }

    void printGraph(){
        for (int i = 0; i < numVertices; i++)
        {
            cout << lists[i]->data << ": ";
            Node *temp = lists[i]->next;
            while (temp)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void graph_BFS(int s){
        bool visited[numVertices]={false};

        int queue[numVertices];
        int front = 0, rear = 0;

        visited[s] = true;
        queue[rear++] = s;

        while (front != rear) {

            s = queue[front++];
            cout << lists[s]->data << " ";

            Node *temp = lists[s]->next;
            while (temp)
            {
                if (visited[temp->data] == false){
                    visited[temp->data] = true;
                    queue[rear++] = temp->data;
                }

                temp = temp->next;
            }
        }

    }

    int DFS(bool visited[], int s, int depth){
        visited[s] = true;

        Node *temp = lists[s]->next;
        int max_depth = depth;

        while (temp)
        {
            if (visited[temp->data] == false){
                int tmp_depth = DFS(visited, temp->data, depth+1);
                if (max_depth < tmp_depth)  max_depth = tmp_depth;
            }

            temp = temp->next;
        }

        return max_depth;
    }

    void graph_DFS_depth(int s){
        bool visited[numVertices]={false};

        int max_depth = DFS(visited, s, 0);
        cout << max_depth;

    }


};





int main()
{
    int n;
    cin >> n;
    Graph *graph = new Graph(n);

    for(int i = 0; i<n-1;i++){

        int x, y;
        cin >> x >> y;
        graph->addEdge(x, y);
    }


    graph->graph_DFS_depth(0);

    return 0;
}
