#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definicao da estrutura do nó da lista
struct Node {
    char data[100];
    struct Node* prev;
    struct Node* next;
};

// Função para inserir um novo nó no inicio da lista
void insert(struct Node** head_ref, char* newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode ->data, newData);
    newNode->next = (*head_ref);
    newNode->prev = NULL;
    if ((*head_ref) != NULL)
        (*head_ref)->prev = newNode;
    (*head_ref) = newNode;
}

// Função para remover um nó especifico da lista
void removeNode(struct Node** head_ref, struct Node* del) {
    if (*head_ref == NULL || del == NULL)
    return;

    if (*head_ref == del)
        *head_ref = del->next;

    if (del->next != NULL)
        del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del);
}

// Funcao para imprimir os elementos da lista
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%s", node->data);
        node = node->next;
    }
}

int main () {
    struct Node* head = NULL;

    insert(&head, " Maca");
    insert(&head, " Banana");
    insert(&head, " Laranja");

    printf("Lista Original: ");
    printList(head);

    // Removendo o nó com "Banana"
    struct Node* nodeToRemove = head->next;
    removeNode(&head, nodeToRemove);

    printf("\nLista Apos a Remocao: ");
    printList(head);

    printf("\n");

    return 0;
}