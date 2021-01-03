#include "contact.h"
#include <iostream>

Contact::Contact() {

}

Contact::Contact(std::string first_name, 
        std::string last_name,
        std::string primary_number,
        std::string secondary_number,
        std::string email,
        std::string address,
        std::string company,
        std::string group) :
        first_name_(first_name),
        last_name_(last_name),
        primary_number_(primary_number),
        secondary_number_(secondary_number),
        email_(email),
        address_(address),
        company_(company),
        group_(group) {

            auto found  = available_groups_.find(group_);
            if(found == available_groups_.end()){
                throw std::out_of_range("Group is not in list of available groups.");
            }

        }

/*
Contact::Contact(const Contact &obj) {
    first_name_ = obj.GetFirstName();
    last_name_ = obj.GetLastName();
    primary_number_ = obj.GetPrimaryNum();
    secondary_number_ = obj.GetSecondaryNum();
    email_ = obj.GetEmail();
    company_ = obj.GetCompany();
    address_ = obj.GetAddress();
    group_ = obj.GetGroup();
}
*/

Contact::~Contact() {

}

const std::string &Contact::GetFirstName() const {
    return first_name_;
}

const std::string &Contact::GetLastName() const{
    return last_name_;
}

const std::string &Contact::GetPrimaryNum() const{
    return primary_number_;
}

const std::string &Contact::GetSecondaryNum() const{
    return secondary_number_;
}

const std::string &Contact::GetEmail() const{
    return email_;
}

const std::string &Contact::GetAddress() const{
    return address_;
}

const std::string &Contact::GetCompany() const{
    return company_;
}

const std::string &Contact::GetGroup() const{
    return group_;
}

void Contact::DisplayNameNum() const{
    std::cout<<"Name: "<<first_name_<<" "<<last_name_<<std::endl;
    std::cout<<"Primary Number: "<<primary_number_<<std::endl;
}

bool Contact::operator ==(const Contact &obj) const{
    bool ret{1};
    if(obj.GetFirstName() != first_name_) {
        ret = 0;
    }
    else if(obj.GetLastName() != last_name_) {
        ret = 0;
    }
    else if(obj.GetPrimaryNum() != primary_number_) {
        ret = 0;
    }
    else if(obj.GetSecondaryNum() != secondary_number_) {
        ret = 0;
    }
    else if(obj.GetEmail() != email_) {
        ret = 0;
    }
    else if(obj.GetAddress() != address_) {
        ret = 0;
    }
    else if(obj.GetCompany() != company_) {
        ret = 0;
    }
    else if(obj.GetGroup() != group_) {
        ret = 0;
    }

    return ret;
}

std::ostream& operator <<(std::ostream& out, const Contact &obj) {
    out<<"\ncontact.first_name = "<<obj.GetFirstName();
    out<<"\ncontact.last_name = "<<obj.GetLastName();
    out<<"\ncontact.primary_number = "<<obj.GetPrimaryNum();
    out<<"\ncontact.secondary_number = "<<obj.GetSecondaryNum();
    out<<"\ncontact.email = "<<obj.GetEmail();
    out<<"\ncontact.address = "<<obj.GetAddress();
    out<<"\ncontact.company = "<<obj.GetCompany();
    out<<"\ncontact.group = "<<obj.GetGroup();

    return out;
}