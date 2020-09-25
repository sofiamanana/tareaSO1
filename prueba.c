#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

void ordenar_g(int *arreglo, int j){
    
    int aux;
    int i;
    int k;
    
    for(k=0; k<j-1;k++){
        for(i=1; i<j;i++){
            if(arreglo[i-1]>arreglo[i]){
                aux = arreglo[i];
                arreglo[i]=arreglo[i-1];
                arreglo[i-1]=aux;
            }
        }
    }
}


void navegar(){
    char actual[300];
    char nombre[300];
    char opcion[300];
    char titulo[300];
    char genero[300];
    char company[300];
    char descr[300];
    char arreglo[50][200];
    char nom[300];
    int num_g[300];
    char *aux;
    DIR *dir;
    FILE *fp;
    struct dirent *dp;
    const char s[2] = ",";
    char *token;
    
    
    while(strcmp(opcion,"4\n")!=0){
        getcwd(actual,sizeof(actual)); 
        dir = opendir(actual);
        printf("\nLa ubicacion actual es:%s y contiene:\n\n",actual);
        if(dir==NULL){
            printf("No se abrio el directorio");
            exit(2);
        }
        int i=0;
        int j=0;
        while( (dp=readdir(dir)) ){
            
            if ((strcmp(dp->d_name,".") == 0) || (strcmp(dp->d_name,"..") == 0)){		
            }
            else{
                strcpy(nom,dp->d_name);
            
            if (strstr(nom, ".txt") != NULL) {
                int k=0;
                fp = fopen(nom,"r");
                fgets(titulo, sizeof(char)*300, fp);
                fgets(genero, sizeof(char)*300, fp);
                
                
                token = strtok(genero, s);
                
                while( token != NULL ) {
                    k+=1;
                    token = strtok(NULL, s);
                }
                num_g[j]=k;
                strcpy(arreglo[j],nom);
                j+=1;

            }
                i+=1;
                printf("Archivo %d: %s\n",i,dp->d_name);
            }
                
            
        }
        ordenar_g(num_g, j);
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

int main () {
    navegar();
   
   return(0);
}