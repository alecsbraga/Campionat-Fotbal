#include <iostream>
#include <cstdlib>

using namespace std;

class Echipa
{
    string nume_echipa;
    int nr_partide_castigate, nr_partide_egale, nr_partide_pierdute;

public:

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

    void afisare_date() const
    {
        cout<<nume_echipa<<" "<<nr_partide_castigate+nr_partide_egale+nr_partide_pierdute<<" "<<nr_partide_castigate<<" "<<nr_partide_egale<<" "<<nr_partide_pierdute<<" "<<nr_partide_castigate*3+nr_partide_egale<<'\n';
    }

    void echipa_nume() const
    {
        cout<<nume_echipa;
    }

    Echipa(const string &nume_echipa = "noname", int nr_partide_castigate = 0, int nr_partide_egale = 0, int nr_partide_pierdute = 0)
        :nume_echipa{nume_echipa},
         nr_partide_castigate{nr_partide_castigate},
         nr_partide_egale{nr_partide_egale},
         nr_partide_pierdute{nr_partide_pierdute}
    {

    }

    Echipa(Echipa &echipa)
        :nume_echipa{echipa.nume_echipa},
         nr_partide_castigate{echipa.nr_partide_castigate},
         nr_partide_egale{echipa.nr_partide_egale},
         nr_partide_pierdute{echipa.nr_partide_pierdute}
    {

    }

    Echipa& operator=(const Echipa &echipa)
    {
        nume_echipa=echipa.nume_echipa;
        nr_partide_castigate=echipa.nr_partide_castigate;
        nr_partide_egale=echipa.nr_partide_egale;
        nr_partide_pierdute=echipa.nr_partide_pierdute;
        return *this;
    }

    ~Echipa();
};
Echipa::~Echipa()
{
    //  cout<<'\n'<<"Gata cu echipa "<<nume_echipa<<'\n';
}

class Patron
{
    const string nume_patron;
    Echipa echipa;
public:
    void afisare_date()
    {
        cout<<"Patron: "<<nume_patron<<" "<<", club: ";
        echipa.afisare_date();
    }
    Patron(const string &nume_patron, Echipa &echipa)
        :nume_patron{nume_patron},
         echipa{echipa}
    {
        afisare_date();
    }
    ~Patron();

};

Patron::~Patron()
{
    // cout<<"Gata cu patronul "<<nume_patron<<endl;
}

class Stadion
{
    const string nume_stadion;
    Echipa echipa;

public:
    void afisare_date()
    {
        cout<<"Stadion: "<<nume_stadion<<" Gazda: "<<endl;
        echipa.afisare_date();

    }

    Stadion(const string &nume_stadion, Echipa &echipa)
        :nume_stadion{nume_stadion},
         echipa{echipa}
    {
        afisare_date();
    }

    ~Stadion();

};

Stadion::~Stadion()
{
    // cout<<"Gata cu stadionul " << nume_stadion;
}

void cine_a_castigat(Echipa &castigatoare, Echipa &pierzatoare, bool remiza)
{
    cout<<"In urma meciului dintre " ;
    castigatoare.echipa_nume();
    cout<<" si ";
    pierzatoare.echipa_nume();
    if(remiza == false)
    {
        cout<<", a castigat ";
        castigatoare.echipa_nume();
    }
    else
    {

        cout<<", s-a terminat egal";
    }
    cout<<endl<<"Datele sunt urmatoarele:"<<endl;
    castigatoare.afisare_date();
    pierzatoare.afisare_date();

}
class Meci
{
    Echipa echipa_1;
    Echipa echipa_2;
public:

    Meci(Echipa &echipa_1, Echipa &echipa_2)
        :echipa_1{echipa_1},
         echipa_2{echipa_2}
    {

    }

    void joaca(int &v, int &e, int&i)
    {

        bool remiza;
        int castiga= 1 + (rand() % ( 3 - 1 + 1 ) );
        cout<<castiga<<endl;
        if(castiga == 1)
        {
            remiza= false;
            echipa_1.a_castigat_un_meci();
            echipa_2.a_pierdut_un_meci();
            cine_a_castigat(echipa_1, echipa_2, remiza);
            ++v;

        }
        else if(castiga == 2)
        {
            remiza= true;
            echipa_1.a_facut_egal();
            echipa_2.a_facut_egal();
            cine_a_castigat(echipa_1, echipa_2, remiza);
            ++e;

        }
        else
        {
            remiza= false;
            echipa_2.a_castigat_un_meci();
            echipa_1.a_pierdut_un_meci();
            cine_a_castigat(echipa_2, echipa_1, remiza);
            ++i;
        }

    }
    ~Meci();
};

Meci::~Meci()
{

}

int main()
{
    Echipa echipa_1("FCSB", 4, 1);
    Echipa echipa_2("FC Dinamo Bucuresti",2, 2, 1);
    Echipa echipa_3("CFR Cluj",3,1,1);
    echipa_1.afisare_date();
    echipa_2.afisare_date();
    echipa_3.afisare_date();
    Patron patron_1("Gigi Becali", echipa_1);
    Patron patron_2("Pablo Cortacero", echipa_2);
    Stadion stadion_1("Ghencea",echipa_1);
    Stadion stadion_2("Stefan Cel Mare",echipa_2);
    Meci meci_1(echipa_1,echipa_2);
    Meci meci_2(echipa_2,echipa_3);
    Meci meci_3(echipa_1,echipa_3);
    int v,e,i;
    v = i = e = 0;
    while(1)
    {
        meci_1.joaca(v,e,i);
        meci_2.joaca(v,e,i);
        meci_3.joaca(v,e,i);
        cout<<endl;
        if(v == e && v == i)
            break;
        else
        {
            v = e = i= 0;
        }
    }
    return 0;
}
