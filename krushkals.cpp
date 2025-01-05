#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

class kruskal {
public:
    int n, m, cnt = 0;
    vector<Edge> temp, ans;
    int *arr;

    kruskal() {
        cout << "Enter no of vertices: ";
        cin >> n; 
        cout << "Enter no. of edges you are entering: ";
        cin >> m;

        temp.resize(m);
        cout << "Enter values for u, v, w one by one:\n";
        for (int i = 0; i < m; i++) {
            cin >> temp[i].u >> temp[i].v >> temp[i].w;
        }

        mergesort(temp);

        arr = (int *)malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }
    }

    void merge(vector<Edge> &b, vector<Edge> &c, vector<Edge> &a) {
        int i = 0, j = 0, k = 0, p = b.size(), q = c.size();
        while (i < p && j < q) {
            if (b[i].w <= c[j].w) {
                a[k++] = b[i++];
            } else {
                a[k++] = c[j++];
            }
        }
        while (i < p) a[k++] = b[i++];
        while (j < q) a[k++] = c[j++];
    }

    void mergesort(vector<Edge> &a) {
        int n = a.size();
        if (n > 1) {
            vector<Edge> b(a.begin(), a.begin() + n / 2);
            vector<Edge> c(a.begin() + n / 2, a.end());
            mergesort(b);
            mergesort(c);
            merge(b, c, a);
        }
    }

    void Union(int u, int v) {
        int temp1 = arr[u];
        for (int i = 0; i < n; i++) {
            if (arr[i] == temp1) arr[i] = arr[v];
        }
    }

    int Find(int u, int v) {
        return arr[u] == arr[v];
    }

    void ops() {
        int i = 0;
        while (cnt < n - 1 && i < m) { 
            if (!Find(temp[i].u, temp[i].v)) {
                Union(temp[i].u, temp[i].v);
                ans.push_back(temp[i]);
                cnt++;
            }
            i++;
        }
    }
};

int main() {
    kruskal k;
    k.ops();

    cout << "Edges in the Minimum Spanning Tree:\n";
    for (auto edge : k.ans) {
        cout << edge.u << " " << edge.v << " " << edge.w << endl;
    }

    return 0;
}
