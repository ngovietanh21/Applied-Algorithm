//Cho 1 một chuỗi tổ hợp 𝐶 độ dài 𝑚 với các thành phần nằm trong tập {1,2,…,𝑛}. Tìm chuỗi tổ hợp kế tiếp của chuỗi 𝐶 trong thứ tự từ điển.
//
//Input
//Dòng đầu 2 số nguyên dương 𝑛,𝑚≤104.
//
//Dòng thứ 2 ghi 𝑚 số nguyên dương ≤𝑛 cách nhau bởi dấu cách.
//
//Output
//Ghi ra chuỗi 𝐶 trên một dòng duy nhất, các thành phần cách nhau bởi dấu cách. Nếu không tồn tại thì ghi ra -1.
//
//Example
//inputCopy
//5 3
//2 3 5
//outputCopy
//2 4 5

#include <iostream>
#define MAX 10002
 
using namespace std;
int n, m;
int A[MAX];
 
 
int main(){
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        cin >> A[i];
    }
    int k = m-1;
    while(A[k] == n-m+k+1) k--;
    if (k==-1){
        cout << "-1";
        return 0;
    }
    A[k]++;
    for(int i=k+1;i<m;i++){
        A[i]=A[i-1] +1;
        
    }
    for (int i=0;i<m;i++)
        cout << A[i] << " ";
    return 0;
}
