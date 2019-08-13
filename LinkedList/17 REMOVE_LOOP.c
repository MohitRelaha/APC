// REMOVE LOOP


#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next ;
};



void removeLoop(struct node* head)
{
	int flag=0;  // FOR NO LOOP
	
	struct node* slow = head;
	struct node* fast = head;
	
	while(fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		
		if(fast == slow)
			{
			flag=1;
			break;
			}
	}
	
	if(flag==1)
	{
		struct node* temp = head;
		 
		while(temp->next != fast->next)
		{
			temp = temp->next;
			fast = fast->next;
		}
		fast->next = NULL;
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
	
	
	printf("Enter Last Node Next Value     :      ");
	int n;
	scanf("%d",&n);
	
	if(n == -1)
		return head;
	else
	{
		int count = 1;
		struct node* temp = head;
		while(count<n)
		{
			temp = temp->next;
			count++;
		}
		
		prev->next = temp;
		
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
	
	removeLoop(head);
	printf("Linked List\n");
	print(head);
	

	
	
}







