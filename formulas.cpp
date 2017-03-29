#include <iostream>
#include <math.h>
using namespace std;


//hacer una funcion sobre el promedio de vida de las personas y de rentabilidad real


float Sp_ob(S_ob,r_s,RIP,Z,meses){ // formula A .. sacar el parametro r_s, debe ingresar como funcion
	float St_ob;
	for (int i=1;i<=meses;i++){
		Z+=pow((1+r_s),i);
	}
	St_ob= S_ob * pow((1+r_s),meses) + 0.1 * RIP * Z;
	return  St_ob;
}
float Sp_v(S_v,r_s,meses){ // formula B
	float St_v;
	St_v=S_v* pow((1+r_s),meses);
	return St_v;
}

float ST(S_ob,r_s,RIP,Z,S_v,meses,CAPV){ // Formula 1
 		float S_T,Z1=0;
 		//Z1 sumatoria q acompaña a  CAPV
 		for (int i =1;i<=meses;i++){
 			Z1+=pow((1+r_s),i);
		 }
 	// de la formula del informe, se asume d = , BR=0.
 		S_T= (Sp_ob(S_ob,r_s,RIP,Z,meses) + Sp_v(S_v,r_s,meses))+CAPV*Z1;
 		
		 return S_T;
		 //return (S_T)/mesesvida; // da la mensualidad de la jubilacion
 			
}



int main() {
	float S_ob,r_s,RIP,Z=0,S_v;
	int meses,CAPV;
	// ST = saldo total de la AFP
	//St_ob dinero obtenido por la cotizacion obligaroria
	// S_ob dinero ahorrado por la cotizacion obligatoria
	// r_s rentabilidad real
	//RIP sueldo imponible promedio (de donde se descuenta el 10%)
	// Z sumatoria de la formula
	// S_v dinero ahorrado en la APV
	// meses restantes para jubilarse
	
	//cout de los cin :v
	
	cin>>S_ob>>r_s>>RIP>>meses;
	
	//cout<<Sp_ob(S_ob,r_s,RIP,Z);// formula A ?
	//cout<<Sp_v(S_v,r_s,meses);// formula B 
	
	// if opcion 1 -> hace lo q esta abajo
	
	
	// else hace esto de aca
	
	
	cout<< ST(S_ob,r_s,RIP,Z,S_v,meses,CAPV); // saldo total ahorrado en la afp al momento de jubilar.
	// ver cuaderno
	
	//Actualizacion : 28/03- 10.23 hrs
	
	
	
		
	
	return 0;
}
