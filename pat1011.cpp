/* ***********************************************
Author :Chord
Email:pengrj2018@gmail.com
Created Time :2019/10/3 22:37:12
File Name :pat1011.cpp
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

pair<double,char> selectTree(double a,double b,double c){
	double ans1;
	char ans2;
	if(a > b){
		ans1 = a;
		ans2 = 'W';
	}else {
		ans1 = b;
		ans2 = 'T';
	}

	if(c > ans1){
		ans1 = c;
		ans2 = 'L';
	}
	return make_pair(ans1,ans2);
}

void solve(void){
	double ansnum = 1;
	double t1,t2,t3;
	char anschar[3];
	for(int i = 0 ; i < 3 ; i ++){
		cin>>t1>>t2>>t3;
		auto p = selectTree(t1,t2,t3);
		anschar[i] = p.second;
		ansnum *= p.first;
	}
	ansnum *= 0.65;
	ansnum -= 1.0;
	ansnum *=2;
	cout<<anschar[0]<<' '<<anschar[1]<<' '<<anschar[2]<<' '<<fixed<<setprecision(2)<<ansnum;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
 
 	return 0;
}
