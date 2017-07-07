#pragma once

#include <stdlib.h>
#include <string.h>
#include "Enums.h"

class Pokemon
{
protected:
	//Atributos
	int XImagen;
	int YImagen;
	int Ancho;
	int Alto;
	int Tipo;
	int Vida;
	int Vitalidad;
	int Experiencia;
	int Nivel;
	int UltimoDanio;
	int Danio1;
	int Danio2;
	int Danio3;
	int Danio4;
	int PertenenciaPokemon;
	char * Nombre;
	char * DirImagenFront;
	char * DirImagenBack;
	

public:
		 Pokemon(void);//Constructor
		~Pokemon(void);//Destructor

		char ** NombresDeAtaques;
		char ** MatrizDeNombresDeAtaques;
		int * MensajeIndex;
		int * TipoDeMensajeDeAtaques;
		int * MatrizDeTipoDeAtaques;
		int * MatrizDeDanioDeAtaques;
		int * MatrizDePPDeAtaques;
		int * MatrizDeEfectividadDeAtaques;

	//METODOS DE ACCESO
		// GET
		int getXImagen();
		int getYImagen();
		int getAncho();
		int getAlto();
		int getTipo();
		int getVida();
		int getVitalidad();
		int getExperiencia();
		int getNivel();
		int getUltimoDanio();
		int getDanio1();
		int getDanio2();
		int getDanio3();
		int getDanio4();
		int getPertenenciaPokemon();
		char* getNombre();
		char* getAtaque(int IndexAtaque);
		char* getDirImagen();
		
		//SET
		void setXImagen(int NuevoXImagen);
		void setYImagen(int NuevaYImagen);
		void setAncho(int NuevoAncho);
		void setAlto(int NuevoAlto);
		void setTipo(int NuevoTipo);
		void setVida(int NuevaVida);
		void setVitalidad(int NuevaVitalidad);
		void setExperiencia(int NuevaExperiencia);
		void setNivel(int NuevoNivel);
		void setUltimoDanio(int NuevoDanio);
		void setDanio1(int NuevoDanio1);
		void setDanio2(int NuevoDanio2);
		void setDanio3(int NuevoDanio3);
		void setDanio4(int NuevoDanio4);
		void setPertenenciaPokemon(int NuevoPertenenciaPokemon);
		void setNombre(char* NuevoNombre);
		void setDirImagenFront(char* NuevaDirImagenFront);
		void setDirImagenBack(char* NuevaDirImagenFront);
		void setAtaque(int IndexAtaque, char* NuevoAtaque);

		//OTROS METODOS
		void AsignarAtaquesAleatorios();
		void DibujarPokemon(Graphics^ Graphic, int EsquinaX, int EsquinaY, int NuevoAncho, int NuevoAlto);
		void CurarPokemon();
};

//Constructor
Pokemon::Pokemon(void)
{
	UltimoDanio = 0;
	Experiencia = 0;
	Nivel = 1;
	MatrizDeNombresDeAtaques = new char*[15];
	NombresDeAtaques = new char*[4];
	MatrizDeDanioDeAtaques = new int[15];
	MensajeIndex = new int[15];
	MatrizDeTipoDeAtaques = new int[15];
	MatrizDePPDeAtaques = new int[15];
	MatrizDeEfectividadDeAtaques = new int[15];
	TipoDeMensajeDeAtaques = new int[4];
	for (int i = 0; i <= 14; i++)
	{
		MatrizDeNombresDeAtaques[i] = new char[20];
	}

	for (int i = 0; i <= 3; i++)
	{
		NombresDeAtaques[i] = new char[20];
	}

	PertenenciaPokemon = Pertenencia::Salvaje;
	Nombre = new char[15];
	DirImagenFront = new char[100];
	DirImagenBack = new char[100];
}

//Destructor
Pokemon::~Pokemon()
{
	delete[] Nombre;
	delete[] DirImagenFront;
	delete[] DirImagenBack;
}


// Metodos GET
int Pokemon::getXImagen(){ return XImagen; }
int Pokemon::getYImagen(){ return YImagen; }
int Pokemon::getTipo(){ return Tipo; }
int Pokemon::getVida(){ return Vida; }
int Pokemon::getVitalidad(){ return Vitalidad; }
int Pokemon::getExperiencia(){ return Experiencia; }
int Pokemon::getNivel(){ return Nivel; }
int Pokemon::getAncho(){ return Ancho; }
int Pokemon::getAlto(){ return Alto; }
int Pokemon::getUltimoDanio(){ return UltimoDanio; }
int Pokemon::getDanio1(){ return Danio1; }
int Pokemon::getDanio2(){ return Danio2; }
int Pokemon::getDanio3(){ return Danio3; }
int Pokemon::getDanio4(){ return Danio4; }
int Pokemon::getPertenenciaPokemon(){ return PertenenciaPokemon; }
char* Pokemon::getNombre(){ return Nombre; }
char* Pokemon::getAtaque(int IndexAtaque){ return NombresDeAtaques[IndexAtaque]; }

char* Pokemon::getDirImagen()
{
	if (PertenenciaPokemon == Pertenencia::DeMarco)
		return DirImagenBack;
	else
		return DirImagenFront;
}

//Metodos SET
void Pokemon::setVitalidad(int NuevaVitalidad){ Vitalidad = NuevaVitalidad; }
void Pokemon::setXImagen(int NuevoXImagen){ XImagen = NuevoXImagen; }
void Pokemon::setYImagen(int NuevaYImagen){ YImagen = NuevaYImagen; }
void Pokemon::setUltimoDanio(int NuevoDanio){ UltimoDanio = NuevoDanio; }
void Pokemon::setDanio1(int NuevoDanio1){ Danio1 = NuevoDanio1; }
void Pokemon::setDanio2(int NuevoDanio2){ Danio2 = NuevoDanio2; }
void Pokemon::setDanio3(int NuevoDanio3){ Danio3 = NuevoDanio3; }
void Pokemon::setDanio4(int NuevoDanio4){ Danio4 = NuevoDanio4; }
void Pokemon::setAncho(int NuevoAncho){ Ancho = NuevoAncho; }
void Pokemon::setAlto(int NuevoAlto){ Alto = NuevoAlto; }
void Pokemon::setTipo(int NuevoTipo){ Tipo = NuevoTipo; }
void Pokemon::setVida(int NuevaVida){ Vida = NuevaVida; }
void Pokemon::setExperiencia(int NuevaExperiencia){ Experiencia = NuevaExperiencia; }
void Pokemon::setNivel(int NuevoNivel){ Nivel = NuevoNivel; }
void Pokemon::setPertenenciaPokemon(int NuevoPertenenciaPokemon){ PertenenciaPokemon = NuevoPertenenciaPokemon; }
void Pokemon::setNombre(char* NuevoNombre){ strcpy(Nombre, NuevoNombre); }
void Pokemon::setAtaque(int IndexAtaque, char* NuevoAtaque){ strcpy(NombresDeAtaques[IndexAtaque], NuevoAtaque); }
void Pokemon::setDirImagenFront(char* NuevaDirImagenFront){ strcpy(DirImagenFront, NuevaDirImagenFront); }
void Pokemon::setDirImagenBack(char* NuevaDirImagenBack){ strcpy(DirImagenBack, NuevaDirImagenBack); }

void Pokemon::AsignarAtaquesAleatorios()
{
	Random VariableRandom;
	int EnteroRandom;
	
	EnteroRandom = VariableRandom.Next(0, 11);
	strcpy(NombresDeAtaques[0], MatrizDeNombresDeAtaques[EnteroRandom]);
	TipoDeMensajeDeAtaques[0] = MensajeIndex[EnteroRandom];
	Danio1 = MatrizDeDanioDeAtaques[EnteroRandom];
	int Auxiliar0 = EnteroRandom;
	
	do
	{
		EnteroRandom = VariableRandom.Next(0, 11);
		strcpy(NombresDeAtaques[1], MatrizDeNombresDeAtaques[EnteroRandom]);
		TipoDeMensajeDeAtaques[1] = MensajeIndex[EnteroRandom];
		Danio2 = MatrizDeDanioDeAtaques[EnteroRandom];
	} while (EnteroRandom == Auxiliar0);
	int Auxiliar1 = EnteroRandom;

	do
	{
		EnteroRandom = VariableRandom.Next(0, 11);
		strcpy(NombresDeAtaques[2], MatrizDeNombresDeAtaques[EnteroRandom]);
		TipoDeMensajeDeAtaques[2] = MensajeIndex[EnteroRandom];
		Danio3 = MatrizDeDanioDeAtaques[EnteroRandom];
	} while (EnteroRandom == Auxiliar0 || EnteroRandom == Auxiliar1);
	int Auxiliar2 = EnteroRandom;
	
	do
	{
		EnteroRandom = VariableRandom.Next(0, 11);
		strcpy(NombresDeAtaques[3], MatrizDeNombresDeAtaques[EnteroRandom]);
		TipoDeMensajeDeAtaques[3] = MensajeIndex[EnteroRandom];
		Danio4 = MatrizDeDanioDeAtaques[EnteroRandom];
	} while (EnteroRandom == Auxiliar0 || EnteroRandom == Auxiliar1 || EnteroRandom == Auxiliar2);

}

void Pokemon::DibujarPokemon(Graphics^ Graphic,int EsquinaX, int EsquinaY, int NuevoAncho, int NuevoAlto)
{
	Graphic->DrawImage(
		gcnew Bitmap(gcnew String(getDirImagen())),//--------->Imagen del Pokemon
		Rectangle(EsquinaX, EsquinaY, NuevoAncho, NuevoAlto),//Destino y Tamaño de la Imagen
		Rectangle(0, 0, Ancho, Alto),//----------------------->Porcion de la Imagen
		GraphicsUnit::Pixel//--------------------------------->Unidad de Medicion
		);
}

void Pokemon::CurarPokemon()
{
	Vida = Vitalidad;
}



