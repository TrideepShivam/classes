#include "config.h"
#include "./Book/book.h"
#include "./Candidate/candidate.h"
#include "./BookKeeping/bookKeeping.h"
#include "./Transaction/transaction.h"
#include "./LiveReading/liveReading.h"
#include<conio.h>
#include<windows.h>

/* Forward declarations for submenu handlers */
void bookMenu(void);
void candidateMenu(void);
void borrowMenu(void);
void transactionMenu(void);
void readingMenu(void);

/* Helper to clear stdin line */
static void clear_stdin(void){ int c; while((c=getchar())!=EOF && c!='\n'); }

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
		system("cls");
		switch (choice) {
			case 1: bookMenu(); break;
			case 2: candidateMenu(); break;
			case 3: borrowMenu(); break;
			case 4: transactionMenu(); break;
			case 5: readingMenu(); break;
			case 6: printf("Sorry to see you go:)\n"); return 0;
			default: printf("Invalid choice.\n");
		}
		printf("\n");
	}
	printf("Press any key to continue: ");
	getch();
	return 0;
}


/* ---------------- Menu implementations ---------------- */
void bookMenu(void){
	int ch=0;
	Book b;
	while(1){
		printf("--- Book Menu ---\n");
		printf("1. Register Book\n");
		printf("2. Retrieve book by ID\n");
		printf("3. Get books by author\n");
		printf("4. Get books by genere\n");
		printf("5. Get book by name\n");
		printf("6. Show all books\n");
		printf("7. Check availability by ID\n");
		printf("0. Main Menu\n");
		printf("9. Exit\n");
		printf("Enter choice: ");
		if(scanf("%d", &ch)!=1){ clear_stdin(); printf("Invalid input.\n\n"); continue; }
		clear_stdin();
		if(ch==0) return;
		if(ch==9){ printf("Exiting...\n"); exit(0); }
		if(ch==1){
			printf("Book name: "); fgets(b.B_name, sizeof(b.B_name), stdin);
			b.B_name[strcspn(b.B_name,"\n")]=0;
			printf("Author: "); fgets(b.Author, sizeof(b.Author), stdin); b.Author[strcspn(b.Author,"\n")]=0;
			printf("Genere: "); fgets(b.Genere, sizeof(b.Genere), stdin); b.Genere[strcspn(b.Genere,"\n")]=0;
			printf("Price: "); scanf("%d", &b.price); clear_stdin();
			printf("Count: "); scanf("%d", &b.B_count); clear_stdin();
			b.Book_ID = get_ID();
			B_Register(b);
			printf("Book registered with ID %d\n", b.Book_ID);
		} else if(ch==2){
			int id; printf("Enter Book ID: "); if(scanf("%d", &id)!=1){ clear_stdin(); printf("Invalid input.\n"); continue; }
			Book r = B_Retrive(id);
			printf("Name: %s, Author: %s, Genere: %s, Price: %d, Count: %d, ID: %d\n",
				   r.B_name, r.Author, r.Genere, r.price, r.B_count, r.Book_ID);
		} else if(ch==3){
			char author[100]; printf("Author: "); fgets(author, sizeof(author), stdin); author[strcspn(author,"\n")]=0;
			get_book_by_author(author);
		} else if(ch==4){
			char g[50]; printf("Genere: "); fgets(g, sizeof(g), stdin); g[strcspn(g,"\n")]=0;
			get_book_by_genere(g);
		} else if(ch==5){
			char name[100]; printf("Book name: "); fgets(name, sizeof(name), stdin); name[strcspn(name,"\n")]=0;
			get_book_by_name(name);
		} else if(ch==6){
			Book all = Showall_Book();
			printf("Sample book from Showall_Book - Name: %s\n", all.B_name);
		} else if(ch==7){
			int id; printf("Enter Book ID: "); if(scanf("%d", &id)!=1){ clear_stdin(); printf("Invalid input.\n"); continue; }
			printf(is_available(id)?"Available\n":"Not available\n");
		} else {
			printf("Invalid choice.\n");
		}
		printf("\n");
	}
}

void candidateMenu(void){
	int ch=0; Candidate c;
	while(1){
		printf("--- Candidate Menu ---\n");
		printf("1. Register Candidate\n");
		printf("2. Show all Candidates\n");
		printf("3. Get Candidate by ID\n");
		printf("4. Get Candidate by Contact\n");
		printf("0. Main Menu\n");
		printf("9. Exit\n");
		printf("Enter choice: ");
		if(scanf("%d", &ch)!=1){ clear_stdin(); printf("Invalid input.\n\n"); continue; }
		clear_stdin();
		if(ch==0) return;
		if(ch==9){ printf("Exiting...\n"); exit(0); }
		if(ch==1){
			printf("Name: "); fgets(c.Name, sizeof(c.Name), stdin); c.Name[strcspn(c.Name,"\n")]=0;
			printf("Contact: "); fgets(c.contact, sizeof(c.contact), stdin); c.contact[strcspn(c.contact,"\n")]=0;
			printf("Email: "); fgets(c.email, sizeof(c.email), stdin); c.email[strcspn(c.email,"\n")]=0;
			registerCandidate(c);
			printf("Candidate registered.\n");
		} else if(ch==2){ showCandidate(); }
		else if(ch==3){ int id; printf("ID: "); if(scanf("%d", &id)!=1){ clear_stdin(); printf("Invalid input.\n"); continue;} Candidate r=getCandidateById(id); printf("Name: %s, Contact: %s\n", r.Name, r.contact); }
		else if(ch==4){ char contact[20]; printf("Contact: "); fgets(contact, sizeof(contact), stdin); contact[strcspn(contact,"\n")]=0; Candidate r=getCandidateByContact(contact); printf("Name: %s, ID: %d\n", r.Name, r.id); }
		else { printf("Invalid choice.\n"); }
		printf("\n");
	}
}

void borrowMenu(void){
	int ch=0; BookKeeping bk;
	while(1){
		printf("--- Borrow/Return Menu ---\n");
		printf("1. Borrow (keep record)\n");
		printf("2. Get borrow records by Candidate ID\n");
		printf("3. Show all Borrow/Return Records\n");
		printf("0. Main Menu\n");
		printf("9. Exit\n");
		printf("Enter choice: "); if(scanf("%d", &ch)!=1){ clear_stdin(); printf("Invalid input.\n\n"); continue; }
		clear_stdin();
		if(ch==0) return;
		if(ch==9){ printf("Exiting...\n"); exit(0); }
		if(ch==1){ printf("Candidate ID: "); if(scanf("%d", &bk.C_ID)!=1){ clear_stdin(); printf("Invalid input.\n"); continue; } printf("Book ID: "); if(scanf("%d", &bk.B_ID)!=1){ clear_stdin(); printf("Invalid input.\n"); continue; } clear_stdin(); keep(bk); printf("Borrow recorded.\n"); }
		else if(ch==2){ int id; printf("Candidate ID: "); if(scanf("%d", &id)!=1){ clear_stdin(); printf("Invalid input.\n"); continue; }  getborrowbyC_ID(id);}        
		else if(ch==3){ showBookKeepingRecords(); }
		else { printf("Invalid choice.\n"); }
		printf("\n");
	}
}

void transactionMenu(void){
	int ch=0; Transaction t;
	while(1){
		printf("--- Transaction Menu ---\n");
		printf("1. Log Transaction\n");
		printf("2. Show All Transactions\n");
		printf("3. Get Transaction by ID\n");
		printf("4. Get Transaction by Date\n");
		printf("0. Main Menu\n");
		printf("9. Exit\n");
		printf("Enter choice: "); if(scanf("%d", &ch)!=1){ clear_stdin(); printf("Invalid input.\n\n"); continue; }
		clear_stdin();
		if(ch==0) return;
		if(ch==9){ printf("Exiting...\n"); exit(0); }
		if(ch==1){ printf("Transaction ID: "); if(scanf("%d", &t.id)!=1){ clear_stdin(); printf("Invalid input.\n"); continue; } printf("Amount: "); if(scanf("%d", &t.amount)!=1){ clear_stdin(); printf("Invalid input.\n"); continue; } clear_stdin(); logTransaction(t); printf("Transaction logged.\n"); }
		else if(ch==2){ getAllTransaction(); }
		else if(ch==3){ int id; printf("ID: "); if(scanf("%d", &id)!=1){ clear_stdin(); printf("Invalid input.\n"); continue; } getTransactionById(id); }
		else if(ch==4){ Date d; printf("Day Month Year: "); if(scanf("%d %d %d", &d.day, &d.month, &d.year)!=3){ clear_stdin(); printf("Invalid input.\n"); continue; } getTransactionByDate(d); }
		else { printf("Invalid choice.\n"); }
		printf("\n");
	}
}

void readingMenu(void){
	int ch=0; LiveReading lr;
	while(1){
		printf("--- Live Reading Menu ---\n");
		printf("1. Initiate Live Reading\n");
		printf("2. Show Live Reading Records\n");
		printf("0. Main Menu\n");
		printf("9. Exit\n");
		printf("Enter choice: "); if(scanf("%d", &ch)!=1){ clear_stdin(); printf("Invalid input.\n\n"); continue; }
		clear_stdin();
		if(ch==0) return;
		if(ch==9){ printf("Exiting...\n"); exit(0); }
		if(ch==1){ printf("Candidate ID: "); if(scanf("%d", &lr.C_ID)!=1){ clear_stdin(); printf("Invalid input.\n"); continue; } printf("Book ID: "); if(scanf("%d", &lr.B_ID)!=1){ clear_stdin(); printf("Invalid input.\n"); continue; } clear_stdin(); initiate(lr); printf("Live reading initiated.\n"); }
		else if(ch==2){ showLiveRreading(); }
		else { printf("Invalid choice.\n"); }
		printf("\n");
	}
}