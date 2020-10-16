/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: dalva
 *
 * Created on October 16, 2020, 2:55 PM
 */

#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <iomanip>


using namespace std;

double sigmoide(int);
int menu();
double aproximacionPi(int);

/*
 * 
 */
int main(int argc, char** argv) {
    
    int opcion = 0;
    
    while( opcion != 3){
        
        switch((opcion = menu())){
            
            case 1:{
                int valorX = 0;
                
                cout << "Ingrese el valor de x para la funcion sigmoide: ";
                cin >> valorX;
                
                cout <<endl;
                
                double result = sigmoide(valorX);
                
                cout << "El resultado de la funcion sigmoide es: " 
                     <<showpoint <<fixed <<setprecision(4) <<result <<endl;
                break;
                
            }case 2:{
                int limite = 0;
                
                cout << "Ingrese el valor del limite para la aproximacion de Pi: ";
                cin >> limite;
                
                cout <<endl;
                
                double resultado = aproximacionPi(limite);
                
                cout << "El resultado de la aproximacion es: " <<showpoint
                        <<fixed <<setprecision(4) <<resultado <<endl;
                
                break;
                
            }
            
     
        }
        
        
    }
    
    return 0;
}

//Calcula el valor de la funcion sigmoide dada el valor de x
double sigmoide(int valorX){
    
    int numerador = 1;
    
    double e = 2.718;
    double elevadoE = 1;
    
    for(int i=0; i < valorX; i++){
        elevadoE *= e;
    }
    
    double resultE = 1/elevadoE;
    
    double denominador = 1 + resultE;
    
    double resultadoF = numerador / denominador;
    
    
    return resultadoF;
    
}

//Calcula una aproximacion al valor de Pi dado un limite
double aproximacionPi(int limite){
    
    double result = 0;
    
    for(int n = 0; n < limite; n++){
        
        int potNum = 1;
        
        for(int j = 0; j < limite; j++){
            potNum *= -1;
        }
        
        
        int denominador = (2*n) + 1;
        
        result += potNum / denominador;
    }
    
    double resultado = result * 4;
    
    return resultado;
}

//Menu con ciclo repetitivo
int menu(){
    int opcion = 0;
    
    do{
        
        cout << "       Menu        \n"
             << "1. Calcular el valor de la funcion Sigmoide \n"
             << "2. Aproximacion del valor de Pi \n"
             << "3. Salir del programa \n";   
        cin >> opcion;
        
        if(opcion < 1 || opcion > 3){
            
            cout << "La opcion es incorrecta intente de nuevo! \n";
        }
        
        
    }while(opcion < 1 && opcion < 3 );
    
    return opcion;
}

