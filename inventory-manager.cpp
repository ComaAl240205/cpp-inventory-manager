#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include <limits>


void showItems(const std::vector<std::string>& inventory);
void addItem(std::vector<std::string>& inventory);
void removeItem(std::vector<std::string>& inventory);
void searchItem(const std::vector<std::string>& inventory);
std::string lowerCase(std::string text);
void Continue();

int main()
{
    std::vector<std::string> inventory;
    bool activ = true;
    char choice;
    
    while (activ) {
        std::cout
            << "===============\n"
            << "   INVENTORY\n"
            << "===============\n"
            << "1. Add item\n"
            << "2. Remove item\n"
            << "3. Show items\n"
            << "4. Search item\n"
            << "5. Exit\n\n"
            << "Choice :";
                
        choice = _getch();

        if (choice < '1' || choice > '5')
         {
            system("cls");
            continue;
         }
         std::cout << choice << '\n';

         std::string dummy;
         std::getline(std::cin, dummy);

        switch (choice) {
            case '1':
                system("cls");
                addItem(inventory);
                break;

            case '2':
                system("cls");
                removeItem(inventory);
                break;
            
            case '3':
                system("cls");
                showItems(inventory);
                break;

            case '4':
                system("cls");
                searchItem(inventory);
                break;

            case '5':
                activ = false;
                break;
        }
    }
}

void addItem(std::vector<std::string>& inventory)
{
    std::string item;

    std::cout << "Add a new item to the Inventory:";
    std::getline(std::cin, item);

    if (item.find_first_not_of(" \t\n\r") != std::string::npos) {
        inventory.push_back(item);
        std::cout << "Added succesfully!" << std::endl;
    }
    else
    {
        std::cout << "Invalid item name!" << std::endl;
    }
    Continue();
}

void removeItem(std::vector<std::string>& inventory)
{
    if (!inventory.empty()) {
        int choice;
        int maxValid = inventory.size();

        showItems(inventory);

        std::cout << "Remove an Item from the Inventory: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (!(std::cin >> choice))
        {
            std::cout << "Invalid item number!" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }else if (choice > 0 && choice <= maxValid)
        {
            inventory.erase(inventory.begin() + choice - 1);
            std::cout << "Removed Successfully!" << std::endl;
        }
        else
        {
            std::cout << "Invalid item number!" << std::endl;
        }
    }
    else
    {
        std::cout << "Inventory is empty!" << std::endl;
    }
    Continue();
}

void showItems(const std::vector<std::string>& inventory)
{
    if (!inventory.empty()) {
        for (int i = 0; i < inventory.size(); i++)
        {
            std::cout << i + 1 << "..." << inventory[i] << "\n" << std::endl;
        }
    }
    else
    {
        std::cout << "Inventory is empty!" << std::endl;
        Continue();
    }
}

void searchItem(const std::vector<std::string>& inventory)
{
    if (!inventory.empty())
    {
        int index = 0;
        bool gefunden = false;
        std::string search;

        std::cout << "Search an Item:";
        std::getline(std::cin, search);
        std::cout << "\n" << std::endl;


        for (std::string item : inventory) {

            std::string found = item;
            std::string lowerSearch = lowerCase(search);
            std::string lowerItem = lowerCase(item);

            if (lowerItem.find(lowerSearch) != std::string::npos) {
                std::cout << index + 1 << "..." << found << std::endl;
                gefunden = true;
            }
            else
            {
                index++;
            }
        }
        if (!gefunden)
        {
            std::cout << "No items found." << std::endl;

        }
    }
    else
    {
        std::cout << "Inventory is empty!" << std::endl;
    }
    Continue();
}

std::string lowerCase(std::string text) {
    for (char& c : text) {
        c = std::tolower(c);
    }
    return text;
}

void Continue() {
    std::string dummy;
    std::cout << "Press ENTER to continue...";
    std::getline(std::cin, dummy);
    system("cls");
}
