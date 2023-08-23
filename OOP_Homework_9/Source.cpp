#include <iostream>
#include <string>
using namespace std;

class Hero 
{
protected:
    string profession;
    string weapon;
    int mp;
    int cp;
    int hp;
public:
    Hero(const string& prof, const string& weap, int mana, int energy, int health)
        : profession(prof), weapon(weap), mp(mana), cp(energy), hp(health) {}

    void displayInfo()
    {
        cout << "Profession: " << profession << endl;
        cout << "Weapon: " << weapon << endl;
        cout << "MP: " << mp << endl;
        cout << "CP: " << cp << endl;
        cout << "HP: " << hp << endl;
    }
};

class Scout : public Hero
{
public:
    Scout(const string& weap) : Hero("Scout", weap, 50, 100, 80) {}
};

class Warrior : public Hero 
{
public:
    Warrior(const string& weap) : Hero("Warrior", weap, 30, 150, 150) {}
};

class Mage : public Hero 
{
public:
    Mage(const string& weap) : Hero("Mage", weap, 200, 50, 70) {}
};

class Priest : public Hero 
{
public:
    Priest(const string& prof, const string& weap)
        : Hero(prof, weap, 200, 30, 90) {}
};

class Assasin : public Scout 
{
public:
    Assasin(const string& weap) : Scout(weap)
    {
        profession = "Assasin";
        mp = 20;
        cp = 120;
        hp = 90;
    }
};

class Ranger : public Scout 
{
public:
    Ranger(const string& weap) : Scout(weap) 
    {
        profession = "Ranger";
        mp = 40;
        cp = 100;
        hp = 100;
    }
};

class Templar : public Warrior 
{
public:
    Templar(const string& weap) : Warrior(weap)
    {
        profession = "Templar";
        mp = 20;
        cp = 200;
        hp = 200;
    }
};

class Gladiator : public Warrior 
{
public:
    Gladiator(const string& weap) : Warrior(weap) {
        profession = "Gladiator";
        mp = 40;
        cp = 180;
        hp = 180;
    }
};

class Sorcerer : public Mage
{
public:
    Sorcerer(const string& weap) : Mage(weap)
    {
        profession = "Sorcerer";
        mp = 250;
        cp = 40;
        hp = 60;
    }
};

class Spiritmaster : public Mage
{
public:
    Spiritmaster(const string& weap) : Mage(weap) 
    {
        profession = "Spiritmaster";
        mp = 220;
        cp = 60;
        hp = 80;
    }
};

class Chanter : public Priest
{
public:
    Chanter(const string& weap) : Priest("Chanter", weap)
    {
        mp = 100;
        cp = 120;
        hp = 90;
    }
};

class Cleric : public Priest 
{
public:
    Cleric(const string& weap) : Priest("Cleric", weap) 
    {
        mp = 150;
        cp = 80;
        hp = 100;
    }
};

int main()
{
    string weapon;
    cout << "Enter weapon for your hero: ";
    getline(cin, weapon);

    int choice;
    cout << "Choose a hero class:" << endl;
    cout << "1. Scout" << endl;
    cout << "2. Warrior" << endl;
    cout << "3. Mage" << endl;
    cout << "4. Priest" << endl;
    cin >> choice;

    Hero* hero = nullptr;

    switch (choice) 
    {
    case 1:
        int scoutChoice;
        cout << "Choose a scout class:" << endl;
        cout << "1. Assasin" << endl;
        cout << "2. Ranger" << endl;
        cin >> scoutChoice;
        if (scoutChoice == 1)
            hero = new Assasin(weapon);
        else if (scoutChoice == 2)
            hero = new Ranger(weapon);
        else
        {
            cout << "Error! Invalid choice." << endl;
            return 1;
        }
        break;
    case 2:
        int warriorChoice;
        cout << "Choose a warrior class:" << endl;
        cout << "1. Templar" << endl;
        cout << "2. Gladiator" << endl;
        cin >> warriorChoice;
        if (warriorChoice == 1)
            hero = new Templar(weapon);
        else if (warriorChoice == 2)
            hero = new Gladiator(weapon);
        else
        {
            cout << "Error! Invalid choice." << endl;
            return 1;
        }
        break;
    case 3:
        int mageChoice;
        cout << "Choose a mage class:" << endl;
        cout << "1. Sorcerer" << endl;
        cout << "2. Spiritmaster" << endl;
        cin >> mageChoice;
        if (mageChoice == 1)
            hero = new Sorcerer(weapon);
        else if (mageChoice == 2)
            hero = new Spiritmaster(weapon);
        else
        {
            cout << "Error! Invalid choice." << endl;
            return 1;
        }
        break;
    case 4:
        int priestChoice;
        cout << "Choose a priest class:" << endl;
        cout << "1. Chanter" << endl;
        cout << "2. Cleric" << endl;
        cin >> priestChoice;
        if (priestChoice == 1)
            hero = new Chanter(weapon);
        else if (priestChoice == 2)
            hero = new Cleric(weapon);
        else
        {
            cout << "Error! Invalid choice." << endl;
            return 1;
        }
        break;
    default:
        cout << "Error! Invalid choice." << endl;
        return 1;
    }

    if (hero) 
    {
        cout << "\nHero Info:\n";
        hero->displayInfo();
        delete hero;
    }

    system("pause");

    return 0;
}