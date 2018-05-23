#include<stdio.h>
#include<string.h>
char map[15][15];
int visit[15];
int n,k;
int ans;
void dfs(int x,int c)
{
	int i,j; 
	if(c == k)
	{
		ans++;
		return;
	}
	for(i = x;i < n;i++)
		for(j = 0;j < n;j++)
		if(!visit[j]&&map[i][j] == '#')
		{
			visit[j] = 1;
			dfs(i+1,c+1);
			visit[j] = 0;		
		}
}
int main()
{
	while(~scanf("%d%d%*c",&n,&k)&&n != -1&&k != -1)
	{
		int i;
		ans = 0;
		memset(visit,0,sizeof(visit));
		for(i = 0;i < n;i++)
		gets(map[i]);
		dfs(0,0);
		printf("%d\n",ans);
	}
	return 0;
}


这道题目类似N皇后问题，与之不同的是每一行不一定有棋盘，所以dfs里要注意不一定是当前行。
思路很简单，只需从第一行第一个开始搜索，如果该位置该列没被标记且为棋盘，那么在这里放上棋子，并标记，因为每行每列不能冲突，所以搜索下一行，比并且棋子数加1。每次搜索之前先要判断是否棋子已经用完，如果用完，记录方案数加1，然后直接返回。直到所有搜索全部完成，此时已得到全部方案数。
此题还需注意标记数组仅仅标记某一列上是否有棋子，因为每次递归下一行，所以每一行不会有冲突，只需判断这一列上是否有其他棋子。还要注意修改标记后递归回来要及时复原。


//之前由于将 i，j定义在了外面，导致了不知名的错误
