#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "users.h"
#include "menu.h"

EntradaDiccionario diccionario[10];
int numPalabras = 0;
int encontrado;
void new_usuario(List_Users** l) {
    usuario user;
    char usu[MAX_USUARIO], larg[MAX_LENGTH];
    do {
        printf("\n-Cual es su nombre de usuario? (MAX. 15)\n");
        scanf("%s", usu);
        busqueda(*l,usu);
        if (encontrado==1){
            printf("El usuario introducido ya es existente.\n");
        }
        else{
            strcpy(user.nombre, usu);
        }
    }while(encontrado==1);

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
    scanf("%s", larg);
    strcpy(user.pref.pref1, larg);

    printf("\nNum. 2:");
    scanf("%s", larg);
    strcpy(user.pref.pref2, larg);

    printf("\nNum. 3:");
    scanf("%s", larg);
    strcpy(user.pref.pref3, larg);

    printf("\nNum. 4:");
    scanf("%s", larg);
    strcpy(user.pref.pref4, larg);

    printf("\nNum. 5:");
    scanf("%s", larg);
    strcpy(user.pref.pref5, larg);

    List_Users* new_list = malloc(sizeof(List_Users));
    new_list->user = user;
    new_list->next = NULL;
    new_list->user.amigos= NULL;
    new_list->user.cola_solicitudes= NULL;
    if (*l == NULL) {
        *l = new_list;
    } else {
        List_Users* current = *l;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_list;
    }
    (*l)->total_users++;
}

void listar(List_Users* l) {
    if (l == NULL) {
        printf("No hay usuarios para listar\n");
        return;
    } else {
        List_Users* current = l;
        while (current != NULL) {
            printf("%s\n", current->user.nombre);
            current = current->next;
        }
    }
}

void op_usuario(List_Users* l) {
    char nombre_usuario[MAX_USUARIO];
    usuario* select_user;
    printf("Ingresa el nombre del usuario:  ");
    scanf("%s", nombre_usuario);
    select_user = busqueda(l, nombre_usuario);
    if (encontrado == 1) {
        printf("Has iniciado sesion como %s\n", select_user->nombre);
        int option1;
        do {
            show_submenu();
            printf("Selecciona una opcion:");
            scanf("%d", &option1);
            if (option1 == 1) { //enviar solicitud
                enviarSolicitud(l, select_user);

            }
            else if (option1 == 2) { //gestionar solicitudes
                procesarSolicitudesPendientes(select_user);
            }
            else if (option1 == 3) {//realizar publicacion.
                char texto[MAX_PUB];
                printf("Ingresa el texto de la publicacion (max. 120 caracteres): ");
                scanf(" %[^\n]", texto);
                realizar_publicacion(select_user, texto);
                printf("Publicacion realizada con exito.\n");

            }
            else if(option1 ==4){// Mostrar historial de publicaciones
                mostrarHistorial(select_user);

            }
            else if (option1 == 5) { //Mostrar amigos
                mostrarAmistades(select_user);
            }else if (option1 == 6) { //Ir al menu principal
               printf("Volviendo al menu principal... \n");
            }
            else{
                printf("Opcion Invalida\n");
            }
        } while (option1 != 6);
    } else {
        printf("Usuario no encontrado\n");
    }
}

usuario* busqueda(List_Users* l, char nombre[MAX_USUARIO]) {
    List_Users* current = l;
    encontrado = 0;
    while (current != NULL) {
        if (strcmp(nombre, current->user.nombre) == 0) {
            encontrado = 1;
            return &(current->user);
        }
        current = current->next;
    }
    return NULL;
}

void leer_file(List_Users** l) {
    FILE* file;
    usuario user;
    file = fopen("file_users.txt", "r");
    if (file != NULL) {
        while (fscanf(file, "%s %d %s %s %s %s %s %s %s", user.nombre, &user.edad, user.correo, user.ubi, user.pref.pref1, user.pref.pref2, user.pref.pref3, user.pref.pref4, user.pref.pref5) == 9) {
            List_Users* new_list = malloc(sizeof(List_Users));
            new_list->user = user;
            new_list->next = NULL;
            new_list->user.amigos= NULL;
            new_list->user.cola_solicitudes= NULL;

            if (*l == NULL) {
                *l = new_list;
            }
            else {
                List_Users* current = *l;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = new_list;
            }
            (*l)->total_users++;
        }
        printf("Usuarios registrados con exito\n");
        fclose(file);
    }
    else {
        perror("Error al abrir el archivo");
    }
}

void liberar_memoria(List_Users *l) {
    List_Users *current = l;
    List_Users *temp;
    while (current != NULL) {
        temp = current;
        current = (List_Users *)current->next;
        free(temp);
    }
}
// Función para insertar una solicitud en la cola
void insertarSolicitud(usuario* user, char nombre[MAX_USUARIO]) {
    Node* newNode = malloc(sizeof(Node)); // Crea un nuevo nodo con la solicitud
    strcpy(newNode->name_sol, nombre); // Guarda el nombre del usuario que envió la solicitud
    newNode->siguiente=NULL;

    if (user->cola_solicitudes == NULL) { // Si la cola está vacía
        user->cola_solicitudes = newNode; // El nuevo nodo se convierte en el frente de la cola
    } else {
        Node* temp = user->cola_solicitudes; // Puntero temporal para recorrer la cola
        while (temp->siguiente != NULL) { // Recorre la cola hasta el último nodo
            temp = temp->siguiente;
        }
        temp->siguiente = newNode; // Agrega el nuevo nodo al final de la cola
    }
}

// Función para mostrar las amistades aceptadas
void mostrarAmistades(usuario* user) {
    if (user->amigos == NULL) { // Si la lista de amigos está vacía
        printf("No tienes amistades aceptadas.\n");
    } else {
        List_Users* temp = user->amigos; // Puntero temporal para recorrer la lista de amigos
        printf("Tus amistades aceptadas son:\n");
        while (temp != NULL) { // Recorre la lista hasta el final
            printf("- %s\n", temp->user.nombre); // Imprime el nombre del amigo
            temp = temp->next; // Avanza al siguiente nodo
        }
    }
}
void enviarSolicitud(List_Users* l, usuario* user) {
    char nombre[MAX_USUARIO];
    usuario* req_user;
    printf("Ingresa el nombre del usuario al que deseas enviar la solicitud: ");
    scanf("%s", nombre);
    req_user = busqueda(l, nombre);
    if (encontrado == 1) {
        // Inserta aquí la lógica para enviar la solicitud de amistad
        insertarSolicitud(req_user, user->nombre);
        printf("Solicitud enviada a %s\n", req_user->nombre);
    } else {
        printf("El usuario no fue encontrado\n");
    }
}
int aceptarSolicitud(usuario* user, char nombre[MAX_USUARIO]) {
    // Buscar la solicitud en la cola de solicitudes pendientes
    Node* temp = user->cola_solicitudes;
    Node* prev = NULL;
    while (temp != NULL) {
        if (strcmp(temp->name_sol, nombre) == 0) {
            // Mostrar la solicitud al usuario y solicitar su decisión
            printf("Has recibido una solicitud de amistad de %s\n", nombre);
            printf("Deseas aceptarla? (s/n): ");
            char decision;
            scanf(" %c", &decision);

            if (decision == 's' || decision == 'S') {
                // Aceptar la solicitud y agregar al usuario a la lista de amigos
                if (user->amigos == NULL) {
                    user->amigos = malloc(sizeof(List_Users));
                    strcpy(user->amigos->user.nombre, nombre);
                    user->amigos->next = NULL;
                } else {
                    List_Users* amigoTemp = user->amigos;
                    while (amigoTemp->next != NULL) {
                        if (strcmp(amigoTemp->user.nombre, nombre) == 0) {
                            printf("Ya eres amigo de %s.\n", nombre);
                            return 0;
                        }
                        amigoTemp = amigoTemp->next;
                    }

                    List_Users* nuevoAmigo = malloc(sizeof(List_Users));
                    strcpy(nuevoAmigo->user.nombre, nombre);
                    nuevoAmigo->next = NULL;
                    amigoTemp->next = nuevoAmigo;
                }

                // Eliminar la solicitud de la cola de solicitudes pendientes
                if (prev == NULL) {
                    user->cola_solicitudes = temp->siguiente;
                } else {
                    prev->siguiente = temp->siguiente;
                }

                free(temp);
                return 1; // Solicitud aceptada correctamente
            } else {
                // Rechazar la solicitud
                printf("Has rechazado la solicitud de amistad de %s\n", nombre);

                // Eliminar la solicitud de la cola de solicitudes pendientes
                if (prev == NULL) {
                    user->cola_solicitudes = temp->siguiente;
                } else {
                    prev->siguiente = temp->siguiente;
                }

                free(temp);
                return 0; // Solicitud rechazada
            }
        }

        prev = temp;
        temp = temp->siguiente;
    }

    // La solicitud no fue encontrada en la cola de solicitudes pendientes
    printf("No se encontró ninguna solicitud de amistad de %s\n", nombre);
    return 0; // Solicitud no encontrada
}


void procesarSolicitudesPendientes(usuario* user) {
    // Verificar si hay solicitudes pendientes
    if (user->cola_solicitudes == NULL) {
        printf("No tienes solicitudes pendientes.\n");
        return;
    }

    printf("Tienes solicitudes pendientes:\n");
    int i = 1;
    Node* temp = user->cola_solicitudes;
    while (temp != NULL) {
        printf("%d. Usuario: %s\n", i, temp->name_sol);
        temp = temp->siguiente;
        i++;
    }

    printf("Selecciona la solicitud que deseas procesar (ingresa el numero): ");
    int opcion;
    scanf("%d", &opcion);

    // Obtener el nombre del usuario seleccionado
    temp = user->cola_solicitudes;
    for (int j = 1; j < opcion; j++) {
        temp = temp->siguiente;
    }
    char nombre[MAX_USUARIO];
    strcpy(nombre, temp->name_sol);

    // Procesar la solicitud seleccionada
    if (aceptarSolicitud(user, nombre)) {
        printf("Solicitud aceptada correctamente.\n");
    } else {
        printf("No se pudo procesar la solicitud.\n");
    }
}

void realizar_publicacion(usuario* user, const char* texto) {
    // Crear una nueva publicación
    publicacion* nueva_publicacion = malloc(sizeof(publicacion));
    strcpy(nueva_publicacion->pub, texto);
    nueva_publicacion->siguiente = NULL;

    // Insertar la nueva publicación al inicio de la lista de publicaciones
    nueva_publicacion->siguiente = user->publicaciones;
    user->publicaciones = nueva_publicacion;
    user->num_pub++;

    // Actualizar el diccionario con las palabras de la publicación
    char copia_texto[MAX_PUB];
    strcpy(copia_texto, texto);
    char* token = strtok(copia_texto, " ");
    while (token != NULL) {
        agregarPalabraDiccionario(token);
        token = strtok(NULL, " ");
    }
}

void mostrarHistorial(usuario* user) {

    if (user->num_pub == 0) {
        printf("No has realizado ninguna publicacion.\n");
        return;
    }
    else{
        printf("Historial de publicaciones:\n");
        publicacion* current = user->publicaciones;
        int count = 0;
        int k;
            while (count<user->num_pub) {
                k = user->num_pub-count;
                printf("%d. %s\n", k, current->pub);
                current = current->siguiente;
                count++;
            }
    }
}
void inicializarDiccionario() {
    for (int i = 0; i < 10; i++) {
        strcpy(diccionario[i].palabra,"");
        diccionario[i].conteo = 0;
    }
}

void agregarPalabraDiccionario(char* palabra) {
    for (int i = 0; i < numPalabras; i++) {
        if (strcmp(diccionario[i].palabra, palabra) == 0) {
            diccionario[i].conteo++;
            return;
        }
    }

    if (numPalabras < MAX_PALABRAS) {
        strcpy(diccionario[numPalabras].palabra, palabra);
        diccionario[numPalabras].conteo = 1;
        numPalabras++;
    }
}

void mostrarTop10Palabras() {
    if (numPalabras == 0) {
        printf("No hay palabras registradas.\n");
        return;
    }

    // Ordenar el diccionario en orden descendente por conteo utilizando el algoritmo de inserción
    for (int i = 1; i < numPalabras; i++) {
        EntradaDiccionario temp = diccionario[i];
        int j = i - 1;
        while (j >= 0 && diccionario[j].conteo < temp.conteo) {
            diccionario[j + 1] = diccionario[j];
            j--;
        }
        diccionario[j + 1] = temp;
    }

    printf("Top 10 palabras mas usadas:\n");
    for (int i = 0; i < numPalabras && i < 10; i++) {
        printf("%d. %s (%d veces)\n", i + 1, diccionario[i].palabra, diccionario[i].conteo);
    }
}

