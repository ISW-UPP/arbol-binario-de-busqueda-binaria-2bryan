#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;


struct Nodo {
	int dato;
	Nodo* der;
	Nodo* izq;
	Nodo* padre;
};


//Prototipos
void menu();
void intercambiar(int&, int&);
void arreglo();
Nodo* crearNodo(int, Nodo*);
void insertarNodo(Nodo*&, int, Nodo*);
void mostrarArbol(Nodo*, int);
//bool buscar(   );


Nodo* arbol = NULL;

int main()
{
	
	menu();
	
	return 0;

}

void menu() {
	int  dato, opcion, contador = 0;

	do {
		 system("cls");
		cout << "\n MENU" << endl;
		cout << "1. Insertar un nuevo nodo" << endl;
		cout << "2. Mostrar el arbol" << endl;
		cout << "3. Buscar elemento" << endl;
		cout << "4. SALIR" << endl;
		cout << "Elige una opcion: " << endl;
		cin >> opcion;

		switch (opcion)
		{
		case 1: 
			int tamano;
			int a[30];
			cout <<  "Ingrese el tamano del arbol: ";
			cin >> tamano;
			for(int i=0; i< tamano;i++)
			{
				cout << "\n Ingrese el nodo "<< i+1 << ": ";
				cin >> a[i];
				insertarNodo(arbol, a[i], NULL);
			}

			cout << "\n";
			system("pause");
			break;

		case 2:  cout << "\n Mostrar arbol:\n\n" << endl;
			mostrarArbol(arbol, contador);
			cout << "\n";
			system("pause");
			break;		
		case 3:
			int n, i, num, primero, ultimo, medio;

		    cout<<"Ingrese el numero que desea buscar: ";
		    cin>>num;

		    primero=0;
		    ultimo=tamano-1;
		    medio=(primero+ultimo)/2;
		    while (primero<=ultimo)
		    {
		        if (a[medio]< num)
		        {
		            primero=medio+1;
		        } else if (a[medio]== num) 
		        {
		            cout<<" Se encontro en la posicion: ";
		            cout<<medio+1<<endl;
		            break;
		        }
		        else {
		            ultimo = medio - 1;
		        }
		
		        medio = (primero+ultimo)/2;
		    }
		    if (primero>ultimo)
		    {
		        cout<<"  "<<num<<" no se encontro\n";
		    }
		system("pause");
		break;
		}
	} while (opcion != 4);
	
}	
//Funcion para crear un nuevo nodo
Nodo* crearNodo(int n, Nodo* padre)
{
	Nodo* nuevo_nodo = new Nodo();

	nuevo_nodo->dato = n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	nuevo_nodo->padre = padre;

	return nuevo_nodo;
}
//Funcion para insertar elementos en el arbol
void insertarNodo(Nodo*& arbol, int n, Nodo* padre)
{
	if (arbol == NULL) //Esta vacio
	{
		Nodo* nuevo_nodo = crearNodo(n, padre);
		arbol = nuevo_nodo;
	}
	else
	{
		int valorRaiz = arbol->dato;
		if (n < valorRaiz) //Si el elemento es menor a la raiz, insertamos izq
		{
			insertarNodo(arbol->izq, n, arbol);
		}
		else
		{
			insertarNodo(arbol->der, n, arbol); //Si el elemento es menor a la raiz, insertamos der
		}

	}
}
//Funcion para mostrar el arbol completo
void mostrarArbol(Nodo* arbol, int cont)
{
	if (arbol == NULL) //Si el arbol esta vacio
	{
		return;
	
	}
	else
	{
		mostrarArbol(arbol->der, cont + 1);
		for (int i = 0; i < cont; i++)
		{
			cout << " ";
		}
		cout << arbol->dato << endl;
		mostrarArbol(arbol->izq, cont + 1);
	}
}

void intercambiar(int &a, int &b)
{
  int tmp = b;
  b = a;
  a = tmp;
}





