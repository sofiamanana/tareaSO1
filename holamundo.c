#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
int main()
{   
    int i=1;
    DIR *dir;
    struct dirent *dp;
    const char *path="./Juegos"; 
    FILE *file;
    dir = opendir(path);
<<<<<<< HEAD
    if(dir==NULL){
        printf("No se abrio el directorio");
        exit(2);
    }
    while((dp=readdir(dir))!=NULL){
        printf("%d\t%d\t%d\t%s\n",dp->d_ino,dp->d_off,dp->d_reclen,dp->d_name);
    }
    closedir(dir);
    return 0;
}
=======
    while(dp=readdir(dir)){
        dp->d_name;
        print("%d",i);
        i++;
    }
    return 0;
}
>>>>>>> 52180394b6f370bd96d1643bb213b03028110b2a
