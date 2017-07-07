#pragma once
#include <string.h>

using namespace System;
using namespace System::Drawing;

enum Fondos
{
MenuPrincipal,
Introduccion,
EscogerPokemones,
ChoosePokemones,
BatallaSalvaje,
Ganaste,
Perdiste,
CPokemon1,
CPokemon2,
CPokemon3,
AokiSama,
Intro1,
Intro2,
Intro3,
};

enum PNGS
{
PresionaStart,
Boton1,
Boton2,
Boton3,
Boton4,
Boton5,
Boton6,
BotonA,
BotonS,
BotonZ,
BotonX,
CuadroDialogo
};



class Fondo
{
protected:
	char** DireccionDelFondo;
	char** DireccionDelPNG;
public:
	Fondo();
	~Fondo();
	void MostrarFondo(Graphics^ Graphic, Fondos FondoParaMostrar);
	void MostrarPNG(Graphics^ Graphic, PNGS PNGParaMostrar, int EsquinaX, int EsquinaY, int NuevoAncho, int NuevoAlto, int Ancho, int Alto);
};

Fondo::Fondo()
{
	DireccionDelFondo = new char*[20];
	DireccionDelPNG = new char*[20];

	for (int i = 0; i <= 19; i++)
	{
		DireccionDelFondo[i] = new char[100];
		DireccionDelPNG[i] = new char[100];
	}


	strcpy(DireccionDelFondo[Fondos::MenuPrincipal], "Data\\Imagenes\\Interfaces\\MenuPrincipal.png");
	strcpy(DireccionDelFondo[Fondos::EscogerPokemones], "Data\\Imagenes\\Interfaces\\EscogerPokemon.png");
	strcpy(DireccionDelFondo[Fondos::ChoosePokemones], "Data\\Imagenes\\Fondos\\EscogePokemon.png");
	strcpy(DireccionDelFondo[Fondos::BatallaSalvaje], "Data\\Imagenes\\Fondos\\BatallaSalvaje.png");
	strcpy(DireccionDelFondo[Fondos::Ganaste], "Data\\Imagenes\\Fondos\\Congratulations.png");
	strcpy(DireccionDelFondo[Fondos::Perdiste], "Data\\Imagenes\\Fondos\\GameOver.png");
	strcpy(DireccionDelFondo[Fondos::CPokemon1], "Data\\Imagenes\\Fondos\\EnfermeraJoy.png");
	strcpy(DireccionDelFondo[Fondos::CPokemon2], "Data\\Imagenes\\Fondos\\AshKetchup.png");
	strcpy(DireccionDelFondo[Fondos::CPokemon3], "Data\\Imagenes\\Fondos\\PokemonesCurados.png");
	strcpy(DireccionDelFondo[Fondos::AokiSama], "Data\\Imagenes\\Fondos\\Oak.png");
	strcpy(DireccionDelFondo[Fondos::Intro1], "Data\\Imagenes\\Fondos\\Introduccion1.png");
	strcpy(DireccionDelFondo[Fondos::Intro2], "Data\\Imagenes\\Fondos\\Introduccion2.png");
	strcpy(DireccionDelFondo[Fondos::Intro3], "Data\\Imagenes\\Fondos\\Introduccion3.png");


	strcpy(DireccionDelPNG[PNGS::PresionaStart], "Data\\Imagenes\\PNGs\\PresionaStart.png");
	strcpy(DireccionDelPNG[PNGS::BotonA], "Data\\Imagenes\\PNGs\\A.png");
	strcpy(DireccionDelPNG[PNGS::BotonS], "Data\\Imagenes\\PNGs\\S.png");
	strcpy(DireccionDelPNG[PNGS::BotonZ], "Data\\Imagenes\\PNGs\\Z.png");
	strcpy(DireccionDelPNG[PNGS::BotonX], "Data\\Imagenes\\PNGs\\X.png");
	strcpy(DireccionDelPNG[PNGS::Boton1], "Data\\Imagenes\\PNGs\\1.png");
	strcpy(DireccionDelPNG[PNGS::Boton2], "Data\\Imagenes\\PNGs\\2.png");
	strcpy(DireccionDelPNG[PNGS::Boton3], "Data\\Imagenes\\PNGs\\3.png");
	strcpy(DireccionDelPNG[PNGS::Boton4], "Data\\Imagenes\\PNGs\\4.png");
	strcpy(DireccionDelPNG[PNGS::Boton5], "Data\\Imagenes\\PNGs\\5.png");
	strcpy(DireccionDelPNG[PNGS::Boton6], "Data\\Imagenes\\PNGs\\6.png");
	strcpy(DireccionDelPNG[PNGS::CuadroDialogo], "Data\\Imagenes\\PNGs\\Dialogo.png");

}

Fondo::~Fondo()
{
	for (int i = 0; i <= 9; i++)
	{
		delete[] DireccionDelFondo[i];
		delete[] DireccionDelPNG[i];
	}

	delete[] DireccionDelFondo;
	delete[] DireccionDelPNG;


}

void Fondo::MostrarFondo(Graphics^ Graphic, Fondos FondoParaMostrar)
{
	Graphic->DrawImage(
		gcnew Bitmap(gcnew String(DireccionDelFondo[FondoParaMostrar])),//Imagen del Pokemon
		Rectangle(0, 0, 720, 480),//------------------------------------->Destino de la Imagen
		Rectangle(0, 0, 720, 480),//------------------------------------->Porcion de la Imagen
		GraphicsUnit::Pixel//-------------------------------------------->Unidad de Medicion
		);
}

void Fondo::MostrarPNG(Graphics^ Graphic, PNGS PNGParaMostrar, int EsquinaX, int EsquinaY, int NuevoAncho, int NuevoAlto, int Ancho, int Alto)
{
	Graphic->DrawImage(
		gcnew Bitmap(gcnew String(DireccionDelPNG[PNGParaMostrar])),//Imagen del Pokemon
		Rectangle(EsquinaX, EsquinaY, NuevoAncho, NuevoAlto),//------------------------------------->Destino de la Imagen
		Rectangle(0, 0, Ancho, Alto),//------------------------------------->Porcion de la Imagen
		GraphicsUnit::Pixel//-------------------------------------------->Unidad de Medicion
		);
}
