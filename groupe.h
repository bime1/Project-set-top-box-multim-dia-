#ifndef GROUPE_H
#define GROUPE_H
#include "multimedia.h"
#include <list>
#include <iterator>
#include <memory>
using namespace std;
using PtrSmart = std::shared_ptr<multimedia>;



class Groupe : public list<shared_ptr<multimedia>>
{
private:

    string nameListe;
public:
    Groupe(string _name) {
        nameListe = _name;
    }

    string getNameListe() const {
        return nameListe;
    }

     ~Groupe(){
        for(auto it = this->begin() ; it != this->end(); ++it)
        {
            it->reset();
        }
    }
    void show(ostream & s) const
    {
        for(auto it = this->begin(); it != this->end(); ++it  )
        {
            (*it)->show(s);
        }
    }


};
#endif // GROUPE_H
