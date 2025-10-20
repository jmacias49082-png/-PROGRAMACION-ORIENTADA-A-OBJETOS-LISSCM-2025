#pragma once
#include <iostream>
using namespace std;

template <typename T>
class LinkedList
{
private:
	// 'Node' es una clase "anidada" (nested class).
	// Solo existe para que la LinkedList la use.
	class Node
	{
	public:
		// Constructor del Nodo.
		Node(T _data)
		{
			data = _data; // Guarda el dato.
			next = nullptr; // El siguiente nodo empieza apuntando a nada (nullptr).
		}

		T data; // El valor que guardamos (int, float, etc.).
		Node* next; // Puntero al siguiente nodo de la lista.
	};

	Node* first; // Puntero que apunta al primer nodo (la "cabeza").
	int count; // Cuántos nodos tengo en la lista.

public:
	// Constructor
	LinkedList()
	{
		count = 0; // La lista empieza vacía.
		first = nullptr; // La cabeza apunta a nada.
	}

	// (TAREA 2.2) Destructor
	// Esto es lo que "faltaba" (la pista del profe).
	// Se llama solo cuando la lista se destruye.
	~LinkedList()
	{
		// Llama a Clear() para borrar todos los nodos
		// y evitar la fuga de memoria (memory leak).
		Clear();
	}

	// Código de Clase Original

	// Función "alias", solo llama a Append.
	void PushBack(const T value)
	{
		Append(value);
	}

	// Añade un nodo al final de la lista.
	void Append(const T value)
	{
		// Caso 1: La lista está vacía.
		if (first == nullptr)
		{
			first = new Node(value); // El nuevo nodo es ahora el primero.
			count++;
			return; // Listo.
		}

		// Caso 2: La lista NO está vacía.
		// Necesito llegar hasta el final.
		Node* nodoActual = first; // Empiezo por el primero.

		// Mientras el nodo actual TENGA un 'next'...
		while (nodoActual->next != nullptr)
		{
			nodoActual = nodoActual->next; // ...me muevo al siguiente.
		}

		// 'nodoActual' es ahora el último nodo (su 'next' es nullptr).
		Node* nuevoNodo = new Node(value); // Creo el nuevo nodo.
		nodoActual->next = nuevoNodo; // Lo conecto al final de la lista.
		count++;
	}

	// Inserta un valor nuevo después de un valor que ya existe.
	bool InsertAfterValue(T valorAEncontrar, T valorAInsertar)
	{
		// Empiezo a buscar desde el primer nodo.
		Node* nodoActual = first;

		while (nodoActual != nullptr) // Mientras no llegue al final...
		{
			// ...reviso si el nodo actual tiene el dato que busco.
			if (nodoActual->data == valorAEncontrar)
			{
				// ¡Lo encontré!
				Node* newNode = new Node(valorAInsertar); // Creo el nuevo nodo.
				// Conecto el nuevo nodo a lo que 'nodoActual' tenía después.
				newNode->next = nodoActual->next;
				// Conecto el 'nodoActual' al nuevo nodo.
				nodoActual->next = newNode;
				count++;
				return true; // Listo.
			}
			nodoActual = nodoActual->next; // Avanzo al siguiente nodo.
		}

		// Si salgo del 'while', no lo encontré.
		cout << "Advertencia, no existe el valor: " << valorAEncontrar << " en esta lista ligada" << endl;
		return false;
	}

	// Borra el primer nodo que encuentre con ese valor.
	bool BorrarNodoPorValor(const T valorDelNodoABorrar)
	{
		if (count == 0) // Si la lista está vacía, no hago nada.
		{
			cout << "Advertencia, tratando de borrar de una lista ligada vaca en BorrarNodoPorValor()." << endl;
			return false;
		}

		// Caso especial: El nodo a borrar es el primero (first).
		Node* nodoActual = first;
		if (nodoActual->data == valorDelNodoABorrar)
		{
			first = nodoActual->next; // Muevo 'first' al segundo nodo.
			delete nodoActual; // Borro el primer nodo.
			count--;
			return true;
		}

		// Caso normal: El nodo a borrar está en medio o al final.
		// Reviso si el *siguiente* nodo es el que hay que borrar.
		while (nodoActual->next != nullptr)
		{
			if (nodoActual->next->data == valorDelNodoABorrar)
			{
				// Encontré el nodo a borrar (es 'nodoActual->next').
				Node* nodoABorrar = nodoActual->next;
				// "Salto" el nodo a borrar, conectando el actual con el que sigue.
				nodoActual->next = nodoActual->next->next;
				// Ahora sí, borro el nodo huérfano.
				delete nodoABorrar;
				count--;
				return true;
			}
			nodoActual = nodoActual->next; // Avanzo.
		}

		// Si salgo del 'while', no lo encontré.
		cout << "Advertencia, no existe el valor: " << valorDelNodoABorrar << " en esta lista ligada" << endl;
		return false;
	}

	// Devuelve el valor del primer nodo.
	T Front()
	{
		if (first != nullptr) // Si la lista no está vacía...
			return first->data; // ...devuelvo su dato.

		cout << "Advertencia se pidi el front de la lista ligada pero est vaca." << endl;
		return T{}; // Devuelvo un valor vacío (ej. 0 si es int).
	}

	// Devuelve el valor del último nodo.
	T Back()
	{
		if (count == 0)
		{
			cout << "Advertencia se pidi el Back de la lista ligada pero est vaca." << endl;
			return T{};
		}

		// Recorro la lista hasta el último nodo.
		Node* nodoActual = first;
		while (nodoActual->next != nullptr)
		{
			nodoActual = nodoActual->next;
		}

		// 'nodoActual' es el último, devuelvo su dato.
		return nodoActual->data;
	}

	// Devuelve el valor en la posición 'indice'.
	T GetByIndex(const size_t indice) const
	{
		// Si me piden un índice que no existe...
		if (indice >= count)
		{
			cout << "ERROR: intentando acceder a un nodo con un ndice invlido." << endl;
			return T{};
		}

		Node* nodoActual = first; // Empiezo en el primero.
		// Avanzo 'indice' veces.
		for (int i = 0; i < indice; i++)
		{
			nodoActual = nodoActual->next;
		}
		// Devuelvo el dato del nodo al que llegué.
		return nodoActual->data;
	}

	// (TAREA) Inserta un nodo al *inicio* de la lista.
	void push_front(T data)
	{
		// 1. Creo el nuevo nodo.
		Node* newNode = new Node(data);
		// 2. El 'next' del nuevo nodo apunta al que era el primero.
		newNode->next = first;
		// 3. 'first' ahora apunta al nuevo nodo.
		first = newNode;
		// 4. Aumento el contador.
		count++;
	}

	// (TAREA) Borra el nodo del *inicio* de la lista.
	void pop_front()
	{
		// Si la lista no está vacía...
		if (first != nullptr)
		{
			// 1. Guardo un puntero temporal al nodo que voy a borrar (el primero).
			Node* nodeToDelete = first;
			// 2. Muevo 'first' para que apunte al segundo nodo.
			first = first->next;
			// 3. Borro el nodo que antes era el primero.
			delete nodeToDelete;
			// 4. Reduzco el contador.
			count--;
		}
	}

	// (TAREA) Imprime la lista completa.
	void Print()
	{
		cout << "Imprimiendo Lista Ligada: " << endl;
		Node* current = first; // Empiezo en 'first'.

		// Mientras 'current' no sea nulo (no haya llegado al final)...
		while (current != nullptr)
		{
			// ...imprimo su dato y una flecha.
			std::cout << current->data << " -> ";
			// ...y avanzo al siguiente.
			current = current->next;
		}
		// Al final, imprimo 'nullptr' para que se vea claro.
		std::cout << "nullptr" << std::endl;
	}

	/*
	* (TAREA 2.2) Función Clear
	* Borra todos los nodos de la lista. Es la solución a la fuga de memoria.
	*/
	void Clear()
	{
		// Mientras 'first' no sea nulo (mientras la lista tenga algo)...
		while (first != nullptr)
		{
			// ...sigo borrando el primer elemento.
			// 'pop_front' ya se encarga de mover 'first' y de hacer el 'delete'.
			pop_front();
		}
	}

	/*
	* (TAREA 2.2) ARGUMENTACIÓN SOBRE FUGA DE MEMORIA (Requerido por la Tarea)
	*
	* ¿Dónde nos falta liberar memoria?
	* En el código de clase original, falta un mecanismo para liberar todos los Nodos
	* creados con 'new Node()' cuando la instancia de 'LinkedList' se destruye.
	*
	* ¿Por qué?
	* Si el objeto 'LinkedList' se destruye (ej. sale de scope), solo se libera la
	* memoria del objeto mismo (el puntero 'first' y el 'count'). La *cadena* de Nodos
	* a la que apuntaba 'first' queda "huérfana" en el Heap, causando una fuga de memoria
	* (memory leak), ya que perdemos la única referencia a esos Nodos.
	*
	* ¿Cómo se soluciona (sin mencionar la función prohibida)?
	* Se debe implementar una función (como la 'Clear()' que añadí arriba) que itere
	* sobre toda la lista y libere cada Nodo uno por uno (usando 'delete').
	* Esta función 'Clear()' DEBE ser invocada por la función especial de la clase
	* que se llama automáticamente justo antes de que el objeto sea destruido.
	*/
};