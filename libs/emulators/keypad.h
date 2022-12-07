#ifndef __KEYPAD_H__
#define __KEYPAD_H__

#include "../constants.h"
//lib for thread
#include <pthread.h>
#include <stdio.h>
//libe for delay
#include <unistd.h>
#include "mutex.h"

int enabledKeypad = 0;
char *puntNumPad;

void IRQ_col(void);

void disableInterruptNumPad()
{
    enabledKeypad = 0;
}

void enableInterruptNumPad()
{
    enabledKeypad = 1;
}

void evaluateKeyPad()
{
    disableInterruptNumPad();

    //take mutex
    pthread_mutex_lock(&mutex);

    //get input from keybord
    printf("Inserisci il carattere da simulare per il keypad: ");
    scanf(" %c", puntNumPad);
    //release mutex
    pthread_mutex_unlock(&mutex);
    
    enableInterruptNumPad();
}

void IRQ_col(void)
{
    printf("IRQ_keypad started\n");
    while(1){
        if(enabledKeypad && *puntNumPad==0){
            //take mutex
            pthread_mutex_lock(&mutex);

            //ask it you want to simulate a key
            printf("vuoi simulare una pressione? (y/n) ");
            char c;
            scanf(" %c", &c);
            
            if(c == 'y'){
                *puntNumPad = 1;
            }

            //release mutex
            pthread_mutex_unlock(&mutex);

        }
        //delay 10 seconds
        sleep(10);
    }
}


void setUpKeyPad(uint_fast8_t *rowPorts, uint_fast16_t *rowPins,
                 uint_fast8_t *colPorts, uint_fast16_t *colPins,
                 char *res)
{
    puntNumPad = res;
    disableInterruptNumPad();

    //start thread with function IRQ_col
    pthread_t thread;
    pthread_create(&thread, NULL, (void *)IRQ_col, NULL);
}

#endif