#include"../config.h"
#include <stdio.h>
void keep(BookKeeping bk){
    FILE *f;
    f = fopen("data/BookKeeping.dat","ab");  //ab = "Appending in Binory..."
    if(f==NULL){
        printf("File doesn't exist.\n");
        return;
    } 
    fwrite(&bk, sizeof(BookKeeping ), 1, f);
    fclose(f);
    printf("Data written successfully!\n");
}

/* void main(){
    // BookKeeping bk = {1,2,{12,12,2023},{19,12,2023}};
    // keep(bk);
}*/


