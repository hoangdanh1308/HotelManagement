#pragma once
#include "Manager.h"


void Manager::addDrinksAndFoods(){
    this->menu.addDrinksAndFoods();
}
void Manager::updateDrinksAndFoods(){
    this->menu.updateDrinksAndFoods();
}
void Manager::deleteDrinksAndFoods(){
    this->menu.deleteDrinksAndFoods();
}
void Manager::getMenu(){
    this->menu.getMenu();
}
void Manager::setTotalRooms(){
    cout<<"enter total number of Rooms:"<<endl;
    cin>>this->totalRooms;
}
int Manager::getTotalRooms(){
    return this->totalRooms;
}
void Manager::setPriceRoom(){
    cout<<"-----\n1.hourly price\n2.overnight price\n";
    int tempOption;
    cin>>tempOption;
    if(tempOption == 1){
        cout<<"enter hourly price"<<endl;
        cin>>this->priceRoom[0];
    } else if(tempOption == 2){
        cout<<"enter overnight price"<<endl;
        cin>>this->priceRoom[1];
    }
}
int Manager::getPriceRoom(int option){
    if(option == 1){
        return this->priceRoom[0];
    } else if(option == 2){
        return this->priceRoom[1];
    }
}

