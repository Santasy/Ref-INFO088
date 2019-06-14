\[Concepto\]: Un **Binary Search Tree** (BST) es un **tipo de árbol**, cuya estructura se basa en:
	* **La estructura de un nodo**, que es una estructura que contiene información (atributos), y además presenta conexiones con otros de su mismo tipo. En este caso, los nodos tendrán un valor numérico como información y tendrán dos enlaces (hojas); uno izquierdo y uno derecho.
	* **Una cabeza**, que será siempre el primer nodo entregado al consultarse el árbol. Se entenderá por consulta cualquier función que obtenga o agregue información al árbol.
	* **Una estructura recursiva**, heredada de los árboles, referido a que un árbol se conforma por sub-árboles, que cumplen con la misma estructura, es decir, los nodos a la izquierda de la cabeza formar un sub-árbol que pudo ser creado ingresando solo esos valores, y análogamente para los nodos a la derecha de la cabeza.
	* **Una función de comparación** (que es una expresión booleana), que estructurará los nodos, de manera que:
		- Todo nodo a la izquierda de la cabeza tendrá un valor menor en comparación.
		- Todo nodo a la derecha de la cabeza tendrá un valor mayor en comparación. 
	* Por razones de simplifación, no aceptar valores repetidos.
	* Generar una estructura relacionada, que simplifica la dificultad de búsqueda de un valor en una estructura líneal **O(n)** a **O(log_2(n)).
***
\
## Ejercicio 1:
	* Defina las funciones descritas en 'bst.h', en 'bst.cpp'.
	* En 'ejercicio1.cpp' complete el main, creando todas las funciones que estime convieniente, y modificando las funciones de la clase 'bst' para lograr que:
		- El programa reciba un parámetro correspondiente al número de nodos deseados, mayor a 10, cuyos valores deben estar en \[1, MAX\].
		- El programa elimine correctamente 3 valores **existentes** en el árbol. Estos también pueden ser no-hojas.
		- El programa reciba un parámetro en ejecución que le permita hacer una impresión final de In-order, Pre-order, o de Post-order.
		- El programa imprima, luego de cualquier tipo de impresión, la cantidad de valores pares, impares y primos en el árbol, calculados aprovechando el recorrido del árbol (no debe hacer los conteos antes de agregar al árbol).