#pragma once
#include "Enums.h"


class Lugar
{
protected:
	int* AnchoReal;
	int* AltoReal;
	char** DireccionImagen;
public:
	Lugar(void);
	~Lugar(void);

	void DibujarLugar(Graphics^ miGraphic, Lugares LugarQueSeDibujara, int PosicionMarcoX, int PosicionMarcoY);
	void DibujarPorcion(Graphics^ miGraphic, Lugares LugarQueSeDibujara,  int dX, int dY, int cX, int cY , int Alto, int Ancho);
};

Lugar::Lugar(void)
{
	AnchoReal = new int[10];
	AltoReal = new int[10];
	DireccionImagen = new char*[10];



	for (int i = 0; i <= 9; i++)
		DireccionImagen[i] = new char[100];

	AnchoReal[Lugares::Plazuela] = 24;
	AltoReal[Lugares::Plazuela] = 28;
	DireccionImagen[Lugares::Plazuela] = "Data\\Imagenes\\Lugares\\Plazuela.png";
}

Lugar::~Lugar(void){}

gcroot<Image^> imgPlazuela = Image::FromFile("Data\\Imagenes\\Lugares\\Plazuela.png");
gcroot<Image^> imgCentroPokemon = Image::FromFile("Data\\Imagenes\\Lugares\\CentroPokemon.png");
gcroot<Image^> imgGimnasioPlanta = Image::FromFile("Data\\Imagenes\\Lugares\\GimnasioPlanta.png");
gcroot<Image^> imgGimnasioNormal = Image::FromFile("Data\\Imagenes\\Lugares\\GimnasioNormal.png");
gcroot<Image^> imgGimansioAgua = Image::FromFile("Data\\Imagenes\\Lugares\\GimnasioAgua.png");

void Lugar::DibujarLugar(Graphics^ miGraphic, Lugares LugarQueSeDibujara, int PosicionMarcoX, int PosicionMarcoY)
{
	switch (LugarQueSeDibujara)
	{
	case Plazuela:
		miGraphic->DrawImage(
			imgPlazuela,
			Rectangle(0, 0, 720, 480),//------------------------------------->Destino de la Imagen
			Rectangle(PosicionMarcoX - 336, PosicionMarcoY - 192, 720, 480),
			GraphicsUnit::Pixel//-------------------------------------------->Unidad de Medicion
			);
		break;
	
	case CentroPokemon:
		miGraphic->DrawImage(
			imgCentroPokemon,
			Rectangle(0, 0, 720, 480),//------------------------------------->Destino de la Imagen
			Rectangle(PosicionMarcoX - 336, PosicionMarcoY - 192, 720, 480),
			GraphicsUnit::Pixel//-------------------------------------------->Unidad de Medicion
			);
		break;
	case GimnasioNormal:
		miGraphic->DrawImage(
			imgGimnasioNormal,
			Rectangle(0, 0, 720, 480),//------------------------------------->Destino de la Imagen
			Rectangle(PosicionMarcoX - 336, PosicionMarcoY - 192, 720, 480),
			GraphicsUnit::Pixel//-------------------------------------------->Unidad de Medicion
			);
		break;
	case GimnasioAgua:
		miGraphic->DrawImage(
			imgGimansioAgua,
			Rectangle(0, 0, 720, 480),//------------------------------------->Destino de la Imagen
			Rectangle(PosicionMarcoX - 336, PosicionMarcoY - 192, 720, 480),
			GraphicsUnit::Pixel//-------------------------------------------->Unidad de Medicion
			);
		break;
	case GimnasioPlanta:
		miGraphic->DrawImage(
			imgGimnasioPlanta,
			Rectangle(0, 0, 720, 480),//------------------------------------->Destino de la Imagen
			Rectangle(PosicionMarcoX - 336, PosicionMarcoY - 192, 720, 480),
			GraphicsUnit::Pixel//-------------------------------------------->Unidad de Medicion
			);
		break;
	}
}


void Lugar::DibujarPorcion(Graphics^ miGraphic, Lugares LugarQueSeDibujara, int dx, int dy, int cX, int cY, int Alto, int Ancho)
{
	switch (LugarQueSeDibujara)
	{
	case Plazuela:
		miGraphic->DrawImage(
			imgPlazuela,
			Rectangle(dx, dy, Ancho, Alto),//------------------------------------->Destino de la Imagen
			Rectangle(cX, cY, Ancho, Alto),
			GraphicsUnit::Pixel//-------------------------------------------->Unidad de Medicion
			);
		break;
	case CentroPokemon:
		miGraphic->DrawImage(
			imgCentroPokemon,
			Rectangle(dx, dy, Ancho, Alto),//------------------------------------->Destino de la Imagen
			Rectangle(cX, cY, Ancho, Alto),
			GraphicsUnit::Pixel//-------------------------------------------->Unidad de Medicion
			);
		break;
	case GimnasioAgua:
		miGraphic->DrawImage(
			imgGimansioAgua,
			Rectangle(dx, dy, Ancho, Alto),//------------------------------------->Destino de la Imagen
			Rectangle(cX, cY, Ancho, Alto),
			GraphicsUnit::Pixel//-------------------------------------------->Unidad de Medicion
			);
		break;
	case GimnasioNormal:
		miGraphic->DrawImage(
			imgGimnasioNormal,
			Rectangle(dx, dy, Ancho, Alto),//------------------------------------->Destino de la Imagen
			Rectangle(cX, cY, Ancho, Alto),
			GraphicsUnit::Pixel//-------------------------------------------->Unidad de Medicion
			);
		break;
	case GimnasioPlanta:
		miGraphic->DrawImage(
			imgGimnasioPlanta,
			Rectangle(dx, dy, Ancho, Alto),//------------------------------------->Destino de la Imagen
			Rectangle(cX, cY, Ancho, Alto),
			GraphicsUnit::Pixel//-------------------------------------------->Unidad de Medicion
			);
		break;

	}
}