#include<iostream>
using namespace std;

int main(){
	int n=0,f[20]={0},a[20],q=0,p,Max=0;
	bool b[20];
	while(cin >> a[n]){b[n] = 1;n++;}
	p = a[0];
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < i ; j++)
			f[i] = a[j] > a [i] ? (f[j] > f[i]?f[j]:f[i]) : f[i];
		if(b[i]){
			q++;
			p = a[i];
			for(int j = i + 1;j < n;j++) if(b[j] && a[j] < p) {p = a[j];b[j] = 0;}
		}
	f[i]++;
	Max = Max > f[i]?Max:f[i];
	}
	cout << Max <<"\n"<< q;
	return 0;
}
