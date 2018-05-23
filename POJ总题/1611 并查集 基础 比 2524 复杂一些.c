#include<stdio.h>
int father[30001];
int son[30001];
int find(int x)
{
	return  x ==father[x] ? x : find(father[x]);
 } 
 void merge(int a,int b)
{
 	int x = find(a);
	int y = find(b);
	if (x != y)
	{
		father[y] = x;
		son[x] += son[y];
	}
}
int main()
{
	int qq[30001];
	int i,j;
	int n,m;
	int z;
	while(scanf("%d%d",&n,&m),n+m)
	{
		for (i = 0 ; i < n ;i++)
		{
			father[i] = i;
			son[i] = 1;
		}
		for( i = 0 ;i < m ;i++)
		{
			scanf("%d",&z);
			for ( j = 0;j < z;j++)
			{
				scanf("%d",&qq[j]);
				if(j != 0)
				merge(qq[j-1],qq[j]);
			}
		}
		printf("%d\n",son[find(0)]);
	}
	return 0;
}