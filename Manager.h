#pragma once
#include "header.h"
#include "Menu.h"

class Manager{
    private:
        int priceRoom[2];
        Menu menu;
        int totalRooms;
    public:
        void setTotalRooms();
        int getTotalRooms();
        void addDrinksAndFoods();
        void updateDrinksAndFoods();
        void deleteDrinksAndFoods();
        void getMenu();
        void setPriceRoom();
        int getPriceRoom(int option);
        friend class Room;
        friend class Staff;
};