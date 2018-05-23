这是自己打的  结果第一次就wa了
一直没有找到原因  
后来才发现 原来是 数组开小了一个数
原来开成 了 1001
其实开成1002  就能过
#include<stdio.h>
#include<string.h>
int d;
struct node
{
	int father;
	int xi,yi;
}p[1011];
int find(int x)
{
	return x == p[x].father ? x : find(p[x].father);
}
void merge(const node p1,const node p2)
{
	int x = find(p1.father);
	int y = find(p2.father);
	if(x != y)
		if((p1.xi - p2.xi)*(p1.xi - p2.xi) + (p1.yi - p2.yi)*(p1.yi - p2.yi) <= d*d)
		p[y].father = x;
}
int main()
{
	int num,i,n,m;
	bool ok[1011];
	char pp;
	memset(ok,0,sizeof(ok));
	scanf("%d%d",&num,&d);
	for(i = 1;i <= num ;i++)
	p[i].father = i;
	for ( i = 1; i <= num ;i++)
		scanf("%d%d",&p[i].xi ,&p[i].yi);
	while(scanf("\n%c",&pp)!=EOF)
	{
		if(pp == 'O')
		{
			scanf("%d",&n);
			ok[n] = 1;
			for ( i = 1; i <= num ;i++)
				if(ok[i]&& i != n)
				merge(p[i],p[n]);
		}
		else 
		{
			scanf("%d%d",&m,&n);
			if(find(m) == find(n))
			printf("SUCCESS\n");
			else printf("FAIL\n");
		}
	}
	return 0;	
} 







#include<string.h>
#include<stdio.h>
#define N 1110
int d;
bool use[N];

struct node
{
	int pre;
	int x, y;
}p[N];

int find(int x)
{
	return x == p[x].pre ? x : find(p[x].pre);
}

void join(const node p1, const node p2)
{
	int root1, root2;
	root1 = find(p1.pre);
	root2 = find(p2.pre);
	if(root1 != root2)
		if((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) <= d * d)
			p[root2].pre = root1;
}

int main()
{
	//freopen("Input.txt", "r", stdin);
	int num;
	char ope;
	int ok;
	int from, to;
	scanf("%d%d", &num, &d);
	for(int i = 1; i <= num; ++i)
		p[i].pre = i;
	memset(use, false, sizeof(use));
	for(int i = 1; i <= num; ++i)
		scanf("%d%d", &p[i].x, &p[i].y);
	while(scanf("\n%c", &ope) != EOF)
	{
		if(ope == 'O')
		{
			scanf("%d", &ok);
			use[ok] = true;
			for(int i = 1; i <= num; ++i)
				if(use[i] && i != ok)
					join(p[i], p[ok]);
		}
		else
		{
			scanf("%d%d", &from, &to);
			if(find(from) == find(to))
				printf("SUCCESS\n");
			else
				printf("FAIL\n");
		}
	}
	return 0;
}