#include <iostream>
#include <string>
using namespace std;

void go(int x,int y);
int n, m, k, Max=0 , t=0;
bool a[2000][2000],army = true;
int main()
{
    string tmp;
    cin >> n >> m >> Max; //从标准输入流中输入两个整数
    for(int i =0;i<n;i++){
        cin >> tmp;
        for(int j =0;j<m;j++) 
            if(tmp[j] =='*') a[i][j] = 1;
            else a[i][j] = 0;
    }
    for(int i =0;i<n;i++)
        for(int j =0;j<m;j++)
            if(a[i][j]==1){
		t++;
		if(army){
		        k=0;
		        go(i,j);
			if(k*3>=Max) army = false;
		}
		if(t>1&&!army) {cout << "Demacia Win!";return 0;}
            }
    cout << "Demacia Lose!";
    return 0;
                
}

void go(int x,int y){
    k+= 1;
    a[x][y] = 0;
    if(a[x][y+1]==1) go(x,y+1);
    if(a[x+1][y]==1) go(x+1,y);
    if(a[x-1][y]==1) go(x-1,y);
    if(a[x][y-1]==1) go(x,y-1);
}
