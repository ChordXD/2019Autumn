/* ***********************************************
Author :Chord
Email:pengrj2018@gmail.com
Created Time :2019/10/11 9:16:29
File Name :pat1018.cpp
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
const int maxn = 5e2 + 7;
#define EPS 1e-9
const int INF = 0x3f3f3f3f;
int n,m,d[maxn],ok,Exaim;
typedef struct GI{
	int end,val;
	GI(int e,int v){
		end = e;
		val = v;
	}
}GI;

vector<GI>G[maxn];
vector<int>minF[maxn];

void dijstra(void){
	for(int i = 0 ; i <= n ; i++)
		d[i] = INF;
	d[0] = 0;
	priority_queue<pair<int,int> >p;
	p.push(make_pair(-d[0],0));
	while(!p.empty()){
		auto t = p.top();
		p.pop();
		int /*val = t.first,*/poi = t.second;
		for(int i = 0,aimpoi,aimVal; i <(int)G[poi].size() ; i++){
			aimpoi = G[poi][i].end;
			aimVal = G[poi][i].val;
			if(d[aimpoi] > d[poi] + aimVal){
				minF[aimpoi].clear();
				minF[aimpoi].push_back(poi);
				d[aimpoi] = d[poi] + aimVal;
				p.push(make_pair(-d[aimpoi],aimpoi));
			}else if(d[aimpoi] == d[poi] + aimVal){
				p.push(make_pair(-d[aimpoi],aimpoi));
				minF[aimpoi].push_back(poi);
			}
		}
	}
}

void solve(void){

}

int main()
{
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
 
 	return 0;
}
