#include "Parent.h"
#include "GetData.h"
#include <vector>
using namespace std;
#include <fstream>

Parent::Parent() {
  
}

void Parent::setAttributes() {
  do { //gets parent/guardian name
    cout << "\nEnter the name of the parent/guardian: ";
    getline(cin, name);
  } while (name == "");
  cout 
    << "\n1. Cell\n" 
    << "2. Email\n" 
    << "3. SMS" << endl;
  do {
    cout << "What would you like to do? ";
  } while ((!(getValidInt(contact)) || (contact > 3) || (contact <= 0)));

  do { //gets primary and secondary phone number
    cout << "\nEnter your primary phone number: ";
    getline(cin, primary);
  } while (primary == "" || (!(isPhoneNum(primary))) );
  if (primary == "201-602-0580") { //Extra Thing: prints if the user enters my phone number
    cout << "Hey wait that's my phone number...";
  }
  cout << "\nEnter your secondary phone number (if applicable): ";
  getline(cin, secondary);
  if (secondary == "201-602-0580") { //Extra Thing: if my phone is entered, this message prints
    cout << "Hey wait that's my phone number...";
  }
  if (contact == 2) { //gets email
    do {
      cout << "\nEnter your email: ";
      getline(cin, email);
    } while (email == "");
  } else {
    cout << "\nEnter your email (if applicable): ";
    getline(cin, email);
  }

  do { //gets address
    cout << "\nEnter your home address: ";
    getline(cin, address);
  } while (address == "");

  cout //gets employment status
    << "\n1. Employed\n"
    << "2. Unemployed\n" << endl;
  do {
    cout << "Please select an option: ";
  } while ((!(getValidInt(employed)) || (employed > 2) || (employed <= 0)));

  if (employed == 1) { //gets place of employment
    do {
      cout << "\nEnter your place of employment: ";
      getline(cin, employment); 
    } while (employment == "");
  }

  do { //gets adults authorized to pick up the child (includes )
    cout << "\nEnter number of adults authorized to pick up child: ";
  } while ((!(getValidInt(adult)) || (adult <= 0)));

  for (int i = 1; i <= adult; i++) {
    do {
      cout << "\nEnter Adult #" << i << ": ";
      getline(cin, adName);
    } while (adName == "");
    pickup.push_back(adName);

    do {
      cout << "\nEnter Adult #" << i << "'s Connection: ";
      getline(cin, connect);
    } while (connect == "");
    connection.push_back(connect);

    do {
      cout << "\nEnter Adult #" << i << "'s Phone Number: ";
      getline(cin, pnums);
    } while ((pnums == "") || (!(isPhoneNum(pnums))) ) ;
    phones.push_back(pnums);
  }

  cout << "\nEnter your parent's insurance plan: ";
  getline(cin, insurance);
}


bool Parent::isPhoneNum(string str) { //checks if phone num uses characters in an actual phone number
  string num = "0123456789-";
  for(int k = 0; k < str.length(); k++) {
    bool test = false;
  for(int i = 0; i < 11; i++ ) {
    if(str[k] == num[i]) {
      test = true;
    }
    else if (i == 10 && test == false) {
      return false;
    }
    }
  }
  return true;
}

void Parent::addToFileParent() {//code
  ofstream out = ofstream("ParentInfo.txt", ios::app);
  
  if (name != "")  {
  out << "Parent/Guardian: " << name << endl;
    if (contact == 1) { //saves preferred contact method to file
      out << "Preferred Contact Method: Cell\n";
    } else if (contact == 2) {
      out << "Preferred Contact Method: Email\n";
    } else {
      out << "Preferred Contact Method: SMS\n";
    }
  out << "Primary Phone: " << primary << endl;
  out << "Secondary Phone: " << secondary << endl;
  out << "Email: " << email << endl;
  out << "Address: " << address << endl;
  out << "Employment: " << employment << endl;
  for (int i = 0; i < adult; i++) {
    out << "Adult #" << i + 1 << " Name: " << pickup[i] << endl;
    out << "Adult #" << i + 1 << " Connection: " << connection[i] << endl;
    out << "Adult #" << i + 1 << " Number: " << phones[i] << endl;
    out << endl;
  }
  }
}
