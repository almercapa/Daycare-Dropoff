#include "Child.h"
#include "GetData.h"
#include <fstream>

Child::Child() {

}

void Child::getChildAttributes() { //This method asks for all child info
  do { //gets name
    cout << "Enter the name of the child: ";
    getline(cin, name);
  } while ((name == "") );

  do { //gets number of allergies
    cout << "\nEnter number of allergies for child: ";
  } while ((!(getValidInt(alnum))));

  if (alnum > 0) {
  for (int i = 1; i <= alnum; i++) { //asks for each allergy and adds to vector
    do {
      cout << "\nEnter Allergy #" << i << ": ";
      getline(cin, allergy);
    } while (allergy == "");
    allergens.push_back(allergy);

    //severity, light, moderate, severe, exetreme
    //do in a four thing menu 
    do {
      cout << "\nEnter Allergy #" << i << "'s Severity (Light, Moderate, Severe, Extreme): "; //adds each allergy severity to vector
      getline(cin, severe);
    } while (severe == "" || (!(severe == "Light") && !(severe == "Moderate") && !(severe == "Severe") && !(severe == "Extreme")));
    severity.push_back(severe);
  }
  }

  cout << "\nEnter feeding accomodations: "; //gets feeding and napping accomodations
  getline(cin, feedingInstruct);
  
  cout << "\nEnter napping accomodations: ";
  getline(cin, nappingInstruct);
}


void Child::addToFile() { //adds all info to file
  ofstream out = ofstream("ChildrenRegistry.txt", ios::app);

  if (name != "") {
  out << "Child's Name: " << name << endl;
  if (alnum > 0) {
    for (int i = 0; i < alnum; i++) {
      out << "Allergy #" << i + 1 << ": " << allergens[i] << endl;
      out << "Allergy #" << i + 1 << " Severity: " << severity[i] << endl;
    }
  }
  out << "Napping Instructions: " << nappingInstruct << endl;
  out << "Feeding Instructions: " << feedingInstruct << endl;
  out << endl;
  }
}
