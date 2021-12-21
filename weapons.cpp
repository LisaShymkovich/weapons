#include "weapons.hpp"

unsigned Weapons::nextID = 0;

Weapons::Weapons(string aBrand, int aCreation, string aCountry, int aRange, int aPrice) : ID(nextID++)
{
    setBrand(aBrand);
    setYearCreation(aCreation);
    setCountry(aCountry);
    SetRange(aRange);
    setPrice(aPrice);
}

void Weapons::setBrand(string aBrand)
{
    brand = aBrand;
}

void Weapons::setYearCreation(int aCreation)
{
    if (aCreation > 2021 || aCreation <= 0)
        throw runtime_error("Invalid creation year! Try again!");
    yearCreation = aCreation;
}


void Weapons::setCountry(string acountry)
{
    country = acountry;
}

void Weapons::SetRange(int aRange)
{
    range = aRange;
}

void Weapons::setPrice(int aPrice)
{
    if (aPrice < 0)
        throw runtime_error("Invalid price! Try again!");

    price = aPrice;
}


string Weapons::getBrand() const
{
    return brand;
}


int Weapons::getYearCreation() const
{

    return yearCreation;
}


string Weapons::getCountry() const
{
    return country;
}


int Weapons::getPrice() const
{
    return price;
}

int Weapons::getRange() const
{
    return range;
}

unsigned Weapons::getID() const
{
    return ID;
}

Weapons::Weapons(const Weapons& other) : ID(nextID++)
{
    clone(other);
}

void Weapons::operator=(const Weapons& other)
{
    clone(other);
}

Weapons::Weapons() : ID(nextID++)
{
    readFromConsole();
}


void Weapons::readFromConsole()
{
    int t;
    string s;
    cout << "Enter the brand of weapon: ";
    getline(cin, s);
    setBrand(s);
    cout << "Enter the year of brand creation: ";
    while (true)
    {
        cin >> t;
        try
        {
            setYearCreation(t);
            break;
        }
        catch (const runtime_error &ex)
        {
            cout << ex.what() << endl;
        }

    }
    cin.ignore();
    
    cout << "Enter the producuing country: ";
    getline(cin, s);
    setCountry(s);
    
    cout << "Enter the price (USD): ";
    while (true)
    {
        cin >> t;
        try
        {
            setPrice(t);
            break;
        }
        catch (const runtime_error &ex)
        {
            cout << ex.what() << endl;
        }
    }
}

void Weapons::writeToStream(ostream& os)
{
    os << " Weapon ID: " << ID <<"\n"<< " Brand: " << brand << "\n"  <<
        " Creation year: " << yearCreation <<"\n"<< " Country: "<< country << "\n" <<  " Range: " << range <<"\n"<< " Price: " << price <<"\n"<< "\n";
}

void Weapons::clone(const Weapons& other)
{
    brand = other.brand;
    yearCreation = other.yearCreation;
    country = other.country;
    range = other.range;
    price = other.price;
}

ostream& operator<<(ostream& os, const Weapons& c)
{
    os << " Weapon ID: " << c.ID <<"\n"<< " Brand: " << c.brand <<"\n"<< " Creation year: " << c.yearCreation <<"\n"<< " Country: "<< c.country << "\n" <<" Range: " <<
        c.range <<" m\n" << " Price: " << c.price <<"$"<< "\n" << "\n";
    return os;
}

