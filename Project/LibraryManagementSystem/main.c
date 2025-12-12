#include "config.h"
#include "./Book/book.h"
#include "./Candidate/candidate.h"
#include "./BookKeeping/bookKeeping.h"
#include "./Transaction/transaction.h"
#include "./LiveReading/liveReading.h"

#include <stdio.h>

/* Helper to display BookKeeping (borrow/return) records */
void showBookKeepingRecords(void){
	FILE *f = fopen("data/BookKeeping.dat","rb");
	if(f==NULL){
		printf("No borrow/return records found.\n");
		return;
	}
	BookKeeping bk;
	printf("BORROW/RETURN RECORDS:\n--------------------------------------------\n");
	printf("%-6s | %-6s | %-12s | %-12s\n","C_ID","B_ID","DOI","DOR");
	while(fread(&bk,sizeof(BookKeeping),1,f)==1){
		printf("%-6d | %-6d | %-2d/%-2d/%-4d | %-2d/%-2d/%-4d\n", bk.C_ID, bk.B_ID,
			   bk.DOI.day, bk.DOI.month, bk.DOI.year,
			   bk.DOR.day, bk.DOR.month, bk.DOR.year);
	}
	fclose(f);
}

int main(void){
	int choice = 0;
	while(1){
		printf("===== Library Management System =====\n");
		printf("1. Book Records\n");
		printf("2. Candidate Records\n");
		printf("3. Borrow/Return Records\n");
		printf("4. Transactions\n");
		printf("5. Live Reading Records\n");
		printf("6. Exit\n");
		printf("Enter your choice: ");
		if(scanf("%d", &choice)!=1){
			/* clear invalid input */
			int c; while((c=getchar())!=EOF && c!='\n');
			printf("Invalid input. Try again.\n\n");
			continue;
		}

		switch(choice){
			case 1:
				Showall_Book();
				break;
			case 2:
				showCandidate();
				break;
			case 3:
				showBookKeepingRecords();
				break;
			case 4:
				getAllTransaction();
				break;
			case 5:
				showLiveRreading();
				break;
			case 6:
				printf("Exiting.\n");
				return 0;
			default:
				printf("Invalid choice. Please choose 1-6.\n");
		}
		printf("\n");
	}
	return 0;
}