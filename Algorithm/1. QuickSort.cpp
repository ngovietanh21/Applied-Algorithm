#include <iostream>
#define MAX 1000005
 
using namespace std;
 
int A[MAX];
int n;
 
void input(){
    cin >> n;
    for (int i = 0; i<n; i++) {
        cin >> A[i];
    }
}
 
void print(){
    for (int i = 0; i<n; i++) {
        cout << A[i] << " ";
    }
}
 
void quickSort(int l, int r) {
    if (l<r) {
        int i = l;
        int j = r;
        int pivot = A[(i+j)/2];
        do {
            
            while (A[i] < pivot) {
                i++;
            }
            while (A[j] > pivot) {
                j--;
            }
            if (i<=j) {
                swap(A[i], A[j]);
                i++;
                j--;
            }
        } while (i <= j);
        quickSort(l, j);
        quickSort(i, r);
    }
    
}
 
 
int main(){
    input();
    quickSort(0,n-1);
    print();
    return 0;
}
