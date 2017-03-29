#include <iostream>
#include <math.h>
using namespace std;


float Sp_ob(S_ob,r_s,RIP,Z){
	float St_ob;
	for (int i=1;i<=meses;i++){
		Z+=pow((1+r_s),i);
	}
	St_ob= S_ob * pow((1+r_s),meses) + 0.1 * RIP * Z
	return  St_ob;
}
float Sp_v(S_v,r_s,meses){
	float St_v;
	St_v=S_v* pow((1+r_s),meses);
	return St_v;
}

float ST(St_ob,S_ob,r_s,RIP,Z,S_v,meses,...){
	float St_ob,St_v;
	
}



int main() {
	float ST,S_ob,r_s,RIP,Z=0,S_v;
	int meses;
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
	
	ST= Sp_ob(S_ob,r_s,RIP,Z) + Sp_v(S_v,r_s,meses); // colocar en una funcion ? R: no, no es necesario
	
	// else hace esto de aca
	
	
	cout<< ST; // saldo total ahorrado en la afp al momento de jubilar.
	// ver cuaderno
	
	//Actualizacion : 28/03- 0.44 hrs
	
	
	
		
	
	return 0;
}
