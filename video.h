#ifndef VIDEO_H
#define VIDEO_H
#include "multimedia.h"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;


class Video : public multimedia
{


private:
    double duree;
public:
    Video() {duree = 0;}
    Video(double _duree, string _path, string _fileName): multimedia (_path, _fileName){
        duree = _duree;
    }
    void setDuree(double _duree) {duree = _duree;}
    double getDuree() const {return duree;}
    void show(ostream & s) const override { s << getDuree()<< endl;}

    void jouer() const override
    {
        //string pathComplet = getPath() + "/"+ getNameFile();
        //string commande = "mpv " + pathComplet + " &";
        //system(commande.c_str());
        cout << "Je suis une video" << endl;

    }


};









#endif // VIDEO_H
