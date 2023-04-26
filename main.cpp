#include "Child.h"
#include "GetData.h" //for input validation
#include "Parent.h"
#include <fstream>
#include <iomanip>
#include <iostream>

/***************************************************
    Recall the directions on the directions on the
      Document.

      In main(), there should be only 5 options present

        1.) Register Emergency Contact Information
        2.) Register Child
        3.) Print all children registered
        4.) Print all emergency contact information
              for each child.
        5.) Quit

 *NOTE : Like in Real-life, every time an adult
          registers a new child, they have to re-do
          this process and enter the same emergency
          contact information

***************************************************/

using namespace std;
int main() {

  //clears file from previous program
  ofstream out = ofstream("ChildrenRegistry.txt", ios::trunc);
  ofstream out2 = ofstream("ParentInfo.txt", ios::trunc);
  
  out << "";
  out2 << "";
  
  out.close();
  out2.close();
  
  string input; // used for user input
  
  cout << "\nWelcome to Montville's Daycare for Devils!" << endl;
  int run = 0;
  
  while (run != 5) { //Creates menu
    cout << "\n1. Register Child + Emergency Contact Information" << endl;
    cout << "2. Print all children registered" << endl;
    cout << "3. Print all emergency contact information for each child."
         << endl;
    cout << "4. Quit" << endl;
    do {
      cout << "What would you like to do?" << endl; //User picks (error trapped)
    } while ((!(getValidInt(run)) || (run > 4) || (run <= 0)));

    if (run == 1) { // Emergency Contact Info
      Child *child = new Child();
      child -> setAttributes(); //sets emergency contact info
      cout << endl;
      child -> getChildAttributes(); //sets child attributes
      child -> addToFile(); //adds contact info to file
      child -> addToFileParent(); //adds child attributes to seperate file
      
    } else if (run == 2) { // Print all children
      ifstream in = ifstream("ChildrenRegistry.txt");
      string data;

      while (getline(in,data)) {
        cout << data << "\n"; //prints all data in child file
      }
      
    } else if (run == 3) { // Print all emergency contact info
      ifstream in = ifstream("ParentInfo.txt");
      string data;
      
      while (getline(in,data)) {
        cout << data << "\n"; //prints all data in contact info file
      }
      
    } else { //Quits Program
      break;
    }
  }
}
