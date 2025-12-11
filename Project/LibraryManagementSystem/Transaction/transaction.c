#include<stdio.h>
#include<stdlib.h>
#include"../config.h"

void logTransation(Transaction t){
    FILE *f;
    f = fopen("data/Transaction.dat","ab");
    if (f==NULL){
        printf("File does not exist.");
    }
    fwrite(&t,sizeof(Transaction),1,f);
    fclose(f);
    printf("Data written successfully!\n");
}

void getAllTransaction(){
    FILE *f;
    Transaction t;
    f = fopen("data/Transaction.dat","rb");
    if (f==NULL){
        printf("File does not exist.");
    }
    printf("TRANSACTION DETAILS :\n--------------------------------------\n%-5s | %-6s | %-10s | %-12s\n----------------------------------------\n","ID","AMOUNT","TIME","DATE");
    while (fread(&t, sizeof(Transaction), 1, f)) {
        printf("%-5d | %-6d | %-2d:%-2d:%-2d | %-2d/%-2d/%-4d\n",t.id,t.amount,t.time.hr,t.time.min,t.time.sec,t.date.day,t.date.month,t.date.year);      
    }
    fclose(f);
}

void main(){
    // Transaction t = {1,340,{9,50,30},{12,12,2012}};
    // logTransation(t);
    getAllTransaction();
}

