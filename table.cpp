#include "table.h"
#include <string>
#include "tcpserver.h"
#include "ostream"

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




bool table::processRequest(TCPConnection& cnx, const string& request, string& response) {

    cerr << "\nDemande: '" << request << "'" << endl;

    stringstream stream;
    stringstream response_stream;

    stream << request;

    string operation;
    string target;

    stream >> operation >> target;

    TCPLock lock(cnx);

    if(operation == "Recherche") {
        shared_ptr<multimedia> result = findMultimedia(target);
        if(result == nullptr) {
            response = "Aucun multimedia trouvé de ce nom : " + target + "||";
        }
        else {
            result->show(response_stream);
            response = response_stream.str();
        }
    }
    else if(operation == "Recherche Groupe") {
        shared_ptr<Groupe> result = finGroupe(target);
        if(result == nullptr) {
            response = "Aucun groupe trouvé avec ce nom : " + target + "||";
        }
        else {
            result->show(response_stream);
            response = response_stream.str();
        }
    }
    else if(operation == "Jouer") {
        shared_ptr<multimedia> result = findMultimedia(target);
        if(result == nullptr) {
            response = "Aucune multimédia avec ce nom " + target + "||";
        }
        else {
            result->jouer();
            response = "Execution " + target + " sur le serveur ! ||";
        }
    }
    else if(operation == "Quitter") {
        response = "By !";
        return false;
    }
    else {
        response = "Entrer une nouvelle requet";
    }
    cerr << "reponse: " << response << endl;


    return true;
}
