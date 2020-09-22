#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

int main(){
    char actual[300];
    char path[300];
    printf("Escriba nombre de la carpeta:\n");
    fgets(actual,100,stdin);
    printf("%s",actual);

    int a = strcmp(actual,"lalala\n");
    printf("%d",a);
    
}