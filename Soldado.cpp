#ifndef SOLDADO_CPP
#define SOLDADO_CPP
	#include<string>
	using namespace std;
	class Soldado{
		protected:
			string nombre;
			int puntos_vida;
			int puntos_fuerza;
		public:
			
			 void setNombre(string nombre) {
		        this->nombre = nombre;
		    }
		    string getNombre(){
		    	return nombre;
			}
		
		     int getPuntos_vida() {
		        return puntos_vida;
		    }
		
		     void setPuntos_vida(int puntos_vida) {
		        this->puntos_vida = puntos_vida;
		    }
		
		     int getPuntos_fuerza() {
		        return puntos_fuerza;
		    }
		
		     void setPuntos_fuerza(int puntos_fuerza) {
		        this->puntos_fuerza = puntos_fuerza;
		    }
		    virtual int atacarSoldadoAsalto()=0;
		    virtual int atacarSoldadoSoporte()=0;
		    virtual void defenderSoldadoAsalto(int)=0;
		    virtual void defenderSoldadoSoporte(int)=0;
		    	
			
			
			
	};
#endif
