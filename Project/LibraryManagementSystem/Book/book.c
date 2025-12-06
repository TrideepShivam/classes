#include<stdio.h>
#include<stdlib.h>

// for taking informations....
typedef struct {
    char B_name [100];
    char Author_FN [50];
    int price;
    char Genere [50]; //catagory of book...
    int B_count;
    int Book_ID;
} Book;

// Function for register book details in file...
// Function nmae = "B_Register"....
void B_Register ( Book B_R){

    FILE *f;
    f = fopen("Book.dat","wb");  //wb = "Wrintig in Binory..."
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

int main () {

   // Book B={"Fundamantals","Shivam ",343,"Inspiration",1,25};
    // B_Register (B);
    int id;
    printf("Book id ");
    scanf("%d",&id);
     Book b = B_Retrive(id);
    if(b.Book_ID==-1){
        printf("Id not found");
    }else{
        printf("%s",b.B_name);
    }
    return 0;
}
