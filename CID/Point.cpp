#include "Point.h"


CID::CID()
{

}

void CID::ajouter(string mID, string mnom, string mprenom, string madresse, string mcp, string mville)
{
//Equivalent à la fonction création
	this->ID = mID;
	this->nom = mnom;
	this->prenom = mprenom;
	this->adresse = madresse;
	this->cp = mcp;
	this->ville = mville;

}

//SETTER
void CID::setID(string mID)
{
	ID = mID;
}

void CID::setnom(string mnom)
{
	nom = mnom;
}

void CID::setprenom(string mprenom)
{
	prenom = mprenom;
}

void CID::setadresse(string madresse)
{
	adresse = madresse;
}

void CID::setcp(string mcp)
{
	cp = mcp;
}

void CID::setville(string mville)
{
	ville = mville;
}

//GETTER

string CID::getID() const
{
	return ID;
}

string CID::getnom() const
{
	return nom;
}

string CID::getprenom() const
{
	return prenom;
}

string CID::getadresse() const
{
	return adresse;
}

string CID::getcp() const
{
	return cp;
}

string CID::getville() const
{
	return ville;
}

void CID::afficher() const
{
	system("cls");
	cout << "ID : " << this->getID() << endl;
	cout << "Nom : "<< this->getnom() << endl;
	cout << "Prenom : " << this->getprenom() << endl;
	cout << "Adresse : " << this->getadresse() << endl;
	cout << "CP : " << this->getcp() << endl;
	cout << "Ville : " << this->getville() << endl;
	cout << "\n" << endl;
}

void CID::modifier()
{
	string modparam;

	cout << "Que voulez-vous modifiez ? Veuillez ecrire votre reponse en minuscule" << endl;
	cin >> modparam;
	//TODO suppr \n
	
	if (modparam == "id") {
		cout << "Vous ne pouvez pas modifier l'ID" << endl;
	}
	else if (modparam=="nom"){
		cout << "Indiquer votre nouveau nom "<<endl;
		cin >> modparam;
		setnom(modparam);
	}

	else if (modparam == "prenom"){
		cout << "Indiquer votre nouveau prenom " << endl;
		cin >> modparam;
		setprenom(modparam);

	}else if (modparam == "adresse") {
		cout << "Indiquer votre nouvelle adresse" << endl;
		//cin.ignore(255, '\n');
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		getline(cin, modparam);
		setadresse(modparam);
	
	}else if(modparam == "cp") {
		cout << "Indiquer votre nouveau code postal" << endl;
		cin >> modparam;
		setcp(modparam);
	}
	else if (modparam== "ville") {
		cout << "Indiquer votre nouvelle ville" << endl;
		cin >> modparam;
		setville(modparam);
	}
	else {
		cout << "Incorect ! Soit vous avez mal orthographie le parametre recherche, soit il n'existe pas" <<endl;
	}

	//delete(modparam);
}

CID::~CID()
{
	//Equivalent à la fonction destruction/supression
}

