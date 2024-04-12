#include "sort.h"
/**
 * swap_nodes - helper function to swap two nodes in a listint_t
 * doubly linked list.
 * @h: pointer to the head of the doubly-linked list
 * @n1: pointer to the first node to swap
 * @n2: second node to swap
 * Return: nothing
 */
void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
(*n1)->next = n2->next;
if (n2->next != NULL)
n2->next->prev = *n1;
n2->prev = (*n1)->prev;
n2->next = *n1;
if ((*n1)->prev != NULL)
(*n1)->prev->next = n2;
else
*h = n2;
(*n1)->prev = n2;
*n1 = n2->prev;
}
/**
 * insertion_sort_list - insertion sorting algorithm for doubly linked
 * listint_t lists.
 * @list: pointer to pointer to head of list
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;
listint_t *current = (*list)->next;
while (current != NULL)
{
listint_t *insert = current->prev;
while (insert != NULL && current->n < insert->n)
{
swap_nodes(list, &insert, current);
print_list((const listint_t *)*list);
insert = current->prev;
}
current = current->next;
}
}
