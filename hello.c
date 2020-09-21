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
    char compania[300];
    char resumen[300];
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
            i++;
            printf("File %d: %s\n", i, dp->d_name);
            strcpy(direc, "./Juegos/");  //direccion del archivo txt
			strcat(direc, dp->d_name);	
            printf("%s\n", direc);

            fp = fopen(direc, "r");
            fgets(titulo, sizeof(char)*300, fp);
            fgets(genero, sizeof(char)*300, fp);
            fgets(compania, sizeof(char)*300, fp);
            fgets(resumen, sizeof(char)*300, fp);
            printf("Genero: %s", genero);   //todos los generos
            aux = strtok(genero, ",");
            printf("%s\n",aux);  //primero genero
            strcpy(aux2, "./");  //carpeta a donde tiene ir el txt
			strcat(aux2, aux);
            printf("%s\n", aux2);
            dir2 = opendir(aux2);
            if(dir2==NULL){
                printf("no existe esa carpeta\n");
                mkdir(aux,0700);
            }
            else{
                printf("si existe esa carpeta\n");
            }
            strcat(path1,"./");
            strcat(path1,aux);
            strcat(path1,"/");
            strcat(path1,dp->d_name);
            printf("%s",path1);
            rename(direc,path1);
            strcpy(path1,"");
            fclose(fp);
            closedir(dir2);
        }
    }   
    closedir(dir);
}
int main(){
    printf("Bienvenido!\n Presione 1 si desea ordenar la carpeta Juegos.\n Presione 2 si desea recorrer los archivos.\n");
    ordenar();
    

    return 0;
}