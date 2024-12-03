#include "constantes.h"
#include <unistd.h>
#include <string.h> //permet d'utiliser strlen(arg) qui donne la longueur en oct de arg
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

/*Les fonctions que j'utiliserai*/

int NewShell(){
    int fd = open("enseash", O_WRONLY | O_CREAT, SIZE_NewFILE);
    if (fd==-1){
        perror("error_open_enseash");
        exit(EXIT_FAILURE);
    }
    return fd;
}

void InitShell(){
    write(STDOUT_FILENO, Message_de_bienvenue, strlen(Message_de_bienvenue));
}

void prompt(){
    //uid_t UserID = getuid();
    //sprintf("User:%d",UserID);
    write(STDOUT_FILENO, Message_prompt, strlen(Message_prompt));
}

void readCommand(char Buffer[]){
    ssize_t retour=read(STDIN_FILENO, Buffer, BUFFER_SIZE);
    Buffer[retour-1]=0;
    if (strcmp(Buffer,"exit")==0){
        exit(EXIT_SUCCESS);
    }
    if (fork()==0){
        execlp(Buffer, Buffer,NULL);
        exit(EXIT_FAILURE);
        }
    wait(NULL);
}