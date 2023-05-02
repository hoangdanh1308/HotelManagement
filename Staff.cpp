#pragma once
#include "Staff.h"

Staff::Staff(){

}
void Staff::display(Manager manager){
    databaseListRoom.resize(manager.getTotalRooms());
    for(int i = 0;i < databaseListRoom.size();i++){
        databaseListRoom[i].setBookedRoom(false);
    }
    do{
        cout<<"Room:     ";
        for(int i = 0;i <databaseListRoom.size();i++){
        cout<<(i + 1)<<"         ";
        }
        cout<<endl;
        cout<<"Status: ";
        for(int i = 0;i <databaseListRoom.size();i++){
            if(databaseListRoom[i].getBookedRoom() == true){
                cout<<"booked"<<"   ";
            } else{
                cout<<"available"<<" ";
            }
        }
        cout<<"\n enter key room number or key 0 to Exit\n";
        int key;
        cin>>key;
        if(key == 0){break;}
        cout<<"1.Rent\n2.Services\n3.Check-out\n";
        int tempOption;
        cin>>tempOption;
        switch (tempOption)
        {
        case 1:
        {
            if(databaseListRoom[key - 1].getBookedRoom() == true){
                cout<<"Room was booked"<<endl;
            }else {
                databaseListRoom[key - 1].rentRoom(manager);
            }
            break;
        }
        case 2:
        {   
            databaseListRoom[key - 1].services(manager);
            break;
        }
        case 3:
        {   
            databaseListRoom[key - 1].checkOut(manager);
            break;
        }
        default:
            break;
        }

    }while(1);
}