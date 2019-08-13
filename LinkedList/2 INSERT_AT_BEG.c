#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

void insertAtBeg(struct node** head , int data)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	
	// IF LL IS EMPTY INITIALLY
	if(*head==NULL)
	{
		temp->next = NULL;
		*head = temp;
			
	}
	else
	{
		temp->next = *head;
		*head = temp;
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
	insertAtBeg(&list1,1);
	insertAtBeg(&list1,2);
	insertAtBeg(&list1,3);
	print(list1);
}

