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

struct cus{
	char a[40];
	bool onLineFlag;
	int mounth,day,hour,min;
	void getCus(void){
		char flag[20];
		scanf("%s %d:%d:%d:%d %s",a,&mounth,&day,&hour,&min,flag);
		if(flag[1] == 'n') onLineFlag = true;
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
		cost = lastingTime = 0;

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

void print(vector<record>now){
	if((int)now.size() == 0) return;
	printf("%s %02d\n",now[0].start.a,now[0].start.mounth);
	int n = (int)now.size();
	int total = 0;
	for(int i = 0 ; i < n ; i++){
		printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",
				now[i].start.day,now[i].start.hour,now[i].start.min,
				now[i].end.day,now[i].end.hour,now[i].end.min,
				now[i].lastingTime,(double)now[i].cost / 100.0);
		total += now[i].cost;
	}
	printf("Total amount: $%.2f\n",(double)total/100.0);
}

void toSolveOneCusOneMounth(vector<cus>p){
	int n = p.size();
	vector<record>ans;
	if(n <= 1) return;
	for(int i = 0 ; i < n - 1 ; i ++){
		if(p[i].onLineFlag && !p[i+1].onLineFlag){
			ans.push_back(record(p[i],p[i+1]));
		}
	}
	print(ans);
}

void toSolveOneCus(vector<cus>p){
	sort(p.begin(),p.end());
	int n = p.size();
	vector<cus>onMounth;
	onMounth.push_back(p[0]);
	for(int i = 1 ; i < n ; i++){
		if(p[i].mounth == p[i-1].mounth){
			onMounth.push_back(p[i]);
		}else{
			toSolveOneCusOneMounth(onMounth);
			onMounth.clear();
			onMounth.push_back(p[i]);
		}
	}
	toSolveOneCusOneMounth(onMounth);
}

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
	vector<cus>av8d;
	sort(t.begin(),t.end(),sortBySting);
	for(int i = 0 ; i < n ; i++){
		if(i == 0){
			av8d.push_back(t[i]);
		}else{
			if(strcmp(t[i].a,t[i-1].a) == 0){
				av8d.push_back(t[i]);
				if(i == n-1)
					toSolveOneCus(av8d);
			}else{
				toSolveOneCus(av8d);
				av8d.clear();
				av8d.push_back(t[i]);
			}	
		}
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	solve();
 
 	return 0;
}
