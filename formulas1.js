// todo esta relacionado con tu codigo

//hay q colocar que r_s=0.004
//hay que crear una funcion meses1 

function FA(S_ob, r_s, RIP, Z, meses){
	var St_ob;
	for(int i = 1; i <=meses; i++){
		Z += Math.pow(1 + r_s, i);
	}
	
	St_ob = S_ob * Math.pow(1+r_s, meses) + 0.1 * RIP * Z;
	return St_ob;
}

function FB(S_v, r_s, meses){
	var St_v;
	St_v = S_v * Math.pow(1 + r_s, meses);
	return St_v;
}

function F1(S_ob, r_s, RIP, Z, S_v, meses, CAPV){
	var S_T, Z1 =0;
	for (int i = 1; i <= meses; i++){
		Z1 += Math.pow(1 + r_s, i);
	}

	S_T = (FA(s_ob, r_s, RIP, Z, meses) + FB(S_v, r_s, meses)) + CAPV * Z1;
	return S_T;
}

function F2(S_ob, r_s, RIP, Z, S_v, meses, Jd, mv){
	var CAPV,Z2 = 0;
	for (int i = 0; i <= meses; i++){
		Z2 += Math.pow(1 + r_s, i);
	}
	
	CAPV = (mv * Jd - FA(S_ob, r_s, RIP, Z, meses) - FB(S_v, r_s, meses))/Z2;
	return CAPV;
}

function MV(edad, sexo){
	var mv = (sexo == "h") ? (80.5 - edad)*12 : (83.5 - edad) * 12;
	return mv;
}

function meses1(edad,sexo){
	var m = (sexo == "h") ? (65 - edad)*12 : (60 - edad) * 12;
	return m;
	
}

function main(op, edad, sexo, Jd, S_ob, RIP, meses){// los datos se insertan desde la pagina
	var Z=0, r_s=0.004 , mv = MV(edad, sexo), meses=meses1(edad,sexo);
	
	if (op == 1){
		return F1(s_ob, r_s, RIP, Z, S_v, meses, CAPV) / mv;
	}else{
		return F2(S_ob, r_s, RIP, Z, S_v, meses, Jd, mv);	
	}
	return "Algo salio mal";
}
