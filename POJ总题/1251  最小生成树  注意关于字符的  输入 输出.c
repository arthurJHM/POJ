#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int father[30];
struct Road
{
	int a,b,cost;
}road[100];
int find(int  x)
{
	if(x !=father[x])
	return father[x] = find(father[x]);
	return x;
}
int merge(int x,int y)
{
	int a = find(x);
	int b = find(y);
	if( a != b)
	{
		father[a] = b;
		return 1;
	}
	return 0;
}
int cmp(Road x,Road y)
{
	return x.cost < y.cost;
}
int main()
{
	int n,m,j,k,g,ans,i;
	char c1[3],c2[3];
	while(scanf("%d",&n),n)
	{
		for(i = 0;i <= 29;i++)
		father[i] = i;
		k = 1 ;
		g = 1;
		ans = 0;
		memset(road,-1,sizeof(road));
		getchar();
		for( i = 1;i < n;i++)
		{
				scanf("%s%d",c1,&m);
				for( j = 1;j <= m;j++)
				{
					getchar();
					scanf("%s%d",c2,&road[k].cost);
					road[k].a = c1[0] -'A';
					road[k++].b = c2[0] - 'A';
 				}				
		}
	sort(road+1,road+k,cmp);
	for( i =1 ;i < k;i++)
	{
		if(merge(road[i].a,road[i].b))
		{
			ans +=road[i].cost;
			g++;
		}
		if(g == n )
		break;
	}
	printf("%d\n",ans);
	}
	return 0;
}




kruskal  Ëã·¨


#include<stdio.h>
#define M 28
#define min(a,b) a<b?a:b
const int INF = 99999999;
int map[M][M];
int visit[M];
int dis[M];
int main()
{
	int n,m;
	char l,h;
	int j,k,i;
	while(scanf("%d",&n),n)
	{
		for(i = 1;i <= n;i++)
			for(j = 1;j <= n;j++)
			map[i][j] = INF;
		for(i = 1;i < n;i++)
		{
			scanf(" %c%d",&l,&m);
			while(m--)
			{
				scanf(" %c%d",&h,&k);
				map[l-64][h-64] = map[h-64][l-64] = min(map[l-64][h-64],k);
			}
		}
		for(i = 1;i <= n;i++)
		dis[i] = map[1][i],visit[i] = 0;
		visit[1] = 1;
		int ans = 0;
		for(i = 1;i < n;i++)
		{
			int z;
			int min = INF;
			for(j = 1;j <= n;j++)
			{
				if(!visit[j]&&min >dis[j])
				{
					min = dis[j];
					z = j;
				}
			}
			visit[z] = 1;
			ans += min;
			for(j = 1;j <= n;j++)
			{
				if(!visit[j]&&dis[j] > map[z][j])
					dis[j] = map[z][j];
			}
		}		
		printf("%d\n",ans);	
	}
	return 0;
}