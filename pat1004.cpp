/* ***********************************************
Author :Chord
Email:pengrj2018@gmail.com
Created Time :2019/9/27 14:46:27
File Name :c:\Localproject\2019Autumn\pat1004.cpp
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
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
const int maxn = 1e5 + 7;
vector<int>tree[maxn];
int n,m;
int F[maxn];
void init(void){
	memset(F,0,sizeof F);
	for(int i = 0 ; i < maxn ; i++)
		tree[i].clear();
}

int read(void){
	cin>>n
	if(n == 0) return 0;
	cin>>m;
	while(m--){
		int root;
		cin>>root;
		int k;
		cin>>k;
		for(int i = 0 ; i < k ; i++){
			int id;
			cin>>id;
			tree[root].push_back(id);
		}
	}
	return 1;
}


void find(int level,int root){
	if((int))tree[root].size == 0){
		F[level]++;
		return;
	}
	for(int i = 0 ; i < (int)tree[root].size() ; i++){
		find(level+1,tree[root][i]);
	}
}

void write(void){
	for(int i = 1 ; i <= n ; i++)
		cout<<F[i]<<(i == n ? '\n' : ' ')<<endl;
}
void solve(void)
{
	 while(read()){
	 	find();
		write();
	 }
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
 
 	return 0;
}
