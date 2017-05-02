#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include<stdlib.h> 

struct node {
	int data;
	struct node *link;
};
// release the nodes of a linked list
void release_linked_list(struct node **head)
{
	struct node *p;
	while (*head) {
		p = *head;
		*head = (*head)->link;
		free(p);
	}
	*head = NULL;
}

int size(struct node *head) // return the number of nodes in a linked list
{
	int num = 0;
	while (head)
	{
		num++;
		head = head->link;
	}
	return num;
}

// insert a new node after trail
// if trail == NULL, the newnode is the new head of this linked list
void linked_list_insert(struct node **head, struct node* trail, int data)
{
	struct node* p = (struct node *) malloc(sizeof(struct node));
	p->data = data;
	if (*head) {
		if (trail == NULL)
		{
			p->link = *head;
			*head = p;
		}
		else 
		{ 
			p->link = trail->link;
			trail->link = p;
		}
	}
	else { 
		p->link = NULL;
		(*head) = p;
	}
	return;
}

// delete all nodes with data=k
void linked_list_delete_data(struct node **head, int k)
{
	node *now = *head;
	node *before = NULL;

	while (now != NULL)
	{
		if (now->data != k)
		{
			before = now;
			now = now->link;
		}
		else
		{
			if (now == *head)
			{
				node *temp = now->link;
				free(now);
				now = temp;
				*head = temp;
			}
			else
			{
				node *temp = now->link;
				free(now);
				now = temp;
				before->link = now;
			}
		}
	}
}

void linked_list_reverse_data(struct node **head)
{
	// insert your code
	struct node* previous, *current, *preceding;

	previous = *head;
	current = previous->link;
	(*head)->link = NULL;

	while (current != NULL)
	{
		preceding = current->link;
		current->link = previous;
		previous = current;
		current = preceding;
	}

	*head = previous;


}
// return a node with data == k

struct node* linked_list_find(struct node *p, int k)
{
	while (p && p->data != k)
	{
		p = p->link;
	}
	return p;
}

void output_linked_list(struct node* head)
{
	while (head) {
		printf("%d\n", head->data);
		head = head->link;
	}
	return;
}


int main() // Do not modify the main program
{
	int op, data;   struct node *head = NULL;
	scanf("%d%d", &op, &data);
	while (op != 0)
	{
		switch (op) {
		case 1: 	linked_list_insert(&head, NULL, data); // insert     
			break;
		case 2: 	linked_list_delete_data(&head, data); // delete
			break;
		case 3: 	printf("%d %s\n", data, linked_list_find(head, data) ? "found" : "not found"); // search
			break;
		case 4: 	printf("%d elements in linked list\n", size(head)); // size
			break;
		case 5:  	linked_list_reverse_data(&head); // reverse all nodes
			break;
		case 6:  	output_linked_list(head); // list all nodes
			break;
		}
		scanf("%d%d", &op, &data);
	}
	release_linked_list(&head);
	return 0;
}
