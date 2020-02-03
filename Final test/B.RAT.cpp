// Thành phố được mã hóa dưới dạng tọa đồ 100x100. Thành phố bị tấn công bởi chuột, được biết thành phố được trang bị 1 quả có sức công phá là d, tức là mọi điểm trong (|x-x0|, |y-y0| <=d) sẽ bị nổ. Tính toán số chuột bị giết nhiều nhất

// Input:
// Dòng 1 d và n
// n Dòng tiếp là tọa độ chuột có và số lượng chuột ở đó

//Ouput: Tọa độ x,y và số chuột giết đc

//1
//2
//4 4 10
//6 6 20

//5 5 30

#include <iostream>
#define MAXN 10005
using namespace std;
 
int d,n;
int matrix[102][102];
int res[3];

int check (int x, int y) {
    int boom = 0;
    for (int i = x-d; i<=x+d; i++) {
        for (int j = y-d; j<=y+d; j++) {
            if (i>=0 && i<=100 && j >=0 && j <=100) {
                boom += matrix[i][j];;
            }
        }
    }
    return boom;
}
 
void Solve(){
    res[2] = -1;
    for (int i = 0; i<=100; i++) {
        for (int j = 0; j<=100; j++) {
            int k = check(i, j);
            if (k > res[2]) {
                res[2] = k;
                res[1] = j;
                res[0] = i;
            }
        }
    }
    
    cout << res[0] << " " << res[1] << " " << res[2];
}
    
 
void Input(){
    cin >> d >> n;
    for (int i = 1; i<=n; i++) {
        int x,y,chuot;
        cin >> x >> y >> chuot;
        matrix[x][y] = chuot;
    }
}
 
int main(){
    Input();
    Solve();
    
    return 0;
}
