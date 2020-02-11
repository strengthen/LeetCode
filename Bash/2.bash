__________________________________________________________________________________________________
sample 0 ms submission
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* newNode(int d)
{
    struct ListNode* node = malloc(sizeof(struct ListNode));
    node->val   = d;
    node->next  = NULL;
    return node;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode* dummy  = newNode(0);
    struct ListNode* cur    = dummy;
    struct ListNode* pl1    = l1;
    struct ListNode* pl2    = l2;       
    int carry               = 0;
    while( pl1 != NULL || pl2 != NULL )
    {
        int l1Val   = ( pl1 != NULL ) ? pl1->val : 0;
        int l2Val   = ( pl2 != NULL ) ? pl2->val : 0;
        int sum     = carry +l1Val + l2Val;
        
        // Check if over 10
        carry       = sum/10;
        
        // Only single digit
        cur->next   = newNode(sum%10);
        cur         = cur->next;
        
        if( pl1 != NULL ) pl1 = pl1->next;
        if( pl2 != NULL ) pl2 = pl2->next;
    }
    

    if (carry > 0) {
        cur->next = newNode(carry);
    }     
    return dummy->next;  
}
__________________________________________________________________________________________________
sample 4 ms submission
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     struct ListNode *next;
* };
*/

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *sp_Polling1 = l1;
	struct ListNode *sp_Polling2 = l2;
	struct ListNode *sp_Ret = NULL;
	struct ListNode *sp_RetNext = NULL;
	int iOverDigit = 0;
	
	while (sp_Polling1 != NULL && sp_Polling2 != NULL)
	{
		if (sp_RetNext != NULL)
		{
			sp_RetNext->next = malloc(sizeof(struct ListNode));
			sp_RetNext = sp_RetNext->next;
		}
		else
			sp_RetNext = sp_Ret = malloc(sizeof(struct ListNode));

		sp_RetNext->val = sp_Polling1->val + sp_Polling2->val + iOverDigit;
		iOverDigit = sp_RetNext->val - sp_RetNext->val % 10;
		sp_RetNext->val -= iOverDigit;
		iOverDigit /= 10;
		sp_RetNext->next = NULL;

		sp_Polling1 = sp_Polling1->next, sp_Polling2 = sp_Polling2->next;
	}

	while (sp_Polling1 != NULL)
	{
		if (sp_RetNext != NULL)
		{
			sp_RetNext->next = malloc(sizeof(struct ListNode));
			sp_RetNext = sp_RetNext->next;
		}
		else
			sp_RetNext = sp_Ret = malloc(sizeof(struct ListNode));

		sp_RetNext->val = sp_Polling1->val + iOverDigit;
		iOverDigit = sp_RetNext->val - sp_RetNext->val % 10;
		sp_RetNext->val -= iOverDigit;
		iOverDigit /= 10;
		sp_RetNext->next = NULL;

		sp_Polling1 = sp_Polling1->next;
	}

	while (sp_Polling2 != NULL)
	{
		if (sp_RetNext != NULL)
		{
			sp_RetNext->next = malloc(sizeof(struct ListNode));
			sp_RetNext = sp_RetNext->next;
		}
		else
			sp_RetNext = sp_Ret = malloc(sizeof(struct ListNode));

		sp_RetNext->val = sp_Polling2->val + iOverDigit;
		iOverDigit = sp_RetNext->val - sp_RetNext->val % 10;
		sp_RetNext->val -= iOverDigit;
		iOverDigit /= 10;
		sp_RetNext->next = NULL;

		sp_Polling2 = sp_Polling2->next;
	}

	if (iOverDigit == 1)
	{
		sp_RetNext->next = malloc(sizeof(struct ListNode));
		sp_RetNext = sp_RetNext->next;
		sp_RetNext->val = iOverDigit;
		sp_RetNext->next = NULL;
	}

	return sp_Ret;
}
__________________________________________________________________________________________________
sample 12 ms submission
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode *mylistnode;

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    
    mylistnode ind_a,ind_b,first,current,previous;
    int count = 0;
    char carrier = 0;
    ind_a = l1;
    ind_b = l2;
    
    while(((ind_a!=NULL) || (ind_b!=NULL))||carrier)
    { 
      count++;
      current = (struct ListNode *) malloc(sizeof(struct ListNode));
          if(((ind_a==NULL) && (ind_b==NULL)))
          {
            current->val = carrier;
          }
          else if( (ind_a!=NULL) && (ind_b==NULL))
           {
               current->val  = ind_a->val +carrier ;
               ind_a = ind_a->next;
                           
               
           }
           else if((ind_a==NULL) && (ind_b!=NULL))
           {
               current->val  =  ind_b->val +carrier ;
               ind_b = ind_b->next;
           }    
           else 
           {
               current->val  = ind_a->val + ind_b->val +carrier ;
               ind_a = ind_a->next;
               ind_b = ind_b->next;
           }
      
      if (current->val>=10)
      {    carrier =1 ;
        current->val  = current->val-carrier*10; 
      }
      else
      { 
          carrier = 0;
      }      
      if (count ==1)
      {
          first=current;
      }
      else 
      {
          previous->next=current;
      }
      current->next = NULL;
      previous = current;
    }
    return first;

}
__________________________________________________________________________________________________
执行用时为 4 ms 的范例
struct ListNode* node(void)
{
    struct ListNode* p;
    p=malloc(sizeof(struct ListNode));
    if(p==NULL)
        printf("No room\n");
    else
    {
        p->val=0;
        p->next=NULL;
    }
    return p;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* temp1, * temp2, * head, *temp3;
    temp1=l1;
    temp2=l2;
    int carry = 0;
    int sum = 0;
    head=node();
    temp3=head;
    while(temp1 != NULL || temp2 != NULL)
    { 
        int x = (temp1 == NULL) ? 0:temp1->val;
   
        int y = (temp2 == NULL) ? 0:temp2->val;
        sum = x + y + carry;
        carry = sum / 10; 
        temp3->val = sum % 10;       
        if(temp1 != NULL)
            temp1 = temp1->next; 
        if(temp2 != NULL)
            temp2 = temp2->next; 
        if(temp1 == NULL && temp2 == NULL)
            break;
        
        temp3->next = node();
        temp3 = temp3->next;
    } 
    if(carry)
    {  
        temp3->next = node();
        temp3 = temp3->next;
        temp3->val = 1;
    }
    return head;
}
