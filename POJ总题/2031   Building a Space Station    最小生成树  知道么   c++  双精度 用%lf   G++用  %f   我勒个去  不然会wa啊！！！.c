自己的方法

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

struct Island
{
	double xi,yi,zi,r;
	int father;
}island[101];

double dist(Island A,Island B)  
{  
    return sqrt((A.xi-B.xi)*1.0*(A.xi-B.xi)+(A.yi-B.yi)*(A.yi-B.yi)+(A.zi-B.zi)*(A.zi-B.zi))-A.r-B.r;  
}  
struct Bridge
{
	int a,b;
	double price;
}bridge[10010];

int cmp(Bridge a,Bridge b)
{
	return a.price < b.price;
}

int find(int x)
{
	int t;
	int child = x;
	while(x != island[x].father)
	{
		x = island[x].father;
	}
		while(x != child)
		{
			t=island[child].father;
			island[child].father = x;
			child = t;
		}	
	return x;
}

int merge(int x,int y)
{
	int a =find(x);
	int b =find(y);
	if(a != b)
	{
		island[a].father = b;
		return 1;
	}
	return 0;	
} 


int main()
{
	int n,m,i,j,k,g,t; //g 是用来优化最后一步  如果当所有的岛都联通之后 停止 造桥 
	double ans;
	while(scanf("%d",&n),n)	
	{
		k = 1;
		g =1;
		ans = 0.000;
		memset(bridge,0,sizeof(bridge));
		memset(island,0,sizeof(island));
		for(i = 0;i <= 100;i++ )
		island[i].father = i;
		for (i = 1;i <= n;i++)
		{
			scanf("%lf%lf%lf%lf",&island[i].xi,&island[i].yi,&island[i].zi,&island[i].r);
			for( j = 1;j < i;j++)
			{
				if(dist(island[i],island[j]) > 0)				
				{
				bridge[k].a = i;
				bridge[k].price = dist(island[i],island[j]);
				bridge[k++].b = j; 
				}
				else
				{
				bridge[k].a = i;
				bridge[k].price = 0.000;
				bridge[k++].b = j; 
				}
			}		
		}	
			sort(bridge+1,bridge+k,cmp);
			for(i = 1;i < k;i++)
			{
				if (merge(bridge[i].a,bridge[i].b))
				{
				ans += bridge[i].price;
				g++;
				}				
				if(g == n)
				break;
			}
			printf("%.3lf\n",ans);
	}
	return 0;
}


网上的方法1

这个真的是太简洁 了    好飘逸  ！！！  prim 算法  好好学！！！

#include<cstdio>  
#include<iostream>  
#include<cmath>  
using namespace std;  
const int mm=111;  
double x[mm],y[mm],z[mm],r[mm],dis[mm];  
bool p[mm];  
int i,j,k,n;  
double mn,ans;  
double sq(double a)  
{  
    return a*a;  
}  
double dd(int i,int j)  
{  
    double ret=sqrt(sq(x[i]-x[j])+sq(y[i]-y[j])+sq(z[i]-z[j]))-r[i]-r[j];  
    return ret>0?ret:0;  
}  
int main()  
{  
    while(scanf("%d",&n),n)  
    {  
        for(i=1;i<=n;++i)  
            scanf("%lf%lf%lf%lf",&x[i],&y[i],&z[i],&r[i]);  
        for(i=1;i<=n;++i)dis[i]=1e30,p[i]=1;  
        ans=dis[1]=0;  
        for(i=1;i<=n;++i)  
        {  
            mn=1e30;  
            for(j=1;j<=n;++j)  
                if(p[j]&&dis[j]<mn)  
                {  
                    mn=dis[j];  
                    k=j;  
                }  
            p[k]=0;  
            ans+=mn;  
            for(j=1;j<=n;++j)  
                if(p[j])dis[j]=min(dis[j],dd(k,j));  
        }  
        printf("%.3lf\n",ans);  
    }  
    return 0;  
} 


网上的方法2 


#include<stdio.h>
#include<math.h>
#include<string.h>
#define N 99999999
struct node {
   double x,y,z,r;
}lnode[150];
double map[150][150];
double d[150];
int flag[150],n;
double dist(int a,int b)
{
   double sum;
   sum=sqrt(pow((lnode[a].x-lnode[b].x),2)+pow((lnode[a].y-lnode[b].y),2)+pow((lnode[a].z-lnode[b].z),2))-lnode[a].r-lnode[b].r;
   return sum;
}
double prim()
{
   int i,j,z;
   double min,sum=0;
   memset(flag,0,sizeof(flag));
   for(i=0;i<n;i++)
       d[i]=map[0][i];
   flag[0]=1;
   for(i=1;i<n;i++)
   {
       min=N;
       for(j=1;j<n;j++)
           if(!flag[j]&&d[j]<min)
           {
               min=d[j];
               z=j;
           }
           flag[z]=1;
           //printf("%.3f\n",min);
           sum+=min;
           for(j=0;j<n;j++)
               if(!flag[j]&&d[j]>map[j][z])
                   d[j]=map[z][j];
   }
   return sum;
}
int main()
{
   int i,j;
   while(scanf("%d",&n),n)
   {
       for(i=0;i<n;i++)
           scanf("%lf%lf%lf%lf",&lnode[i].x,&lnode[i].y,&lnode[i].z,&lnode[i].r);
       for(i=0;i<n;i++)
           for(j=0;j<n;j++)
               map[i][j]=N;
       for(i=0;i<n;i++)
           for(j=i+1;j<n;j++)
           {
               double v=dist(i,j);
               //printf("%.3f\n",v);
               if(v<=0)
               {
                   map[i][j]=0;
                   map[j][i]=0;
               }
               else
               {
                   map[i][j]=v;
                   map[j][i]=v;
               }
           }
           printf("%.3f\n",prim());
   }
   return 0;
}