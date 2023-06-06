#include <string.h>
#include "stdio.h"
#include <stdlib.h>
#include "users.h"


// Función para crear un nuevo nodo de solicitud
Node* crearNodo(solicitudes solicitud) {
    Node* newNode = malloc(sizeof(Node)); // Asigna memoria para un nuevo nodo
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

//Función para procesar la siguiente solicitud de amistad en la cola
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
