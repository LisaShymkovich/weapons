#include "knife.hpp"
#include <string>

string toString(knifeT d)
{
    return Knife_NAMES_T[(int)d - 1];
}

string toString(MaterialT t)
{
    return Material_NAMES_T[(int)t - 1];
}

string toString(BladeS e)
{
    return Blade_NAMES_SH[(int)e - 1];
}

Knife::Knife() :Weapons()
{
    readElFromConsole();
}

Knife::Knife(string aBrand, int aCreation, string aCountry, int aPrice, int aMileage, knifeT aKnife, MaterialT aMaterial, BladeS aBlade, double alength,  int aWeight) :
    Weapons(aBrand,  aCreation, aCountry, aPrice, aMileage)
{
    setKnifeT(aKnife);
    setMaterialT(aMaterial);
    setBladeS(aBlade);
    setBlade_length(alength);
    setWeight(aWeight);
}

void Knife::setKnifeT(knifeT aKnife)
{
    knife_t = aKnife;
}

void Knife::setMaterialT(MaterialT amaterial)
{
    material_t = amaterial;
}

void Knife::setBladeS(BladeS ablade)
{
    blade_s = ablade;
}

void Knife::setBlade_length(double alength)
{
    if (alength <= 0)
        throw runtime_error("Error: invalid blade length!");
    length = alength;
}

void Knife::setWeight(int aWeight)
{
    if (aWeight < 0)
        throw runtime_error("Error: invalid weight of knife!");
    weight = aWeight;
}


knifeT Knife::getKnifeT() const
{
    return knife_t;
}

MaterialT Knife::getMaterialT() const
{
    return material_t;
}

BladeS Knife::getBladeS() const
{
    return blade_s;
}

double Knife::getBlade_length() const
{
    return length;
}

int Knife::getWeight() const
{
    return weight;
}


void Knife::readFromConsole()
{
    Weapons::readFromConsole();
    readElFromConsole();
}

void Knife::writeToStream(ostream& os)
{
    os << (const Weapons&)*this << " Knife type: " << toString(knife_t) << "\n"
        <<" Matetial: " << toString(material_t) << "\n" <<" Blade shape: "<< toString(blade_s) <<" \n" <<" Blade length: " << length << " sm \n" <<  " Weight : " <<weight<<" g" << "\n\n";

}

void Knife::readElFromConsole()
{
    cin.ignore();
    knifeT inputKnifeT;
    MaterialT inputMaterialT;
    BladeS inputBladeS;
    int t;
    int e;
    int tr;
    int d;
    int w;
    double l;
    
    cout << "Enter weapons range: ";
    cin >> t;
    if (t >= 10 || t <=0)
        throw runtime_error("Invalid knife range!!!");
    SetRange(t);
    cout << "" + MENU_STRING_Knife_T + "";
    while (true) {
        cin >> e;
        if (!((e < 1) || (e > Knife_COUNT_T)))
            break;
        cout << "Error, Try again!\n";
    }
    inputKnifeT = (knifeT)e;
    setKnifeT(inputKnifeT);
    cout << "Enter the blades length(sm): ";
    while (true)
    {
        cin >> l;
        try
        {
            setBlade_length(l);
            break;
        }
        catch (const runtime_error &ex)
        {
            cout << ex.what() << endl;
        }
    }
   
    cout << "" + MENU_STRING_Mat_T + "";
    while (true)
    {
        cin >> tr;
        if (!((tr < 1) || (tr > Material_COUNT_T)))
            break;
        cout << "Error, try again!\n";
    }
    inputMaterialT = (MaterialT)tr;
    setMaterialT(inputMaterialT);
    
    
    cout << "" + MENU_STRING_Blade_SH + "";
    while (true)
    {
        cin >> d;
        if (!((d < 1) || (d > Blade_COUNT_SH)))
            break;
        cout << "Error, try again!\n";
    }
    inputBladeS = (BladeS)d;
    setBladeS(inputBladeS);


    cout << "Enter the weight of a knife (g): ";
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
}
