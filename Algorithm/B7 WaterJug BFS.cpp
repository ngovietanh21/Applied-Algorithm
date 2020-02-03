//
//There are two jugs, 𝑎 -litres jug and 𝑏 -litres jug (𝑎,𝑏 are positive integers). There is a pump with unlimited water. Given a positive integer 𝑐 , how to get exactly 𝑐 litres.
//
//Input
//Unique line contains positive integers 𝑎,𝑏,𝑐 (1≤𝑎,𝑏,𝑐≤900).
//
//Output
//Line contains the minimal number of steps to get 𝑐 litres or -1 if no solution found.
//
//6 8 4
//
//
//4


#include <iostream>
#include <queue>
#define MAX 902
 
using namespace std;
 
int a,b,c, temp;
int visited[MAX][MAX];
 
struct Pour{
    int x, y,buoc;
    Pour(int a, int b, int d){
        x = a; y =b; buoc = d;
    }
};
 
void BFS(int x, int y){
    queue<Pour> q;
    q.push(Pour(x,y,0));
    visited[x][y] = true;
    
    while(!q.empty()){
        Pour t = q.front();
        q.pop();
        
        if (t.x == c || t.y == c){
            cout << t.buoc;
            return;
        }
        
        if (t.x == 0){
            if(!visited[a][t.y]){
                q.push(Pour(a,t.y,t.buoc+1));
                visited[a][t.y] = true;
            }
        }
        
        if (t.y == 0){
            if (!visited[t.x][b]){
                q.push(Pour(t.x,b,t.buoc+1));
                visited[t.x][b] = true;
            }
        }
        
        if (t.x > 0){
            if(!visited[0][t.y]){
                q.push(Pour(0,t.y,t.buoc+1));
                visited[0][t.y] = true;
            }
        }
        
        if (t.y > 0){
            if(!visited[t.x][0]){
                q.push(Pour(t.x,0,t.buoc+1));
                visited[t.x][0] = true;
            }
        }
        
        if (t.x > 0 && t.y < b){
            temp = min (t.x, b-t.y);
            if (!visited[t.x-temp][t.y+temp]){
                q.push(Pour(t.x - temp,t.y+temp,t.buoc+1));
                visited[t.x-temp][t.y+temp] = true;
            }
        }
        
        if (t.x < a && t.y > 0){
            temp = min (a-t.x, t.y);
            if (!visited[t.x+temp][t.y-temp]){
                q.push(Pour(t.x+temp,t.y-temp,t.buoc+1));
                visited[t.x+temp][t.y-temp] = true;
            }
        }
    }
    cout << "-1";
}
 
int main(){
    cin >> a >> b >> c;
    BFS(0,0);
    return 0;
}
