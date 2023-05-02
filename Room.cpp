#pragma once
#include "Room.h"


/*
* Function: leapYear
* Description: This function check leap year.
* Input:
*   inputYear - an const integer value
* Output:
*   returns 0 if false , 1 if true.
*/
bool leapYear(const int inputYear){
    if(inputYear % 4 == 0 || inputYear % 400 == 0){
         return true;
    }
    else{
        return false;
    }
}
/*
* Function: totalDayInMonth
* Description: This function determine the number of days in the month.
* Input:
*   inputMonth - a Month enums
*   inputYear - an const integer value
* Output:
*   return the number of days in the month. 
*/
int totalDayInMonth(Month inputMonth, const int inputYear){
    switch (inputMonth)
    {
    case JANUARY:
    case MARCH:
    case MAY:
    case JULY:
    case AUGUST:
    case OCTOCBER:
    case DECEMBER:
        return 31;
        break;
    case APRIL:
    case JUNE:
    case SEPTEMBER:
    case NOVEMBER:
        return 30;
        break;
    case FEBRUARY:
        if(leapYear(inputYear)){
            return 29;
        }else return 28;
        break;
    default:
        printf("please re-enter the month");
        break;
    }
}

Room::Room(){
    this->checkinDate = {0,0,JANUARY,0};
    this->checkoutDate = {0,0,JANUARY,0};
    this->bookedRoom = false;
}
void Room::rentRoom(Manager Manager){
    cout<<"A hourly price is: "<<Manager.getPriceRoom(1)<<endl;
    cout<<"A overnight price is: "<<Manager.getPriceRoom(2)<<endl;
    cout<<"1.hourly rental\n2.overnight rental\n";
    int tempOption;
    cin>>tempOption;
    cout<<"enter a check-in date:(example: 23 1 JANUARY 2023)\n";
    cin>>this->checkinDate.hour;
    cin>>this->checkinDate.day;
    setMonth(this->checkinDate.month);
    cin>>this->checkinDate.year;
    if(tempOption ==1){
        rental = true;
        priceRoom = Manager.getPriceRoom(1);
    } else if(tempOption == 2){
        rental = false;
        priceRoom = Manager.getPriceRoom(2);   
    }
    this->bookedRoom = true;
}
void Room::services(Manager Manager){
    cout<<"Services:\n1.Order\n2.update Order\n3.delete order\n4.list order\n";
    int tempOption;
    cin>>tempOption;
    switch (tempOption)
    {
    case 1:
    {
        do{
        Manager.getMenu();
        cout<<"enter ID of Drink or Food you want to order:\n";
        int tempID;
        Order tempOrder;
        cin>>tempID;
        DrinksAndFoods temp = Manager.menu.getInformation(tempID);
        tempOrder.setID(tempID);
        tempOrder.setName(temp.getName());
        tempOrder.setPrice(temp.getPrice());
        cout<<"enter quantity: "<<endl;
        int tempQuantity;
        cin>>tempQuantity;
        tempOrder.setquantityofThatItem(tempQuantity);
        this->listOrder.push_back(tempOrder);
        cout<<"1.continue\n2.exit\n";
        int key;
        cin>>key;
        if(key == 2){break;}
        }while(1);
        break;
    }
    case 2:
    {
        for(Order item:listOrder){
            cout<<"ID: "<<item.getID()<<"\tName: "<<item.getName()<<"\tPrice: "<<item.getPrice()<<"\tQuantity: "<<item.getquantityofThatItem()<<endl;
        }
        cout<<"enter ID of Drink or Food you want to update"<<endl;
        int tempID;
        cin>>tempID;
        for (int i = 0; i < listOrder.size();i++){
            if(listOrder[i].getID() == tempID){
                listOrder[i].setquantityofThatItem(tempID);
                break;
            }
        }
        break;
    }
    case 3:
    {   
        for(Order item:listOrder){
        cout<<"ID: "<<item.getID()<<"\tName: "<<item.getName()<<"\tPrice: "<<item.getPrice()<<"\tQuantity: "<<item.getquantityofThatItem()<<endl;
        }
        cout<<"enter ID of Drink or Food you want to delete"<<endl;
        int tempID;
        cin>>tempID;
        for (int i = 0; i < listOrder.size();i++){
            if(listOrder[i].getID() == tempID){
                listOrder.erase(listOrder.begin()+i);
                break;
            }
        }
        break;
    }
    case 4:
    {   
        cout<<"Your list order is:\n";
        for(Order item:listOrder){
        cout<<"ID: "<<item.getID()<<"\tName: "<<item.getName()<<"\tPrice: "<<item.getPrice()<<"\tQuantity: "<<item.getquantityofThatItem()<<endl;
        }
    }
    default:
        break;
    }
}

void Room::checkOut(Manager Manager){
    cout<<"enter a check-out date:(example: 22 1 12 2023)\n";
    cin>>this->checkoutDate.hour;
    cin>>this->checkoutDate.day;
    setMonth(this->checkoutDate.month);
    cin>>this->checkoutDate.year;
    int totalTime = totalHour(checkinDate,checkoutDate);
    int totalMoney = 0;
    cout<<"---------Your bill is:---------\n";
    if(this->rental == 1){
        cout<<"hourly rental\t"<<"Price: \t"<<this->priceRoom<<"\tquantity: "<<totalTime<<"\tMoney: "<<totalTime*this->priceRoom<<endl;
        totalMoney = totalMoney + totalTime*this->priceRoom;
    }else if(this->rental == 0){
        cout<<"overnight rental\t"<<"Price: \t"<<this->priceRoom<<"\tquantity: "<<totalTime/24<<"\tMoney: "<<(totalTime/24)*this->priceRoom<<endl;
        cout<<"extra hourly rental\t"<<"Price: \t"<<Manager.getPriceRoom(1)<<"\tquantity: "<<(totalTime%24)<<"\tMoney: "<<totalTime%24*Manager.getPriceRoom(1)<<endl;
        totalMoney = totalMoney + (totalTime/24)*this->priceRoom + totalTime%24*Manager.getPriceRoom(1);
    }
    for(Order item:listOrder){
        cout<<"Name: "<<item.getName()<<"\tPrice: "<<item.getPrice()<<"\tQuantity: "<<item.getquantityofThatItem()<<"\tMoney: "<<item.getPrice()*item.getquantityofThatItem()<<endl;
        totalMoney = totalMoney + item.getPrice()*item.getquantityofThatItem();
    }
    cout<<"total money is: "<<totalMoney<<endl;
    this->checkinDate = {0,0,JANUARY,0};
    this->checkoutDate = {0,0,JANUARY,0};
    this->bookedRoom = false; 
}

void Room::setBookedRoom(bool bookedRoom){
    this->bookedRoom = bookedRoom;
}
bool Room::getBookedRoom(){
    return this->bookedRoom;
}

int totalHour(DayMonthYear a,DayMonthYear b){
    if (a.month == b.month){
        return (b.day-a.day)*24 + (b.hour-a.hour);
    } else if(a.month != b.month){
        return ((totalDayInMonth(a.month,a.year) - a.day)+b.day)*24 + (b.hour-a.hour);
    }
}
void setMonth(Month &month){
    int tempMonth;
    cin>>tempMonth;
    switch (tempMonth)
    {
    case 1:
        month = JANUARY;
        break;
    case 2:
        month = FEBRUARY;
        break;
    case 3:
        month = MARCH;
        break;
    case 4:
        month = APRIL;
        break;
    case 5:
        month = MAY;
        break;
    case 6:
        month = JUNE;
        break;
    case 7:
        month = JULY;
        break;
    case 8:
        month = AUGUST;
        break;
    case 9:
        month = SEPTEMBER;
        break;
    case 10:
        month = OCTOCBER;
        break;
    case 11:
        month = NOVEMBER;
        break;
    case 12:
        month = DECEMBER;
        break;
    default:
        break;
    }
}
