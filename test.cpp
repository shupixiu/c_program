#include <stdio.h>
#include <stdlib.h>
#define NULL 0
#define TYPE struct stu
#define LEN sizeof (struct stu)

struct stu
{
	int num;
	int age;
	struct stu *next;
};

TYPE *creat(int n)
{
	struct stu *head,*pf,*pb;
	int i;
	for(i=0;i<n;i++)
	{
		pb=(TYPE*) malloc(LEN);
		printf("input Number and Age\n");
		scanf("%d%d",&pb->num,&pb->age);
		if(i==0)
		pf=head=pb;
		else pf->next=pb;
		pb->next=NULL;
		pf=pb;
	}
	//free(pb);
	return(head);
}

TYPE *search(TYPE *head,int n)
{
	TYPE *p;
	p=head;
	while (p->num!=n && p->next!=NULL)
    {
     	p=p->next; /* 不是要找的结点后移一步*/
	}
	if (p->num==n) 
	{
     	printf ("find it\n");
		return (p);
	}
	if (p->num!=n && p->next==NULL)
	{
		printf ("Node %d has not been found!\n",n);
		return NULL;
	}
	
}

TYPE *del(TYPE *head,int num)
{
	TYPE *pf,*pb;
	if(head==NULL) /*如为空表， 输出提示信息*/
	{ 
		printf("\nempty list!\n");
     	return NULL;
	}
	pb=head;
	while (pb->num!=num && pb->next!=NULL)
	/*当不是要删除的结点，而且也不是最后一个结点时，继续循环*/
	{
		pf=pb;
		pb=pb->next;
	}/*pf指向当前结点，pb指向下一结点*/
	if(pb->num==num)
	{
	/*如找到被删结点，且为第一结点，则使head指向第二个结点，
	否则使pf所指结点的指针指向下一结点*/
		if(pb==head) 
		{
		  head=pb->next;
		}else{
	    	pf->next=pb->next;
		}
	    free(pb);
    	printf("The node is deleted\n");
	}else{
		printf("The node not been foud!\n");
	}



	return head;
}

/***
写一个函数，在链表中指定位置插入一个结点。在一个链表的指定位置插入结点， 要求链表本身必须是已按某种规律排好序的。例如，在学生数据链表中， 要求学号顺序插入一个结点。设被插结点的指针为pi。 可在三种不同情况下插入。
1. 原表是空表，只需使head指向被插结点即可。见图7.7(a)
2. 被插结点值最小，应插入第一结点之前。这种情况下使head指向被插结点，被插结点的指针域指向原来的第一结点则可。即：pi->next=pb;
head=pi; 见图7.7(b)
3. 在其它位置插入，见图7.7(c)。这种情况下，使插入位置的前一结点的指针域指向被插结点，使被插结点的指针域指向插入位置的后一结点。即为：pi->next=pb;pf->next=pi；
4. 在表末插入，见图7.7(d)。这种情况下使原表末结点指针域指向被插结点，被插结点指针域置为NULL。
***/
TYPE *insert(TYPE * head,TYPE *pi)
{
	TYPE *pf,*pb;
	pb=head;
	if(head==NULL) /*空表插入*/
	{
		head=pi;
	    pi->next=NULL;
	}
	else
	{
		while((pi->num>pb->num)&&(pb->next!=NULL))
		{
			pf=pb;
			pb=pb->next; 
		}/*找插入位置*/

		if(pi->num<=pb->num)
		{
		  if(head==pb)
		  {    
			  head=pi;/*在第一结点之前插入*/	  
		  }else{
			  pf->next=pi;/*在其它位置插入*/	  
		  }	  
		  pi->next=pb; 
		}
		else
		{
			pb->next=pi;
			pi->next=NULL;
		} /*在表末插入*/
	}
	return head;
}

void print(TYPE * head)
{
	printf("Number\t\tAge\n");
	int n=0;
	while(head!=NULL && n<5)
	{
    	printf("%d\t\t%d\n",head->num,head->age);
    	n++;
		head=head->next;
	}
}

void main(){
   TYPE *creat(int n);
   TYPE *search (TYPE *head,int n);
   TYPE *del (TYPE *head,int n);
   TYPE *creatLink,*delLink,*node,*insertLink;
  
   creatLink=creat(3);
   print(creatLink); 
 //  return;
   node=(TYPE*) malloc(LEN);
   node->num=5;
   node->age=1;
   insertLink=insert(creatLink,node);
  // search(creatLink,10);
   print(insertLink);
   //delLink=del(creatLink,10);
  // search(delLink,10);
}
