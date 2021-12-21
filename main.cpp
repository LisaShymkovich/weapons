#include <iostream>
#include "weapons.hpp"
#include "gun.hpp"
#include "knife.hpp"
#include "crossbow.hpp"
#include <vector>
using namespace std;
int main()
{
    int op;
    int size;
    Weapons* weapon;
    vector <Weapons*> mass;
    cout << "Enter the amount of weapon: ";
    cin >> size;
    for (unsigned i = 0; i < size; i++)
    {
        cout << "Choose your weapon: \n" << "1. Gun\n" << "2. Knife\n" << "3. Crossbow\n";
        cin >> op;
        switch (op)
        {
            case 1:
                cin.ignore();
                try
            {
                weapon = new Gun();
                mass.push_back(weapon);
            } catch (runtime_error &err)
            {
                cout << err.what() << endl;
                return 0;
            }
                break;
                
            case 2:
                cin.ignore();
                try
            {
                weapon = new Knife();
                mass.push_back(weapon);
            }
                catch (runtime_error &err)
            {
                cout << err.what() << endl;
                return 0;
            }
                
                break;
                
            case 3:
                cin.ignore();
                try
            {
                weapon = new Crossbow();
                mass.push_back(weapon);
            }
                catch (const runtime_error &err)
            {
                cout << err.what() << endl;
                return 0;
            }
                break;
            default:
                cout << "Error option choose\n";
        }
    }
    cout << "\n\n Weapon: " << endl;
    for (unsigned i = 0; i < mass.size(); i++)
    {
        
        mass[i]->writeToStream(cout);
    }
    cout << "\n";
    return 0;
}

