#include<stdio.h>
#include<stdlib.h>
typedef struct {
    int hr;
    int min;
    int sec;
}Time;
typedef struct{
    int day;
    int month;
    int year;
}Date;
typedef struct{
    int id;
    int amount;
    Time time;
    Date date;
} Transaction;

void logTransation(Transaction t){
    FILE *f;
    f = fopen("Transaction.dat","ab");
    if (f==NULL){
        printf("File does not exist.");
    }
    fwrite(&t,sizeof(Transaction),1,f);
    fclose(f);
    printf("Data written successfully!\n");
}

void getAllTransaction(){
    FILE *f;
    f = fopen("Transaction.dat","rb");
    if (f==NULL){
        printf("File does not exist.");
    }
    
}
void main(){
    Transaction t = {1,340,{9,50,30},{12,12,2012}};
    logTransation(t);
}

