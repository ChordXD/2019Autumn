/* ***********************************************
Author :Chord
Email:pengrj2018@gmail.com
Created Time :2019/10/8 8:21:18
File Name :
************************************************ */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <stack>
#include <bitset>
#include <iomanip>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 7;
#define EPS 1e-9

struct man{
	int starTime,processTime;
	void manCin(void){
		int h,m,c,pt;
		scanf("%d:%d:%d %d",&h,&m,&c,&pt);
		starTime = h * 60 * 60 + m * 60 + c;
		processTime = pt * 60;
	}
	bool operator < (const man &t) const{
		return starTime < t.starTime;
	}
};

vector<man> read(void){
	int n,w;
	scanf("%d%d",&n,&w);
	vector<man>p(n);
	for(int i = 0 ; i < n ; i++){
		p[i].manCin();
	}
	sort(p.begin(),p.end());
	return p;
}

void solve(void){
 
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
 
 	return 0;
}
