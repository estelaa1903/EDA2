#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "users.h"
#include "menu.h"

int encontrado;

void new_usuario(List_Users** l) {
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
    printf("%d\n", encontrado);
    if (encontrado == 1) {
        printf("Has iniciado sesion como %s\n", select_user->nombre);
        int option1;
        do {
            show_submenu();
            printf("Selecciona una opcion:");
            scanf("%d", &option1);
            if (option1 == 1) { //enviar solicitud

            }
            if (option1 == 2) { //gestionar solicitudes

            }
            if (option1 == 3) { //realizar publicacion

            }
            if (option1 == 4) { //listar publicaciones

            }
        } while (option1 != 5);
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
        printf("Usuarios registrados con exito\n");
        fclose(file);

        // After adding users from the file, list them
    } else {
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
// Función para crear un nuevo nodo de solicitud
Node* crearNodo(solicitudes solicitud) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Asigna memoria para un nuevo nodo
    strcpy(newNode->solicitud.n_solicitud, solicitud.n_solicitud); // Copia la solicitud en el nodo
    newNode->siguiente = NULL; // Establece el puntero siguiente como NULL
    return newNode; // Devuelve el puntero al nuevo nodo
}

// Función para insertar una solicitud en la cola
void insertarSolicitud(usuario* user, solicitudes solicitud) {
    Node* newNode = crearNodo(solicitud); // Crea un nuevo nodo con la solicitud
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

// Función para procesar la siguiente solicitud de amistad en la cola
void procesarSolicitud(usuario* user) {
    if (user->cola_solicitudes != NULL) { // Si la cola no está vacía
        Node* temp = user->cola_solicitudes; // Puntero temporal para el nodo a procesar
        user->cola_solicitudes = temp->siguiente; // Actualiza el frente de la cola
        // Aquí puedes escribir la lógica para aceptar o denegar la solicitud
        // Por ejemplo, si se acepta, puedes agregar al usuario en la lista de amigos aceptados
        // Puedes usar la estructura List_Users para almacenar los amigos aceptados
        free(temp); // Libera la memoria del nodo eliminado
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


