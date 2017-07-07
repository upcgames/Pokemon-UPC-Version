//clase pokemon tipo normal

#pragma once
#include "Pokemon.h"
//Normal normal
class PokemonNormal : public Pokemon
{
public:
	PokemonNormal(void);
	~PokemonNormal(void);
};

PokemonNormal::PokemonNormal(void) : Pokemon()
{

	//supongo tipo 6
	Tipo == 6;
	strcpy(MatrizDeNombresDeAtaques[0], "Placaje");
	MatrizDeDanioDeAtaques[0] = 50;
	MatrizDeTipoDeAtaques[0] = Tipo::Normal;
	MatrizDePPDeAtaques[0] = 35;
	MatrizDeEfectividadDeAtaques[0] = 100;
	//strcpy(mensaje[0], "Usaste Placaje!");
	MensajeIndex[0] = MensajeDeAtaque::MensajeNormal;

	strcpy(MatrizDeNombresDeAtaques[1], "Golpe Cabeza");
	MatrizDeDanioDeAtaques[1] = 70;
	MatrizDeTipoDeAtaques[1] = Tipo::Normal;
	MatrizDePPDeAtaques[1] = 15;
	MatrizDeEfectividadDeAtaques[1] = 100;
	//strcpy(mensaje[1], "El rival retrocedio!");
	MensajeIndex[1] = MensajeDeAtaque::AtaqueRivalBajo1;

	strcpy(MatrizDeNombresDeAtaques[2], "Descanso");
	MatrizDeDanioDeAtaques[2] = 0;
	MatrizDeTipoDeAtaques[2] = Tipo::Psiquico;
	MatrizDePPDeAtaques[2] = 10;
	MatrizDeEfectividadDeAtaques[2] = 100;
	//strcpy(mensaje[2], "Descansas y recuperas toda tu energia!");
	MensajeIndex[2] = MensajeDeAtaque::MensajeNormal;

	strcpy(MatrizDeNombresDeAtaques[3], "Antojo");
	MatrizDeDanioDeAtaques[3] = 60;
	MatrizDeTipoDeAtaques[3] = Tipo::Normal;
	MatrizDePPDeAtaques[3] = 25;
	MatrizDeEfectividadDeAtaques[3] = 100;
	//strcpy(mensaje[3], "Usaste Antojo");
	MensajeIndex[3] = MensajeDeAtaque::MensajeNormal;

	strcpy(MatrizDeNombresDeAtaques[4], "Desenrollar");
	MatrizDeDanioDeAtaques[4] = 45;
	MatrizDeTipoDeAtaques[4] = Tipo::Roca;
	MatrizDePPDeAtaques[4] = 20;
	MatrizDeEfectividadDeAtaques[4] = 90;
	//strcpy(mensaje[4], "Usaste Desenrrollar!");
	MensajeIndex[4] = MensajeDeAtaque::RivalEnvenenado1;

	strcpy(MatrizDeNombresDeAtaques[5], "Hiperrayo");
	MatrizDeDanioDeAtaques[5] = 150;
	MatrizDeTipoDeAtaques[5] = Tipo::Normal;
	MatrizDePPDeAtaques[5] = 5;
	MatrizDeEfectividadDeAtaques[5] = 90;
	//strcpy(mensaje[5], "Usaste Hiperrayo!");
	MensajeIndex[5] = MensajeDeAtaque::RivalDormido1;

	strcpy(MatrizDeNombresDeAtaques[6], "Ronquido");
	MatrizDeDanioDeAtaques[6] = 50;
	MatrizDeTipoDeAtaques[6] = Tipo::Normal;
	MatrizDePPDeAtaques[6] = 15;
	MatrizDeEfectividadDeAtaques[6] = 100;
	//strcpy(mensaje[6], "El rival retrocedio!");
	MensajeIndex[6] = MensajeDeAtaque::Critico;

	strcpy(MatrizDeNombresDeAtaques[7], "Bostezo");
	MatrizDeDanioDeAtaques[7] = 0;
	MatrizDeTipoDeAtaques[7] = Tipo::Psiquico;
	MatrizDePPDeAtaques[7] = 10;
	MatrizDeEfectividadDeAtaques[7] = 100;
	//strcpy(mensaje[7], "Tu rival parece dormido");
	MensajeIndex[7] = MensajeDeAtaque::EvasionRivalBajo1;

	strcpy(MatrizDeNombresDeAtaques[8], "Rizo Defensa");
	MatrizDeDanioDeAtaques[8] = 0;
	MatrizDeTipoDeAtaques[8] = Tipo::Normal;
	MatrizDePPDeAtaques[8] = 40;
	MatrizDeEfectividadDeAtaques[8] = 100;
	//strcpy(mensaje[8], "Tu defensa subio!");
	MensajeIndex[8] = MensajeDeAtaque::MiAtaqueYEspecialSubio1;

	strcpy(MatrizDeNombresDeAtaques[9], "Tambor");
	MatrizDeDanioDeAtaques[9] = 0;
	MatrizDeTipoDeAtaques[9] = Tipo::Normal;
	MatrizDePPDeAtaques[9] = 10;
	MatrizDeEfectividadDeAtaques[9] = 100;
	//strcpy(mensaje[9], "Tu HP bajo considerablemente (50%) y tu ataque subio 6 niveles!");
	MensajeIndex[9] = MensajeDeAtaque::MiHPSubio1;

	strcpy(MatrizDeNombresDeAtaques[10], "Bloqueo");
	MatrizDeDanioDeAtaques[10] = 0;
	MatrizDeTipoDeAtaques[10] = Tipo::Normal;
	MatrizDePPDeAtaques[10] = 5;
	MatrizDeEfectividadDeAtaques[10] = 100;
	//strcpy(mensaje[10], "El rival no puede escapar!");
	MensajeIndex[10] = MensajeDeAtaque::RecargandoEnergia;
}

PokemonNormal::~PokemonNormal(void){}

//Pokemones Tipo normal
//Rattata Meowth Lickitung Snorlax Aipom
class Rattata : public PokemonNormal
{
public:
	Rattata(void);
	~Rattata(void);
};
Rattata::Rattata(void) : PokemonNormal()
{
	Vitalidad = 500;
	Vida = Vitalidad;
	setAncho(80);
	setAlto(80);

	setDirImagenFront("Data\\Imagenes\\\\Pokemones\\Batalla\\rattata_front.png");
	setDirImagenBack("Data\\Imagenes\\\\Pokemones\\Batalla\\rattata_back.png");
	setNombre("Rattata");

	AsignarAtaquesAleatorios();

}
Rattata::~Rattata(void){}
// //Rattata Meowth Lickitung Snorlax Aipom
class Meowth : public PokemonNormal
{
public:
	Meowth(void);
	~Meowth(void);
};
Meowth::Meowth(void) : PokemonNormal()
{
	Vitalidad = 500;
	Vida = Vitalidad;
	setAncho(80);
	setAlto(80);

	setDirImagenFront("Data\\Imagenes\\\\Pokemones\\Batalla\\meowth_front.png");
	setDirImagenBack("Data\\Imagenes\\\\Pokemones\\Batalla\\meowth_back.png");
	setNombre("Meowth");
	AsignarAtaquesAleatorios();

}
Meowth::~Meowth(void){}
//Rattata Meowth Lickitung Snorlax Aipom
class Lickitung : public PokemonNormal
{
public:
	Lickitung(void);
	~Lickitung(void);
};
Lickitung::Lickitung(void) : PokemonNormal()
{
	Vitalidad = 500;
	Vida = Vitalidad;
	setAncho(80);
	setAlto(80);

	setDirImagenFront("Data\\Imagenes\\\\Pokemones\\Batalla\\lickitung_front.png");
	setDirImagenBack("Data\\Imagenes\\\\Pokemones\\Batalla\\lickitung_back.png");
	setNombre("Lickitung");
	AsignarAtaquesAleatorios();

}
Lickitung::~Lickitung(void){}
//Rattata Meowth Lickitung Snorlax Aipom
class Snorlax : public PokemonNormal
{
public:
	Snorlax(void);
	~Snorlax(void);
};
Snorlax::Snorlax(void) : PokemonNormal()
{
	Vitalidad = 500;
	Vida = Vitalidad;
	setAncho(80);
	setAlto(80);

	setDirImagenFront("Data\\Imagenes\\\\Pokemones\\Batalla\\snorlax_front.png");
	setDirImagenBack("Data\\Imagenes\\\\Pokemones\\Batalla\\snorlax_back.png");
	setNombre("Snorlax");
	AsignarAtaquesAleatorios();

}
Snorlax::~Snorlax(void){}
//Rattata Meowth Lickitung Snorlax Aipom
class Aipom : public PokemonNormal
{
public:
	Aipom(void);
	~Aipom(void);
};
Aipom::Aipom(void) : PokemonNormal()
{
	Vitalidad = 500;
	Vida = Vitalidad;
	setAncho(80);
	setAlto(80);

	setDirImagenFront("Data\\Imagenes\\\\Pokemones\\Batalla\\aipom_front.png");
	setDirImagenBack("Data\\Imagenes\\\\Pokemones\\Batalla\\aipom_back.png");
	setNombre("Aipom");
	AsignarAtaquesAleatorios();

}
Aipom::~Aipom(void){}