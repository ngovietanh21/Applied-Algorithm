/*
 Từ thời xa xưa, dãy ngoặc được xem như là biểu tượng của tình yêu đôi lứa. Một cách tự nhiên như cách con người tìm ra lửa, người ta trở nên yêu quý các dãy ngoặc đúng
 
 Xâu rỗng là một dãy ngoặc đúng
 Nếu A là dãy ngoặc đúng thì (A) cũng là dãy ngoặc đúng
 Nếu A,B là 2 dãy ngoặc đúng thì AB cũng là dãy ngoặc đúng
 Ví dụ (()(())) là một dãy ngoặc đúng còn ()(()( thì không. Ngày còn mặn nồng ân ái, Hà Lan đã dành tặng cho Ngạn một dãy ngoặc đúng. Qua năm tháng, dãy ngoặc bị mờ đi một số chỗ, ta có thể biểu diễn các vị trí bị mờ bằng ký tự '?', lúc này dãy ngoặc sẽ trông như "(??(??))". Ngạn bối rối vì dãy ngoặc năm nào không còn nguyên vẹn, anh đã xem nó như minh chứng cho tình yêu của hai người. Dù biết có thể có rất nhiều cách khác nhau, Ngạn vẫn muốn khôi phục lại dãy ngoặc của mình. Suy cho cùng, sửa chữa lại dãy ngoặc cũng chính là đang sửa chữa lại các vết thương trong lòng...
 Hãy giúp Ngạn đếm số cách khác nhau để thay thế các ký tự '?' thành '(' hoặc ')' sao cho dãy ngoặc thu được là đúng.
 
 Input
 Gồm một xâu 𝑆 chỉ chứa các ký tự '?', '(', ')'
 
 Output
 Ghi số cách khác nhau khôi phục dãy ngoặc đúng, chỉ cần in ra số dư của số cách khi chia cho 1000000007
 
 Scoring
 Có 50% số test với 0<|𝑆|≤20
 Có 30% số test với 20<|𝑆|≤30
 Có 20% số test với 30<|𝑆|≤1000
 Example
 input
 (??(??))
 output
 5
 Note
 Các cách khôi phục là: (((()))), (()(())), (()()()), ()((())), ()(()())
 */

#include <iostream>
#define MAXN 1005

using namespace std;

const int mod = 1e9+7;

string s;
int dp[MAXN][MAXN]; // so luong ngoac mo con phai dong
int n;

void input() {
    cin >> s;
}

void init() {
    n = (int) s.size();
    s = ' ' + s;
}

void solve() {
    dp[0][0] = 1;
    
    for (int i = 1; i <= n; i++) {
        if (s[i]=='(')
            for (int j=0; j<=i; j++)
                dp[i][j] = dp[i-1][j-1];
        
        if (s[i]==')')
            for (int j=0; j<=i; j++)
                dp[i][j] = dp[i-1][j+1];
        
        if (s[i]=='?')
            for (int j=0; j<=i; j++) {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
                dp[i][j] = dp[i][j]%mod;
            }
    }
    
    /*
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    */
    cout << dp[n][0] << '\n';
}

int main() {
    input();
    init();
    solve();
    return 0;
}
