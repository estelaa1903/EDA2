//
//
//

#include "base.h"

usuario new_usuario(){
     usuario user;
    char usu[MAX_USUARIO], larg[MAX_LENGTH];
    printf("¿Cual es su nombre de usuario? (MAX. 15)");
    scanf("%s", &usu);
    strcpy(user.nombre, usu);

    printf("¿Cual es su edad?");
    scanf("%d", &user.edad);

    printf("¿Cual es su correo electronico? (MAX. 50)");
    scanf("%s", &larg);
    strcpy(user.correo, larg);

    printf("¿Cual es su Ciudad? (MAX. 50)");
    scanf("%s", &larg);
    strcpy(user.ubi, larg);

    printf("Liste 5 preferencias:");
    printf("\nNum. 1:");
    scanf("%s",&larg);
    strcpy(user.pref.pref1, larg);

    printf("\nNum. 2:");
    scanf("%s",&larg);
    strcpy(user.pref.pref2, larg);

    printf("\nNum. 3:");
    scanf("%s",&larg);
    strcpy(user.pref.pref3, larg);

    printf("Num. 4:");
    scanf("%s",&larg);
    strcpy(user.pref.pref4, larg);

    printf("Num. 5:");
    scanf("%s",&larg);
    strcpy(user.pref.pref5, larg);
    return user;
}
 List_Users* new_lista(usuario new_user,List_Users *l){ //añadir al main
    List_Users *new_list = (List_Users*)malloc(sizeof(List_Users));
    new_list->user=new_user;
    new_list->next=NULL;
     if(l->total_users==0){
         l = new_list;
    }
    else {
        while (l->next!=NULL){
            l= l->next;
        }
        l->next= new_list;
    }
     l->total_users++;
}

void listar(List_Users l ){

for(int i=0;i<l.numusers; i++){
    printf("%s", l.user.nombre);

}
}