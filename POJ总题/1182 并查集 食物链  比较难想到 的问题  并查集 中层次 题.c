在书上 88 页 有原题  思路不错啊

#include<stdio.h>
int father[150010];
int ans,n,m,i;
int find(int x)
{
	if(father[x] == x)
	return x;
	else return father[x] = find(father[x]);
}
int merge(int x,int y)
{
	int a = find(x);
	int b = find(y);
	if(a != b)
	father[a] = b;
}
void init()
{
	ans = 0;
	for( i = 1;i <= 3*n ;i++)
	father[i] = i;
}
int main()
{
	int d,x,y;
	scanf("%d%d",&n,&m);
	init();
	while(m--)
	{
		scanf("%d%d%d",&d,&x,&y);
		if(x > n||x <= 0||y > n||y <= 0)
		{
			ans++;
			continue;
		}
		if (d == 1)
		{
			if (find(x) == find (y+n)||find(x) == find(y+2*n) )
				ans++;
			else
			{
				merge(x,y);
				merge(x+n,y+n);
				merge(x+2*n,y+2*n);
			}
		}
		else 
		{
			if(find(x) == find(y) ||find(x) == find(y+2*n) )
				ans++;
			else
			{
				merge(x,y+n);
				merge(x+n,y+2*n);
				merge(x+2*n,y);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
 } 

