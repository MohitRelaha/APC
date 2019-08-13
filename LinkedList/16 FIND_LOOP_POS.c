// STARTING POINT OF LOOP


#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next ;
};



int findLoopPos(struct node* head)
{
	int flag=0;  // FOR NO LOOP
	int pos=0;  // NO LOOP MEANS 0 POSITION
	
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
	
	if(flag==0)
		return pos;
	else
	{
		struct node* temp = head;
		 pos = 1;
		while(temp != fast)
		{
			temp = temp->next;
			fast = fast->next;
			pos++;
		}
	}
	
	return pos;
	
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
	
	int ans = findLoopPos(head);
	if(ans)
	printf("\n\nLoop Exists at %d Positon \n",ans);
	else
	{
	printf("\n\nLoop Doesn't Exist\n");
	printf("Original List\n");
	print(head);
	}

	
	
}







