#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int pow(int x, int n)
{
	int val = 1;
	
	while(n--)
	{
		val = val * x;
	}
	
	return val;
}



void search(char* str, char* ptrn)
{
	int h_ptrn = 0 ;
	int h_str = 0 ;
	int len_str = strlen(str);
	int len_ptrn = strlen(ptrn);
	int mod = 1000000000 + 9 ;
	int prime = 7 ;
	
	int i;
	for(i=0; i < len_ptrn ; i++)
	{
		h_ptrn += ( (ptrn[i] - 'a' + 1) * pow(prime,i) % mod ) % mod ;
		h_str += ( (str[i] - 'a' + 1) * (pow(prime,i) % mod) ) % mod ;
	}
	
	//printf("%d  %d\n",h_ptrn,h_str);
	
	i=0;
	if(h_ptrn == h_str)
		{
			int j=0;
			for(j=0; j < len_ptrn; j++)
			{
				if(str[i+j] != ptrn[j])
					break;
			}
			
			if(j == len_ptrn)
				printf("Pattern found a Index : %d\n",i);
				
		}
	
	
	for(i=1; i <= len_str - len_ptrn; i++)
	{
		
		
		if(i <= len_str - len_ptrn)
		{
			int old_hash = h_str ;   // extra variable for sake of better understanding
			int new_hash = ( ((old_hash - (str[i-1] - 'a')) / prime)  + ( ((str[i+len_ptrn-1] - 'a' + 1) * (pow(prime,len_ptrn-1) % mod)) % mod ) ) % mod;
			h_str = new_hash ;
			
		}
		
	//	printf("%d  %d\n",h_ptrn,h_str);
	
		if(h_ptrn == h_str)
		{
			int j=0;
			for(j=0; j < len_ptrn; j++)
			{
				if(str[i+j] != ptrn[j])
					break;
			}
			
			if(j == len_ptrn)
				printf("Pattern found a Index : %d\n",i);
				
		}
	
	
	}
	
}


int main()
{
	char* str = "abedabc" ;
	char* ptrn = "abc" ;
	
	search(str,ptrn);
}
