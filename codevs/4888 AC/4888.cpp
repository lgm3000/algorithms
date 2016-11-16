#include<iostream>
#include<vector>

using namespace std;

class item{
public:
	void add(int p,int q);
	void sort();
	int iLen(int i){return len[i];}
	int iWgt(int i){return w[i];}
private:
	void qsl(int l,int r);
	void qsw(int l,int r);
	vector<int> len;
	vector<int> w;

};

int main(){
	int n, p, q;
	bool b[1000];
	cin >> n;
	item ag;
	for(int i =0;i<n;i++) {cin >> p >> q;ag.add(p,q);}
	ag.sort();
	for(int i =0;i<n;i++) b[i] = true;
	q = 0;
	for(int i = 0;i<n;i++)
		if(b[i]){
			q++;
			p = ag.iWgt(i);
			for(int j = i+1;j<n;j++)
				if(b[j] && p < ag.iWgt(j)){
					b[j] = 0;
					p = ag.iWgt(j);
				}
		}
	cout << q;
	return 0;

}
void item::add(int p,int q){
	len.push_back(p);
	w.push_back(q);
}

void item::sort(){
	qsl(0,len.size()-1);
	int j;	
	for(int i = 0;i<len.size();i++)
		if(len[i] == len[i+1]){
			j = i;
			while(len[i] == len[j] && i < len.size()) i++;
			qsw(j,i-1);
		}
}
void item::qsw(int l,int r){
	if(l >= r) return;
	int i = l,j = r;
	int x = w[i],y = len[i];
	 
	while(i < j)
	{
		while(i < j && w[j] > x) j--;
		len[i] = len[j];
		w[i] = w[j];
		while(i < j && w[i] <= x) i++;
		len[j] = len[i];
		w[j] = w[i];
	}
	w[i] = x;
	len[i] = y;
	qsw(l, i-1);
	qsw(i+1, r);
}

void item::qsl(int l,int r){
	if(l >= r) return;
	int i = l,j = r;
	int x = len[i],y = w[i];
	 
	while(i < j)
	{
		while(i < j && len[j] > x) j--;
		len[i] = len[j];
		w[i] = w[j];
		while(i < j && len[i] <= x) i++;
		len[j] = len[i];
		w[j] = w[i];
	}
	len[i] = x;
	w[i] = y;
	qsl(l, i-1);
	qsl(i+1, r);
}
