//
// main.cpp
// Created on 21/10/2018
//
#include <list>
#include <iterator>
#include <iostream>
#include <string>
#include "multimedia.h"
#include "photo.h"
#include "video.h"
#include <vector>
#include "groupe.h"
#include "film.h"
#include <memory>

using PtrSmart = std::shared_ptr<multimedia>;
using namespace std;

int main(int argc, const char* argv[])
{
    /* test avant de rendre multimedia abstraite */


    /*
    multimedia * p = new multimedia("c/Desktop", "Info and math");
    p->show(cout);
    */


    /*Création du tableau multimedia */

    /*
    int longeurTableau= 2;
    vector <multimedia *> tableauMedia;
    tableauMedia.push_back(new Photo(5,5,"/Desktop","photo1"));
    tableauMedia.push_back(new Video(10,"Desktop","video1"));
    */


    //lire le tableau jouer
    /*
    for(int i = 0 ; i < longeurTableau; i ++)
    {
       tableauMedia[i]->show(cout);
       tableauMedia[i]->jouer();
    }
    */

    /* tests de la class film */
    /*
    Film * f = new Film();
    int _tableChapite[5] = {1,2,3,4,5};
    f->setTableau(_tableChapite , 5);
    f->show(cout);
    f->setDuree(10);
    f->setNameFile("My first video");
    f->setPath("/Desktop");

    Film * newFilm = new Film(*f);

    newFilm->show(cout);
    int newtableChapite[5] = {6,7,8,9,10};
    f->setTableau(newtableChapite, 5);
    cout << "Après modification de film " << endl;
    newFilm->show(cout);
    */

    /*test de la class groupe sans utilisation des smarts pointeurs   */

    /*
    Groupe * g1 = new Groupe("Mygroupe1");

    Photo * image = new Photo();
    image->setLatitude(17);
    image->setLongitude(17);
    image->setNameFile("Mon Image");

    Video * v = new Video();
    v->setDuree(18);
    v->setNameFile("Ma vidéo");

    Film * f1 = new Film();
    f1->setNameFile("My Film");
    int tableDureef1[5] = {1,2,3,4,5};
    f1->setTableau(tableDureef1,5);

    g1->addFront(image);
    g1->addBack(v);
    g1->addBack(f1);


    g1->show(cout);



    Groupe * g2 = new Groupe("Mygroupe2");

    Photo * image2 = new Photo();
    image2->setLatitude(20);
    image2->setLongitude(20);
    image2->setNameFile("Mon Image 2");

    g2->addFront(image2);
    g2->addBack(image);
    g2->addBack(v);
    g2->addBack(f1);


    g2->show(cout);
    */


    /* Tests avec utilisation des smarts pointeurs */

    shared_ptr<Groupe> groupeSmart(new Groupe("MySmartGroupe"));

    shared_ptr<Photo> ImageSmart(new Photo());
    ImageSmart->setLatitude(17);
    ImageSmart->setLongitude(17);
    ImageSmart->setNameFile("Mon Smart Image");

    shared_ptr<Video> VideosSmart(new Video());
    VideosSmart->setDuree(18);
    VideosSmart->setNameFile("Ma Smart vidéo");

    shared_ptr<Film> FilmSmart(new Film());
    FilmSmart->setNameFile("My Film");
    int tableDureefSmart[5] = {1,2,3,4,5};
    FilmSmart->setTableau(tableDureefSmart,5);

    /*Les élèments du gourpe 1*/

    groupeSmart->addFront(ImageSmart);
    groupeSmart->addBack(VideosSmart);
    //groupeSmart->addBack(FilmSmart);


//    shared_ptr<Groupe> groupeSmart2(new Groupe("MysecondeSmartGroupe"));

//    shared_ptr<Photo> ImageSmart2(new Photo());
//    ImageSmart2->setLatitude(16);
//    ImageSmart2->setLongitude(16);
//    ImageSmart2->setNameFile("Mon Smart Image numéro 2");

    /*Les élèments du gourpe 2*/

//    groupeSmart2->addFront(ImageSmart2);
//    groupeSmart2->addBack(VideosSmart);
//    groupeSmart2->addBack(FilmSmart);

    cout << "Le premier Groupe " << endl;
    groupeSmart->show(cout);
    //cout << "Le second groupe " << endl;
    //groupeSmart2->show(cout);

    cout << "Suppression des élèments" << endl;

    ImageSmart.reset();

    cout << "Après suppression :" << endl;
    groupeSmart->show(cout);

    return 0;
}
