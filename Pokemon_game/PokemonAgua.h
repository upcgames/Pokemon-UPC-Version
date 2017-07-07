#pragma once
#include "Pokemon.h"

class PokemonAgua : public Pokemon
{
public:
	PokemonAgua(void);
	~PokemonAgua(void);
};

PokemonAgua::PokemonAgua(void) : Pokemon()
{
	Tipo = 4;

	strcpy(MatrizDeNombresDeAtaques[0], "Placaje");
	MatrizDeDanioDeAtaques[0] = 50;
	MatrizDeTipoDeAtaques[0] = Tipo::Normal;
	MatrizDePPDeAtaques[0] = 35;
	MatrizDeEfectividadDeAtaques[0] = 100;
	//strcpy(mensaje[0], "Usaste Placaje!");
	MensajeIndex[0] = MensajeDeAtaque::MensajeNormal;

	strcpy(MatrizDeNombresDeAtaques[1], "Látigo");
	MatrizDeDanioDeAtaques[1] = 0;
	MatrizDeTipoDeAtaques[1] = Tipo::Normal;
	MatrizDePPDeAtaques[1] = 30;
	MatrizDeEfectividadDeAtaques[1] = 100;
	//strcpy(mensaje[1], "La defensa del rival bajo!");
	MensajeIndex[1] = MensajeDeAtaque::DefensaRivalBajo1;

	strcpy(MatrizDeNombresDeAtaques[2], "Burbuja");
	MatrizDeDanioDeAtaques[2] = 40;
	MatrizDeTipoDeAtaques[2] = Tipo::Agua;
	MatrizDePPDeAtaques[2] = 30;
	MatrizDeEfectividadDeAtaques[2] = 90;
	//strcpy(mensaje[2], "Usaste Burbujas, La velocidad del rival bajó");
	MensajeIndex[2] = MensajeDeAtaque::VelocidadRivalBajo1;

	strcpy(MatrizDeNombresDeAtaques[3], "Refugio");
	MatrizDeDanioDeAtaques[3] = 0;
	MatrizDeTipoDeAtaques[3] = Tipo::Agua;
	MatrizDePPDeAtaques[3] = 40;
	MatrizDeEfectividadDeAtaques[3] = 100;
	//strcpy(mensaje[3], "Tu defensa subió!");
	MensajeIndex[3] = MensajeDeAtaque::MiDefensaSubio1;

	strcpy(MatrizDeNombresDeAtaques[4], "Pistola de Agua");
	MatrizDeDanioDeAtaques[4] = 40;
	MatrizDeTipoDeAtaques[4] = Tipo::Agua;
	MatrizDePPDeAtaques[4] = 25;
	MatrizDeEfectividadDeAtaques[4] = 75;
	//strcpy(mensaje[4], "Usaste Pistola de agua!")
	MensajeIndex[4] = MensajeDeAtaque::MensajeNormal;

	strcpy(MatrizDeNombresDeAtaques[5], "Mordisco");
	MatrizDeDanioDeAtaques[5] = 60;
	MatrizDeTipoDeAtaques[5] = Tipo::Siniestro;
	MatrizDePPDeAtaques[5] = 25;
	MatrizDeEfectividadDeAtaques[5] = 75;
	//strcpy(mensaje[5], "Usaste Mordisco!");
	MensajeIndex[5] = MensajeDeAtaque::MensajeNormal;

	strcpy(MatrizDeNombresDeAtaques[6], "Giro Rápido");
	MatrizDeDanioDeAtaques[6] = 20;
	MatrizDeTipoDeAtaques[6] = Tipo::Normal;
	MatrizDePPDeAtaques[6] = 40;
	MatrizDeEfectividadDeAtaques[6] = 95;
	//strcpy(mensaje[6], "Usaste Giro Rápido!");
	MensajeIndex[6] = MensajeDeAtaque::MensajeNormal;

	strcpy(MatrizDeNombresDeAtaques[7], "Protección");
	MatrizDeDanioDeAtaques[7] = 0;
	MatrizDeTipoDeAtaques[7] = Tipo::Normal;
	MatrizDePPDeAtaques[7] = 10;
	MatrizDeEfectividadDeAtaques[7] = 100;
	//strcpy(mensaje[7], "Usaste Protección, Estás protegido!");
	MensajeIndex[7] = MensajeDeAtaque::MiProteccionSubio1;

	strcpy(MatrizDeNombresDeAtaques[8], "Danza Lluvia");
	MatrizDeDanioDeAtaques[8] = 0;
	MatrizDeTipoDeAtaques[8] = Tipo::Agua;
	MatrizDePPDeAtaques[8] = 5;
	MatrizDeEfectividadDeAtaques[8] = 100;
	//strcpy(mensaje[8], "Provocaste una Llovisna");
	MensajeIndex[8] = MensajeDeAtaque::Llovizna;

	strcpy(MatrizDeNombresDeAtaques[9], "Cabezaso");
	MatrizDeDanioDeAtaques[9] = 130;
	MatrizDeTipoDeAtaques[9] = Tipo::Normal;
	MatrizDePPDeAtaques[9] = 10;
	MatrizDeEfectividadDeAtaques[9] = 100;
	//strcpy(mensaje[9], "Tu defensa aumentó, espera para golpear!");
	MensajeIndex[9] = MensajeDeAtaque::MiDefensaSubio1;

	strcpy(MatrizDeNombresDeAtaques[10], "Hidrobomba");
	MatrizDeDanioDeAtaques[10] = 110;
	MatrizDeTipoDeAtaques[10] = Tipo::Agua;
	MatrizDePPDeAtaques[10] = 5;
	MatrizDeEfectividadDeAtaques[10] = 80;
	//strcpy(mensaje[10], "Usaste Hidrobomba!");
	MensajeIndex[10] = MensajeDeAtaque::MensajeNormal;
}

PokemonAgua::~PokemonAgua(void) {}

//Pokemones Tipo Agua
class Squirtle : public PokemonAgua
{
public:
	Squirtle(void);
	~Squirtle(void);
};
Squirtle::Squirtle(void) : PokemonAgua()
{
	Vitalidad = 500;
	Vida = Vitalidad;
	setAncho(80);
	setAlto(80);

	setDirImagenFront("Data\\Imagenes\\\\Pokemones\\Batalla\\squirtle_front.png");
	setDirImagenBack("Data\\Imagenes\\\\Pokemones\\Batalla\\squirtle_back.png");

	setNombre("Squirtle");

	Random VariableRandom;
	int EnteroRandom;

	AsignarAtaquesAleatorios();

}
Squirtle::~Squirtle(void){}

/**/
class Totodile : public PokemonAgua
{
public:
	Totodile(void);
	~Totodile(void);
};
Totodile::Totodile(void) : PokemonAgua()
{
	Vitalidad = 500;
	Vida = Vitalidad;
	setAncho(80);
	setAlto(80);

	setDirImagenFront("Data\\Imagenes\\\\Pokemones\\Batalla\\totodile_front.png");
	setDirImagenBack("Data\\Imagenes\\\\Pokemones\\Batalla\\totodile_back.png");

	setNombre("Totodile");

	AsignarAtaquesAleatorios();

}
Totodile::~Totodile(void){}

class Suicune : public PokemonAgua
{
public:
	Suicune(void);
	~Suicune(void);
};
Suicune::Suicune(void) : PokemonAgua()
{
	Vitalidad = 500;
	Vida = Vitalidad;
	setAncho(80);
	setAlto(80);

	setDirImagenFront("Data\\Imagenes\\\\Pokemones\\Batalla\\suicune_front.png");
	setDirImagenBack("Data\\Imagenes\\\\Pokemones\\Batalla\\suicune_back.png");

	setNombre("Suicune");

	Random VariableRandom;
	int EnteroRandom;

	AsignarAtaquesAleatorios();

}
Suicune::~Suicune(void){}
/////
class Wailmer : public PokemonAgua
{
public:
	Wailmer(void);
	~Wailmer(void);
};
Wailmer::Wailmer(void) : PokemonAgua()
{
	Vitalidad = 500;
	Vida = Vitalidad;
	setAncho(80);
	setAlto(80);

	setDirImagenFront("Data\\Imagenes\\\\Pokemones\\Batalla\\wailmer_front.png");
	setDirImagenBack("Data\\Imagenes\\\\Pokemones\\Batalla\\wailmer_back.png");

	setNombre("Wailmer");

	Random VariableRandom;
	int EnteroRandom;

	AsignarAtaquesAleatorios();

}
Wailmer::~Wailmer(void){}
/////
class Kyogre : public PokemonAgua
{
public:
	Kyogre(void);
	~Kyogre(void);
};
Kyogre::Kyogre(void) : PokemonAgua()
{
	Vitalidad = 500;
	Vida = Vitalidad;
	setAncho(80);
	setAlto(80);

	setDirImagenFront("Data\\Imagenes\\\\Pokemones\\Batalla\\kyogre_front.png");
	setDirImagenBack("Data\\Imagenes\\\\Pokemones\\Batalla\\kyogre_back.png");

	setNombre("Kyogre");

	Random VariableRandom;
	int EnteroRandom;

	AsignarAtaquesAleatorios();

}
Kyogre::~Kyogre(void){}




