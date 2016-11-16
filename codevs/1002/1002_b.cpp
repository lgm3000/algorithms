#include<vector>
#include<iostream>
#include<string>

#define endline cout << endl

using namespace std;
int n,m,b[2500],flag=0,ext = 0,shits=0,a[2500][2500]={0};
void print();

int main(){

	cin >> n >> m;

	string a;
	cin >> a;
	if(a.substr(0,1) == ".") b[0] = -1;

	for(int j = 1; j < m; j++)
		if(a.substr(j,1) == "#"){
			if(b[j-1]!=-1)			
				{b[j] = b[b[j-1]];
				shits++;
				}
			else b[j] = j;
		}
		else b[j] = -1;


	for(int i = 1; i < n; i++){
		cin >> a;		
		for(int j = 0; j < m; j++){
			if(a.substr(j,1) == "#") {
				if(b[(i-1)*m+j]!=-1)
					b[i*m+j] = b[b[(i-1)*m+j]];
				else if(b[(i-1)*m+j+1]!=-1)
					b[i*m+j] = b[b[(i-1)*m+j+1]];
				else if(j>0&&b[(i-1)*m+j-1]!=-1)
					b[i*m+j] = b[b[(i-1)*m+j-1]];
				else if(j>0&&b[j-1]!=-1)			
					b[j] = b[b[j-1]];
				else
					b[i*m+j] = i*m+j;
			shits++;
			}
			else b[i*m+j] = -1;
		}
	}

	print();


}

void print(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			{cout.width(3);cout << b[i*m+j];}
		endline;
	}
	endline;
}
