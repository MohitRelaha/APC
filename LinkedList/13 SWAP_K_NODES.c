// SWAP K NODES


#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next ;
};



struct node* swapK(struct node* head , int k)
{
	
	if(k<2)
		return head;
	
	
	struct node* first1 = head;
	struct node* last1 = head;
	struct node* first2 = NULL;
	struct node* last2 = NULL;
	struct node* prev = NULL;
	
	
	int count = 1;
	
	while(count<k && last1)
	{
		last1 = last1->next;
		count++;
	}
	
	
	if(last1)
		first2 = last1->next;
	else
		return head;
		
	last2 = first2;
	count = 1;
	while(count<k && last2->next)
	{
		last2 = last2->next;
		count++;
	} 
	
	
	if(!(first1 && last1 && first2 && last2))
		return head;
	
	
	
	while((last1 != first2))
	{
	
	
	last1->next = last2->next ;
	last2->next = first1;
	
	if(prev==NULL)
		head = first2;
	else
		prev->next = first2;
		
	prev = last1;
	
	
	
	if(last1->next)
		{first1 = last1->next;
		 last1 = last1->next;
		}
	else
		break;
	
	
	count = 1;
	while(count<k &&  last1)
	{
		last1 = last1->next;
		count++;
	} 
	
	if(last1)
		{
			first2 = last1->next;
			last2 = last1->next;
		}
	else
		break;
		
	
	count = 1;
	while(count<k && last2->next)
	{
		last2 = last2->next;
		count++;
	} 
		
		if(!(first1 && last1 && first2 && last2))
			break;
		
		
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
	
	
	printf("\n\nEnter value of K  :    ");
	int k;
	scanf("%d",&k);
	head = swapK(head,k);
	printf("\n\nLinkedList After Swapping Adjacent Nodes\n");
	print(head);
	
	
}







