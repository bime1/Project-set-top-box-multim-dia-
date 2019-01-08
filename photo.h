#ifndef PHOTO_H
#define PHOTO_H
#include "multimedia.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;


class Photo : public multimedia
{

private:
    double latitude;
    double longitude;
public:
    ~Photo() override{}
    Photo() {latitude = 0; longitude = 0;}
    Photo(double _latitude, double _longitude,
          string _path, string _filename)
        :multimedia (_path,_filename) {
        latitude = _latitude;
        longitude = _longitude;
    }
    void setLatitude(double _latitude)  {latitude = _latitude;}
    void setLongitude(double _longitude) {longitude = _longitude;}
    double getLatitude() const {return latitude;}
    double getLongitude() const {return longitude;}
    void show(ostream& s) const override { s << getLatitude() << getLongitude() << endl;}

    void jouer() const override
    {
        //string pathComplet = getPath() + "/"+ getNameFile();
        //string commande = "image " + pathComplet + " &";
        //system(commande.c_str());
        cout << "Je suis une photo" << endl;

    }

};




#endif // PHOTO_H
