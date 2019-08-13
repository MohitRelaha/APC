// REMOVE DUPLICATE NODE ALSO


#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next ;
};


struct node* removeNode(struct node* head)
{
	struct node* ptr1 = head;
	struct node* ptr2 = NULL;
	struct node* prev = NULL;
	
	if(ptr1)
		ptr2 = ptr1->next;
	else
		return ptr1;
		
	while(ptr2)
	{
		
		while( ptr2  &&  ptr1->data == ptr2->data)
		{
			ptr2 = ptr2->next;
		}
		
	    if(ptr1->next == ptr2)
	    {
	    
	    	prev = ptr1;
	    		
	    	ptr1 = ptr1->next;
			ptr2 = ptr2->next;	
		}
		else
		{
			if(prev == NULL)
				head = ptr2;
			else
				prev->next = ptr2;
			
			ptr1 = ptr2;
			
			if(ptr1)
				ptr2 = ptr2->next;
		}
		
		
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
	
	head = removeNode(head);
	printf("\n\nLinkedList After Removing Duplicate Nodes\n");
	print(head);
	
	
}







