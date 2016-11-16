#include<iostream>
#include<string>
#include<list>
using namespace std;
class node{
public:
	node(string newStr,int dep):stri(newStr),depth(dep){}
	string str(){return stri;}
	int depth;
private:
	string stri;
};


int main(){
	string a,b,end,rule[7],chan[7];
	int n = 0;
	list<node> tree;
	list<string> replic;
	cin >> a >> end;
	if(a == end) {cout << 0;return 0;}
	tree.push_back(node(a,0));
	replic.push_back(a);
	while(cin >> a >> b)
		if(a!=b){
			rule[n] = a;
			chan[n++] = b;
		}

	while(tree.size()>0){
		//cout << tree. front().str() << endl;
		for(int i = 0;i<n;i++){
			string newStr;

			for(int j =0;j<=int(tree.front().str().size() - rule[i].size());j++){
				//cout << tree.front().str().substr(j,rule[i].size()) << " " << rule[i] << endl;
				if(tree.front().str().substr(j,rule[i].size()) == rule[i]){

					newStr = tree.front().str().replace(j,rule[i].size(),chan[i]);
					list<string>::iterator it;
					for(it = replic.begin();it != replic.end();it++) if(newStr == *it) break;
					if(it==replic.end()){
						if(newStr == end){cout << tree.front().depth+1; return 0;}		

						tree.push_back(node(newStr,tree.front().depth+1));
						replic.push_back(newStr);
					}
				}
			}
		}
		//cout << tree.size();
		tree.pop_front();
	}
	cout <<"NO ANSWER!";
	return 0;

}


