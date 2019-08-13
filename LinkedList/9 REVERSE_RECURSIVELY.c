// REVERSE LINKED_LIST RECURSIVELY


#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next ;
};



struct node* reverse_recur(struct node* head)
{
	// EMPTY OR ONLY ONE ELEMENT
	if(head == NULL || head->next == NULL)
		return head;
		
	struct node* smallAns = reverse_recur(head->next);
	head->next->next = head;
	head->next = NULL;
	
	return smallAns;

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
	
	head = reverse_recur(head);
	printf("\n\nLinkedList After Reverse\n");
	print(head);
	
	
}







