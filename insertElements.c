#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do nó da Lista Ligada
struct Node {
    char data[100]; // Dados do nó (string de tamanho 100)
    struct Node* next; // Ponteiro para o proximo nó
};

// Função para inserir um elemento no inicio da lista
void insert(struct Node** head, char* newData) {
    // Aloca memoria para o novo nó
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Copia os dados para o novo nó
    strcpy(newNode ->data, newData);

    // Define o proximo do novo nó como o antigo inicio da lista
    newNode ->next = *head;

    // Define o novo nó como o inicio da lista
    *head = newNode;
}

// Função para imprimir os elementos da lista
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%s", node ->data);
        node = node->next;
    }
    printf("\n");
}

int main () {
    // Inicializa a lista como vazia
    struct Node* head = NULL;

    // Insere elementos na lista
    insert(&head, " exemplo!!!");
    insert(&head, " um");
    insert(&head, " e");
    insert(&head, " este");
    insert(&head, " Oi");

    // Imprime os elementos da lista
    printf("Lista ligada de strings: ");
    printList(head);

    return 0;
}