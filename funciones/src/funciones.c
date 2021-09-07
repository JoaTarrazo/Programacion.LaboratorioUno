/*
 ============================================================================
 Name        : funciones.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void funcionMostrarResultado(int resultadoSuma, int resultadoResta, int resultadoMultiplicacion);
int funcionDivision(int numeroFuncionUno,int numeroFuncionDos,float* punteroDelResultado);
int funcionMultiplicacion(int numeroFuncionUno,int numeroFuncionDos);
int funcionResta(int numeroFuncionUno,int numeroFuncionDos);
int funcionSuma(int numeroFuncionUno,int numeroFuncionDos);

int main(void)
{
	setbuf(stdout,NULL);


int numeroUno;
int numeroDos;
int resultadoSuma;
int resultadoResta;
int estadoDivision;
int resultadoMultiplicacion;
float resultadoDivisionFuncion;


printf("ingrese el numero UNO\n");
scanf("%d",&numeroUno);

printf("ingrese el numero DOS\n");
scanf("%d",&numeroDos);


resultadoSuma= funcionSuma(numeroUno,numeroDos);


resultadoResta= funcionResta(numeroUno,numeroDos);


resultadoMultiplicacion= funcionMultiplicacion(numeroUno,numeroDos);


estadoDivision= funcionDivision(numeroUno,numeroDos,&resultadoDivisionFuncion);  //ACA GUARDO LO QUE RETORNO O SEA EL ESTADO (*en la funcion* return=estado)
														//en resultadoDivisionFuncion GUARDO EL RESULTADO DE LA DIVISION QUE HICE EN LA FUNCION. MEJOR DICHO, EL RESULTADO DE ESA DIVISION SE GUARDA EN LA VARIABLE DEL MAIN LLAMADA "FLOAT* PUNTERO DEL RESULTADO" Y DE AHI, GUARDO ESE RESULTADO EN &resultadoDivisionFuncion el cual se asimila por el &= en el main y el puntero* en la funcion, y porque es el 3er argumento en el MAIN y el 3er argumento en la FUNCION.

if(estadoDivision==1)
{
	printf("el resultado de la division es :%f \n",resultadoDivisionFuncion);
}
else
{
	printf("No se puede dividir por 0\n");
}


funcionMostrarResultado(resultadoSuma,resultadoResta,resultadoMultiplicacion); //funcion que muestra los PRINTF. (menos la division porque tiene su printf en el if-else.


	return EXIT_SUCCESS;
}

//FUNCIONES:

//SUMAR
int funcionSuma(int numeroFuncionUno,int numeroFuncionDos)
{
	int resultadoSumaFuncion;

	resultadoSumaFuncion= numeroFuncionUno + numeroFuncionDos;

	return resultadoSumaFuncion;
}

//RESTAR
int funcionResta(int numeroFuncionUno,int numeroFuncionDos)
{
	int resultadoRestaFuncion;

		resultadoRestaFuncion= numeroFuncionUno - numeroFuncionDos;

		return resultadoRestaFuncion;
}

//MULTIPLICAR
int funcionMultiplicacion(int numeroFuncionUno,int numeroFuncionDos)
{
	int resultadoMultiplicacionFuncion;

		resultadoMultiplicacionFuncion= numeroFuncionUno * numeroFuncionDos;

return resultadoMultiplicacionFuncion;
}
//DIVISION
int funcionDivision(int numeroFuncionUno,int numeroFuncionDos,float* punteroDelResultado) //en la variable punteroDelResultado, yo guardo el resultado de la division, y envio este resultado por REFERENCIA, a la tercer variable que este colocada en el argumento del main, esto se hace asi xq la funcion ya esta retornando el ESTADO (el cual edtermina si se puede dividir o no) y como ya sabemos, las funciones solo pueden retornar un valor por return, cualquier otro dato que querramos pasarle se hace por referencia.
{
	int estado=1;
	//estado=1 Se puede dividir
	//estado=0 no se puede divivir por 0.
	if(numeroFuncionDos==0)
	{
		estado=0;
	}
	else
	{
		estado=1;
		*punteroDelResultado= numeroFuncionUno / numeroFuncionDos;
	}

	return estado;
}
//PRINTF
void funcionMostrarResultado(int resultadoSuma, int resultadoResta, int resultadoMultiplicacion) //la funcion no retorna nada, xq el printf no se considera dato de retorno, solo se muestra(void - int) solo sirve para mostrar un dato, mas no se puede hacer nada con el.
{
	printf("el resultado de la suma es: %d\n El resultado de la resta es: %d\n El resultado de la multiplicacion es: %d\n",resultadoSuma, resultadoResta, resultadoMultiplicacion);
}

