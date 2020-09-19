#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
int main()
{   
    int i=0;
    DIR *dir;
    struct dirent *dp;
    const char *path="./Juegos"; 
    char direc[300];
    char word[300];
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
            while(!feof(fp)){
                fgets(word, sizeof(char)*300, fp);
                printf("%s\n", word);
            }

        }
    }
    closedir(dir);
    return 0;
}