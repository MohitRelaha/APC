// INSERT AT GIVEN POSITION

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

void insertAtPos(struct node** head , int pos, int data)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	
	if(*head==NULL && pos>1)
	{
		printf("\n LL is empty and positon is greater than 1");
		getch();
		exit(1);
	}
	else if(pos==1)
	{
		temp->next = *head;
		*head = temp;
	}
	else
	{
		int count = 1;
		struct node* cur = *head;
		while(count<pos-1 && cur)
		{
			cur=cur->next;
			count++;
		}
		
		if(cur)
		{
			temp->next = cur->next ;
			cur->next = temp;
		}
		else
		{
			printf("\n Positon is greater than size of LL+1 ");
			getch();
			exit(1);
		}
		
		
	}
	
}

void print(struct node* head)
{
	while(head!=NULL)
	{
		printf("%d ",head->data);
		head = head->next;
	}
}


int main()
{
	struct node* list1 = NULL;
	
//	insertAtPos(&list1,2,5);    //  LL is empty and positon is greater than 1
	
	insertAtPos(&list1,1,10);
	insertAtPos(&list1,2,20);
	insertAtPos(&list1,3,30);
	
	insertAtPos(&list1,3,25);
	insertAtPos(&list1,2,15);
	
	insertAtPos(&list1,3,25);
	
//	insertAtPos(&list1,8,40);   // Positon > size of LL+1
	print(list1);
}

