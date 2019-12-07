#include<bits/stdc++.h>

using namespace std;

string po, pt;
int pop = 0, ptp = 0;

string cp;

int omark = 0, tmark = 0;

void draw()
{
    system("clear");
    cout << "Your turn " << cp << endl;
    cout << po << ": " << pop << "                       " << pt << ": " << ptp << endl;
}
void input()
{  
    cout << "choose :-" << endl << "1 for stone" << endl << "2 for paper" << endl << "3 for scissors" << endl;
    if(cp == po){
        cin >> omark;
        if(omark < 1 || omark > 3){
            cout << "Invalid input";
            input();
        }
    }
    else{
        cin >> tmark;
        if(tmark < 1 || tmark > 3){
            cout << "Invalid input" << endl;
            input();
        }
    }
}
int logic()
{
    if((omark == 1 && tmark == 2) || (omark == 2 && tmark == 3) || (omark == 3 && tmark == 2)){
        cout << "Point to " << pt << endl;
        ptp++;
        return 2;
    }
    else if((omark == 2 && tmark == 1) || (omark == 3 && tmark == 2) || (omark == 1 && tmark == 3)){
        cout << "Point to " << po << endl;
        pop++;
        return 1;
    }
    else{
        cout << "Draw point" << endl;
    }
    
}

void playershift()
{
    if(cp == po){
        cp = pt;
    }
    else{
        cp = po;
    }
}

int main()
{
    system("clear");

    int target;

    cout << "PVP stone paper scissors" << endl;
    cout << "What is your name player number 1: ";
    cin >> po;
    cp = po;
    cout << "Write your name player number 2: ";
    cin >> pt;
    cout << "For how many points you want to play: ";
    cin >> target;
    system("clear");
    
    while(1){
        if(pop >= target){
            system("clear");
            cout << "You won it " << po << " .Congratulations!!";
            return 0;
        }
        if(ptp >= target){
            system("clear");
            cout << "You won it " << pt << " .Congratulations!!";
            return 0;
        }
        draw();
        input();
        playershift();
        draw();
        input();
        logic();
    }

    return 0;
}