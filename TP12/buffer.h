#ifndef _CIRCULAR_BUFFER_H
#define _CIRCULAR_BUFFER_H


// LIBRERIAS

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>



// ESTRUCTURA

typedef struct 
{ 

	uint16_t size;
	int16_t contador;

	uint8_t *puntero_inicio_buffer;
	uint8_t *puntero_write;
	uint8_t *puntero_read;

	

}CIRCULAR_BUFFER;

// PROTOTIPOS

void b_create_buffer(CIRCULAR_BUFFER * p_struct, uint16_t size);

int16_t b_state_buffer(CIRCULAR_BUFFER * p_struct);

void b_write_buffer(CIRCULAR_BUFFER * p_struct,uint8_t tecla);

uint8_t b_read_buffer(CIRCULAR_BUFFER * p_struct);

void b_end_buffer(CIRCULAR_BUFFER * p_struct);



#endif  // _CIRCULAR_BUFFER_H