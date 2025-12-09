#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// for taking informations....
typedef struct {
    char B_name [100];
    char Author [50];
    int price;
    char Genere [50]; //catagory of book...
    int B_count;
    int Book_ID;
} Book;

// Function for register book details in file...
// Function nmae = "B_Register"....
void B_Register ( Book B_R){

    FILE *f;
    f = fopen("Book.dat","ab");  //wb = "Wrintig in Binory..."
       if(f==NULL){
        printf("File doesn't exist.");
    }
     
     fwrite(&B_R, sizeof(Book ), 1, f);

    fclose(f);
        printf("Data written successfully!\n");

}

// Function for retrive book details from file...
// Function nmae = "B_Retrive"....
Book B_Retrive (int id){
    Book B_R;
    FILE *f;
    f = fopen("Book.dat","rb");  //rb = "readin into Binory..."
       if(f==NULL){
        printf("File doesn't exist.");
    }
    while(fread(&B_R, sizeof(Book), 1, f)){
        if(B_R.Book_ID == id){
            return B_R;
        }
    }
    fclose(f);
    Book nullBook = {"","",-1,"",-1,-1};
    //returning null value if not found the value using the given id
    return nullBook;

}

// Function to print books by author
void get_book_by_author(const char *author) {
    Book B_R;
    FILE *f = fopen("Book.dat", "rb");  // rb = read binary

    if (f == NULL) {
        printf("File doesn't exist.\n");
        return;
    }

    int count = 0;
    printf("BOOK DETAILS :\n---------------------------------------------------------------------------------\n%-5s | %-20s | %-13s | %-15s | %-8s | %-5s\n---------------------------------------------------------------------------------\n","ID","NAME","AUTHOR","GENERE","PRICE","COUNT");
    while (fread(&B_R, sizeof(Book), 1, f)) {
        if (strcmp(B_R.Author, author) == 0) {
            count++;
            printf("%-5d | %-20s | %-13s | %-15s | %-8d | %-5d\n",B_R.Book_ID,B_R.B_name,B_R.Author,B_R.Genere,B_R.price,B_R.B_count);      
        }
    }

    if (count == 0) {
        printf("Sorry, Not found\n");
    }

    fclose(f);
}

// Function for get last id from Book.dat and print the ID after addining 1 in that ID.........
int get_ID() {
    Book B_R;
    FILE *f = fopen("Book.dat", "rb");  // rb = read binary

    if (f == NULL) {
        printf("File doesn't exist.\n");
        return;
    }
    int temp;
    while (fread(&B_R, sizeof(Book), 1, f)){
        temp=B_R.Book_ID;
    }
        
    return temp+1;

}

int main() {
   
    //Book B = {"Programming with C++", "Shivam", 1749, "Programming", 2, 26};
    // Book B = {"Fundamentals", "Shivam", 343, "Inspiration", 1, 25};
    // B_Register(B);
    //char author[50];
    //printf("Enter author name: ");
    //scanf("%s", author);
    //get_book_by_author(author);
    int temp =get_ID();
    printf("%d",temp);
    return 0;
}

