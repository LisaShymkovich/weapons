

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
class Weapons
{
public:
    Weapons(string aBrand, int aCreation, string aCountry, int aPrice, int aRange);
    Weapons(const Weapons& other);
    void operator = (const Weapons& other);
    Weapons();
    void setPrice(int aPrice);
    void setBrand(string aBrand);
    void setCountry(string aCountry);
    void SetRange(int aRange);
    void setYearCreation(int aCreation);
    string getBrand() const;
    string getCountry() const;
    int getYearCreation() const;
    int getPrice() const;
    int getRange() const;
    unsigned getID() const;
    virtual void readFromConsole();
    virtual void writeToStream(ostream&);
    
    
private:
    unsigned ID;
    string brand;
    string model;
    string country;
    int yearCreation;
    int yearRelease;
    int price;
    int range;
    void clone(const Weapons& other);
    virtual void dummy() = 0;
    static unsigned nextID;
    friend ostream& operator << (ostream& os, const Weapons& b);
};

