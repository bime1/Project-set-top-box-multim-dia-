#include "table.h"
#include <string>
table::table()
{

}

shared_ptr <Photo> table::createPhoto(double latitude, double longitude,
                                      string path, string filename){
    shared_ptr <Photo> photo_tmp(new Photo(latitude, longitude, path, filename));
    mapMultimedia[filename] = photo_tmp;
    return photo_tmp;
}

shared_ptr <Video> table::createVideo(double duree, string path,
                                      string filename){
    shared_ptr <Video> video_tmp(new Video(duree , path, filename));
    mapMultimedia[filename] = video_tmp;
    return video_tmp;

}

shared_ptr <Film> table::createFilm(double duree,
                                    string path , string filename){
    shared_ptr <Film> film_tmp(new Film(duree, path ,filename));
    mapMultimedia[filename] = film_tmp;
    return film_tmp;
}

shared_ptr <Groupe> table::createGroupe(string name){
    shared_ptr <Groupe> groupe_tmp(new Groupe(name));
    mapGroupe[name] = groupe_tmp;
    return  groupe_tmp;
}

shared_ptr <multimedia> table::findMultimedia(string name){
    auto it = mapMultimedia.find(name);
    if (it != mapMultimedia.end()){
        return it->second;
    }
    else
        return nullptr;
}

shared_ptr <Groupe> table::finGroupe(string name){
    auto it = mapGroupe.find(name);
    if(it != mapGroupe.end()){
        return it->second;
    }
    else
        return nullptr;
}

void table::show(string name, ostream& s){
    auto it = findMultimedia(name);
    if (it == nullptr){
        s << "Erreur le fichier n'existe pas" << endl;
        return;
    }
    else
        it->show(s);
}

void table::jouer(string name, ostream& s){
    auto it = findMultimedia(name);
    if (it == nullptr)
    {
        s << "Erreur le fichier n'existe pas" << endl;
    }
    else
        it->jouer();
}
