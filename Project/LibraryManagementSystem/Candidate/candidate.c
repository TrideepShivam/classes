#include<stdio.h>
#include<stdlib.h>
typedef struct {
    int day;
    int month;
    int year;
} Date;
typedef struct {
    int id;
    char Name[50];
    char contact[11];
    char email[50];
    Date doj;
    Date doe;
}Candidate;

void registerCandidate(Candidate c){
    FILE *fp;
    fp=fopen("candidate.dat", "ab");// w for write, b for binary, a for append
    if(fp==NULL){
        printf("File not found");
    }
    fwrite(&c, sizeof(Candidate), 1, fp);
    fclose(fp);
    printf("Data written successfully!\n");
}
void showCandidate( ){
    Candidate c;
    FILE *fp;
    fp=fopen("candidate.dat","rb");
    if(fp==NULL){
         printf("File not found");
    }
    printf("CANDIDATE DETAILS :\n-------------------------------------------------------------------------------------------\n%-4s | %-20s | %-10s | %-20s | %-13s | %-10s\n-------------------------------------------------------------------------------------------\n","ID","NAME","CONTACT","EMAIL","JOINING DATE","EXIT DATE");
    while(fread(&c,sizeof(Candidate),1,fp)==1){
        printf("%-4d | %-20s | %-10s | %-20s | %-2d/%-2d/%-7d | %-2d/%-2d/%-4d \n",c.id,c.Name,c.contact,c.email,c.doj.day,c.doj.month,c.doj.year,c.doe.day,c.doe.month,c.doe.year);
    }
    fclose(fp);
}
Candidate getCandidateById(int id){
    Candidate c;
    FILE *fp;
    fp=fopen("candidate.dat","rb");
    if(fp==NULL){
         printf("File not found");
    }
    while(fread(&c,sizeof(Candidate),1,fp)==1){
        if(c.id==id){
            return c;
        }
    }
    fclose(fp);
    c.id = -1;
    return c;
}
void main(){
    Candidate c = {2, "Isha Singh", "9878907890", "isha.singh@gmail.com", {15, 12, 2020}, {2, 2, 2023}};
    registerCandidate(c);
    showCandidate();
    // Candidate c = getCandidateById(1);
    // if(c.id !=-1){
    //     printf("Name: %s",c.Name);
    // }else{
    //     printf("not found");
    // }
}
