#include<iostream>
using namespace std;


int main(){
	int n, m,val,wgt,num,dVal[15],dWgt[15],v[200002]={0},count;

	cin >> n >> m;	


	for(int i = 0; i < n; i++){
		cin >> wgt >> val >> num;
		if(num==-1){
			for(int j = 1;j<=m;j++)
				if(j>=wgt)
					v[j] = (v[j-wgt] + val) > v[j] ? (v[j-wgt] + val) : v[j];
		} else{
			count = 0;
			for(int k = 1;k<=num;k<<=1){
				dVal[count] = val * k;
				dWgt[count] = wgt * k;
				num -= k;
				count++;
			}

			if(num>0){
				dVal[count] = val * num;
				dWgt[count] = wgt * num;
				count++;
			}
			for(int k = 0;k<count;k++)
				for(int j = m;j>=dWgt[k];j--)
					v[j] = (v[j-dWgt[k]] + dVal[k]) > v[j] ? v[j-dWgt[k]] + dVal[k] : v[j];

		}

	}

	cout << v[m];
	return 0;
}

