#ifndef TABLE_H
#define TABLE_H
#include <string>
#include <map>
#include "multimedia.h"
#include "groupe.h"
#include <memory>
#include "photo.h"
#include "video.h"
#include "film.h"
#include <iostream>
#include "tcpserver.h"

using namespace std;
using namespace cppu;


class table
{

private:
    map <string ,shared_ptr <multimedia>> mapMultimedia;
    map <string , shared_ptr <Groupe>> mapGroupe;
public:
    table();

    shared_ptr <Photo> createPhoto(double latitude, double longitude,
                                   string path, string filename);
    shared_ptr <Video> createVideo(double duree, string path,
                                   string filename);
    shared_ptr <Film> createFilm(double duree,
                                 string path, string filename);
    shared_ptr <Groupe> createGroupe(string nameGroupe);

    shared_ptr <Groupe> finGroupe(string name);
    shared_ptr <multimedia> findMultimedia(string name);

    void show(string name, ostream& s);
    void jouer(string name, ostream& s);
    bool processRequest(TCPConnection& cnx, const string& request, string& response);
};

#endif // TABLE_H
