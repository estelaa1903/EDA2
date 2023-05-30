//
//
//
#include "main.h"
#include "base.h"

usuario new_usuario(){
     usuario user;
    char usu[MAX_USUARIO], larg[MAX_LENGTH];
    printf("\n-Cual es su nombre de usuario? (MAX. 15)");
    scanf("%s", usu);
    strcpy(user.nombre, usu);

    printf("\n-Cual es su edad?");
    scanf("%d", &user.edad);

    printf("\n-Cual es su correo electronico? (MAX. 50)");
    scanf("%s", &larg);
    strcpy(user.correo, larg);

    printf("\n-Cual es su Ciudad?(MAX. 50)");
    scanf("%s", &larg);
    strcpy(user.ubi, larg);

    printf("\nListe 5 preferencias:");
    printf("\nNum. 1:");
    scanf("%s",&larg);
    strcpy(user.pref.pref1, larg);

    printf("\nNum. 2:");
    scanf("%s",&larg);
    strcpy(user.pref.pref2, larg);

    printf("\nNum. 3:");
    scanf("%s",&larg);
    strcpy(user.pref.pref3, larg);

    printf("\nNum. 4:");
    scanf("%s",&larg);
    strcpy(user.pref.pref4, larg);

    printf("\nNum. 5:");
    scanf("%s",&larg);
    strcpy(user.pref.pref5, larg);
    return user;
}
 void new_lista(usuario new_user,List_Users *l){ //añadir al main
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
     l->total_users++;//
}

void listar(List_Users *l ){ //print users
    for(int i=0;i<l->total_users; i++) {
        printf("%s", l->user.nombre);
        l = l->next;
    }
}

usuario busqueda(List_Users *l){ // buscar usuario lo retorna para operar con el.
    char nombre[MAX_USUARIO];
    int si=1;
    scanf("%s",&nombre);
    while(si!=0) {
        si=strcmp(nombre,l->user.nombre);
        l = l->next;
    }
    return l->user;
}

int leer_archivo(){
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
}

int leer_archivo_mi_forma_xd(){
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
}