
题目也是比较醉的  
并查集的应用。重点在于考虑情况要全。
      1: 0 0  空树是一棵树 (自己就卡在这里)
      2: 1 1 0 0  不是树 不能自己指向自己
      2: 1 2 1 2 0 0  不是树 自己开始一直在这么WA  好郁闷 重复都不行呀~~5555
      2: 1 2 2 1 0 0  也是错误的
      （2类归纳为：节点不能指向自己集合的任一元素）
      3: 1 2 2 3 4 5  不是树 森林不算是树


还有一些初始化的问题  需要十分注意啊

#include<stdio.h>
#include<string.h>
int ok[5100];
int father[5100];
int find(int x)
{
	return x == father[x] ? x :find(father[x]);
} 
int merge(int a,int b)
{
	int x = find(a);
	int y = find(b);
	if(father[b] != b)
	return 0;
	if(x != y && father[a] != b)
	{
	father[b]=a;
	return 1;
	}
	else return 0;
}
int main()
{
	int n,m,i;
	int judge = 1;
	int num = 0;
	int k = 1,z;
		for (i = 0;i <= 5100 ;i++)
			father[i] = i;
			memset(ok,0,sizeof(ok));
	while(scanf("%d%d",&n,&m))
	{
		if(n < 0&&m < 0)break;
		if(n == 0 && m == 0)
		{
			z=0;
			for (i = 0 ;i <= 5100 ;i++)
			{
				if (ok[i] == 1)
				{
				z = find(i);
				break;
				}
			}
			
			for (i =0 ;i <= 5100 ;i++)
			{
				if(ok[i] == 1&&find(i) != z)
				judge = 0;
			}
			num++;
			if(judge != 0&&k != 0) printf("Case %d is a tree.\n",num);
			else printf("Case %d is not a tree.\n",num);
			judge = 1;
			for (i = 0;i <= 5100 ;i++)
			father[i] = i;
			memset(ok,0,sizeof(ok));
			k =1;
			continue;
		}
		ok[n] = 1;
		ok[m] = 1;
 		judge = merge(n,m);
		if(judge == 0)
		k = 0;
	}
	return 0;
}