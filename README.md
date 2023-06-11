# EDA2
Nuestra red social
26/04/2023
    




ESTRUCTURAS DE DATOS Y ALGORITMOS II, 2022-2023
Información sobre TÍTULO DE PROYECTO


Alex Alastuey Centeno, Estela Callejón Molina, Marc Cano Lafarga

NIA: 268167, 266667, 269701

11 de junio 2023

# MEMORIA DEL PROYECTO UNICONNECT

## INTRODUCCION
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

New_usuario

La primera opción del programa es introducir un usuario de forma manual, se codificará en el archivo users.c al igual que las demás funciones. La funcionalidad de la función new_usuario,
consistirá en que vaya pidiendo datos necesarios para registrar un usuario en la red social. En dicha función se creará una variable local de estructura usuario para poder registrar
la información (La lista de usuarios será pasada como parámetro por referencia para que asi pueda ser modificada). Una vez introducido todos los datos teniendo en cuenta que el nombre de 
usuario es único, se usara un algoritmo para recorrer la lista de usuarios comprobando si el puntero al siguiente usuario es nulo o no; en el caso que sea nulo se introducirá el nuevo 
usuario en ese nodo apuntando a un siguiente nulo.

Leer_file

Para la de leer_file primero se tiene que crear un fichero con los datos de los usuarios separados por un espacio, 

Listar


MostrarTop10Palabras


liberar_memoria


op_usuario


PLANTILLA DE MEMORIA DE PROYECTO [Máximo 5000 palabras en total]
LISTA DE CONTENIDOS [Incluir todas las secciones que se detallan a continuación]

INTRODUCCIÓN [Aprox.  250 palabras]
En esta sección se debe describir el contexto, la definición del problema, las soluciones existentes que habéis revisado en busca de inspiración, su propuesta y los objetivos alcanzados.

Nuestro objetivo para este proyecto 
OBJETIVOS DEL PROYECTO [Aprox. 2500 palabras]
En esta sección se deben cubrir los objetivos alcanzados en el proyecto. Cada objetivo presentado en las siguientes subsecciones debe cubrir los siguientes elementos:
Descripción general: Describir cómo se ha implementado. Más allá de lo que se le proporcionó en el documento de orientación, indique las características principales de las estructuras de datos y los algoritmos implementados para lograr este objetivo y su comportamiento. 
Debería incluir:
Explicar todas las fucnciones y como funcionan especificando las variables y las estructuras de datos
¿Qué variables se utilizaron y con qué propósito?

¿Cuáles fueron las estructuras de datos elegidas para este objetivo? ¿Para que se utilizó?

¿Cuál fue el algoritmo elegido para este objetivo? ¿Cuál es su comportamiento esperado? 

¿Qué limitaciones tiene el algoritmo? ¿Cómo pasó en su implementación?
¿Qué se puede mejorar?

Tiempo: Tiempo necesario para desarrollar este objetivo

Ubicación: a qué línea de código y en qué archivo se encuentra esta implementación.

Objetivos obligatorios alcanzados:

Esta subsección debe describir qué objetivos obligatorios se han implementado en el proyecto siguiendo la estructura y los elementos presentados anteriormente.

Objetivos deseables alcanzados:

Esta subsección debe describir qué objetivos deseables se han implementado en el proyecto siguiendo la estructura y los elementos presentados anteriormente.

Objetivos exploratorios adquiridos:

Esta subsección debe describir qué objetivos exploratorios se han implementado en el proyecto siguiendo la estructura y los elementos presentados anteriormente.

SOLUCIÓN [Aprox. 1500 palabras]
Esta sección debe profundizar en la solución desarrollada para este proyecto.
Arquitectura del sistema [Aprox. 750 palabras]
Esta subsección debe incluir al menos un diagrama de la arquitectura del sistema y una descripción de los bloques principales y su funcionalidad.

Gestión de errores [Aprox. 250 palabras]
Esta subsección debe describir cómo se manejaron los errores en el proyecto y su razonamiento.
Diseño del modelo de datos [Aprox. 250 palabras]
Esta subsección debe incluir al menos un diagrama de flujo de datos de la solución y su descripción.
Descripción y procesamiento del conjunto de datos [Aprox. 250 words]
Esta subsección debe incluir una descripción de los conjuntos de datos utilizados, cómo se leyeron y procesaron.

REFERENCIAS
Esta sección debe incluir las referencias utilizadas en el informe. Estas referencias incluyen cualquier sitio web, material de lectura, publicaciones o libros utilizados como inspiración.

cosas para comentar.

error de diccionario, control de errors de seleccion del menu, error con el fichero, error de punteros y mal inicializacion de variables, error en mostar historial programa deja de funcionar


