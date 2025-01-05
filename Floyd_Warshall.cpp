#include <iostream>
#include <limits>

using namespace std;

void floydWarshall(int graph[][n], int v) 
{    
    int n = numeric_limits<int>::max();  
    int dist[n][n];
    
    for (int i = 0; i < v; ++i) 
    {
        for (int j = 0; j < v; ++j) 
        {
            dist[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < v; ++k) 
    {
        for (int i = 0; i < v; ++i) 
        {
            for (int j = 0; j < v; ++j) 
            {
                if (dist[i][k] != n && dist[k][j] != n && dist[i][k] + dist[k][j] < dist[i][j]) 
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    for (int i = 0; i < v; ++i) 
    {
        for (int j = 0; j < v; ++j) 
        {
            if (dist[i][j] == n)
            {
                cout << "INF ";
            }
            else
            {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() 
{
    int n;
    cin>>n;
    int graph[n][n];
    floydWarshall(graph, n) ;
    return 0;
}
