// CREATING A LINKED_LIST


#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next ;
};


struct node* create(struct node* head)
{
	int data;
	scanf("%d",&data);
	struct node* prev = NULL;
	while(data!=-1)
	{
			struct node* temp = (struct node*)malloc(sizeof(struct node));
			temp->data = data;
			temp->next = NULL;
			
			scanf("%d",&data);
			
			if(head==NULL)
				{
				head=temp;
				prev=head;
				}
			else
				{
					prev->next = temp;
					prev = temp;
				}
				
	}
	return head;
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
	struct node* head = NULL;
	head = create(head);
	print(head);
}
