#include<iostream>

using namespace std;

struct Nodo{
	 string cod;
    Nodo *siguiente;
};

void agregarCaja(Nodo *&,string);
void sacarCaja(Nodo *&,string &);
int numCajas(int);
int CantidadCajas(int);
int main()
{
	Nodo *pila = NULL;
	
    string cod;  
	int cajas=0;	
	int cajasDespachadas=0;	
	 
    cout<<"Ingrese cantidad de cajas a registrar: " <<endl;
	cin>>cajas;
	
	int espaciosDisponibles=cajas;
	
    	for(int x=0;x<cajas;x++){
    	numCajas(espaciosDisponibles);
    	
        cout<<"Ingrese codigo de caja: "; cin>>cod;        
        agregarCaja(pila,cod);     
        espaciosDisponibles--;
        cajasDespachadas++;
    }

    cout<<"Sacando cajas: ";
    while(pila!=NULL){
        sacarCaja(pila,cod);
        if(pila!=NULL){
            cout<<cod<<" - ";
        }
        else{
             cout<<cod<<" . ";
        }      
    } 
	 cout<<"\n";CantidadCajas(cajasDespachadas);  
    return 0;
}

void agregarCaja(Nodo *&lista,string n){
 Nodo *nuevo_nodo = new Nodo();
 nuevo_nodo->cod=n;
 nuevo_nodo->siguiente = lista;
 lista=nuevo_nodo;
 cout<<"\nElmento "<<"'"<<n<<"'"<<" Agregado correctamente"<<endl<<endl;
}

void sacarCaja(Nodo *&lista,string &n){
 Nodo *aux=lista;
 n=aux->cod;
 lista=aux->siguiente;
 delete aux;
}

int numCajas(int n){
	int cont =n;
	cout<<"Espacios disponibles: "<<cont<<endl;
	return n;
}

int CantidadCajas(int n){
	int cont =n;
	cout<<"Total de Cajas Despachadas: "<<cont<<endl;
}

