#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

void ordenar(){
    int i=0;
    DIR *dir;
    DIR *dir2;
    struct dirent *dp;
    const char *path="./Juegos"; 
    char path1[300]="";
    char direc[300];
    char titulo[300];
    char genero[300];
    char *aux;
    char aux2[300];
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
            strcpy(direc, "./Juegos/");  //direccion del archivo txt
			strcat(direc, dp->d_name);	
            fp = fopen(direc, "r");
            fgets(titulo, sizeof(char)*300, fp);
            fgets(genero, sizeof(char)*300, fp);
            aux = strtok(genero, ",");
            strcpy(aux2, "./");  //carpeta a donde tiene ir el txt
			strcat(aux2, aux);
            dir2 = opendir(aux2);
            if(dir2==NULL){
                mkdir(aux,0700);
            }
            strcat(path1,"./");
            strcat(path1,aux);
            strcat(path1,"/");
            strcat(path1,dp->d_name);
            rename(direc,path1);
            strcpy(path1,"");
            fclose(fp);
            closedir(dir2);
        }
    }   
    closedir(dir);
}
int main(){
    ordenar();
    return 0;
}