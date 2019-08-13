// DELETE FROM GIVEN POSITION


#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next ;
};


void delFromPos(struct node** head,int pos)
{
	if(*head == NULL)
	{
		printf("LinkedList is already Empty. Delete Operation Cannot Be Performed\n");
		getch();
		exit(1);
	}
	else if(pos == 1)
	{
		struct node* temp = *head;
		*head = (*head)->next;
		free(temp);
		temp=NULL;
	}
	else{
		int count = 1 ;
		struct node* cur = *head;
		
		while(cur && count<pos-1 )
		{
			cur = cur->next;	
			count++;
		}
		
		if(cur && cur->next)
		{
			struct node* temp = cur->next;
			
			cur->next = cur->next->next ; // cur->next = temp->next ;
			free(temp);
			temp = NULL ;
		}
		else
		{
			printf("\nGiven Position is Greater than size of LinkedList\n");
			getch();
			exit(1);
		}
		
	}
	
	
	
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
	
	int pos;
	printf("\n\nEnter Position of Node to be deleted   :       ") ;
	scanf("%d",&pos);
	delFromPos(&head,pos);
	
	while(pos>0)
	{
	
	printf("\n\n\nLinkedList after delete from %d position \n",pos);
	print(head);
	
	printf("\n\nEnter Position of Node to be deleted   :       ") ;
	scanf("%d",&pos);
	delFromPos(&head,pos);
	
	}
}
