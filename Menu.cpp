#pragma once
#include "Menu.h"

void Menu::addDrinksAndFoods(){
    do{
    DrinksAndFoods temp;
    temp.setDrinksAndFoods();
    this->databaseMenu.push_back(temp);
    int key = 0;
    cout<<"enter key 1 to exit.";
    cin>>key;
    if(key){break;}
    }while(1);
}
void Menu::updateDrinksAndFoods(){
    cout<<"enter ID of Drink or Food you want to update:\n";
    int tempID;
    cin>> tempID;
    cout<<"what do you want to update? 1. Name   2.Price\n";
    int tempOption;
    cin>>tempOption;
    for(int i = 0; i < databaseMenu.size();i++){
        if(this->databaseMenu[i].getID() == tempID){
            if(tempOption == 1){
                databaseMenu[i].setName();
            }else if(tempOption == 2){
                databaseMenu[i].setPrice();
            }
        }
    }
}
void Menu::deleteDrinksAndFoods(){
    cout<<"enter ID of Drink or Food you want to delete:";
    int tempID;
    cin>> tempID;
    for(int i = 0; i < databaseMenu.size();i++){
        if((int)databaseMenu[i].getID() == tempID){
            databaseMenu.erase(databaseMenu.begin() + i);
        }
    }
}
void Menu::getMenu(){
    cout<<"**This is the restaurant's menu**\n"<<"STT: \tName: \tID: \tPrice: \n";
    for(int i = 0; i < databaseMenu.size();i++){
        cout<<"STT: "<<i+1<<"  Name: "<<databaseMenu[i].getName().c_str()<<" "<<"ID: ";
        printf("%d",databaseMenu[i].getID());
        cout<<" "<<"Price: "<<databaseMenu[i].getPrice()<<endl;
    }
}
DrinksAndFoods Menu::getInformation(int id){
    for(DrinksAndFoods item:this->databaseMenu){
        if(item.getID() == id){
            return item;
        }
    }
}