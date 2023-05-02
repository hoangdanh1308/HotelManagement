#pragma once
#include "Room.h"
#include "Manager.h"

class Staff{
    private:
        vector<Room> databaseListRoom;
    public:
        Staff();
        void display(Manager manager);
};
