#pragma once
#include "Batalla.h"
#include "Fondo.h"
#include <iostream>

using namespace System;
using namespace System::Drawing;

class Juego
{
protected:
	
	Fondo* misFondos;
	Lugar* misLugares;
	int EstadoDeImagen;
	int Escena;

public:
	Juego(void);
	~Juego(void);

	Marco* Yo;
	PrimerLider* Nagayoshi;
	SegundoLider* Crayon;
	TercerLider* Bicugo;
	Batalla* miBatalla;
	int EstadoDialogo;
	int getEscena();
	int getEstadoDeImagen();
	int qMedallas;
	void setEscena(int NuevaEscena);
	void setEstadoDeImagen(Estado NuevoEstadoDeImagen);

	void Escena1_Mostrar(Graphics^ miGraphic);
	void Escena1_Boton1(Graphics^ miGraphic);

	void EscogerPokemon(Graphics^ miGraphic);
	void Escena3_Escoger(Tecla TeclaDireccional);

	Batalla* getBatalla();
	Lugar* getMisLugares();
	bool TerminoLaBatalla(Batalla* LaBatalla);
	void FinBatalla(BufferedGraphics^ miBuffered , Graphics^ miGraphic);
	void Batalla_CrearBatalla();
	void Batalla_Atacar(BufferedGraphics^ miBuffer , Graphics^ miGraphic, Tecla TeclaDireccional );
	void Batalla_Defender(BufferedGraphics^ miBuffer , Graphics^ miGraphic );
	void Batalla_Huida(BufferedGraphics^ miBuffer, Graphics^ miGraphic);
	void Batalla_LanzarPokebola(BufferedGraphics^ miBuffer, Graphics^ miGraphic);
	void Batalla_CambiarPokemon(Tecla LaTecla);
	void Batalla_EscogerPokemon(BufferedGraphics^ miBuffer, Graphics^ miGraphic);

	void EscenaCentroPokemon(BufferedGraphics^ MiBuffer, Graphics^ miGraphic);
	void EscenaAOki(BufferedGraphics^ MiBuffer, Graphics^ miGraphic);
	void EscenaIntro(BufferedGraphics^ MiBuffer, Graphics^ miGraphic);
	void MostarMedallas(BufferedGraphics^ MiBuffer, Graphics^ miGraphic);

	void Mapa_ConsultarBloque(BufferedGraphics^ miBuffer, Graphics^ miGraphics);
	void Mapa_AccionTerreno(BufferedGraphics^ miBuffer, Graphics^ miGraphic);
	bool Mapa_ColisionPuerta(BufferedGraphics^ miBuffer, Graphics^ miGraphic ,Tecla Direccion);
	bool Mapa_PuedeAvanzar(Movimiento Direccion);
	void Mapa_RecibirDireccion(BufferedGraphics^ miBuffer , Graphics^ miGraphic, Tecla LaDireccion);
	void Mapa_MoverMarcoDerecha(BufferedGraphics^ miBuffer, Graphics^ miGraphic , bool CambioDeMapa);
	void Mapa_MoverMarcoIzquierda(BufferedGraphics^ miBuffer, Graphics^ miGraphic, bool CambioDeMapa);
	void Mapa_MoverMarcoAbajo(BufferedGraphics^ miBuffer, Graphics^ miGraphic, bool CambioDeMapa);
	void Mapa_MoverMarcoArriba(BufferedGraphics^ miBuffer, Graphics^ miGraphic, bool CambioDeMapa);
	void Mapa_RotarMarco(BufferedGraphics^ miBuffer, Graphics^ miGraphic, Movimiento MiradaFinal);
	
};

Juego::Juego(void)
{
	qMedallas = 0;
	EstadoDialogo = 0;
	Escena = Interfaces::InterfazMenuPrincipal;
	EstadoDeImagen = Estado::SinDibujo;
	Nagayoshi = new PrimerLider();
	Crayon = new SegundoLider();
	Bicugo = new TercerLider();
	Yo = new Marco();
	misFondos = new Fondo();
	misLugares = new Lugar();
}

Juego::~Juego(void)
{
	miBatalla = NULL;
	delete misFondos;
	delete misLugares;
}

int Juego::getEstadoDeImagen(){ return EstadoDeImagen; }
void Juego::setEstadoDeImagen(Estado NuevoEstadoDeImagen){ EstadoDeImagen = NuevoEstadoDeImagen; }

int Juego::getEscena(){ return Escena; }
void Juego::setEscena(int NuevaEscena){ Escena = NuevaEscena; }


//***----------------------Escena 1 : MENU De INICIO------------------------***\\\

void Juego::Escena1_Mostrar(Graphics^ miGraphic)
{
	misFondos->MostrarFondo(miGraphic, Fondos::MenuPrincipal);
}

void Juego::Escena1_Boton1(Graphics^ miGraphic)
{
	misFondos->MostrarPNG(miGraphic, PNGS::PresionaStart,136,198,327,104,327,104);
}

//***-----------------------------------------------------------------------***\\\


//***----------------------Escena 2 : INTRODUCCIÓN DEL JUEGO------------------------***\\\



//***-------------------------------------------------------------------------------***\\\



//***----------------------Escena 3 : INTERFAZ PARA ESCOGER POKEMONES------------------------***\\\

void Juego::EscogerPokemon(Graphics^ miGraphic)
{
	misFondos->MostrarFondo(miGraphic, Fondos::EscogerPokemones);
}

void Juego::Escena3_Escoger(Tecla TeclaDireccional)
{
	if (TeclaDireccional == Tecla::TeclaA)
	{
		Yo->getArregloPokemon()->AgregarPokemon(new Charmander(), Yo->getPertenenciaPokemon());
		Nagayoshi->getArregloPokemon()->AgregarPokemon(new Squirtle(), Nagayoshi->getPertenenciaPokemon());
	}
	else if (TeclaDireccional == Tecla::TeclaS)
	{
		Yo->getArregloPokemon()->AgregarPokemon(new Squirtle(), Yo->getPertenenciaPokemon());
		Nagayoshi->getArregloPokemon()->AgregarPokemon(new Bulbasaur(), Nagayoshi->getPertenenciaPokemon());
	}
	else if (TeclaDireccional == Tecla::TeclaZ)
	{
		Yo->getArregloPokemon()->AgregarPokemon(new Pikachu(), Yo->getPertenenciaPokemon());
		Nagayoshi->getArregloPokemon()->AgregarPokemon(new Cyndaquil(), Nagayoshi->getPertenenciaPokemon());
	}
	else if (TeclaDireccional == Tecla::TeclaX)
	{
		Yo->getArregloPokemon()->AgregarPokemon(new Bulbasaur(), Yo->getPertenenciaPokemon());
		Nagayoshi->getArregloPokemon()->AgregarPokemon(new Charmander(), Nagayoshi->getPertenenciaPokemon());
	}

	EstadoDeImagen = Estado::NoMasDibujos;

}

//***----------------------------------------------------------------------------------------***\\\



//***----------------------Escena 4 : BATALLA POKEMÓN------------------------***\\\

Batalla* Juego::getBatalla(){ return miBatalla; }
Lugar* Juego::getMisLugares(){ return misLugares; }
void Juego::Batalla_CrearBatalla()
{
	miBatalla = new Batalla(Yo);
}


void Juego::FinBatalla(BufferedGraphics^ miBuffer, Graphics^ miGraphic)
{
	if (EstadoDialogo == 0)
	{
		if (Yo->getArregloPokemon()->QuedanPokemonesVivos() == false)
		{
			Threading::Thread::Sleep(600);
			EscribirLinea(miBuffer, miGraphic, "A Marco no le quedan más pokemones y", 1, true, 80);
			EscribirLinea(miBuffer, miGraphic, "corrió Hasta El centro Pokemon más cercano", 3, false, 80);
		}
		else if (miBatalla->TipoDeBatalla == TiposDeBatalla::ContraLider && Nagayoshi->getArregloPokemon()->QuedanPokemonesVivos() == false)
		{
			Threading::Thread::Sleep(600);
			EscribirLinea(miBuffer, miGraphic, "Tu Pokemon Acaba de Subir muchos Niveles.", 2, true, 80);
			Threading::Thread::Sleep(800);
			qMedallas++;
		}
		if (miBatalla->TipoDeBatalla == TiposDeBatalla::ContraLider && Crayon->getArregloPokemon()->QuedanPokemonesVivos() == false)
		{
			Threading::Thread::Sleep(600);
			EscribirLinea(miBuffer, miGraphic, "Tu Pokemon Acaba de Subir muchos Niveles.", 2, true, 80);
			Threading::Thread::Sleep(800);
			qMedallas++;
		}
		 if (miBatalla->TipoDeBatalla == TiposDeBatalla::ContraLider && Bicugo->getArregloPokemon()->QuedanPokemonesVivos() == false)
		{
			Threading::Thread::Sleep(600);
			EscribirLinea(miBuffer, miGraphic, "Tu Pokemon Acaba de Subir muchos Niveles.", 2, true, 80);
			Threading::Thread::Sleep(800);
			qMedallas++;
		}
		else if (miBatalla->TipoDeBatalla == TiposDeBatalla::ContraPokemonSalvaje && miBatalla->getPokemonRetador()->getVida() <= 0)
		{
			Threading::Thread::Sleep(600);
			EscribirLinea(miBuffer, miGraphic, "Tu Pokemon subió un nivel.", 2, true, 80);
			Threading::Thread::Sleep(800);
		}
	}
	else if (EstadoDialogo == 1)
	{
		if (Yo->getArregloPokemon()->QuedanPokemonesVivos() == false)
		{
			Yo->setPseudoX(14);
			Yo->setPseudoY(7);
			Yo->LugarActual = Lugares::Plazuela;
			Yo->Sprite = Movimiento::Abajo2;
			Threading::Thread::Sleep(800);
			EscenaCentroPokemon(miBuffer, miGraphic);
		}
	}
	EstadoDialogo++;
}

void Juego::Batalla_Atacar(BufferedGraphics^ miBuffer , Graphics^ miGraphic, Tecla TeclaDireccional)
{
	misFondos->MostrarPNG(miBuffer->Graphics, PNGS::CuadroDialogo, 0, 336, 720, 144, 720, 144);

	switch (TeclaDireccional)
	{
	case TeclaA:
		if (miBatalla->getPokemonMio()->TipoDeMensajeDeAtaques[0] == MensajeDeAtaque::MensajeNormal)
			EscribirLinea(miBuffer, miGraphic, miBatalla->getMensajeDeBatalla(-1, miBatalla->getPokemonMio()->TipoDeMensajeDeAtaques[0], Pertenencia::DeMarco), 2, true);
		else
		{
			EscribirLinea(miBuffer, miGraphic, miBatalla->getMensajeDeBatalla(-1, miBatalla->getPokemonMio()->TipoDeMensajeDeAtaques[0], Pertenencia::DeMarco), 1, true);
			Threading::Thread::Sleep(400);
			EscribirLinea(miBuffer, miGraphic, miBatalla->getMensajeDeBatalla(1, miBatalla->getPokemonMio()->TipoDeMensajeDeAtaques[0], Pertenencia::DeMarco), 3, false);
		}
		miBatalla->BatallarConMi("Primera");
		break;

	case TeclaS:
		if (miBatalla->getPokemonMio()->TipoDeMensajeDeAtaques[1] == MensajeDeAtaque::MensajeNormal)
			EscribirLinea(miBuffer, miGraphic, miBatalla->getMensajeDeBatalla(-2, miBatalla->getPokemonMio()->TipoDeMensajeDeAtaques[1], Pertenencia::DeMarco), 2, true);
		else
		{
			EscribirLinea(miBuffer, miGraphic, miBatalla->getMensajeDeBatalla(-2, miBatalla->getPokemonMio()->TipoDeMensajeDeAtaques[1], Pertenencia::DeMarco), 1, true);
			Threading::Thread::Sleep(400);
			EscribirLinea(miBuffer, miGraphic, miBatalla->getMensajeDeBatalla(2, miBatalla->getPokemonMio()->TipoDeMensajeDeAtaques[1], Pertenencia::DeMarco), 3, false);
		}
		miBatalla->BatallarConMi("Segunda");
		break;

	case TeclaZ:
		if (miBatalla->getPokemonMio()->TipoDeMensajeDeAtaques[2] == MensajeDeAtaque::MensajeNormal)
			EscribirLinea(miBuffer, miGraphic, miBatalla->getMensajeDeBatalla(-3, miBatalla->getPokemonMio()->TipoDeMensajeDeAtaques[2], Pertenencia::DeMarco), 2, true);
		else
		{
			EscribirLinea(miBuffer, miGraphic, miBatalla->getMensajeDeBatalla(-3, miBatalla->getPokemonMio()->TipoDeMensajeDeAtaques[2], Pertenencia::DeMarco), 1, true);
			Threading::Thread::Sleep(400);
			EscribirLinea(miBuffer, miGraphic, miBatalla->getMensajeDeBatalla(3, miBatalla->getPokemonMio()->TipoDeMensajeDeAtaques[2], Pertenencia::DeMarco), 3, false);
		}
		miBatalla->BatallarConMi("Tercera");
		break;
		
	case TeclaX:
		if (miBatalla->getPokemonMio()->TipoDeMensajeDeAtaques[3] == MensajeDeAtaque::MensajeNormal)
			EscribirLinea(miBuffer, miGraphic, miBatalla->getMensajeDeBatalla(-4, miBatalla->getPokemonMio()->TipoDeMensajeDeAtaques[3], Pertenencia::DeMarco), 2, true);
		else
			{
			EscribirLinea(miBuffer, miGraphic, miBatalla->getMensajeDeBatalla(-4, miBatalla->getPokemonMio()->TipoDeMensajeDeAtaques[3], Pertenencia::DeMarco), 1, true);
			Threading::Thread::Sleep(400);
			EscribirLinea(miBuffer, miGraphic, miBatalla->getMensajeDeBatalla(4, miBatalla->getPokemonMio()->TipoDeMensajeDeAtaques[3], Pertenencia::DeMarco), 3, false);
		}
		miBatalla->BatallarConMi("Cuarta");
		break;
		
	}

	miBatalla->ActualizarEscenario(miBuffer, miGraphic, Pertenencia::Todos);

	if (miBatalla->getPokemonRetador()->getVida() <= 0)
	{
		if (miBatalla->getPokemonRetador()->getPertenenciaPokemon() == Pertenencia::DeLider && Nagayoshi->getArregloPokemon()->QuedanPokemonesVivos())
		{
			miBatalla->CambiarPokemon(miBuffer,miGraphic,miBatalla->getPokemonRetador(),Yo,Nagayoshi);
		}
		else
			miBatalla->setGanador(QuienGano::GanoMarco);
	}
	else
		miBatalla->setTurno(Turnos::TurnoDeRival);

	EstadoDeImagen = Estado::EsperandoTecla;

}

void Juego::Batalla_Defender(BufferedGraphics^ miBuffer , Graphics^ miGraphic)
{
	misFondos->MostrarPNG(miBuffer->Graphics, PNGS::CuadroDialogo, 0, 336, 720, 144, 720, 144);

	Random VariableRandom;
	int EnteroRandom;

	EnteroRandom = VariableRandom.Next(0, 4);

	switch (EnteroRandom)
	{
		case 0:
			if (miBatalla->getPokemonRetador()->TipoDeMensajeDeAtaques[0] == MensajeDeAtaque::MensajeNormal)
				EscribirLinea(miBuffer, miGraphic, miBatalla->getMensajeDeBatalla(-1, miBatalla->getPokemonRetador()->TipoDeMensajeDeAtaques[0], Pertenencia::Salvaje), 2, true);
			else
			{
				EscribirLinea(miBuffer, miGraphic, miBatalla->getMensajeDeBatalla(-1, miBatalla->getPokemonRetador()->TipoDeMensajeDeAtaques[0], Pertenencia::Salvaje), 1, true);
				Threading::Thread::Sleep(400);
				EscribirLinea(miBuffer, miGraphic, miBatalla->getMensajeDeBatalla(1, miBatalla->getPokemonRetador()->TipoDeMensajeDeAtaques[0], Pertenencia::Salvaje), 3, false);
			}
			miBatalla->ElRivalBatalla(0);
			break;

		case 1:
			if (miBatalla->getPokemonRetador()->TipoDeMensajeDeAtaques[1] == MensajeDeAtaque::MensajeNormal)
				EscribirLinea(miBuffer, miGraphic, miBatalla->getMensajeDeBatalla(-2, miBatalla->getPokemonRetador()->TipoDeMensajeDeAtaques[1], Pertenencia::Salvaje), 2, true);
			else
			{
				EscribirLinea(miBuffer, miGraphic, miBatalla->getMensajeDeBatalla(-2, miBatalla->getPokemonRetador()->TipoDeMensajeDeAtaques[1], Pertenencia::Salvaje), 1, true);
				Threading::Thread::Sleep(400);
				EscribirLinea(miBuffer,miGraphic, miBatalla->getMensajeDeBatalla(2 , miBatalla->getPokemonRetador()->TipoDeMensajeDeAtaques[1] , Pertenencia::Salvaje),3, false);
			}
			miBatalla->ElRivalBatalla(1);
			break;

		case 2:
			if (miBatalla->getPokemonRetador()->TipoDeMensajeDeAtaques[2] == MensajeDeAtaque::MensajeNormal)
				EscribirLinea(miBuffer, miGraphic, miBatalla->getMensajeDeBatalla(-3, miBatalla->getPokemonRetador()->TipoDeMensajeDeAtaques[2], Pertenencia::Salvaje), 2, true);
			else
			{
				EscribirLinea(miBuffer, miGraphic, miBatalla->getMensajeDeBatalla(-3, miBatalla->getPokemonRetador()->TipoDeMensajeDeAtaques[2], Pertenencia::Salvaje), 1, true);
				Threading::Thread::Sleep(400);
				EscribirLinea(miBuffer, miGraphic, miBatalla->getMensajeDeBatalla(3, miBatalla->getPokemonRetador()->TipoDeMensajeDeAtaques[2], Pertenencia::Salvaje), 3, false);
			}
			miBatalla->ElRivalBatalla(2);
			break;

		case 3:
			if (miBatalla->getPokemonRetador()->TipoDeMensajeDeAtaques[3] == MensajeDeAtaque::MensajeNormal)
				EscribirLinea(miBuffer, miGraphic, miBatalla->getMensajeDeBatalla(-4, miBatalla->getPokemonRetador()->TipoDeMensajeDeAtaques[3], Pertenencia::Salvaje), 2, true);
			else
			{
				EscribirLinea(miBuffer, miGraphic, miBatalla->getMensajeDeBatalla(-4, miBatalla->getPokemonRetador()->TipoDeMensajeDeAtaques[3], Pertenencia::Salvaje), 1, true);
				Threading::Thread::Sleep(400);
				EscribirLinea(miBuffer,miGraphic, miBatalla->getMensajeDeBatalla(4 , miBatalla->getPokemonRetador()->TipoDeMensajeDeAtaques[3] , Pertenencia::Salvaje),3, false);
			}
			miBatalla->ElRivalBatalla(3);
			break;
	}

	miBatalla->ActualizarEscenario(miBuffer, miGraphic, Pertenencia::Todos);

	if (miBatalla->getPokemonMio()->getVida() <= 0)
	{
		if (Yo->getArregloPokemon()->QuedanPokemonesVivos())
		{
			miBatalla->setTurno(Turnos::TurnoDeMarco);
			miBatalla->CambiarPokemon(miBuffer, miGraphic, miBatalla->getPokemonMio(), Yo, Nagayoshi);
		}
		else
			miBatalla->setGanador(QuienGano::GanoRival);
	}
	else
		miBatalla->setTurno(Turnos::TurnoDeMarco);

	EstadoDeImagen = Estado::EsperandoTecla;

}

void Juego::Batalla_CambiarPokemon(Tecla LaTecla)
{
	switch (LaTecla)
	{
		case Tecla1:
			Yo->PokemonMechador = 0;
			break;
		case Tecla2:
			Yo->PokemonMechador = 1;
			break;
		case Tecla3:
			Yo->PokemonMechador = 2;
			break;
		case Tecla4:
			Yo->PokemonMechador = 3;
			break;
		case Tecla5:
			Yo->PokemonMechador = 4;
			break;
		case Tecla6:
			Yo->PokemonMechador = 5;
			break;
	}
}

void Juego::Batalla_Huida(BufferedGraphics^ miBuffer, Graphics^ miGraphic)
{

		EscribirLinea(miBuffer, miGraphic, "Escapaste sin problemas!!!!!!!!", 2, true, 80);
		Threading::Thread::Sleep(800);
		EstadoDeImagen = Estado::NoMasDibujos;
}


void Juego::Batalla_LanzarPokebola(BufferedGraphics^ miBuffer ,  Graphics^ miGraphic)
{
	if (miBatalla->getPokemonRetador()->getVida() >= 250)
	{
		EscribirLinea(miBuffer, miGraphic, "Usaste una Pokebola!!!!!!!!", 1, true, 80);
		Threading::Thread::Sleep(1000);
		EscribirLinea(miBuffer, miGraphic, "Parecía que lo habías capturado!", 3,false, 80);
		Threading::Thread::Sleep(800);
		misFondos->MostrarPNG(miBuffer->Graphics, PNGS::CuadroDialogo, 0, 336, 720, 144, 720, 144);
		DibujarAtaquesPokemon(miBuffer, miGraphic, miBatalla->getPokemonMio(), 200, 380);
		miBuffer->Render(miGraphic);
	}
	else if (Yo->getArregloPokemon()->getTamanioDelArreglo() <= 5 && miBatalla->getPokemonRetador()->getPertenenciaPokemon() != Pertenencia::DeLider)
	{
		Yo->getArregloPokemon()->AgregarPokemon(miBatalla->getPokemonRetador(), Pertenencia::DeMarco);
		EscribirLinea(miBuffer, miGraphic, "Atrapaste al pokemon!!!!.", 2, true, 80);
		Threading::Thread::Sleep(800);
		EstadoDeImagen = Estado::NoMasDibujos;
	}
	else
	{
		EscribirLinea(miBuffer, miGraphic, "Ya tienes muchos pokemones!!!!.", 2, true, 80);
		Threading::Thread::Sleep(800);
		misFondos->MostrarPNG(miBuffer->Graphics, PNGS::CuadroDialogo, 0, 336, 720, 144, 720, 144);
		DibujarAtaquesPokemon(miBuffer, miGraphic, miBatalla->getPokemonMio(), 200, 380);
		miBuffer->Render(miGraphic);
	}
}

void Juego::Batalla_EscogerPokemon(BufferedGraphics^ miBuffer, Graphics^ miGraphics)
{
	InterfazEscogeTuPokemon(miBuffer->Graphics, Yo->getArregloPokemon());
	miBuffer->Render(miGraphics);
}

//***----------------------------------------------------------------------------------***\\\


//***----------------------Escena 5 : CONCLUSIÓN DE LA BATALLA 1------------------------***\\\


void Juego::EscenaCentroPokemon(BufferedGraphics^ MiBuffer, Graphics^ miGraphic)
{
	Yo->getArregloPokemon()->CurarPokemones();
	misFondos->MostrarFondo(MiBuffer->Graphics, Fondos::CPokemon1);
	MiBuffer->Render(miGraphic);
	Threading::Thread::Sleep(600);
	EscribirLinea(MiBuffer, miGraphic, "Bienvenido al Centro Pokemon, aqui cura", 2, true, 100);
	misFondos->MostrarFondo(MiBuffer->Graphics, Fondos::CPokemon2);
	EscribirLinea(MiBuffer, miGraphic, "SHUT UP!!!", 1, true, 18);
	Threading::Thread::Sleep(600);
	EscribirLinea(MiBuffer, miGraphic, "AND TAKE MY POKEMON!!!", 3, false, 18);
	Threading::Thread::Sleep(3200);
	misFondos->MostrarFondo(MiBuffer->Graphics, Fondos::CPokemon3);
	EscribirLinea(MiBuffer, miGraphic, "Tus Pokemones han sido curados!", 1, true, 50);
	EscribirLinea(MiBuffer, miGraphic, "Y están listos para volver a luchar!", 3, false, 50);
	Threading::Thread::Sleep(300);
	EstadoDeImagen = Estado::EsperandoTecla;
}

void Juego::EscenaAOki(BufferedGraphics^ MiBuffer, Graphics^ miGraphic)
{
	if (strcmp(Yo->getArregloPokemon()->RetornaPokemon(0)->getNombre(), "Pikachu") == 0)
	{
		Yo->getArregloPokemon()->RetornaPokemon(0)->setNombre("Raichu");
		Yo->getArregloPokemon()->RetornaPokemon(0)->setDirImagenBack("Data\\Imagenes\\\\Pokemones\\Batalla\\PikachuE_Back.png");
		Yo->getArregloPokemon()->RetornaPokemon(0)->setDirImagenFront("Data\\Imagenes\\\\Pokemones\\Batalla\\PikachuE_Front.png");
		Yo->getArregloPokemon()->RetornaPokemon(0)->setVitalidad(600);
		Yo->getArregloPokemon()->RetornaPokemon(0)->setVida(600);
	}
	Yo->getArregloPokemon()->CurarPokemones();
	misFondos->MostrarFondo(MiBuffer->Graphics, Fondos::AokiSama);
	MiBuffer->Render(miGraphic);
	Threading::Thread::Sleep(600);
	EscribirLinea(MiBuffer, miGraphic, "Necesitas una piedra trueno para Pikachu!!", 1, true, 40);
	EscribirLinea(MiBuffer, miGraphic, "Pikachu ahora es Raichu!!", 3, false, 40);
	Threading::Thread::Sleep(600);
	EscribirLinea(MiBuffer, miGraphic, "Espero que te ayude en tu aventura pokemon!", 2, true, 40);
	EstadoDeImagen = Estado::EsperandoTecla;
}

void Juego::EscenaIntro(BufferedGraphics^ MiBuffer, Graphics^ miGraphic)
{
	Yo->getArregloPokemon()->CurarPokemones();
	misFondos->MostrarFondo(MiBuffer->Graphics, Fondos::Intro1);
	MiBuffer->Render(miGraphic);
	Threading::Thread::Sleep(600);
	EscribirLinea(MiBuffer, miGraphic, "Bienvenido al centro Pokemon", 1, true, 50);
	EscribirLinea(MiBuffer, miGraphic, "Donde tendras muchas aventuras!", 3, false, 50);
	misFondos->MostrarFondo(MiBuffer->Graphics, Fondos::Intro2);
	EscribirLinea(MiBuffer, miGraphic, "Te espera un mundo lleno!", 1, true, 50);
	EscribirLinea(MiBuffer, miGraphic, "de batallas y de aventuras!", 3, false, 50);
	Threading::Thread::Sleep(600);
	misFondos->MostrarFondo(MiBuffer->Graphics, Fondos::Intro3);
	EscribirLinea(MiBuffer, miGraphic, "Vamos!! Tienes un gran camino que recorer!", 1, true, 50);
	EscribirLinea(MiBuffer, miGraphic, "TU historia empieza Ya!", 3, false, 50);

	EstadoDeImagen = Estado::EsperandoTecla;
}


void Juego::MostarMedallas(BufferedGraphics^ MiBuffer, Graphics^ miGraphic)
{
	
	
	if (qMedallas==1)
		EscribirLinea(MiBuffer, miGraphic, "Numero Medallas: 1/3", 1, true, 50);
	if (qMedallas == 2)
		EscribirLinea(MiBuffer, miGraphic, "Numero Medallas: 2/3", 1, true, 50);
	if (qMedallas == 3)
		EscribirLinea(MiBuffer, miGraphic, "Numero Medallas: 3/3", 1, true, 50);
	
	Threading::Thread::Sleep(1000);
}

//***-----------------------------------------------------------------------------------***\\\

void Juego::Mapa_ConsultarBloque(BufferedGraphics^ miBuffer, Graphics^ miGraphic)
{
	int XAuxiliar = Yo->getPseudoX();
	int YAuxiliar = Yo->getPseudoY();

	switch (Yo->Sprite)
	{
	case Derecha2:
		XAuxiliar++;
		break;
	case Izquierda2:
		XAuxiliar--;
		break;
	case Arriba2:
		YAuxiliar--;
		break;
	case Abajo2:
		YAuxiliar++;
		break;
	}

	switch (Yo->LugarActual)
	{
	case Plazuela:
		break;
	case CentroPokemon:
		if (XAuxiliar == 17 && YAuxiliar == 6 && Yo->Sprite == Movimiento::Arriba2 && Yo->getArregloPokemon()->HayPoquemonHerido())
			EscenaCentroPokemon(miBuffer, miGraphic);
		break;
	case GimnasioNormal:
		if (XAuxiliar == 7 && YAuxiliar == 4 && Yo->Sprite == Movimiento::Arriba2)
			miBatalla = new Batalla(Yo, Nagayoshi);
			EstadoDeImagen = Estado::EsperandoMechaConLider;
		break;
	case GimnasioAgua:
		if (XAuxiliar == 13 && YAuxiliar == 4 && Yo->Sprite == Movimiento::Arriba2)
			miBatalla = new Batalla(Yo, Bicugo);
		EstadoDeImagen = Estado::EsperandoMechaConLider;
		break;
	case GimnasioPlanta:
		if (XAuxiliar == 11 && YAuxiliar == 3 && Yo->Sprite == Movimiento::Arriba2)
			miBatalla = new Batalla(Yo, Crayon);
		EstadoDeImagen = Estado::EsperandoMechaConLider;
		break;
	}
}

bool Juego::Mapa_PuedeAvanzar(Movimiento Direccion)
{
	int X = Yo->getPseudoX();
	int Y = Yo->getPseudoY();

	if (Direccion == Movimiento::Derecha2)
		X++;
	else if(Direccion == Movimiento::Izquierda2)
		X--;
	else if (Direccion == Movimiento::Arriba2)
		Y--;
	else if (Direccion == Movimiento::Abajo2)
		Y++;

	switch (Yo->LugarActual)
	{
	case Plazuela:
		if ((X == 6) || (X == 31) || (Y == 4) || (Y == 33) || (X == 13 && Y == 5) || (X == 17 && Y == 5) || (X == 19 && Y == 5) || (X == 20 && Y == 5) || (X == 25 && Y == 5) || (X == 26 && Y == 5) ||
			(X == 12 && Y == 6) || (X == 13 && Y == 6) || (X == 16 && Y == 6) || (X == 7 && Y == 7) || (X == 8 && Y == 7) || (X == 11 && Y == 7) || (X == 21 && Y == 8) ||
			(X == 22 && Y == 8) || (X == 23 && Y == 8) || (X == 25 && Y == 8) || (X == 26 && Y == 8) || (X == 27 && Y == 8) || (X == 28 && Y == 8) || (X == 29 && Y == 8) ||
			(X == 21 && Y == 9) || (X == 23 && Y == 9) || (X == 25 && Y == 9) || (X == 29 && Y == 9) || (X == 22 && Y == 10) || (X == 23 && Y == 10) ||
			(X == 25 && Y == 10) || (X == 29 && Y == 10) || (X == 25 && Y == 11) || (X == 29 && Y == 11) || (X == 25 && Y == 12) || (X == 29 && Y == 12) || (X == 25 && Y == 13) ||
			(X == 26 && Y == 13) || (X == 27 && Y == 13) || (X == 28 && Y == 13) || (X == 29 && Y == 13) || (X == 15 && Y == 16) || (X == 16 && Y == 16) || (X == 17 && Y == 16) ||
			(X == 18 && Y == 16) || (X == 19 && Y == 16) || (X == 20 && Y == 16) || (X == 21 && Y == 16) || (X == 22 && Y == 16) || (X == 23 && Y == 16) || (X == 24 && Y == 16) ||
			(X == 25 && Y == 16) || (X == 26 && Y == 16) || (X == 27 && Y == 16) || (X == 28 && Y == 16) || (X == 29 && Y == 16) || (X == 15 && Y == 17) || (X == 29 && Y == 17) ||
			(X == 15 && Y == 18) || (X == 29 && Y == 18) || (X == 15 && Y == 19) || (X == 16 && Y == 19) || (X == 17 && Y == 19) || (X == 18 && Y == 19) || (X == 29 && Y == 19) ||
			(X == 9 && Y == 20) || (X == 10 && Y == 20) || (X == 11 && Y == 20) || (X == 19 && Y == 20) || (X == 20 && Y == 20) || (X == 23 && Y == 20) || (X == 24 && Y == 20) || 
			(X == 25 && Y == 20) || (X == 26 && Y == 20) || (X == 27 && Y == 20) || (X == 28 && Y == 20) || (X == 29 && Y == 20) ||	(X == 9 && Y == 21) || (X == 11 && Y == 21) || 
			(X == 10 && Y == 22) || (X == 11 && Y == 22) || (X == 15 && Y == 24) || (X == 16 && Y == 24) || (X == 17 && Y == 24) ||	(X == 18 && Y == 24) || (X == 19 && Y == 24) ||
			(X == 20 && Y == 24) || (X == 10 && Y == 25) || (X == 11 && Y == 25) || (X == 12 && Y == 25) || (X == 13 && Y == 25) ||	(X == 15 && Y == 25) || (X == 20 && Y == 25) || 
			(X == 10 && Y == 26) || (X == 13 && Y == 26) || (X == 15 && Y == 26) || (X == 16 && Y == 26) || (X == 17 && Y == 26) ||	(X == 18 && Y == 26) || (X == 19 && Y == 26) || 
			(X == 20 && Y == 26) || (X == 10 && Y == 27) || (X == 13 && Y == 27) || (X == 10 && Y == 28) || (X == 13 && Y == 28) ||	(X == 11 && Y == 29) || (X == 12 && Y == 29))
			return false;

		return true;

	case CentroPokemon:
		if ((X == 21 && Y == 4) || (X == 11 && Y == 5) || (X == 12 && Y == 5) || (X == 13 && Y == 5) || (X == 20 && Y == 5) || (X == 22 && Y == 5) || (X == 23 && Y == 5) || (X == 24 && Y == 5) ||
			(X == 10 && Y == 6) || (X == 14 && Y == 6) || (X == 15 && Y == 6) || (X == 16 && Y == 6) || (X == 17 && Y == 6) || (X == 18 && Y == 6) || (X == 19 && Y == 6) || (X == 20 && Y == 6) ||
			(X == 25 && Y == 6) || (X == 10 && Y == 7) || (X == 25 && Y == 7) || (X == 11 && Y == 8) || (X == 12 && Y == 8) || (X == 13 && Y == 8) || (X == 21 && Y == 8) || (X == 22 && Y == 8) ||
			(X == 23 && Y == 8) || (X == 24 && Y == 8) || (X == 7 && Y == 9) || (X == 8 && Y == 9) || (X == 11 && Y == 9) || (X == 12 && Y == 9) || (X == 13 && Y == 9) || (X == 21 && Y == 9) ||
			(X == 6 && Y == 10) || (X == 9 && Y == 10) || (X == 10 && Y == 10) || (X == 21 && Y == 10) || (X == 6 && Y == 11) || (X == 9 && Y == 11) || (X == 10 && Y == 11) || (X == 21 && Y == 11) ||
			(X == 22 && Y == 11) || (X == 23 && Y == 11) || (X == 24 && Y == 11) || (X == 25 && Y == 11) || (X == 26 && Y == 11) || (X == 27 && Y == 11) || (X == 28 && Y == 11) || (X == 29 && Y == 11) ||
			(X == 6 && Y == 12) || (X == 21 && Y == 12) || (X == 26 && Y == 12) || (X == 30 && Y == 12) || (X == 6 && Y == 13) || (X == 30 && Y == 13) || (X == 6 && Y == 14) || (X == 30 && Y == 14) ||
			(X == 6 && Y == 15) || (X == 30 && Y == 15) || (Y == 16 && X != 17))
			return false;
		return true;	

	case GimnasioNormal:
		if ((X == 7 && Y == 4) || (X == 6 && Y == 5) || (X == 8 && Y == 5) || (X == 6 && Y == 6) || (X == 8 && Y == 6) || (X == 6 && Y == 7) || (X == 8 && Y == 7) || (X == 6 && Y == 8) || (X == 8 && Y == 8) ||
			(X == 6 && Y == 9) || (X == 8 && Y == 9) || (X == 6 && Y == 10) || (X == 8 && Y == 10) || (X == 6 && Y == 11) || (X == 8 && Y == 11) || (X == 6 && Y == 12) || (X == 8 && Y == 12) || (X == 5 && Y == 13) ||
			(X == 6 && Y == 13) || (X == 8 && Y == 13) || (X == 9 && Y == 13) || (X == 4 && Y == 14) || (X == 10 && Y == 14) || (X == 5 && Y == 15) || (X == 6 && Y == 15) || (X == 8 && Y == 15) || (X == 9 && Y == 15))
			return false;
		return true;

	case GimnasioAgua:
		if ((Y == 5 && X != 13) || (Y == 10 && X <= 17) || (X == 6 && Y == 6) || (X == 12 && Y == 6) || (X == 14 && Y == 6) || (X == 6 && Y == 7) || (X == 12 && Y == 7) || (X == 14 && Y == 7) || (X == 6 && Y == 8) || 
			(X == 12 && Y == 8) || (X == 14 && Y == 8) || (X == 7 && Y == 9) ||	(X == 18 && Y == 11) || (X == 18 && Y == 12) || (X == 18 && Y == 13) || (X == 18 && Y == 14) || (X == 13 && Y == 15) || (X == 16 && Y == 15) || 
			(X == 17 && Y == 15) || (X == 18 && Y == 15) || (X == 12 && Y == 16) || (X == 14 && Y == 16) || (X == 15 && Y == 16) || (X == 11 && Y == 17) || (X == 11 && Y == 18) || (X == 11 && Y == 19) || (Y == 4 && X!= 13) || 
			(X == 20) || (Y == 20 && X != 13) || (Y == 3))
			return false;
		return true;

	case GimnasioPlanta:
		if ((X == 10 && Y == 4) || (X == 11 && Y == 3) || (X == 12 && Y == 4) || (X == 9 && Y == 5) || (X == 13 && Y == 5) || (X == 7 && Y == 6) || (X == 8 && Y == 6) || (X == 14 && Y == 6) || (X == 15 && Y == 6) || (X == 6 && Y == 7) ||
			(X == 16 && Y == 7) || (X == 7 && Y == 8) || (X == 8 && Y == 8) || (X == 9 && Y == 8) || (X == 10 && Y == 8) || (X == 13 && Y == 8) || (X == 14 && Y == 8) || (X == 15 && Y == 8) || (X == 9 && Y == 9) || (X == 13 && Y == 9) ||
			(X == 9 && Y == 10) || (X == 13 && Y == 10) || (X == 9 && Y == 11) || (X == 13 && Y == 11) || (X == 9 && Y == 12) || (X == 13 && Y == 12) || (X == 9 && Y == 13) || (X == 13 && Y == 13) || (X == 9 && Y == 14) || (X == 13 && Y == 14) ||
			(X == 7 && Y == 15) || (X == 8 && Y == 15) || (X == 9 && Y == 15) || (X == 13 && Y == 15) || (X == 14 && Y == 15) || (X == 15 && Y == 15) || (X == 6 && Y == 16) || (X == 10 && Y == 16) || (X == 12 && Y == 16) || (X == 16 && Y == 16) ||
			(X == 6 && Y == 17) || (X == 16 && Y == 17) || (X == 7 && Y == 18) || (X == 8 && Y == 18) || (X == 9 && Y == 18) || (X == 10 && Y == 18) || (X == 12 && Y == 18) || (X == 13 && Y == 18) || (X == 14 && Y == 18) || (X == 15 && Y == 18))
			return false;
		return true;			
	}
	
}

void Juego::Mapa_AccionTerreno(BufferedGraphics^ miBuffer , Graphics^ miGraphic)
{
	int X = Yo->getPseudoX();
	int Y = Yo->getPseudoY();

	switch (Yo->LugarActual)
	{
	case Plazuela:

		//Si Choca Con Hierbas
		if ((X == 11 && Y == 9) || (X == 12 && Y == 9) || (X == 13 && Y == 9) || (X == 14 && Y == 9) || (X == 15 && Y == 9) || (X == 16 && Y == 9) || (X == 17 && Y == 9) ||
			(X == 18 && Y == 9) || (X == 11 && Y == 10) || (X == 12 && Y == 10) || (X == 13 && Y == 10) || (X == 14 && Y == 10) || (X == 15 && Y == 10) || (X == 16 && Y == 10)
			|| (X == 17 && Y == 10) || (X == 18 && Y == 10) || (X == 11 && Y == 11) || (X == 12 && Y == 11) || (X == 13 && Y == 11) || (X == 14 && Y == 11) || (X == 15 && Y == 11)
			|| (X == 16 && Y == 11) || (X == 17 && Y == 11) || (X == 18 && Y == 11) || (X == 11 && Y == 12) || (X == 12 && Y == 12) || (X == 13 && Y == 12) || (X == 14 && Y == 12)
			|| (X == 15 && Y == 12) || (X == 16 && Y == 12) || (X == 17 && Y == 12) || (X == 18 && Y == 12) || (X == 11 && Y == 13) || (X == 12 && Y == 13) || (X == 13 && Y == 13)
			|| (X == 14 && Y == 13) || (X == 15 && Y == 13) || (X == 16 && Y == 13) || (X == 17 && Y == 13) || (X == 18 && Y == 13) || (X == 19 && Y == 13) || (X == 20 && Y == 13)
			|| (X == 21 && Y == 13) || (X == 22 && Y == 13) || (X == 23 && Y == 13) || (X == 11 && Y == 14) || (X == 12 && Y == 14) || (X == 13 && Y == 14) || (X == 14 && Y == 14)
			|| (X == 15 && Y == 14) || (X == 16 && Y == 14) || (X == 17 && Y == 14) || (X == 18 && Y == 14) || (X == 19 && Y == 14) || (X == 20 && Y == 14) || (X == 21 && Y == 14)
			|| (X == 22 && Y == 14) || (X == 23 && Y == 14) || (X == 11 && Y == 15) || (X == 12 && Y == 15) || (X == 13 && Y == 15) || (X == 14 && Y == 15) || (X == 15 && Y == 15)
			|| (X == 16 && Y == 15) || (X == 17 && Y == 15) || (X == 18 && Y == 15) || (X == 19 && Y == 15) || (X == 20 && Y == 15) || (X == 21 && Y == 15) || (X == 22 && Y == 15)
			|| (X == 23 && Y == 15) || (X == 11 && Y == 16) || (X == 12 && Y == 16) || (X == 13 && Y == 16) || (X == 14 && Y == 16) || (X == 22 && Y == 24) || (X == 23 && Y == 24)
			|| (X == 24 && Y == 24) || (X == 25 && Y == 24) || (X == 26 && Y == 24) || (X == 27 && Y == 24) || (X == 28 && Y == 24) || (X == 22 && Y == 25) || (X == 23 && Y == 25)
			|| (X == 24 && Y == 25) || (X == 25 && Y == 25) || (X == 26 && Y == 25) || (X == 27 && Y == 25) || (X == 28 && Y == 25) || (X == 22 && Y == 26) || (X == 23 && Y == 26)
			|| (X == 24 && Y == 26) || (X == 25 && Y == 26) || (X == 26 && Y == 26) || (X == 27 && Y == 26) || (X == 28 && Y == 26) || (X == 22 && Y == 27) || (X == 23 && Y == 27)
			|| (X == 24 && Y == 27) || (X == 25 && Y == 27) || (X == 26 && Y == 27) || (X == 27 && Y == 27) || (X == 28 && Y == 27) || (X == 22 && Y == 28) || (X == 23 && Y == 28)
			|| (X == 24 && Y == 28) || (X == 25 && Y == 28) || (X == 26 && Y == 28) || (X == 27 && Y == 28) || (X == 28 && Y == 28))
		{
			Random VariableRandom;
			int EnteroRandom;
			EnteroRandom = VariableRandom.Next(1, 6);
			if (EnteroRandom == 5)
				EstadoDeImagen = Estado::EsperandoMecha;
		}
		break;
	
	case CentroPokemon:
		break;
	}
}


void Juego::Mapa_MoverMarcoDerecha(BufferedGraphics^ miBuffer, Graphics^ miGraphics, bool CambioDeMapa)
{
	Movimiento SpriteActual = Movimiento::Derecha1;
	if (CambioDeMapa)
	{
		for (int i = 1; i <= 24; i++)
		{
			if (i == 17)SpriteActual = Movimiento::Derecha3;
			misLugares->DibujarLugar(miBuffer->Graphics, Yo->LugarActual, Yo->getPseudoX() * 48 + i, Yo->getPseudoY() * 48);
			Yo->MostrarMiniatura(miBuffer->Graphics, SpriteActual);
			miBuffer->Render(miGraphics);
			//System::Threading::Thread::Sleep(0);	
		}
		Yo->setPseudoX(Yo->NuevaCordX);
		Yo->setPseudoY(Yo->NuevaCordY);
		for (int i = 25; i <= 48; i++)
		{
			if (i == 33)SpriteActual = Movimiento::Derecha2;
			misLugares->DibujarLugar(miBuffer->Graphics, Yo->ProximoLugar, Yo->getPseudoX() * 48 + i, Yo->getPseudoY() * 48);
			Yo->MostrarMiniatura(miBuffer->Graphics, SpriteActual);
			miBuffer->Render(miGraphics);
			//System::Threading::Thread::Sleep(0);	
		}
		Yo->setPseudoX(Yo->getPseudoX() + 1);
		Yo->LugarActual = Yo->ProximoLugar;
	}
	else
	{
		for (int i = 1; i <= 48; i++)
		{
			if (i == 17)SpriteActual = Movimiento::Derecha3;
			else if (i == 33)SpriteActual = Movimiento::Derecha2;
			misLugares->DibujarLugar(miBuffer->Graphics, Yo->LugarActual, Yo->getPseudoX() * 48 + i, Yo->getPseudoY() * 48);
			Yo->MostrarMiniatura(miBuffer->Graphics, SpriteActual);
			miBuffer->Render(miGraphics);
			//System::Threading::Thread::Sleep(0);	
		}

		Yo->setPseudoX(Yo->getPseudoX() + 1);
	}
}

void Juego::Mapa_MoverMarcoIzquierda(BufferedGraphics^ miBuffer, Graphics^ miGraphics, bool CambioDeMapa)
{
	Movimiento SpriteActual = Movimiento::Izquierda1;
	if (CambioDeMapa)
	{
		for (int i = 1; i <= 24; i++)
		{
			if (i == 17)SpriteActual = Movimiento::Izquierda3;
			misLugares->DibujarLugar(miBuffer->Graphics, Yo->LugarActual, Yo->getPseudoX() * 48 - i, Yo->getPseudoY() * 48);
			Yo->MostrarMiniatura(miBuffer->Graphics, SpriteActual);
			miBuffer->Render(miGraphics);
			//System::Threading::Thread::Sleep(0);
		}
		Yo->setPseudoX(Yo->NuevaCordX);
		Yo->setPseudoY(Yo->NuevaCordY);
		for (int i = 25; i <= 48; i++)
		{
			if (i == 33)SpriteActual = Movimiento::Izquierda2;
			misLugares->DibujarLugar(miBuffer->Graphics, Yo->ProximoLugar , Yo->getPseudoX() * 48 - i, Yo->getPseudoY() * 48);
			Yo->MostrarMiniatura(miBuffer->Graphics, SpriteActual);
			miBuffer->Render(miGraphics);
			//System::Threading::Thread::Sleep(0);
		}
		Yo->setPseudoX(Yo->getPseudoX() - 1);
		Yo->LugarActual = Yo->ProximoLugar;
	}
	else
	{
		for (int i = 1; i <= 48; i++)
		{
			if (i == 17)SpriteActual = Movimiento::Izquierda3;
			else if (i == 33)SpriteActual = Movimiento::Izquierda2;
			misLugares->DibujarLugar(miBuffer->Graphics, Yo->LugarActual, Yo->getPseudoX() * 48 - i, Yo->getPseudoY() * 48);
			Yo->MostrarMiniatura(miBuffer->Graphics, SpriteActual);
			miBuffer->Render(miGraphics);
			//System::Threading::Thread::Sleep(0);
		}

		Yo->setPseudoX(Yo->getPseudoX() - 1);
	}
}

void Juego::Mapa_MoverMarcoAbajo(BufferedGraphics^ miBuffer, Graphics^ miGraphics, bool CambioDeMapa)
{
	Movimiento SpriteActual = Movimiento::Abajo1;
	if (CambioDeMapa)
	{
		for (int i = 1; i <= 24; i++)
		{
			if (i == 17)SpriteActual = Movimiento::Abajo3;
			misLugares->DibujarLugar(miBuffer->Graphics, Yo->LugarActual, Yo->getPseudoX() * 48, Yo->getPseudoY() * 48 + i);
			Yo->MostrarMiniatura(miBuffer->Graphics, SpriteActual);
			miBuffer->Render(miGraphics);
			//System::Threading::Thread::Sleep(0);
		}
		Yo->setPseudoX(Yo->NuevaCordX);
		Yo->setPseudoY(Yo->NuevaCordY);
		for (int i = 25; i <= 48; i++)
		{
			if (i == 33)SpriteActual = Movimiento::Abajo2;
			misLugares->DibujarLugar(miBuffer->Graphics, Yo->ProximoLugar, Yo->getPseudoX() * 48, Yo->getPseudoY() * 48 + i);
			Yo->MostrarMiniatura(miBuffer->Graphics, SpriteActual);
			miBuffer->Render(miGraphics);
			//System::Threading::Thread::Sleep(0);
		}
		Yo->setPseudoY(Yo->getPseudoY() + 1);
		Yo->LugarActual = Yo->ProximoLugar;
	}
	else
	{
		for (int i = 1; i <= 48; i++)
		{
			if (i == 17)SpriteActual = Movimiento::Abajo3;
			else if (i == 33)SpriteActual = Movimiento::Abajo2;
			misLugares->DibujarLugar(miBuffer->Graphics, Yo->LugarActual, Yo->getPseudoX() * 48, Yo->getPseudoY() * 48 + i);
			Yo->MostrarMiniatura(miBuffer->Graphics, SpriteActual);
			miBuffer->Render(miGraphics);
			//System::Threading::Thread::Sleep(0);
		}
		Yo->setPseudoY(Yo->getPseudoY() + 1);
	}
}

void Juego::Mapa_MoverMarcoArriba(BufferedGraphics^ miBuffer, Graphics^ miGraphics, bool CambioDeMapa)
{
	Movimiento SpriteActual = Movimiento::Arriba1;
	if (CambioDeMapa)
	{
		for (int i = 1; i <= 24; i++)
		{
			if (i == 17)SpriteActual = Movimiento::Arriba3;
			misLugares->DibujarLugar(miBuffer->Graphics, Yo->LugarActual, Yo->getPseudoX() * 48, Yo->getPseudoY() * 48 - i);
			Yo->MostrarMiniatura(miBuffer->Graphics, SpriteActual);
			miBuffer->Render(miGraphics);
			//System::Threading::Thread::Sleep(0);
		}
		Yo->setPseudoX(Yo->NuevaCordX);
		Yo->setPseudoY(Yo->NuevaCordY);
		for (int i = 25; i <= 48; i++)
		{
			if (i == 33)SpriteActual = Movimiento::Arriba2;
			misLugares->DibujarLugar(miBuffer->Graphics, Yo->ProximoLugar, Yo->getPseudoX() * 48, Yo->getPseudoY() * 48 - i);
			Yo->MostrarMiniatura(miBuffer->Graphics, SpriteActual);
			miBuffer->Render(miGraphics);
			//System::Threading::Thread::Sleep(0);
		}
		Yo->setPseudoY(Yo->getPseudoY() - 1);
		Yo->LugarActual = Yo->ProximoLugar;
	}
	else
	{
		for (int i = 1; i <= 48; i++)
		{
			if (i == 17)SpriteActual = Movimiento::Arriba3;
			else if (i == 33)SpriteActual = Movimiento::Arriba2;
			misLugares->DibujarLugar(miBuffer->Graphics, Yo->LugarActual, Yo->getPseudoX() * 48, Yo->getPseudoY() * 48 - i);
			Yo->MostrarMiniatura(miBuffer->Graphics, SpriteActual);
			miBuffer->Render(miGraphics);
			//System::Threading::Thread::Sleep(0);
		}
		Yo->setPseudoY(Yo->getPseudoY() - 1);
	}
}

bool Juego::Mapa_ColisionPuerta(BufferedGraphics^ miBuffer, Graphics^ miGraphic, Tecla Direccion)
{
	short int CordX = Yo->getPseudoX();
	short int CordY = Yo->getPseudoY();

	if (Direccion == Tecla::Abajo) CordY ++;
	else if (Direccion == Tecla::Arriba) CordY --;
	else if (Direccion == Tecla::Derecha) CordX ++;
	else if (Direccion == Tecla::Izquierda) CordX --;

	switch (Yo->LugarActual)
	{
	case Plazuela:

		//Si Choca Con Gimnasio Normal
		if ((CordX == 9 && CordY == 7) || (CordX == 10 && CordY == 7))
		{
			Yo->ProximoLugar = Lugares::GimnasioNormal;
			Yo->NuevaCordX = 7;
			Yo->NuevaCordY = 15;;
			return true;
		}
		//Si Choca Con Gimnasion Agua
		else if ((CordX == 21 && CordY == 20) || (CordX == 22 && CordY == 20))
		{
			Yo->ProximoLugar = Lugares::GimnasioAgua;
			Yo->NuevaCordX = 13;
			Yo->NuevaCordY = 20;;
			return true;
		}
		//Si Choca Con Gimnasion Planta
		else if (CordY == 5 && CordX == 18)
		{
			Yo->ProximoLugar = Lugares::GimnasioPlanta;
			Yo->NuevaCordX = 11;
			Yo->NuevaCordY = 18;;
			return true;
		}
		//Si Choca Con Centro Pokemon
		else if ((CordX == 14 && CordY == 6) || (CordX == 15 && CordY == 6))
		{
			Yo->ProximoLugar = Lugares::CentroPokemon;
			Yo->NuevaCordX = 17;
			Yo->NuevaCordY = 16;;
			return true;
		}
		//casa de oak
		else if (CordX == 21 && CordY == 10)
		{
			EscenaAOki(miBuffer, miGraphic);
			
		}
		return false;

	case CentroPokemon:
		//Si Chocca Con Puerta A Plazuela
		if (CordX == 17 && CordY == 16)
		{
			Yo->ProximoLugar = Lugares::Plazuela;
			Yo->NuevaCordX = 14;
			Yo->NuevaCordY = 6;
			return true;
		}
		return false;

	case GimnasioNormal:
		//Si Chocca Con Puerta A Plazuela
		if (CordX == 7 && CordY == 15)
		{
			Yo->ProximoLugar = Lugares::Plazuela;
			Yo->NuevaCordX = 9;
			Yo->NuevaCordY = 7;
			return true;
		}
		return false;
		
	case GimnasioAgua:
		//Si Chocca Con Puerta A Plazuela
		if (CordX == 13 && CordY == 20)
		{
			Yo->ProximoLugar = Lugares::Plazuela;
			Yo->NuevaCordX = 21;
			Yo->NuevaCordY = 20;
			return true;
		}
		return false;

	case GimnasioPlanta:
		//Si Chocca Con Puerta A Plazuela
		if (CordX == 11 && CordY == 18)
		{
			Yo->ProximoLugar = Lugares::Plazuela;
			Yo->NuevaCordX = 18;
			Yo->NuevaCordY = 5;
			return true;
		}
		return false;

	}
}


void Juego::Mapa_RecibirDireccion(BufferedGraphics^ miBuffer, Graphics^ miGraphic, Tecla LaDireccion)
{
	bool CambiaONo = Mapa_ColisionPuerta(miBuffer, miGraphic, LaDireccion);
	switch (LaDireccion)
	{

	case Derecha:
		if (Yo->Sprite == Movimiento::Derecha2)
		{
			if (Yo->getPseudoX() + 1 <= 30 && Mapa_PuedeAvanzar(Movimiento::Derecha2)) Mapa_MoverMarcoDerecha(miBuffer, miGraphic, CambiaONo);
		}
		else
			Mapa_RotarMarco(miBuffer, miGraphic, Movimiento::Derecha2);
		break;

	case Izquierda:
		if (Yo->Sprite == Movimiento::Izquierda2)
			{ if (Mapa_PuedeAvanzar(Movimiento::Izquierda2)) Mapa_MoverMarcoIzquierda(miBuffer, miGraphic,CambiaONo); }
		else
			Mapa_RotarMarco(miBuffer,miGraphic, Movimiento::Izquierda2);
			
		break;

	case Arriba:
		if (Yo->Sprite == Movimiento::Arriba2)
			{ if (Mapa_PuedeAvanzar(Movimiento::Arriba2))	Mapa_MoverMarcoArriba(miBuffer, miGraphic,CambiaONo); }
		else
			Mapa_RotarMarco(miBuffer,miGraphic, Movimiento::Arriba2);
		break;

	case Abajo:
		if (Yo->Sprite == Movimiento::Abajo2)
			{ if (Mapa_PuedeAvanzar(Movimiento::Abajo2))	Mapa_MoverMarcoAbajo(miBuffer, miGraphic,CambiaONo); }
		else
			Mapa_RotarMarco(miBuffer,miGraphic, Movimiento::Abajo2);
		break;
	}
}

void Juego::Mapa_RotarMarco(BufferedGraphics^ miBuffer, Graphics^ miGraphic, Movimiento MiradaFinal)
{
	switch( MiradaFinal)
	{
	case Derecha2:
		misLugares->DibujarPorcion(miBuffer->Graphics, Yo->LugarActual, 336, 192, Yo->getPseudoX() * 48, Yo->getPseudoY() * 48, 96, 48);
		Yo->MostrarMiniatura(miBuffer->Graphics, Movimiento::Derecha1);
		miBuffer->Render(miGraphic);
		System::Threading::Thread::Sleep(50);
		misLugares->DibujarPorcion(miBuffer->Graphics, Yo->LugarActual, 336, 192, Yo->getPseudoX() * 48, Yo->getPseudoY() * 48, 96, 48);
		Yo->MostrarMiniatura(miBuffer->Graphics, Movimiento::Derecha2);
		miBuffer->Render(miGraphic);
		System::Threading::Thread::Sleep(50);
		Yo->Sprite = Movimiento::Derecha2;
		break;
	case Izquierda2:
		misLugares->DibujarPorcion(miBuffer->Graphics, Yo->LugarActual, 336, 192, Yo->getPseudoX() * 48, Yo->getPseudoY() * 48, 96, 48);
		Yo->MostrarMiniatura(miBuffer->Graphics, Movimiento::Izquierda1);
		miBuffer->Render(miGraphic);
		System::Threading::Thread::Sleep(50);
		misLugares->DibujarPorcion(miBuffer->Graphics, Yo->LugarActual, 336, 192, Yo->getPseudoX() * 48, Yo->getPseudoY() * 48, 96, 48);
		Yo->MostrarMiniatura(miBuffer->Graphics, Movimiento::Izquierda2);
		miBuffer->Render(miGraphic);
		System::Threading::Thread::Sleep(50);
		Yo->Sprite = Movimiento::Izquierda2;
		break;
	case Abajo2:
		misLugares->DibujarPorcion(miBuffer->Graphics, Yo->LugarActual, 336, 192, Yo->getPseudoX() * 48, Yo->getPseudoY() * 48, 96, 48);
		Yo->MostrarMiniatura(miBuffer->Graphics, Movimiento::Abajo1);
		miBuffer->Render(miGraphic);
		System::Threading::Thread::Sleep(50);
		misLugares->DibujarPorcion(miBuffer->Graphics, Yo->LugarActual, 336, 192, Yo->getPseudoX() * 48, Yo->getPseudoY() * 48, 96, 48);
		Yo->MostrarMiniatura(miBuffer->Graphics, Movimiento::Abajo2);
		miBuffer->Render(miGraphic);
		System::Threading::Thread::Sleep(50);
		Yo->Sprite = Movimiento::Abajo2;
		break;
	case Arriba2:
		misLugares->DibujarPorcion(miBuffer->Graphics, Yo->LugarActual, 336, 192, Yo->getPseudoX() * 48, Yo->getPseudoY() * 48, 96, 48);
		Yo->MostrarMiniatura(miBuffer->Graphics, Movimiento::Arriba1);
		miBuffer->Render(miGraphic);
		System::Threading::Thread::Sleep(50);
		misLugares->DibujarPorcion(miBuffer->Graphics, Yo->LugarActual,336, 192, Yo->getPseudoX() * 48, Yo->getPseudoY() * 48, 96, 48);
		Yo->MostrarMiniatura(miBuffer->Graphics, Movimiento::Arriba2);
		miBuffer->Render(miGraphic);
		System::Threading::Thread::Sleep(50);
		Yo->Sprite = Movimiento::Arriba2;
		break;
	}
}