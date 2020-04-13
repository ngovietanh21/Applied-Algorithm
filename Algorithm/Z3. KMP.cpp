//Gần đây giới sinh vật học chấp nhận một thuyết tiến hóa mới gọi là di truyền ngang, bác bỏ một số quan điểm trong thuyết tiến hóa của Darwin - vốn cho rằng di truyền chỉ xay ra theo chiều dọc, tức là cấu trúc cây. Theo đó, một sinh vật có thể tiếp nhận một đoạn ADN tự do của một loài hoàn toàn khác vào trong cấu trúc di truyền của mình.
//
//Để đưa ra bằng chứng cho thuyết mới này, họ đã sưu tập ADN của nhiều loài sinh vật khác nhau. Sau đó, họ đưa ra một đoạn ADN tự do và tính toán số lần xuất hiện của đoạn ADN này trong ADN của từng loài trong số đã sưu tập được. Hãy giúp các nhà khoa học thực hiện công việc phức tạp này để nhanh chóng kiểm định được thuyết di truyền ngang
//
//Input
//Dòng đầu tiên chứa một xâu chỉ gồm các ký tự A, T, G, X mô tả mẫu ADN tự do
//Dòng tiếp theo chứa số nguyên dương 𝑄 là số loài đã có AND
//𝑄 dòng tiếp theo, mỗi dòng chứa một xâu chỉ gồm các ký tự A, T, G, X mô tả ADN của một loài
//Output
//Ghi ra 𝑄 dòng, mỗi dòng là số lần xuất hiện của mẫu ADN tự do trong ADN của loài tương ứng
//
//Scoring
//1≤𝑄≤106. Tổng độ dài của tất cả các xâu trong input không quá 2×106
//Có 50% số test với độ dài mỗi xâu không quá 1000 và 𝑄≤10
//Example
//inputCopy
//AGA
//3
//AGAGAGA
//GAGXAGAGAXAGA
//ATGX
//outputCopy
//3
//3
//0

#include <iostream>
#define MAX 1000005
 
using namespace std;
 
string freeADN;
string animalADN[MAX];
int Q;
 
void input() {
    cin >> freeADN >> Q;
    for (int i = 0; i<Q; i++) {
        cin >> animalADN[i];
    }
    
}
 
int checkADN(string check){
    unsigned long M = freeADN.length();
    unsigned long N = check.length();
    int res = 0;
    for (int i = 0; i <= N - M; i++)
     {
 
         int j;
         for (j = 0; j < M; j++)
             if (check[i+j] != freeADN[j])
                 break;
    
         if (j == M)
         {
            res++;
         }
     }
     return res;
    
}
 
void solve(){
    for (int i = 0; i<Q; i++) {
        cout << checkADN(animalADN[i]) << endl;
    }
}
 
int main(){
    input();
    solve();
    return 0;
}
