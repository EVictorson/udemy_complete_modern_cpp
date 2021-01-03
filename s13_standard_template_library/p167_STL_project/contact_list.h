#ifndef CONTACT_LIST_H
#define CONTACT_LIST_H

#include "contact.h"
#include <set>
#include <vector>
#include <algorithm>
#include <map>

class ContactList {
public:
    ContactList();
    ContactList(const ContactList &cl);
    ~ContactList();

    void AddContact(Contact contact);
    void DeleteContact(Contact contact);

    void DisplayContacts(std::string sort_by="last_name");
    void DisplayContactsInCompany(std::string company);
    void DisplayContactsInGroup(std::string group);

    std::vector<Contact> FindByFirstName(std::string first_name);
    std::vector<Contact> FindByLastName(std::string last_name);

    void DisplayCountByGroups();
    void DisplayCountByCompanies();


    std::vector<Contact> GetContactList()const;
    //std::set<Contact, ContactCompare> contact_set;

private:
    std::vector<Contact> contact_list_;

    std::set<std::string> GetGroupSet();
    std::multiset<std::string> GetGroupMultiSet();
    std::map<std::string, int> GetGroupMap(std::set<std::string> groups, std::multiset<std::string> group_count_ms);
    std::set<std::string> GetCompanySet();
    std::multiset<std::string> GetCompanyMultiSet();

    template<typename func>
    std::set<std::string> GetSet(func f);



};

std::ostream& operator <<(std::ostream& out, const ContactList &obj);


#endif