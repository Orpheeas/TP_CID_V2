#include <stdlib.h>
#include "Point.h"
#include <string> 
#define TAILLE 10

//PROTOTYPES
void afficheCID(CID tabCID[TAILLE]);
void modCID(CID tabCID[TAILLE]);
void ajouterCID(CID tabCID[TAILLE]);
void supprCID(CID tabCID[TAILLE]);
void modifstring(string& str_ref);

int main(){
	
	CID tabCID[TAILLE] = {};
	//Seul CID rentré de façon brut
	tabCID[0].ajouter("0", "Kretz", "Teo", "11 rue de l'anneau", "67100", "Strasbourg");
	
	char ask_user = ' ';
	string str_ref = "test pour le passage par referencement";

	while (ask_user != 'q') {
		cout<< "Que voulez-vous faire ?" << endl;
		cout << "Ajouter une carte (a)" << endl;
		cout << "Supprimer une carte (s)" << endl;
		cout << "Modifier une carte (m) "<< endl;
		cout << "Afficher une ou toutes les cartes (d)" << endl;
		cout << "Quitter le programme (q)" << endl;
		cout << "Modifiez la ligne juste en dessous(l)" << endl;
		cout << str_ref << endl;
		cin >> ask_user;
		if (ask_user == 'a') {
			ajouterCID(tabCID);
		}else if (ask_user == 's') {
			supprCID(tabCID);
		}
		else if (ask_user =='m') {
			modCID(tabCID);
		}
		else if (ask_user == 'd') {
			afficheCID(tabCID);
		}
		else if (ask_user == 'l') {
			modifstring(str_ref);
		}
	}
	return 0;
}

void modCID(CID tabCID[TAILLE]) {
	//BUT Modifier un paramètre d'une carte d'identité
	//ENTREE Une id de carte pour savoir quel carte modifier
	//SORTIE La carte modifié
	int id_ask;
	cout << "Indiquer l'ID de la carte que vous voulez modifier" << endl;
	cin >> id_ask;
	//On vérifie que l'Id est bien dans le tableau
	if ( id_ask >= 0 && id_ask <= TAILLE) {
		//Si oui on modifie la carte choisie
		//tabCID[id_ask].modifier();
	}
	else {
		//Sinon on prévient l'utilisateur
		cout << "Votre ID n'existe pas" << endl;
	}
}

void afficheCID(CID tabCID[TAILLE]) {
	//BUT Afficher une carte d'identité
	//ENTREE Une id de carte ou un caractère défini pour toutes les afficher
	//SORTIE L'affichage de une ou plusieurs cartes
	string id_ask;
	cout << "Indiquer l'ID de la carte que vous voulez afficher" << endl;
	cin >> id_ask;
	//On vérifie que la carte est bien dans le tableau
	if ((stoi(id_ask) >= 0) & ((stoi(id_ask) <= TAILLE))){
		//Si oui on affiche la carte
		tabCID[(stoi(id_ask))].afficher();
	}else{
		//Sinon on prévient l'utilisateur
		cout << "Votre ID n'existe pas"<<endl;
	}
}

void ajouterCID(CID tabCID[TAILLE]) {

	string ret_id,vnom,vprenom,vadresse,vcp,vville;
	ret_id = "none";
	int i;
	i=0;
	//On cherche la première case du tableau vide 
	while (ret_id == "none") {
		if (tabCID[i].getnom() == "") {
			//On prépare l'id de la future carte d'identité
			ret_id = std::to_string(i);
		}
		else {
			i++;
			//on évite la boucle infini
			if (i > TAILLE) {
				//au cas ou le tableau est plein on prévient l'utilisateur
				cout << "Le tableau est plein" << endl;
				ret_id = "full";
			}
		}
	}
		//On demande à l'utilisateur de rentrer les valeurs dans l'ordre
		cout << "Indiquer votre nom" << endl;
		cin >> vnom;
		cout << "Indiquer votre prenom" << endl;
		cin >> vprenom;
		cout << "Indiquer votre adresse" << endl;
		cin >> vadresse;
		cout << "Indiquer votre cp" << endl;
		cin >> vcp;
		cout << "Indiquer votre ville" << endl;
		cin >> vville;
		//On crée une nouvel carte
		tabCID[i].ajouter(ret_id,vnom,vprenom,vadresse,vcp,vville);
}

void supprCID(CID tabCID[TAILLE]) {
	//BUT Supprimer une carte d'identité
	//ENTREE Une id de carte pour savoir quelle carte supprimer
	//SORTIE La carte suprimé
	string id_ask;
	cout << "Indiquer l'ID de la carte que vous voulez supprimer" << endl;
	cin >> id_ask;
	//On vérifie que l'id est dans le tableau
	if ((stoi(id_ask) >= 0) & ((stoi(id_ask) <= TAILLE))) {
		//Si oui on supprime
		tabCID[(stoi(id_ask))].~CID();
	}
	else {
		//Sinon on prévient l'utilisateur
		cout << "Votre ID n'existe pas" << endl;
	}
}

void modifstring(string& str_ref) {
	cout << "Quel est votre nouvelle chaine de caractere" << endl;
	cin >> str_ref;
}