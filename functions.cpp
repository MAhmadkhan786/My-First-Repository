
#include<iostream>
#include "functions.h"
#include <fstream>
#include <string>
using namespace std;

void MergeFiles(){
 
          int *file1 = new int[100];           
          int *file2 = new int[100];
          int *merge = new int[200];
        
int i = 0;
 ifstream read1("MyFile1.txt", ios::in);

   if (!read1.is_open()){
    cout << "Unable to open file";
   }else{
      while(!read1.eof()){
            read1  >> file1[i] >> ws ;       
            i++;
      }
      cout << " The value of i is : "<< i << endl;
    read1.close();
   }

   
int j = 0;   
     ifstream read2("MyFile2.txt", ios::in);

    if (!read2.is_open()){
    cout << "Unable to open file";
   }else{
      while(!read2.eof()){
            read2 >> file2[j]  >> ws ;
            j++;
      }
        cout << " The value of j is : "<< j << endl;
      read2.close();
   }

int totalElemnets = i+j;
  cout << " The value of totalElements is : "<< totalElemnets<< endl;
int k=0;
    for(int a=0; a < i; a++){
        merge[k] = file1[a];
        k++;
    }

     for(int a=0; a < i; a++){
        merge[k] = file2[a];
        k++;
    }

    ofstream mergefile("MyFile3.txt", ios :: app);

                if(!mergefile.is_open()){
                    cout << "Unable to open file";
                }else{
                     
                     int x=0;
                     while(x<totalElemnets)
                     {
                        mergefile << merge[x]<<" ";
                        x++;
                     }

                     mergefile << endl;
                     mergefile.close();
                }
            
          delete[]file1;
          delete[]file2;
          delete[]merge;
}

struct Book{
   string title, author;
   float price;
};

void viewBookDetails(){

   Book* book1 = new Book[100];

 int i = 0;
   ifstream inves("BookInventory.txt", ios :: in);
      
       if (!inves.is_open()){
         cout << "Error opening the file." << endl;
         delete[]book1;
         return;
       }
       else{

           while(!inves.eof()){
                
                inves >> book1[i].title   >> ws ; 
                inves >> book1[i].author  >> ws ; 
                inves >> book1[i].price   >> ws ; 
            
                i++;
           }
           inves.close();
       }
    
           cout << "\n No. of books available are : " << i<< endl;
             for (int k=0; k<i; k++){
                
                cout <<"\n  Book Name : " <<  book1[k].title   << endl;
                cout <<"  Author    : "   <<  book1[k].author  << endl;
                cout <<"  Price     : "   <<  book1[k].price   << endl;

                cout << endl;          
             }
             delete[]book1;
             cout << endl;
}
void addDetails(){

       Book* add = new Book[100];
       char choose;
       int num;

     while(true){
     cout << "\n Do you want to add some books. Press a (or b to break): " << endl;
     cin  >> choose;

          if (cin.fail()){       
             cout << " Invalid input !" << endl;
             cin.clear();
             cin.ignore();
          }

         if (choose == 'a' || choose == 'A'){

            cout << " How many ?  " ;
            cin >> num;

            for (int i=0; i <num; i++){

                cout << " Enter book name     : ";
                cin  >>  add[i].title;

                      cout <<" Enter author,s name : ";
                      cin >> add[i].author;

                             cout << " Enter price         : ";
                             cin  >> add[i].price;
                                                 cout << endl;
            }        
        }
         else if (choose == 'b'){
               break;
            }
            else{
               cout << " Invalid Input ! " << endl;
               continue;
            }
    }
           cout << "\n Books were added successfully ! " << endl;
    ofstream writeBooks("BookInventory.txt", ios :: app);

                if (!writeBooks.is_open()){
                  cout << " Unable to open the file !" <<endl;
                }
                else {
                  int a = 0;
                    while (a < num){
                    
                         writeBooks << add[a].title << endl;
                         writeBooks << add[a].author << endl;
                         writeBooks << add[a].price << endl;
                         a++;
                    }
                }
                delete[]add;
}
void updateDetails() {
    viewBookDetails(); 

    int bookNo;
    cout << "Enter the book no to update: ";
    cin >> bookNo;

    if (cin.fail() || bookNo < 0) {
        cout << "Invalid input for book number!" << endl;
        cin.clear();
        cin.ignore();
        return;
    }

    Book* change = new Book[100];
      int i = 0;
    ifstream inves("BookInventory.txt", ios::in);
    if (!inves.is_open()) {
        cout << "Error opening the file." << endl;
        delete[] change;
        return;
    } else {
      
        while (!inves.eof()) {
            inves >> change[i].title  >> ws;
            inves >> change[i].author >> ws;
            inves >> change[i].price  >> ws;

            i++;
        }
        inves.close();
    }

    if (bookNo > 0 && bookNo < i) {
        cout << "Enter updated details for book " << bookNo << ":" << endl;
        cout << "Enter book name     : ";
        cin >> change[bookNo-1].title; 

        cout << "Enter author's name : ";
        cin >> change[bookNo-1].author;

        cout << "Enter price         : ";
        cin >> change[bookNo-1].price;
    } else {
        cout << "Invalid book number! No changes made." << endl;
    }

    ofstream writeBooks("BookInventory.txt", ios::trunc); 

    if (!writeBooks.is_open()) {
        cout << "Unable to open the file!" << endl;
    } else {
        int a = 0;
        while (a < i) {
            writeBooks << change[a].title << endl;
            writeBooks << change[a].author << endl;
            writeBooks << change[a].price << endl;
            a++;
        }
    }

    delete[] change;
    cout << "Book details updated successfully!" << endl;
}

  void bookInventory(){
               
             cout << "\n\t| Book Inventory |"  << endl; 

    int choice;

    while(true){
    cout << "\n Press a key (or any negative value to break) "<< endl;
  
            cout << "\n 1. View Book Details " << endl;
            cout << "\n 2. Add Details " << endl;
            cout << "\n 3. Update " << endl;

              cin >> choice;

            if (cin.fail()) {
            cout << "\n Invalid input. Please enter a valid numeric value." << endl;
            cin.clear();
            cin.ignore();
            continue;
        }
 
 if (choice == 1){
   viewBookDetails();
 }
      else if (choice == 2){
         addDetails();
       }
          else if(choice == 3){
             updateDetails();
           }
             else if (choice < 0){
                  break;
               }
                  
     }   
  } 

  //-------------------------------------------------------------------------------------------------------------------

 void matrixAddition(int **array, int **array2, int rows, int cols){

       
      int **arr3 = new int*[rows];
                 for (int i=0 ;i<rows; ++i){
                        arr3[i] = new int [cols];
                           }

        for(int i=0; i < rows; i++){
           for(int j=0; j < cols; j++){
             arr3[i][j] = array[i][j] + array2[i][j];
        }
     }
 cout << "\n Addition of Matrices " << endl;    
        for(int i=0; i < rows; i++){
          for(int j=0; j < cols; j++){
             cout << arr3[i][j] << " ";
        }
        cout << endl;
     }

              for (int i=0; i< rows; i++){
                         delete[]arr3[i];
               }   
                         delete[]arr3;  
   }
 

 void  matrixSubtraction(int **array, int **array2, int rows, int cols){

        int **arr3 = new int*[rows];
      for (int i=0 ;i<rows; ++i){
        arr3[i] = new int [cols];
      }
        for(int i=0; i < rows; i++){
          for(int j=0; j < cols; j++){
             arr3[i][j] = array[i][j] - array2[i][j];
        }
     }
 cout << " \n Subtraction of Matrices " << endl;    
        for(int i=0; i < rows; i++){
          for(int j=0; j < cols; j++){
             cout << arr3[i][j] << " ";
        }
        cout << endl;
      }

           for (int i=0; i< rows; i++){
                         delete[]arr3[i];
               }   
                         delete[]arr3;  
   }
   

   void  matrixMultiplication(int **array, int **array2, int rows, int cols){

       int **multiply = new int*[rows];
       for (int i=0 ;i<rows; ++i){
            multiply[i] = new int [cols];
     }

        for (int i=0; i<rows; i++){
          for(int j=0; j<cols; j++){
             int sum =0;
            for (int k=0; k < rows; k++){
                  sum += array[i][k]*array2[k][j];
                  
            }          
            multiply[i][j] = sum;
          }
        }
 cout << "\n Multiplication of matrices " << endl;
    for (int i=0; i<rows; i++){
          for(int j=0; j<cols; j++){
            cout << multiply[i][j] << " ";
      }
      cout << endl;
     }   

     for (int i=0; i<rows; i++){
       delete[]multiply[i];
     }
     delete[]multiply;
   }
  void matrixOperation(){
     
     while (true) {
        int n;
        cout << "\nWhich operation do you want?" << endl;
        cout << "1. Matrix Addition\n";
        cout << "2. Matrix Subtraction\n";
        cout << "3. Matrix Multiplication\n";
        cout << "4. All\n";
        cout << "5. Escape\n";
        cin >> n;

        if (cin.fail()) {
            cout << "\nInvalid input. Please enter a valid numeric value." << endl;
            cin.clear();
            cin.ignore();
            continue; // Restart the loop
        }

        if (n == 5) {
            break;
        }

        int rows, cols;
        cout << "Enter the number of rows: ";
        cin >> rows;

        cout << "Enter the number of columns: ";
        cin >> cols;

        int **arr1 = new int *[rows];
        int **arr2 = new int *[rows];

        for (int i = 0; i < rows; i++) {
            arr1[i] = new int[cols];
            arr2[i] = new int[cols];
        }

        cout << "Enter the elements for Matrix 1:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> arr1[i][j];
            }
        }

        cout << "Enter the elements for Matrix 2:" << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> arr2[i][j];
            }
        }

        switch (n) {
        case 1:
            matrixAddition(arr1, arr2, rows, cols);
            break;
        case 2:
            matrixSubtraction(arr1, arr2, rows, cols);
            break;
        case 3:
            matrixMultiplication(arr1, arr2, rows, cols);
            break;
        case 4:
            matrixAddition(arr1, arr2, rows, cols);
            matrixSubtraction(arr1, arr2, rows, cols);
            matrixMultiplication(arr1, arr2, rows, cols);
            break;
        default:
            cout << "\nInvalid choice. Please enter a valid option." << endl;
        }

        // Deallocate memory for matrices
        for (int i = 0; i < rows; i++) {
            delete[] arr1[i];
            delete[] arr2[i];
        }
        delete[] arr1;
        delete[] arr2;
      }                  
  }

  //---------------------------------------------------------------------------------------------------------------
   
   // Answer 04 
void fileCompression() {
    const int maxWords = 100;
    string storeWords[maxWords];
    int frequency[maxWords] = {0};

    ifstream readtext("NormalFile.txt", ios::in);

    if (!readtext.is_open()) {
        cout << "Error opening the file!" << endl;
        return;
    }

    int totalWords = 0;

    while (readtext >> storeWords[totalWords]) {
        totalWords++;
    }

    for (int k = 0; k < totalWords; k++) {
        if (frequency[k] == 0) {
            int count = 1;
            for (int j = k + 1; j < totalWords; j++) {
                if (storeWords[k] == storeWords[j]) {
                    count++;
                    frequency[j] = 1; 
                }
            }
            if (count > 1) {
                for (int j = 0; j < totalWords; j++) {
                    if (storeWords[k] == storeWords[j]) {
                        storeWords[j] = to_string(count) + " " + storeWords[k];
                    }
                }
            }
        }
    }

    ofstream compressedFile("CompressedFile.txt", ios::out);

    if (!compressedFile.is_open()) {
        cout << "Error creating compressed file!" << endl;
        return;
    }

    for (int i = 0; i < totalWords; i++) {
        if (frequency[i] == 0) {
            compressedFile << storeWords[i] << endl;
        }
    }

    readtext.close();
    compressedFile.close();
}
