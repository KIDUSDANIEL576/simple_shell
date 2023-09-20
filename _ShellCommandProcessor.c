#include "shell.h"

/**
* h: lists
* display_list - Display lists
* Return: nodes list
*/
size_t display_list(const list_t *h)
{
unsigned int node_count = 0;

while (h != NULL)
{
if (h->str)
{
_puts(num_to_str(h->len));
_puts(" ");
_puts(h->str);
_puts("\n");
}
else
_puts("[0] (nil)\n");
h = h->next;
node_count++;
}
return (node_count);
}

/**
* str: string
* append_node_end – insert  new node
* Return: pointer to the first node
*/


list_t *append_node_end(list_t **head, const char *str)
{
list_t *last_node, *temp;

last_node = malloc(sizeof(list_t));

if (last_node == NULL)
return (NULL);

last_node->str = _strdup(str);
last_node->len = _strlen(str);
last_node->next = NULL;

if (*head == NULL)
{
*head = last_node;
return (*head);
}
temp = *head;
while (temp->next != NULL)
temp = temp->next;
temp->next = last_node;
return (last_node);

}

/**
* delete_list - delete a linked list
* Return:  validated delete the linked list
*/
void delete_list(list_t *head)
{
if (head == NULL)
return;
delete_list(head->next);
free(head->str);
free(head);
}

