#include<stdio.h>
#include<stdlib.h>
typedef struct{
   int hr;
   int min;
   int sec;
}Time;
typedef struct{
    int day;
    int month;
    int year;
}Date;


typedef struct {
    int C_ID;
    int B_ID;
    Time entry;
    Time exit;
    Date date;
}LiveReading;
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

void main(){
    LiveReading lr={3,6,{10,30,0},{12,0,0},{15,8,2024}};
    initiate(lr);
}




