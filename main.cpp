#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <time.h>
#include <ctime>

using namespace std;

string imie;
string pesel;
int wybor;

int main()
{
    cout << "Witam!" << endl;
    cout << "1. Wyswietlenie imienia"<< endl;
    cout << "2. Wyswietlenie imienia duzymi literami"<< endl;
    cout << "3. Plec z imienia"<< endl;
    cout << "4. Plec z numeru PESEL"<< endl;
    cout << "5. Plec i pelnoletniosc z PESELU"<< endl;
    cout << "Prosze wybrac funkcje programu: " << endl;
    cin>>wybor;

    switch(wybor){
    case 1:
    system("cls");
    cout<<"Prosze wpisac imie: ";
    cin>>imie;
    cout<<"Wpisanie imie to: "<<imie;
    break;

    case 2:
    system("cls");
    cout<<"Prosze wpisac imie: ";
    cin>>imie;
    transform(imie.begin(), imie.end(), imie.begin(), ::toupper);
    cout<<"Wpisanie imie duzymi literami to: "<<imie;
    break;

    case 3:
    system("cls");
    cout<<"Prosze wpisac imie: ";
    cin>>imie;
    if(imie.back()=='a'){
        cout<<"Twoja plec to kobieta"<<endl;
    }else{
    cout<<"Twoja plec to mezczyzna"<<endl;
    }
    break;

    case 4:
    cout<<"Podaj PESEL: ";
    cin>>pesel;
    if(pesel.length() != 11){
        cout<<"Niepoprawny pesel";
        return 0;
    }
    pesel.pop_back();       //usuwa ostatni charakter z pesel
    if(pesel.back()%2==0){  //sprawdza parzystosc przedostatniego charakteru pesel
    cout<<"Twoja plec to kobieta";
    }else{
    cout<<"Twoja plec to mezczyzna";}
    break;

    case 5:
    system("cls");
    cout<<"Podaj PESEL: ";
    cin>>pesel;
    if(pesel.length() != 11){
        cout<<"Niepoprawny pesel";
        return 0;
    }
    int rok = stoi(pesel.substr(0,2));
    int plec = stoi(pesel.substr(9,1));
    int miesiac = stoi(pesel.substr(2,2));
    int rokUrodzenia;
    time_t t = time(NULL);
	tm* timePtr = localtime(&t);
    int obecnyRok = timePtr->tm_year + 1900;    //tworzy zmienna obecnyRok i nadaje jej obecny rok

    if(miesiac > 0 && miesiac <13){             //w zmiennej rok tworzy rok urodzenia w formacie YYYY (np. 1990, 2002)
        rok += 1900;
    }else if(miesiac>20 && miesiac <33){
        rok += 2000;
    }
    cout<<rok;

    if(rok+18 <= obecnyRok){
        if(plec%2==0){
            cout<<"Jestes pelnoletnia kobieta";
            }else{
                cout<<"Jestes pelnoletnim mezczyzna";
            }
    }else{
        if(plec%2==0){
            cout<<"Jestes niepelnoletnia kobieta";
            }else{
                cout<<"Jestes niepelnoletnim mezczyzna";
            }
    }

    }


    return 0;
}



