#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
int t[10] = {0},b[10][10]={0};
int check(int n){
int s=1;
for(int i=0;i<10;i++)
	if(b[n][i] == 1&& t[i] == 0){
		t[i] = 1;
		s += check(i);
	}
return s;
}


int main(){
string a;
int i,k,n,s;
char p;
unsigned long long x;
int key[10]={0};

cin >> a >> k;

for(i=0;i<k;i++){
	cin >> s >> n;
	b[s][n] = 1;
}
for(i=0;i<10;i++){
	t[i] = 1;
	key[i] = check(i);
	for(int j = 0;j<10;j++) t[j] = 0;
}
x = 1;
n = a.size();
//for(i=0;i<10;i++) cout << key[i];
for(i=0;i<n;i++){
	x*=key[a[i]-48];
}
cout << x;
return 0;
}

