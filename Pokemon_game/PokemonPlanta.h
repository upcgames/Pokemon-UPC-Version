#pragma once
#include "Pokemon.h"

class PokemonPlanta : public Pokemon
{
public:
	PokemonPlanta(void);
	~PokemonPlanta(void);
};

PokemonPlanta::PokemonPlanta(void) : Pokemon()
{
	Tipo == 2;
	strcpy(MatrizDeNombresDeAtaques[0], "Placaje");
	MatrizDeDanioDeAtaques[0] = 50;
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
	MensajeIndex[1] = MensajeDeAtaque::AtaqueRivalBajo1;

	strcpy(MatrizDeNombresDeAtaques[2], "Drenadoras");
	MatrizDeDanioDeAtaques[2] = 35;
	MatrizDeTipoDeAtaques[2] = Tipo::Planta;
	MatrizDePPDeAtaques[2] = 10;
	MatrizDeEfectividadDeAtaques[2] = 90;
	//strcpy(mensaje[2], "Usaste Drenadoras");
	MensajeIndex[2] = MensajeDeAtaque::MensajeNormal;

	strcpy(MatrizDeNombresDeAtaques[3], "Látigo Sepa");
	MatrizDeDanioDeAtaques[3] = 45;
	MatrizDeTipoDeAtaques[3] = Tipo::Planta;
	MatrizDePPDeAtaques[3] = 25;
	MatrizDeEfectividadDeAtaques[3] = 100;
	//strcpy(mensaje[3], "Usaste Látigo Sepa");
	MensajeIndex[3] = MensajeDeAtaque::MensajeNormal;

	strcpy(MatrizDeNombresDeAtaques[4], "Polvo Veneno");
	MatrizDeDanioDeAtaques[4] = 35;
	MatrizDeTipoDeAtaques[4] = Tipo::Veneno;
	MatrizDePPDeAtaques[4] = 35;
	MatrizDeEfectividadDeAtaques[4] = 75;
	//strcpy(mensaje[4], "Usaste Polvo Veneno, El rival parece envenedado");
	MensajeIndex[4] = MensajeDeAtaque::RivalEnvenenado1;

	strcpy(MatrizDeNombresDeAtaques[5], "Somnifero");
	MatrizDeDanioDeAtaques[5] = 0;
	MatrizDeTipoDeAtaques[5] = Tipo::Planta;
	MatrizDePPDeAtaques[5] = 15;
	MatrizDeEfectividadDeAtaques[5] = 75;
	//strcpy(mensaje[5], "Usaste Somnifero, El rival está profundamente dormido");
	MensajeIndex[5] = MensajeDeAtaque::RivalDormido1;

	strcpy(MatrizDeNombresDeAtaques[6], "Hoja Afilada");
	MatrizDeDanioDeAtaques[6] = 55;
	MatrizDeTipoDeAtaques[6] = Tipo::Planta;
	MatrizDePPDeAtaques[6] = 25;
	MatrizDeEfectividadDeAtaques[6] = 95;
	//strcpy(mensaje[6], "Usaste Hoja Afilida, y Provocaste un golpe CRÍTICO!");
	MensajeIndex[6] = MensajeDeAtaque::Critico;

	strcpy(MatrizDeNombresDeAtaques[7], "Dulce Aroma");
	MatrizDeDanioDeAtaques[7] = 0;
	MatrizDeTipoDeAtaques[7] = Tipo::Normal;
	MatrizDePPDeAtaques[7] = 20;
	MatrizDeEfectividadDeAtaques[7] = 100;
	//strcpy(mensaje[7], "La Evasion del rival bajo!");
	MensajeIndex[7] = MensajeDeAtaque::EvasionRivalBajo1;

	strcpy(MatrizDeNombresDeAtaques[8], "Desarrollo");
	MatrizDeDanioDeAtaques[8] = 0;
	MatrizDeTipoDeAtaques[8] = Tipo::Normal;
	MatrizDePPDeAtaques[8] = 20;
	MatrizDeEfectividadDeAtaques[8] = 100;
	//strcpy(mensaje[8], "El ataque subio!, El ataque Especial subió");
	MensajeIndex[8] = MensajeDeAtaque::MiAtaqueYEspecialSubio1;

	strcpy(MatrizDeNombresDeAtaques[9], "Sintesis");
	MatrizDeDanioDeAtaques[9] = 0;
	MatrizDeTipoDeAtaques[9] = Tipo::Planta;
	MatrizDePPDeAtaques[9] = 5;
	MatrizDeEfectividadDeAtaques[9] = 100;
	//strcpy(mensaje[9], "Usaste Sintesis, Tu HP subió");
	MensajeIndex[9] = MensajeDeAtaque::MiHPSubio1;

	strcpy(MatrizDeNombresDeAtaques[10], "Rayo Solar");
	MatrizDeDanioDeAtaques[10] = 120;
	MatrizDeTipoDeAtaques[10] = Tipo::Planta;
	MatrizDePPDeAtaques[10] = 10;
	MatrizDeEfectividadDeAtaques[10] = 100;
	//strcpy(mensaje[10], "Usaste Rayo Solar!, Tu pokemon está recargando energías");
	MensajeIndex[10] = MensajeDeAtaque::RecargandoEnergia;
}

PokemonPlanta::~PokemonPlanta(void){}

//Pokemones Tipo Planta
//bulbasur chikorita treeko cacnea lotad 
class Bulbasaur : public PokemonPlanta
{
public:
	Bulbasaur(void);
	~Bulbasaur(void);
};
Bulbasaur::Bulbasaur(void) : PokemonPlanta()
{
	Vitalidad = 500;
	Vida = Vitalidad;
	setAncho(80);
	setAlto(80);

	setDirImagenFront("Data\\Imagenes\\\\Pokemones\\Batalla\\bulbasaur_front.png");
	setDirImagenBack("Data\\Imagenes\\\\Pokemones\\Batalla\\bulbasaur_back.png");
	setNombre("Bulbasaur");

	AsignarAtaquesAleatorios();

}
Bulbasaur::~Bulbasaur(void){}
// 
class Chikorita : public PokemonPlanta
{
public:
	Chikorita(void);
	~Chikorita(void);
};
Chikorita::Chikorita(void) : PokemonPlanta()
{
	Vitalidad = 500;
	Vida = Vitalidad;
	setAncho(80);
	setAlto(80);

	setDirImagenFront("Data\\Imagenes\\\\Pokemones\\Batalla\\chikorita_front.png");
	setDirImagenBack("Data\\Imagenes\\\\Pokemones\\Batalla\\chikorita_back.png");
	setNombre("Chikorita");
	AsignarAtaquesAleatorios();

}
Chikorita::~Chikorita(void){}
//Treecko 
class Treecko : public PokemonPlanta
{
public:
	Treecko(void);
	~Treecko(void);
};
Treecko::Treecko(void) : PokemonPlanta()
{
	Vitalidad = 500;
	Vida = Vitalidad;
	setAncho(80);
	setAlto(80);

	setDirImagenFront("Data\\Imagenes\\\\Pokemones\\Batalla\\treecko_front.png");
	setDirImagenBack("Data\\Imagenes\\\\Pokemones\\Batalla\\treecko_back.png");
	setNombre("Treecko");
	AsignarAtaquesAleatorios();

}
Treecko::~Treecko(void){}
//Cacnea
class Cacnea : public PokemonPlanta
{
public:
	Cacnea(void);
	~Cacnea(void);
};
Cacnea::Cacnea(void) : PokemonPlanta()
{
	Vitalidad = 500;
	Vida = Vitalidad;
	setAncho(80);
	setAlto(80);

	setDirImagenFront("Data\\Imagenes\\\\Pokemones\\Batalla\\cacnea_front.png");
	setDirImagenBack("Data\\Imagenes\\\\Pokemones\\Batalla\\cacnea_back.png");
	setNombre("Cacnea");
	AsignarAtaquesAleatorios();

}
Cacnea::~Cacnea(void){}
//Lotad
class Lotad : public PokemonPlanta
{
public:
	Lotad(void);
	~Lotad(void);
};
Lotad::Lotad(void) : PokemonPlanta()
{
	Vitalidad = 500;
	Vida = Vitalidad;
	setAncho(80);
	setAlto(80);

	setDirImagenFront("Data\\Imagenes\\\\Pokemones\\Batalla\\lotad_front.png");
	setDirImagenBack("Data\\Imagenes\\\\Pokemones\\Batalla\\lotad_back.png");
	setNombre("Lotad");
	AsignarAtaquesAleatorios();

}
Lotad::~Lotad(void){}
