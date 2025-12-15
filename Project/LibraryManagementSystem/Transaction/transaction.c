#include<stdio.h>
#include<stdlib.h>
#include"../config.h"

void logTransation(Transaction t){
    FILE *f;
    f = fopen("../data/Transaction.dat","ab");
    if (f==NULL){
        printf("File does not exist.\n");
        return;
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
        printf("File does not exist.\n");
        return;
    }
    printf("TRANSACTION DETAILS :\n--------------------------------------\n%-5s | %-6s | %-10s | %-12s\n----------------------------------------\n","ID","AMOUNT","TIME","DATE");
    while (fread(&t, sizeof(Transaction), 1, f)) {
        printf("%-5d | %-6d | %-2d:%-2d:%-2d | %-2d/%-2d/%-4d\n",t.id,t.amount,t.time.hr,t.time.min,t.time.sec,t.date.day,t.date.month,t.date.year);      
    }
    fclose(f);
}
void getTransactionById(int id){
    Transaction t;
    FILE *fp;
        fp=fopen("data/Transaction.dat","rb");
        if(fp==NULL){
            printf("File not found\n");
            return;
        }
    while(fread(&t,sizeof(Transaction),1,fp)==1){
        if(t.id==id){
            printf("TRANSACTION DETAILS :\n--------------------------------------\n%-5s | %-6s | %-10s | %-12s\n----------------------------------------\n","ID","AMOUNT","TIME","DATE");
            printf("%-5d | %-6d | %-2d:%-2d:%-2d | %-2d/%-2d/%-4d\n",t.id,t.amount,t.time.hr,t.time.min,t.time.sec,t.date.day,t.date.month,t.date.year);
            break;
        }
    }
    if(fread(&t,sizeof(Transaction),1,fp)==0){
        printf("invalid id\n");
    }
}
void getTransactionByDate(Date date){
    //code
    Transaction t;
    FILE *fp;
        fp=fopen("../data/Transaction.dat","rb");
        if(fp==NULL){
            printf("File not found\n");
            return;
        }
    while(fread(&t,sizeof(Transaction),1,fp)==1){
        if(t.date.day==date.day&&t.date.month==date.month&&t.date.year==date.year){
            printf("TRANSACTION DETAILS :\n--------------------------------------\n%-5s | %-6s | %-10s | %-12s\n----------------------------------------\n","ID","AMOUNT","TIME","DATE");
            printf("%-5d | %-6d | %-2d:%-2d:%-2d | %-2d/%-2d/%-4d\n",t.id,t.amount,t.time.hr,t.time.min,t.time.sec,t.date.day,t.date.month,t.date.year);
            break;
        }
    }
    if(fread(&t,sizeof(Transaction),1,fp)==0){
        printf("invalid id\n");
    }
}

//  void main(){
// //     Transaction t = {2,540,{9,10,30},{14,12,2015}};
// //     logTransation(t);
// //     //getAllTransaction();
// //     getTransactionById(2);
// Date d = {12,12,2012};
//     getTransactionByDate(d);
// }

