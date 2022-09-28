#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list_entry_t list_entry;
struct list_entry_t
{
    int key;
    list_entry *next;
    list_entry *previous;
};

list_entry *List_head;

void removeEntry(int key)
{
    list_entry *entry;

    for (entry = List_head; entry != NULL; entry = entry->next) {
        if (entry->key == key)
            break;
    }

    if (entry == NULL)
        return;

    // Caso a entrada seja a cabeça da lista
    if (entry == List_head)
    {
        List_head = entry->next;
    }
    // Caso a entrada não seja a cabeça da lista
    if (entry->previous != NULL)
    {
        entry->previous->next = entry->next;
    }
    // Caso a entrada não seja a calda da lista
    if (entry->next != NULL)
    {
        entry->next->previous = entry->previous;
    }

    free(entry);
}

void free_list(list_entry* list_entry)
{
    if (list_entry != NULL)
    {
        if (list_entry->next != NULL)
        {
            free_list(list_entry->next);
        }
        printf("Deletando Item key %d\n", list_entry->key);
        free(list_entry);
    }
    return;
}

int main(int argc, char const *argv[])
{
    List_head = (list_entry *)malloc(sizeof(list_entry));
    bzero(List_head, sizeof(list_entry*));
    List_head->key = 0;
    List_head->next = NULL;
    List_head->previous = NULL;

    list_entry *a = (list_entry *)malloc(sizeof(list_entry));
    a->key = 1;
    a->next = NULL;
    a->previous = List_head;
    List_head->next = a;

    list_entry *b = (list_entry *)malloc(sizeof(list_entry));
    b->key = 2;
    b->next = NULL;
    b->previous = a;
    a->next = b;

    list_entry *c = (list_entry *)malloc(sizeof(list_entry));
    c->key = 3;
    c->next = NULL;
    c->previous = b;
    b->next = c;
    
    list_entry *temp;
    for (temp = List_head; temp != NULL; temp = temp->next)
    {
        printf("Item key %d\n", temp->key);
    }

    removeEntry(1);

    free_list(List_head);
    
    return 0;
}
