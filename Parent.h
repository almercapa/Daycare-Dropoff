using namespace std;
#include <iostream>
#include <vector>
#ifndef PARENT_H
#define PARENT_H


class Parent{
  public:
    Parent();
    ~Parent(){};
    void setAttributes();
    //void printAttributes();
    void addToFileParent();
    bool isPhoneNum(string str);


  protected:
    string name = "", primary = "", secondary, email = "", text, address = "", employment = "", workContact, workContactPhone, healthInsurance, adName = "", connect = "", pnums = "", insurance;
    int authorized, contact, employed, adult;
    string contacts[10];
    vector <string> pickup;
    vector <string> connection;
    vector <string> phones;

    
  //All variables go here
};


#endif
