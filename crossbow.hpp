
#include <stdio.h>
#include <string>
#include "weapons.hpp"
using namespace std;
constexpr auto START_LINE_M = __LINE__;
enum class MAT
{
    
    Aluminum = 1,
    Wood,
    Plastic
};
constexpr auto DRIVE_COUNT_E = __LINE__ - START_LINE_M - 3;
const string DRIVE_NAMES_E[] = { "Aluminum", "Wood", "Plastic" };
const string MENU_STRING_DRIVE_E = "Выберите материал приклада арбалета (1 - Aluminum, 2 - Wood, 3 - Plastic): ";

constexpr auto START_LINE_ET = __LINE__;
enum class TypeE
{
    Block = 1,
    Recurve
};
constexpr auto TYPE_COUNT_E = __LINE__ - START_LINE_ET - 3;
const string TYPE_NAMES_E[] = { "Block", "Recurve" };
const string MENU_STRING_TYPE_ET = "Выберите тип арбалета (1- Block, 2 - Recurve ): ";

class Crossbow : public Weapons
{
public:
    Crossbow();
    Crossbow(string aBrand,  int aCreation, string aCountry, int aPrice, int aMileage, MAT aDrive, TypeE aType, int aStroke, int aforce,  int aBattery_capacity);
    void setTypeE(TypeE aType);
    void setDriveE(MAT aDrive);
    void setBowstring_stroke(int astroke);
    void setPulling_Force(int aforce);
    void setBow_speed(int aspeed);
    TypeE getTypeE() const;
    MAT getDriveE() const;
    int getBowstring_stroke() const;
    int getPulling_Force() const;
    int getBow_speed() const;
    void readFromConsole() override;
    void writeToStream(ostream&) override;
private:
    MAT drive_e;
    TypeE type_e;
    int bowstring_stroke;
    int speed;
    int force;
    void readElFromConsole();
    void dummy() override{};
};

