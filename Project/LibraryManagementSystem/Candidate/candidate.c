#include "candidate.h"

int getCandidateID() {
    Candidate c;
        FILE *f = fopen("data/candidate.dat", "rb");  // rb = read binary

        if (f == NULL) {
            printf("File doesn't exist.\n");
            return -1;
        }
    
    int temp=0;
    while (fread(&c, sizeof(Candidate), 1, f)){
        temp=c.id;
    }
    return temp+1;
}

void registerCandidate(Candidate c){
    FILE *fp;
        fp=fopen("data/candidate.dat", "ab");// w for write, b for binary, a for append
    if(fp==NULL){
        printf("File not found\n");
        return;
    }
    c.id = getCandidateID();
    fwrite(&c, sizeof(Candidate), 1, fp);
    fclose(fp);
    printf("Data written successfully!\n");
}
void showCandidate( ){
    Candidate c;
    FILE *fp;
           fp=fopen("data/candidate.dat","rb");
        if(fp==NULL){
            printf("File not found\n");
            return;
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
           fp=fopen("data/candidate.dat","rb");
        if(fp==NULL){
            printf("File not found\n");
            c.id = -1;
            return c;
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
Candidate getCandidateByContact(char *Contact){
    Candidate c;
    FILE *fp;
    fp=fopen("data/candidate.dat","rb");
    if(fp==NULL){
        printf("File not found");
        c.id = -1;
        return c;
    }
    while(fread(&c,sizeof(Candidate),1,fp)==1){
        if(strcmp(Contact,c.contact)==0){
            return c;
        }
    }
    fclose(fp);
    c.id = -1;
    return c;
}
// void main(){
//     Candidate c = {101, "lipika", "9876543219", "lipika.singh@gmail.com", {25, 2, 2024}, {0, 0, 0000}};
//     registerCandidate(c);
//     showCandidate();
//     // Candidate c = getCandidateById(1);
//     // if(c.id !=-1){
//     //     printf("Name: %s",c.Name);
//     // }else{
//     //     printf("not found");
//     // }
// }
