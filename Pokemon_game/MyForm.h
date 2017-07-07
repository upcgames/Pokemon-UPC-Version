#pragma once
#include "Batalla.h"
#include "Juego.h"
#include <time.h>

namespace Pokemon_game {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			ManipularTimers(Acciones::Activar, Ticks::Interfaces);
			miTiempo = time(NULL);
			miGraphic = this->CreateGraphics();
			EspacioParaBuffer = BufferedGraphicsManager::Current;
			miBuffer = EspacioParaBuffer->Allocate(miGraphic, this->ClientRectangle);
			PokemonUPC = new Juego();	
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>

		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			delete PokemonUPC;
			delete miGraphic;
			delete EspacioParaBuffer;
			delete miBuffer;

		}
	private: System::Windows::Forms::Timer^  TimerInterfaces;
	private: System::Windows::Forms::Timer^  TimerBatalla;
	private: System::Windows::Forms::Timer^  TimerMapa;
	protected:

	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		Juego* PokemonUPC;
		time_t miTiempo;
		Graphics^ miGraphic;
		BufferedGraphicsContext^ EspacioParaBuffer;
		BufferedGraphics^ miBuffer;
		
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->TimerInterfaces = (gcnew System::Windows::Forms::Timer(this->components));
			this->TimerBatalla = (gcnew System::Windows::Forms::Timer(this->components));
			this->TimerMapa = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// TimerInterfaces
			// 
			this->TimerInterfaces->Tick += gcnew System::EventHandler(this, &MyForm::TimerInterfaces_Tick);
			// 
			// TimerBatalla
			// 
			this->TimerBatalla->Tick += gcnew System::EventHandler(this, &MyForm::TimerBatalla_Tick);
			// 
			// TimerMapa
			// 
			this->TimerMapa->Tick += gcnew System::EventHandler(this, &MyForm::TimerMapa_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(720, 480);
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"MyForm";
			this->Text = L"Pokemon UPC";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	
public:

	void ManipularTimers(Acciones QueSeVaAHacer, Ticks ElTick)
	{
		switch (QueSeVaAHacer)
		{
			case Acciones::Intercambiar:
			{
				if (ElTick == Ticks::Interfaces)
				{
					TimerBatalla->Enabled = false;
					TimerInterfaces->Enabled = true;
					TimerMapa->Enabled = false;
				}
				else if (ElTick == Ticks::EnBatalla)
				{
					TimerBatalla->Enabled = true;
					TimerInterfaces->Enabled = false;
					TimerMapa->Enabled = false;
				}
				else if (ElTick == Ticks::EnMapa)
				{
					TimerBatalla->Enabled = false;
					TimerInterfaces->Enabled = false;
					TimerMapa->Enabled = true;
				}
				break;
			}
			case Acciones::Activar:
			{
				if (ElTick == Ticks::EnBatalla)TimerBatalla->Enabled = true;
				if (ElTick == Ticks::Interfaces)TimerInterfaces->Enabled = true;
				if (ElTick == Ticks::EnMapa)TimerMapa->Enabled = true;
				break;
			}
			case Acciones::Desactivar:
			{
				if (ElTick == Ticks::EnBatalla)TimerBatalla->Enabled = false;
				if (ElTick == Ticks::Interfaces)TimerInterfaces->Enabled = false;
				if (ElTick == Ticks::EnMapa)TimerMapa->Enabled = false;
				break;
			}
		}
	}
	

private: 


	System::Void TimerMapa_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		if (PokemonUPC->getEstadoDeImagen() == Estado::SinDibujo)
		{
			PokemonUPC->getMisLugares()->DibujarLugar(miBuffer->Graphics, PokemonUPC->Yo->LugarActual, PokemonUPC->Yo->getPseudoX() * 48, PokemonUPC->Yo->getPseudoY() * 48);
			PokemonUPC->Yo->MostrarMiniatura(miBuffer->Graphics, Movimiento(PokemonUPC->Yo->Sprite));
			miBuffer->Render(miGraphic);
			PokemonUPC->setEstadoDeImagen(Estado::Dibujado);
			PokemonUPC->setEstadoDeImagen(Estado::EsperandoTeclaDireccional);
		}
		else if (PokemonUPC->getEstadoDeImagen() == Estado::EsperandoMecha)
		{
			ManipularTimers(Intercambiar, Ticks::EnBatalla);
			PokemonUPC->Batalla_CrearBatalla();
			PokemonUPC->setEstadoDeImagen(Estado::SinDibujo);
		}
		else if (PokemonUPC->getEstadoDeImagen() == Estado::EsperandoMechaConLider)
		{
			ManipularTimers(Intercambiar, Ticks::EnBatalla);
			PokemonUPC->setEstadoDeImagen(Estado::SinDibujo);
		}
	}


	System::Void TimerBatalla_Tick(System::Object^  sender, System::EventArgs^  e) 
	{
		if (PokemonUPC->getEstadoDeImagen() == Estado::SinDibujo)
		{
			if (PokemonUPC->Yo->getArregloPokemon()->HayVariosPokemones())
			{
				PokemonUPC->Batalla_EscogerPokemon(miBuffer, miGraphic);
				PokemonUPC->setEstadoDeImagen(Estado::EsperandoNumericas);
			}
			else
			{
				PokemonUPC->setEstadoDeImagen(Estado::ActualizadoNumericas);
			}
		}
		if (PokemonUPC->getEstadoDeImagen() == Estado::ActualizadoNumericas)
		{
			PokemonUPC->getBatalla()->DibujarEscenario(miBuffer ,miGraphic);
			PokemonUPC->setEstadoDeImagen(Estado::Dibujado);
			PokemonUPC->setEstadoDeImagen(Estado::EsperandoAccion);
		}
		
		else if (PokemonUPC->getEstadoDeImagen() == Estado::SinActualizarAccion)
		{
			PokemonUPC->getBatalla()->DibujarDialogoBatalla(miBuffer , miGraphic);
			PokemonUPC->setEstadoDeImagen(Estado::ActualizadoAccion);
			PokemonUPC->setEstadoDeImagen(Estado::EsperandoAccion);
		}
		else if (PokemonUPC->getEstadoDeImagen() == Estado::NoMasDibujos)
		{
			PokemonUPC->getBatalla()->getPokemonMio()->setUltimoDanio(0);
			PokemonUPC->getBatalla()->getPokemonRetador()->setUltimoDanio(0);
			PokemonUPC->setEscena(Interfaces::FinalDeBatalla);
			PokemonUPC->setEstadoDeImagen(Estado::SinDibujo);
			ManipularTimers(Acciones::Intercambiar, Ticks::Interfaces);
		}

				
	}

	System::Void TimerInterfaces_Tick(System::Object^  sender, System::EventArgs^  e)
	{
	
		time_t TiempoEnFuncion;
		TiempoEnFuncion = time(NULL);

//----------------------------------------------//*** MENU DE INICIO***-------------------------------------------------------------\\

		if (PokemonUPC->getEscena() == Interfaces::InterfazMenuPrincipal)
		{
			if (PokemonUPC->getEstadoDeImagen() == Estado::SinDibujo)
			{
				PokemonUPC->Escena1_Mostrar(miBuffer->Graphics);
				miBuffer->Render(miGraphic);
				PokemonUPC->setEstadoDeImagen(Estado::Dibujado);
			}
			else if (difftime(TiempoEnFuncion, miTiempo) >= 0 && PokemonUPC->getEstadoDeImagen() == Estado::Dibujado)
			{
				PokemonUPC->Escena1_Boton1(miBuffer->Graphics);
				miBuffer->Render(miGraphic);
				PokemonUPC->setEstadoDeImagen(Estado::Actualizado);
			}
			else if (PokemonUPC->getEstadoDeImagen() == Estado::NoMasDibujos)
			{
				PokemonUPC->setEscena(Interfaces::EscogeTuPokemon);
				PokemonUPC->setEstadoDeImagen(Estado::SinDibujo);
			}
		}
//--------------------------------------------//***INTRODUCCIÓN DEL JUEGO***----------------------------------------------------------\\

		else if (PokemonUPC->getEscena() == Interfaces::InterfazIntroduccion)
		{

			ManipularTimers(Acciones::Intercambiar, Ticks::EnMapa);
		}

//--------------------------------------------//***INTERFAZ PARA ESCOGER POKEMONES***-------------------------------------------------\\

		else if (PokemonUPC->getEscena() == Interfaces::EscogeTuPokemon)
		{
			if (PokemonUPC->getEstadoDeImagen() == Estado::SinDibujo)
			{
				PokemonUPC->EscenaIntro(miBuffer, miGraphic);
				PokemonUPC->EscogerPokemon(miBuffer->Graphics);
				miBuffer->Render(miGraphic);
				PokemonUPC->setEstadoDeImagen(Estado::Dibujado);
			}
			else if (PokemonUPC->getEstadoDeImagen() == Estado::NoMasDibujos)
			{
				PokemonUPC->setEscena(Interfaces::InterfazIntroduccion);
				PokemonUPC->setEstadoDeImagen(Estado::SinDibujo);
				
			}
		}
		
//-----------------------------------------------//***BATALLA POKEMON***--------------------------------------------------------------\\

	

//--------------------------------------------//***CONCLUSIÓN DE LA BATALLA 1***------------------------------------------------------\\

		else if (PokemonUPC->getEscena() == Interfaces::FinalDeBatalla)
		{
			if (PokemonUPC->EstadoDialogo == 2)
			{
				ManipularTimers(Acciones::Intercambiar, Ticks::EnMapa);
				PokemonUPC->EstadoDialogo = 0;
			}
			else
			PokemonUPC->FinBatalla(miBuffer , miGraphic);	
		}

//------------------------------------------------------------------------------------------------------------------------------------\\

	}

	System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
	{
		Tecla TeclaPresionada;
		CategoriaTeclas Categoria = CategoriaTeclas::Cualquiera;

		if (e->KeyCode == Keys::A){ Categoria  = CategoriaTeclas::TeclasDeAccion , TeclaPresionada = Tecla::TeclaA; }
		else if (e->KeyCode == Keys::S){ Categoria = CategoriaTeclas::TeclasDeAccion , TeclaPresionada = Tecla::TeclaS; }
		else if (e->KeyCode == Keys::Z){ Categoria = CategoriaTeclas::TeclasDeAccion , TeclaPresionada = Tecla::TeclaZ; }
		else if (e->KeyCode == Keys::X){ Categoria = CategoriaTeclas::TeclasDeAccion , TeclaPresionada = Tecla::TeclaX; }
		else if (e->KeyCode == Keys::Left){ Categoria = CategoriaTeclas::TeclasDeMovimiento, TeclaPresionada = Tecla::Izquierda; }
		else if (e->KeyCode == Keys::Right){ Categoria = CategoriaTeclas::TeclasDeMovimiento, TeclaPresionada = Tecla::Derecha; }
		else if (e->KeyCode == Keys::Up){ Categoria = CategoriaTeclas::TeclasDeMovimiento, TeclaPresionada = Tecla::Arriba; }
		else if (e->KeyCode == Keys::Down){ Categoria = CategoriaTeclas::TeclasDeMovimiento, TeclaPresionada = Tecla::Abajo; }
		else if (e->KeyCode == Keys::D1){ Categoria = CategoriaTeclas::TeclasNumericas, TeclaPresionada = Tecla::Tecla1; }
		else if (e->KeyCode == Keys::D2){ Categoria = CategoriaTeclas::TeclasNumericas, TeclaPresionada = Tecla::Tecla2; }
		else if (e->KeyCode == Keys::D3){ Categoria = CategoriaTeclas::TeclasNumericas, TeclaPresionada = Tecla::Tecla3; }
		else if (e->KeyCode == Keys::D4){ Categoria = CategoriaTeclas::TeclasNumericas, TeclaPresionada = Tecla::Tecla4; }
		else if (e->KeyCode == Keys::D5){ Categoria = CategoriaTeclas::TeclasNumericas, TeclaPresionada = Tecla::Tecla5; }
		else if (e->KeyCode == Keys::D6){ Categoria = CategoriaTeclas::TeclasNumericas, TeclaPresionada = Tecla::Tecla6; }
		else if (e->KeyCode == Keys::Space){ TeclaPresionada = Tecla::TeclaEspacio; }
		else if (e->KeyCode == Keys::Escape){ TeclaPresionada = Tecla::TeclaEscape; }
		
		if (TimerMapa->Enabled == true)
		{
			ManipularTimers(Acciones::Desactivar, Ticks::EnMapa);
			if (PokemonUPC->getEstadoDeImagen() == Estado::EsperandoTeclaDireccional && Categoria == CategoriaTeclas::TeclasDeMovimiento)
			{
				PokemonUPC->Mapa_RecibirDireccion(miBuffer,miGraphic, TeclaPresionada);
				PokemonUPC->Mapa_AccionTerreno(miBuffer , miGraphic);
			}
			else if (TeclaPresionada == Tecla::TeclaZ)
			{
				PokemonUPC->MostarMedallas(miBuffer, miGraphic);
			}
			else if (TeclaPresionada == Tecla::TeclaEspacio)
			{
				PokemonUPC->Mapa_ConsultarBloque(miBuffer , miGraphic);
			}
			else if (PokemonUPC->getEstadoDeImagen() == Estado::EsperandoTecla)
			{
				PokemonUPC->setEstadoDeImagen(Estado::SinDibujo);
			}
			ManipularTimers(Acciones::Activar, Ticks::EnMapa);
		}

		else if (TimerBatalla->Enabled == true)
		{
			ManipularTimers(Acciones::Desactivar, Ticks::EnBatalla);
			if (PokemonUPC->getEstadoDeImagen() == Estado::EsperandoNumericas && Categoria == CategoriaTeclas::TeclasNumericas)
			{
				PokemonUPC->Batalla_CambiarPokemon(TeclaPresionada);
				PokemonUPC->Batalla_CrearBatalla();
				PokemonUPC->setEstadoDeImagen(Estado::ActualizadoNumericas);
			}

			else if (PokemonUPC->getEstadoDeImagen() == Estado::EsperandoAccion && TeclaPresionada == Tecla::TeclaEscape)
			{
				PokemonUPC->Batalla_Huida(miBuffer, miGraphic);

			}
			else if (PokemonUPC->getEstadoDeImagen() == Estado::EsperandoAccion && TeclaPresionada == Tecla::TeclaEspacio)
			{
				PokemonUPC->Batalla_LanzarPokebola(miBuffer,miGraphic);
				
			}

			else if ( PokemonUPC->getEstadoDeImagen() == Estado::EsperandoAccion && Categoria == CategoriaTeclas::TeclasDeAccion )
			{
				PokemonUPC->Batalla_Atacar(miBuffer , miGraphic, TeclaPresionada);	
			}
			else if ( PokemonUPC->getEstadoDeImagen() == Estado::EsperandoTecla )
			{
				if (PokemonUPC->getBatalla()->getGanador() != QuienGano::NadieGano )
					PokemonUPC->setEstadoDeImagen(Estado::NoMasDibujos);
				else if (PokemonUPC->getBatalla()->getGanador() == QuienGano::NadieGano)
				{
					if (PokemonUPC->getBatalla()->getTurno() == Turnos::TurnoDeMarco)
						PokemonUPC->setEstadoDeImagen(Estado::SinActualizarAccion);
					else if(PokemonUPC->getBatalla()->getTurno() == Turnos::TurnoDeRival)
					{
						PokemonUPC->Batalla_Defender(miBuffer , miGraphic);
					}
				}
			}
			ManipularTimers(Acciones::Activar, Ticks::EnBatalla);
		}

		else if (TimerInterfaces->Enabled == true)
		{
			if (PokemonUPC->getEscena() == Interfaces::InterfazMenuPrincipal)
			{
				if (PokemonUPC->getEstadoDeImagen() == Estado::Actualizado)
					PokemonUPC->setEstadoDeImagen(Estado::NoMasDibujos);			}

			else if (PokemonUPC->getEscena() == Interfaces::EscogeTuPokemon)
			{
					if (e->KeyCode == Keys::A) PokemonUPC->Escena3_Escoger(Tecla::TeclaA);
				else if (e->KeyCode == Keys::S) PokemonUPC->Escena3_Escoger(Tecla::TeclaS);
				else if (e->KeyCode == Keys::Z) PokemonUPC->Escena3_Escoger(Tecla::TeclaZ);
				else if (e->KeyCode == Keys::X) PokemonUPC->Escena3_Escoger(Tecla::TeclaX);
			}

			else
			{

			}
		}
	}
	
};
}