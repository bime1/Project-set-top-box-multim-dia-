#ifndef GROUPE_H
#define GROUPE_H
#include "multimedia.h"
#include <list>
#include <iterator>
using namespace std;

class Groupe
{
private:
    list < multimedia> * liste ;
    string nameListe;
public:
    Groupe() {
        nameListe = "None";
        liste = new list<multimedia>() ;
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
            it.show(s);
        }
    }

    void addBack(multimedia & mlt){
        liste->push_back(mlt);
    }
    void addFront(multimedia & mlt){
        liste->push_front(mlt);
    }

    void removeFromListe(multimedia & mlt)
    {
        liste->remove(mlt);
    }
};
#endif // GROUPE_H
