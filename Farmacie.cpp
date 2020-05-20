#include "Farmacie.h"
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
///Functii membru ale clasei Farmacie

Farmacie::Farmacie(int id): m_id(id)//partea default
{
   /// std::cout<<"Construiesc o farmacie cu urmatorul id: "<<id<<std::endl;
}

////copy constructor -> folosit pt initializarea obiectelor noi
Farmacie::Farmacie(const Farmacie &f): m_id(f.m_id)
{
  ///  std::cout<<"Am apelat copy constructor pt Farmacie"<<std::endl;
}

///operator= -> am folosit pentru a inlocui continutul unui obiect
Farmacie& Farmacie::operator= (const Farmacie &f)
{
    /// self-assignment guard
    if (this == &f)
        return *this;

    // do the copy
    m_id = f.m_id; // can handle self-assignment

    // return the existing object
   /// std::cout<<"Am apelat operator= pt Farmacie"<<std::endl;
    return *this;
}

///destructor
Farmacie::~Farmacie()
{
   /// std::cout<<"Distrug farmacia cu urmatorul id: "<<m_id<<std::endl;
}

///functie virtuala de afisare in supraclasa
void Farmacie::print()
{
    std::cout<<"Farmacie (clasa de baza) cu id-ul: "<<m_id<<std::endl;
}

///setter, getter
void Farmacie::SetIdFarmacie(int id)
{
    m_id = id;
}

int Farmacie::GetIdFarmacie() const
{
    return m_id;
}


std::ostream& operator<< (std::ostream &out, const Farmacie &f)
{
    out<<"Farmacia are id-ul: "<<f.m_id<<std::endl;
    return out;
}

std::istream& operator>> (std::istream &in, Farmacie &f)
{
    std::cout<<"Introduceti id-ul farmaciei:"<<std::endl;
    in >> f.m_id;
    return in;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
///Functii membru ale clasei FarmacieFizica
FarmacieFizica::FarmacieFizica(int id)
{
        Farmacie::SetIdFarmacie(id);
        m_nrAngajati = 0;
        m_denumire = "";
        m_profit = 0;
        std::cout<<"Construiesc farmacia fizica cu id-ul: "<<id<<std::endl;
}

///constructor cu parametri
FarmacieFizica::FarmacieFizica(int id, const std::string &denumire, int nrAngajati, int profit):m_denumire(denumire),
                                                                                                m_nrAngajati(nrAngajati),
                                                                                                m_profit(profit)
{
        Farmacie::SetIdFarmacie(id);
    ///    std::cout<<"Construiesc farmacia fizica cu id-ul "<<id<<" si numele "<<denumire<<std::endl;
}

///copy constructor
FarmacieFizica::FarmacieFizica(const FarmacieFizica &f)
{
        Farmacie::m_id = f.m_id;
        m_denumire = f.m_denumire;
        m_nrAngajati = f.m_nrAngajati;
        m_profit = f.m_profit;
        std::cout<<"Am apelat copy constructor pt FarmacieFizica"<<std::endl;
}

///operator=

FarmacieFizica& FarmacieFizica::operator= (const FarmacieFizica &f)
    {
    // self-assignment guard
    if (this == &f)
        return *this;

    // do the copy
    Farmacie::m_id = f.m_id; // can handle self-assignment
    m_denumire = f.m_denumire;
    m_nrAngajati = f.m_nrAngajati;
    m_profit = f.m_profit;
    // return the existing object
    std::cout<<"Am apelat assignment constructor pt FarmacieFizica"<<std::endl;
    return *this;
}

///destructor
FarmacieFizica::~FarmacieFizica()
{
   /// std::cout<<"Distrug farmacia fizica cu id-ul: "<<m_id<<std::endl;
}

///setter, getter
void FarmacieFizica::SetDenumire(const std::string &denumire)
{
    m_denumire = denumire;
}

void FarmacieFizica::SetNumarAngajati(int nrAngajati)
{
    m_nrAngajati = nrAngajati;
}

void FarmacieFizica::SetProfit (int profit)
{
    m_profit = profit;
}

int FarmacieFizica::GetNumarAngajati() const
{
    return m_nrAngajati;
}

int FarmacieFizica::GetProfit() const
{
    return m_profit;
}

const std::string& FarmacieFizica::GetDenumire() const
{
    return m_denumire;
}

///supraincarcare >>,<<
std::ostream& operator<< (std::ostream &out, const FarmacieFizica &f)
{
        out<<"Farmacia fizica are:"<<std::endl;
        out<<"-id-ul: "<<f.GetIdFarmacie()<<std::endl;
        out<<"-deunumirea: "<<f.m_denumire<<std::endl;
        out<<"-numarul de angajati:"<<f.m_nrAngajati<<std::endl;
        out<<"-profitul:"<<f.m_profit<<std::endl;
        return out;
}

std::istream& operator>> (std::istream &in, FarmacieFizica &f)
{
    std::cout<<"Introduceti pentru farmacia fizica urmatoarele:"<<std::endl;
    std::cout<<"Id-ul:"<<std::endl;
    int id;
    in>>id;
    f.SetIdFarmacie(id);
    std::cout<<"Denumirea:"<<std::endl;
    in>>f.m_denumire;
    std::cout<<"Numarul de angajati:"<<std::endl;
    in>>f.m_nrAngajati;
    std::cout<<"Profitul:"<<std::endl;
    in>>f.m_profit;
    std::cout<<std::endl;
    return in;
}

///functie virtuala de afisare
void FarmacieFizica::print()
{
    std::cout<<"Farmacie fizica (clasa derivata)"<<std::endl;
    std::cout<<*this;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

///Functii membru ale clasei FarmacieOnline
///default constructor
FarmacieOnline::FarmacieOnline(int id)
{
    Farmacie::m_id = id;
    m_web = "";
    m_nrVizitatori = 0;
    m_discount = 0;
    m_dateFarmacie = make_tuple(m_web, m_nrVizitatori, m_discount);
    std::cout<<"Construiesc farmacia online cu id-ul: "<<Farmacie::m_id<<std::endl;
}
///constructor cu parametrii
FarmacieOnline::FarmacieOnline(int id, std::string web, int nrVizitatori, int discount):m_web(web),
                                                                                        m_nrVizitatori(nrVizitatori),
                                                                                        m_discount(discount)
{
    Farmacie::m_id = id;
    m_dateFarmacie = make_tuple(web, nrVizitatori, discount);
    //m_info.push_back(m_dateFarmacie);
    std::cout<<"Construiesc farmacia online cu id-ul "<<Farmacie::m_id<<"si adresa web "<<web<<std::endl;
}

///copy constructor
FarmacieOnline::FarmacieOnline(const FarmacieOnline &f)
{
        Farmacie::m_id = f.m_id;
        m_web = f.m_web;
        m_nrVizitatori = f.m_nrVizitatori;
        m_discount = f.m_discount;
        m_dateFarmacie = make_tuple(f.m_web, f.m_nrVizitatori, f.m_discount);
        //m_info.push_back(m_dateFarmacie);
        std::cout<<"Am apelat copy constructor pt FarmacieOnline"<<std::endl;
}
///operator=
FarmacieOnline& FarmacieOnline::operator= (const FarmacieOnline &f)
{
    // self-assignment guard
    if (this == &f)
        return *this;

    //do the copy
    Farmacie::m_id = f.m_id; // can handle self-assignment
    m_web = f.m_web;
    m_nrVizitatori = f.m_nrVizitatori;
    m_discount = f.m_discount;
    m_dateFarmacie = make_tuple(f.m_web, f.m_nrVizitatori, f.m_discount);
    //do the copy in the data structure

    for (unsigned int i = 0; i<m_info.size(); i++)
        if (m_info[i] == f.m_dateFarmacie)
        {
            m_info[i] = f.m_dateFarmacie;
            break;
        }

    // return the existing object
    std::cout<<"Am apelat operator= pentru FarmacieOnline"<<std::endl;
    return *this;
}

///destructor
FarmacieOnline::~FarmacieOnline()
{
    //Stergem obiectul si din vector!
    std::cout<<"Distrugem farmacia online cu id-ul:"<<Farmacie::m_id<<std::endl;
    m_info.erase(std::find(m_info.begin(), m_info.end(), this->m_dateFarmacie));
}

///functie care afiseaza toate farmaciile online
void FarmacieOnline::ShowAllFarmaciiOnline()
{
         std::cout<<"Lista tuturor farmaciilor online"<<std::endl;
         for (m_vec::const_iterator i = m_info.begin(); i != m_info.end(); i++)
        {
            std::cout<<"Adresa web este: "<<std::get<0>(*i)<<std::endl;
            std::cout<<"Numarul de vizitatori este: "<<std::get<1>(*i)<<std::endl;
            std::cout<<"Discount-ul este: "<<std::get<2>(*i)<<std::endl;
            std::cout<<std::endl;
        }
}
///functie care adauga o farmacie in vector
void FarmacieOnline::addFarmacieOnline(FarmacieOnline &f)
{
    m_info.push_back(f.m_dateFarmacie);
}

///supraincarcare operatori
bool operator== (const FarmacieOnline &f1, const FarmacieOnline &f2)
{
    if (f1.GetIdFarmacie()==f2.GetIdFarmacie() && f1.m_dateFarmacie == f2.m_dateFarmacie)
        return true;
    return false;
}

std::ostream& operator<< (std::ostream &out, const FarmacieOnline &f)
{
    out<<"Farmacia online are:"<<std::endl;
    out<<"-id-ul: "<<f.GetIdFarmacie()<<std::endl;
    out<<"-adresa web: "<<f.m_web<<std::endl;
    out<<"-numarul de vizitatori:"<<f.m_nrVizitatori<<std::endl;
    out<<"-discout-ul:"<<f.m_discount<<std::endl;
    return out;
}

std::istream& operator>> (std::istream &in, FarmacieOnline &f)
{
    std::cout<<"Introduceti pentru farmacia online urmatoarele:"<<std::endl;
    std::cout<<"Id-ul:"<<std::endl;
    int id;
    in>>id;
    f.SetIdFarmacie(id);
    std::cout<<"Adresa web:"<<std::endl;
    in>>f.m_web;
    std::cout<<"Numarul de vizitatori:"<<std::endl;
    in>>f.m_nrVizitatori;
    std::cout<<"Discount-ul:"<<std::endl;
    in>>f.m_discount;

    f.m_dateFarmacie = make_tuple(f.m_web, f.m_nrVizitatori, f.m_discount);
    return in;

}

///functie de afisare
void FarmacieOnline::print()
{
        std::cout<<"Farmacie online (clasa derivata)"<<std::endl;
        std::cout<<*this;
}

///instantierea vectorului
std::vector<std::tuple<std::string,int,int>> FarmacieOnline::m_info;
