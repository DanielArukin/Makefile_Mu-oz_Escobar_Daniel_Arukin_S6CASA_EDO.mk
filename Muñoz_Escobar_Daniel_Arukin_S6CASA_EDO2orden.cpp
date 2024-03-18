#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<cmath>
#include <fstream>

using namespace std;

float euler (float x0, const int t_inter, float t0, float dt, float k, float m, float v0);
float LeapFrog (float x0, const int t_inter, float t0, float dt, float k, float m, float v0);
int main(){
	float e = euler(0.1, 50, 0, 0.01, 50, 0.2, 0);
	float LF= LeapFrog(0.1, 50, 0, 0.01, 50, 0.2, 0);
}

float euler (float x0, const int t_inter, float t0, float dt, float k, float m, float v0){
	char data[t_inter];

   // open a file in write mode.
   ofstream outfile;
   outfile.open("metodo de euler EDO2orden");
  
	float x[t_inter];
	float t[t_inter];
	float v[t_inter];
	x[0]=x0;
	t[0]=t0;
	v[0]=v0;
	outfile<<t[0]<<" | "<<x[0]<<endl;
	for (int i=1; i<t_inter; i++){
		x[i]= x[i-1] + dt*(v[i-1]);
		v[i]= -(k/m)*x[i];
		t[i]=i*dt;
		outfile<<t[i]<<" | "<<x[i]<<endl;
	}
	outfile.close();
	/*
	cout<<"Los errores relativos porcentuales del metodo de euler son: "<<endl;
	float errores[t_inter];
	for (int j=0; j<t_inter; j++){
		errores[j]= ((abs(y[j]-exp(-t[j])))/exp(-t[j]))*100.0;
		cout<<errores[j]<<" porciento"<<endl;
	}
	*/
}

float LeapFrog (float x0, const int t_inter, float t0, float dt, float k, float m, float v0){
	char data[t_inter];

   // open a file in write mode.
   ofstream outfile;
   outfile.open("metodo de LeapFrog EDO2orden");
   
	float x[t_inter];
	float t[t_inter];
	float v[t_inter];
	x[0]=x0;
	t[0]=t0;
	v[0]=v0 + (1.0/2)*dt*(-k/m)*x0;
	outfile<<t[0]<<" | "<<x[0]<<endl;
	for (int i=1; i<t_inter; i++){
		x[i]= x[i-1] + dt*(v[i-1]);
		v[i]= v[i-1] + dt*(-k/m)*x[i-1];
		t[i]=i*dt;
		outfile<<t[i]<<" | "<<x[i]<<endl;
	}
	outfile.close();
}
