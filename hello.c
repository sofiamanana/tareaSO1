#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

void ordenar(){
    int i=0;
    DIR *dir;
    struct dirent *dp;
    const char *path="./Juegos"; 
    char direc[300];
    char titulo[300];
    char genero[300];
    char *aux;
    FILE *fp;
    dir = opendir(path);
    if(dir==NULL){
        printf("No se abrio el directorio");
        exit(2);
    }
    while( (dp=readdir(dir)) ){
        if ((strcmp(dp->d_name,".") == 0) || (strcmp(dp->d_name,"..") == 0)){		//elimina carpeta "." y ".."
	    }
        else{
            i++;
            printf("File %d: %s\n", i, dp->d_name);         

            strcpy(direc, "Juegos/");
			strcat(direc, dp->d_name);	
            printf("%s\n", direc);

            fp = fopen(direc, "r");
            fgets(titulo, sizeof(char)*300, fp);
            fgets(genero, sizeof(char)*300, fp);
            printf("Genero: %s", genero);

            aux = strtok(genero, ",");
            
            /*
            while(aux != NULL){
                printf("Genero: %s\n", aux);
                aux = strtok(NULL, ",");
            }*/
            
        }
    }
    closedir(dir);
}

int main(){
    ordenar();
    /*
    char accion[100];
    printf("Bienvenido!\n Presione 1 si desea ordenar la carpeta Juegos.\n Presione 2 si desea recorrer los archivos.\n Presione 3 para salir.\n");
    fgets(accion,100,stdin);
    while(strcmp(accion,"3")!=0){
        strtok(accion, "\n");
        if(strcmp(accion,"1")==0){
            ordenar();
            printf("Bienvenido!\n Presione 1 si desea ordenar la carpeta Juegos.\n Presione 2 si desea recorrer los archivos.\n Presione 3 para salir.\n");
            fgets(accion,100,stdin);
            strtok(accion, "\n");
        }
        else{
            printf("Bienvenido!\n Presione 1 si desea ordenar la carpeta Juegos.\n Presione 2 si desea recorrer los archivos.\n Presione 3 para salir.\n");
            fgets(accion,100,stdin);
            strtok(accion, "\n");
        }
    }*/
    return 0;
}