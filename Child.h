#ifndef CHILD_H
#define CHILD_H

#include "Parent.h"
using namespace std;
#include <iostream>
#include <fstream>

//How do we setup inheritance?
class Child : public Parent {
  public:
    Child();
    ~Child(){};
    void getChildAttributes();
    //void printChildAttributes();
    void addToFile();

  private:
    string name, allergy = "", severe = "", feedingInstruct, nappingInstruct;
    int alnum, weight;
    vector <string> allergens;
    vector <string> severity;
  //All variables go here
};
#endif
