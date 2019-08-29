#include<stdio.h>
#include<stdlib.h>
int strlen1(char* str)
{
	int i = 0; 
	while(str[i] != '\0')
	{	
		i++;
	}
	
	return i;
}

int* findLps(char* substr)
{
	int n = strlen1(substr);
	
	int* lps = (int*)malloc(sizeof(int) * n);
	
	int i=0,j;
	lps[0] = 0;
	for(j=1;j<n;)
	{
		if(substr[i] != substr[j])
		{
			if(i==0)
			{
				lps[j] = 0;
				j++;
			}
			else
			{
				i = lps[i-1];
			}
			
		}
		else
		{
			lps[j] = ++i;
			j++;
		}
		
	}
	
	return lps;
}


char* strstr1(char* str, char* substr)
{
	int l = strlen1(str);
	int ls = strlen(substr);
	
	int* lps = findLps(substr);
	
	int i=0,j=0,index=0;

		while(str[i] != '\0')
		{
			if(str[i] == substr[j])
			{
				i++; 
				j++;	
			}
			else
			{
				if(j == 0)
				{
					i++;
				//	index = i;  // index will be i here  i-0 == i
				}
				else
					{
					j = lps[j-1] ;	
					}
				
				index = i-j;
			}	
		}
		
	if(j == ls)
		return &str[index];
		
	return NULL;
}


int main()
{
	char* str = "abcdabcdabcy" ;
	char* substr = "abcy" ;
	
	char* s = strstr1(str,substr);
	
	printf("%s",s);
	
}
