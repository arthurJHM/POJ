#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
struct Com
{
	char id[100];
	int q,priority,i;
	friend bool operator < (Com a,Com b)
	{
		if(a.priority == b.priority)
		return a.i > b.i;
		else return a.priority > b.priority;
	}
}z;
int main()
{
	int k;
	char type[4];
	k = 1;
	priority_queue<Com>p;
	while(scanf("%s",type)!=EOF)
	{
		if(strcmp(type,"GET") == 0)
		{
			if(p.empty())
			{
			printf("EMPTY QUEUE!\n");
			continue;
			}
			else 
			{
				printf("%s %d\n",p.top().id,p.top().q);
				p.pop();
			}
		}
		else if(strcmp(type,"PUT") == 0)
		{
			scanf("%s%d%d",z.id,&z.q,&z.priority);
			z.i = k;
			p.push(z);
			k++;
		}
	}
	return 0;
}





���� ���ϱ��˲��͵� ����  ���� priority ��д����Щ��һ��  


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;
struct node
{
    char s[100];
    int n;
    int p;
    int i;
};
struct cmp
{
    bool operator ()(const node&a,const node&b)
    {
        if(a.p==b.p)
        {
            return a.i>b.i;
        }
        return a.p>b.p;
    }
};
int main()
{
    node t;
    priority_queue<node,vector<node>,cmp> Q;
    char s[5];
    int k=1;
    while(scanf("%s",s)!=EOF)
    {
        if(s[0]=='G')
        {
            if(!Q.empty())
            {
                t=Q.top();
                Q.pop();
                printf("%s %d\n",t.s,t.n);
            }
            else
              printf("EMPTY QUEUE!\n");//��ʼʱ������д'!'���ţ������˴�WA
        }
        else
        {
           scanf("%s%d%d",t.s,&t.n,&t.p);
             t.i=k++;
           Q.push(t);
        }
    }
    return 0;
}



��һ��priority ��һ����д��   ���� �о�һ��  ԭ��


#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <queue>
#include <limits.h>
using namespace std;
typedef struct MES{
	char str[25];
	int mes;
	int p;
	int ind;
};
bool operator<(MES a, MES b)
{
	if( a.p == b.p )
		return a.ind > b.ind;
	return a.p > b.p;
}
priority_queue<MES> q;
int main()
{
	char str[25];
	int ind = 0;
	MES tmp;
	while( ~scanf("%s",str) )
	{
		if( strcmp(str,"PUT") == 0 )
		{
			scanf("%s%d%d",tmp.str,&tmp.mes,&tmp.p);
			tmp.ind = ind++;
			q.push(tmp);
		}
		if( strcmp(str,"GET") == 0 )
		{
			if( q.empty() )
			{
				printf("EMPTY QUEUE!\n");
				continue;
			}
			tmp = q.top();
			q.pop();
			printf("%s %d\n",tmp.str,tmp.mes);
		}
	}
return 0;
}

