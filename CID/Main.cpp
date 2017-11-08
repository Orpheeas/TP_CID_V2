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
	//Seul CID rentr� de fa�on brut
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
	//BUT Modifier un param�tre d'une carte d'identit�
	//ENTREE Une id de carte pour savoir quel carte modifier
	//SORTIE La carte modifi�
	int id_ask;
	cout << "Indiquer l'ID de la carte que vous voulez modifier" << endl;
	cin >> id_ask;
	//On v�rifie que l'Id est bien dans le tableau
	if ( id_ask >= 0 && id_ask <= TAILLE) {
		//Si oui on modifie la carte choisie
		//tabCID[id_ask].modifier();
	}
	else {
		//Sinon on pr�vient l'utilisateur
		cout << "Votre ID n'existe pas" << endl;
	}
}

void afficheCID(CID tabCID[TAILLE]) {
	//BUT Afficher une carte d'identit�
	//ENTREE Une id de carte ou un caract�re d�fini pour toutes les afficher
	//SORTIE L'affichage de une ou plusieurs cartes
	string id_ask;
	cout << "Indiquer l'ID de la carte que vous voulez afficher" << endl;
	cin >> id_ask;
	//On v�rifie que la carte est bien dans le tableau
	if ((stoi(id_ask) >= 0) & ((stoi(id_ask) <= TAILLE))){
		//Si oui on affiche la carte
		tabCID[(stoi(id_ask))].afficher();
	}else{
		//Sinon on pr�vient l'utilisateur
		cout << "Votre ID n'existe pas"<<endl;
	}
}

void ajouterCID(CID tabCID[TAILLE]) {

	string ret_id,vnom,vprenom,vadresse,vcp,vville;
	ret_id = "none";
	int i;
	i=0;
	//On cherche la premi�re case du tableau vide 
	while (ret_id == "none") {
		if (tabCID[i].getnom() == "") {
			//On pr�pare l'id de la future carte d'identit�
			ret_id = std::to_string(i);
		}
		else {
			i++;
			//on �vite la boucle infini
			if (i > TAILLE) {
				//au cas ou le tableau est plein on pr�vient l'utilisateur
				cout << "Le tableau est plein" << endl;
				ret_id = "full";
			}
		}
	}
		//On demande � l'utilisateur de rentrer les valeurs dans l'ordre
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
		//On cr�e une nouvel carte
		tabCID[i].ajouter(ret_id,vnom,vprenom,vadresse,vcp,vville);
}

void supprCID(CID tabCID[TAILLE]) {
	//BUT Supprimer une carte d'identit�
	//ENTREE Une id de carte pour savoir quelle carte supprimer
	//SORTIE La carte suprim�
	string id_ask;
	cout << "Indiquer l'ID de la carte que vous voulez supprimer" << endl;
	cin >> id_ask;
	//On v�rifie que l'id est dans le tableau
	if ((stoi(id_ask) >= 0) & ((stoi(id_ask) <= TAILLE))) {
		//Si oui on supprime
		tabCID[(stoi(id_ask))].~CID();
	}
	else {
		//Sinon on pr�vient l'utilisateur
		cout << "Votre ID n'existe pas" << endl;
	}
}

void modifstring(string& str_ref) {
	cout << "Quel est votre nouvelle chaine de caractere" << endl;
	cin >> str_ref;
}