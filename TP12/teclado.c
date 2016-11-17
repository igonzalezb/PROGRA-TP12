#include "teclado.h"



#include <unistd.h>

void threads_main (CIRCULAR_BUFFER * p_struct)      //EN LOS OTROS THREADS VER QUE METER
{
    pthread_t tid_timer, tid_teclado;
    srand(time(NULL));
    nonblock(NB_ENABLE);
    pthread_create (&tid_timer, NULL, thread_timer, NULL);
	
    pthread_create (&tid_teclado, NULL, thread_teclado, p_struct);
    
	pthread_join(tid_timer,NULL);
    pthread_join(tid_teclado, NULL);
     nonblock(NB_DISABLE);
    
}


unsigned int TimerTick;


//////////// thread_timer /////////////////
void* thread_timer() //Timer base thread
{
    while(1)
    {
        usleep (100 * ONE_MS); //100 ms *   NO SE PUEDE SACAR ESTE USLEEP????????
        if (TimerTick)
            TimerTick--;
    }
    
}


///////////////////////// thread_teclado /////////////////////////////////
void* thread_teclado(void* arg)  //VER DONDE CREAR EL BUFFER QUE SE USA
{
    CIRCULAR_BUFFER *p_struct = (CIRCULAR_BUFFER*) arg;
	
	static int r = 0;//BORRAR!!!!!!! ES DE PRUEBA
    static int tecla_baja = 0;
	char c;
    
    while (1)
    {
	    if (!TimerTick)
	    {
	        if (tecla_baja) //si la tecla esta baja, la guarda en el buffer
	        {
	            c=fgetc(stdin);
				b_write_buffer (p_struct,c); //ver bien esto
				printf("Buffer: %c\n",b_read_buffer(p_struct));
	        }
	        else
	        {
	            	//enable non-blocking
	        	
	            if (kbhit()) //si ahora se presiono una tecla, guardara el el buffer e indicar que se presiono
	            {
					c = fgetc(stdin);
					//b_write_buffer (p_struct,c); //ver bien esto
	                tecla_baja = SI;
					printf("Buffer: %c\n",b_read_buffer(p_struct));
	            }
				
	           	//return back to normal
	        }
	        TimerTick = time_delay(500);  //500 ms VER SI ESTO ESTA BIEN O CUANTO PONERLE Y SI LOS 500 PUEDEN IR COMO UNA CONSTANTE ARRIBA QUE SE CAMBIA SI UNO QUIERE
	     printf ("Tread2 r=%d\n",r++);   //BORRAR!!!!!!! ES DE PRUEBA
	    }
   
	}
}
    
    