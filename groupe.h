#ifndef GROUPE_H
#define GROUPE_H
#include "multimedia.h"
#include <list>
#include <iterator>
template<typename T>
class Groupe : public multimedia
{

private:
    list < T > liste ;
    string nameListe;
public:
    Groupe() {}
    virtual ~Groupe();
    void show(ostream & s) const;
};
#endif // GROUPE_H
