/* ***********************************************
Author :Chord
Email:pengrj2018@gmail.com
Created Time :2019/10/6 9:02:26
File Name :pat1016.cpp
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

int costExel[40];
int costOneDay;

struct cus{
	char a[40];
	bool onLineFlag;
	int mounth,day,hour,min;
	void getCus(void){
		char flag[20];
		scanf("%s %d:%d:%d:%d %s",a,&mounth,&day,&hour,&min,flag);
		if(flag[2] == 'n') onLineFlag = true;
		else onLineFlag = false;
	}
	bool operator < (const cus &t) const{
		if(mounth == t.mounth){
			if(day == t.day){
				if(hour == t.hour){
					return min < t.min;
				}
				return hour < t.hour;
			}
			return day < t.day;
		}
		return mounth < t.mounth;
	}
};

bool sortBySting(cus a,cus b){
	return strcmp(a.a,b.a) < 0;
}

struct record{
	cus start,end;
	int cost,lastingTime;
	record (const cus ts,const cus te){
		strcpy(start.a,ts.a);
		strcpy(end.a,te.a);
		
		start.hour = ts.hour;
		start.day = ts.day;
		start.mounth = ts.mounth;
		start.min = ts.min;
		end.mounth = te.mounth;
		end.day = te.day;
		end.hour = te.hour;
		end.min = te.min;

		start.onLineFlag = end.onLineFlag;
		cltCost();
	}
	void cltCost(void){
		int clock = 0;
		while(clock < 24){
			int smin = start.day * 60;
			if(start.hour > clock) smin += 60;
			else if(start.hour == clock) smin += start.min;

			int emin = end.day * 60;
			if(end.hour > clock) emin += 60;
			else if(end.hour == clock) emin += end.min;

			int righTm = emin - smin;
			cost += righTm * costExel[clock];
			clock++;
			lastingTime += righTm;
		}
	}
};

void solve(void){
	for(int i = 0 ; i < 24 ; i++)
		cin>>costExel[i];
	vector<cus>t;
	int n;
	cin>>n;
	for(int i = 0 ; i < n ; i++){
		cus tt;
		tt.getCus();
		t.push_back(tt);
	}
	sort(t.begin(),t.end(),sortBySting);
	
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
 
 	return 0;
}
