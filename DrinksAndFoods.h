#pragma once
#include "header.h"

class DrinksAndFoods{
    protected:
        int id;
        string name;
        int price;
    public:
        DrinksAndFoods();
        void setDrinksAndFoods();
        void setID(int id);
        int getID();
        string getName();
        int getPrice();
        void setName();
        void setName(string name);
        void setPrice();
        void setPrice(int price);
        void setID();
};

class Order:public DrinksAndFoods{
    private:
    int quantityofThatItem;
    public:
    void setquantityofThatItem(int quantity);
    int getquantityofThatItem();
};

