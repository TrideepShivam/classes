#include<stdio.h>
#include<stdlib.h>
typedef struct {
    int day;
    int month;
    int year;
} Date;
typedef struct {
    int id;
    char Name[100];
    char contact[10];
    char email[50];
    Date doj;
    Date doe;
}Candidate;

void registerCandidate(Candidate c){
    FILE *fp;
    fp=fopen("candidate.dat", "wb");
    if(fp==NULL){
        printf("File not found");
    }
    fwrite(&c, sizeof(Candidate), 1, fp);
    fclose(fp);
    printf("Data written successfully!\n");
}


void main(){
    Candidate c = {1, "John Doe", "1234567890", "johndoe.xyz@gmail.com", {1, 1, 2020}, {1, 1, 2025}};
    registerCandidate(c);
}
