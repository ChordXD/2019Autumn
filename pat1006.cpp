/* ***********************************************
Author :Chord
Email:pengrj2018@gmail.com
Created Time :2019/9/28 13:01:23
File Name :pat1006.cpp
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

typedef struct man{
	char name[300];
	int hstart,mstart,sstart,hend,mend,send;
}man;

bool cmpstart(man a,man b){
	if(a.hstart == b.hstart){
		if(a.mstart == b.mstart){
			return a.sstart < b.sstart;
		}
		return a.mstart < b.mstart;
	}
	return a.hstart < b.hstart;
}

bool cmpend(man a,man b){
	if(a.hend == b.hend){
		if(a.mend == b.mend){
			return a.send > b.send;
		}
		return a.mend > b.mend;
	}
	return a.hend > b.hend;
}

man a[maxn];
int n;

void read(void){
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i++){
		scanf("%s %d:%d:%d %d:%d:%d",&a[i].name,&a[i].hstart,&a[i].mstart
				,&a[i].sstart,&a[i].hend,&a[i].mend,&a[i].send);
	}
}

void write(void){
	sort(a,a+n,cmpstart);
	printf("%s ",a[0].name);
	sort(a,a+n,cmpend);
	printf("%s",a[0].name);
}

void solve(void)
{
	read();
	write();
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
 
 	return 0;
}
