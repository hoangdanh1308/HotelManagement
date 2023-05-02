#pragma once
#include "DrinksAndFoods.h"
DrinksAndFoods::DrinksAndFoods(){
    this->id = 0;
    this->name = " ";
    this->price = 0;
}
void DrinksAndFoods::setDrinksAndFoods(){
    static int coutID = 2;
    this->id = (int)coutID;
    coutID++;
    cout<<"Enter name of Drink or Food:\n";
    cin>>this->name;
    cout<<"Enter price:"<<endl;
    cin>>this->price;
}
void DrinksAndFoods::setID(int id){
    this->id = id;
}
int DrinksAndFoods::getID(){
    return this->id;
}
string DrinksAndFoods::getName(){
    return this->name;
}
int DrinksAndFoods::getPrice(){
    return this->price;
}
void DrinksAndFoods::setName(){
    cout<<"Enter name of Drink or Food:\n";
    cin>>this->name;
}
void DrinksAndFoods::setName(string name){
    this->name = name;
}
void DrinksAndFoods::setPrice(){
    cout<<"Enter price:"<<endl;
    cin>>this->price;
}
void DrinksAndFoods::setPrice(int price){
    this->price = price;
}
void DrinksAndFoods::setID(){
    int id;
    cin>>id;
    this->id = id;
}

void Order::setquantityofThatItem(int quantity){
    this->quantityofThatItem = quantity;
}
int Order::getquantityofThatItem(){
    return this->quantityofThatItem;
}