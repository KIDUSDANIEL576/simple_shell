#include "shell.h"

/**
* current_size: Current size of the allocated memory
* new_size: New size for the allocated memory
* resize_memory - Resize a memory block
* mem: Memory block to be resized
* Return: Pointer to the resized memory block
*/

void *_resize_memory(void *mem, unsigned int current_size, unsigned int new_size)
{
int min_size, index;
void *new_mem;

if (current_size == new_size)
return (mem);

if (mem == NULL)
return (malloc(new_size));

if (new_size == 0)
{
free(mem);
return (NULL);
}

new_mem = malloc(new_size);

if (current_size > new_size)
min_size = new_size;

else
min_size = current_size;

for (index = 0; index < min_size; index++)
((char *)new_mem)[index] = ((char *)mem)[index];

free(mem);

return (new_mem);
}

