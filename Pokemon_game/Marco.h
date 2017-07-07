#pragma once
#include"Entrenador.h"
#include "Lugar.h"

class Marco : public Entrenador
{
protected:
	int PseudoX;
	int PseudoY;
	bool Medalla1;
	bool Medalla2;
	bool Medalla3;
	bool Medalla4;
	bool Medalla5;
	bool Medalla6;
public:
	Lugares LugarActual;
	Lugares	ProximoLugar;
	int NuevaCordX;
	int NuevaCordY;
	int Sprite;
	 Marco(void);
	~Marco(void);
	int getPseudoX();
	int getPseudoY();
	bool getMedalla1();
	bool getMedalla2();
	bool getMedalla3();
	bool getMedalla4();
	bool getMedalla5();
	bool getMedalla6();
	void setPseudoX(int NuevoX);
	void setPseudoY(int NuevoY);
	void setMedalla1(bool Nuevo);
	void setMedalla2(bool Nuevo);
	void setMedalla3(bool Nuevo);
	void setMedalla4(bool Nuevo);
	void setMedalla5(bool Nuevo);
	void setMedalla6(bool Nuevo);
	void MostrarEnBatalla(Graphics^ Graphic);
	void MostrarMiniatura(Graphics^ Graphic, Movimiento Direccion);
	void Mover(Graphics^ miGraphic);
};

Marco::Marco(void) : Entrenador()
{
	LugarActual = Lugares::Plazuela;
	Sprite = Movimiento::Abajo2;
	PseudoX = 10;
	PseudoY = 10;
	Medalla1 = false;
	Medalla2 = false;
	Medalla3 = false;
	Medalla4 = false;
	Medalla5 = false;
	Medalla6 = false;
	AnchoBatalla = 80;
	AltoBatalla = 80;
	AnchoMiniatura = 102;
	AltoMiniatura = 200;
	PertenenciaPokemon = Pertenencia::DeMarco;
	strcpy(Nombre,"Cachimbo");
	strcpy(DirImagenBatalla, "Data\\Imagenes\\\\Pokemones\\Batalla\\squirtle_back.png");
	strcpy(DirSpritesMiniatura, "Data\\Imagenes\\Personajes\\Marco\\Marco.png");
}
Marco::~Marco(void){}

int Marco::getPseudoX(){ return PseudoX; }
int Marco::getPseudoY(){ return PseudoY; }
bool Marco::getMedalla1(){ return Medalla1; }
bool Marco::getMedalla2(){ return Medalla2; }
bool Marco::getMedalla3(){ return Medalla3; }
bool Marco::getMedalla4(){ return Medalla4; }
bool Marco::getMedalla5(){ return Medalla5; }
bool Marco::getMedalla6(){ return Medalla6; }
void Marco::setPseudoX(int NuevoX){ PseudoX = NuevoX; }
void Marco::setPseudoY(int NuevoY){ PseudoY = NuevoY; }
void Marco::setMedalla1(bool Nuevo){ Medalla1 = Nuevo; }
void Marco::setMedalla2(bool Nuevo){ Medalla2 = Nuevo; }
void Marco::setMedalla3(bool Nuevo){ Medalla3 = Nuevo; }
void Marco::setMedalla4(bool Nuevo){ Medalla4 = Nuevo; }
void Marco::setMedalla5(bool Nuevo){ Medalla5 = Nuevo; }
void Marco::setMedalla6(bool Nuevo){ Medalla6 = Nuevo; }

void Marco::MostrarEnBatalla(Graphics^ Graphic){}

Rectangle rAbajo1 = Rectangle(0, 0, 34, 50);
Rectangle rAbajo2 = Rectangle(34, 0, 34, 50);
Rectangle rAbajo3 = Rectangle(68, 0, 34, 50);
Rectangle rArriba1 = Rectangle(0, 150, 34, 50);
Rectangle rArriba2 = Rectangle(34, 150, 34, 50);
Rectangle rArriba3 = Rectangle(68, 150, 34, 50);
Rectangle rDerecha1 = Rectangle(0, 100, 34, 50);
Rectangle rDerecha2 = Rectangle(34, 100, 34, 50);
Rectangle rDerecha3 = Rectangle(68, 100, 34, 50);
Rectangle rIzquierda1 = Rectangle(0, 50, 34, 50);
Rectangle rIzquierda2 = Rectangle(34, 50, 34, 50);
Rectangle rIzquierda3 = Rectangle(68, 50, 34, 50);

void Marco::MostrarMiniatura(Graphics^ Graphic , Movimiento Direccion)
{
	Rectangle rMirada;

	if (Direccion == Movimiento::Derecha1) rMirada = rDerecha1;
	if (Direccion == Movimiento::Derecha2) rMirada = rDerecha2;
	if (Direccion == Movimiento::Derecha3) rMirada = rDerecha3;
	if (Direccion == Movimiento::Izquierda1) rMirada = rIzquierda1;
	if (Direccion == Movimiento::Izquierda2) rMirada = rIzquierda2;
	if (Direccion == Movimiento::Izquierda3) rMirada = rIzquierda3;
	if (Direccion == Movimiento::Arriba1) rMirada = rArriba1;
	if (Direccion == Movimiento::Arriba2) rMirada = rArriba2;
	if (Direccion == Movimiento::Arriba3) rMirada = rArriba3;
	if (Direccion == Movimiento::Abajo1) rMirada = rAbajo1;
	if (Direccion == Movimiento::Abajo2) rMirada = rAbajo2;
	if (Direccion == Movimiento::Abajo3) rMirada = rAbajo3;

	Graphic->DrawImage(
		gcnew Bitmap(gcnew String(DirSpritesMiniatura)),
		Rectangle(343,215,34,50),//Destino y Tamaño de la Imagen
		rMirada,//----------------------->Porcion de la Imagen
		GraphicsUnit::Pixel//--------------------------------->Unidad de Medicion
		);
}

void Marco::Mover(Graphics^ miGraphic)
{

}