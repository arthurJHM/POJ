#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stack>
using namespace std;
int main()
{
	int n,j,k,i;
	int out[1010];
	while(scanf("%d",&n),n)
	{	
		i = 0;
		memset(out,-1,sizeof(out));
		while(scanf("%d",&out[i]),out[0])
		{	
			stack<int>s;		
	    	k = 0;		
			for( i = 1;i < n;i++ )
			{
				scanf("%d",&out[i]);
			}
			for( i = 1;i <= n;i++)
			{
				s.push(i);
				while(!s.empty()&&s.top() == out[k])
				{
					s.pop();
					k++;
				}
			}
			if(k != n)
			printf("No\n");
			else
			printf("Yes\n");
			i = 0;			
		}
		printf("\n");
	}
	return 0;
}