#include <iostream>
#include <string>

using namespace std;

enum Categories
{
    Food,
    Tools,
    Equipment
};

class Item
{
public:
    static int total_foods;
    static int total_tools;
    static int total_equipment;

private:
    int uid;
    string name;
    int quantity;
    Categories categorie;

public:
    Item(){};
    Item(int uid, string name, int quantity, Categories categorie) : uid(uid), name(name), quantity(quantity), categorie(categorie)
    {
        switch (categorie)
        {
        case 0:
            total_foods++;
            break;
        case 1:
            total_tools++;
            break;
        case 2:
            total_equipment++;
            break;
        default:
            break;
        }
    };

    void set_uid(int uid)
    {
        this->uid = uid;
    };
    void set_name(string name)
    {
        this->name = name;
    };
    void set_quantity(int quantity)
    {
        this->quantity = quantity;
    };
    void set_categorie(Categories categorie)
    {
        this->categorie = categorie;
    };

    int get_uid()
    {
        return uid;
    };
    string get_name()
    {
        return name;
    };
    int get_quantity()
    {
        return quantity;
    };
    Categories get_categorie()
    {
        return categorie;
    };

    void print_info()
    {
        cout << "Item id : " << uid << endl;
        cout << "Item Name : " << name << endl;
        cout << "Item quantity : " << quantity << endl;
        cout << "Item Categories : ";
        switch (categorie)
        {
        case 0:
            cout << "Food";
            break;
        case 1:
            cout << "Tools";
            break;
        case 2:
            cout << "Equipmen";
            break;

        default:
            break;
        }
        cout << endl;
    };

    static void print_total_categories()
    {
        cout << "Total Food : " << total_foods << endl;
        cout << "Total Tools : " << total_tools << endl;
        cout << "Total Equipment : " << total_equipment << endl;
    }
};

int Item::total_foods = 0;
int Item::total_tools = 0;
int Item::total_equipment = 0;

void addNewItem(Item *items, int size)
{
    Item temp[size + 1];
    for (int i = 0; i < size; i++)
    {
        temp[i] = items[i];
    }
    cout << "Enter Item id: ";
    
};

int main()
{
    int size = 0;
    Item *items[0];
    int uid;
    string name;
    int quantity;
    Categories categorie;

    char choice1;
    cout << "1:Add New Item\n2:Update item\n3.Retriev Item Detail";
    cin >> choice1;

    return 0;
}