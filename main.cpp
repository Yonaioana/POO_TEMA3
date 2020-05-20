#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <tuple>
#include <cassert>
#include "Gestionar.h"
#include "Gestionar.cpp"
#include "Farmacie.h"
#include "Farmacie.cpp"

int main()
{   using namespace std;
int comanda;
cin>>comanda;
switch(comanda){
case 1:{

    //Testare -> clasa farmacie

    try
    {int numarid;
    cout<<"Introduceti id u farmaciei: ";
    cin>>numarid;
    if(numarid<0)
        throw 0;
    else cout<<"id ul este:"<<numarid;}
    catch(int numarid)
    {
        cout<<numarid<<" repetati citirea!\n";
        cin>>numarid;if(numarid<0)
        throw 0;
    else cout<<"id ul este:"<<numarid;
    }

    cout<<"\n";
    Farmacie f1,g1;//default for avea id-ul 0, dar il putem modifica
    cin>>f1;
    g1 = f1;//assignment constructor aici ->pt obiecte care deja exista
    Farmacie h1 = g1;//copy constructor aici -> doar pt obiecte noi
    cout<<f1<<g1<<h1;

    //Am alocat dinamic n obiecte Farmacie
    Farmacie *foo1;
    int len1;
    cin>>len1;
    foo1 = new Farmacie[len1];
    for(int i=0;i<len1;i++)
        cin>>foo1[i];
    for(int i=0;i<len1;i++)
        cout<<foo1[i];
    delete[] foo1;
}
    break;
   case 2:{
    //Testare->clasa FarmacieFizica

    FarmacieFizica f2,g2;//default vor avea id-ul 0
    FarmacieFizica h2(10,"catena",10,45);//constructor parametrizat
    FarmacieFizica n2 = h2; //copy constructor
    f2=h2;//assignment constructor
    cin>>g2;
    cout<<f2<<g2<<h2<<n2;

    //Am alocat dinamic n obiecte de tipul FarmacieFizica
    FarmacieFizica *foo2;
    int len2;
    cin>>len2;
    foo2 = new FarmacieFizica[len2];
    for(int i=0;i<len2;i++)
        cin>>foo2[i];
    for(int i=0;i<len2;i++)
        cout<<foo2[i];
    delete[] foo2;
   }
   break;
case 3:{

    //Testare -> clasa Farmacie Online



    FarmacieOnline f3;//default are id-ul 0
    FarmacieOnline g3(5,"www",10500,2), n3(7,"wwwww", 21400,3);//constructor parametrizat
    FarmacieOnline h3=g3;//copy constructor

   FarmacieOnline::addFarmacieOnline(f3);
    FarmacieOnline::ShowAllFarmaciiOnline();
    FarmacieOnline::addFarmacieOnline(h3);
    FarmacieOnline::ShowAllFarmaciiOnline();

    //Am alocat dinamic n obiecte de tipul FarmacieOnline
   FarmacieOnline *foo3;
    int len3;
    cin>>len3;
    foo3 = new FarmacieOnline[len3];
    for(int i=0;i<len3;i++)
        cin>>foo3[i];
    for(int i=0;i<len3;i++)
        cout<<foo3[i];
    delete[] foo3;
}
    break;
case 4:{
    //Testare -> functiile virtuale de afis
    Farmacie f4(10);
    FarmacieFizica ff4(15,"dr max",4,12000);
    FarmacieOnline fo4(20,"www.catena.ro",34000,2);
    f4.print();
    ff4.print();
    fo4.print();}
    break;
  case 5: { //Testare -> gestionare farmacii
    GestionareFarmacii<Farmacie> Temp;
    Farmacie f5(10),g5(11),h5(13);
    Temp.addFarmacie(f5);
    Temp.addFarmacie(g5);
    Temp.addFarmacie(h5);
    Temp.SetIdLant(205);
    Temp.afiseazaFarmacii();}
    break;
  default:
    cout<<"Nu ati introdus un nr intre 1 si 5. ";
}
 Farmacie *obj1 = new FarmacieFizica;
    FarmacieFizica *obj2 = dynamic_cast<FarmacieFizica*>(obj1);
    if(obj2!= NULL)
        cout << "Se poate";
    else
        cout << "Nu se poate converti pointer baza in pointer derivata";
    getchar();
    return 0;

}
