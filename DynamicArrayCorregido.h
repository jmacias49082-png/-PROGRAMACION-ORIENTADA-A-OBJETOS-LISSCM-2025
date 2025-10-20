// Guarda para evitar que este archivo se incluya varias veces y cause errores.
#pragma once

#include <iostream>
using namespace std;

// (TAREA) Esta es la bandera para activar/desactivar el contador de copias.
// Si lo pongo en 0, el código del contador no se compila.
#define COUNT_DYNAMIC_ARRAY_COPIES 1

/// <summary>
/// El Dynamic Array de la clase, pero ahora como template para la Tarea 3.
/// </summary>
template <typename T> // 'T' significa que puede ser de cualquier tipo (int, float, etc.)
class DynamicArray
{
public:
	// El profe nos dio esta capacidad máxima.
	static const int maxCapacity = 1024;

	// Se llama al crear un DynamicArray. 'in_capacity = 0' es el valor por defecto.
	DynamicArray(int in_capacity = 0)
	{
		capacity = in_capacity;

		// Si me dan una capacidad inicial, pido esa memoria.
		if (capacity > 0)
			elements = new T[capacity];
		else
			// Si no, el puntero empieza en nulo.
			elements = nullptr;

		// Nuevo arreglo, así que 0 elementos guardados.
		count = 0;

		// (TAREA) Si la bandera está activa...
#if COUNT_DYNAMIC_ARRAY_COPIES != 0
	// ...inicio mi contador de copias en 0.
		copyCounter = 0;
#endif
	}

	// Se llama cuando el objeto se destruye.
	~DynamicArray()
	{
		// Si sí pedí memoria, la libero aquí para evitar memory leaks.
		// Uso delete[] porque pedí memoria con new[].
		if (capacity > 0)
			delete[] elements;
	}

	// Añade un valor al final.
	void Append(const T value)
	{
		// Si estoy lleno...
		if (count == capacity)
		{
			// ...calculo la nueva capacidad (el doble, o 1 si era 0).
			int newCapacity;
			if (capacity == 0)
				newCapacity = 1;
			else
				newCapacity = capacity * 2;

			// Llamo a Resize para que haga el trabajo de ampliar.
			Resize(newCapacity);
		}

		// Si Resize funcionó (o si ya tenía espacio)...
		if (count < capacity)
		{
			// ...guardo el valor y aumento mi contador.
			elements[count] = value;
			count++;
		}
	}

	// Inserta un valor nuevo después de un valor que ya existe.
	bool InsertarDespuesDeValor(T valorAEncontrar, T valorAInsertar)
	{
		// Busco el valor.
		for (int i = 0; i < count; i++)
		{
			// Si lo encuentro...
			if (valorAEncontrar == elements[i])
			{
				// ...reviso si necesito espacio (igual que en Append).
				if (count == capacity)
				{
					int newCapacity;
					if (capacity == 0)
						newCapacity = 1;
					else
						newCapacity = capacity * 2;

					Resize(newCapacity);

					// Si Resize falló (llegué al max), aviso y salgo.
					if (count == capacity)
					{
						cout << "ERROR: se excedi el tamao mximo del dynamic array" << endl;
						return false;
					}
				}

				// Recorro los elementos a la derecha para hacer espacio.
				for (int j = count; j > i; j--)
				{
					elements[j] = elements[j - 1];
				}
				// Pongo el valor nuevo en el hueco.
				elements[i + 1] = valorAInsertar;
				count++; // Aumento el contador.
				return true; // Listo.
			}
		}
		return false; // No lo encontré.
	}

	// Devuelve el elemento en un índice.
	T ObtenerElemento(const size_t indice) const
	{
		if (indice < count) // Reviso que el índice sea válido.
			return elements[indice];
		else
			cout << "ERROR, se intent obtener un valor en una posicin invlida de este array. Posicin: "
			<< indice << endl;
		return T{}; // Devuelvo un valor vacío (ej. 0 si es int).
	}

	// Pone un valor en un índice.
	void AsignarElemento(const size_t indice, const T valor)
	{
		if (indice < count) // Reviso que el índice sea válido.
			elements[indice] = valor;
		else
			cout << "ERROR, se intent escribir un valor en una posicin invlida de este array. Posicin: "
			<< indice << endl;
	}

	// Busca un valor y devuelve su índice.
	int BuscarElemento(const T valor) const
	{
		for (int i = 0; i < count; i++)
		{
			if (elements[i] == valor)
				return i; // Lo encontré, devuelvo dónde.
		}
		return -1; // No lo encontré.
	}

	// Quita el último elemento y lo devuelve.
	T QuitarUltimoElemento()
	{
		if (count > 0)
		{
			count--; // Solo bajo el contador, el dato sigue ahí pero "pisable".
			return elements[count];
		}
		cout << "ERROR el dynamic array estaba vaco pero se intent sacar un elemento de l." << endl;
		return T{};
	}

	// (TAREA) Sobrecarga de []. Permite hacer 'miArray[0] = 10'.
	// Devuelve T& (referencia) para poder *modificar* el valor.
	T& operator[](int index)
	{
		// Si el índice es válido...
		if (index >= 0 && index < count)
		{
			// ...devuelvo el elemento.
			return elements[index];
		}
		// Si no, es un error grave. Cierro el programa.
		cerr << "ERROR: Índice fuera de rango en DynamicArray::operator[]" << endl;
		exit(1);
	}

	// (TAREA) Añade un elemento al final.
	void push_back(T data)
	{
		// Es lo mismo que Append, así que reutilizo esa función.
		Append(data);
	}

	// (TAREA) Borra el último elemento.
	void pop_back()
	{
		// Si no estoy vacío...
		if (count > 0)
		{
			// ...solo bajo el contador.
			count--;
		}
	}

	/*
	* (TAREA) Función shrink_to_fit
	* IMPLEMENTADA según el feedback.
	* Ajusta la capacidad (memoria) al tamaño exacto de los elementos (count).
	*/
	void shrink_to_fit()
	{
		// Si tengo más memoria (capacity) de la que uso (count)...
		if (capacity > count && capacity > 0)
		{
			// ...llamo a Resize para que ajuste la memoria a 'count'.
			Resize(count);
		}
		// Si estoy vacío (count 0) pero aún tengo memoria (capacity > 0)...
		else if (count == 0 && capacity > 0)
		{
			// ...libero toda la memoria.
			Resize(0);
		}
	}

	// Devuelve cuántos elementos tengo.
	int GetCount() const
	{
		return count;
	}

	// Imprime los elementos que tengo.
	void Print() const
	{
		cout << "imprimiendo Array: " << endl;
		for (int i = 0; i < count; i++) // Recorre solo hasta 'count'.
			cout << elements[i] << ", ";
		cout << endl;
	}


	// 'private:' significa que solo la clase puede usar esto.
private:
	// Puntero a mi arreglo de datos en el Heap.
	T* elements;
	// Cuántos elementos tengo guardados.
	int count;
	// Cuánta memoria tengo reservada en total.
	int capacity;

	// (TAREA) Si la bandera está activa...
#if COUNT_DYNAMIC_ARRAY_COPIES != 0
	// ...declaro mi contador de copias.
	int copyCounter;
#endif

	// Esta es la función que hace la "magia" de cambiar el tamaño.
	void Resize(int newCapacity)
	{
		// Caso especial: shrink_to_fit() me pide liberar todo.
		if (newCapacity == 0)
		{
			if (elements != nullptr) // Si había memoria...
			{
				delete[] elements; // ...la borro.
			}
			elements = nullptr;
			capacity = 0;
			return; // Salgo.
		}

		// Si la nueva capacidad se pasa del límite...
		if (newCapacity > maxCapacity)
		{
			// ...y ya estaba en el límite, aviso y salgo.
			if (capacity >= maxCapacity)
			{
				cout << "ERROR: se excedi el tamao mximo del dynamic array" << endl;
				return;
			}
			// ...si no, la ajusto al límite.
			newCapacity = maxCapacity;
		}

		// 1. Pido la nueva memoria.
		T* arrayConMasMemoria = new T[newCapacity];

		// 2. Copio mis datos viejos al arreglo nuevo.
		for (int i = 0; i < count; i++)
		{
			arrayConMasMemoria[i] = elements[i];

			// (TAREA) Si la bandera está activa...
#if COUNT_DYNAMIC_ARRAY_COPIES != 0
			// ...sumo 1 al contador por esta copia (como pidió el profe).
			copyCounter++;
#endif
		}

		// (TAREA) Si la bandera está activa...
#if COUNT_DYNAMIC_ARRAY_COPIES != 0
		// ...imprimo el total de copias acumuladas.
		cout << "[DEBUG: Copias totales acumuladas: " << copyCounter << "]" << endl;
#endif

		// 3. Borro el arreglo viejo (si existía).
		if (elements != nullptr)
		{
			delete[] elements;
		}

		// 4. Apunto 'elements' al nuevo arreglo.
		elements = arrayConMasMemoria;
		// 5. Actualizo mi capacidad.
		capacity = newCapacity;
	}
};