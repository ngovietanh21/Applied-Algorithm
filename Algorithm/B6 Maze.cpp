//A Maze is represented by a 0-1 matrix 𝑎𝑁×𝑀 in which 𝑎𝑖,𝑗 = 1 means cell (𝑖,𝑗) is an obstacle, 𝑎𝑖,𝑗 = 0 means cell (𝑖,𝑗) is free. From a free cell, we can go up, down, left, or right to an adjacent free cell. Compute the minimal number of steps to escape from a Maze from a given cell (𝑖0,𝑗0) within the Maze.
//
//Input
//Line 1 contains 𝑁,𝑀,𝑖0,𝑗0 (2≤𝑁,𝑀≤900 )
//Line 𝑖+1 (𝑖=1,…,𝑁 ) contains the 𝑖𝑡ℎ line of the matrix 𝑎𝑁×𝑀
//
//Output
//Unique line contains the number minimal of steps to escape the Maze or -1 if no way to escape the Maze.
//
//8 12 5 6
//1 1 0 0 0 0 1 0 0 0 0 1
//1 0 0 0 1 1 0 1 0 0 1 1
//0 0 1 0 0 0 0 0 0 0 0 0
//1 0 0 0 0 0 1 0 0 1 0 1
//1 0 0 1 0 0 0 0 0 1 0 0
//1 0 1 0 1 0 0 0 1 0 1 0
//0 0 0 0 1 0 1 0 0 0 0 0
//1 0 1 1 0 1 1 1 0 1 0 1
//
//7


#include <iostream>
#include <queue>
#define MAX 1000
 
using namespace std;
 
int n,m,x0,y0,xi,yi;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int A[MAX][MAX];
bool visited[MAX][MAX];
 
struct point
{
    int x, y, dem;
    point(int X, int Y, int Dem)
    {
        x=X; y=Y; dem=Dem;
    }
};
 
bool isSafe(int x, int y){
    if ((x>n) || (y>m) || (x<1) || (y<1) || (A[x][y] == 1) || (visited[x][y]))
        return false;
    return true;
}
 
void BFS(int x, int y){
    queue <point> q;
    q.push(point(x,y,1));
    visited[x][y] = true;
    while(!q.empty()){
        point check = q.front();
        q.pop();
        for(int i =0;i<4;i++){
            xi = check.x + dx[i];
            yi = check.y + dy[i];
            if (isSafe(xi, yi)){
                visited[xi][yi] = true;
                q.push(point(xi,yi,check.dem+1));
                if (xi == n || yi == m || xi == 1 || yi == 1){
                    cout << check.dem+1;
                    return;
                }
            }
        }
    }
    cout << "-1";
}
 
void Init(){
    cin >> n >> m >> x0 >> y0;
    for(int i = 1;i<=n;i++){
        for(int j = 1; j<=m;j++){
            cin >> A[i][j];
        }
    }
}
 
int main(){
    Init();
    BFS(x0,y0);
    return 0;
}
