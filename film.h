#ifndef FILM_H
#define FILM_H
#include "video.h"
#include <iostream>

class Film : public Video
{
private:
    int nombreChapitres;
    int *tableau;
public:
    Film(){
        nombreChapitres = 0;
        tableau = nullptr;
    }
    // méthode de class on peut avoir acces au attributs privées
    Film(Film const& filmTocopy){
        nombreChapitres = filmTocopy.nombreChapitres;
        tableau = new int[nombreChapitres];
        for(int i = 0; i < nombreChapitres; i++)
        {
            tableau[i] = filmTocopy.tableau[i];
        }
    }

     ~Film() override {delete []tableau;}
    void setTableau(int _tableau[], int _nombreChapitre)
    {
        nombreChapitres = _nombreChapitre;
        int * newArray = new int[nombreChapitres];
        for(int i = 0; i < nombreChapitres; i++)
        {
            newArray[i] = _tableau[i];
        }
        tableau = newArray;
    }
    int getNombreChapitre() const {return  nombreChapitres;}
    int getTableauChapitre(int numChapitre) const {return tableau[numChapitre];}
    void show(ostream& s) const override
    {
        s << "Le nombre de chapitres est : " <<getNombreChapitre() << endl;
        for(int i = 0; i < nombreChapitres; i++)
        {
            s << "Le chapitre " << i << " est de duree " << getTableauChapitre(i) << endl;
        }
    }
};
#endif // FILM_H
