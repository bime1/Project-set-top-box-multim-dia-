#ifndef GROUPE_H
#define GROUPE_H
#include "multimedia.h"
#include <list>
#include <iterator>
template<typename T>
class Groupe : public multimedia
{

private:
    list < T > * liste ;
    string nameListe;
public:
    Groupe() {
        nameListe = "None";
        liste = nullptr;
    }

    string getNameListe(void) const {
        return nameListe;
    }

    virtual ~Groupe();
    void show(ostream & s) const;
};
#endif // GROUPE_H
