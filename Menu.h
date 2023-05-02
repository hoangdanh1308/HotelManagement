#pragma once
#include "DrinksAndFoods.h"


class Menu{
    private:
        vector<DrinksAndFoods> databaseMenu;
    public:
        void addDrinksAndFoods();
        void updateDrinksAndFoods();
        void deleteDrinksAndFoods();
        void getMenu();
        DrinksAndFoods getInformation(int id);
};

