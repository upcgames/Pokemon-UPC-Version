#pragma once
#include "Pokemon.h"

class PokemonElectrico : public Pokemon
{
public:
	PokemonElectrico(void);
	~PokemonElectrico(void);
};

PokemonElectrico::PokemonElectrico() : Pokemon()
{

	Tipo = 1;

	strcpy(MatrizDeNombresDeAtaques[0], "Látigo");
	MatrizDeDanioDeAtaques[0] = 0;
	MatrizDeTipoDeAtaques[0] = Tipo::Normal;
	MatrizDePPDeAtaques[0] = 30;
	MatrizDeEfectividadDeAtaques[0] = 100;
	//strcpy(mensaje[0], "La defensa del rival bajo!");
	MensajeIndex[0] = MensajeDeAtaque::MensajeNormal;

	strcpy(MatrizDeNombresDeAtaques[1], "Gruñido");
	MatrizDeDanioDeAtaques[1] = 0;
	MatrizDeTipoDeAtaques[1] = Tipo::Normal;
	MatrizDePPDeAtaques[1] = 40;
	MatrizDeEfectividadDeAtaques[1] = 100;
	//strcpy(mensaje[1], "El ataque  del rival bajo!");
	MensajeIndex[1] = MensajeDeAtaque::AtaqueRivalBajo1;

	strcpy(MatrizDeNombresDeAtaques[2], "Camaradería");
	MatrizDeDanioDeAtaques[2] = 0;
	MatrizDeTipoDeAtaques[2] = Tipo::Normal;
	MatrizDePPDeAtaques[2] = 20;
	MatrizDeEfectividadDeAtaques[2] = 100;
	//strcpy(mensaje[2], "El ataque  del rival bajo!");
	MensajeIndex[2] = MensajeDeAtaque::AtaqueRivalBajo1;

	strcpy(MatrizDeNombresDeAtaques[3], "Ataque Rápido");
	MatrizDeDanioDeAtaques[3] = 40;
	MatrizDeTipoDeAtaques[3] = Tipo::Normal;
	MatrizDePPDeAtaques[3] = 30;
	MatrizDeEfectividadDeAtaques[3] = 100;
	//strcpy(mensaje[3], "Usaste Ataque Rapido!");
	MensajeIndex[3] = MensajeDeAtaque::MensajeNormal;

	strcpy(MatrizDeNombresDeAtaques[4], "Bola Voltio");
	MatrizDeDanioDeAtaques[4] = 60 + (rand() % 91);
	MatrizDeTipoDeAtaques[4] = Tipo::Electrico;
	MatrizDePPDeAtaques[4] = 10;
	MatrizDeEfectividadDeAtaques[4] = 100;
	//strcpy(mensaje[4], "Usaste Onda Voltio!");
	MensajeIndex[4] = MensajeDeAtaque::MensajeNormal;

	strcpy(MatrizDeNombresDeAtaques[5], "Onda Trueno");

	MatrizDeDanioDeAtaques[5] = 0;
	MatrizDeTipoDeAtaques[5] = Tipo::Electrico;
	MatrizDePPDeAtaques[5] = 20;
	MatrizDeEfectividadDeAtaques[5] = 100;
	//strcpy(mensaje[5], "Usaste Onda Trueno!, El rival parece Paralizado");
	MensajeIndex[5] = MensajeDeAtaque::RivalParalizado1;

	strcpy(MatrizDeNombresDeAtaques[6], "Amago");
	MatrizDeDanioDeAtaques[6] = 30;
	MatrizDeTipoDeAtaques[6] = Tipo::Normal;
	MatrizDePPDeAtaques[6] = 40;
	MatrizDeEfectividadDeAtaques[6] = 100;
	//strcpy(mensaje[6], "Usaste amago, nunca falla!");
	MensajeIndex[6] = MensajeDeAtaque::NuncaFalla;

	strcpy(MatrizDeNombresDeAtaques[7], "Doble Equipo");
	MatrizDeDanioDeAtaques[7] = 0;
	MatrizDeTipoDeAtaques[7] = Tipo::Normal;
	MatrizDePPDeAtaques[7] = 15;
	MatrizDeEfectividadDeAtaques[7] = 100;
	//strcpy(mensaje[7], "Evasion de tu pokemon subio!");
	MensajeIndex[7] = MensajeDeAtaque::EvasionRivalBajo1;

	strcpy(MatrizDeNombresDeAtaques[8], "Chispa");
	MatrizDeDanioDeAtaques[8] = 65;
	MatrizDeTipoDeAtaques[8] = Tipo::Electrico;
	MatrizDePPDeAtaques[8] = 20;
	MatrizDeEfectividadDeAtaques[8] = 100;
	//strcpy(mensaje[8], "Usaste Chispa!, El rival parece Paralizado");
	MensajeIndex[8] = MensajeDeAtaque::RivalParalizado1;

	strcpy(MatrizDeNombresDeAtaques[9], "Chispazo");
	MatrizDeDanioDeAtaques[9] = 80;
	MatrizDeTipoDeAtaques[9] = Tipo::Electrico;
	MatrizDePPDeAtaques[9] = 15;
	MatrizDeEfectividadDeAtaques[9] = 100;
	//strcpy(mensaje[9], "Usaste Chispazo!, El rival parece Paralizado");
	MensajeIndex[9] = MensajeDeAtaque::RivalParalizado1;

	strcpy(MatrizDeNombresDeAtaques[10], "Rayo");
	MatrizDeDanioDeAtaques[10] = 90;
	MatrizDeTipoDeAtaques[10] = Tipo::Electrico;
	MatrizDePPDeAtaques[10] = 15;
	MatrizDeEfectividadDeAtaques[10] = 100;
	//strcpy(mensaje[10], "Usaste Rayo!, El rival parece Paralizado");
	MensajeIndex[10] = MensajeDeAtaque::RivalParalizado1;

	strcpy(MatrizDeNombresDeAtaques[11], "Agilidad");
	MatrizDeDanioDeAtaques[11] = 0;
	MatrizDeTipoDeAtaques[11] = Tipo::Psiquico;
	MatrizDePPDeAtaques[11] = 30;
	MatrizDeEfectividadDeAtaques[11] = 100;
	//strcpy(mensaje[11], "Tu velocidad subio mucho!");
	MensajeIndex[11] = MensajeDeAtaque::MiVelocidadSubio2;

	strcpy(MatrizDeNombresDeAtaques[12], "Trueno");
	MatrizDeDanioDeAtaques[12] = 110;
	MatrizDeTipoDeAtaques[12] = Tipo::Electrico;
	MatrizDePPDeAtaques[12] = 10;
	MatrizDeEfectividadDeAtaques[12] = 70;
	//strcpy(mensaje[12], "Usaste Trueno, El rival parece Paralizado");
	MensajeIndex[12] = MensajeDeAtaque::RivalParalizado1;

	strcpy(MatrizDeNombresDeAtaques[13], "Voltio Cruel");
	MatrizDeDanioDeAtaques[13] = 90;
	MatrizDeTipoDeAtaques[13] = Tipo::Electrico;
	MatrizDePPDeAtaques[13] = 15;
	MatrizDeEfectividadDeAtaques[13] = 100;
	//strcpy(mensaje[13], "Usaste Voltio Curel!");
	MensajeIndex[13] = MensajeDeAtaque::MensajeNormal;


}

PokemonElectrico::~PokemonElectrico(void){}

//Pokemones Tipo Electrico
//pikachu Voltorb manectric Raikou jolteon 
class Pikachu : public PokemonElectrico
{
public:
	Pikachu(void);
	~Pikachu(void);
};
Pikachu::Pikachu(void) : PokemonElectrico()
{
	Vitalidad = 500;
	Vida = Vitalidad;
	setAncho(80);
	setAlto(80);

	setDirImagenFront("Data\\Imagenes\\\\Pokemones\\Batalla\\pikachu_front.png");
	setDirImagenBack("Data\\Imagenes\\\\Pokemones\\Batalla\\pikachu_back.png");
	setNombre("Pikachu");

	AsignarAtaquesAleatorios();

}
Pikachu::~Pikachu(void){}
//Voltorb
class Voltorb : public PokemonElectrico
{
public:
	Voltorb(void);
	~Voltorb(void);
};
Voltorb::Voltorb(void) : PokemonElectrico()
{
	Vitalidad = 500;
	Vida = Vitalidad;
	setAncho(80);
	setAlto(80);

	setDirImagenFront("Data\\Imagenes\\\\Pokemones\\Batalla\\voltorb_front.png");
	setDirImagenBack("Data\\Imagenes\\\\Pokemones\\Batalla\\voltorb_back.png");
	setNombre("Voltorb");

	AsignarAtaquesAleatorios();

}
Voltorb::~Voltorb(void){}
//Manectric
class Manectric : public PokemonElectrico
{
public:
	Manectric(void);
	~Manectric(void);
};
Manectric::Manectric(void) : PokemonElectrico()
{
	Vitalidad = 500;
	Vida = Vitalidad;
	setAncho(80);
	setAlto(80);

	setDirImagenFront("Data\\Imagenes\\\\Pokemones\\Batalla\\manectric_front.png");
	setDirImagenBack("Data\\Imagenes\\\\Pokemones\\Batalla\\manectric_back.png");
	setNombre("Manectric");

	AsignarAtaquesAleatorios();

}
Manectric::~Manectric(void){}
//Raikou
class Raikou : public PokemonElectrico
{
public:
	Raikou(void);
	~Raikou(void);
};
Raikou::Raikou(void) : PokemonElectrico()
{
	Vitalidad = 500;
	Vida = Vitalidad;
	setAncho(80);
	setAlto(80);

	setDirImagenFront("Data\\Imagenes\\\\Pokemones\\Batalla\\raikou_front.png");
	setDirImagenBack("Data\\Imagenes\\\\Pokemones\\Batalla\\raikou_back.png");
	setNombre("Raikou");

	AsignarAtaquesAleatorios();

}
Raikou::~Raikou(void){}
//
//Jolteon
class Jolteon : public PokemonElectrico
{
public:
	Jolteon(void);
	~Jolteon(void);
};
Jolteon::Jolteon(void) : PokemonElectrico()
{
	Vitalidad = 500;
	Vida = Vitalidad;
	setAncho(80);
	setAlto(80);

	setDirImagenFront("Data\\Imagenes\\\\Pokemones\\Batalla\\jolteon_front.png");
	setDirImagenBack("Data\\Imagenes\\\\Pokemones\\Batalla\\jolteon_back.png");
	setNombre("Jolteon");

	AsignarAtaquesAleatorios();

}
Jolteon::~Jolteon(void){}
