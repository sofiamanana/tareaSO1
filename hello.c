#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
/*
void ordenar_por_categoria(){
    mkdir("Juegos2",0700);
    DIR *dir;
    struct dirent *dp;
    const char *path="./Juegos";
    dir = opendir(path);
    if(dir==NULL){
        printf("No se abrio el directorio");
    }
    while((dp=readdir(dir))){
        if ((strcmp(dp->d_name,".") == 0) || (strcmp(dp->d_name,"..") == 0)){		//elimina carpeta "." y ".."
	    }
        else{

        }
    }
}
*/
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
        if ((strcmp(dp->d_name,".") == 0) || (strcmp(dp->d_name,"..") == 0)){		
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


void navegar(){
    char actual[300];
    char nombre[300];
    char opcion[300];
    char titulo[300];
    char genero[300];
    char company[300];
    char descr[300];
    char *aux;
    DIR *dir;
    FILE *fp;
    struct dirent *dp;
    
    while(strcmp(opcion,"4\n")!=0){
        getcwd(actual,sizeof(actual)); 
        dir = opendir(actual);
        printf("\nLa ubicacion actual es:%s y contiene:\n\n",actual);
        if(dir==NULL){
            printf("No se abrio el directorio");
            exit(2);
        }
        int i=0;
        while( (dp=readdir(dir)) ){
            
            if ((strcmp(dp->d_name,".") == 0) || (strcmp(dp->d_name,"..") == 0)){		
            }
            else{
                i+=1;
                printf("Archivo %d: %s\n",i,dp->d_name);
            }
            
        }
        printf("\n1. Abrir carpeta.\n");
        printf("2. Para volver atras.\n");
        printf("3. Abrir un txt.\n");
        printf("4. Salir.\n");
        fgets(opcion,100,stdin);

        if(strcmp(opcion,"1\n")==0){
            printf("Escriba nombre de la carpeta:\n");
            fgets(nombre,100,stdin);
            aux = strtok(nombre,"\n");
            strcat(actual,"/");
            strcat(actual,aux);
            chdir(actual);
        }
        else if(strcmp(opcion,"2\n")==0){
            strcat(actual,"/");
            strcat(actual,"..");
            chdir(actual);
        }
        else if(strcmp(opcion,"3\n")==0){
            printf("Escriba nombre de la archivo (archivo.txt):\n");
            fgets(nombre,100,stdin);
            aux = strtok(nombre,"\n");
            fp = fopen(aux,"r");
            fgets(titulo, sizeof(char)*300, fp);
            fgets(genero, sizeof(char)*300, fp);
            fgets(company, sizeof(char)*300, fp);
            fgets(descr, sizeof(char)*300, fp);

            printf("\nTitulo: %s\n",titulo);
            printf("Genero: %s\n",genero);
            printf("Company: %s\n",company);
            printf("Descripcion: %s\n",descr);
        }
    }
}

int main(){
    int opcion;
    printf("Bienvenido!\n 1. Ordenar los archivos. \n 2. Navegar por los archivos, \n 3. Salir\n");
    scanf("%d",&opcion);
    while(opcion != 3){
        if(opcion == 1){
            ordenar();
        }
        else if(opcion == 2){
            navegar();
        }
        printf("Bienvenido!\n 1. Ordenar los archivos. \n 2. Navegar por los archivos, \n 3. Salir\n");
        scanf("%d",&opcion);
    }
    printf("Adios!\n");
    return 0;
}