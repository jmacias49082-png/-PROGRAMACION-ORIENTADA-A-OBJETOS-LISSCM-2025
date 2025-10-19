#pragma once

#include <iostream>
using namespace std;

/*
* Nombres: Jesus Isai Macias Cruz y Diego Velazquez 
* Tarea 3: Templates, Dynamic Array y Linked List
*
* Fuentes Consultadas:
* 1. Asistencia de IA (Copilot) para refactorizar DynamicArray a template
* y para implementar la lógica de las nuevas funciones (push/pop, overload[], Print).
*
* 2. Referencias
* https://cplusplus.com/reference/vector/vector/
* Templates (Plantillas): https://www.youtube.com/watch?v=sycJ-NU1efg

Sobrecarga de Operadores (operator[]): https://www.youtube.com/watch?v=QjV-qC93q1s

Directivas de Preprocesador (#define, #if): https://www.youtube.com/watch?v=A-n-d-fN-m0

Concepto RAII (Destructores y Memoria): https://www.youtube.com/watch?v=c-f-PjV-L38
*/

// 3.0) Definimos la directiva de preprocesador
#define COUNT_DYNAMIC_ARRAY_COPIES 1

/// <summary>
/// Un array que incrementa su tamao automticamente (versión Tarea 3: Template).
/// </summary>
template <typename T> // Convertimos la clase a template
class DynamicArray
{
public:
	static const int maxCapacity = 1024;

	// DEFINICIÓN DEL CONSTRUCTOR 
	DynamicArray(int in_capacity = 0)
	{
		capacity = in_capacity;
		if (capacity > 0)
			elements = new T[capacity]; // Usamos T
		else
			elements = nullptr;

		count = 0;

		// 3.2) Inicializar el contador
#if COUNT_DYNAMIC_ARRAY_COPIES != 0
		copyCounter = 0;
#endif
	}

	// DEFINICIÓN DEL DESTRUCTOR
	~DynamicArray()
	{
		if (capacity > 0)
			delete[] elements;
	}

	// CÓDIGO DE CLASE ORIGINAL 

	void Append(const T value)
	{
		if (count == capacity)
		{
			int newCapacity;
			if (capacity == 0)
				newCapacity = 1;
			else
				newCapacity = capacity * 2;

			Resize(newCapacity);
		}

		if (count < capacity)
		{
			elements[count] = value;
			count++;
		}
	}

	bool InsertarDespuesDeValor(T valorAEncontrar, T valorAInsertar)
	{
		for (int i = 0; i < count; i++)
		{
			if (valorAEncontrar == elements[i])
			{
				if (count == capacity)
				{
					int newCapacity;
					if (capacity == 0)
						newCapacity = 1;
					else
						newCapacity = capacity * 2;

					Resize(newCapacity);

					// Si Resize falló (ej. maxCapacity) y seguimos sin espacio
					if (count == capacity)
					{
						cout << "ERROR: se excedi el tamao mximo del dynamic array" << endl;
						return false;
					}
				}

				for (int j = count; j > i; j--)
				{
					elements[j] = elements[j - 1];
				}
				elements[i + 1] = valorAInsertar;
				count++;
				return true;
			}
		}
		return false;
	}

	T ObtenerElemento(const size_t indice) const
	{
		if (indice < count) // Usamos count, no capacity, para obtener elementos válidos
			return elements[indice];
		else
			cout << "ERROR, se intent obtener un valor en una posicin invlida de este array. Posicin: "
			<< indice << endl;
		return T{}; // Regresamos un valor T por defecto
	}

	void AsignarElemento(const size_t indice, const T valor)
	{
		if (indice < count) // Usamos count
			elements[indice] = valor;
		else
			cout << "ERROR, se intent escribir un valor en una posicin invlida de este array. Posicin: "
			<< indice << endl;
	}

	int BuscarElemento(const T valor) const
	{
		for (int i = 0; i < count; i++)
		{
			if (elements[i] == valor)
				return i;
		}
		return -1;
	}

	T QuitarUltimoElemento()
	{
		if (count > 0)
		{
			count--;
			return elements[count];
		}
		cout << "ERROR el dynamic array estaba vaco pero se intent sacar un elemento de l." << endl;
		return T{}; // Regresamos un valor T por defecto
	}

	//  FIN CÓDIGO DE CLASE ORIGINAL 


	//  TAREA 3 NUEVAS FUNCIONES 

	T& operator[](int index)
	{
		if (index >= 0 && index < count)
		{
			return elements[index];
		}
		cerr << "ERROR: Índice fuera de rango en DynamicArray::operator[]" << endl;
		exit(1);
	}

	void push_back(T data)
	{
		Append(data);
	}

	void pop_back()
	{
		if (count > 0)
		{
			count--;
		}
	}

	void shrink_to_fit()
	{
		// Cuerpo vacío.
	}

	//  FIN TAREA 3 NUEVAS FUNCIONES 


	int GetCount() const
	{
		return count;
	}

	void Print() const
	{
		cout << "imprimiendo Array: " << endl;
		for (int i = 0; i < count; i++)
			cout << elements[i] << ", ";
		cout << endl;
	}


private:
	T* elements;
	int count;
	int capacity;

#if COUNT_DYNAMIC_ARRAY_COPIES != 0
	int copyCounter; // Variable miembro
#endif


	void Resize(int newCapacity)
	{
		if (newCapacity > maxCapacity)
		{
			if (capacity >= maxCapacity) // Si ya estamos en el max, no podemos crecer
			{
				cout << "ERROR: se excedi el tamao mximo del dynamic array" << endl;
				return;
			}
			newCapacity = maxCapacity; // Ajusta al máximo si se pasó
		}

		T* arrayConMasMemoria = new T[newCapacity];

		for (int i = 0; i < count; i++) // Copiamos solo los 'count' elementos
		{
			arrayConMasMemoria[i] = elements[i];

			// 3.2) Incrementa copyCounter directamente
#if COUNT_DYNAMIC_ARRAY_COPIES != 0
			copyCounter++; // Incrementa la variable miembro
#endif
		}

		// 3.2) Reporta el total (ya no usamos 'copiesThisResize')
#if COUNT_DYNAMIC_ARRAY_COPIES != 0
		// Imprimimos el contador total después del resize
		cout << "[DEBUG: Copias totales acumuladas: " << copyCounter << "]" << endl;
#endif

		if (elements != nullptr)
		{
			delete[] elements;
		}

		elements = arrayConMasMemoria;
		capacity = newCapacity;
	}
};