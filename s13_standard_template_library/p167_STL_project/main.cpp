/*
STL Project
Create a contacts application that allows users to store contact information:

First Name
Last Name
Primary phone number
Secondary phone number
Email id
Address
Company
Group (Friends, Family, Coworker, Acquaintance)
Provide the following features:

x Display all contacts sorted by first or last name (provide an option that users can choose)
x Display only first name with primary number
x Display contacts from the same company only
x Display contacts based on group type
x Allow contact search by first or last name
x Display count of contacts by company and group.
Decide carefully about the usage of containers and algorithms.

*/

#include <iostream>
#include "contact_list.h"
#include "contact.h"

ContactList CreateTestContacts() {
    Contact beth{"Beth", "Johnson","612-555-5555","-","beth@gmail.com","123 1st street","Fleet Farm", "Friends"};
    Contact dan{"Dan","Carlson","612-554-5555","-","-","-","Fleet Farm", "Family"};
    Contact gregg{"Gregg","Doe","612-553-5555","2","2","2","Bosch","Coworkers"};
    Contact sara{"Sara", "", "612-111-5555"};
    Contact aaron{"Aaron", "a-aron","612 238 1111","","","","Mobile", "Acquiantance"};
    Contact beth2{"Beth", "McMahon", "612-319-5555"};
    Contact john{"John"};
    Contact dave{"Dave","Byrd","612 832 5555","","","","","Friends"};

    ContactList cl;
    cl.AddContact(beth);
    cl.AddContact(dan);
    cl.AddContact(gregg);
    cl.AddContact(sara);
    cl.AddContact(aaron);
    cl.AddContact(beth2);
    cl.AddContact(john);
    cl.AddContact(dave);
    
    std::cout<<"Printing contact list: "<<std::endl;
    std::cout<<cl<<std::endl;
    std::cout<<"-----------------"<<std::endl;

    cl.DeleteContact(john);
    std::cout<<"Contact list after deleting john: "<<std::endl;
    std::cout<<cl<<std::endl;

    return cl;
}

int main() {

    ContactList cl = CreateTestContacts();
    
    std::cout<<"\nDisplay contacts sorted by last name:"<<std::endl;
    cl.DisplayContacts();
    std::cout<<"\nDisplay contacts sorted by first name:"<<std::endl;
    cl.DisplayContacts("first_name");

    std::cout<<"\nDisplay contacts only within company Fleet Farm:"<<std::endl;
    cl.DisplayContactsInCompany("Fleet Farm");

    std::cout<<"\nDisplay contacts in group Friends: "<<std::endl;
    cl.DisplayContactsInGroup("Friends");

    std::cout<<"\nFinding contacts by first name: Beth"<<std::endl;
    auto found = cl.FindByFirstName("Beth");
    for(const auto &x : found) {
        std::cout<<x<<std::endl;
    }
    
    std::cout<<"\nFinding contacts by last name: Johnson"<<std::endl;
    found = cl.FindByLastName("Johnson");
    for(const auto &x : found) {
        std::cout<<x<<std::endl;
    }

    std::cout<<"\nDisplaying count for contacts in each group"<<std::endl;
    cl.DisplayCountByGroups();

    std::cout<<"\nDisplaying count for contacts in each company"<<std::endl;
    cl.DisplayCountByCompanies();

    return 0;
}