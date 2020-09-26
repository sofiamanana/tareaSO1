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
    //return arreglo;
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
    int num_o[300];
    int flags[300];
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

                }else{
                    
                    printf("-%s\n",dp->d_name);
                }
                
            }
                
            
        }
        for(int k=0; k<j;k++){
            num_o[k]=num_g[k];
        }
        for(int k = 0; k<j ;k++){
            flags[k]=0;
        }

        ordenar_g(num_g, j);
        
        for(int i=0; i<j; i++){
            for(int k=0; k<j; k++){
                if(num_g[i]==num_o[k] && flags[k]==0){
                    printf("-%s\n",arreglo[k]);
                    flags[k]=1;
                }
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