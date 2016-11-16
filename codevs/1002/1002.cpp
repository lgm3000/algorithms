#include<vector>
#include<iostream>
#include<string>

#define endline cout << endl

using namespace std;
int n,m,b[2500],flag=0,ext = 0,shits=0,a[2500][2500]={0};
void connect(int fat,int son);
bool c_connect(int fat,int son);
void print();

int main(){

	string a;

	cin >> n >> m;


	for(int i = 0; i < n; i++){
		cin >> a;		
		for(int j = 0; j < m; j++){
			if(a.substr(j,1) == "#") {b[i*m+j] = i*m+j;shits++;}
			else b[i*m+j] = -1;
		}
	}


	//horizontal
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m-1; j++)
			if(b[i*m+j]!=b[i*m+j+1]&&b[i*m+j]!=-1&&b[i*m+j+1]!=-1)
				connect(i*m+j,i*m+j+1);

	//vertical
	for(int i = 0; i < n-1; i++)
		for(int j = 0; j < m; j++)
			if(b[i*m+j]!=b[i*m+j+m]&&b[i*m+j]!=-1&&b[i*m+j+m]!=-1)
				connect(i*m+j,i*m+j+m);

	//rightbottom
	for(int i = 0; i < n-1; i++)
		for(int j = 0; j < m-1; j++)
			if(b[i*m+j]!=b[i*m+j+m+1]&&b[i*m+j]!=-1&&b[i*m+j+m+1]!=-1)
				connect(i*m+j,i*m+j+m+1);


	//righttop
	for(int i = 0; i < n-1; i++)
		for(int j = 1; j < m; j++)
			if(b[i*m+j]!=b[i*m+j+m-1]&&b[i*m+j]!=-1&&b[i*m+j+m-1]!=-1)
				connect(i*m+j,i*m+j+m-1);
	print();
/*	//allin
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(b[i*m+j]!=-1)
				for(int k = 2; i+k<n||j+k<m; k++){
					if(j+k<m){					
						if(i-1>0&&b[i*m+j+k-m]!=-1)   if(c_connect(i*m+j,i*m+j+k-m)  ){ext+=k-2;break;}
						if(       b[i*m+j+k]!=-1)     if(c_connect(i*m+j,i*m+j+k)    ){ext+=k-2;break;}
						if(i+1<n&&b[i*m+j+k+m]!=-1)   if(c_connect(i*m+j,i*m+j+k+m)  ){ext+=k-2;break;}
					}
					if(i+k<n){
						if(j-1>0&&b[(i+k)*m+j-1]!=-1) if(c_connect(i*m+j,(i+k)*m+j-1)){ext+=k-2;break;}
						if(       b[(i+k)*m+j  ]!=-1) if(c_connect(i*m+j,(i+k)*m+j)  ){ext+=k-2;break;}
						if(j+1<m&&b[(i+k)*m+j+1]!=-1) if(c_connect(i*m+j,(i+k)*m+j+1)){ext+=k-2;break;}
					}
				}

	//hori
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m-2; j++)
			if(b[i*m+j]!=-1)
				for(int k = j+2; k < m; k++){
					if(i-1>0&&b[i*m+k-m]!=-1){c_connect(i*m+j,i*m+k-m);ext+=k-j-2;break;}
					if(       b[i*m+k]!=-1)  {c_connect(i*m+j,i*m+k);  ext+=k-j-2;break;}
					if(i+1<n&&b[i*m+k+m]!=-1){c_connect(i*m+j,i*m+k+m);ext+=k-j-2;break;}
				}
	//vert
	for(int i = 0; i < n-2; i++)
		for(int j = 0; j < m; j++)
			if(b[i*m+j]!=-1)
				for(int k = i+2; k < n; k++){
					if(j-1>0&&b[k*m+j-1]!=-1){c_connect(i*m+j,k*m+j-1);ext+=k-i-2;break;}
					if(       b[k*m+j  ]!=-1){c_connect(i*m+j,k*m+j);  ext+=k-i-2;break;}
					if(j+1<m&&b[k*m+j+1]!=-1){c_connect(i*m+j,k*m+j+1);ext+=k-i-2;break;}
				}
*/
//	print();
	cout << shits<<"\n" << flag << " " <<ext+flag;
	return 0;
}

void print(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++)
			{cout.width(3);cout << b[i*m+j];}
		endline;
	}
	endline;
}
void connect(int fat,int son){

	while(b[b[fat]]!=fat) fat = b[fat] = b[b[fat]];
	while(b[b[son]]!=son) son = b[son]= b[b[son]];
	if(b[fat]!=b[son]){
		b[son] = b[fat];
		shits--;
	}
}
bool c_connect(int fat,int son){
	while(b[b[fat]]!=fat) fat = b[b[fat]];
	while(b[b[son]]!=son) son = b[b[son]];
	if(b[fat]!=b[son]){
		b[son] = b[fat];
		flag++;
		return true;
	}
	return false;
}
