#include "config.h"
#include "./Book/book.h"
#include "./Candidate/candidate.h"
#include "./BookKeeping/bookKeeping.h"
#include "./Transaction/transaction.h"
#include "./LiveReading/liveReading.h"
#include <conio.h>

/* Forward declarations for submenu handlers */
void bookMenu(void);
void candidateMenu(void);
void borrowMenu(void);
void transactionMenu(void);
void readingMenu(void);
// function to store the date and time of the given variable through address


/* Helper to clear stdin line */
static void clear_stdin(void)
{
	int c;
	while ((c = getchar()) != EOF && c != '\n');
}

int main(void)
{
	int choice = 0;
	while (1)
	{
		printf("===== Library Management System =====\n");
		printf("1. Book Records\n");
		printf("2. Candidate Records\n");
		printf("3. Borrow/Return Records\n");
		printf("4. Transactions\n");
		printf("5. Live Reading Records\n");
		printf("6. Exit\n");
		printf("Enter your choice: ");
		if (scanf("%d", &choice) != 1)
		{
			/* clear invalid input */
			int c;
			while ((c = getchar()) != EOF && c != '\n')
				;
			printf("Invalid input. Try again.\n\n");
			continue;
		}
		switch (choice)
		{
		case 1:
			bookMenu();
			break;
		case 2:
			candidateMenu();
			break;
		case 3:
			borrowMenu();
			break;
		case 4:
			transactionMenu();
			break;
		case 5:
			readingMenu();
			break;
		case 6:
			printf("Sorry to see you go:)\n");
			return 0;
		default:
			printf("Invalid choice.\n");
		}
		printf("\n");
	}
	return 0;
}

/* ---------------- Menu implementations ---------------- */
void bookMenu(void)
{
	int ch = 0;
	Book b;
	while (1)
	{
		system("cls");
		printf("--- Book Menu ---\n");
		printf("1. Register Book\n");
		printf("2. Get books by author\n");
		printf("3. Get books by genere\n");
		printf("4. Get book by name\n");
		printf("5. Show all books\n");
		printf("0. Main Menu\n");
		printf("9. Exit\n");
		printf("Enter choice: ");
		if (scanf("%d", &ch) != 1)
		{
			clear_stdin();
			printf("Invalid input.\n\n");
			continue;
		}
		clear_stdin();
		if (ch == 0)
			return;
		if (ch == 9)
		{
			printf("Exiting...\n");
			exit(0);
		}
		if (ch == 1)
		{
			printf("Book name: ");
			fgets(b.B_name, sizeof(b.B_name), stdin);
			b.B_name[strcspn(b.B_name, "\n")] = 0;
			printf("Author: ");
			fgets(b.Author, sizeof(b.Author), stdin);
			b.Author[strcspn(b.Author, "\n")] = 0;
			printf("Genere: ");
			fgets(b.Genere, sizeof(b.Genere), stdin);
			b.Genere[strcspn(b.Genere, "\n")] = 0;
			printf("Price: ");
			scanf("%d", &b.price);
			clear_stdin();
			printf("Count: ");
			scanf("%d", &b.B_count);
			clear_stdin();
			b.Book_ID = get_ID();
			B_Register(b);
			printf("Book registered with ID %d\n", b.Book_ID);
		}
		else if (ch == 2)
		{
			char author[100];
			printf("Author: ");
			fgets(author, sizeof(author), stdin);
			author[strcspn(author, "\n")] = 0;
			get_book_by_author(author);
		}
		else if (ch == 3)
		{
			char g[50];
			printf("Genere: ");
			fgets(g, sizeof(g), stdin);
			g[strcspn(g, "\n")] = 0;
			get_book_by_genere(g);
		}
		else if (ch == 4)
		{
			char name[100];
			printf("Book name: ");
			fgets(name, sizeof(name), stdin);
			name[strcspn(name, "\n")] = 0;
			get_book_by_name(name);
		}
		else if (ch == 5)
		{
			Showall_Book();
		}
		else
		{
			printf("Invalid choice.\n");
		}
		printf("\nPress any key to continue: ");
		getch();
		printf("\n");
	}
}

void candidateMenu(void)
{
	int ch = 0;
	Candidate c;
	while (1)
	{
		system("cls");
		printf("--- Candidate Menu ---\n");
		printf("1. Register Candidate\n");
		printf("2. Show all Candidates\n");
		printf("3. Get Candidate by ID\n");
		printf("4. Get Candidate by Contact\n");
		printf("0. Main Menu\n");
		printf("9. Exit\n");
		printf("Enter choice: ");
		if (scanf("%d", &ch) != 1)
		{
			clear_stdin();
			printf("Invalid input.\n\n");
			continue;
		}
		clear_stdin();
		if (ch == 0)
			return;
		if (ch == 9)
		{
			printf("Exiting...\n");
			exit(0);
		}
		if (ch == 1)
		{
			printf("Name: ");
			fgets(c.Name, sizeof(c.Name), stdin);
			c.Name[strcspn(c.Name, "\n")] = 0;
			printf("Contact: ");
			fgets(c.contact, sizeof(c.contact), stdin);
			c.contact[strcspn(c.contact, "\n")] = 0;
			printf("Email: ");
			getchar();
			fgets(c.email, sizeof(c.email), stdin);
			c.email[strcspn(c.email, "\n")] = 0;
			Time t = {0,0,0};
			setCurrentDateTime(&c.doj,&t);
			c.doe = (Date){0,0,0};
			registerCandidate(c);
			printf("Candidate registered.\n");
		}
		else if (ch == 2)
		{
			showCandidate();
		}
		else if (ch == 3)
		{
			int id;
			printf("ID: ");
			if (scanf("%d", &id) != 1)
			{
				clear_stdin();
				printf("Invalid input.\n");
				continue;
			}
			Candidate r = getCandidateById(id);
			if(r.id!=-1)
				printf("Name: %s, Contact: %s\n", r.Name, r.contact);
			else
				printf("Invalid ID\n");
		}
		else if (ch == 4)
		{
			char contact[20];
			printf("Contact: ");
			fgets(contact, sizeof(contact), stdin);
			contact[strcspn(contact, "\n")] = 0;
			Candidate r = getCandidateByContact(contact);
			if(r.id!=-1)
			printf("Name: %s, email: %s\n", r.Name, r.email);
			else
			printf("Contact not found\n");
		}
		else
		{
			printf("Invalid choice.\n");
		}
		printf("\nPress any key to continue: ");
		getch();
		printf("\n");
	}
}

void borrowMenu(void)
{
	int ch = 0;
	BookKeeping bk;
	while (1)
	{
		system("cls");
		printf("--- Borrow/Return Menu ---\n");
		printf("1. Borrow (keep record)\n");
		printf("2. Get borrow records by Candidate ID\n");
		printf("3. Show all Borrow/Return Records\n");
		printf("0. Main Menu\n");
		printf("9. Exit\n");
		printf("Enter choice: ");
		if (scanf("%d", &ch) != 1)
		{
			clear_stdin();
			printf("Invalid input.\n\n");
			continue;
		}
		clear_stdin();
		if (ch == 0)
			return;
		if (ch == 9)
		{
			printf("Exiting...\n");
			exit(0);
		}
		if (ch == 1)
		{
			printf("Candidate ID: ");
			if (scanf("%d", &bk.C_ID) != 1)
			{
				clear_stdin();
				printf("Invalid input.\n");
				continue;
			}
			if(getCandidateById(bk.C_ID).id!=-1){
				Showall_Book();
				printf("Choose Book ID: ");
				if (scanf("%d", &bk.B_ID) != 1)
				{
					clear_stdin();
					printf("Invalid input.\n");
					continue;
				}
				clear_stdin();
				Time t = {0,0,0};
				setCurrentDateTime(&bk.DOI,&t);
				bk.DOR = (Date){0,0,0};
				keep(bk);
				printf("Borrow recorded.\n");
			}else{
				printf("Candidate ID is invalid: Try again\n");
			}
		}
		else if (ch == 2)
		{
			int id;
			printf("Candidate ID: ");
			if (scanf("%d", &id) != 1)
			{
				clear_stdin();
				printf("Invalid input.\n");
				continue;
			}
			getborrowbyC_ID(id);
		}
		else if (ch == 3)
		{
			showBookKeepingRecords();
		}
		else
		{
			printf("Invalid choice.\n");
		}
		printf("\nPress any key to continue: ");
		getch();
		printf("\n");
	}
}

void transactionMenu(void)
{
	int ch = 0;
	Transaction t;
	while (1)
	{
		system("cls");
		printf("--- Transaction Menu ---\n");
		printf("1. Log Transaction\n");
		printf("2. Show All Transactions\n");
		printf("3. Get Transaction by ID\n");
		printf("4. Get Transaction by Date\n");
		printf("0. Main Menu\n");
		printf("9. Exit\n");
		printf("Enter choice: ");
		if (scanf("%d", &ch) != 1)
		{
			clear_stdin();
			printf("Invalid input.\n\n");
			continue;
		}
		clear_stdin();
		if (ch == 0)
			return;
		if (ch == 9)
		{
			printf("Exiting...\n");
			exit(0);
		}
		if (ch == 1)
		{
			printf("CANDITATE ID: ");
			if (scanf("%d", &t.id) != 1)
			{
				clear_stdin();
				printf("Invalid input.\n");
				continue;
			}
			Candidate c = getCandidateById(t.id);
			if(c.id != -1){
				printf("Amount: ");
				if (scanf("%d", &t.amount) != 1)
				{
					clear_stdin();
					printf("Invalid input.\n");
					continue;
				}
				clear_stdin();
				setCurrentDateTime(&t.date, &t.time);
				logTransaction(t);
				printf("Transaction logged with name: %s amount: %d\n",c.Name,t.amount);
			}else{
				printf("Invalid Candidate ID: Try again\n");
			}
		}
		else if (ch == 2)
		{
			getAllTransaction();
		}
		else if (ch == 3)
		{
			int id;
			printf("ID: ");
			if (scanf("%d", &id) != 1)
			{
				clear_stdin();
				printf("Invalid input.\n");
				continue;
			}
			getTransactionById(id);
		}
		else if (ch == 4)
		{
			Date d;
			printf("Day Month Year: ");
			if (scanf("%d %d %d", &d.day, &d.month, &d.year) != 3)
			{
				clear_stdin();
				printf("Invalid input.\n");
				continue;
			}
			getTransactionByDate(d);
		}
		else
		{
			printf("Invalid choice.\n");
		}
		printf("\nPress any key to continue: ");
		getch();
		printf("\n");
	}
}

void readingMenu(void)
{
	int ch = 0;
	LiveReading lr;
	while (1)
	{
		system("cls");
		printf("--- Live Reading Menu ---\n");
		printf("1. Initiate Live Reading\n");
		printf("2. Show Live Reading Records\n");
		printf("3. Done Live Reading\n");
		printf("0. Main Menu\n");
		printf("9. Exit\n");
		printf("Enter choice: ");
		if (scanf("%d", &ch) != 1)
		{
			clear_stdin();
			printf("Invalid input.\n\n");
			continue;
		}
		clear_stdin();
		if (ch == 0)
			return;
		if (ch == 9)
		{
			printf("Exiting...\n");
			exit(0);
		}
		if (ch == 1)
		{
			printf("Candidate ID: ");
			if (scanf("%d", &lr.C_ID) != 1)
			{
				clear_stdin();
				printf("Invalid input.\n");
				continue;
			}
			if(getCandidateById(lr.C_ID).id!=-1){
				Showall_Book();
				printf("Choose Book ID: ");
				if (scanf("%d", &lr.B_ID) != 1)
				{
					clear_stdin();
					printf("Invalid input.\n");
					continue;
				}
				clear_stdin();
				setCurrentDateTime(&lr.date,&lr.entry);
				lr.exit = (Time){0,0,0};
				initiate(lr);
				printf("Live reading initiated.\n");
			}else{
				printf("Candidate ID is invalid: Try again\n");
			}
		}
		else if (ch == 2)
		{
			showLiveRreading();
		}
		else if (ch == 3)
		{
			printf("CANDITATE ID: ");
			if (scanf("%d", &lr.C_ID) != 1)
			{
				clear_stdin();
				printf("Invalid input.\n");
				continue;
			}
			Candidate c = getCandidateById(lr.C_ID);
			if(c.id != -1){
				destroy(lr.C_ID);
			}else{
				printf("Candidate Id is invalid\n");
			}
		}
		else
		{
			printf("Invalid choice.\n");
		}
		printf("\nPress any key to continue: ");
		getch();
		printf("\n");
	}
}