#pragma once
#include "Pokemon.h"

class PokemonFuego : public Pokemon
{
public:
	PokemonFuego(void);
	~PokemonFuego(void);
};

PokemonFuego::PokemonFuego(void) : Pokemon()
{
	Tipo = 3;
	strcpy(MatrizDeNombresDeAtaques[0], "Arañazo");
	MatrizDeDanioDeAtaques[0] = 40;
	MatrizDeTipoDeAtaques[0] = Tipo::Normal;
	MatrizDePPDeAtaques[0] = 35;
	MatrizDeEfectividadDeAtaques[0] = 100;
	//strcpy(mensaje[0], "Usaste Placaje!");
	MensajeIndex[0] = MensajeDeAtaque::MensajeNormal;

	strcpy(MatrizDeNombresDeAtaques[1], "Gruñido");
	MatrizDeDanioDeAtaques[1] = 0;
	MatrizDeTipoDeAtaques[1] = Tipo::Normal;
	MatrizDePPDeAtaques[1] = 40;
	MatrizDeEfectividadDeAtaques[1] = 100;
	//strcpy(mensaje[1], "El ataque  del rival bajo!");
	MensajeIndex[1] = MensajeDeAtaque::DefensaRivalBajo1;

	strcpy(MatrizDeNombresDeAtaques[2], "Ascuas");
	MatrizDeDanioDeAtaques[2] = 40;
	MatrizDeTipoDeAtaques[2] = Tipo::Fuego;
	MatrizDePPDeAtaques[2] = 25;
	MatrizDeEfectividadDeAtaques[2] = 100;
	//strcpy(mensaje[2], "Usaste Ascuas");
	MensajeIndex[2] = MensajeDeAtaque::MensajeNormal;

	strcpy(MatrizDeNombresDeAtaques[3], "Humo");
	MatrizDeDanioDeAtaques[3] = 0;
	MatrizDeTipoDeAtaques[3] = Tipo::Normal;
	MatrizDePPDeAtaques[3] = 20;
	MatrizDeEfectividadDeAtaques[3] = 100;
	//strcpy(mensaje[3], "La precisión del rival bajó!");
	MensajeIndex[3] = MensajeDeAtaque::PrecisionRivalBajo1;

	strcpy(MatrizDeNombresDeAtaques[4], "Furia Dragon");
	MatrizDeDanioDeAtaques[4] = 40;
	MatrizDeTipoDeAtaques[4] = Tipo::Dragon;
	MatrizDePPDeAtaques[4] = 10;
	MatrizDeEfectividadDeAtaques[4] = 100;
	//strcpy(mensaje[4], "Usaste Furia Dragon!");
	MensajeIndex[4] = MensajeDeAtaque::MensajeNormal;

	strcpy(MatrizDeNombresDeAtaques[5], "Cara Susto");
	MatrizDeDanioDeAtaques[5] = 0;
	MatrizDeTipoDeAtaques[5] = Tipo::Normal;
	MatrizDePPDeAtaques[5] = 10;
	MatrizDeEfectividadDeAtaques[5] = 100;
	//strcpy(mensaje[5], "La velocidad del rival bajo mucho!");
	MensajeIndex[5] = MensajeDeAtaque::VelocidadRivalBajo2;

	strcpy(MatrizDeNombresDeAtaques[6], "Comillo igneo");
	MatrizDeDanioDeAtaques[6] = 65;
	MatrizDeTipoDeAtaques[6] = Tipo::Fuego;
	MatrizDePPDeAtaques[6] = 15;
	MatrizDeEfectividadDeAtaques[6] = 95;
	//strcpy(mensaje[6], "Usaste Comillo igneo");
	MensajeIndex[6] = MensajeDeAtaque::MensajeNormal;

	strcpy(MatrizDeNombresDeAtaques[7], "Pirotecnia");
	MatrizDeDanioDeAtaques[7] = 70;
	MatrizDeTipoDeAtaques[7] = Tipo::Fuego;
	MatrizDePPDeAtaques[7] = 15;
	MatrizDeEfectividadDeAtaques[7] = 100;
	//strcpy(mensaje[7], "Usaste pirotecnia, afecta tambien a los rivales cercanos!");
	MensajeIndex[7] = MensajeDeAtaque::IgualParaTodos;

	strcpy(MatrizDeNombresDeAtaques[8], "Cuchillada");
	MatrizDeDanioDeAtaques[8] = 70;
	MatrizDeTipoDeAtaques[8] = Tipo::Normal;
	MatrizDePPDeAtaques[8] = 20;
	MatrizDeEfectividadDeAtaques[8] = 100;
	//strcpy(mensaje[8], "Usaste Cuchillada, y Provocaste un golpe CRÍTICO!");
	MensajeIndex[8] = MensajeDeAtaque::Critico;

	strcpy(MatrizDeNombresDeAtaques[9], "Lanzallamas");
	MatrizDeDanioDeAtaques[9] = 90;
	MatrizDeTipoDeAtaques[9] = Tipo::Fuego;
	MatrizDePPDeAtaques[9] = 15;
	MatrizDeEfectividadDeAtaques[9] = 100;
	//strcpy(mensaje[9], "Usaste Lanzallamas, El rival parece quemado!");
	MensajeIndex[9] = MensajeDeAtaque::RivalQuemado1;

	strcpy(MatrizDeNombresDeAtaques[10], "Giro Fuego");
	MatrizDeDanioDeAtaques[10] = 70;
	MatrizDeTipoDeAtaques[10] = Tipo::Fuego;
	MatrizDePPDeAtaques[10] = 15;
	MatrizDeEfectividadDeAtaques[10] = 85;
	//strcpy(mensaje[10], "Usaste Giro Fuego");
	MensajeIndex[10] = MensajeDeAtaque::MensajeNormal;

	strcpy(MatrizDeNombresDeAtaques[11], "Infierno");
	MatrizDeDanioDeAtaques[11] = 100;
	MatrizDeTipoDeAtaques[11] = Tipo::Fuego;
	MatrizDePPDeAtaques[11] = 5;
	MatrizDeEfectividadDeAtaques[11] = 50;
	//strcpy(mensaje[11], "Usaste Infierno, El rival esta completamente QUEMADO!");
	MensajeIndex[11] = MensajeDeAtaque::RivalQuemado2;
}

PokemonFuego::~PokemonFuego(void) {}

//Pokemones Tipo Fuego
class Charmander : public PokemonFuego
{
public:
	Charmander(void);
	~Charmander(void);

};
Charmander::Charmander(void) : PokemonFuego()
{
	Vitalidad = 500;
	Vida = Vitalidad;
	setAncho(80);
	setAlto(80);

	setDirImagenFront("Data\\Imagenes\\\\Pokemones\\Batalla\\charmander_front.png");
	setDirImagenBack("Data\\Imagenes\\\\Pokemones\\Batalla\\charmander_back.png");

	setNombre("Charmander");

	AsignarAtaquesAleatorios();

}
Charmander::~Charmander(void){}

/**/

class Cyndaquil : public PokemonFuego
{
public:
	Cyndaquil(void);
	~Cyndaquil(void);
};
Cyndaquil::Cyndaquil(void) : PokemonFuego()
{
	Vitalidad = 500;
	Vida = Vitalidad;
	setAncho(80);
	setAlto(80);

	setDirImagenFront("Data\\Imagenes\\\\Pokemones\\Batalla\\cyndaquil_front.png");
	setDirImagenBack("Data\\Imagenes\\\\Pokemones\\Batalla\\cyndaquil_back.png");
	setNombre("Cyndaquil");

	AsignarAtaquesAleatorios();

}
Cyndaquil::~Cyndaquil(void){}
//
class Entei : public PokemonFuego
{
public:
	Entei(void);
	~Entei(void);

};
Entei::Entei(void) : PokemonFuego()
{
	Vitalidad = 500;
	Vida = Vitalidad;
	setAncho(80);
	setAlto(80);

	setDirImagenFront("Data\\Imagenes\\\\Pokemones\\Batalla\\entei_front.png");
	setDirImagenBack("Data\\Imagenes\\\\Pokemones\\Batalla\\entei_back.png");

	setNombre("Entei");

	AsignarAtaquesAleatorios();

}
Entei::~Entei(void){}
//
class Slugma : public PokemonFuego
{
public:
	Slugma(void);
	~Slugma(void);

};
Slugma::Slugma(void) : PokemonFuego()
{
	Vitalidad = 500;
	Vida = Vitalidad;
	setAncho(80);
	setAlto(80);

	setDirImagenFront("Data\\Imagenes\\\\Pokemones\\Batalla\\slugma_front.png");
	setDirImagenBack("Data\\Imagenes\\\\Pokemones\\Batalla\\slugma_back.png");

	setNombre("Slugma");

	AsignarAtaquesAleatorios();

}
Slugma::~Slugma(void){}
//
class Ponyta : public PokemonFuego
{
public:
	Ponyta(void);
	~Ponyta(void);

};
Ponyta::Ponyta(void) : PokemonFuego()
{
	Vitalidad = 500;
	Vida = Vitalidad;
	setAncho(80);
	setAlto(80);

	setDirImagenFront("Data\\Imagenes\\\\Pokemones\\Batalla\\ponyta_front.png");
	setDirImagenBack("Data\\Imagenes\\\\Pokemones\\Batalla\\ponyta_back.png");

	setNombre("Ponyta");

	AsignarAtaquesAleatorios();

}
Ponyta::~Ponyta(void){}