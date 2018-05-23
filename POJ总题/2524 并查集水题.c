#include<stdio.h>
int father[50001];
int find(int p)
{
	return p == father[p] ? p : (father[p] = find(father[p]));
}
void merge(int a,int b)
{
	int x = find(a);
	int y = find(b);
	if (x != y)
	father[y] = x;
}
int main()
{
		int m,n;
		int i;
		int a,b;
		int q;
		int num = 0;
		while(scanf("%d%d",&n,&m))
		{
			num++;
			q = 0;
			if(n == 0 && m == 0)
			break;
			for(i = 1;i <= n;i++)
			father[i]=i;
			for (i = 0; i < m;i++)
			{
					scanf("%d%d",&a,&b);
					merge(a,b);
			}
			for (i = 1;i <= n;i++)
			{
				if(father[i] == i)
				q++;
			}
			printf("Case %d: %d\n",num,q);
		}
		return 0;
} 