#include <iostream>
#include <cstdlib>

using namespace std;

class Echipa
{
    string nume_echipa;
    int nr_partide_castigate, nr_partide_egale, nr_partide_pierdute;

public:
    int* nr_partide()
    {
        int *nr_partidetotal;
        nr_partidetotal=new int;
        *nr_partidetotal=nr_partide_castigate+nr_partide_egale+nr_partide_pierdute;
        return nr_partidetotal;
        delete nr_partidetotal;
    }

    void a_castigat_un_meci()
    {
        nr_partide_castigate++;
    }

    void a_pierdut_un_meci()
    {
        nr_partide_pierdute++;
    }
    void a_facut_egal()
    {
        nr_partide_egale++;
    }
    int* punctaj_calculat()
    {
        int *puntajtotal;
        puntajtotal=new int;
        *puntajtotal=nr_partide_castigate*3+nr_partide_egale;
        return puntajtotal;
        delete puntajtotal;

    }
    void afisare_date()
    {
        cout<<nume_echipa<<" "<<*nr_partide()<<" "<<nr_partide_castigate<<" "<<nr_partide_egale<<" "<<nr_partide_pierdute<<" "<<*punctaj_calculat()<<'\n';
    }
    string get_nume()
    {
        return nume_echipa;
    }
    ///Am redus numarul de constructori la unul, folosind parametri impliciti
    /*
     Echipa();

    Echipa(string);

    Echipa(string, int);

    Echipa(string, int, int);

    Echipa(string, int, int, int);
     */
    Echipa(string nume_echipa = "noname", int nr_partide_castigate = 0, int nr_partide_egale = 0, int nr_partide_pierdute=0);

    Echipa(Echipa &);

    ~Echipa();
};
/*
Echipa::Echipa()
{
    nume_echipa = "noname";
    nr_partide = 0;
    nr_partide_castigate = 0;
    nr_partide_egale = 0;
    nr_partide_pierdute = 0;
    punctaj_calculat(nr_partide_castigate,nr_partide_egale);
    afisare_date();

}

Echipa::Echipa(string nume_echipa)
{
    this->nume_echipa = nume_echipa;
    nr_partide = 0;
    nr_partide_castigate = 0;
    nr_partide_egale = 0;
    nr_partide_pierdute = 0;
    punctaj_calculat(nr_partide_castigate,nr_partide_egale);
    afisare_date();
}

Echipa::Echipa(string nume_echipa, int nr_partide)
{
    this->nume_echipa = nume_echipa;
    this->nr_partide = nr_partide;
    nr_partide_castigate = 0;
    nr_partide_egale = 0;
    nr_partide_pierdute = 0;
    punctaj_calculat(nr_partide_castigate,nr_partide_egale);
    afisare_date();
}

Echipa::Echipa(string nume_echipa, int nr_partide, int nr_partide_castigate)
{
    this->nume_echipa = nume_echipa;
    this->nr_partide = nr_partide;
    this->nr_partide_castigate = nr_partide_castigate;
    nr_partide_egale = 0;
    nr_partide_pierdute = 0;
    punctaj_calculat(nr_partide_castigate,nr_partide_egale);
    afisare_date();
}

Echipa::Echipa(string nume_echipa, int nr_partide, int nr_partide_castigate, int nr_partide_egale)
{
    this->nume_echipa = nume_echipa;
    this->nr_partide = nr_partide;
    this->nr_partide_castigate = nr_partide_castigate;
    this->nr_partide_egale = nr_partide_egale;
    nr_partide_pierdute = 0;
    punctaj_calculat(nr_partide_castigate,nr_partide_egale);
    afisare_date();
}
*/
Echipa::Echipa(string nume_echipa, int nr_partide_castigate, int nr_partide_egale,int nr_partide_pierdute)
{
    this->nume_echipa = nume_echipa;
    this->nr_partide_castigate = nr_partide_castigate;
    this->nr_partide_egale = nr_partide_egale;
    this->nr_partide_pierdute = nr_partide_pierdute;


}

Echipa::Echipa(Echipa &echipa)
{
    this->nume_echipa = echipa.nume_echipa;
    this->nr_partide_castigate = echipa.nr_partide_castigate;
    this->nr_partide_egale = echipa.nr_partide_egale;
    this->nr_partide_pierdute = echipa.nr_partide_pierdute;

}

Echipa::~Echipa()
{
    //  cout<<'\n'<<"Gata cu echipa "<<nume_echipa<<'\n';
    delete nr_partide();
    delete punctaj_calculat();
}

class Patron
{
    string nume_patron;
    Echipa echipa;
public:
    void afisare_date()
    {
        cout<<"Patron: "<<nume_patron<<" "<<", club: ";
        echipa.afisare_date();
    }
    Patron(string nume_patron, Echipa echipa);
    ~Patron();

};

Patron::Patron(string nume_patron, Echipa echipa)
{
    this->nume_patron = nume_patron;
    this->echipa = echipa;
    afisare_date();
}

Patron::~Patron()
{
    // cout<<"Gata cu patronul "<<nume_patron<<endl;
    delete echipa.nr_partide();
    delete echipa.punctaj_calculat();
}

class Stadion
{
    string nume_stadion;
    Echipa echipa;

public:
    void afisare_date()
    {
        cout<<"Stadion: "<<nume_stadion<<" Gazda: ";
        echipa.afisare_date();

    }

    Stadion(string, Echipa);
    ~Stadion();

};

Stadion::Stadion(string nume_stadion,Echipa echipa)
{
    this->nume_stadion = nume_stadion;
    this->echipa=echipa;

}

Stadion::~Stadion()
{
    // cout<<"Gata cu stadionul " << nume_stadion;
    delete echipa.nr_partide();
    delete echipa.punctaj_calculat();
}

class Meci
{
    Echipa echipa_1;
    Echipa echipa_2;
public:
    void meci(Echipa &echipa_1, Echipa &echipa_2)
    {
        int castiga= 1 + (rand() % ( 3 - 1 + 1 ) );
        if(castiga == 1)
        {
            cout<<"In urma meciului dintre " <<echipa_1.get_nume()<<" si "<< echipa_2.get_nume()<<", a castigta "<< echipa_1.get_nume();
            echipa_1.a_castigat_un_meci();
            echipa_1.nr_partide();
            echipa_2.a_pierdut_un_meci();
            echipa_2.nr_partide();
            echipa_1.punctaj_calculat();
            cout<<endl<<"Datele sunt urmatoarele:"<<endl;
            echipa_1.afisare_date();
            echipa_2.afisare_date();

        }
        else if(castiga == 2)
        {
            cout<<"In urma meciului dintre " <<echipa_1.get_nume()<<" si "<< echipa_2.get_nume()<<", s-a terminat egal";
            echipa_1.a_facut_egal();
            echipa_2.a_facut_egal();
            echipa_1.nr_partide();
            echipa_1.nr_partide();
            echipa_1.punctaj_calculat();
            echipa_2.punctaj_calculat();
            cout<<endl<<"Datele sunt urmatoarele:"<<endl;
            echipa_1.afisare_date();
            echipa_2.afisare_date();
        }
        else
        {
            cout<<"In urma meciului dintre " <<echipa_1.get_nume()<<" si "<< echipa_2.get_nume()<<", a castigat "<< echipa_2.get_nume();
            echipa_2.a_castigat_un_meci();
            echipa_1.a_pierdut_un_meci();
            echipa_1.nr_partide();
            echipa_1.nr_partide();
            echipa_2.punctaj_calculat();
            cout<<endl<<"Datele sunt urmatoarele:"<<endl;
            echipa_1.afisare_date();
            echipa_2.afisare_date();
        }

    }
    ~Meci();
};

Meci::~Meci()
{
    delete echipa_1.nr_partide();
    delete echipa_1.punctaj_calculat();
    delete echipa_2.nr_partide();
    delete echipa_2.punctaj_calculat();
}

main()
{
    Echipa echipa_1("FCSB",4, 1);
    Echipa echipa_2("FC Dinamo Bucuresti",2, 2, 1);
    echipa_1.afisare_date();
    echipa_2.afisare_date();
    Patron patron_1("Gigi Becali", echipa_1);
    Patron patron_2("Pablo Cortacero", echipa_2);
    Stadion stadion_1("Ghencea",echipa_1);
    Stadion stadion_2("Stefan Cel Mare",echipa_2);
    Meci meci_1;
    meci_1.meci(echipa_1, echipa_2);
    return 0;
}
