#include<vector>
#include<iostream>
#define endline cout << endl

using namespace std;
int n,m;


class route{

public:
	int size();
	void sort();
	void add(int val, int p);
	void shrink();

	vector<int> val;
	vector<int> track;
private:
	void qs(int l,int r);

};

point a[500];

int main(){

	int p,q,r;
	cin >> n >> m;

	for(int i = 0; i < m; i++){
		cin >> p >> q >> r;
		p--;q--;
		a[p].add(r,q);
		a[q].add(r,p);
	}

	for(int i = 0; i < n; i++){
		a[i].sort();
		for(int j = 0;j<a[i].track.size();j++) cout << i+1 << " " << a[i].track[j]+1 << " " << a[i].route[j] << endl;
		endline;
	}
	
}
int point::size(){
	return route.size();
}

void point::add(int val,int p){
	route.push_back(val);
	track.push_back(p);
}

void point::sort(){
	qs(0,route.size()-1);
}


void point::qs(int l,int r){
	if(l >= r) return;
	int i = l,j = r;
	int x = route[i],y = track[i];
	 
	while(i < j)
	{
		while(i < j && route[j] >= x) j--;
		route[i] = route[j];
		track[i] = track[j];
		while(i < j && route[i] <= x) i++;
		route[j] = route[i];
		track[j] = track[i];
	}
	route[i] = x;
	track[i] = y;
	qs(l, i-1);
	qs(i+1, r);
}
