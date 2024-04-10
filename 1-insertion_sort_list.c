#include "sort.h"
#include <stdio.h>
/**
 * insertion_sort_list - sorts in insertion sort algorithm
 * @list: pointer to pointer to list
 * Return: sorted doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
listint_t *sorted = NULL;
listint_t *current;
listint_t *next;
listint_t *ptr;
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;
current = *list;
while (current != NULL)
{
next = current->next;
if (sorted == NULL || current->n <= sorted->n)
{
current->prev = NULL;
current->next = sorted;
if (sorted != NULL)
sorted->prev = current;
sorted = current;
}
else
{
ptr = sorted;
while (ptr->next != NULL && ptr->next->n < current->n)
ptr = ptr->next;
current->prev = ptr;
current->next = ptr->next;
if (ptr->next != NULL)
ptr->next->prev = current;
ptr->next = current;
}
current = next;
print_list(sorted);
}
*list = sorted;
}
