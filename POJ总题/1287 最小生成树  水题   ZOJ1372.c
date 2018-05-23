#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#include<string.h>
int father[51];
struct Road
{
	int x,y,cost;
}road[2500];
int cmp(Road x,Road y)
{
	return x.cost < y.cost;
}
int find(int x)
{
	if(x != father[x])
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
int main()
{
	int n,m,i,j,ans;
	while(scanf("%d",&n),n)
	{
		for (i = 0 ;i <= 50;i++)
		father[i] = i;
		memset(road,-1,sizeof(road));
		ans = 0;
		j = 1;
		scanf("%d",&m);
		for (i = 0;i < m;i++)
		scanf("%d%d%d",&road[i].x,&road[i].y,&road[i].cost);
		sort(road,road+m,cmp);
		for( i = 0;i < m;i++)
		{
			if(merge(road[i].x,road[i].y))
			{
				ans +=road[i].cost;
				j++;
			}
			if(j == n)
			break;
		}
		printf("%d\n",ans);
	}
	return 0;
}