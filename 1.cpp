#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
struct a {
	int p, n;
};

bool compare(const a &x, const a &y) {
    return x.p < y.p;
}

int main() {
	//freopen("data", "r", stdin);
	int tt, b, tp = 0;
	cin>>tt>>b;
	vector<a> aa(b);
	for(int i = 0; i < b; i++) {
		cin>>aa[i].p>>aa[i].n;
	}
	sort(aa.begin(), aa.end(), compare);
	/*for(int i = 0; i < b; i++) {
		cout<<aa[i].p<<" "<<aa[i].n<<endl;
	}*/
	int id = 0;
	while( tt > 0) {
		if(tt >= aa[id].n) {
			tp += ( aa[id].n *  aa[id].p);
			tt -= aa[id].n;
			id++;
		}
		else {
			tp += ( tt *  aa[id].p);
			tt = 0;
		}
	}
	cout<<tp<<endl;
}
