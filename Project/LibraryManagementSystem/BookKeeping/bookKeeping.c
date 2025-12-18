#include"../config.h"
#include <stdio.h>
#include"../Book/book.h"
#include"../Candidate/candidate.h"

void keep(BookKeeping bk){
    FILE *f;
    f = fopen("data/BookKeeping.dat","ab");  //ab = "Appending in Binory..."
    if(f==NULL){
        printf("File doesn't exist.\n");
        return;
    } 
    fwrite(&bk, sizeof(BookKeeping ), 1, f);
    fclose(f);
    printf("Data written successfully!\n");
}
void showBookKeepingRecords(){
    FILE *f = fopen("data/BookKeeping.dat","rb");
	if(f==NULL){
		printf("No borrow/return records found.\n");
		return;
	}
	BookKeeping bk;
    Book b;
    Candidate c;
	printf("BORROW/RETURN RECORDS:\n------------------------------------------------------------------\n");
	printf("%-4s | %-20s | %-4s | %-25s | %-12s | %-12s\n------------------------------------------------------------------\n","C_ID","NAME","B_ID","B NAME","DOI","DOR");
	while(fread(&bk,sizeof(BookKeeping),1,f)==1){
        b = B_Retrive(bk.B_ID);
        if(b.Book_ID == -1){
            continue; // Skip if book not found
        }
		b = B_Retrive(bk.B_ID);
        c = getCandidateById(bk.C_ID);
        printf("%-4d | %-20s | %-4d | %-25s | %-2d/%-2d/%-4d | %-2d/%-2d/%-4d\n", 
        bk.C_ID, c.Name, bk.B_ID, b.B_name,bk.DOI.day, bk.DOI.month,
        bk.DOI.year, bk.DOR.day, bk.DOR.month, bk.DOR.year);
	}
	fclose(f);
}
void getborrowbyC_ID(int C_ID){
    FILE *f = fopen("data/BookKeeping.dat","rb");
	if(f==NULL){
		printf("No borrow/return records found.\n");
		return;
	}
	BookKeeping bk;
    Book b;
    Candidate c;
    printf("BORROW/RETURN RECORDS:\n------------------------------------------------------------------\n");
	printf("%-4s | %-20s | %-4s | %-25s | %-12s | %-12s\n------------------------------------------------------------------\n","C_ID","NAME","B_ID","B NAME","DOI","DOR");
    while(fread(&bk,sizeof(BookKeeping),1,f)==1){
        if(C_ID==bk.C_ID){
            b = B_Retrive(bk.B_ID);
            c = getCandidateById(bk.C_ID);
            printf("%-4d | %-20s | %-4d | %-25s | %-2d/%-2d/%-4d | %-2d/%-2d/%-4d\n", bk.C_ID,
            c.Name, bk.B_ID, b.B_name,bk.DOI.day, bk.DOI.month, bk.DOI.year,
			  bk.DOR.day, bk.DOR.month, bk.DOR.year);
        }
    } 
}


/*
void main(){
    // BookKeeping bk = {1,2,{12,12,2023},{19,12,2023}};
    // keep(bk);
    showBookKeepingRecords();
    int id;
    printf("enter id ");
    scanf("%d",&id);
    getborrowbyC_ID(id);

}
*/

 
