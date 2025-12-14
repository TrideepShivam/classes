#include "../config.h"
#include <stdio.h>
#include <stdlib.h>
#include "../Book/book.h"

void initiate(LiveReading lr){
    FILE *f;
    f = fopen("data/LiveReading.dat","ab");  //ab = "Appending in Binory..."
       if(f==NULL){
        printf("File doesn't exist.\n");
        return;
    } 
    fwrite(&lr, sizeof(LiveReading ), 1, f);
    fclose(f);
    printf("Data written successfully!\n");
}
void showLiveRreading(){
    FILE *f;
    LiveReading lr;
    f =fopen("../data/LiveReading.dat","rb"); //rb ="Reading in Binory..."
    if(f==NULL){
        printf("File not read.\n");
        return;
    }
    while(fread(&lr,sizeof(LiveReading),1,f)==1){
        Book b = B_Retrive(1);
        printf("%s\n",b.B_name);
        printf("%d %d %d:%d:%d %d:%d:%d %d/%d/%d\n",lr.C_ID,lr.B_ID,lr.entry.hr,lr.entry.min,lr.entry.sec,lr.exit.hr,lr.exit.min,lr.exit.sec,lr.date.day,lr.date.month,lr.date.year);
    }
}
// void main(){
//     // LiveReading lr={1,26,{10,30,0},{12,0,0},{15,8,2024}};
//     // initiate(lr);
//     showLiveRreading();
// }




