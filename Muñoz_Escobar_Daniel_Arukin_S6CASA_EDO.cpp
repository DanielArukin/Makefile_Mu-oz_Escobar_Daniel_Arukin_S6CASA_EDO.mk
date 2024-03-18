#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<cmath>
#include <fstream>

//#include <array>

using namespace std;

float euler (float y0, const int t_quiero, float t0, float dt);
float Runge_Kutta_4to (float y0, int t_inter, float t0, float dt);

int main(){
float e=euler(1, 50, 0,0.01);

float rk=Runge_Kutta_4to(1, 50, 0, 0.01);
}

float euler (float y0, const int t_inter, float t0, float dt){
	char data[t_inter];

   // open a file in write mode.
   ofstream outfile;
   outfile.open("metodo de euler");
   /*
	array<float, t_inter> y;
	array<float, t_inter> t;
	*/
	float y[t_inter];
	float t[t_inter];
	y[0]=y0;
	t[0]=t0;
	outfile<<t[0]<<" | "<<y[0]<<endl;
	for (int i=1; i<t_inter; i++){
		y[i]= y[i-1] + dt*(-y[i-1]);
		t[i]=i*dt;
		outfile<<t[i]<<" | "<<y[i]<<endl;
	}
	outfile.close();
	
	cout<<"Los errores relativos porcentuales del metodo de euler son: "<<endl;
	float errores[t_inter];
	for (int j=0; j<t_inter; j++){
		errores[j]= ((abs(y[j]-exp(-t[j])))/exp(-t[j]))*100.0;
		cout<<errores[j]<<" porciento"<<endl;
	}
}

float Runge_Kutta_4to (float y0, int t_inter, float t0, float dt){
	char data[t_inter];
	 // open a file in write mode.
   	ofstream outfile;
   	outfile.open("metodo de Runge-Kutta de 4to");
   	float y[t_inter];
	float t[t_inter];
	float K1[t_inter];
	float K2[t_inter];
	float K3[t_inter];
	float K4[t_inter];
	y[0]=y0;
	t[0]=t0;
	K1[0]= dt*(-y0);
	K2[0]=dt*(-(y0) + K1[0]/2);
	K3[0]=dt*(-(y0) + K2[0]/2);
	K4[0]=dt*(-(y0) + K3[0]);
	outfile<<t[0]<<" | "<<y[0]<<endl;
	for (int i=1; i<t_inter; i++){
		y[i]= y[i-1]+(1.0/6)*(K1[i-1] + 2*K2[i-1] + 2*K3[i-1] +K4[i-1]);
		t[i]=i*dt;
		K1[i]= dt*(-y[i]);
		K2[i]=dt*(-(y[i]) + K1[i]/2);
		K3[i]=dt*(-(y[i]) + K2[i]/2);
		K4[i]=dt*(-(y[i]) + K3[i]);
		outfile<<t[i]<<" | "<<y[i]<<endl;
	}
	outfile.close();	
	cout<<"Los errores relativos porcentuales del metodo de Runge-Kutta_4to son: "<<endl;
	float errores[t_inter];
	for (int j=0; j<t_inter; j++){
		errores[j]= ((abs(y[j]-exp(-t[j])))/exp(-t[j]))*100.0;
		cout<<errores[j]<<" porciento"<<endl;
	}
	
}


