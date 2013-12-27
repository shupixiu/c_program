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
     	p=p->next; /* ����Ҫ�ҵĽ�����һ��*/
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
	if(head==NULL) /*��Ϊ�ձ� �����ʾ��Ϣ*/
	{ 
		printf("\nempty list!\n");
     	return NULL;
	}
	pb=head;
	while (pb->num!=num && pb->next!=NULL)
	/*������Ҫɾ���Ľ�㣬����Ҳ�������һ�����ʱ������ѭ��*/
	{
		pf=pb;
		pb=pb->next;
	}/*pfָ��ǰ��㣬pbָ����һ���*/
	if(pb->num==num)
	{
	/*���ҵ���ɾ��㣬��Ϊ��һ��㣬��ʹheadָ��ڶ�����㣬
	����ʹpf��ָ����ָ��ָ����һ���*/
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
дһ����������������ָ��λ�ò���һ����㡣��һ�������ָ��λ�ò����㣬 Ҫ��������������Ѱ�ĳ�ֹ����ź���ġ����磬��ѧ�����������У� Ҫ��ѧ��˳�����һ����㡣�豻�����ָ��Ϊpi�� �������ֲ�ͬ����²��롣
1. ԭ���ǿձ�ֻ��ʹheadָ�򱻲��㼴�ɡ���ͼ7.7(a)
2. ������ֵ��С��Ӧ�����һ���֮ǰ�����������ʹheadָ�򱻲��㣬�������ָ����ָ��ԭ���ĵ�һ�����ɡ�����pi->next=pb;
head=pi; ��ͼ7.7(b)
3. ������λ�ò��룬��ͼ7.7(c)����������£�ʹ����λ�õ�ǰһ����ָ����ָ�򱻲��㣬ʹ�������ָ����ָ�����λ�õĺ�һ��㡣��Ϊ��pi->next=pb;pf->next=pi��
4. �ڱ�ĩ���룬��ͼ7.7(d)�����������ʹԭ��ĩ���ָ����ָ�򱻲��㣬������ָ������ΪNULL��
***/
TYPE *insert(TYPE * head,TYPE *pi)
{
	TYPE *pf,*pb;
	pb=head;
	if(head==NULL) /*�ձ����*/
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
		}/*�Ҳ���λ��*/

		if(pi->num<=pb->num)
		{
		  if(head==pb)
		  {    
			  head=pi;/*�ڵ�һ���֮ǰ����*/	  
		  }else{
			  pf->next=pi;/*������λ�ò���*/	  
		  }	  
		  pi->next=pb; 
		}
		else
		{
			pb->next=pi;
			pi->next=NULL;
		} /*�ڱ�ĩ����*/
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
