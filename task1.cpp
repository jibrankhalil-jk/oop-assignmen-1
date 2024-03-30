#include <iostream>
#include <string>

using namespace std;

enum Categorie
{
    Food = 1,
    Tools,
    Equipment
};

struct Items
{
    int id;
    string name;
    int quantity;
    Categorie categorie;
};

class Item
{
private:
    struct Items item;

public:
    Item(){};
    Item(struct Items item) : item(item)
    {
        switch (item.categorie)
        {
        case (Categorie::Food):
            total_foods++;
            break;
        case (Categorie::Tools):
            total_tools++;
            break;
        case (Categorie::Equipment):
            total_equipment++;
            break;
        }
    };

    void udateItem(Items item)
    {
        this->item = item;
    };

    static int total_items;
    static int total_foods;
    static int total_tools;
    static int total_equipment;

    void set_id(int id)
    {
        item.id = id;
    };
    void set_name(string name)
    {
        item.name = name;
    };
    void set_quantity(int quantity)
    {
        item.quantity = quantity;
    };
    void set_categorie(Categorie categorie)
    {
        item.categorie = categorie;
    };

    int get_id()
    {
        return item.id;
    };
    string get_name()
    {
        return item.name;
    };
    int get_quantity()
    {
        return item.quantity;
    };
    Categorie get_categorie()
    {
        return item.categorie;
    };

    void display()
    {
        cout << "Item id : " << item.id << endl;
        cout << "Item Name : " << item.name << endl;
        cout << "Item quantity : " << item.quantity << endl;
        cout << "Item Categories : ";
        switch (item.categorie)
        {
        case 0:
            cout << "Food";
            break;
        case 1:
            cout << "Tools";
            break;
        case 2:
            cout << "Equipment";
            break;
        }
        cout << endl;
    };
    static void display_total_categories()
    {
        cout << "-----------------------------------------" << endl;
        cout << "-------- Total Items : " << total_foods << " --------" << endl;
        cout << "Total Food : " << total_foods << endl;
        cout << "Total Tools : " << total_tools << endl;
        cout << "Total Equipment : " << total_equipment << endl
             << "-----------------------------------------"
             << endl
             << endl;
    }

    void operator++()
    {
        ++total_items;
    }
};

int Item::total_items = 0;
int Item::total_foods = 0;
int Item::total_tools = 0;
int Item::total_equipment = 0;

bool checkDubilcateId(int id, Item *items)
{
    for (int i = 0; i < Item::total_items; i++)
    {
        if (items[i].get_id() == id)
        {
            return true;
        }
    }

    return false;
};

void addNewItem(Item *&items)
{
    Item *temp = new Item[Item::total_items + 1];

    for (int i = 0; i < Item::total_items; i++)
    {
        temp[i] = items[i];
    }

    struct Items single_item;
    cout << "Enter Item id : ";
    while (1)
    {
        cin >> single_item.id;
        if (!checkDubilcateId(single_item.id, items))
        {
            break;
        }
        else
        {
            cout << "id already used try another :";
        }
        cin.ignore();
    }
    cout << "Enter Name : ";
    // cin >> item.name;
    cin.ignore();
    getline(cin, single_item.name);
    cout << "Enter Quantity :";
    cin >> single_item.quantity;
    int ctg;
    while (1)
    {
        cout << "Enter categorie (1:Food,2:Tools,3:Equipment) : ";
        cin >> ctg;
        if (ctg >= 1 && ctg <= 3)
        {
            break;
        }
        else
        {
            cout << "Incorrect categorie chose again ! " << endl;
        }
    }
    single_item.categorie = Categorie(1);

    Item new_item(single_item);
    // incrementing the the total item (staic variable strig items)
    // ++new_item;

    cout << Item::total_items;
    // temp[Item::total_items] = new_item;
    ++new_item;

    items = temp;
    // deleting the temperory items array
    // delete[] temp;
};
void showAllItems(Item *items)
{
    for (int i = 0; i < Item::total_items; i++)
    {
        items[i].display();
    }
    cout << endl;
    Item::display_total_categories();
};

int main()
{

    Item *items = new Item[Item::total_equipment];

    char choice1;

    while (1)
    {
        cout << "1:Add New Item\n2:Update item\n3.Retriev Item Detail\n4.Retriev Total Item \n0:Exit" << endl;
        cin >> choice1;
        cin.ignore();
        // cin.clear();
        if (choice1 == '1')
        {
            system("clear");
            addNewItem(items);
        }
        else if (choice1 == '2')
        {
            system("clear");
            if (Item::total_items <= 0)
            {
                cout << "-----------------------------------------" << endl
                     << "Nothing here ,  add some items first!" << endl
                     << "-----------------------------------------" << endl;
            }
            else
                cout << "updating new items" << endl;
        }
        else if (choice1 == '3')
        {
            system("clear");
            if (Item::total_items <= 0)
            {
                cout << "-----------------------------------------" << endl
                     << "Nothing here ,  add some items first!" << endl
                     << "-----------------------------------------" << endl;
            }
            else
                showAllItems(items);
        }
        else if (choice1 == '4')
        {
            system("clear");

            Item::display_total_categories();
        }
        else if (choice1 == '0')
        {
            cout << "Exiting !..." << endl;
            break;
        }
    }

    return 0;
}