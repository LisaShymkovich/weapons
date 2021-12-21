
#include "crossbow.hpp"
string toString(TypeE t)
{
    return TYPE_NAMES_E[(int)t - 1];
}

string toString(MAT d)
{
    return DRIVE_NAMES_E[(int)d - 1];
}



Crossbow::Crossbow() : Weapons()
{
    readElFromConsole();
}

Crossbow::Crossbow(string aBrand, int aCreation, string aCountry, int aPrice, int aMileage, MAT aDrive,
                   TypeE aType, int astroke, int aforce, int aspeed) :
Weapons(aBrand, aCreation, aCountry, aPrice, aMileage)
{
    setTypeE(aType);
    setDriveE(aDrive);
    setBowstring_stroke(astroke);
    setPulling_Force(aforce);
    setBow_speed(aspeed);
}

void Crossbow::setTypeE(TypeE aType)
{
    type_e = aType;
}

void Crossbow::setDriveE(MAT aDrive)
{
    drive_e = aDrive;
}

void Crossbow::setBowstring_stroke(int astroke)
{
    if (astroke <= 0)
        throw runtime_error("Error: invalid bowstring stroke!");
    bowstring_stroke = astroke;
}

void Crossbow::setPulling_Force(int aforce)
{
    if (aforce <=0)
        throw runtime_error("Error: invalid pulling force!");
    force=aforce;
}

TypeE Crossbow::getTypeE() const
{
    return type_e;
}

MAT Crossbow::getDriveE() const
{
    return drive_e;
}

int Crossbow::getBowstring_stroke() const
{
    return bowstring_stroke;
}

int Crossbow::getPulling_Force() const
{
    return force;
}


void Crossbow::setBow_speed(int aspeed)
{
    if (aspeed <= 0)
        throw runtime_error("Error: invalid speed!");
    speed = aspeed;
}

void Crossbow::readFromConsole()
{
    Weapons::readFromConsole();
    readElFromConsole();
}

void Crossbow::writeToStream(ostream& os)
{
    os << (const Weapons&)*this << " Body Type: " << toString(type_e) << "\n" << " Drive type: " << toString(drive_e) << "\n" << " Bowstring stroke: " << bowstring_stroke << " sm\n " << "Pulling Force: "<< force << "kg\n" << " Bow starting speed: " << speed << " m/s " "\n\n";
}

void Crossbow::readElFromConsole()
{
    cin.ignore();
    TypeE inputTypeE;
    MAT inputDriveE;
    int t;
    int d;
    int bs;
    int pf;
    int sp;
    cout << "Enter the weapons range: ";
    cin >> t;
    if (t >= 300 || t<=0)
        throw runtime_error("Invalid crossbow range!!!");
    SetRange(t);
    cout << "" + MENU_STRING_TYPE_ET + "";
    while (true)
    {
        cin >> t;
        if (!((t < 1) || (t > TYPE_COUNT_E)))
            break;
        cout << "Error, try again!\n";
    }
    inputTypeE = (TypeE)t;
    setTypeE(inputTypeE);
    
    
    cout << "" + MENU_STRING_DRIVE_E + "";
    while (true)
    {
        cin >> d;
        if (!((d < 1) || (d > DRIVE_COUNT_E)))
            break;
        cout << "Error, try again!\n";
    }
    inputDriveE = (MAT)d;
    setDriveE(inputDriveE);
    
    
    cout << "Enter the bowstring stroke (sm): ";
    while (true)
    {
        cin >> bs;
        try
        {
            setBowstring_stroke(bs);
            break;
        }
        catch (const runtime_error &ex)
        {
            cout << ex.what() << endl;
        }
    }
    
    cout << "Enter the pulling force(kg): ";
    while (true)
    {
        cin >> pf;
        try
        {
            setPulling_Force(pf);
            break;
        }
        catch (const runtime_error &ex)
        {
            cout << ex.what() << endl;
        }
    }
    
    
    cout << "Enter the starting speed of an arrow: ";
    while (true)
    {
        cin >> sp;
        try
        {
            setBow_speed(sp);
            break;
        }
        catch (const runtime_error &ex)
        {
            cout << ex.what() << endl;
        }
    }
}
