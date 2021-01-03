#include "contact_list.h"
#include <iostream>
#include <map>


struct ContactsInGroup {
    std::vector<Contact> contacts_in_group_;
    std::string group_;

    ContactsInGroup(std::string group) : group_(group) {
    }

    void operator()(const Contact &contact) {
        if(contact.GetGroup() == group_) {
            contacts_in_group_.push_back(contact);
        }
    }
};

struct ContactsInCompany {
    std::vector<Contact> contacts_in_company_;
    std::string company_;

    ContactsInCompany(std::string company) : company_(company) {
    }

    void operator()(const Contact &contact) {
        if(contact.GetCompany() == company_) {
            contacts_in_company_.push_back(contact);
        }
    }
};


ContactList::ContactList() {

}

ContactList::ContactList(const ContactList &cl) {
    contact_list_ = cl.GetContactList();
}

ContactList::~ContactList() {

}

void ContactList::AddContact(Contact contact) {
    contact_list_.push_back(contact);
}

void ContactList::DeleteContact(Contact contact) {
    // because we're using a vector we need to search all contacts, then return index, then delete by index
    int size = contact_list_.size();
    int i;
    for(i = 0; i < size; ++i) {
        if(contact_list_[i] == contact) {
            break;
        }
    }
    contact_list_.erase(contact_list_.begin()+i);
}

void ContactList::DisplayContacts(std::string sort_by) {
    std::vector<Contact> sorted{contact_list_};
    if(sort_by == "last_name") {
        std::sort(sorted.begin(), sorted.end(), [](const auto &c1, const auto &c2) {
            return c1.GetLastName() < c2.GetLastName();
        });
    }
    else if(sort_by == "first_name"){
        std::sort(sorted.begin(), sorted.end(), [](const auto &c1, const auto &c2) {
            return c1.GetFirstName() < c2.GetFirstName();
        });
    }
    else{
        std::cout<<"Invalid sort by parameter in ContactList::DisplayAllContacts"<<std::endl;
        return;
    }
    for (auto x : sorted){
        x.DisplayNameNum();
    }
}

void ContactList::DisplayContactsInCompany(std::string company) {
    auto found_contacts = std::for_each(contact_list_.begin(), contact_list_.end(), ContactsInCompany(company));
    for (auto const &x : found_contacts.contacts_in_company_) {
        std::cout<<x<<std::endl;
    }
}

void ContactList::DisplayContactsInGroup(std::string group) {
    auto found_contacts = std::for_each(contact_list_.begin(), contact_list_.end(), ContactsInGroup(group));
    for (auto const &x : found_contacts.contacts_in_group_) {
        std::cout<<x<<std::endl;
    }
}

std::vector<Contact> ContactList::FindByFirstName(std::string first_name) {
    // let's just not use any algorithms with this one:
    std::vector<Contact> found;
    for(const auto &x : contact_list_) {
        if(x.GetFirstName() == first_name) {
            found.push_back(x);
        }
    }
    return found;
}

std::vector<Contact> ContactList::FindByLastName(std::string last_name) {
    // let's just not use any algorithms with this one:
    std::vector<Contact> found;
    for(const auto &x : contact_list_) {
        if(x.GetLastName() == last_name) {
            found.push_back(x);
        }
    }
    return found;
}

std::vector<Contact> ContactList::GetContactList()const {
    return contact_list_;
}

void ContactList::DisplayCountByGroups() {
    std::set<std::string> groups = GetGroupSet();

    // create multiset with group names from all contacts
    std::multiset<std::string> group_count_ms = GetGroupMultiSet();

    // get the map
    std::map<std::string, int> group_count = GetGroupMap(groups, group_count_ms);

    std::for_each(group_count.begin(), group_count.end(), [](const auto &x) {
        std::cout<<x.first<<" : "<<x.second<<std::endl;
    });

}

std::multiset<std::string> ContactList::GetGroupMultiSet() {
    std::multiset<std::string> group_count_ms;
    for(const auto &x : contact_list_) {
        group_count_ms.insert(x.GetGroup());
    }

    return group_count_ms;
}

std::map<std::string, int> ContactList::GetGroupMap(std::set<std::string> groups, std::multiset<std::string> group_count_ms) {
    std::map<std::string, int> group_count;
    // initialize the map
    for(const auto &g : groups){
        group_count.insert(std::pair<std::string, int>(g, 0));
    }

    // add counts to the map
    for(auto x : groups) {
        group_count[x] = group_count_ms.count(x);
    }

    return group_count;
}

std::set<std::string> ContactList::GetGroupSet() {
    std::set<std::string> groups;
    for(const auto &x : contact_list_) {
        groups.insert(x.GetGroup());
    }

    return groups;
}


void ContactList::DisplayCountByCompanies() {
    std::set<std::string> groups = GetCompanySet();

    // create multiset with group names from all contacts
    std::multiset<std::string> group_count_ms = GetCompanyMultiSet();

    // get the map
    std::map<std::string, int> group_count = GetGroupMap(groups, group_count_ms);

    std::for_each(group_count.begin(), group_count.end(), [](const auto &x) {
        std::cout<<x.first<<" : "<<x.second<<std::endl;
    });

}

std::set<std::string> ContactList::GetCompanySet() {
    std::set<std::string> groups;
    for(const auto &x : contact_list_) {
        groups.insert(x.GetCompany());
    }

    return groups;
}

std::multiset<std::string> ContactList::GetCompanyMultiSet() {
    std::multiset<std::string> group_count_ms;
    for(const auto &x : contact_list_) {
        group_count_ms.insert(x.GetCompany());
    }

    return group_count_ms;
}

std::ostream& operator <<(std::ostream& out, const ContactList &obj) {
    auto contacts = obj.GetContactList();
    for(const auto x : contacts) {
        std::cout<< x <<std::endl;
    }

    return out;
}
