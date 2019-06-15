## Funcionalidades:
***
* **Búsqueda**: Se trabajará con dos tipos de búsqueda:
	1. **De nodo**, que buscará el nodo padre correspondiente al valor entregado, que tendrá una conexión disponible para integrar el valor. La respuesta debe ser 'nullptr' en caso de que la cabeza lo sea, para explicar que el árbol está vacío.
	1. **De valor**, que simplemente buscará un valor entregado entre los almacenados por el árbol. La respuesta debe ser un valor booleano. 
	* Para ambos, se deberá recorrer el árbol de acuerdo a la función de comparación.
***
* **Inserción**: Dado que la cabeza del árbol puede ser un 'nullptr', pueden darse dos casos:
	1. La cabeza **es 'nullptr'**, por lo que debe ser reemplazado por el nuevo nodo.
	2. La cabeza **no es 'nullptr'**, por lo que debe buscarse una posición libre:
		- Se busca un nodo disponible con la función correspondiente.
		- Se agrega la conexión, y el nodo nuevo pasa a ser hoja del árbol.
***
* **Eliminación**: Dado que no se busca que este árbol esté balanceado, este proceso es bastante simplificado, y pueden darse tres casos:
	1. El valor no se encuentra, por lo que no es necesario operar.
	2. El valor se encontró, y es una hoja:
		- Se reemplaza la conexión con el nodo padre con un 'nullptr'.
		- Se elimina el nodo de la memoria (delete en C++).
	3. El valor se encontró, y no es una hoja:
		- Se reemplaza la conexión con el nodo padre con un 'nullptr'.
		- Se elimina el nodo de la memoria (delete en C++).
		- Ahora, existirán (virtualmente; no están enlazados a nada, y solo existen mientras tengamos su referencia) dos sub-árboles formados por los hijos del nodo eliminado, que deberán ser re-integrados al árbol original, buscando el nodo correcto con la función correspondiente, y:
			1. Se agrega el sub-árbol izquierdo. Esto es porque el sub-árbol derecho puede terminar siendo hijo derecho de alguna hoja del sub-árbol izquierdo.
			2. Se agrega el sub-árbol derecho.
	- Para eliminar un árbol, se deben eliminar todos los nodos almacenados.
***
* **Impresión**: Este tipo de árbol, binario, es capaz de ser recorrido recursivamente (con un proceso que no necesite diferenciar el tipo de nodo que está evaluando, y que una vez llamado puede propagarse) de tres maneras, que son variaciones en el orden del arreglo \[raíz, izquierda, derecha\], y han sido formalmente descritas como:
	1. **Pre-order**: (**raíz**, izquierda, derecha), que imprimirá el valor del nodo evaluado, luego evaluará a la izquierda (se imprimira el valor, y se volverá a ir a la izquierda de ser posible), y terminará evaluando a la derecha (de la misma manera, imprimirá el valor, revisará a la izquierda, y luego continuará a la derecha). Esto resultara en una impresión sin orden numérico, solo evidenciará el orden en que fueron **agregados** los nodos.
	2. **In-order**: (izquierda, **raíz**, derecha), que primero evaluará a la izquierda, luego imprimira el valor, y continuará con la derecha. Gracias a la estructura de nuetro árbol, todo nodo izquierdo será menor que el anterior, por lo que la impresión termina siendo en **orden numérico ascendente**.
	3. **Post-order**: (izquierda, derecha, **raíz**), que primero evaluará a la izquierda, luego a la derecha, y luego imprimirá la raíz. Esta impresión tampoco evidencia un orden numérico particular, es decir, solo evidencia el orden en que las hojas escalan hasta la raíz, que referencia un poco al concepto de **niveles**.
	- Para identificar qué tipo de valor (par, impar, primo) se almacena en el árbol, deberán tener contadores internos que se inicien con el primer llamado a la función (con la cabeza), y pase por referencia estas variables a los sub-procesos.
***