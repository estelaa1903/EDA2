#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "users.h"
#include "menu.h"
int encontrado;
void new_usuario(List_Users **l){  //crear nuevo usuario
    usuario user;
    char usu[MAX_USUARIO], larg[MAX_LENGTH];
    printf("\n-Cual es su nombre de usuario? (MAX. 15)");
    scanf("%s", usu);
    strcpy(user.nombre, usu);

    printf("\n-Cual es su edad?");
    scanf("%d", &user.edad);

    printf("\n-Cual es su correo electronico? (MAX. 50)");
    scanf("%s", larg);
    strcpy(user.correo, larg);

    printf("\n-Cual es su Ciudad?(MAX. 50)");
    scanf("%s", larg);
    strcpy(user.ubi, larg);

    printf("\nListe 5 preferencias:");
    printf("\nNum. 1:");
    scanf("%s",larg);
    strcpy(user.pref.pref1, larg);

    printf("\nNum. 2:");
    scanf("%s",larg);
    strcpy(user.pref.pref2, larg);

    printf("\nNum. 3:");
    scanf("%s",larg);
    strcpy(user.pref.pref3, larg);

    printf("\nNum. 4:");
    scanf("%s",larg);
    strcpy(user.pref.pref4, larg);

    printf("\nNum. 5:");
    scanf("%s",larg);
    strcpy(user.pref.pref5, larg);

    List_Users *new_list = malloc(sizeof(List_Users));
    new_list->user = user;
    new_list->next = NULL;

    if(*l == NULL){
        *l = new_list;
    }
    else {
        List_Users *current = l;
        while (current->next != NULL){
            current = current->next;
        }
        current->next = new_list;
    }
    (*l)->total_users++;
}


void listar(List_Users *l ){ //print users
    if(l==NULL){
        printf("No hay usuarios para listar\n");
        return;
    }
    else{
        List_Users *current = l;
        while (current != NULL) {
            printf("%s\n", current->user.nombre);
            current = (List_Users*)current->next;
        }
    }
}

void op_usuario(List_Users *l){
    char nombre_usuario[MAX_USUARIO];
    usuario *select_user;
    printf("Ingresa el nombre del usuario:  ");
    scanf("%s", nombre_usuario);
    select_user=busqueda(l,nombre_usuario);
    printf("%d",encontrado);
    if(encontrado==1){

        printf("Has iniciado sesion como %s\n",select_user->nombre);
        int option1;
        do{
            show_submenu();
            printf("Selecciona una opcion:");
            scanf("%d", &option1);
            if(option1==1){//enviar solicitud

            }
            if (option1==2){//gestionar solicitudes

            }
            if (option1==3){//realizar publicacion

            }
            if (option1==4){//listar publicaciones

            }
        }while(option1!=5);
    }
    else {
        printf("Usuario no encontrado\n");
    }

}
usuario* busqueda(List_Users *l,char nombre[MAX_USUARIO]){ // buscar usuario
    List_Users* current = l;
    encontrado=0;
    while (current != NULL) {
        if (strcmp(nombre, current->user.nombre) == 0) {
            encontrado=1;
            return &current->user;
        }
        current = (List_Users *) current->next;
    }
    return &current->user;
}

void leer_file(List_Users **l){
    FILE *f;
    usuario user;
    f = fopen("fichero_usuarios/file_users.txt", "r");
    if(f!=NULL){
        List_Users *new_list = malloc(sizeof(List_Users));
        while(fscanf(f, "%s %d %s %s %s %s %s %s %s", user.nombre, &user.edad, user.correo, user.ubi, user.pref.pref1, user.pref.pref2, user.pref.pref3, user.pref.pref4, user.pref.pref5) == 9){
            new_list->user = user;
            new_list->next = NULL;

            if(*l == NULL){
                *l = new_list;
            }
            else {
                List_Users *current = *l;
                while (current->next != NULL){
                    current = current->next;
                }
                current->next = new_list;
            }
            (*l)->total_users++;
        }
        printf("Usuarios registrados con exito\n");
        fclose(f);
    }
    else {
        perror("Error al abrir el archivo");
    }
}