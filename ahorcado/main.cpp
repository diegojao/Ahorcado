#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <chrono>
#include <thread>
using namespace std;
void LimpiarPantalla(){
    system("cls");
}
void config();
void jugarPC();
void JuegoUs();
char eleccion;
string palabrasES[10];
string palabrasEN[10];
string palabra, fallidas;
bool completo, correcta;
int vida;
int nA;
int idioma;
int main()
{
        while (true)
        {
                vida = 6;
                cout << ": : : Menu : : :" <<endl;
                cout << "1) configurar juego/configure game" <<endl;
                cout << "2) jugar con computadora/play with the computer" <<endl;
                cout << "3) jugar con usuario/play with the user" <<endl;
                cout << "4) salir/exit" <<endl;
                cout << "Eleccion:/Choice: "<<endl;
                cin >> eleccion;

                switch(eleccion)
                {
                    case '1':
                        config();
                        break;
                    case '2':
                        jugarPC();
                        break;
                    case '3':
                        JuegoUs();
                        break;
                    case '4':
                        return 0;
                        break;
                }
        }
}
void jugarPC()
{
    cout << "Eliga el idioma:/Choose the language: "<<endl;
    cout << "1. English " <<endl;
    cout << "2. Español " <<endl;
    cin >> idioma;

    srand((int)time(NULL));
    nA = rand()%10;

 if (idioma == 1)
    {
        for(int i = 0; i < (int)palabrasEN[nA].size(); i++)
        {
            palabra += "_";
        }
           while(vida >= 0)
    {
        LimpiarPantalla();
        cout << "\t: : : A H O R C A D O : : : "<<endl;

        cout<<"Fails:"<<fallidas;
        cout<<"  Progress: "<<palabra<<endl;
		cout<<"Enter a letter: ";
		cin>>eleccion;

		correcta = false;
		for(int i = 0; i < (int)palabrasEN[nA].size(); i++)
		{
			if(palabrasEN[nA][i] == eleccion)
                {
				palabra[i] = eleccion;
				correcta = true;
			}
        }
        if(!correcta){
			vida--;
			fallidas += eleccion;
		}
		completo = true;
		for(int i = 0; i < (int)palabra.size(); i++){
			if(palabra[i] == '-'){
				completo = false;
    }
    if(completo){
			LimpiarPantalla();
			cout<<"\t::: A H O R C A D O :::"<<endl;

			cout<<"Word: "<<palabrasEN[nA]<<endl;
			cout<<"You Win. Enter a letter to continue: ";
			cin>>eleccion;
			return;
		}
}
    }
     if (idioma == 2)
    {
            for(int i = 0; i < (int)palabrasES[nA].size(); i++)
            {
                palabra += "_";
            }
              while(vida >= 0)
    {
        LimpiarPantalla();
        cout << "\t: : : A H O R C A D O : : : "<<endl;

        cout<<"Fallos: "<<fallidas;
        cout<<"  Progreso: "<<palabra<<endl;
		cout<<"Ingrese una letra: ";
		cin>>eleccion;

		correcta = false;
		for(int i = 0; i < (int)palabrasES[nA].size(); i++)
		{
			if(palabrasES[nA][i] == eleccion)
                {
				palabra[i] = eleccion;
				correcta = true;
			}
        }
        if(!correcta){
			vida--;
			fallidas += eleccion;
		}

		completo = true;
		for(int i = 0; i < (int)palabra.size(); i++){
			if(palabra[i] == '-'){
				completo = false;
    }
    if(completo){
			LimpiarPantalla();
			cout<<"\t::: A H O R C A D O :::"<<endl;

			cout<<"Palabra: "<<palabrasES[nA]<<endl;
			cout<<"Ganaste, Ingresa una letra para continuar: ";
			cin>>eleccion;
			return;
                        }
                    }
                }
            }
        }
    }

void JuegoUs()
{
    int a;
    cout<<"Seleccione el idioma: "<<endl;
    cout<<" 1. Ingles "<<endl;
    cout<<" 2. Español  "<<endl;
    cin>>a;

    if(a==1)
    {
        string p1, p2, palabra2;
     cout<<"Name of the first person"<<endl;
     cin>>p1;
     cout<<"Name of the second person"<<endl;
     cin>>p2;
     cout<<"Write the word to guess"<<endl;
     cin>>palabra2;
     string guion(palabra2.size(), '_'); //"guion" de las letras no adivinadas
     int fails = 0;
     while (fails < 7 && guion != palabra2) {
          char letra;
          cout << "Guess a letter: ";
          cin >> letra;
          bool letra_encontrada = false;
          for (int i = 0; i < palabra2.size(); i++) {
             if (palabra2[i] == letra) {
                 guion[i] = letra;
                 letra_encontrada = true;
          }}
          if (!letra_encontrada) {
              fails++;

          }cout << guion << endl;
        }if (fails == 7) {
            cout << "You lost! The word was: " << palabra2 << endl;
            cout<<""<<endl;
        } else {
            cout << "You win!" << endl;
            cout<<""<<endl;
        }
    }

    else if(a==2)
    {
        string p1, p2, palabra2;
cout<<"Ingrese el nombre de la persona 1"<<endl;
cin>>p1;
cout<<"Ingrese el nombre de la persona 2"<<endl;
cin>>p2;
cout<<"Escriba la palabra del juego"<<endl;
cin>>palabra2;
string guion(palabra2.size(), '_'); //"guion" de las letras no adivinadas
int fails = 0;
while (fails < 7 && guion != palabra2) {
    char letra;
    cout << "Adivine una letra: ";
    cin >> letra;
    bool letra_encontrada = false;
    for (int i = 0; i < palabra2.size(); i++){
       if (palabra2[i] == letra) {
           guion[i] = letra;
           letra_encontrada = true;
       }}if(!letra_encontrada) {
            fails++;

         }cout << guion << endl;
         std::this_thread::sleep_for(std::chrono::milliseconds(1500));
         LimpiarPantalla();
    }if (fails == 7) {
       cout << "Perdiste! La palabra era: " << palabra2 << endl;
    }else {
        cout << "Ganaste!" << endl;
     }
    }
    }


void config()
{
    cout<<"Ingresar las 10 palabras en español/Enter the 10 words in Spanish"<<endl;
    for (int i = 0; i <10; i++){
    cin>>palabrasES[i];}
    cout<<"Ingresar las 10 palabras en ingles/Enter the 10 words in English"<<endl;
    for (int i = 0; i <10; i++){
    cin>>palabrasEN[i];}
    cout<<"La lista de palabras en espanol es:/The list of words in Spanish is: " << endl;
    for (int i = 0; i < 10; i++) {
        cout << palabrasES[i] << " ";}
        cout<<endl;
    cout<<"La lista de palabras en ingles es:/The list of words in English is: " << endl;
    for (int i = 0; i < 10; i++) {
        cout << palabrasEN[i] << " ";}
    cout<<endl;
    cout<<endl;
}
