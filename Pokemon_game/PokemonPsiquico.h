//clase pokemon tipo psiquico
#pragma once
#include "Pokemon.h"
//Psiquico
//psiquico
class PokemonPsiquico : public Pokemon
{
public:
	PokemonPsiquico(void);
	~PokemonPsiquico(void);
};

PokemonPsiquico::PokemonPsiquico(void) : Pokemon()
{
	//supongo tipo 5
	Tipo == 5;
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

	strcpy(MatrizDeNombresDeAtaques[2], "Destructor");
	MatrizDeDanioDeAtaques[2] = 40;
	MatrizDeTipoDeAtaques[2] = Tipo::Normal;
	MatrizDePPDeAtaques[2] = 35;
	MatrizDeEfectividadDeAtaques[2] = 100;
	//strcpy(mensaje[2], "Usaste Destructor");
	MensajeIndex[2] = MensajeDeAtaque::MensajeNormal;

	strcpy(MatrizDeNombresDeAtaques[3], "Transformacion");
	MatrizDeDanioDeAtaques[3] = 0;
	MatrizDeTipoDeAtaques[3] = Tipo::Planta;
	MatrizDePPDeAtaques[3] = 25;
	MatrizDeEfectividadDeAtaques[3] = 100;
	//strcpy(mensaje[3], "Usaste Látigo Sepa");
	MensajeIndex[3] = MensajeDeAtaque::MensajeNormal;

	strcpy(MatrizDeNombresDeAtaques[4], "Mega puño");
	MatrizDeDanioDeAtaques[4] = 35;
	MatrizDeTipoDeAtaques[4] = Tipo::Veneno;
	MatrizDePPDeAtaques[4] = 35;
	MatrizDeEfectividadDeAtaques[4] = 75;
	//strcpy(mensaje[4], "Usaste Polvo Veneno, El rival parece envenedado");
	MensajeIndex[4] = MensajeDeAtaque::RivalEnvenenado1;

	strcpy(MatrizDeNombresDeAtaques[5], "MEtrónomo");
	MatrizDeDanioDeAtaques[5] = 0;
	MatrizDeTipoDeAtaques[5] = Tipo::Planta;
	MatrizDePPDeAtaques[5] = 15;
	MatrizDeEfectividadDeAtaques[5] = 75;
	//strcpy(mensaje[5], "Usaste Somnifero, El rival está profundamente dormido");
	MensajeIndex[5] = MensajeDeAtaque::RivalDormido1;

	strcpy(MatrizDeNombresDeAtaques[6], "Psiquico");
	MatrizDeDanioDeAtaques[6] = 55;
	MatrizDeTipoDeAtaques[6] = Tipo::Planta;
	MatrizDePPDeAtaques[6] = 25;
	MatrizDeEfectividadDeAtaques[6] = 95;
	//strcpy(mensaje[6], "Usaste Hoja Afilida, y Provocaste un golpe CRÍTICO!");
	MensajeIndex[6] = MensajeDeAtaque::Critico;

	strcpy(MatrizDeNombresDeAtaques[7], "Poder pasado");
	MatrizDeDanioDeAtaques[7] = 0;
	MatrizDeTipoDeAtaques[7] = Tipo::Normal;
	MatrizDePPDeAtaques[7] = 20;
	MatrizDeEfectividadDeAtaques[7] = 100;
	//strcpy(mensaje[7], "La Evasion del rival bajo!");
	MensajeIndex[7] = MensajeDeAtaque::EvasionRivalBajo1;

	strcpy(MatrizDeNombresDeAtaques[8], "Barrera");
	MatrizDeDanioDeAtaques[8] = 0;
	MatrizDeTipoDeAtaques[8] = Tipo::Normal;
	MatrizDePPDeAtaques[8] = 20;
	MatrizDeEfectividadDeAtaques[8] = 100;
	//strcpy(mensaje[8], "El ataque subio!, El ataque Especial subió");
	MensajeIndex[8] = MensajeDeAtaque::MiAtaqueYEspecialSubio1;

	strcpy(MatrizDeNombresDeAtaques[9], "Esfera Aural");
	MatrizDeDanioDeAtaques[9] = 0;
	MatrizDeTipoDeAtaques[9] = Tipo::Planta;
	MatrizDePPDeAtaques[9] = 5;
	MatrizDeEfectividadDeAtaques[9] = 100;
	//strcpy(mensaje[9], "Usaste Sintesis, Tu HP subió");
	MensajeIndex[9] = MensajeDeAtaque::MiHPSubio1;

	strcpy(MatrizDeNombresDeAtaques[10], "Amnesia");
	MatrizDeDanioDeAtaques[10] = 120;
	MatrizDeTipoDeAtaques[10] = Tipo::Planta;
	MatrizDePPDeAtaques[10] = 10;
	MatrizDeEfectividadDeAtaques[10] = 100;
	//strcpy(mensaje[10], "Usaste Rayo Solar!, Tu pokemon está recargando energías");
	MensajeIndex[10] = MensajeDeAtaque::RecargandoEnergia;
}

PokemonPsiquico::~PokemonPsiquico(void){}

//Pokemones Tipo psiquico
//Abra Mew Wobbufet  Garvedoir Natu 
class Abra : public PokemonPsiquico
{
public:
	Abra(void);
	~Abra(void);
};
Abra::Abra(void) : PokemonPsiquico()
{
	Vitalidad = 500;
	Vida = Vitalidad;
	setAncho(80);
	setAlto(80);

	setDirImagenFront("Data\\Imagenes\\\\Pokemones\\Batalla\\abra_front.png");
	setDirImagenBack("Data\\Imagenes\\\\Pokemones\\Batalla\\abra_back.png");
	setNombre("Abra");

	AsignarAtaquesAleatorios();

}
Abra::~Abra(void){}
// 
class Mew : public PokemonPsiquico
{
public:
	Mew(void);
	~Mew(void);
};
Mew::Mew(void) : PokemonPsiquico()
{
	Vitalidad = 500;
	Vida = Vitalidad;
	setAncho(80);
	setAlto(80);

	setDirImagenFront("Data\\Imagenes\\\\Pokemones\\Batalla\\mew_front.png");
	setDirImagenBack("Data\\Imagenes\\\\Pokemones\\Batalla\\mew_back.png");
	setNombre("Mew");
	AsignarAtaquesAleatorios();

}
Mew::~Mew(void){}
//Wobbufet 
class Wobbufet : public PokemonPsiquico
{
public:
	Wobbufet(void);
	~Wobbufet(void);
};
Wobbufet::Wobbufet(void) : PokemonPsiquico()
{
	Vitalidad = 500;
	Vida = Vitalidad;
	setAncho(80);
	setAlto(80);

	setDirImagenFront("Data\\Imagenes\\\\Pokemones\\Batalla\\wobbufet_front.png");
	setDirImagenBack("Data\\Imagenes\\\\Pokemones\\Batalla\\wobbufet_back.png");
	setNombre("Wobbufet");
	AsignarAtaquesAleatorios();

}
Wobbufet::~Wobbufet(void){}
//Garvedoir
class Garvedoir : public PokemonPsiquico
{
public:
	Garvedoir(void);
	~Garvedoir(void);
};
Garvedoir::Garvedoir(void) : PokemonPsiquico()
{
	Vitalidad = 500;
	Vida = Vitalidad;
	setAncho(80);
	setAlto(80);
	setNombre("Garvedoir");
	setDirImagenFront("Data\\Imagenes\\\\Pokemones\\Batalla\\garvedoir_front.png");
	setDirImagenBack("Data\\Imagenes\\\\Pokemones\\Batalla\\garvedoir_back.png");

	AsignarAtaquesAleatorios();

}
Garvedoir::~Garvedoir(void){}
//Natu
class Natu : public PokemonPsiquico
{
public:
	Natu(void);
	~Natu(void);
};
Natu::Natu(void) : PokemonPsiquico()
{
	Vitalidad = 500;
	Vida = Vitalidad;
	setAncho(80);
	setAlto(80);

	setDirImagenFront("Data\\Imagenes\\\\Pokemones\\Batalla\\natu_front.png");
	setDirImagenBack("Data\\Imagenes\\\\Pokemones\\Batalla\\natu_back.png");
	setNombre("Natu");
	AsignarAtaquesAleatorios();

}
Natu::~Natu(void){}