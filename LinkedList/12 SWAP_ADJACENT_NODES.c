// SWAP ADJACENT NODES


#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next ;
};



struct node* swapAdjacent(struct node* head)
{
	struct node* cur = head ;
	struct node* nextt = NULL ;
	struct node* prev = NULL ;
	
	if(cur)
		nextt = cur->next;
		
	while(cur && nextt)
	{
		cur->next = nextt->next ;
		nextt->next = cur;
		
		if(prev == NULL)
			head = nextt;
		else
			prev->next = nextt;
		
		prev = cur;
		cur = cur->next;
		if(cur)
		nextt = cur->next;
		
	
	}
	
	return head;


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
	
	head = swapAdjacent(head);
	printf("\n\nLinkedList After Swapping Adjacent Nodes\n");
	print(head);
	
	
}







