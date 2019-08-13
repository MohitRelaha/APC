// REVERSE K NODES RECURSIVELY


#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next ;
};



struct node* reverseK(struct node* head , int k)
{
	
	if(head == NULL || k==0)
		return head;
	
	
	struct node* cur = head;
	struct node* prev = NULL;
	struct node* nextt = NULL;
	
	int count = 0;
	while(cur!=NULL && count<k)
	{
		nextt = cur->next;
		cur->next = prev;
		prev = cur;
		cur = nextt;
		count++ ;
	}
	
	head->next = reverseK(cur,k);
	
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
	
	int k;
	printf("\n\nEnter Value of K   :     ");
	scanf("%d",&k);

	head = reverseK(head,k);
	printf("\n\nLinkedList After Reverse\n");
	print(head);
	
	
}







