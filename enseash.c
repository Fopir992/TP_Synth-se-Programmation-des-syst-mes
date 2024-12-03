//#include <stdio.h>
//#include <stdlib.h>
#include <unistd.h>
//#include <sys/wait.h>
#include "constantes.h"

#include "toolcase.h"

//gcc *.c -o enseash
int main(void){
  //  NewShell();
    char Buffer[BUFFER_SIZE]={0};
    InitShell();
    prompt();
    while(1){
        readCommand(Buffer);
        prompt();
    }
}