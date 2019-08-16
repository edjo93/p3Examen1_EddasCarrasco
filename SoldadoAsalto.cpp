#ifndef SOLDADOASALTO_CPP
#define SOLDADOASALTO_CPP
	#include"Soldado.cpp"
	class SoldadoAsalto:public Soldado{
		private:
			int velocidad;
			int fuerza_extra;
		public:
			
			 int getVelocidad() {
		        return velocidad;
		    }
		
		     void setVelocidad(int velocidad) {
		        this->velocidad = velocidad;
		    }
		
		     int getFuerza_extra() {
		        return fuerza_extra;
		    }
		
		     void setFuerza_extra(int fuerzaExtra) {
		        this->fuerza_extra = fuerza_extra;
		    }
		    
			virtual int atacarSoldadoAsalto(){
				return puntos_fuerza*10;
			}
			//puntos de fuerza * (10 + (velocidad * 2))
			virtual int atacarSoldadoSoporte(){
				return puntos_fuerza*(10+(velocidad*2));
			}
			virtual void defenderSoldadoAsalto(int ataque){
				puntos_vida-=ataque;
			}
		    virtual void defenderSoldadoSoporte(int ataque){
		    	puntos_vida-=(ataque/fuerza_extra);
			}
	};
#endif
