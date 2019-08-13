// FIND LOOP


#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next ;
};



int findLoop(struct node* head)
{
	
	struct node* slow = head;
	struct node* fast = head;
	
	while(fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		
		if(fast == slow)
			return 1;
	}
	
	return 0;
	
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
	
	int ans = findLoop(head);
	if(ans)
	printf("\n\nLoop Exists\n");
	else
	{
	printf("\n\nLoop Doesn't Exist\n");
	print(head);
	}

	
	
}







