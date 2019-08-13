// DELETE AT BEGINNING


#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next ;
};


void delFromBeg(struct node** head)
{
	if(*head == NULL)
	{
		printf("Cannot Delete From Empty List \n");
		getch();
		exit(1);
	}
	
	struct node* temp = *head;
	*head = (*head)->next;
	
	free(temp);
	temp = NULL;
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
	
	delFromBeg(&head);
	printf("\n\n\nLinkedList after delete from beginning\n");
	print(head);
}
