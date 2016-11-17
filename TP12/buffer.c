

#include "buffer.h"

#define TRUE 1
#define FALSE 0
#define ERROR -1



// Crea buffer y le asigna el tamano enviado a la funcion


void b_create_buffer(CIRCULAR_BUFFER * p_struct, uint16_t size)
	{									
		
		((*p_struct).size)=size; 

		(*p_struct).puntero_inicio_buffer=(uint8_t *) calloc((*p_struct).size,sizeof(uint8_t));  // void*calloc(size_t num_elements,size_t element_size) ---> le paso la cantidad de elementos y el tamano del tipo de dato

		(*p_struct).puntero_read=(*p_struct).puntero_inicio_buffer; // iguala los punteros de write y read para que ambos comiencen en el mismo lugar
		
		(*p_struct).puntero_write=(*p_struct).puntero_inicio_buffer;

		((*p_struct).contador)=TRUE; 
	

	}

// Devuelve la cantidad de elementos que hay hasta el momento en el arreglo, si se lleno devuelve ERROR <- esto lo hace en el funcion write

int16_t b_state_buffer(CIRCULAR_BUFFER * p_struct)
{										
	return ((*p_struct).contador);
}



// Va ingresando los datos en el buffer hasta que no haya mas espacio

void b_write_buffer(CIRCULAR_BUFFER * p_struct,uint8_t tecla) 
{
	int16_t estado = b_state_buffer(p_struct);

	if(estado != ERROR)
	{
		if( estado > ((*p_struct).size))
		{
			((*p_struct).contador)=ERROR;  // pone el contador en ERROR en el caso de que se llene el buffer
		}
		else
		{	

			*((*p_struct).puntero_write)=tecla;

			((*p_struct).contador)++;

			((*p_struct).puntero_write)++;  // aumento el puntero de escritura

			if(estado >((*p_struct).size))  // chequeo si no hay mas espacio
			{
				((*p_struct).puntero_write)=((*p_struct).puntero_inicio_buffer) ; //si no hay mas espacio vuelve el puntero de lectura al principio 
				
				//SE PUEDE HACER ESTO?????  Ademas, mirar si aca esta volviendo a la posicion inicial o una menos !!!!!!!!!!!!!!!!

				// mirar que no esta chequeando si se leyo donde va a apuntar el puntero, podria estar pisando datos
			}

		}
	}
}

// Escribe hasta que no haya mas espacio

uint8_t b_read_buffer(CIRCULAR_BUFFER * p_struct)//vacia el buffer circular, si estuviese vacio devuelve 0,
{
	uint8_t tecla;

	int16_t estado = b_state_buffer(p_struct);

	
	if (estado!=TRUE)//evaluo si hay un dato que levantar o si esta vacio
	{

		if(estado==ERROR) // si se lleno el buffer seteo el contador
		{
			((*p_struct).contador)=((*p_struct).size);
		}

		tecla=*((*p_struct).puntero_read);

		((*p_struct).contador)--;

		((*p_struct).puntero_read)++;  //aumento el puntero de lectura

		if(estado >((*p_struct).size))  // chequeo si no hay mas espacio
		{
			((*p_struct).puntero_read)=((*p_struct).puntero_inicio_buffer) ; //si no hay mas espacio vuelve el puntero de escritura al principio 
				
			//SE PUEDE HACER ESTO?????  Ademas, mirar si aca esta volviendo a la posicion inicial o una menos !!!!!!!!!!!!!!!!

		}


	}

	// si esta vacio que pasa?

	return tecla;
}


// Libera la reserva de memoria

void b_end_buffer(CIRCULAR_BUFFER * p_struct)
{
	free(((*p_struct).puntero_inicio_buffer));
}