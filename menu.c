//
//
//

#include "menu.h"
#include "main.h"

void show_menu(){
    printf("-----------------------------------------\n");
    printf("1. Introduce el usuario \n");
    printf("2. Listar usuarios \n");
    printf("3. Operar como usuario \n");
    printf("4. Salir \n");
    printf("-----------------------------------------\n");

}
void show_submenu(){
    printf("-----------------------------------------\n");
    printf("1. Enviar solicitud de amistad \n");
    printf("2. Gestionar solicitudes pendientes \n");
    printf("3. Realizar una publicacion \n");
    printf("4. Listar publicaciones del usuario \n");
    printf("5. Volver al menu principal \n");
    printf("-----------------------------------------\n");

}
int elegirm(int opcion, List_Users *l){
    int subm;
    usuario u;
    if(opcion==1){
        u=new_usuario();
        new_lista(u,l);
        return 0;
    }
    else if(opcion==2){
        listar(l);
        return 0;
    }else if(opcion==3){
        u=busqueda(l);
        show_submenu();
        subm=comprobarsm();
        elegirsm(subm, u);
        return 0;
    }else if(opcion==4){
        return 1;
    }
    }

int comprobarm(){
    int opcion;
    printf("Elige una opcion: (1-4)\n");
    scanf("%d", &opcion);
    while (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4) {
        printf("Opcion erronea\nElige otra opcion: (1-4)\n");
        scanf("%d", &opcion);
    }
    return opcion;
}

void elegirsm(int opcion, usuario u){// elegir opcion submenu
    if(opcion==1){

    }
    else if(opcion==2){

    }else if(opcion==3){


    }else if(opcion==4){

    }
}
int comprobarsm(){
    int opcion;
    printf("Elige una opcion: (1-5)");
    scanf("%d", &opcion);
    while (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5) {
        printf("Opcion erronea\nElige otra opcion: (1-5)\n");
        scanf("%d", &opcion);
    }
    return  opcion;
}