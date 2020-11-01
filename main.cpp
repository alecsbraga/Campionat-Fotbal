#include <iostream>
#include <cstdlib>

using namespace std;

class Echipa
{
    string nume_echipa;
    int nr_partide_castigate, nr_partide_egale, nr_partide_pierdute;

public:
    void partide()
    {
        cout<<nr_partide_castigate+nr_partide_egale+nr_partide_pierdute;
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
    void punctaj_calculat()
    {
        cout<<nr_partide_castigate*3+nr_partide_egale;

    }
    void afisare_date()
    {
        cout<<nume_echipa<<" ";
        partide();
        cout<<" "<<nr_partide_castigate<<" "<<nr_partide_egale<<" "<<nr_partide_pierdute<<" ";
        punctaj_calculat();
        cout<<'\n';
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
    Echipa(string nume_echipa = "noname", int nr_partide_castigate = 0, int nr_partide_egale = 0, int nr_partide_pierdute = 0);

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
Echipa::Echipa(string nume_echipa, int nr_partide_castigate, int nr_partide_egale, int nr_partide_pierdute)
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
}

class Meci{
    Echipa echipa_1;
    Echipa echipa_2;
    public:
    void cine_a_castigat(Echipa &castigatorea, Echipa &invinsa, bool remiza)
    {
        if(remiza == false)
            cout<<"In urma meciului dintre " <<castigatorea.get_nume()<<" si "<< invinsa.get_nume()<<", a castigat "<< castigatorea.get_nume();
        else
            cout<<cout<<"In urma meciului dintre " <<castigatorea.get_nume()<<" si "<< invinsa.get_nume()<<", s-a terminat egal";
    }

    void meci(Echipa &echipa_1, Echipa &echipa_2)
    {
        int castiga= 1 + (rand() % ( 3 - 1 + 1 ) );
        static bool remiza;
        if(castiga == 1)
        {
            remiza= false;
            cine_a_castigat(echipa_1, echipa_2, remiza);
            echipa_2.a_pierdut_un_meci();
            cout<<endl<<"Datele sunt urmatoarele:"<<endl;
            echipa_1.afisare_date();
            echipa_2.afisare_date();

        }
        else if(castiga == 2)
        {
            remiza= true;
            cine_a_castigat(echipa_1, echipa_2, remiza);
            echipa_1.a_facut_egal();
            echipa_2.a_facut_egal();
            cout<<endl<<"Datele sunt urmatoarele:"<<endl;
            echipa_1.afisare_date();
            echipa_2.afisare_date();
        }
        else
        {
            remiza= false;
            cine_a_castigat(echipa_2, echipa_1, remiza);
            echipa_2.a_castigat_un_meci();
            echipa_1.a_pierdut_un_meci();
            cout<<endl<<"Datele sunt urmatoarele:"<<endl;
            echipa_1.afisare_date();
            echipa_2.afisare_date();
        }

    }
};

 main()
{
    Echipa echipa_1("FCSB", 4, 1);
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
