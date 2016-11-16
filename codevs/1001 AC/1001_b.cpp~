#include<vector>
#include<iostream>
#include<cstdio>

using namespace std;
class UnionElement{
public:
	bool is_sameUni(int a,int b){
		while(uni[uni[a]]!=a){a = uni[a] = uni[uni[a]];}
		while(uni[uni[b]]!=b){b = uni[b] = uni[uni[b]];}
		if(uni[a]!=uni[b]) return false;
		else return true;
	}


	void fuseUnion(int a,int b){
		while(uni[uni[a]]!=a){a = uni[a] = uni[uni[a]];}
		while(uni[uni[b]]!=b){b = uni[b] = uni[uni[b]];}
		if(uni[a]!=uni[b]) uni[b] = uni[a];
	}
	void initiate(int n){
		for(int i = 0;i<n;i++) uni[i] = i;
	}
private:

	int uni[500];
};



class route{

public:
	int size();
	void sort();
	void add(int value, int p,int q);
	void shrink();

	vector<int> val;
	vector<int> p1;
	vector<int> p2;
private:
	void qs(int l,int r);

};

bool is_larger(int ta,int ba,int tb,int bb);
int gys(int a, int b);
int main(){
	route a;
	UnionElement b;
	int n,m;
	int p,q,r,top=1,bottom=0;
	cin >> n >> m;

	for(int i = 0; i < m; i++){
		cin >> p >> q >> r;
		a.add(r,p-1,q-1);
	}
	a.sort();
	cin >> p >> q;
	p--;q--;
	for(int i = 0; i < m; i++){

		b.initiate(n);
		int j = i;
		while(!b.is_sameUni(p,q) && j < m){
			b.fuseUnion(a.p1[j],a.p2[j]);
			j++;
		}
		if(!b.is_sameUni(p,q)){ if(j==m)break;}
		else if(is_larger(top,bottom,a.val[j-1],a.val[i])) {top = a.val[j-1];bottom = a.val[i];}
	}
	if(bottom == 0) cout << "IMPOSSIBLE";
	else {
		int t = gys(top,bottom);
		if(bottom/t == 1) cout << top/t;
		else cout << top/t <<"/" << bottom/t;
	}
	return 0;
	
}
bool is_larger(int ta,int ba,int tb,int bb){
	return ta*bb > ba*tb;
}
int gys(int a, int b){
	int t;
	while(t = a%b){
		a = b;
		b = t;
	}
	return b;
}
int route::size(){
	return val.size();
}

void route::add(int value,int p,int q){
	val.push_back(value);
	p1.push_back(p);
	p2.push_back(q);
}

void route::sort(){
	qs(0,val.size()-1);
}


void route::qs(int l,int r){
	if(l >= r) return;
	int i = l,j = r;
	int x = val[i],y = p1[i],z = p2[i];
	 
	while(i < j)
	{
		while(i < j && val[j] > x) j--;
		val[i] = val[j];
		p1[i] = p1[j];
		p2[i] = p2[j];
		while(i < j && val[i] <= x) i++;
		val[j] = val[i];
		p1[j] = p1[i];
		p2[j] = p2[i];
	}
	val[i] = x;
	p1[i] = y;
	p2[i] = z;
	qs(l, i-1);
	qs(i+1, r);
}
