#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: the to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *head = NULL;
	listint_t *current = NULL;
	listint_t *p = NULL;

	while (list != NULL)
	{
		current = *list;
		*list = *list->next;
		if(head == NULL || current->n < head->n)
		{
			current->next = head;
			head = current;
		}
		else
		{
			p = head;
			while (p != NULL)
			{
				if (p->next == NULL || current->n < p->next->n)
				{
					current->next = p->next;
					p->next = current;
					break;
				}
				p = p->next;
			}
		}
		print_list(*list);
	}
}
