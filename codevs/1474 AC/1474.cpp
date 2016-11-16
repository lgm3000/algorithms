#include<iostream>
using namespace std;

char trans(int q){
	switch(q){
	case 0:
		return '0';	

	case 1:
		return '1';	

	case 2:
		return '2';	

	case 3:
		return '3';	

	case 4:
		return '4';	

	case 5:
		return '5';	

	case 6:
		return '6';	

	case 7:
		return '7';	

	case 8:
		return '8';	

	case 9:
		return '9';	

	case 10:
		return 'A';	

	case 11:
		return 'B';	

	case 12:
		return 'C';	

	case 13:
		return 'D';	
	case 14:
		return 'E';	
	case 15:
		return 'F';	
	}

}

int main(){
	int n,i=0,m,a[1000]={0};
	cin >> n >> m;
	while(n!=0){
		a[i] = n%m;
		n -= a[i];
		n /= m;
		i++;
	}
	for(i=i-1;i>=0;i--) cout << trans(a[i]);

return 0;
}
