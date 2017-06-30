//
// Created by Ruwan on 6/22/2017.
//

#include <stdio.h>
void writeFile(char path[],char key[]){
    FILE *file;
    file=fopen(path, "w+"); //wb
    if (!file){
        printf("Error: Unable to open file!\n");
    }else{
        fwrite(key, sizeof(key), 1, file);
        printf("file >> %s  \n ", key );
    }

    fclose(file);

}
void readFile(char path[],char key[]){
    FILE *file;
    file=fopen(path, "r+"); //rb
    if (!file){
        printf("Error: Unable to open file!\n");
    }else {
        fread(key ,sizeof(key),1,file);
        printf("file >> %s \n", key );
    }
    fclose(file);
}
