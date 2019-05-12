#include <stdio.h>
//Función lineal f(x)
//Se puede cambiar por cualquier otra función
float f(float x){
  float r;
  r=x;
  return r;
}

//Función principal
int main (void){
	//Se declaran los arreglos x y df
	float x [1000],df[1000];

	//Se declaran las variables a,b y h
	float a,b,h;

	//Se declara e inicializa el indice 
	// (o variable) i con el valor 0
	int i=0,j=0;
	//Se inicializa la bandera
	int bandera=0;

	//Se le pide al usuario el valor inicial "a"
	printf("a = ");scanf("%f",&a);

	//Se le pide al usuario el valor final "b"
	printf("\nb = ");scanf("%f",&b);

	//Se le pide al usuario el valor del diferencial o incremento "h"
	printf("\nh = ");scanf("%f",&h);

	//Le pide al usuario un valor correcto una y otra vez, si es que 
	// se equivoca.
	do{
		//Se le pide al usuario qué tipo de difencial hacer
		printf("\nQue tipo de diferenciacion desea hacer?\n 1. Progresiva\n 2. Regresiva.\n 3. Media.\n ");scanf("%i",&bandera);	
	}while(bandera>3 || bandera<0);

	//Va a realizar éste ciclo por lo menos 
	// una vez mientras "a" sea menor que "b"
	do{
		//En el arreglo df, realiza la derivada con
		//los valores de a y h. Asi también lo asigna
		//al elemento df en la posición i. La primera vez
		//que entra seria de la siguiente forma: df[0]
		printf("\n( f( %0.5f  + %0.5f ) - f(%0.5f))/ %0.5f = %0.5f",a,h,a,h, (( f( a + h ) - f(a) ) / h) );
		switch(bandera){
			//Realiza la diferenciacion progresiva
			case 1: df[i] = ( f( a + h ) - f(a) ) / h; break;
			//Realiza la diferenciacion regresiva
			case 2: df[i] = ( f(a) - f( a + h ) ) / h; break;
			//Realiza la diferenciacion media
			case 3: df[i] = ( f( a + h ) - f(a) ) / (2*h); break;
			//Marca el error
			default: printf("\nOcurrio un error.");
		}
		
		//Aumenta el valor de a, sumándole el valor de h
		a = a + h;

		//Aumenta el indice en 1
		i++;
	}while( a < b );

	//Imprime el valor de x, f(x) y df(x) 
	printf("\nx\t\tf(x)\t\tdf(x)\n\n");

	//Imprime los valores obtenidos hasta donde se quedó el
	//indice i, utilizando un indice j para iterar "i" veces
	for( j = 0 ; j <= i ; j++ ){
		//Impreme los valores con un formato de 5 decimales
		printf("%0.5f\t %0.5f\t %0.5f\n\n", 
			(a+h*j), f(a+h*j), df[j] );
	}
	return 0;
}