/* ***********************************************
Author :Chord
Email:pengrj2018@gmail.com
Created Time :2019/9/28 17:30:11
File Name :pat1009.cpp
************************************************ */
#include <iomanip>
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
double ans[maxn];
bool check[maxn];
int num;
#define EPS 1e-5
void read(void){
	int t,a;
	double b;
	cin>>t;
	vector<pair<int,double>>p;
	for(int i = 0 ; i < t; i++){
		cin>>a>>b;
		p.push_back(make_pair(a,b));
	}
	cin>>t;
	for(int i = 0 ; i < t ; i++){
		cin>>a>>b;
		for(auto it : p){
			int index = a + it.first;
			ans[index] += b * it.second;
		}
	}
	for(int i = 0 ; i < 5000 ; i++)
		if(fabs(ans[i]) > EPS){
			num++;
			check[i] = true;
		}
}

void write(void){
	cout<<num;
	for(int i = 5000 ; i >= 0 ; i--){
		if(check[i])
			cout<<' '<<i<<' '<<fixed<<setprecision(1)<<ans[i];
	}
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
