#pragma once
#include <iostream>
using namespace std;

/*
* Nombres: [Tu Nombre]
* Tarea 3: Templates, Dynamic Array y Linked List
*
* Fuentes Consultadas:
* 1. Asistencia de IA (Gemini de Google) para implementación y guía conceptual.
* Link de la conversación: [Pega el link de este chat aquí]
*
* 2. Referencia de C++ (para push_front/pop_front):
* https://cplusplus.com/reference/forward_list/forward_list/
*/

template <typename T>
class LinkedList
{
private:
	// clase anidada.
	class Node
	{
	public:
		Node(T _data)
		{
			data = _data;
			next = nullptr;
		}

		T data;
		Node* next;
	};

	Node* first;
	int count;

public:
	LinkedList()
	{
		count = 0;
		first = nullptr;
	}

	// PUNTO 2.2 CORREGIDO
	/*
	* Se añade el destructor para liberar la memoria.
	* Llama a Clear() automáticamente cuando la lista se destruye.
	*/
	~LinkedList()
	{
		// Esto soluciona la fuga de memoria
		Clear();
	}
	// FIN DEL 2.2 


	// INICIO CÓDIGO DE CLASE ORIGINAL 

	void PushBack(const T value)
	{
		Append(value);
	}

	void Append(const T value)
	{
		if (first == nullptr)
		{
			first = new Node(value);
			count++;
			return;
		}

		Node* nodoActual = first;
		while (nodoActual->next != nullptr)
		{
			nodoActual = nodoActual->next;
		}

		Node* nuevoNodo = new Node(value);
		nodoActual->next = nuevoNodo;
		count++;
	}

	bool InsertAfterValue(T valorAEncontrar, T valorAInsertar)
	{
		Node* nodoActual = first;
		while (nodoActual != nullptr)
		{
			if (nodoActual->data == valorAEncontrar)
			{
				Node* newNode = new Node(valorAInsertar);
				newNode->next = nodoActual->next;
				nodoActual->next = newNode;
				count++;
				return true;
			}
			nodoActual = nodoActual->next;
		}
		cout << "Advertencia, no existe el valor: " << valorAEncontrar << " en esta lista ligada" << endl;
		return false;
	}

	bool BorrarNodoPorValor(const T valorDelNodoABorrar)
	{
		if (count == 0)
		{
			cout << "Advertencia, tratando de borrar de una lista ligada vaca en BorrarNodoPorValor()." << endl;
			return false;
		}

		Node* nodoActual = first;
		if (nodoActual->data == valorDelNodoABorrar)
		{
			first = nodoActual->next;
			delete nodoActual;
			// Si count == 1, first ya es nullptr.
			// La línea 'if (count == 1) first = nullptr;' 
			// Lo correcto es solo:
			// first = nodoActual->next; (que será nullptr si era el último)
			// delete nodoActual;
			count--;
			return true;
		}

		while (nodoActual->next != nullptr)
		{
			if (nodoActual->next->data == valorDelNodoABorrar)
			{
				Node* nodoABorrar = nodoActual->next;
				nodoActual->next = nodoActual->next->next;
				delete nodoABorrar;
				count--;
				return true;
			}
			nodoActual = nodoActual->next;
		}
		cout << "Advertencia, no existe el valor: " << valorDelNodoABorrar << " en esta lista ligada" << endl;
		return false;
	}

	T Front()
	{
		if (first != nullptr)
			return first->data;
		cout << "Advertencia se pidi el front de la lista ligada pero est vaca." << endl;
		return T{};
	}

	T Back()
	{
		if (count == 0)
		{
			cout << "Advertencia se pidi el Back de la lista ligada pero est vaca." << endl;
			return T{};
		}
		Node* nodoActual = first;
		while (nodoActual->next != nullptr)
		{
			nodoActual = nodoActual->next;
		}
		return nodoActual->data;
	}

	T GetByIndex(const size_t indice) const
	{
		if (indice >= count)
		{
			cout << "ERROR: intentando acceder a un nodo con un ndice invlido." << endl;
			return T{};
		}
		Node* nodoActual = first;
		for (int i = 0; i < indice; i++)
		{
			nodoActual = nodoActual->next;
		}
		return nodoActual->data;
	}

	//  FIN CÓDIGO DE CLASE ORIGINAL 


	// TAREA 3 NUEVAS FUNCIONES 

	void push_front(T data)
	{
		Node* newNode = new Node(data);
		newNode->next = first;
		first = newNode;
		count++;
	}

	void pop_front()
	{
		if (first != nullptr)
		{
			Node* nodeToDelete = first;
			first = first->next;
			delete nodeToDelete;
			count--;
		}
	}

	void Print()
	{
		cout << "Imprimiendo Lista Ligada: " << endl;
		Node* current = first;
		while (current != nullptr)
		{
			std::cout << current->data << " -> ";
			current = current->next;
		}
		std::cout << "nullptr" << std::endl;
	}

	void Clear()
	{
		while (first != nullptr)
		{
			pop_front();
		}
	}

	/*
	* 2.2) ARGUMENTACIÓN SOBRE FUGA DE MEMORIA (Requerido por la Tarea)
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