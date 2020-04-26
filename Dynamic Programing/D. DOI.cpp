/*
 Cho dãy số nguyên 𝑎1,𝑎2,...,𝑎𝑛. Ta gọi dãy con gồm các phần tử liên tiếp của dãy đã cho 𝑎𝑖, ..., 𝑎𝑗, ..., 𝑎𝑘 (1≤𝑖<𝑗<𝑘≤𝑛) là đồi nếu 𝑎𝑡<𝑎𝑡+1 với mọi 𝑖≤𝑡<𝑗 và 𝑎𝑡>𝑎𝑡+1 với mọi 𝑗≤𝑡<𝑘. Trong trường hợp này ta gọi min{𝑗−𝑖, 𝑘−𝑗} là độ cao của đồi. Tương tự như vậy, ta gọi dãy con gồm các phần tử liên tiếp của dãy đã cho 𝑎𝑖, ..., 𝑎𝑗, ..., 𝑎𝑘 (1≤𝑖<𝑗<𝑘≤𝑛) là thung lũng nếu 𝑎𝑡>𝑎𝑡+1 với mọi 𝑖≤𝑡<𝑗 và 𝑎𝑡<𝑎𝑡+1 với mọi 𝑗≤𝑡<𝑘. Trong trường hợp này ta gọi min{𝑗−𝑖, 𝑘−𝑗} là độ sâu của thung lũng.
 
 Yêu cầu: Hãy tính độ cao của đồi cao nhất và độ sâu của thung lũng sâu nhất của dãy số đã cho.
 
 Input
 Dòng thứ nhất chứa số nguyên 𝑛 (1≤𝑛≤106) là số lượng phần tử của dãy số
 Dòng thứ hai chứa 𝑛 số nguyên là các phần tử của dãy số (hai số liên tiếp được ghi cách nhau bởi dấu cách. Mỗi phần tử của dãy số có trị tuyệt đối không vượt quá 100000.
 Output
 Một dòng chứa hai số nguyên là độ cao của đồi cao nhất và độ sâu của thung lũng sâu nhất. Nếu không có đồi hoặc không có thung lũng thì vị trí tương ứng ghi số 0.
 
 Examples
 
 input
 10
 4 4 1 6 3 2 1 2 5 7
 output
 1 3
 
 input
 10
 2 3 4 5 6 7 8 9 10 9
 output
 1 0
 */

#include <iostream>

using namespace std;

const int MAX = 1e6 + 1;

int n;
int a[MAX];

int f1[MAX];    // tang dan ket thuc tai i
int f2[MAX];    // giam dan bat dau tu i

int f3[MAX];    // giam dan ket thuc tai i
int f4[MAX];    // tang dan bat dau tu i

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >>a[i];
}

void tim_doi_cao_nhat() {
    f1[0] = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i-1]) f1[i] = f1[i-1] + 1;
        else f1[i] = 0;
    }
    
    f2[n-1] = 0;
    for (int i = n-2; i >= 0; i--) {
        if (a[i] > a[i+1]) f2[i] = f2[i+1] + 1;
        else f2[i] = 0;
    }
    
    int res1 = 0;
    for (int i = 0; i < n; i++) {
        res1 = max(res1, min(f1[i],f2[i]));
    }
    cout << res1;
}

void tim_thung_lung_sau_nhat() {
    f3[0] = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i-1]) f3[i] = f3[i-1] + 1;
        else f3[i] = 0;
    }
    
    f4[n-1] = 0;
    for (int i = n-2; i >= 0; i--) {
        if (a[i] < a[i+1]) f4[i] = f4[i+1] + 1;
        else f4[i] = 0;
    }
    
    int res2 = 0;
    for (int i = 0; i < n; i++) {
        res2 = max(res2, min(f3[i],f4[i]));
    }
    cout << " " << res2;
}

int main() {
    input();
    tim_doi_cao_nhat();
    tim_thung_lung_sau_nhat();
}
