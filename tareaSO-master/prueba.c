#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

int main(){
    rename("./Juegos/Among us.txt","./Rpg/Among us.txt");
    return 0;
}