//Hình ảnh chụp từ vệ tinh vùng biển Atlantic gồm nhiều hòn đảo được chia nhỏ thành các lưới ô vuông. Máy quang học sẽ tiến hành quét từng lưới ô vuông, và tiến hành tô màu đỏ nếu ô đó có chứa đất của hòn đảo nào đó, và tô màu xanh nếu không có hòn đảo nào nằm trong nó. Hãy:
//
//* Đếm số hòn đảo có trong ảnh
//
//* Đưa ra diện tích của hòn đảo lớn nhất (= số lượng lưới ô vuông chứa hòn đảo lớn nhất)
//
//Input
//Dòng đầu tiên chứa hai số nguyên dương 𝑛,𝑚<=1000.
//
//Các dòng tiếp theo biểu diễn lưới ô vuông như ví dụ.
//
//Output
//Gồm hai dòng:
//
//Dòng đầu tiên chứa số lượng hòn đảo trong ảnh.
//
//Dòng thứ hai chứa diện tích của hòn đảo lớn nhất như miêu tả.
//
//Example
//input
//7 11
//00000000010
//11100000000
//00000111100
//00111111110
//00111111110
//00111111000
//00000110000
//output
//3
//28

#include <iostream>
#define MAX 1100
 
using namespace std;
 
int n, m, S, Smax;
char A[MAX][MAX];
bool visited[MAX][MAX];
int ncheck[] = {-1,0,1,0};
int mcheck[] = {0,-1,0,1};
 
bool isSafe(int i, int j){
    return (i>=0) && (j >= 0) && (i<n) && (j<m) && (A[i][j] == '1') && (!visited[i][j]);
}
 
void DFS(int i, int j){
    visited[i][j] = true;
    ++S;
    
    for(int k=0;k<4;k++){
        if (isSafe(i + ncheck[k], j + mcheck[k]))
            DFS(i + ncheck[k], j + mcheck[k]);
    }
}
 
int Count(){
    int IslandCount = 0;
    Smax = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j] == '1' && !visited[i][j]){
                S = 0;
                DFS(i,j);
                ++IslandCount;
                if (S > Smax) Smax = S;
            }
        }
    }
    return IslandCount;
}
 
int main(){
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> A[i][j];
        }
    }
    
    cout << Count() << endl << Smax;
    
    return 0;
}
