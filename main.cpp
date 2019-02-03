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
#include "tcpserver.h"
#include "table.h"

using PtrSmart = std::shared_ptr<multimedia>;
using namespace std;
using namespace cppu;


const int PORT = 3331;


int main(int argc, const char* argv[])
{
    shared_ptr<TCPServer> server(new TCPServer());


    shared_ptr<table> table_client(new table());


    shared_ptr<Video> video = table_client->createVideo(30, "media/my_vid.wma", "video");
    shared_ptr<Photo> photo = table_client->createPhoto(32, 98, "media/my_img.png", "photo");
    shared_ptr<Groupe> groupe = table_client->createGroupe("group");

    groupe->push_back(video);
    groupe->push_back(photo);

    server->setCallback(*table_client, &table::processRequest);

    cout << "Démarage du sérveur avec le port " << PORT << endl;
    int status = server->run(PORT);

    if (status < 0) {
      cerr << "Le serveur ne peut pas démarrer " << PORT << endl;
      return 1;
    }






#ifdef OLD_VERSION

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
     * La photo reste tant qu'elle est dans un groupe, si on supprime un groupe
     * Les objets qui y sont ne seront pas supprimé.
    */

    /*
    Groupe * groupe_1 = new Groupe("groupe_test_1");
    shared_ptr<Photo> photo_1(new Photo(15, 17, "/Desktop", "image_test"));
    shared_ptr<Video> video_1(new Video(17, "Desktop", "video_test"));
    groupe_1->push_back(video_1);
    groupe_1->push_front(photo_1);

    Groupe * groupe_2 = new Groupe("groupe_test_2");
    groupe_2->push_back(photo_1);

    groupe_1->show(cout);
    delete groupe_1;
    cout << "apres suppression du groupe 1" << endl ;
    photo_1->show(cout);
    photo_1.reset();
    cout << "Affichage du second groupe " << endl ;
    groupe_2->show(cout);
    */
#endif


    return 0;
}
