#include<iostream>
using namespace std;

void HeapBottomUp(int H[], int n) {
    for (int i = n / 2; i >= 1; i--) {
        int k = i;
        int v = H[k];
        bool heap = false;
        while (!heap && 2 * k <= n) {
            int j = 2 * k;
            if (j < n && H[j] < H[j + 1]) {
                j = j + 1;
            }
            if (v >= H[j]) {
                heap = true;
            } else {
                H[k] = H[j];
                k = j;
            }
        }
        H[k] = v;
    }
}

void HeapSort(int H[], int n) {
    HeapBottomUp(H, n);
    for (int i = n; i > 1; i--) {
        swap(H[1], H[i]);
        int k = 1;
        int v = H[k];
        bool heap = false;
        while (!heap && 2 * k <= i - 1) {
            int j = 2 * k;
            if (j < i - 1 && H[j] < H[j + 1]) {
                j = j + 1;
            }
            if (v >= H[j]) {
                heap = true;
            } else {
                H[k] = H[j];
                k = j;
            }
        }
        H[k] = v;
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int H[n + 1]; // 1-based indexing for the heap

    cout << "Enter the elements: ";
    for (int i = 1; i <= n; i++) {
        cin >> H[i];
    }

    HeapSort(H, n);

    cout << "Sorted array: ";
    for (int i = 1; i <= n; i++) {
        cout << H[i] << " ";
    }
    cout << endl;

    return 0;
}
