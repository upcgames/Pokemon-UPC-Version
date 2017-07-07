#include "ArregloPokemon.h"
#include "Fondo.h"

Fondo misFondos;

void DibujarVidas(BufferedGraphics^ miBuffer, Graphics^ miGraphic, Pokemon* PokemonEnCuestion , int CordX , int CordY)
{
	int PseudoVidaAntigua;//Es la vida del pokemon antes de recibir el ataque.
	int PseudoVidaActual;//Es la vida del pokemon después de recibir el ataque.
	int Vitalidad;//Es la vida completa que tiene el pokemon.
	int SizeBarraDeVida;//El tamaño de la barra de vida depende si el cartel pokemon esta arriba o está abajo.
	int PorcentajeReal;//Se utiliza para pintar la vida de diferentes colores.

	if (PokemonEnCuestion->getPertenenciaPokemon() == Pertenencia::DeMarco)
		SizeBarraDeVida = 128;
	else
		SizeBarraDeVida = 118;

	Vitalidad = PokemonEnCuestion->getVitalidad();
	
	if (PokemonEnCuestion->getVida() <= 0)
		PseudoVidaActual = 0;
	else
		PseudoVidaActual = PokemonEnCuestion->getVida() * SizeBarraDeVida / Vitalidad;
	
	PseudoVidaAntigua = (PokemonEnCuestion->getVida() + PokemonEnCuestion->getUltimoDanio()) * SizeBarraDeVida / Vitalidad;
	
	for (int i = PseudoVidaAntigua; i >= PseudoVidaActual; i--)
	{
		PorcentajeReal = PseudoVidaActual * 100 / SizeBarraDeVida;
	
		miBuffer->Graphics->FillRectangle(Brushes::White, Rectangle(CordX, CordY, SizeBarraDeVida, 8));

		if (PorcentajeReal <= 33)
			miBuffer->Graphics->FillRectangle(Brushes::Red, Rectangle(CordX , CordY , i , 8));
		else if (PorcentajeReal <= 66)
			miBuffer->Graphics->FillRectangle(Brushes::Yellow, Rectangle(CordX , CordY , i , 8));
		else
			miBuffer->Graphics->FillRectangle(Brushes::Green, Rectangle(CordX , CordY , i , 8));
	
		miBuffer->Render(miGraphic);
		System::Threading::Thread::Sleep(10);

	}
	
}

void DibujarCuadroPokemon(BufferedGraphics^ miBuffer , Graphics^miGraphic, Pokemon* miPokemon, int Cordx, int Cordy)
{
	int Ancho, Alto;
	float PorcentajeVida =miPokemon->getVida()*1.0/miPokemon->getVitalidad();
	int XVariable, YVariable;
	String^ CuadroPokemon;
	String^ DireccionPokemon;

	if (miPokemon->getPertenenciaPokemon() == Pertenencia::DeMarco)
	{	
		Ancho = 281; Alto = 101;
		XVariable = Cordx + 25;
		YVariable = Cordy + 12;
		CuadroPokemon = gcnew String("Data\\Imagenes\\PNGs\\CuadroDeStatsMio.png");
		miPokemon->DibujarPokemon(miBuffer->Graphics, 80, 188, 160, 160);
	}
	else
	{
		Ancho = 254; Alto = 77;
		XVariable = Cordx + 2;
		YVariable = Cordy + 7;
		CuadroPokemon = gcnew String("Data\\Imagenes\\PNGs\\CuadroDeStatsRetador.png");
		miPokemon->DibujarPokemon(miBuffer->Graphics, 360, 35, 200, 200);
	}
	
	miBuffer->Graphics->DrawImage(
		gcnew Bitmap(CuadroPokemon),//-------->Imagen del Pokemon
		Rectangle(Cordx, Cordy, Ancho, Alto),//Destino y Tamaño de la Imagen
		Rectangle(0, 0, Ancho, Alto),//------->Porcion de la Imagen
		GraphicsUnit::Pixel//----------------->Unidad de Medicion
		);

	miBuffer->Graphics->DrawString(
		gcnew String(miPokemon->getNombre()),//------------>El Nombre del Pokemon
		gcnew Font("Lucida Console", 15, FontStyle::Bold),//La Fuente
		Brushes::Black,//---------------------------------->El Color
		XVariable + 5,//--------------------------------------->La Coordenada X
		YVariable + 10//---------------------------------------->La Coordenada Y
		);

	int PseudoVida = miPokemon->getVida();

	if (PseudoVida <= 0)
		PseudoVida = 0;
	
	miBuffer->Graphics->DrawString(
		PseudoVida.ToString(),//------------------->La Vida del Pokemon
		gcnew Font("Lucida Console", 14, FontStyle::Bold),//->La Fuente
		gcnew SolidBrush(Color::FromArgb(110, 218, 163)),//-->El Color
		XVariable + 5,//----------------------------------------->La Coordenada X
		YVariable + 30//----------------------------------------->La Coordenada Y
		);
	
	miBuffer->Render(miGraphic);
	if (miPokemon->getPertenenciaPokemon() == Pertenencia::DeMarco)
		DibujarVidas(miBuffer, miGraphic, miPokemon, Cordx + 130, Cordy + 47);
	else
		DibujarVidas(miBuffer, miGraphic, miPokemon, Cordx + 101, Cordy + 44);	
}

void DibujarAtaquesPokemon(BufferedGraphics^ miBuffer , Graphics^miGraphic, Pokemon* miPokemon, int Cordx, int Cordy)
{

	Font^Fuente = gcnew Font("Lucida Console", 14);

	//capturar ataques
	String ^Ataque1 = gcnew String(miPokemon->getAtaque(0));
	String ^Ataque2 = gcnew String(miPokemon->getAtaque(1));
	String ^Ataque3 = gcnew String(miPokemon->getAtaque(2));
	String ^Ataque4 = gcnew String(miPokemon->getAtaque(3));

	miBuffer->Graphics->DrawString(Ataque1, Fuente, Brushes::WhiteSmoke, Cordx - 105, Cordy + 05);
	misFondos.MostrarPNG(miBuffer->Graphics, PNGS::BotonA, 28, 355, 64, 64, 64, 64);
	miBuffer->Graphics->DrawString(Ataque2, Fuente, Brushes::WhiteSmoke, Cordx + 155, Cordy + 05);
	misFondos.MostrarPNG(miBuffer->Graphics, PNGS::BotonS, 288, 355, 64, 64, 64, 64);
	miBuffer->Graphics->DrawString(Ataque3, Fuente, Brushes::WhiteSmoke, Cordx - 105, Cordy + 65);
	misFondos.MostrarPNG(miBuffer->Graphics, PNGS::BotonZ, 28, 425, 64, 64, 64, 64);
	miBuffer->Graphics->DrawString(Ataque4, Fuente, Brushes::WhiteSmoke, Cordx + 155, Cordy + 65);
	misFondos.MostrarPNG(miBuffer->Graphics, PNGS::BotonX, 288, 425, 64, 64, 64, 64);

}

void EscribirLinea(BufferedGraphics^ miBuffer, Graphics^ miGraphic, String^ MensajeInicial, int Posicion, bool DibujarCuadroTexto, int Retraso=20)
{
	
	if (DibujarCuadroTexto)
		misFondos.MostrarPNG(miBuffer->Graphics, PNGS::CuadroDialogo, 0, 336, 720, 144, 720, 144);

	char* Auxiliar;
	int contEspacios = 0;
	int TamanioLetra;
	int dx;
	int CordIncioX;
	int CordInicioY;

	Auxiliar = (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(MensajeInicial).ToPointer();
	
	for (int i = 0; i < (sizeof(Auxiliar) / sizeof(Auxiliar[0])); i++)
		if (Auxiliar[i] == ' ')
			contEspacios++;

	if (MensajeInicial->Length <= 39)
	{
		TamanioLetra = 27; 
		CordIncioX = (682 - (MensajeInicial->Length)*16 - 5*contEspacios) / 2;
		dx = 5;
	}
	else
	{
		TamanioLetra = 24;
		CordIncioX = (682 - (MensajeInicial->Length) * 13 - 4 * contEspacios) / 2;
		dx = 4;
	}


	Font^ Fuente = gcnew Font("Lucida Console", TamanioLetra, FontStyle::Bold, GraphicsUnit::Pixel);
	String^ CaracterAPintar;

	switch (Posicion)
	{
	case 1:
		CordInicioY = 380;
		break;
	case 2:
		CordInicioY = 403;
		break;
	case 3:
		CordInicioY = 425;
		break;
	}
	
	char* Auxiliar2;
	Auxiliar2 = new char[1];
	char Auxiliar3;


	for (int i = 1; i <= MensajeInicial->Length; i++)
	{
		Auxiliar3 = Auxiliar[i - 1];
	
		Auxiliar2 = &Auxiliar3;
			 if (strcmp(Auxiliar2, "áÿÿÿ") == 0)
			CaracterAPintar = gcnew String("á");
		else if (strcmp(Auxiliar2, "éÿÿÿ") == 0)
			CaracterAPintar = gcnew String("é");
		else if (strcmp(Auxiliar2, "íÿÿÿ") == 0)
			CaracterAPintar = gcnew String("í");
		else if (strcmp(Auxiliar2, "óÿÿÿ") == 0)
			CaracterAPintar = gcnew String("ó");
		else if (strcmp(Auxiliar2, "úÿÿÿ") == 0)
			CaracterAPintar = gcnew String("ú");
		else if (strcmp(Auxiliar2, "Áÿÿÿ") == 0)
			CaracterAPintar = gcnew String("Á");
		else if (strcmp(Auxiliar2, "Éÿÿÿ") == 0)
			CaracterAPintar = gcnew String("É");
		else if (strcmp(Auxiliar2, "Íÿÿÿ") == 0)
			CaracterAPintar = gcnew String("Í");
		else if (strcmp(Auxiliar2, "Óÿÿÿ") == 0)
			CaracterAPintar = gcnew String("Ó");
		else if (strcmp(Auxiliar2, "Úÿÿÿ") == 0)
			CaracterAPintar = gcnew String("Ú");
		else if (strcmp(Auxiliar2, "ñÿÿÿ") == 0)
			CaracterAPintar = gcnew String("ñ");
		else if (strcmp(Auxiliar2, "Ñÿÿÿ") == 0)
			CaracterAPintar = gcnew String("Ñ");
		else 
			CaracterAPintar = gcnew String(Auxiliar2);

		if (Auxiliar[i - 1] == ' ') CordIncioX = CordIncioX + dx;


		miBuffer->Graphics->DrawString(CaracterAPintar, Fuente, gcnew SolidBrush(Color::DodgerBlue), CordIncioX + 2, CordInicioY + 2);
		miBuffer->Graphics->DrawString(CaracterAPintar, Fuente, gcnew SolidBrush(Color::White), CordIncioX, CordInicioY);
		
		CordIncioX = CordIncioX + (TamanioLetra*15/27);
		miBuffer->Render(miGraphic);
		Threading::Thread::Sleep(Retraso);
	}

	System::Runtime::InteropServices::Marshal::FreeHGlobal((IntPtr)Auxiliar);
}

void DibujarLetreroPokemon(Graphics^ miGraphic, Pokemon* ElPokemon, int Numero)
{
	switch (Numero)
	{
	case 1:
		ElPokemon->DibujarPokemon(miGraphic, 6, 60, 80, 80);
		misFondos.MostrarPNG(miGraphic, PNGS::Boton1, 92, 60, 100, 100, 100, 100);
		break;
	case 2:
		ElPokemon->DibujarPokemon(miGraphic, 6, 200, 80, 80);
		misFondos.MostrarPNG(miGraphic, PNGS::Boton2, 92, 200, 100, 100, 100, 100);
		break;
	case 3:
		ElPokemon->DibujarPokemon(miGraphic, 6, 340, 80, 80);
		misFondos.MostrarPNG(miGraphic, PNGS::Boton3, 92, 340, 100, 100, 100, 100);
		break;
	case 4:
		ElPokemon->DibujarPokemon(miGraphic, 634, 60, 80, 80);
		misFondos.MostrarPNG(miGraphic, PNGS::Boton4, 528, 60, 100, 100, 100, 100);
		break;
	case 5:
		ElPokemon->DibujarPokemon(miGraphic, 634, 200, 80, 80);
		misFondos.MostrarPNG(miGraphic, PNGS::Boton5, 528, 200, 100, 100, 100, 100);
		break;
	case 6:
		ElPokemon->DibujarPokemon(miGraphic, 634, 340, 80, 80);
		misFondos.MostrarPNG(miGraphic, PNGS::Boton6, 528, 340, 100, 100, 100, 100);
		break;

	}

}

void InterfazEscogeTuPokemon(Graphics^ miGraphic, ArregloPokemon* EquipoPokemon)
{
	misFondos.MostrarFondo(miGraphic, Fondos::ChoosePokemones);
	int Contador = 0;

	for (int i = 0; i < EquipoPokemon->getTamanioDelArreglo(); i++)
	{
		if (EquipoPokemon->RetornaPokemon(i)->getVida() > 0)
		{
			Contador++;
			DibujarLetreroPokemon(miGraphic, EquipoPokemon->RetornaPokemon(i), Contador);
		}
		if (Contador == 6)
			break;
	}

}

