#pragma once
#include"ArregloPokemon.h"

class Entrenador
{
protected:

	//Imagenes que se usaran en la batalla pokemon
	int AnchoBatalla;
	int AltoBatalla;
	char* DirImagenBatalla;
	//Imagenes que se usaran para las miniaturas
	int AnchoMiniatura;
	int AltoMiniatura;
	char* DirSpritesMiniatura;

	char* Nombre;
	int PertenenciaPokemon;
	ArregloPokemon* EquipoPokemon;
	
public:

	 Entrenador(void);
	~Entrenador(void);

	//Metodos GET
	int PokemonMechador;
	int getAnchoBatalla();
	int getAltoBatalla();
	char* getDirImagenBatalla();
	int getAnchoMiniatura();
	int getAltoMiniatura();
	char* getDirSpritesMiniatura();
	int getPertenenciaPokemon();
	char* getNombre();
	ArregloPokemon* getArregloPokemon();

	//Otros Metodos
	virtual void MostrarEnBatalla(Graphics^ Graphic);
	virtual void MostrarMiniatura(Graphics^ Graphic);
};

Entrenador::Entrenador(void)
{
	PokemonMechador = 0;
	EquipoPokemon = new ArregloPokemon();
	Nombre = new char[15];
	DirImagenBatalla = new char[100];
	DirSpritesMiniatura = new char[100];
}

Entrenador::~Entrenador(void)
{
	delete EquipoPokemon;
	delete[] Nombre;
	delete[] DirImagenBatalla;
	delete[] DirSpritesMiniatura;
}

int Entrenador::getAnchoBatalla(){ return AnchoBatalla; }
int Entrenador::getAltoBatalla(){ return AltoBatalla; }
char* Entrenador::getDirImagenBatalla(){ return DirImagenBatalla; }
int Entrenador::getAnchoMiniatura(){ return AnchoMiniatura; }
int Entrenador::getAltoMiniatura(){ return AltoMiniatura; }
char* Entrenador::getDirSpritesMiniatura(){ return DirSpritesMiniatura; }
int Entrenador::getPertenenciaPokemon(){ return PertenenciaPokemon; }
char* Entrenador::getNombre(){ return Nombre; }
ArregloPokemon* Entrenador::getArregloPokemon(){ return EquipoPokemon; }

void Entrenador::MostrarEnBatalla(Graphics^ Graphic){ }
void Entrenador::MostrarMiniatura(Graphics^ Graphic){ }