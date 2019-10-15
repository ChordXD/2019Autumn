#include<stdio.h>
const int maxn = 1007;
int Map[maxn][maxn];
int main(void){
	int n,m;
	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++)
			scanf("%d",&Map[i][j]);
	int Same = 0;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < m ; j++){
			int t;
			scanf("%d",&t);
			if(t == Map[i][j])
				Same++;
		}
	printf("%.2f",(double)Same/((double)n*(double)m) * 100.0);
	return 0;
}
