#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	int num;
	struct node *next;
	struct node *bef;
}s_node;

void push(s_node* front,s_node* back,int num)
{
	s_node *new_node;
	new_node = (s_node*)malloc(sizeof(s_node));
	
	if(back->next==NULL)
	{
		new_node->num = num;
		back->next = new_node;
		front->next = new_node;
	}
	else
	{
		new_node->num = num;
		new_node->next = back->next;
		back->next->bef = new_node;
		back->next = new_node;
	}
}

void pop(s_node* front, s_node* back){
	
	if(back->next == NULL)
		printf("%d\n",-1);
	else
	{
		if(front->next == back->next)
		{
			printf("%d\n",front->next->num);
			front->next = NULL;
			back->next = NULL;
		}
		else
		{
			s_node * e_node = NULL;
			e_node = front->next;
			
			printf("%d\n",e_node->num);
			front->next = e_node->bef;
			e_node->bef->next = NULL;
			free(e_node);
		}
	}	
}

void size(s_node* back){
	
	if(back->next == NULL)
		printf("%d\n",0);
	else
	{
		s_node * e_node = NULL;
		int cnt = 0;
		
		e_node = back->next;
		cnt++;
		
		while(e_node->next!=NULL)
		{
			cnt++;
			e_node = e_node->next;
		}
		printf("%d\n",cnt);
	}
}

void empty(s_node* back){
	
	if(back->next == NULL)
		printf("%d\n",1);
	else
		printf("%d\n",0);
}

void front(s_node* front){

	if(front->next == NULL)
		printf("%d\n",-1);
	else
		printf("%d\n",front->next->num);
}

void back(s_node* back){

	if(back->next == NULL)
		printf("%d\n",-1);
	else
		printf("%d\n",back->next->num);
}

int main(void) {
	
	s_node *f = (s_node*)malloc(sizeof(s_node));
	s_node *b = (s_node*)malloc(sizeof(s_node));
	int n = 0;
	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		char f_input[100] = {0};
		int p_num = 0;
		
		scanf("%s",f_input);

		if(strcmp(f_input,"push") == 0)
		{
			scanf("%d",&p_num);
			if(p_num > 0)
			{
				push(f,b,p_num);
			}
		}
		else if(strcmp(f_input,"pop") == 0)
			pop(f,b);
		else if(strcmp(f_input,"size") == 0)
			size(b);
		else if(strcmp(f_input,"empty") == 0)
			empty(b);
		else if(strcmp(f_input,"front") == 0)
			front(f);
		else if(strcmp(f_input,"back") == 0)
			back(b);
	}
	
	return 0;
}
