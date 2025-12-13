#include"../config.h"
#include <stdio.h>
#include"../Book/book.h"    
void keep(BookKeeping bk){
    FILE *f;
    f = fopen("../data/BookKeeping.dat","ab");  //ab = "Appending in Binory..."
    if(f==NULL){
        printf("File doesn't exist.\n");
        return;
    } 
    fwrite(&bk, sizeof(BookKeeping ), 1, f);
    fclose(f);
    printf("Data written successfully!\n");
}
void showBookKeepingRecords(){
	FILE *f = fopen("../data/BookKeeping.dat","rb");
	if(f==NULL){
		printf("No borrow/return records found.\n");
		return;
	}
	BookKeeping bk;
    Book b;
	printf("BORROW/RETURN RECORDS:\n--------------------------------------------\n");
	printf("%-6s | %-6s | %-12s | %-12s\n","C_ID","B_ID","DOI","DOR");
	while(fread(&bk,sizeof(BookKeeping),1,f)==1){
        b = B_Retrive(bk.B_ID);
        if(b.Book_ID == -1){
            continue; // Skip if book not found
        }
		printf("%-6d | %-6d | %-25s | %-2d/%-2d/%-4d | %-2d/%-2d/%-4d\n", bk.C_ID, bk.B_ID,
			   b.B_name,bk.DOI.day, bk.DOI.month, bk.DOI.year,
			   bk.DOR.day, bk.DOR.month, bk.DOR.year);
	}
	fclose(f);
}


void main(){
    // BookKeeping bk = {1,2,{12,12,2023},{19,12,2023}};
    // keep(bk);
    showBookKeepingRecords();
}

 
