# EDA2
Nuestra red social
26/04/2023
    




ESTRUCTURAS DE DATOS Y ALGORITMOS II, 2022-2023
Información sobre TÍTULO DE PROYECTO


Alex Alastuey Centeno, Estela Callejón Molina, Marc Cano Lafarga

NIA: 268167, 266667, 269701

11 de junio 2023

# MEMORIA DEL PROYECTO UNICONNECT

## INTRODUCCIÓN
(LO TENGO QUE CAMBIAR)
El objetivo para este proyecto es crear una red social para estudiantes donde se puedan realizar publicaciones(es decir escritos) relacionados con el ámbito académico. 
Para poder realizar este sistema, se necesita una list_Users que consiste una estructura, donde incluye los datos de cada usuario y un puntero al siguiente usuario. 
Esta lista debera de estar declarada como variable global en la función main para qu eno se eliminen los usuarios introducidos durante la ejecución del programa. 
Además habrá que crear funciones de búsqueda de usuarios dentro de la lista global para poder realizar acciones como: operar como usuario, enviar solicitud de amistad y otras más. 
El programa debera de ser capaz de tener un sistema de inicio de sesión de un usuario introducido ya sea manualmente o por medio de un fichero, ademas de poder agregar amigos. 
Al final de la construcción del proyecto todos los objetivos propuestos han sido alcanzados correctamente y el programa es completamente funcional.

## Objetivos

Para poder empezar el proyecto se hará uso de un sistema que guarde los usuarios dentro de la red social. La estructura de datos de lista es la mejor opción, de esta forma 
se tendrá una lista de usuarios donde se pueda registrar todos los datos necesarios de un usuario. Se hará una estructura llamada List_Users donde se guardaran los datos de un usuario,
y un puntero a otra estructura List_Users siguiente para poder acceder y guardar otros usuarios(también una variable entera que haga de contador de usuarios registrados total_users).
También para tenerlo de forma ordenada y visual, se hará uso de otra estructura usuario, que guardará todos los datos que debería tener (esta estructura está incluida en List_Users).

### Menu

Una vez cumplidos estos objetivos, ya se puede empezar a desarrollar el funcionamiento de la red social. Lo primero de todo es crear un menu principal que funcione como una interfaz
para que sea más cómodo navegar por la aplicación; se hará uso de la función "printf" para mostrar en pantalla las opciones además de hacer un diseño.
Para finalizar el apartado del menu, hay que codificar el sistema para elegir que acción se quiere realizar, para esto un scanf que permita al usuario seleccionar la opción mediante
un número entero.

### Funciones menu

**New_usuario**

La primera opción del programa es introducir un usuario de forma manual, se codificará en el archivo users.c al igual que las demás funciones. La funcionalidad de la función new_usuario,
consistirá en que vaya pidiendo datos necesarios para registrar un usuario en la red social. En dicha función se creará una variable local de estructura usuario para poder registrar
la información (La lista de usuarios será pasada como parámetro por referencia para que asi pueda ser modificada). Una vez introducido todos los datos teniendo en cuenta que el nombre de 
usuario es único, se usara un algoritmo para recorrer la lista de usuarios comprobando si el puntero al siguiente usuario es nulo o no; en el caso que sea nulo se introducirá el nuevo 
usuario en ese nodo apuntando a un siguiente nulo.

**Leer_file**

Para la de leer_file primero se tiene que crear un fichero con los datos de los usuarios separados por un espacio, en el caso que el archivo no esté creado o no pueda ser abierto
un mensaje en pantalla será mostrado informando al cliente que no se pudo abrir. Si el archivo se pudo abrir correctamente se irá escaneando cada línea del fichero y guardando los usuarios
con el mismo método usado en la función de new_usuario. Al principio hemos tenido muchos errores para que funcione correctamente com por ejemplo: Tener el archivo creado y que no lo 
abriera y que abriera el archivo pero que no guarde los usuarios en la lista. Finalmente el error fue solucionado, el motivo era la ubicación del archivo que no se estaba teniendo en cuenta,
se añadió el fichero a la carpeta del cmake y empezó a funcionar correctamente.

**Listar**

Muestra los nombres de los usuarios registrados en la red social, si no hay ninguno imprime un mensaje de que informa que no hay usuarios registrados. En el caso que si haya usuarios,
se creara una variable temporal List_Users para recorrer la lista y con un printf y una condición while se irá imprimiendo el nombre del usuario y comprobando que el nodo no sea nulo.
Esta función fue implementada de una manera rápida y no obtuvimos ningún error a destacar.

**MostrarTop10Palabras**

La función "mostrarTop10Palabras" se encarga de mostrar las 10 palabras más utilizadas en un diccionario. Antes que nada para que el diccionario funcione correctamente tendremos que 
crear la estructura diccionario que contiene una variable tipo char "palabra" que es la palabra y una variable int "conteo" que se refiere a cuantas veces ha aparecido esa palabra.
En primer lugar, realiza una verificación para determinar si hay palabras registradas en el diccionario. En caso de no encontrar ninguna palabra, imprime un mensaje indicando que no hay palabras registradas y finaliza la función. Si hay palabras registradas, 
la función procede a ordenar el diccionario en orden descendente según el conteo de cada palabra. Para lograr esto, se utiliza el algoritmo de inserción. Este algoritmo compara cada 
entrada del diccionario con las anteriores, desplazando las palabras hacia la derecha si su conteo es mayor. Una vez que el diccionario está ordenado, se imprime el encabezado 
"Top 10 palabras más usadas". A continuación, se recorre el diccionario y se imprimen las 10 primeras palabras junto con su respectivo conteo. Este conteo lo hemos añadido ya que nos 
parecía interesante que se supiera las veces que se había interactuado con cada palabra. Cada palabra se muestra en un formato específico, indicando su posición en el top 
(número de posición), la palabra en sí y la cantidad de veces que ha sido utilizada. A la hora de implementarla nos surgió un problema ya que el conteo no lo hacía de forma descendente esto
se pudo arreglar usando un contador j.

**liberar_memoria**

Se borra la memoria dinámica assignada para no malgastar recursos al salir de la aplicación. Se crean dos variables List_Users temp y current(para no perder la direccion del puntero del siguiente nodo)
y se va utilizando la funcion free() para liberar memoria.

**op_usuario**

La función "op_usuario" permite a un usuario interactuar con un sistema mediante diferentes opciones. Las iremos enumerando y explicando una a una:
1 Se solicita al usuario que ingrese su nombre de usuario.
2 Se busca en la lista de usuarios proporcionada aquel que coincida con el nombre ingresado.
3 Si se encuentra el usuario, se muestra un mensaje de inicio de sesión exitoso y se muestra un submenú de opciones.
4 El usuario puede seleccionar una opción del submenú.
5 Si la opción es 1, se permite enviar una solicitud de amistad a otros usuarios mediante la función "enviarSolicitud".
6 Si la opción es 2, se procesan las solicitudes de amistad pendientes del usuario mediante la función "procesarSolicitudesPendientes".
7 Si la opción es 3, se solicita al usuario ingresar un texto para realizar una publicación mediante la función "realizar_publicacion".
8 Si la opción es 4, se muestra el historial de publicaciones del usuario utilizando la función "mostrarHistorial".
9 Si la opción es 5, se muestra la lista de amigos del usuario mediante la función "mostrarAmistades".
10 Si la opción es 6, se muestra un mensaje de retorno al menú principal y se finaliza el bucle.
11 Si la opción seleccionada no es válida, se muestra un mensaje de opción inválida.
12 El bucle continúa hasta que se seleccione la opción 6 para regresar al menú principal.
13 Si el usuario no se encuentra en la lista de usuarios, se muestra un mensaje indicando que el usuario no ha sido encontrado.

### Funciones submenu

Al seleccionar la opción de operar como usuario te muestra un submenu en pantalla como hemos dicho anteriormente, cada opción del submenu se han desarrollado de la siguiente forma.

**Enviar solicitud de amistad** 

Esta opción permite al usuario enviar una solicitud de amistad a otro usuario. Para ello hemos implementado la función de enviarSolicitud.
La función enviarSolicitud toma como argumentos un puntero a una lista de usuarios (List_Users* l) y un puntero a un usuario (usuario* user) y realiza las siguientes acciones:
Solicita al usuario que ingrese el nombre del usuario al que desea enviar la solicitud de amistad utilizando scanf y lo almacena en la variable nombre.
Llama a la función busqueda para buscar en la lista de usuarios (l) un usuario con el nombre ingresado. El resultado se asigna al puntero req_user.
Si se encuentra un usuario con el nombre ingresado (es decir, si encontrado es igual a 1), se ejecuta la lógica para enviar la solicitud de amistad:
Llama a la función insertarSolicitud para insertar la solicitud de amistad en la lista de solicitudes pendientes del usuario destinatario (req_user). El nombre del remitente se obtiene a través de user->nombre.
Imprime en la consola un mensaje indicando que la solicitud ha sido enviada correctamente, mostrando el nombre del usuario destinatario (req_user->nombre).
Si no se encuentra ningún usuario con el nombre ingresado (es decir, encontrado es igual a 0), se imprime en la consola un mensaje indicando que el usuario no fue encontrado.


**Gestionar Solicitudes pendientes**

Esta opción permite al usuario administrar las solicitudes de amistad pendientes. Para ello hemos implementado la función procesarSolicitudesPendientes. La función toma como argumento un puntero a un usuario (usuario* user) y realiza las siguientes acciones:
Verifica si el usuario tiene solicitudes pendientes comprobando si la cola de solicitudes (cola_solicitudes) es nula. Si no hay solicitudes pendientes, imprime un mensaje en la consola indicando que no hay solicitudes y retorna de la función.
Si hay solicitudes pendientes, imprime en la consola un mensaje indicando que el usuario tiene solicitudes pendientes.
Inicia una variable i en 1 y un puntero temporal (temp) para recorrer la cola de solicitudes (cola_solicitudes) del usuario.
Mientras temp no sea nulo, muestra en la consola el número de solicitud (i) y el nombre del usuario que envió la solicitud (temp->name_sol).
Avanza al siguiente nodo de la cola de solicitudes asignando temp como temp->siguiente y aumenta el valor de i en 1.
Solicita al usuario que seleccione la solicitud que desea procesar ingresando el número correspondiente.

Establece nuevamente temp como el inicio de la cola de solicitudes.
Utiliza un bucle for para avanzar j veces en la cola de solicitudes, donde j va desde 1 hasta el número de solicitud seleccionado (opción).
Copia el nombre del usuario seleccionado en la variable nombre.
Procesa la solicitud seleccionada llamando a la función aceptarSolicitud y pasando como argumentos el puntero al usuario actual (user) y el nombre del usuario seleccionado (nombre).
Si la solicitud se acepta correctamente, imprime un mensaje en la consola indicando que la solicitud se aceptó correctamente.
Si la solicitud no se pudo procesar, imprime un mensaje en la consola indicando que no se pudo procesar la solicitud.


**Realizar una publicación**

Esta opción permite al usuario realizar una publicación en la red social. Para ello hemos implementado la función de realizar_Publicacion. Esta función crea una nueva publicación con 
el texto proporcionado, la inserta al inicio de la lista de publicaciones del usuario y actualiza el diccionario con las palabras de la publicación. Dicha función realiza lo siguiente:
Crea una nueva estructura publicacion dinámicamente asignando memoria con malloc(sizeof(publicacion)).
Copia el contenido de la cadena de texto (texto) en el campo pub de la nueva publicación utilizando strcpy.
Establece el campo siguiente de la nueva publicación como nulo.
Inserta la nueva publicación al inicio de la lista de publicaciones del usuario:
Asigna el campo siguiente de la nueva publicación como la lista actual de publicaciones del usuario (user->publicaciones).
Asigna la nueva publicación como la primera publicación en la lista de publicaciones del usuario (user->publicaciones = nueva_publicacion).
Incrementa el contador num_pub del usuario en 1.
Crea una copia del texto de la publicación en la variable copia_texto utilizando strcpy.
Utiliza la función strtok para dividir el texto en palabras individuales. Itera sobre cada palabra utilizando un bucle while con la condición token != NULL.
Para cada palabra, llama a la función agregarPalabraDiccionario para agregarla al diccionario.
Actualiza token con el siguiente token utilizando strtok(NULL, " ").

**Ver el historial de publicaciones**

Esta opción permite al usuario ver el historial de sus publicaciones anteriores. Para ello usamos la función mostrarHistorial que muestra el historial de publicaciones de un usuario, enumerando las publicaciones en orden descendente junto con su contenido. Si el usuario no tiene ninguna publicación, muestra un mensaje indicando que no se ha realizado ninguna.
El contenido de dicha función es el siguiente:
Verifica si el número de publicaciones del usuario (user->num_pub) es igual a 0. Si es así, imprime "No has realizado ninguna publicación" y retorna.
Si el usuario tiene publicaciones, imprime "Historial de publicaciones".
Crea una variable current y la inicializa con la lista de publicaciones del usuario (user->publicaciones).
Crea una variable count y la inicializa en 0. Esta variable se utilizará para contar el número de iteraciones en el bucle.
Crea una variable k y la inicializa con el valor user->num_pub - count. Esta variable se utiliza para imprimir los números de las publicaciones en orden descendente.
Entra en un bucle while que se ejecuta mientras count sea menor que user->num_pub. Esto asegura que se recorran todas las publicaciones.
Imprime el número de la publicación (k) y su contenido (current->pub).
Actualiza current al siguiente nodo de la lista de publicaciones (current = current->siguiente).
Incrementa count en 1.


**Mostrar amigos**

Esta opción permite al usuario ver la lista de sus amigos. Para ellos hemos creado la función mostrarAmistades que muestra las amistades aceptadas de un usuario. Si la lista de amistades está vacía, muestra un mensaje indicando que no tiene amistades aceptadas. De lo contrario, muestra los nombres de las amistades una por una. El contenido de la función es el siguiente:
Verifica si la lista de amigos del usuario (user->amigos) está vacía. Si está vacía, imprime "No tienes amistades aceptadas" y retorna.
Si el usuario tiene amistades, crea un puntero temporal temp y lo inicializa con la lista de amigos del usuario (user->amigos).
Imprime "Tus amistades aceptadas son:" para indicar que se mostrará la lista de amistades.
Entra en un bucle while que se ejecuta mientras temp no sea nulo. Esto permite recorrer la lista de amistades.
Imprime el nombre del amigo contenido en el nodo actual (temp->user.nombre).
Avanza al siguiente nodo de la lista (temp = temp->next).


**Funciones Diccionario**

Para el diccionario mencionado anteriormente en mostrarTop10Palabras, necesitamos implementar dos funciones para que sea funcional, dichas funciones són la de inicializarDiccionario(), que 
se encarga de crear el diccionario inicializandolo con espacios y el conteo a 0; la otra función es la de agregarPalabraDiccionario() que utiliza un bucle para buscar de manera sequencial
el diccionario comparando las palabras. En el caso que esa palabra exista suma en 1 la variable conteo y sale de la función, si no existe guarda la palabra en la última posicion del array
utilizando una variable global int numPalabras, luego sume en uno dicha variable y sale de la función.


**Agenda de exámenes**

Esta opción te muestra un otro menu que contiene las opciones: guardar exámenes, mostrar exámenes y salir además incluye una variable local índice. A continuación se explicará cada función,
pero primero hay una estructura examen que contiene el nombre de la assignatura y otra estructura fecha que contiene el día y el mes, de esta forma se puede guardar la información del examen
La opción de guardar examen llama a una función con el mismo nombre, permite guardar hasta un total de 30 exámenes como máximo pidiendo al usuario los datos del examen expuestos anteriormente.
Si supera el límite de exámenes guardados en pantalla saldrá un mensaje de que has alcanzado el máximo; cuando se guarda el examen se incremente en 1 el índice que indica cuantos exámenes 
han sido registrados. La opción mostrar exámenes llama a la función mostrarexamenes que muestra todos los exámenes añadidos con su respectiva fecha, mediante un loop for teniendo en cuenta
el índice. La opción de exámenes es una función adicional que hemos querido añadir a nuestra red, funciona correctamente pero al cerrar sesión como usuario, no se guardan los exámenes 
añadidos. Para mejorar este apartado se podría modificar el código de tal manera que se mantenga la información al salir de la sesión de un usuario.


**Volver al menu principal**

Esta opción permite al usuario regresar al menú principal. Cuando el usuario selecciona esta opción se sale del bucle y retorna al menú principal.

## **Conclusion**

Así sería el funcionamiento de nuestra red social UNICONNECT, hay aspectos que se podrían mejorar como por ejemplo control
de errores y quizás minimizar el uso de memoria para que esté más optimizado, aún teniendo en cuenta lo anterior, la 
aplicación funciona correctamente y contiene los objetivos deseables pedidos más añadidos, ahora solo queda disfrutarla



