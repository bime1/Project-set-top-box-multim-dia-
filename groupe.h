#ifndef GROUPE_H
#define GROUPE_H
#include "multimedia.h"
#include <list>
#include <iterator>
#include <memory>
using namespace std;
using PtrSmart = std::shared_ptr<multimedia>;



class Groupe
{
private:
    //list < multimedia * > * liste ;
    list <shared_ptr<multimedia>> *liste;

    string nameListe;
public:
    Groupe(string _name) {
        nameListe = _name;
        //liste = new list<multimedia *>() ;

    }

    string getNameListe() const {
        return nameListe;
    }

    virtual ~Groupe(){
        delete liste;
    }
    void show(ostream & s) const
    {
        for(auto const& it : *liste )
        {
            it->show(s);
        }
    }

    /* Avant l'utilisation des smart pointer  */
//    void addBack(multimedia * mlt){
//        liste->push_back( mlt);
//    }

    void addBack(PtrSmart mlt){
        liste->push_back( mlt);
    }


    void addFront(PtrSmart mlt){
        liste->push_front(mlt);
    }

    void removeFromListe(PtrSmart mlt)
    {
        liste->remove(mlt);
    }
};
#endif // GROUPE_H
