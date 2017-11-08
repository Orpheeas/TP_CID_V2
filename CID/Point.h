#pragma once

#include <iostream>
#include <string>

using namespace std;

class CID
{
	//Données membres
	string ID, nom, prenom, adresse, cp, ville;
	
public:
	CID();
	//SETTER
	void setID(string mID);
	void setnom(string mnom);
	void setprenom(string mprenom);
	void setadresse(string madresse);
	void setcp(string mcp);
	void setville(string mville);

	//GETTER
	string getID() const;
	string getnom()const;
	string getprenom()const;
	string getadresse()const;
	string getcp()const;
	string getville()const;

	void ajouter(string mID, string mnom, string mprenom, string madresse, string mcp, string mville);
	void afficher() const;
	void modifier();
	~CID();
};
