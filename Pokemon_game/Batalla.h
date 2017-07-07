#pragma once
#include "Marco.h"
#include "Lider.h"
#include "Dibujos.h"



class Batalla
{
private:
	Pokemon* PokemonRetador;
	Pokemon* PokemonMio;
	int Ganador;
	int Turno;

public:
	Batalla(void);
	Batalla(Entrenador* NuestroMarco, Entrenador* LiderDeGimnasio);// Para Lideres
	Batalla(Marco* NuestroMarco);
	~Batalla(void);
	int TipoDeBatalla;
	int getGanador();
	int getTurno();
	void setTurno(Turnos NuevoTurno);
	void setGanador(QuienGano NuevoGanador);
	Pokemon* getPokemonRetador();
	Pokemon* getPokemonMio();
	String^ getMensajeDeBatalla(int NumeroDeAtaque, int IndexDeAtaque, Pertenencia PokemonRivalOAliado);
	void CambiarPokemon(BufferedGraphics^ miBuffer, Graphics^ miGraphic, Pokemon* ElPokemon, Marco* Yo, Lider* ElLider);
	void DibujarEscenario(BufferedGraphics^ miBuffer, Graphics^ miGraphic);
	void DibujarDialogoBatalla(BufferedGraphics^ miBuffer, Graphics^ miGraphic);
	void ActualizarEscenario(BufferedGraphics^ miBuffer, Graphics^ Graphic, Pertenencia PokemonAActualizar);
	void BatallarConMi(char* TipoDeAtaque);
	void ElRivalBatalla(int NumeroDeAtaque);
};

//Constructor
Batalla::Batalla(void){}
Batalla::Batalla(Entrenador* NuestroMarco, Entrenador* LiderDeGimnasio)
{
	TipoDeBatalla = TiposDeBatalla::ContraLider;
	Turno = Turnos::TurnoDeMarco;
	Ganador = QuienGano::NadieGano;
	PokemonMio = NuestroMarco->getArregloPokemon()->RetornaPokemon(NuestroMarco->PokemonMechador);
	PokemonRetador = LiderDeGimnasio->getArregloPokemon()->RetornaPokemon(LiderDeGimnasio->PokemonMechador);
}

Batalla::Batalla(Marco* NuestroMarco)
{
	TipoDeBatalla = TiposDeBatalla::ContraPokemonSalvaje;
	Turno = Turnos::TurnoDeMarco;
	Ganador = QuienGano::NadieGano;
	PokemonMio = NuestroMarco->getArregloPokemon()->RetornaPokemon(NuestroMarco->PokemonMechador);

	Random VariableRandom;
	int EnteroRandom;
	EnteroRandom = VariableRandom.Next(1, 31);

	switch (EnteroRandom)
	{
	case 1:
		PokemonRetador = new Pikachu();
		break;
	case 2:
		PokemonRetador = new Bulbasaur();
		break;
	case 3:
		PokemonRetador = new Charmander();
		break;
	case 4:
		PokemonRetador = new Squirtle();
		break;
	case 5:
		PokemonRetador = new Cyndaquil();
		break;
	case 6:
		PokemonRetador = new Chikorita();
		break;
	case 7:
		PokemonRetador = new Totodile();
		break;
		//5normal
	case 8:
		PokemonRetador = new Rattata();
		break;
	case 9:
		PokemonRetador = new Meowth();
		break;
	case 10:
		PokemonRetador = new Lickitung();
		break;
	case 11:
		PokemonRetador = new Snorlax();
		break;
	case 12:
		PokemonRetador = new Aipom();
		break;
		//5psiquico
	case 13:
		PokemonRetador = new Abra();
		break;
	case 14:
		PokemonRetador = new Mew();
		break;
	case 15:
		PokemonRetador = new Wobbufet();
		break;
	case 16:
		PokemonRetador = new Garvedoir();
		break;
	case 17:
		PokemonRetador = new Natu();
		break;
		//fuego
	case 18:
		PokemonRetador = new Slugma();
		break;
	case 19:
		PokemonRetador = new Ponyta();
		break;
	case 20:
		PokemonRetador = new Entei();
		break;
		//agua
	case 21:
		PokemonRetador = new Suicune();
		break;
	case 22:
		PokemonRetador = new Wailmer();
		break;
	case 23:
		PokemonRetador = new Kyogre();
		break;
		//electrico
	case 24:
		PokemonRetador = new Jolteon();
		break;
	case 25:
		PokemonRetador = new Raikou();
		break;
	case 26:
		PokemonRetador = new Manectric();
		break;
	case 27:
		PokemonRetador = new Voltorb();
		break;
		//planta
	case 28:
		PokemonRetador = new Treecko();
		break;
	case 29:
		PokemonRetador = new Cacnea();
		break;
	case 30:
		PokemonRetador = new Lotad();
		break;
	}
}



// Destructor
Batalla::~Batalla(void)
{
	PokemonRetador = NULL;
	PokemonMio = NULL;
}

int Batalla::getGanador(){ return Ganador; }
int Batalla::getTurno(){ return Turno; }

void Batalla::setTurno(Turnos NuevoTurno){ Turno = NuevoTurno; }
void Batalla::setGanador(QuienGano NuevoGanador){ Ganador = NuevoGanador; }

Pokemon* Batalla::getPokemonRetador(){ return PokemonRetador; }
Pokemon* Batalla::getPokemonMio(){ return PokemonMio; }

String^ Batalla::getMensajeDeBatalla(int NumeroDeAtaque, int IndexDeAtaque, Pertenencia DeQuienEsElPokemon)
{
	String^ PokemonAtacante;
	String^ PokemonDefensor;
	String^ UsoDePoder;

	int Auxiliar;
	if (NumeroDeAtaque <= 0)
		Auxiliar = -1;
	else
		Auxiliar = 1;

	NumeroDeAtaque = abs(NumeroDeAtaque);
	NumeroDeAtaque--;
	if (DeQuienEsElPokemon == Pertenencia::DeMarco)
	{
		PokemonAtacante = gcnew String(PokemonMio->getNombre());
		PokemonDefensor = gcnew String(PokemonRetador->getNombre()) + " enemigo";
		UsoDePoder = "Usaste " + gcnew String(PokemonMio->getAtaque(NumeroDeAtaque)) + "!";

	}
	else
	{
		PokemonAtacante = gcnew String(PokemonRetador->getNombre()) + " enemigo";
		PokemonDefensor = gcnew String(PokemonMio->getNombre());
		UsoDePoder = PokemonAtacante + " usó " + gcnew String(PokemonRetador->getAtaque(NumeroDeAtaque)) + "!";
	}

	String^ MensajeDeBatalla = UsoDePoder;

	switch (IndexDeAtaque)
	{
	case MensajeNormal:{break; }
	case MiDefensaSubio1:{MensajeDeBatalla = "La defensa de " + PokemonAtacante + " subió!"; break; }
	case MiProteccionSubio1:{MensajeDeBatalla = PokemonAtacante + " está protegido!"; break; }
	case MiVelocidadSubio1:{MensajeDeBatalla = "La velocidad de " + PokemonAtacante + " subió!"; break; }
	case MiVelocidadSubio2:{MensajeDeBatalla = "La velocidad de " + PokemonAtacante + " subió MUCHO!!!"; break; }
	case MiAtaqueSubio1:{MensajeDeBatalla = "El ataque de " + PokemonAtacante + " subió."; break; }
	case MiAtaqueYEspecialSubio1:{MensajeDeBatalla = "El ataque de " + PokemonAtacante + " subió!"; break; }
	case MiHPSubio1:{MensajeDeBatalla = "El HP de " + PokemonAtacante + " subió!"; break; }
	case RecargandoEnergia:{MensajeDeBatalla = " Y " + PokemonAtacante + " está recargando energías!"; break; }
	case PrecisionRivalBajo1:{MensajeDeBatalla = "La precisión de " + PokemonDefensor + " bajó!"; break; }
	case VelocidadRivalBajo1:{MensajeDeBatalla = "La velocidad de " + PokemonDefensor + " bajó!"; break; }
	case VelocidadRivalBajo2:{MensajeDeBatalla = "La velocidad de " + PokemonDefensor + " bajó MUCHO!!!"; break; }
	case AtaqueRivalBajo1:{MensajeDeBatalla = "El ataque de " + PokemonDefensor + " bajó!"; break; }
	case EvasionRivalBajo1:{MensajeDeBatalla = "La evasión de " + PokemonDefensor + " bajó!"; break; }
	case DefensaRivalBajo1:{MensajeDeBatalla = "La defensa de " + PokemonDefensor + " bajó!"; break; }
	case Llovizna:{MensajeDeBatalla = "Y provocó una llovizna!"; break; }
	case Critico:{MensajeDeBatalla = " Y provocó un golpe CRÍTICO!!!"; break; }
	case NuncaFalla:{MensajeDeBatalla = " NUNCA falla!"; break; }
	case IgualParaTodos:{MensajeDeBatalla = "Y afecta a todos los pokemones cercanos!."; break; }
	case RivalQuemado1:{MensajeDeBatalla = PokemonDefensor + " parece quemado!"; break; }
	case RivalQuemado2:{MensajeDeBatalla = PokemonDefensor + " está completamente QUEMADO!!!"; break; }
	case RivalParalizado1:{MensajeDeBatalla = PokemonDefensor + " parece paralizado!"; break; }
	case RivalEnvenenado1:{MensajeDeBatalla = PokemonDefensor + " parece envenenado!"; break; }
	case RivalDormido1:{MensajeDeBatalla = PokemonDefensor + " está profundamente dormido!"; break; }

	}

	if (Auxiliar == -1)
		return UsoDePoder;
	if (Auxiliar == 1)
		return MensajeDeBatalla;
}

void Batalla::CambiarPokemon(BufferedGraphics^ miBuffer, Graphics^ miGraphic, Pokemon* ElPokemon, Marco* Yo, Lider* ElLider)
{
	if (ElPokemon->getPertenenciaPokemon() == Pertenencia::DeMarco)
	{
		EscribirLinea(miBuffer, miGraphic, "Tu Pokemon se ha debilitado.", 2, true, 80);
		Threading::Thread::Sleep(800);
		PokemonMio = Yo->getArregloPokemon()->RetornSiguientePokemon();
		misFondos.MostrarFondo(miBuffer->Graphics, Fondos::BatallaSalvaje);
		misFondos.MostrarPNG(miBuffer->Graphics, PNGS::CuadroDialogo, 0, 336, 720, 144, 720, 144);
		DibujarCuadroPokemon(miBuffer, miGraphic, PokemonMio, 310, 240);
		DibujarCuadroPokemon(miBuffer, miGraphic, PokemonRetador, 50, 50);
	}
	else if (ElPokemon->getPertenenciaPokemon() == Pertenencia::DeLider)
	{
		EscribirLinea(miBuffer, miGraphic, "El Pokemon del lider se ha debilitado.", 2, true, 80);
		Threading::Thread::Sleep(800);
		PokemonRetador = ElLider->getArregloPokemon()->RetornSiguientePokemon();
		misFondos.MostrarFondo(miBuffer->Graphics, Fondos::BatallaSalvaje);
		misFondos.MostrarPNG(miBuffer->Graphics, PNGS::CuadroDialogo, 0, 336, 720, 144, 720, 144);
		DibujarCuadroPokemon(miBuffer, miGraphic, PokemonRetador, 50, 50);
		DibujarCuadroPokemon(miBuffer, miGraphic, PokemonMio, 310, 240);
	}
}

void Batalla::DibujarEscenario(BufferedGraphics^ miBuffer, Graphics^ miGraphic)
{
	misFondos.MostrarFondo(miBuffer->Graphics, Fondos::BatallaSalvaje);
	misFondos.MostrarPNG(miBuffer->Graphics, PNGS::CuadroDialogo, 0, 336, 720, 144, 720, 144);

	PokemonRetador->DibujarPokemon(miBuffer->Graphics, 360, 35, 200, 200);
	PokemonMio->DibujarPokemon(miBuffer->Graphics, 80, 188, 160, 160);

	DibujarCuadroPokemon(miBuffer, miGraphic, PokemonRetador, 50, 50);
	DibujarCuadroPokemon(miBuffer, miGraphic, PokemonMio, 310, 240);

	DibujarAtaquesPokemon(miBuffer, miGraphic, PokemonMio, 200, 380);

	miBuffer->Render(miGraphic);
}

void Batalla::ActualizarEscenario(BufferedGraphics^ miBuffer, Graphics^ miGraphic, Pertenencia PokemonAActualizar)
{
	if (PokemonAActualizar == Pertenencia::Todos)
	{
		DibujarCuadroPokemon(miBuffer, miGraphic, PokemonRetador, 50, 50);
		DibujarCuadroPokemon(miBuffer, miGraphic, PokemonMio, 310, 240);
	}
	else if (PokemonAActualizar == Pertenencia::Enemigo)
	{
		miBuffer->Graphics->DrawString(
			PokemonRetador->getVida().ToString(),//------------------->La Vida del Pokemon
			gcnew Font("Lucida Console", 14, FontStyle::Bold),//->La Fuente
			gcnew SolidBrush(Color::FromArgb(110, 218, 163)),//-->El Color
			57,//----------------------------------------->La Coordenada X
			67//----------------------------------------->La Coordenada Y
			);
		DibujarVidas(miBuffer, miGraphic, PokemonRetador, 151, 94);
	}

	else if (PokemonAActualizar == Pertenencia::DeMarco)
	{
		miBuffer->Graphics->DrawString(
			PokemonMio->getVida().ToString(),//------------------->La Vida del Pokemon
			gcnew Font("Lucida Console", 14, FontStyle::Bold),//->La Fuente
			gcnew SolidBrush(Color::FromArgb(110, 218, 163)),//-->El Color
			340,//----------------------------------------->La Coordenada X
			262//----------------------------------------->La Coordenada Y
			);
		DibujarVidas(miBuffer, miGraphic, PokemonMio, 440, 287);

	}
	miBuffer->Render(miGraphic);
}

void Batalla::DibujarDialogoBatalla(BufferedGraphics^ miBuffer, Graphics^ miGraphic)
{
	misFondos.MostrarPNG(miBuffer->Graphics, PNGS::CuadroDialogo, 0, 348, 600, 152, 600, 152);
	DibujarAtaquesPokemon(miBuffer, miGraphic, PokemonMio, 200, 380);

	miBuffer->Render(miGraphic);
}

int ObtenerDanioReal(int Ataque ,Pokemon* PokemonAtacante, Pokemon* PokemonDefensor)
{
	switch (PokemonAtacante->getTipo())
	{
	case 1:
		if (PokemonDefensor->getTipo() == 2)return Ataque*0.5;
		else if (PokemonDefensor->getTipo() == 1)return Ataque *0.5;
		else if (PokemonDefensor->getTipo() == 4)return Ataque * 2;
		
	case 2:
		if (PokemonDefensor->getTipo() == 2)return Ataque*0.5;
		else if (PokemonDefensor->getTipo() == 3)return Ataque *0.5;
		else if (PokemonDefensor->getTipo() == 4)return Ataque * 2;
		
	case 3:
		if (PokemonDefensor->getTipo() == 2)return Ataque*2;
		else if (PokemonDefensor->getTipo() == 3)return Ataque *0.5;
	
	case 4:
		if (PokemonDefensor->getTipo() == 2)return Ataque*0.5;
		else if (PokemonDefensor->getTipo() == 3)return Ataque * 2;
		else if (PokemonDefensor->getTipo() == 4)return Ataque * 0.5;
		
	case 5:
		if (PokemonDefensor->getTipo() == 5)return Ataque*0.5;

	default: 
		return Ataque;
	}

}

void Batalla::BatallarConMi(char* TipoDeAtaque)
{
	int AtaqueReal;
	if (strcmp(TipoDeAtaque, "Primera") == 0)
	{
		AtaqueReal = ObtenerDanioReal(PokemonMio->getDanio1(), PokemonMio, PokemonRetador);
	}
	else if (strcmp(TipoDeAtaque, "Segunda") == 0)
	{
		AtaqueReal = ObtenerDanioReal(PokemonMio->getDanio2(), PokemonMio, PokemonRetador);
	}
	else if (strcmp(TipoDeAtaque, "Tercera") == 0)
	{
		AtaqueReal = ObtenerDanioReal(PokemonMio->getDanio3(), PokemonMio, PokemonRetador);
	}
	else if (strcmp(TipoDeAtaque, "Cuarta") == 0)
	{
		AtaqueReal = ObtenerDanioReal(PokemonMio->getDanio4(), PokemonMio, PokemonRetador);
	}
	PokemonRetador->setVida(PokemonRetador->getVida() - AtaqueReal);
	PokemonRetador->setUltimoDanio(AtaqueReal);
}

void Batalla::ElRivalBatalla(int NumeroDeAtaque)
{
	int AtaqueReal;
	switch (NumeroDeAtaque)
	{
	case 0:
		AtaqueReal = ObtenerDanioReal(PokemonRetador->getDanio1(), PokemonRetador, PokemonMio);
		break;
	case 1:
		AtaqueReal = ObtenerDanioReal(PokemonRetador->getDanio2(), PokemonRetador, PokemonMio);
		break;
	case 2:
		AtaqueReal = ObtenerDanioReal(PokemonRetador->getDanio1(), PokemonRetador, PokemonMio);
		break;
	case 3:
		AtaqueReal = ObtenerDanioReal(PokemonRetador->getDanio1(), PokemonRetador, PokemonMio);
		break;
	}

	PokemonMio->setVida(PokemonMio->getVida() - AtaqueReal);
	PokemonMio->setUltimoDanio(AtaqueReal);

}