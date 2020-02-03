
//At the beginning of the semester, the head of a computer science department 𝐷 have to assign courses to teachers in a balanced way. The department 𝐷 has 𝑚 teachers 𝑇={1,2,...,𝑚} and 𝑛 courses 𝐶={1,2,...,𝑛}. Each course 𝑐∈𝐶 has a duration ℎ𝑐. Each teacher 𝑡∈𝑇 has a preference list which is a list of courses he/she can teach depending on his/her specialization. We know a list of pairs of conflicting two courses that cannot be assigned to the same teacher as these courses have been already scheduled in the same slot of the timetable. This conflict information is represented by a conflict matrix 𝐴 in which 𝐴(𝑖,𝑗)=1 indicates that course 𝑖 and 𝑗 are conflict.The load of a teacher is the total duration of courses assigned to her/him. How to assign 𝑛 courses to 𝑚 teacher such that each course assigned to a teacher is in his/her preference list, no two conflicting courses are assigned to the same teacher, and the maximal load of teachers is minimal.
//
//Input
//Line 1 contains 𝑛 and 𝑚 (1≤𝑛≤20,2≤𝑚≤5)
//Line 2 contains ℎ1,…,ℎ𝑛
//Line 𝑖+2 (𝑖=1,...,𝑛) contains a positive integer 𝑘 followed by 𝑘 positive integers which are the teachers who can teach course 𝑖.
//Line 𝑖+𝑛+2 (𝑖=1,...,𝑛) contains the 𝑖𝑡ℎ line of the conflict matrix 𝐴
//
//Output
//The output contains a unique number which is the maximal load of the teachers in the solution found and the value -1 if not solution found.
//
//Example
//input
//4 2
//3 7 2 1
//2 1 2
//2 1 2
//2 1 2
//2 1 2
//0 0 0 1
//0 0 0 0
//0 0 0 1
//1 0 1 0
//output
//8


#include <iostream>
#define MAX_N 25
#define MAX_M 8
 
// input data
int n; //lớp
int m; //giáo viên
int sz[MAX_N]; //số lượng giáo viên cho môn i;
int t[MAX_N][MAX_M]; // t[c][i] giáo viên i có thể dạy lớp c
int h[MAX_N]; //số giờ cho môn i
int A[MAX_N][MAX_N]; // môn i và môn j trùng giờ
 
//variables
int x[MAX_N]; // giáo viên cho môn i
int f[MAX_M]; //tải của giáo viên i
int f_best;
 
using namespace std;
 
//duyệt hết các môn trước môn k, nếu xung đột môn i với k và
//giáo viên i dạy môn v thì return false, else return true
int check(int v, int k){
    for(int i =1; i<=k-1;i++){
        if (A[i][k] && v==x[i]) return 0;
    }
    return 1;
}
 
//duyệt hết giáo viên để trả về tải nhỏ nhất
void solution(){
    int max =0;
    for(int i =1; i<=m;i++){
        if (max < f[i]) max = f[i];
    }
    if (max < f_best)
        f_best = max;
}
 
//Tìm giáo viên v cho môn k
void TRY(int k){
    //Duyệt trong các giáo viên có thể dạy môn k
    for(int i=0;i<sz[k];i++){
        //lấy từ dữ liệu giáo viên i có thể dạy lớp k
        int v = t[k][i];
        if(check(v,k)){
            x[k] = v;
            f[v] += h[k];
            if(k==n) solution();
            else TRY(k+1);
            f[v] -=h[k];
        }
    }
}
 
void Input(){
    cin >> n >> m;
    
    for(int i =1; i<=n;i++){
        cin >> h[i];
    }
    
    for(int i =1;i<=n;i++){
        cin >> sz[i];
        for(int j=0;j<sz[i];j++){
            cin >> t[i][j];
        }
    }
    
    for(int i =1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> A[i][j];
        }
    }
}
 
void Solve(){
    f_best = 1000000;
    TRY(1);
    if(f_best == 1000000) cout << "-1";
    else cout << f_best;
}
 
int main(){
    Input();
    Solve();
    return 0;
}
