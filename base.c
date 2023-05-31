//
//
//
#include "main.h"
#include "base.h"
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
        List_Users *current = *l;
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
            current = current->next;
        }
    }

}
usuario busqueda(List_Users *l,char nombre[MAX_USUARIO]){ // buscar usuario
    encontrado=0;
    List_Users* current = l;
    while (current != NULL) {
        if (strcmp(nombre, current->user.nombre) == 0) {
            encontrado=1;
            return current->user;
        }
        current = current->next;
    }
    return current->user;
}

void op_usuario(List_Users *l){
    char nombre_usuario[MAX_USUARIO];
    usuario select_user;
    printf("Ingresa el nombre del usuario:  ");
    scanf("%s", nombre_usuario);
    select_user=busqueda(l,nombre_usuario);

    if(encontrado==1){
        //lo encuentra

        printf("Has iniciado sesion como %s\n",nombre_usuario);
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
    else{
        printf("Usuario no encontrado\n");
    }
}





/*usuario Select(List_Users *l,char nombre[MAX_USUARIO]){//vuelve a buscar el usuario y lo retorna
    for(int i=0; i<l->total_users;i++){
        if(nombre==&l->user){
            return l->user;
        }
        else{
            l=l->next;
        }
    }
}*/
/*int leer_archivo(){
    FILE* archivo= fopen("Users.csv","r");
    if(archivo==NULL){
        printf("Hubo un error en abrir al archivo");
        return 1;
    }
    char linea[1024];
    while(fgets(linea,sizeof(linea),"Users.csv")){
        usuario user;
        char *campo =strtok(linea,",");
        campo = strtok(NULL,",");
        user.edad= atoi(campo);
    }
    fclose(archivo);
}*/

/*int leer_archivo_mi_forma_xd(){
    List_Users *l;
    FILE * archivo=fopen("Users.csv","r");
    if(archivo= NULL){
        printf("No se pudo abrir el archivo");
        return 1;
    }
    usuario new_user;
    while(!feof(archivo)){
        fscanf(archivo,"%s, %d, %s, %s, %s, %s, %s, %s, %s",new_user.nombre,new_user.edad,new_user.correo,new_user.ubi,new_user.pref.pref1, new_user.pref.pref2, new_user.pref.pref3, new_user.pref.pref4, new_user.pref.pref5);
        new_lista(new_user,l);
    }
}*/