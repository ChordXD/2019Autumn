/* ***********************************************
Author :Chord
Email:pengrj2018@gmail.com
Created Time :2019/10/4 18:23:06
File Name :pat1013.cpp
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
const int maxn = 1e3 + 7;
#define EPS 1e-9
bool vis[maxn];
vector<int>Map[maxn];
int n,m,q;
void dfs(int root){
	int n = Map[root].size();
	for(int i = 0 ; i < n ; i++)
		if(!vis[Map[root][i]]){
			vis[Map[root][i]] = 1;
			dfs(Map[root][i]);
		}
}
void solve(void){
	cin>>n>>m>>q;
	while(m--){
		int x,y;
		cin>>x>>y;
		Map[x].push_back(y);
		Map[y].push_back(x);
	}
	for(int i = 0 ; i < q ; i++){
		int t,tans = 0;
		cin>>t;
		memset(vis,0,sizeof vis);
		vis[t] = 1;
		for(int j = 1 ; j <= n ; j++ ){
			if(!vis[j]){
				tans++;
				dfs(j);
			}
		}
		cout<<tans - 1<<endl;
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
 
 	return 0;
}
