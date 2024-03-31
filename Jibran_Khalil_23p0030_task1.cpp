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
    Item(){
        // cout << endl
        //      << "default constructor called" << endl
        //      << endl;
    };
    Item(struct Items item) : item(item)
    {
        // cout << endl
        //      << "parametrized constructor called" << endl
        //      << endl;
        this->item = item;
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

    static long long int total_items;
    static long long int total_foods;
    static long long int total_tools;
    static long long int total_equipment;

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
        case (Categorie::Food):
            cout << "Food";
            break;
        case (Categorie::Tools):
            cout << "Tools";
            break;
        case (Categorie::Equipment):
            cout << "Equipment";
            break;
        }
        cout << endl;
    };

    static void display_total_categories()
    {
        cout << "-----------------------------------------" << endl;
        cout << "-------- Total Items : " << total_items << " --------" << endl;
        cout << "Total Food : " << total_foods << endl;
        cout << "Total Tools : " << total_tools << endl;
        cout << "Total Equipment : " << total_equipment << endl
             << "-----------------------------------------"
             << endl
             << endl;
    }

    static void totalIncrement()
    {
        total_items += 1;
    }
};

long long int Item::total_items = 1;
long long int Item::total_foods = 0;
long long int Item::total_tools = 0;
long long int Item::total_equipment = 0;

void showAllItems(Item *items);

int isIdUsedBefore(int id, Item *items)
{
    for (int i = 0; i < Item::total_items; i++)
    {
        if (id == items[i].get_id())
        {
            return i;
        }
    }
    return -1;
};

void showAllItems(Item *items)
{
    for (int i = 0; i < Item::total_items; i++)
    {
        items[i].display();
        cout << endl;
    }
    cout << endl;
    Item::display_total_categories();
};

Items createNewItem(Item *items)
{
    struct Items single_item;
    int id;
    cout << "Enter Item id : ";
    while (1)
    {
        cin >> id;
        if (Item::total_equipment == 1)
            break;

        if (isIdUsedBefore(id, items) != -1)
        {
            cout << "id already used try another :";
            continue;
        }
        else
        {
            break;
        }
        cin.ignore();
    }
    single_item.id = id;
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
    single_item.categorie = Categorie(ctg);
    return single_item;
}

int main()
{

    cout << "Enter the first item to the list :" << endl;

    Item *items = new Item[Item::total_items];
    items[0] = Item(createNewItem(items));
    system("clear");

    char choice1;
    while (1)
    {
        cout << "1:Add New Item\n2:Update item\n3.Retriev Item Detail\n4.Retriev Total Item \n0:Exit" << endl;
        cin >> choice1;
        cin.ignore();
        if (choice1 == '1')
        {
            system("clear");
            Item::totalIncrement();
            Item *newItems = new Item[Item::total_items];
            for (int i = 0; i < Item::total_items - 1; i++)
            {
                newItems[i] = items[i];
            }
            newItems[Item::total_items - 1] = Item(createNewItem(items));
            delete[] items;
            items = newItems;
            cout << "Sucessfully added " << endl
                 << endl;
        }
        else if (choice1 == '2')
        {
            system("clear");
            if (Item::total_items <= 0)
            {
                cout << "-----------------------------------------" << endl
                     << "Nothing here , add some items first!" << endl
                     << "-----------------------------------------" << endl;
            }
            else
            {
                int id;
                while (1)
                {
                    cout << "Enter the item id :" << endl;
                    cin >> id;
                    int idInArray = isIdUsedBefore(id, items);
                    if (idInArray == -1)
                    {
                        cout << "No Item Found with this id !" << endl;
                        break;
                    }
                    else
                    {
                        // for updating name
                        {
                            char update;
                            while (1)
                            {
                                cout << "Update Name ? (y/n):";
                                cin >> update;
                                if (update != 'y' && update != 'n')
                                {
                                    cout << "wrong input try again !" << endl;
                                    continue;
                                }
                                else
                                {
                                    break;
                                }
                                cin.ignore();
                            }
                            if (update == 'y')
                            {
                                string name;
                                cout << "Enter Name : ";
                                // cin >> item.name;
                                cin.ignore();
                                getline(cin, name);
                                items[idInArray].set_name(name);
                            }
                        }
                        // for updating quantity
                        {
                            char update;
                            while (1)
                            {
                                cout << "Update Quantity ? (y/n):";
                                cin >> update;
                                if (update != 'y' && update != 'n')
                                {
                                    cout << "wrong input try again !" << endl;
                                    continue;
                                }
                                else
                                {
                                    break;
                                }
                            }
                            if (update == 'y')
                            {
                                int qty;
                                cout << "Enter Quantity : ";
                                cin >> qty;
                                items[idInArray].set_quantity(qty);
                            }
                        }
                        // for updating Categorie
                        {
                            char update;
                            while (1)
                            {
                                cout << "Update Categorie ? (y/n):";
                                cin >> update;
                                if (update != 'y' && update != 'n')
                                {
                                    cout << "wrong input try again !" << endl;
                                    continue;
                                }
                                else
                                {
                                    break;
                                }
                            }
                            if (update == 'y')
                            {
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

                                if (items[idInArray].get_categorie() == Categorie::Food)
                                {
                                    Item::total_foods -= 1;
                                }
                                else if (items[idInArray].get_categorie() == Categorie::Tools)
                                {
                                    Item::total_items -= 1;
                                }
                                else if (items[idInArray].get_categorie() == Categorie::Equipment)
                                {
                                    Item::total_equipment -= 1;
                                }

                                items[idInArray].set_categorie(Categorie(ctg));

                                if (items[idInArray].get_categorie() == Categorie::Food)
                                    Item::total_foods += 1;
                                else if (items[idInArray].get_categorie() == Categorie::Tools)
                                    Item::total_items += 1;
                                else if (items[idInArray].get_categorie() == Categorie::Equipment)
                                    Item::total_equipment += 1;
                            }

                            cout << "Updated sucessfully" << endl
                                 << endl;
                            break;
                        }
                    }
                }
            }
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