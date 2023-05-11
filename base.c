//
//
//

#include "base.h"

List_Users new_usuario(){
    List_Users l;
    int n;
    char usu[MAX_USUARIO], larg[MAX_LENGTH];
    printf("¿Cual es su nombre de usuario? (MAX. 15)");
    scanf("%s", &usu);
    strcpy(l.user.nombre, usu);

    printf("¿Cual es su edad?");
    scanf("%d", &l.user.edad);

    printf("¿Cual es su correo electronico? (MAX. 50)");
    scanf("%s", &larg);
    strcpy(l.user.correo, larg);

    printf("¿Cual es su Ciudad? (MAX. 50)");
    scanf("%s", &larg);
    strcpy(l.user.ubi, larg);

    printf("Liste 5 preferencias:");
    printf("\nNum. 1:");
    scanf("%s",&larg);
    strcpy(l.user.pref.pref1, larg);

    printf("\nNum. 2:");
    scanf("%s",&larg);
    strcpy(l.user.pref.pref2, larg);

    printf("\nNum. 3:");
    scanf("%s",&larg);
    strcpy(l.user.pref.pref3, larg);

    printf("Num. 4:");
    scanf("%s",&larg);
    strcpy(l.user.pref.pref4, larg);

    printf("Num. 5:");
    scanf("%s",&larg);
    strcpy(l.user.pref.pref5, larg);
    l.total_users++;
    return l;
}
void new_lista(usuario  user){ //funcion que añade un usuario
    List_Users *new_user = (List_Users*)malloc(sizeof(List_Users));
    new_user->user=user;
    new_user->next=NULL;
    new_user->prev= NULL;
    if(list==NULL){
        list=new_user;
    }
    else {
        List_Users *current= lista;
        while (current->next!=NULL){
            current=current->next;
        }
        current->next= new_user;
        new_user->prev= current;
    }



}

void listar(List_Users l ){

for(int i=0;i<l.numusers; i++){
    printf("%s", l.user.nombre);

}
}