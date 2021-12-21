#include "gun.hpp"

string toString(Type t)
{
    return TYPE_NAMES[(int)t - 1];
}

Gun::Gun() :Weapons()
{
   
    readElFromConsole();
}

Gun::Gun(string aBrand,int aCreation, string aCountry, int aPrice, int aRange, Type aType,  double aweight, double acaliber, double acapcity, int aspeed):
    Weapons(aBrand, aCreation, aCountry, aPrice, aRange)
{
    setType(aType);
    setWeight(aweight);
    setCaliber(acaliber);
    setMagazine_capacity(acapcity);
    setBullet_speed(aspeed);
}


void Gun::setType(Type aType)
{
    type = aType;
}


void Gun::setWeight(double aweight)
{
    if (aweight <= 0)
        throw runtime_error("Error: invalid weight of gun!");
    weight = aweight;
}

void Gun::setCaliber(double acaliber)
{
    if (acaliber <=0)
        throw runtime_error("Error: invalid caliber!");
    caliber = acaliber;
}

void Gun::setMagazine_capacity(int acapacity)
{
    if (acapacity<=0)
        throw runtime_error("Error: invalid magazine capacity");
    capacity=acapacity;
}

void Gun::setBullet_speed(int aspeed)
{
    if (aspeed <=0)
        throw runtime_error("Error: invalid bullet speed");
    speed=aspeed;
}

Type Gun::getType() const
{
    return type;
}


double Gun::getWeight() const
{
    return weight;
}

double Gun::getCaliber() const
{
    return caliber;
}

int Gun::getMagazine_capacity() const
{
    return capacity;
}

int Gun::getBullet_speed() const
{
    return speed;
}

void Gun::readFromConsole()
{
    Weapons::readFromConsole();
    readElFromConsole();
}

void Gun::writeToStream(ostream& os)
{

    os << (const Weapons&)*this << " Gun Type: " << toString(type) <<"\n" << " Unloaded weight: " << weight
        << "g\n" << " Gun caliber: " <<caliber<<" mm\n" <<" Magazine capacity: " << capacity << " bullets\n" << " Starting speed: " << speed << " m/s\n" <<"\n\n";
}

void Gun::readElFromConsole()
{

    cin.ignore();
    Type inputType;
    int t;
    double w;
    double clbr;
    int cps;
    int sp;
    cout << "Enter weapons range: ";
    cin >> t;
    if (t >= 50 || t<=0)
        throw runtime_error("Invalid gun range!!!");
    SetRange(t);
    cout << "" + MENU_STRING_TYPE + "";
    while (true)
    {
        cin >> t;
        if (!((t < 1) || (t > TYPE_COUNT)))
            break;
        cout << "Error, try again!\n";
    }
    inputType = (Type)t;
    setType(inputType);

    cout << "Enter the weight of gun (g): ";
    while (true)
    {
        cin >> w;
        try
        {
            setWeight(w);
            break;
        }
        catch (const runtime_error &ex)
        {
            cout << ex.what() << endl;
        }
    }

    cout << "Enter the caliber of gun(mm): ";
    while (true)
    {
        cin >> clbr;
        try
        {
            setCaliber(clbr);
            break;
        }
        catch (const runtime_error &ex)
        {
            cout << ex.what() << endl;
        }
    }
    
    cout << "Enter the magazine capacity (amount of bullets): ";
    while (true)
    {
        cin >> cps;
        try
        {
             setMagazine_capacity(cps);
            break;
        }
        catch (const runtime_error &ex)
        {
            cout << ex.what() << endl;
        }
    }
    
    cout << "Enter the starting speed of a bullet (m/s): ";
    while (true)
    {
        cin >> sp;
        try
        {
             setBullet_speed(sp);
            break;
        }
        catch (const runtime_error &ex)
        {
            cout << ex.what() << endl;
        }
    }
}

