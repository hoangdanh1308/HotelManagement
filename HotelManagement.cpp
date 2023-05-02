#pragma once
#include "HotelManagement.h"

HotelManagement::HotelManagement(){
    int keyMode = 0;
    int keyLoop = 1;
    do{
        cout<<"Mode:\n1.Manager\n2.Staff\n3.Exit\n";
        cin>>keyMode;
        switch (keyMode)
        {
        case 1:
        {   
            int loop =1;
            do{
            cout<<"----Manager----\n";
            cout<<"1.Room Price\n2.Menu\n3.totalRoom\n4.Exit\n";
            int tempOption;
            cin>>tempOption;
            switch (tempOption)
            {
            case 1:
            {
                this->manager.setPriceRoom();
                break;
            }
            case 2:
            {
                cout<<"-----Menu----"<<endl;
                cout<<"1.Add\n2.Update\n3.Delete\n4.Show Menu\n";
                int key = 0;
                cin>>key;
                switch (key)
                {
                case 1:
                    this->manager.addDrinksAndFoods();
                    break;
                case 2:
                    this->manager.updateDrinksAndFoods();
                    break;
                case 3:
                    this->manager.deleteDrinksAndFoods();
                    break;
                case 4:
                    this->manager.getMenu();
                    break;
                default:
                    break;
                }
                break;
            }
            case 3:
                this->manager.setTotalRooms();
                break;
            case 4:
                loop = 0 ;
                break;
            default:
                break;
            }
            }while(loop);
            break;
        }
        case 2:
        {   
            this->staff.display(manager);
            break;
        }
        case 3:
            keyLoop = 0;
            break;
        default:
            break;
        }
    }while(keyLoop);
}