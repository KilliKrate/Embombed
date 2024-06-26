#ifndef __CONST_H__
#define __CONST_H__


//UART
#define MAX_MSG_SIZE 50000


//ADC
#define MAX_FUNC 10


//dot matrix
#define MAT_OP_NOOP 0
#define MAT_OP_DECODEMODE 9
#define MAT_OP_INTENSITY 10
#define MAT_OP_SCANLIMIT 11
#define MAT_OP_SHUTDOWN 12
#define MAT_OP_DISPLAYTEST 15


//game parser
#define SNMAXDIM 15
#define CODEPADMAXDIM 20

#define NOTNOTMAXTURNS 15
#define NOTNOTMAXMSGDIM 30

#define SIMONSAYSMAXTURNS 10
#define SIMONSAYSMAXSTEPPERTURN 8

#define MAXJSONTOKEN 3000

#define NUMCAVI 4


//keypad
#define NUMROWS 4
#define NUMCOLS 4


//sonda
#define NUM_VOLT 9
#define NUM_SAMPLES 150


//games
#define GAME_CODECRACKER 0
#define GAME_NOTNOT 1
#define GAME_SIMONSAYS 2
#define GAME_CABLES 3
#define GAME_NONE 4

//accelerometro
#define NUM_SAMPLES_ACC 20

//music
#define NUM_NOTES 678
#define TEMPO 60
#define GRID 32

#endif
