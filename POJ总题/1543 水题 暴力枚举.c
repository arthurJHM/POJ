#include<stdio.h>
int main()
{
	int n,i,k,j,z;
	scanf("%d",&n);
	for(i = 6;i <= n;i++)
		for(j = 2;j < i;j++)
			for(k = j;k < i;k++)
				for(z = k;z < i;z++)
				if(i*i*i == j*j*j + k*k*k + z*z*z)
					printf("Cube = %d, Triple = (%d,%d,%d)\n",i,j,k,z);
					return 0;
} 