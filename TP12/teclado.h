/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   teclado.h
 * Author: inaki
 *
 * Created on November 13, 2016, 5:26 PM
 */

#ifndef TECLADO_H
#define TECLADO_H

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h> //VER SI HACE FALTA O NO
#include "nonblock.h"
#include "buffer.h"

#define ONE_MS  1000
#define time_delay(x) (x/100)
#define SI 1

void threads_main (CIRCULAR_BUFFER * p_struct);

void* thread_timer();

void* thread_teclado(void*);

#endif /* TECLADO_H */

