#include <iostream>
#include <math.h>
using namespace std;

//obs: FALTA LA RENTABILDAD
// TRATAR QUE SEA EFICIENTE.
//ORDENAR LOS CIN
float r_S(){	//rentabilidad

}

// se establece que la esperanza de vida de los chilenos es : 80.5 años<- hombres | 83.5 <- mujeres.
//segun comentario de internet Afp usan  90	

float FA(S_ob,r_s,RIP,Z,meses){ // dinero obtenido con las cotizaciones obligatorias 
								//Sp_ob .formula A .. sacar el parametro r_s, debe ingresar como funcion
	float St_ob;
	for (int i=1;i<=meses;i++){
		Z+=pow((1+r_s),i);
	}
	St_ob= S_ob * pow((1+r_s),meses) + 0.1 * RIP * Z;
	return  St_ob;
}
float FB(S_v,r_s,meses){ // formula B // Dinero obtenido por la APV
	float St_v;
	St_v=S_v* pow((1+r_s),meses);
	return St_v;
}

float F1(S_ob,r_s,RIP,Z,S_v,meses,CAPV){ // total de dinero al jubilarse Formula 1 // se cambio el nombre de las funciones
 		float S_T,Z1=0;
 		//Z1 sumatoria q acompaña a  CAPV
 		for (int i =1;i<=meses;i++){
 			Z1+=pow((1+r_s),i);
		 }
 	// de la formula del informe, se asume d = , BR=0.
 		S_T= (FA(S_ob,r_s,RIP,Z,meses) + FB(S_v,r_s,meses))+CAPV*Z1;
 		
		 return S_T;
		 //return (S_T)/mesesvida; // da la mensualidad de la jubilacion
 			
}
float F2(S_ob,r_s,RIP,Z,S_v,meses,Jd,mv){ //dinero que se debe adicionar a la APV
											// colocar mv como funcion.
 	float Z2=0;
 	//float APVad; // dinero q se debe adicionar a la apv. cambio a CAPV
 	for(int i=0;i<=meses;i++){
 		Z2+=pow((1+r_s),i);
 	}
 	CAPV= (mv*Jd-FA(S_ob,r_s,RIP,Z,meses)-FB(S_v,r_s,meses))/(Z2);

 	return CAPV;
}
int MV(edad,sexo){
	if (sexo =='H'){
		mv =(80.5-edad)*12;
	}else{
		mv=(83.5-edad)*12;
	}
	return mv;
}


int main() {
	int op=0;
	float S_ob,r_s,RIP,Z=0,S_v,mv; // mv= meses de vida.
	int Jd;// jubilacion deseada
	int meses,CAPV;
	int edad;
	char sexo;// H hombre, M mujer
	// ST = saldo total de la AFP
	//St_ob dinero obtenido por la cotizacion obligaroria
	// S_ob dinero ahorrado por la cotizacion obligatoria
	// r_s rentabilidad real
	//RIP sueldo imponible promedio (de donde se descuenta el 10%)
	// Z sumatoria de la formula
	// S_v dinero ahorrado en la APV
	// meses restantes para jubilarse
	
	//cout de los cin :v
	cin>>op>>edad>>sexo;
	cin>>Jd;
	cin>>S_ob>>r_s>>RIP>>meses;

	float mv=MV(edad,sexo)
	//cout<<Sp_ob(S_ob,r_s,RIP,Z);// formula A ?
	//cout<<Sp_v(S_v,r_s,meses);// formula B 
	
	
	if (op==1){
		cout<< F1(S_ob,r_s,RIP,Z,S_v,meses,CAPV)/ mv; // saldo total ahorrado en la afp al momento de jubilar.
		//falta dividir por los meses de vida-- listo.
	}else{
		cout<<F2(S_ob,r_s,RIP,Z,S_v,meses,Jd,mv);
	}
	
	
	
	// ver cuaderno
	
	//Actualizacion : 28/03- 12.44 hrs
	
	
	
		
	
	return 0;
}
