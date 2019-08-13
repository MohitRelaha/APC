// REVERSE LINKED_LIST ITERATIVELY


#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next ;
};



struct node* reverseLL(struct node* head)
{
	struct node* cur = head;
	struct node* prev = NULL;
	struct node* nextt = NULL;
	while(cur!=NULL)
	{
		nextt = cur->next;
		cur->next = prev;
		prev = cur;
		cur = nextt;
	}
	return prev;
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
	
	head = reverseLL(head);
	printf("\n\nLinkedList After Reverse\n");
	print(head);
	
	
}







