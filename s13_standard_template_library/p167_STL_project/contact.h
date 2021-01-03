#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <set>

class Contact {
public:
    Contact();
    Contact(std::string first_name, 
        std::string last_name="-",
        std::string primary_number="-",
        std::string secondary_number="-",
        std::string email="-",
        std::string address="-",
        std::string company="-",
        std::string group="-");
    //Contact(const Contact &obj);
    //Contact(Contact &&obj);
    ~Contact();

    void UpdateFirstName(std::string first_name);
    void UpdateLastName(std::string last_name);
    void UpdatePrimaryNum(std::string num);
    void UpdateSecondaryNum(std::string num);
    void UpdateEmail(std::string email);
    void UpdateAddress(std::string address);
    void UpdateCompany(std::string company);
    void updateGroup(std::string group);

    const std::string &GetFirstName()const;
    const std::string &GetLastName()const;
    const std::string &GetPrimaryNum()const;
    const std::string &GetSecondaryNum()const;
    const std::string &GetEmail()const;
    const std::string &GetAddress()const;
    const std::string &GetCompany()const;
    const std::string &GetGroup()const;

    void DisplayNameNum()const;

    bool operator ==(const Contact &obj)const;

private:
    std::string first_name_;
    std::string last_name_;
    std::string primary_number_;
    std::string secondary_number_;
    std::string email_;
    std::string address_;
    std::string company_;
    std::string group_;

    std::set<std::string> available_groups_{"-","Friends", "Family", "Coworkers", "Acquiantance"};
};


std::ostream& operator <<(std::ostream& out, const Contact &obj);


struct ContactCompare {
    bool operator()(const Contact &e1, const Contact &e2) const{
        return e1.GetLastName() < e2.GetLastName();
    }
};


#endif