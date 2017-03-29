#include <iostream>
#include <math.h>
using namespace std;

//La rentabilidad mensual es 0.4%.
//este valor se obtuvo al promediar la rentabilidad promedio de todas las afps de los fondos B,C,D y E


// se establece que la esperanza de vida de los chilenos es : 80.5 años<- hombres | 83.5 <- mujeres.
	

float FA(S_ob,r_s,RIP,Z,meses){ //formula A  //dinero obtenido con las cotizaciones obligatorias 
	
	float St_ob; //St_ob dinero obtenido por la cotizacion obligaroria
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
float F1(S_ob,r_s,RIP,Z,S_v,meses,CAPV){ // total de dinero al jubilarse Formula 1
 	float S_T; // ST = saldo total de la AFP
	float Z1=0; //Z1 sumatoria q acompaña a  CAPV
	
 	for (int i =1;i<=meses;i++){
 		Z1+=pow((1+r_s),i);
	}
 	// de la formula del informe, se asume d =1 , BR=0.
 	S_T= (FA(S_ob,r_s,RIP,Z,meses) + FB(S_v,r_s,meses))+CAPV*Z1;
 		
	return S_T; 		 			
}
float F2(S_ob,r_s,RIP,Z,S_v,meses,Jd,mv){ //dinero que se debe adicionar a la APV
											
 	float Z2=0;//sumatoria que se utiliza en la F2. (colcoar en el informe!)
 	float CAPV; // dinero q se debe adicionar a la apv. 
 	for(int i=0;i<=meses;i++){
 		Z2+=pow((1+r_s),i);
 	}
 	CAPV= (mv*Jd-FA(S_ob,r_s,RIP,Z,meses)-FB(S_v,r_s,meses))/(Z2);

 	return CAPV;
}
int MV(edad,sexo){
	int mv; 
	if (sexo =='H'){
		mv =(80.5-edad)*12;
	}else{
		mv=(83.5-edad)*12;
	}
	return mv;
}
int meses1(edad){// retorna la cantidad de meses que faltan para que el usuario se jubile.
	int m;
	if (sexo =='H'){
		m =(65-edad)*12;
	}else{
		if (sexo =='M'){
			m=(60-edad)*12;
		}
	}
	return m;
}

int main() {
	int op=0;
	float S_ob; // S_ob dinero ahorrado por la cotizacion obligatoria
	float r_s=0.4; // r_s rentabilidad real-> el valor es 0.4
	float RIP; //RIP sueldo imponible promedio (de donde se descuenta el 10%)
	float Z=0; // Z sumatoria de la formula
	float S_v; // S_v dinero ahorrado en la APV
	int mv; // mv= meses de vida.
	int Jd;// jubilacion deseada
	int meses; // meses restantes para jubilarse, nostros obtenemos este numero con la edad que ingresa el usuario.
	int CAPV; //CAPV dinero que se coloca en la APV
	int edad;
	char sexo;// H hombre, M mujer
	
	
	cout<<"Ingrese la operacion que desea realizar:"<<endl;
	cout<<"1.-Obtener el monto de la jubilacion"<<endl;
	cout<<"2.-Obtener el monto que se debe adicionar a la APV para ganar una cantidad de dinero especifica al momento de jubilarse."<<endl;
	cin>>op;
	
	cout<<"Ingrese su edad."<<endl;
	cin>>edad;
	
	cout<<"Ingrese su sexo. (H o M)"<<endl;
	cin>>sexo;
	
	cout<<"Ingrese el monto ahorrado a la fecha en su AFP."<<endl;
	cin>>S_ob;
	
	cout<<"Ingrese el monto ahorrado a la fecha en su APV."<<endl;
	cin>>S_v;
	
	
	cout<<"Ingrese su sueldo imponible promedio. (Estime el sueldo para los años posteriores)"<<endl;
	cin>>RIP;
	
	meses=meses1(edad);
	int mv=MV(edad,sexo);

	if (op==1){//op =1 retorna el dinero que se recibira mensualmente, despues de jubilarse hasta los 80 años (H) o 83 años (M)
		
		cout<< F1(S_ob,r_s,RIP,Z,S_v,meses,CAPV)/ mv; // saldo total ahorrado en la afp al momento de jubilar.
		// Al dividir el valor que retorna F1 por mv se obtiene la jubilacion mensual.
		
	}else{//op=2 se retornara el dinero que se debe colocar mensualmente a la APV para poder tener una jubilacion "deseada" por el usuario
		cout<<"Ingrese la jubilacion que quiere recibir.";
		cin>>Jd;
		cout<<F2(S_ob,r_s,RIP,Z,S_v,meses,Jd,mv);
	}
	
	//Actualizacion : 29/03- 20.33 hrs
	
	return 0;
}
