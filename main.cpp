#include <iostream>
#include "Echipa.h"
#include "Patron.h"
#include "Stadion.h"
#include "Meci.h"
#include <vector>
#include <fstream>
#include "Campionat.h"
#include "Liga1.h"
#include "Liga2.h"
#include <typeinfo>
#include <memory>

using namespace std;

int main()
{
    shared_ptr<Echipa>echipa_1(new Echipa("FCSB", 4, 1));
    try
    {
        Echipa echipa_2("FC Dinamo Bucuresti",2, 2, 1);
        cout<<echipa_2;
    }
    catch(const bad_typeid& e)
    {
        cout << e.what() << '\n';
    }
    cout<<*echipa_1;
    Patron patron_1("Gigi Becali", *echipa_1);
    Stadion stadion_1("Ghencea", *echipa_1);
    Campionat *campionat_liga_1 = new Liga1;
    Campionat *campionat_liga_2 = new Liga2;
    ifstream f;
    try
    {
        f.open("Echipe.in");

        f>>*campionat_liga_1;
        f>>*campionat_liga_2;
        ///---------------------------------------------------------------------------------------------
        try
        {
            campionat_liga_1->joaca();
        }
        catch(const runtime_error& e)
        {
            cout<<e.what()<<endl;
        }
        try
        {
            campionat_liga_1->ordoneaza();
        }
        catch(const runtime_error& e)
        {
            cout<<e.what()<<endl;
        }
        ///-----------------------------------------------------------------------------------------------
        try
        {
            campionat_liga_2->joaca();
        }
        catch(const runtime_error& e)
        {
            cout<<e.what()<<endl;
        }
        try
        {
            campionat_liga_2->ordoneaza();
        }
        catch(const runtime_error& e)
        {
            cout<<e.what()<<endl;
        }
        ///-------------------------------------------------------------------------------------------------
        cout<<*campionat_liga_1;
        campionat_liga_1->cine_a_castigat();
        cout<<"------------------------------------------------"<<endl;
        cout<<*campionat_liga_2;
        campionat_liga_2->cine_a_castigat();
        delete campionat_liga_1;
        delete campionat_liga_2;


    }
    catch (const ifstream::failure& e)
    {
        cout<<"Execeptie deschidere/citire fisier";
    }
    f.close();
    return 0;
}
