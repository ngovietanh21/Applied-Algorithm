//Cho 1 một hoán vị 𝐻 độ dài 𝑛 với các thành phần nằm trong tập {1,2,…,𝑛}. Tìm hoán vị kế tiếp của hoán vị 𝐻 trong thứ tự từ điển.
//
//Input
//Dòng đầu ghi 1 số nguyên dương 𝑛≤104.
//
//Dòng thứ 2 ghi 𝑛 số nguyên dương ≤𝑛 cách nhau bởi dấu cách là hoán vị 𝐻.
//
//Output
//Ghi ra hoán vị 𝐻 trên một dòng duy nhất, các thành phần cách nhau bởi dấu cách. Nếu không tồn tại thì ghi ra -1.
//
//Example
//inputCopy
//5
//3 2 1 5 4
//outputCopy
//3 2 4 1 5

#include <iostream>
#define MAX 10000
 
using namespace std;
 
int n, A[MAX];
 
void Solution(){
    for (int i=0;i<n;i++){
        if (i== n-1) cout << A[i];
        else cout << A[i] << " ";
    }
}
 
void TimHoanViKeTiep(){
    int i = n-1;
    int k = n-1;
    
    while(A[i] < A[i-1]) {
        i--;
        if (i==0){
            cout << "-1";
            return;
        }
    }
    
    while(A[i-1] > A[k]){
        k--;
    }
    swap(A[i-1], A[k]);
    
    k = n-1;
    while(i<k){
        swap(A[i], A[k]);
        i++;k--;
    }
    Solution();
    
}
 
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    TimHoanViKeTiep();
    
    return 0;
}
