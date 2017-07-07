#pragma once
#include <vcclr.h>
using namespace System;
using namespace System::Drawing;

enum QuienGano
{
	NadieGano,
	GanoMarco,
	GanoRival
};

enum Acciones
{
	Intercambiar,
	Activar,
	Desactivar
};

enum Turnos
{
	TurnoDeMarco,
	TurnoDeRival
};

enum Movimiento
{
	Arriba1,
	Arriba2,
	Arriba3,
	Abajo1,
	Abajo2,
	Abajo3,
	Izquierda1,
	Izquierda2,
	Izquierda3,
	Derecha1,
	Derecha2,
	Derecha3
};

enum Bloques
{
	Hierba,
	Piscina,
	Pared,
	PuertaShop,
	PuertaCP,
	PuertaGym1,
	PuertaGym2,
	PuertaGym3,
	PuertaGym4,
	PuertaGym5
};

enum Ticks
{
	Interfaces,
	Historia,
	EnMapa,
	EnBatalla,
	EnLugar
};

enum Lugares
{
	Plazuela,
	CentroPokemon,
	Fumadero,
	Sotano,
	GimnasioAgua,
	GimnasioPlanta,
	GimnasioNormal,
	Gimnasio4,
	Gimnasio5,
	Gimnasio6
};

enum Interfaces
{
	InterfazMenuPrincipal,
	InterfazIntroduccion,
	EscogeTuPokemon,
	FinalDeBatalla
};

enum Numeros
{
	Cero,
	Uno,
	Dos,
	Tres,
	Cuatro,
	Cinco,
	Seis,
	Siete,
	Ocho,
	Nueve,
	Diez
};

enum CategoriaTeclas
{
	TeclasNumericas,
	TeclasDeAccion,
	TeclasDeMovimiento,
	Cualquiera
};

enum Tecla
{
	Izquierda,
	Derecha,
	Arriba,
	Abajo,
	TeclaEscape,
	Tecla1,
	Tecla2,
	Tecla3,
	Tecla4,
	Tecla5,
	Tecla6,
	TeclaA,
	TeclaS,
	TeclaZ,
	TeclaX,
	TeclaEspacio
};
enum Pertenencia
{
	Ninguno,
	Salvaje,
	DeMarco,
	DeLider,
	Enemigo,
	Todos
};

enum Tipo
{
	Normal,
	Electrico,
	Planta,
	Roca,
	Agua,
	Fuego,
	Tierra,
	Bicho,
	Volador,
	Veneno,
	Psiquico,
	Siniestro,
	Dragon
};

enum Estado
{
	SinDibujo,
	Dibujado,
	SinActualizar,
	Actualizado,
	NoMasDibujos,
	EsperandoMecha,
	EsperandoMechaConLider,
	EsperandoNumericas,
	ActualizadoNumericas,
	EsperandoTeclaDireccional,
	EsperandoTecla,
	SinActualizarTecla,
	ActualizadoTecla,
	EsperandoAccion,
	SinActualizarAccion,
	ActualizadoAccion,
	EsperandoEscritura,
	SinActualizarEscritura,
	ActualizadoEscritura
};

enum TiposDeBatalla
{
	ContraPokemonSalvaje,
	ContraLider
};

enum MensajeDeAtaque
{
	MensajeNormal,
	MiDefensaSubio1,
	MiProteccionSubio1,
	MiVelocidadSubio1,
	MiVelocidadSubio2,
	MiAtaqueSubio1,
	MiAtaqueYEspecialSubio1,
	MiHPSubio1,
	RecargandoEnergia,
	PrecisionRivalBajo1,
	VelocidadRivalBajo1,
	VelocidadRivalBajo2,
	AtaqueRivalBajo1,
	EvasionRivalBajo1,
	DefensaRivalBajo1,
	Llovizna,
	Critico,
	NuncaFalla,
	IgualParaTodos,
	RivalQuemado1,
	RivalQuemado2,
	RivalParalizado1,
	RivalEnvenenado1,
	RivalDormido1	
};