#include <stdio.h>
#include "weapons.hpp"

constexpr auto START_LINE_TP = __LINE__;
enum class Type
{
    Carbines = 1,
    Machineguns,
    Pistols,
    Personal_defense_weapons,
    Shotguns
};

constexpr auto TYPE_COUNT = __LINE__ - START_LINE_TP - 3;
const string TYPE_NAMES[] = { "Carbines", "Machineguns", "Pistols", "Personal_defense_weapons", "Shotguns"};
const string MENU_STRING_TYPE = "Выберите тип пистолета (1- Carbines, 2 - Machineguns, 3 - Pistols, 4 - Personal_defense_weapons, 5 - Shotguns ): ";


class Gun : public Weapons
{
public:
    Gun();
    Gun(string aBrand, int aCreation, string aCountry,  int aPrice, int aRange, Type aType,  double acapacity, double aweight, double acaliber, int aspeed);
    void setType(Type aType);

    void setWeight(double aweight);
    void setCaliber(double acaliber);
    void setMagazine_capacity(int acapacity);
    void setBullet_speed(int aspeed);
    Type getType() const;

    double getWeight() const;
    double getCaliber() const;
    int getMagazine_capacity() const;
    int getBullet_speed() const;
    void readFromConsole() override;
    void writeToStream(ostream&) override;
    
private:
    Type type;
    double capacity;
    double weight;
    double caliber;
    int speed;
    void readElFromConsole();
    void dummy () override {};
};
