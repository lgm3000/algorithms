#include<iostream>
#include<vector>
using namespace std;

class HDnum{
public:
	void init();


	HDnum operator + (const HDnum& op);
	HDnum operator + (int op);


	HDnum& operator += (const HDnum& op);
	HDnum& operator += (int op);

	HDnum& operator = (const HDnum& op);
	HDnum& operator = (int op);

	HDnum operator * (int op);
	HDnum operator * (const HDnum& op);

	bool operator > (const HDnum& op);

	friend ostream& operator<< (ostream &os,const HDnum &st){  
		if(st.a.size() == 0) os << 0;
        	else for(int i = st.a.size()-1; i >= 0; i--)
			os << st.a[i];
	        return os;
	}  

private:
	vector<unsigned int> a;

};


int main(){
	int a[80][80],tmp,fin = 0;
	int n,m;
	HDnum tst[41][41];
	HDnum fintst;
	cin >> n >> m;
	for(int i = 0; i < n;i++)
		for(int j = 0; j < m;j++){cin >> tmp;
			a[i][j] = tmp;}

	for(int k = 0; k<n;k++){
		HDnum Maxtst;
		for(int i =1;i<=m;i++){
			tst[0][i] = tst[0][i-1] + a[k][m-i] * (1<< i);
			tst[i][0] = tst[i-1][0] + a[k][i-1] * (1<< i);
			for(int j = 1; j < i;j++){
//				cout << tst[j-1][i-j] <<" "<<(1<<i)*a[k][j-1]<<"<>"<<tst[j][i-j-1] <<" " << (1<<i) * a[k][m - i + j]<<endl;
				tst[j][i-j] = tst[j-1][i-j] + (1<<i) * a[k][j-1] > tst[j][i-j-1] + (1<<i) * a[k][m - i + j] ?
					      tst[j-1][i-j] + (1<<i) * a[k][j-1] : tst[j][i-j-1] + (1<<i) * a[k][m - i + j];
			}
		}
		/*for(int i =0;i<=m;i++){
			for(int j = i; j >= 0;j--)
				cout << "tst["<<j<<"]["<<i-j<<"]"<<tst[j][i-j]<<" ";
			cout << endl;
		}*/
		for(int j = 0; j<=m;j++)
			//if(tst[j][m-j] > Maxtst){cout << Maxtst << "->" <<tst[j][m-j]<<endl;Maxtst = tst[j][m-j];}else cout << Maxtst << "!->" <<tst[j][m-j]<<endl;
			Maxtst = tst[j][m-j] > Maxtst? tst[j][m-j] : Maxtst;
		fintst = fintst + Maxtst;
	}

	cout << fintst;
/*
	for(int k = 0; k<n;k++){
		int f[42][42]={0},Max = 0;
		for(int i =1;i<=m;i++){
			f[0][i]=f[0][i-1] + (1<<i) * a[k][m-i];
			f[i][0]=f[i-1][0] + (1<<i) * a[k][i-1];
			for(int j = 1; j < i;j++)
				f[j][i-j] = f[j-1][i-j] + (1<<i) * a[k][j-1] > f[j][i-j-1] + (1<<i) * a[k][m - i + j ] ?
					    f[j-1][i-j] + (1<<i) * a[k][j-1] : f[j][i-j-1] + (1<<i) * a[k][m - i + j ];
		}
		for(int i =0;i<=m;i++){
			for(int j = i; j >= 0;j--)
				cout << "f["<<j<<"]["<<i-j<<"]"<<f[j][i-j]<<" ";
			cout << endl;
		}
		for(int j = 0; j<=m;j++)Max = f[j][m-j] > Max? f[j][m-j] : Max;
		fin+=Max;
		cout << Max;
	}
	cout << fin;
*/
	return 0;

}

HDnum HDnum::operator * (int op){
	HDnum tmp;
	int c = 0;
	for(int i = 0;i < a.size();i++){
		tmp.a.push_back(op * a[i]+ c);
		c = tmp.a[i]/10;
		tmp.a[i] %= 10;
	}
	while(c>0){
		tmp.a.push_back(c%10);
		c /= 10;
	}
	return tmp;
}

HDnum HDnum::operator + (const HDnum& op){
	HDnum tmp;
	int c = 0;
	int i;
	if(a.size() < op.a.size()){
		for(i = 0;i < a.size();i++){
			tmp.a.push_back(op.a[i] + a[i]+ c);
			c = tmp.a[i]/10;
			tmp.a[i] %= 10;
		}
		for(;i<op.a.size();i++) {
			tmp.a.push_back(op.a[i] + c);
			c = tmp.a[i]/10;
			tmp.a[i] %= 10;
		}
		if(c > 0) tmp.a.push_back(1);
	}else{
		for(i = 0;i < op.a.size();i++){
			tmp.a.push_back(op.a[i] + a[i]+ c);
			c = tmp.a[i]/10;
			tmp.a[i] %= 10;
		}
		if(a.size() == op.a.size() && c > 0) tmp.a.push_back(c);
		else{
			for(;i<a.size();i++) {
				tmp.a.push_back(a[i] + c);
				c = tmp.a[i]/10;
				tmp.a[i] %= 10;
			}
			if(c > 0) tmp.a.push_back(1);
		}
	}
	return tmp;
}
HDnum HDnum::operator + (int op){
	HDnum tmp;
	int c = 0;
	for(int i = 0;i < a.size();i++){
		tmp.a.push_back(op%10 + a[i]+ c);
		c = tmp.a[i]/10;
		tmp.a[i] %= 10;
		op /=10;
	}
	while(op+c > 0){
		int temp = op%10 + c;
		c = temp/10;
		temp %= 10;
		tmp.a.push_back(temp);
		op /= 10;
	}
	return tmp;
}


bool HDnum::operator > (const HDnum& op){
	if(a.size() == op.a.size())
		for(int i = a.size()-1;i>=0;i--)
			if(a[i] > op.a[i]) return 1;
			else {if(a[i] < op.a[i]) return 0;}
	else if(a.size() > op.a.size()) return 1;
	return 0;

}
HDnum& HDnum::operator = (const HDnum& op){
	a = op.a;
	return *this;
}
HDnum& HDnum::operator = (int op){
	while(op > 0){
		a.push_back(op%10);
		op /=10;
	}
	return *this;
}

HDnum& HDnum::operator += (int op){
	int c = 0;
	if(op == 0) return *this;
	for(int i = 0;i < a.size();i++){
		a[i] = op%10 + a[i]+ c;
		c = a[i]/10;
		a[i] %= 10;
		op /=10;
	}
	while(op > 0){
		int temp = op%10 + c;
		c = temp/10;
		temp %= 10;
		a.push_back(temp);
		op /= 10;
	}
	return *this;
}
HDnum& HDnum::operator += (const HDnum& op){
	int c = 0,i;
	if(a.size() < op.a.size()){
		for(i = 0;i < a.size();i++){
			a[i] = op.a[i] + a[i]+ c;
			c = a[i]/10;
			a[i] %= 10;
		}
		for(;i<op.a.size();i++) {
			a.push_back(op.a[i] + c);
			c = a[i]/10;
			a[i] %= 10;
		}
	}else{
		for(i = 0;i < op.a.size();i++){
			a[i] = op.a[i] + a[i]+ c;
			c = a[i]/10;
			a[i] %= 10;
		}
		if(a.size() == op.a.size() && c > 0) a.push_back(c);
		else{
			for(;i<a.size();i++) {
				a.push_back(a[i] + c);
				c = a[i]/10;
				a[i] %= 10;
			}
		}
	}
	return *this;
}
