// REMOVE DUPLICATE FROM SORTED LL


#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next ;
};


void removeDuplicate(struct node* head)
{
	struct node* cur = head;
	
	while(cur->next != NULL)
	{
	
	if(cur->data == cur->next->data)
		cur->next = cur->next->next ;
	else
		cur = cur->next ;
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
	
	

	removeDuplicate(head);
	printf("\n\nLinkedList After Removing Duplicates\n");
	print(head);
	
	
}







