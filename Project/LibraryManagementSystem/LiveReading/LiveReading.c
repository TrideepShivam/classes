#include "../config.h"
#include <stdio.h>
#include <stdlib.h>
#include "../Book/book.h"
#include "../Candidate/candidate.h"
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
    f =fopen("data/LiveReading.dat","rb"); //rb ="Reading in Binory..."
    if(f==NULL){
        printf("File not read.\n");
        return;
    }
    printf("CANDIDATE DETAILS :\n------------------------------------------------------------------------------------------------\n%-4s | %-20s | %-4s | %-25s | %-8s | %-8s | %-12s\n------------------------------------------------------------------------------------------------\n","ID","NAME","B ID","B NAME","ENTRY","EXIT","DATE");
    while(fread(&lr,sizeof(LiveReading),1,f)==1){
        Book b = B_Retrive(lr.B_ID);
        Candidate c=getCandidateById(lr.C_ID);
        printf("%-4d | %-20s | %-4d| %-25s | %2d:%2d:%2d | %2d:%2d:%2d| %2d/%2d/%4d\n",lr.C_ID,c.Name,lr.B_ID,b.B_name,lr.entry.hr,lr.entry.min,lr.entry.sec,lr.exit.hr,lr.exit.min,lr.exit.sec,lr.date.day,lr.date.month,lr.date.year);
    }
}

// void main(){
//     LiveReading lr={102,2,{10,40,0},{2,10,50},{15,2,2024}};
//     initiate(lr);
//     showLiveRreading();
// }