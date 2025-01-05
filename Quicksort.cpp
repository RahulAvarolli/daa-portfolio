#include<iostream>
using namespace std;
int Partition(int A[],int l,int r){
    int pivot=A[r],i=l-1;
    for(int j=l;j<r;j++){
        if(A[j]<=pivot){
            i++;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[r]);
    return i+1;
}
void QuickSort(int A[],int l,int r){
    if(l<r){
        int s=Partition(A,l,r);
        QuickSort(A,l,s-1);
        QuickSort(A,s+1,r);
    }
}
int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)cin>>A[i];
    QuickSort(A,0,n-1);
    for(int i=0;i<n;i++)cout<<A[i]<<" ";
    return 0;
}
