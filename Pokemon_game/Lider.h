#pragma once
#include "Entrenador.h"

class Lider : public Entrenador
{
protected:
	char* Especialidad;
public:
	Lider(void);
	~Lider(void);
	char* getEspecialidad();
	void MostrarEnBatalla(Graphics^ Graphic);
	void MostrarMiniatura(Graphics^ Graphic);
};

Lider::Lider(void) : Entrenador()
{
	Especialidad = new char[20];
}
Lider::~Lider(void){}

void Lider::MostrarEnBatalla(Graphics^ Graphic){}
void Lider::MostrarMiniatura(Graphics^ Graphic){}

class PrimerLider : public Lider
{
protected:
	int IDLider;
public:
	PrimerLider(void);
	~PrimerLider(void);
};

PrimerLider::PrimerLider(void) : Lider()
{
	AnchoBatalla = 80;
	AltoBatalla = 80;
	IDLider = 1;
	PertenenciaPokemon = Pertenencia::DeLider;
	strcpy(Nombre, "Nagayoshi");
	strcpy(Especialidad, "Normal");
	strcpy(DirImagenBatalla, "Data\\Imagenes\\\\Pokemones\\Batalla\\rattata_front.png");
	EquipoPokemon->AgregarPokemon(new Cyndaquil(), Pertenencia::DeLider);
	EquipoPokemon->AgregarPokemon(new Cyndaquil(), Pertenencia::DeLider);
	EquipoPokemon->AgregarPokemon(new Cyndaquil(), Pertenencia::DeLider);
	EquipoPokemon->AgregarPokemon(new Cyndaquil(), Pertenencia::DeLider);
	EquipoPokemon->AgregarPokemon(new Cyndaquil(), Pertenencia::DeLider);
	EquipoPokemon->AgregarPokemon(new Cyndaquil(), Pertenencia::DeLider);
}
PrimerLider::~PrimerLider(void){}

class SegundoLider : public Lider
{
protected:
	int IDLider;
public:
	SegundoLider(void);
	~SegundoLider(void);
};

SegundoLider::SegundoLider(void) : Lider()
{
	AnchoBatalla = 80;
	AltoBatalla = 80;
	IDLider = 1;
	PertenenciaPokemon = Pertenencia::DeLider;
	strcpy(Nombre, "Crayon");
	strcpy(Especialidad, "Planta");
	strcpy(DirImagenBatalla, "Data\\Imagenes\\\\Pokemones\\Batalla\\rattata_front.png");
	EquipoPokemon->AgregarPokemon(new Squirtle(), Pertenencia::DeLider);
	EquipoPokemon->AgregarPokemon(new Squirtle(), Pertenencia::DeLider);
	EquipoPokemon->AgregarPokemon(new Squirtle(), Pertenencia::DeLider);
	EquipoPokemon->AgregarPokemon(new Squirtle(), Pertenencia::DeLider);
	EquipoPokemon->AgregarPokemon(new Squirtle(), Pertenencia::DeLider);
	EquipoPokemon->AgregarPokemon(new Squirtle(), Pertenencia::DeLider);
}
SegundoLider::~SegundoLider(void){}

class TercerLider : public Lider
{
protected:
	int IDLider;
public:
	TercerLider(void);
	~TercerLider(void);
};

TercerLider::TercerLider(void) : Lider()
{
	AnchoBatalla = 80;
	AltoBatalla = 80;
	IDLider = 1;
	PertenenciaPokemon = Pertenencia::DeLider;
	strcpy(Nombre, "Crayon");
	strcpy(Especialidad, "Agua");
	strcpy(DirImagenBatalla, "Data\\Imagenes\\\\Pokemones\\Batalla\\rattata_front.png");
	EquipoPokemon->AgregarPokemon(new Bulbasaur(), Pertenencia::DeLider);
	EquipoPokemon->AgregarPokemon(new Bulbasaur(), Pertenencia::DeLider);
	EquipoPokemon->AgregarPokemon(new Bulbasaur(), Pertenencia::DeLider);
	EquipoPokemon->AgregarPokemon(new Bulbasaur(), Pertenencia::DeLider);
	EquipoPokemon->AgregarPokemon(new Bulbasaur(), Pertenencia::DeLider);
	EquipoPokemon->AgregarPokemon(new Bulbasaur(), Pertenencia::DeLider);
}
TercerLider::~TercerLider(void){}

class CuartoLider : public Lider
{
protected:
	int IDLider;
public:
	CuartoLider(void);
	~CuartoLider(void);
};

CuartoLider::CuartoLider(void) : Lider()
{
	AnchoBatalla = 80;
	AltoBatalla = 80;
	IDLider = 1;
	PertenenciaPokemon = Pertenencia::DeLider;
	strcpy(Nombre, "Crayon");
	strcpy(Especialidad, "Fuego");
	strcpy(DirImagenBatalla, "Data\\Imagenes\\\\Pokemones\\Batalla\\rattata_front.png");
	EquipoPokemon->AgregarPokemon(new Cyndaquil(), Pertenencia::DeLider);
	EquipoPokemon->AgregarPokemon(new Cyndaquil(), Pertenencia::DeLider);
	EquipoPokemon->AgregarPokemon(new Cyndaquil(), Pertenencia::DeLider);
	EquipoPokemon->AgregarPokemon(new Cyndaquil(), Pertenencia::DeLider);
	EquipoPokemon->AgregarPokemon(new Cyndaquil(), Pertenencia::DeLider);
	EquipoPokemon->AgregarPokemon(new Cyndaquil(), Pertenencia::DeLider);
}
CuartoLider::~CuartoLider(void){}

class QuintoLider : public Lider
{
protected:
	int IDLider;
public:
	QuintoLider(void);
	~QuintoLider(void);
};

QuintoLider::QuintoLider(void) : Lider()
{
	AnchoBatalla = 80;
	AltoBatalla = 80;
	IDLider = 1;
	PertenenciaPokemon = Pertenencia::DeLider;
	strcpy(Nombre, "Crayon");
	strcpy(Especialidad, "Psiquico");
	strcpy(DirImagenBatalla, "Data\\Imagenes\\\\Pokemones\\Batalla\\rattata_front.png");
	EquipoPokemon->AgregarPokemon(new Cyndaquil(), Pertenencia::DeLider);
	EquipoPokemon->AgregarPokemon(new Cyndaquil(), Pertenencia::DeLider);
	EquipoPokemon->AgregarPokemon(new Cyndaquil(), Pertenencia::DeLider);
	EquipoPokemon->AgregarPokemon(new Cyndaquil(), Pertenencia::DeLider);
	EquipoPokemon->AgregarPokemon(new Cyndaquil(), Pertenencia::DeLider);
	EquipoPokemon->AgregarPokemon(new Cyndaquil(), Pertenencia::DeLider);
}
QuintoLider::~QuintoLider(void){}

class SextoLider : public Lider
{
protected:
	int IDLider;
public:
	SextoLider(void);
	~SextoLider(void);
};

SextoLider::SextoLider(void) : Lider()
{
	AnchoBatalla = 80;
	AltoBatalla = 80;
	IDLider = 1;
	PertenenciaPokemon = Pertenencia::DeLider;
	strcpy(Nombre, "Crayon");
	strcpy(Especialidad, "Tierra");
	strcpy(DirImagenBatalla, "Data\\Imagenes\\\\Pokemones\\Batalla\\rattata_front.png");
	EquipoPokemon->AgregarPokemon(new Cyndaquil(), Pertenencia::DeLider);
	EquipoPokemon->AgregarPokemon(new Cyndaquil(), Pertenencia::DeLider);
	EquipoPokemon->AgregarPokemon(new Cyndaquil(), Pertenencia::DeLider);
	EquipoPokemon->AgregarPokemon(new Cyndaquil(), Pertenencia::DeLider);
	EquipoPokemon->AgregarPokemon(new Cyndaquil(), Pertenencia::DeLider);
	EquipoPokemon->AgregarPokemon(new Cyndaquil(), Pertenencia::DeLider);
}
SextoLider::~SextoLider(void){}