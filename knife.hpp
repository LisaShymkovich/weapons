#include <stdio.h>
#include "weapons.hpp"
constexpr auto START_LINE_HCK = __LINE__;
enum class knifeT
{
    Trench = 1,
    Bayonets,
    Karambit,
    Machetes
};
constexpr auto Knife_COUNT_T = __LINE__ - START_LINE_HCK - 3;
const string Knife_NAMES_T[] = { "Trench", "Bayonets", "Karambit", "Machetes" };
const string MENU_STRING_Knife_T = "Выберите тип ножа(1 - Trench, 2 - Bayonets, 3-Karambit, 4- Machetes): ";


constexpr auto START_LINE_HCM = __LINE__;
enum class MaterialT
{
    Steel = 1,
    Titanium,
    Ceramics
};

constexpr auto Material_COUNT_T = __LINE__ - START_LINE_HCM - 3;
const string Material_NAMES_T[] = { "Steel", "Titanium", "Ceramics" };
const string MENU_STRING_Mat_T = "Выберите материал из которого изготовлен клинок(1 - Steel, 2 - Titanium, 3- Ceramics): ";

constexpr auto START_LINE_BS = __LINE__;
enum class BladeS
{
    Bowie = 1,
    Kukri,
    Tanto,
    Dagger
};

constexpr auto Blade_COUNT_SH = __LINE__ - START_LINE_BS - 3;
const string Blade_NAMES_SH[] = { "Bowie", "Kukri", "Tanto", "Dagger"};
const string MENU_STRING_Blade_SH = "Выберите форму клинка(1 - Bowie, 2 - Kukri, 3 - Tanto, 4 - Dagger): ";

class Knife:
    public Weapons
{
public:
    Knife();
    Knife(string aBrand,  int aCreation, string aCountry, int aPrice, int aMileage, knifeT aKnife, MaterialT amaterial, BladeS ablade, double alength, int aWeight);


    void setKnifeT(knifeT aKnife);
    void setMaterialT(MaterialT amaterial);
    void setBladeS(BladeS ablade);
    void setBlade_length(double alength);
    void setWeight(int aWeight);
    void setEngine_speed(int aEngine_speed);
    knifeT getKnifeT() const;
    MaterialT getMaterialT() const;
    BladeS getBladeS() const;
    double getBlade_length() const;
    int getWeight() const;
    void readFromConsole() override;
    void writeToStream(ostream&) override;
private:
    knifeT knife_t;
    MaterialT material_t;
    BladeS blade_s;
    double length;
    int engine_power;
    int weight;
    void readElFromConsole();
    void dummy() override {};
};

