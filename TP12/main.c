


#include <stdio.h>
#include <stdlib.h>
#include "buffer.h"
#include "nonblock.h"
#include "teclado.h"
//#include <pthread.h>
#define SIZE_BUFF 10

int main (void)
{
	CIRCULAR_BUFFER prueba;

	int i;

	b_create_buffer(&prueba, SIZE_BUFF);

	for (i=0;i<15;i++)
	{
		b_write_buffer(&prueba,('A'+i));

		printf("%c\n",b_read_buffer(&prueba));
	}
	

	
//=================================================================================
	
	
	threads_main(&prueba);
	
	b_end_buffer(&prueba);
	
	
	
	
	return 0;
}