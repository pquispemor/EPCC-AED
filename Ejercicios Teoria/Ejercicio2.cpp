//Ejercicio 2
/*Del codigo de la pagina 43: descomponer el Delete en 3 partes
(Inicio, Fin , Intermedio)*/

#include <iostream>
using namespace std;
struct DLLNode
{
    int data;
    struct DLLNode *next;
    struct DLLNode *prev;
};


void DLLPush(struct DLLNode **head, int n);
void Imprimir(struct DLLNode **head);
void DLLDeleteFirst(DLLNode **head);
void DLLDeleteEnd(DLLNode **head);
void DLLDeleteIntermediate(DLLNode **head, int position);


int main (){
    struct DLLNode *head = NULL;
    std::cout << "Double Linked List";
    DLLPush(&head,5);
    DLLPush(&head,8);
    DLLPush(&head,1);
    DLLPush(&head,2);
    Imprimir(&head);
    DLLDeleteFirst(&head);
    Imprimir(&head);
    DLLDeleteEnd(&head);
    Imprimir(&head);
    DLLDeleteIntermediate(&head,3);
    Imprimir(&head);
    return 0;
}

void DLLPush(DLLNode **head, int n){
    DLLNode *new_node = new DLLNode();
    new_node->data = n;

    new_node->next = (*head);
    new_node->prev = NULL;

    if((*head) != NULL){
        (*head)->prev = new_node;
    }
    (*head) = new_node;

    cout << "\nInsertaste correctamente el dato: " << n << endl;
}

void Imprimir(struct DLLNode **head){
    DLLNode *actual = new DLLNode();
    actual = (*head);
    if(*head == NULL){
        printf("List is empty\n");
        return;
    }
    else{
        while(actual != NULL){
            cout << actual->data << " -> ";
            actual = actual->next;
        }
        cout << endl;
    }
}

void DLLDeleteFirst(DLLNode **head){
    struct DLLNode *temp;
    temp = (*head);
    if(*head == NULL){
        printf("List is empty");
        return;
    }
    else{
        *head=(*head)->next;
    if (*head != NULL)
        (*head)->prev = NULL;
    free(temp);
    return;
    }
}
void DLLDeleteEnd(DLLNode **head){
    struct DLLNode *temp, *temp2;
    temp = (*head);
    if(*head == NULL){
        printf("List is empty");
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp2 = temp->prev;
    temp2->next = temp->next;

    free(temp);
    return;
}
void DLLDeleteIntermediate(DLLNode **head, int position){
    struct DLLNode *temp, *temp2;
    temp = (*head);
    int k=1; 
    if(*head == NULL){
        printf("List is empty");
        return;
    }
    if (position == 1){
        *head=(*head)->next;
    if (*head != NULL)
        (*head)->prev = NULL;
    free(temp);
    return;
    }
    while((k<position) && temp->next != NULL){
        temp = temp->next;
        k++;
    }
    if(k!=position-1){
        printf("Desired position does not exist\n");
    }

    temp2 = temp->prev;
    temp2->next = temp->next;

    if(temp->next) // Deletion from intermediate Node
        temp->next->prev = temp2;
    free(temp);
    
    return;
}