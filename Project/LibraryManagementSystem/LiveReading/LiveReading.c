#include "../config.h"
#include <stdio.h>
#include <stdlib.h>

void initiate(LiveReading lr){
    FILE *f;
    f = fopen("LiveReading.dat","ab");  //ab = "Appending in Binory..."
       if(f==NULL){
        printf("File doesn't exist.");
    } 
    fwrite(&lr, sizeof(LiveReading ), 1, f);
    fclose(f);
    printf("Data written successfully!\n");
}
void showLiveRreading(){
    FILE *f;
    LiveReading lr;
    f =fopen("LiveReading.dat","rb"); //rb ="Reading in Binory..."
    if(f==NULL){
        printf("File not read.");
    }
    while(fread(&lr,sizeof(LiveReading),1,f)==1){
        printf("%d %d %d:%d:%d %d:%d:%d %d/%d/%d\n",lr.C_ID,lr.B_ID,lr.entry.hr,lr.entry.min,lr.entry.sec,lr.exit.hr,lr.exit.min,lr.exit.sec,lr.date.day,lr.date.month,lr.date.year);
    }
}
void main(){
    // LiveReading lr={3,6,{10,30,0},{12,0,0},{15,8,2024}};
    // initiate(lr);
    showLiveRreading();
}




