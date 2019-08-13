// INSERT AT END

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

void insertAtEnd(struct node** head , int data)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;   // next would be always null because it is Last Node. 
	
	// IF LL IS EMPTY INITIALLY
	if(*head==NULL)
	{
		*head = temp;
	}
	else
	{
		struct node* traverse = *head;
		while(traverse->next != NULL)
		{
			traverse = traverse->next;
		}
		
		traverse->next = temp;
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
	insertAtEnd(&list1,1);
	insertAtEnd(&list1,2);
	insertAtEnd(&list1,3);
	print(list1);
}

