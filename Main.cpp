#include"SoldadoAsalto.cpp"
#include"SoldadoSoporte.cpp"
#include<iostream>
#include<vector>
#include<fstream>
#include<string.h>
#include<typeinfo>
#include<sstream>
#include<cstdlib>
#include<ctime>
using namespace std;
string token(string , string , int );
void agregar();
int main(){
	srand(time(NULL));
	//cargar archivo
	//2 vectores de soldado
	vector<Soldado*>batallon1;
	vector<Soldado*>batallon2;
	//leer
	int number;
	stringstream convert;
	fstream leer;
	string linea;
	leer.open("./initfile.txt");
	bool equipo = false;
	if(leer.is_open()){//si el archivo esta abierto se lee
		while(!leer.eof()){//leer todo el archivo
			getline(leer,linea,'/');
			if(linea=="&"){
				equipo = !equipo;
			}else if(equipo){
				//se llenara el batallon 2
				if(linea=="Soporte"){
					SoldadoSoporte*soldado=new SoldadoSoporte();
					getline(leer,linea,'/');
					soldado->setNombre(linea);
					getline(leer,linea,'/');
					convert<<linea;
					convert>>number;
					soldado->setPuntos_vida(number);
					getline(leer,linea,'/');
					convert<<linea;
					convert>>number;
					soldado->setPuntos_fuerza(number);
					getline(leer,linea,'/');
					convert<<linea;
					convert>>number;
					soldado->setBlindaje(number);
					getline(leer,linea,'/');
					convert<<linea;
					convert>>number;
					soldado->setCamuflaje(number);
					batallon2.push_back(soldado);
				}else{
					SoldadoAsalto*soldado=new SoldadoAsalto();
					getline(leer,linea,'/');
					soldado->setNombre(linea);
					getline(leer,linea,'/');
					convert<<linea;
					convert>>number;
					soldado->setPuntos_vida(number);
					getline(leer,linea,'/');
					convert<<linea;
					convert>>number;
					soldado->setPuntos_fuerza(number);
					getline(leer,linea,'/');
					convert<<linea;
					convert>>number;
					soldado->setVelocidad(number);
					getline(leer,linea,'/');
					convert<<linea;
					convert>>number;
					soldado->setFuerza_extra(number);
					batallon2.push_back(soldado);	
				}
				
			}else{
				
				//se llena el primer batallon
				if(linea=="Soporte"){
					SoldadoSoporte*soldado=new SoldadoSoporte();
					getline(leer,linea,'/');
					soldado->setNombre(linea);
					getline(leer,linea,'/');
					convert<<linea;
					convert>>number;
					soldado->setPuntos_vida(number);
					getline(leer,linea,'/');
					convert<<linea;
					convert>>number;
					soldado->setPuntos_fuerza(number);
					getline(leer,linea,'/');
					convert<<linea;
					convert>>number;
					soldado->setBlindaje(number);
					getline(leer,linea,'/');
					convert<<linea;
					convert>>number;
					soldado->setCamuflaje(number);
					batallon1.push_back(soldado);
				}else{
					SoldadoAsalto*soldado=new SoldadoAsalto();
					getline(leer,linea,'/');
					soldado->setNombre(linea);
					getline(leer,linea,'/');
					convert<<linea;
					convert>>number;
					soldado->setPuntos_vida(number);
					getline(leer,linea,'/');
					convert<<linea;
					convert>>number;
					soldado->setPuntos_fuerza(number);
					getline(leer,linea,'/');
					convert<<linea;
					convert>>number;
					soldado->setVelocidad(number);
					getline(leer,linea,'/');
					convert<<linea;
					convert>>number;
					soldado->setFuerza_extra(number);
					batallon1.push_back(soldado);	
				}
			}
			
			
		}
	}else{
		cout<<"\nno se pudo abrir el archivo\n";
	}
	
	leer.close();
	
	
	char opcion;
	do{
		cout<<"\n1-imprimir soldados\n2-iniciar la simulacion(falto validacion para borrar los soldados)\ns-salir\n?:";
		cin>>opcion;
		switch(opcion){
			case'1':
				//print
				cout<<"batallon1"<<endl<<endl;;
				for(int i=0;i<batallon1.size();i++){
					cout<<batallon1.at(i)->getNombre();
					cout<<endl;
					
				}
				cout<<"batallon2"<<endl<<endl
				;
				for(int i=0;i<batallon2.size();i++){
					
					cout<<batallon2.at(i)->getNombre();
					cout<<endl;
				}
				
				break;
			case'2':
				{	
					int jugador1;
					int jugador2;
					do{
						//iniciar simulacion
						//seleccionar jugador del equipo //este ataca
						jugador1=0+rand()%(batallon1.size()-1);
						//seleccionar jugador del equipo que defiende 
						jugador2=0+rand()%(batallon2.size()-1);	
						if(typeid(*batallon1[jugador1])==typeid(SoldadoAsalto)){
							//soldado de asalto para el primer jugador
							if(typeid(*batallon2[jugador2])==typeid(SoldadoAsalto)){
								//soldado de asalto para el segundo jugador
								batallon2[jugador2]->defenderSoldadoAsalto(batallon1[jugador1]->atacarSoldadoAsalto());
							}else{
								//soldado de soporte para el segundo jugador
								batallon2[jugador2]->defenderSoldadoAsalto(batallon1[jugador1]->atacarSoldadoSoporte());
							}
						}else{
							//soldado de soporte para el primer jugador
							if(typeid(*batallon2[jugador2])==typeid(SoldadoAsalto)){
								//soldado de asalto para el segundo jugador
								batallon2[jugador2]->defenderSoldadoSoporte(batallon1[jugador1]->atacarSoldadoAsalto());
							}else{
								//soldado de soporte para el segundo jugador
								batallon2[jugador2]->defenderSoldadoSoporte(batallon1[jugador1]->atacarSoldadoSoporte());
							}
						}
						jugador1=0+rand()%(batallon1.size()-1);
						//seleccionar jugador del equipo que defiende 
						jugador2=0+rand()%(batallon2.size()-1);	
						
						//jugador 2 ataca
						if(typeid(*batallon2[jugador2])==typeid(SoldadoAsalto)){
							//soldado de asalto para el segundo jugador
							if(typeid(*batallon1[jugador1])==typeid(SoldadoAsalto)){
								//soldado de asalto para el primer jugador
								batallon1[jugador1]->defenderSoldadoAsalto(batallon2[jugador2]->atacarSoldadoAsalto());
							}else{
								//soldado de soporte para el primer jugador
								batallon1[jugador1]->defenderSoldadoAsalto(batallon2[jugador2]->atacarSoldadoSoporte());
							}
						}else{
							//soldado de soporte para el segundo jugador
							if(typeid(*batallon2[jugador2])==typeid(SoldadoAsalto)){
								//soldado de asalto para el primer jugador
								batallon1[jugador1]->defenderSoldadoSoporte(batallon2[jugador2]->atacarSoldadoAsalto());
							}else{
								//soldado de soporte para el primer jugador
								batallon1[jugador1]->defenderSoldadoSoporte(batallon2[jugador2]->atacarSoldadoSoporte());
							}
						}
						
						
					}while(batallon1.size()>0&&batallon2.size()>0);
					
					
				}
				
				break;
			case's':
				
				break;
			default:
				cout<<"\nno ha seleccionado una opcion correcta\n";
				
				
		}
	}while(opcion!='s');
	
	return 0;
}

void revisar_vida(){
	
}
