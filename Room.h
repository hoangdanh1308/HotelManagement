#pragma once
#include "Header.h"
#include "Manager.h"
#include "DrinksAndFoods.h"
typedef enum{
    JANUARY    = 1,
    FEBRUARY   = 2,
    MARCH      = 3,
    APRIL      = 4,
    MAY        = 5,
    JUNE       = 6,
    JULY       = 7,
    AUGUST     = 8,  
    SEPTEMBER  = 9,
    OCTOCBER   = 10,
    NOVEMBER   = 11,
    DECEMBER   = 12,
}Month;

struct DayMonthYear
{   
    int hour;
    int day;
    Month month;
    int year;
};

bool leapYear(const int inputYear);

int totalDayInMonth(Month inputMonth, const int inputYear);

class Room{
    private:
        DayMonthYear checkinDate;
        DayMonthYear checkoutDate;
        vector <Order> listOrder;
        int priceRoom;
        bool bookedRoom;
        bool rental; //true -- hourlyRental   , false -- overnightRental
    public:
        Room();
        void rentRoom(Manager Manager);
        void services(Manager Manager);
        void checkOut(Manager Manager);
        void setBookedRoom(bool bookedRoom);
        bool getBookedRoom();
};
int totalHour(DayMonthYear a,DayMonthYear b);
void setMonth(Month &montn);


