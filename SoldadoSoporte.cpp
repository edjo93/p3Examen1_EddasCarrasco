#ifndef SOLDADOSOPORTE_CPP
#define SOLDADOSOPORTE_CPP
	#include"Soldado.cpp"
	class SoldadoSoporte:public Soldado{
		private:
			int blindaje;
			int camuflaje;
		public:
			
			 int getBlindaje() {
		        return blindaje;
		    }
		
		     void setBlindaje(int blindaje) {
		        this->blindaje = blindaje;
		    }
		
		     int getCamuflaje() {
		        return camuflaje;
		    }
		
		     void setCamuflaje(int camuflaje) {
		        this->camuflaje = camuflaje;
		    }	
		    //puntos de fuerza * (15 + camuflaje)
		    virtual int atacarSoldadoAsalto(){
				return puntos_fuerza*(15+camuflaje);
			}
			//puntos de fuerza * (10)
			virtual int atacarSoldadoSoporte(){
				return puntos_fuerza*10;
			}
			virtual void defenderSoldadoAsalto(int ataque){
				puntos_vida-=(ataque/(blindaje*2));
			}
		    virtual void defenderSoldadoSoporte(int ataque){
		    	puntos_vida-=ataque;
			}
			
	};
#endif
