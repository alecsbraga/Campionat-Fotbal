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
#include "Cupa.h"
#include "CupaRomaniei.h"

using namespace std;

int main()
{
    shared_ptr<Echipa>echipa_1(make_shared<Echipa>("FCSB", 4, 1));
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
    //Campionat *campionat_liga_1 = new Liga1;
    auto campionat_liga_1=Liga1::get_liga1();
    //Campionat *campionat_liga_2 = new Liga2;
    auto campionat_liga_2=Liga2::get_liga2();
    Cupa <CupaRomaniei> cupa;
    ifstream f;
    try
    {
        f.open("Echipe.in");
        f>>*campionat_liga_1;
        f>>*campionat_liga_2;
        f>>cupa;
        try
        {
            campionat_liga_1->joaca();
            campionat_liga_2->joaca();
            cupa.joaca();

        }
        catch(const runtime_error& e)
        {
            cout<<e.what()<<endl;
        }
        campionat_liga_1->ordoneaza();
        campionat_liga_2->ordoneaza();



        cout<<*campionat_liga_1;
        campionat_liga_1->cine_a_castigat();

        cout<<"------------------------------------------------"<<endl;

        cout<<*campionat_liga_2;
        campionat_liga_2->cine_a_castigat();

        cout<<"------------------------------------------------"<<endl;

        cupa.data_jucata();

        cout<<cupa;

        afisare(cupa);

        cout<<endl<<"------------------------------------------------"<<endl;

    }
    catch (const ifstream::failure& e)
    {
        cout<<"Execeptie deschidere/citire fisier";
    }
    f.close();
    return 0;
}
