#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int* zTable(char* str)
{
	int n = strlen(str);
	int* z = (int*)malloc(sizeof(int) * n);
	
	int i=0,l=0,r=0;
	z[0] = 0 ;
	for(i=1; i<n ; i++)
	{
		if(i >= r)
		{
			l = r = i ;
			
			while(str[r] != '\0' && (str[r] == str[r-l]))
			{
				r++;	
			}
			
			z[i] = r - l  ;
			
		}
		else
		{
			if(z[i-l] + i < r)
			{
				z[i] = z[i - l];
			}
			else
			{
				l = i;
				
				while(str[r] != '\0' && (str[r] == str[r-l]))
				{
					r++;	
				}
			
				z[i] = r - l  ;
			}
		}
		
	}
	
	return z;
	
}


int main()
{
	char str[20] = "aabxaabxcaabxaabxay" ;
	char substr[24] = "aab$";
	
	strcat(substr,str);
	
	int n = strlen(substr);
	int* z = zTable(substr);
	
	int i;
	printf("Z - TABLE\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",z[i]);
	}
	printf("\n\n\n");
	printf("Indexes at which pattern found\n");
	
	int l = strlen(substr) - strlen(str) - 1 ;
	
	for(i=0;i<n;i++)
	{
		if(z[i] == l)
			printf("%d  ",i - l - 1);
	}
		
}
