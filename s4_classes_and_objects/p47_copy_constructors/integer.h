#pragma once

class Integer {
    int *m_pInt;

public:
    Integer();
    Integer(int value);
    //NOTE: if we don't pass this by reference it will just keep callint itself
    Integer(const Integer &obj);
    ~Integer();
    int GetValue()const;
    void SetValue(int value);

};