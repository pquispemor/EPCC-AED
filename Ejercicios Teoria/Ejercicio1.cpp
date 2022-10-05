//Ejercicio 1
/*VER si el codigo de la pagina 43 presenta errores*/

void DLLDelete(struct DLLNode **head, int position){
    //struct DLLNode *temp, *temp2, temp = (*head); error ya que el temp se esta volviendo a llamar en la misma linea
    // La solucion seria poner el segundo temp en la siguiente linea.
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
