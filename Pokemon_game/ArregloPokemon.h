#pragma once
#include"Pokemon.h"
#include "PokemonElectrico.h"
#include "PokemonPlanta.h"
#include "PokemonAgua.h"
#include "PokemonFuego.h"
#include "PokemonPsiquico.h"
#include "PokemonNormal.h"

class ArregloPokemon
{
protected:
	Pokemon** ArregloDePokemones;
	int TamanioDelArreglo;

public:

	 ArregloPokemon(void);
	~ArregloPokemon(void);

	Pokemon** CrearArregloPokemon();
	Pokemon* RetornSiguientePokemon();
	Pokemon* RetornaPokemon(int Indice);
	int getTamanioDelArreglo();
	void AgregarPokemon(Pokemon* NuevoPokemon, int LaPertenecia);
	void EliminarPokemon(int Indice);
	void CurarPokemones();
	bool QuedanPokemonesVivos();
	bool HayPoquemonHerido();
	bool HayVariosPokemones();
};

ArregloPokemon::ArregloPokemon(void)
{
	ArregloDePokemones = NULL;
	TamanioDelArreglo = 0;
}

ArregloPokemon::~ArregloPokemon(void)
{
	for (int i = 0; i < TamanioDelArreglo; i++)
		delete ArregloDePokemones[i];
	delete ArregloDePokemones;
}

Pokemon** ArregloPokemon::CrearArregloPokemon()
{
	return new Pokemon*[TamanioDelArreglo + 1];
}

int ArregloPokemon::getTamanioDelArreglo(){
	return TamanioDelArreglo;
}

Pokemon* ArregloPokemon::RetornSiguientePokemon()
{
	for (int i = 0; i<TamanioDelArreglo; i++)
		if (ArregloDePokemones[i]->getVida() > 0)
		{
			return ArregloDePokemones[i];
		}
}

Pokemon* ArregloPokemon::RetornaPokemon(int Indice)
{
	return ArregloDePokemones[Indice];
}

void ArregloPokemon::AgregarPokemon(Pokemon* NuevoPokemon, int LaPertenecia)
{
	Pokemon** ArregloPokemonAuxiliar = CrearArregloPokemon();
	if (ArregloPokemonAuxiliar != NULL)
	{
		NuevoPokemon->setPertenenciaPokemon(LaPertenecia);

		for (int i = 0; i<TamanioDelArreglo; i++)
			ArregloPokemonAuxiliar[i] = ArregloDePokemones[i];

		ArregloPokemonAuxiliar[TamanioDelArreglo] = NuevoPokemon;
		TamanioDelArreglo = TamanioDelArreglo + 1;

		if (ArregloDePokemones != NULL)
			delete ArregloDePokemones;
		ArregloDePokemones = ArregloPokemonAuxiliar;
	}
}

void ArregloPokemon::EliminarPokemon(int Indice){
	Pokemon** ArregloDePokemonesAuxiliar = new Pokemon*[TamanioDelArreglo - 1];
	if (ArregloDePokemonesAuxiliar != NULL)
	{
		//sobre la izquierda del indice a eliminar;
		for (int i = 0; i <= Indice - 1; i++)
			ArregloDePokemonesAuxiliar[i] = ArregloDePokemones[i];
		//sobre la derecha del indice a eliminar;
		for (int i = Indice + 1; i<TamanioDelArreglo; i++)
			ArregloDePokemonesAuxiliar[i - 1] = ArregloDePokemones[i];

		TamanioDelArreglo = TamanioDelArreglo - 1;
		if (ArregloDePokemonesAuxiliar != NULL)
			delete ArregloDePokemonesAuxiliar;

		ArregloDePokemones = ArregloDePokemonesAuxiliar;
	}
}

bool ArregloPokemon::QuedanPokemonesVivos()
{
	for (int i = 0; i < TamanioDelArreglo; i++)
	{
		if (ArregloDePokemones[i]->getVida() > 0)
			return true;
	}
	return false;
}

void ArregloPokemon::CurarPokemones()
{
	for (int i = 0; i < TamanioDelArreglo; i++)
		ArregloDePokemones[i]->CurarPokemon();
}

bool ArregloPokemon::HayPoquemonHerido()
{
	for (int i = 0; i < TamanioDelArreglo; i++)
	{
		if (ArregloDePokemones[i]->getVida() != ArregloDePokemones[i]->getVitalidad())
			return true;
	}
	return false;
}

bool ArregloPokemon::HayVariosPokemones()
{
	int Contador = 0;

	for (int i = 0; i < TamanioDelArreglo; i++)
	{
		if (ArregloDePokemones[i]->getVida() == 0);
		else
			Contador++;

		if (Contador == 2)
			return true;
	}
			return false;
}

	