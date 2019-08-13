// DELETE FROM END


#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next ;
};


void delFromEnd(struct node** head)
{
	struct node* temp = *head;
	
	if(temp == NULL)
	{
		return;
	}
	
	if(temp->next == NULL)
	{	
		free(temp);
		temp = NULL;
		*head = NULL;
		return;
	}
	
	
	while(temp->next->next != NULL)
	{
		temp = temp->next ;
	}
	
	free(temp->next);
	temp->next = NULL;
	
}


struct node* create(struct node* head)
{
	printf("Enter elements in List\n Press -1 to stop entering\n") ;
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
	printf("Original LinkedList\n");
	print(head);
	
	delFromEnd(&head);
	printf("\n\n\nLinkedList after delete from End\n");
	print(head);
}
