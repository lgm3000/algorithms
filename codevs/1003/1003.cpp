#include<iostream>
using namespace std;
static int b[100][100],m=0,min,s=0,n,q;

int main(){
	int i,j;
	cin >> n;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin >> b[i][j];

	for(i=0;i<n;i++){
		min = 
		for(j=0;j<n;j++)
			if(b[i][j] == 0) j+=n+1;
			else if(b[i][j]<min){
				min = b[i][j];
				q = j;
			}
		if(j==n){
			a[m]=q;
			m++;
			s+=min;
		}
	}

	cout << m << s;
	return 0;
}
