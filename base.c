//
//
//

#include "base.h"

void new_usuario(){
    usuario us;
    List_Users l;
    int n;
    char usu[MAX_USUARIO], larg[MAX_LENGTH];
    printf("¿Cual es su nombre de usuario? (MAX. 15)");
    scanf("%s", &usu);
    strcpy(us.nombre, usu);

    printf("¿Cual es su edad?");
    scanf("%d", &n);
    us.edad=n;

    printf("¿Cual es su correo electronico? (MAX. 50)");
    scanf("%s", &larg);
    strcpy(us.correo, larg);

    printf("¿Cual es su Ciudad? (MAX. 50)");
    scanf("%s", &larg);
    strcpy(us.ubi, larg);

    printf("Liste 5 preferencias:");
    printf("\nNum. 1:");
    scanf("%s",&larg);
    strcpy(us.pref.pref1, larg);

    printf("\nNum. 2:");
    scanf("%s",&larg);
    strcpy(us.pref.pref2, larg);

    printf("\nNum. 3:");
    scanf("%s",&larg);
    strcpy(us.pref.pref3, larg);

    printf("Num. 4:");
    scanf("%s",&larg);
    strcpy(us.pref.pref4, larg);

    printf("Num. 5:");
    scanf("%s",&larg);
    strcpy(us.pref.pref5, larg);

    l.numusers+=1;

}
void new_lista(usuario, List_Users){


}
int lista(){}
void listar(List_Users l ){

for(int i=0;i<l.numusers; i++){
    printf("%s", l.user.nombre);

}
}