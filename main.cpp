#include<iostream>
#include "functions.h"
#include <fstream>
#include <string>
using namespace std;

int main(){

  int choice;
       cout << " Enter which Question to run : ";
       cin >> choice;

      switch(choice){
        case 1 : 
               cout << " Running Question 1 ..." << endl;
               MergeFiles();
               break;
        case 2 : 
               cout << " Running Question 2 ..." << endl;
               bookInventory();
               break;
        case 3 : 
               cout << " Running Question 3 ..." << endl;
               matrixOperation();
               break;
        case 4 : 
               cout << " Running Question 4 ..." << endl;
               fileCompression();
               break;
       default : 
               cout << " Invalid Input ! " << endl;          

      }


    return 0;
}
