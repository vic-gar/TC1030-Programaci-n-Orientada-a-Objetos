/*
  * Proyecto Historial Clínico Profesional en Nutrición
  * Víctor Adrián García Galván
  * A01713062
  * 22/05/2025
*/

/**
  * Descripción del Proyecto
  * Este proyecto para la clase de Programación Orientado a Objetos busca ser
  * una plataforma que ayude a un profesional en nutrición a llevar un historial
  * clínico de sus pacientes, dividiendolos en distintas especificaciones en
  * base a condiciones clínicas específicas, como en el caso de presentar un
  * edema o una amputación. Así los datos e interpretaciones de las mismas se
  * clasificarán para tomar los valores reales para estas condiciones. Los
  * pacientes sin ninguna condición cuentan con indices normales, mientras que
  * los que cuentan con problemas específicos tienen otros índices dependiendo
  * de su condición.
**/

//Bibliotecas
#include <iostream> //Para imprimir
#include <string>
#include "Paciente.h" // Objetos de mi proyecto
#include "Historial.h"

void menu(){
    std::cout << "\n================= Menu =================\n" << std::endl;
    std::cout << "1. Agregar un Paciente \n" << std::endl;
    std::cout << "2. Mostrar Historial Clinico \n" << std::endl;
    std::cout << "3. Mostrar Indices de Masa Corporal \n" << std::endl;
    std::cout << "4. Mostrar Indices Cintura Cadera \n" << std::endl;
    std::cout << "5. Salir \n" << std::endl;
}

int main(){
  Historial historial(10);//Declaramos un historial con capacidad de 10

  std::string nombre;
  int edad;
  float peso;
  float altura;
  float cintura;
  float cadera;
  std::string tipo_edema;
  std::string tipo_ampu;

  //Creación de objetos ejemplo para el programa
  historial.creaPacientesEjemplos();

  int opcion = 0;
  //Ciclo para desplegar el menú de los metodos hasta que el usuario desee salir
  while(opcion < 5 && opcion >= 0){
    //Se imprime el menú
    menu();
    //Pide al usuario la opción que desea ejecutar
    std::cin >> opcion;

    if(opcion == 1){
      int tipo;
      std::cout << "¿Que tipo de Paciente es? (solo numero)\n" << std::endl;
      std::cout << "1.Regular  2.Edema  3.Amputacion" << std::endl;
      std::cin >> tipo;

      if (tipo == 1){
        std::cout << "\nNombre del Paciente: " << std::endl;
        std::cin.ignore();
        std::getline(std::cin, nombre);
        std::cout << "\nEdad del Paciente: " << std::endl;
        std::cin >> edad;
        std::cout << "\nPeso del Paciente (kg): " << std::endl;
        std::cin >> peso;
        std::cout << "\nAltura del Paciente (m): " << std::endl;
        std::cin >> altura;
        std::cout << "\nCintura del paciente (cm): " << std::endl;
        std::cin >> cintura;
        std::cout << "\nCadera del paciente (cm): " << std::endl;
        std::cin >> cadera;
        Paciente*n = new Normal(nombre, edad, peso, altura, cintura, cadera);
        historial.agregaPaciente(n);
      }
      else if(tipo == 2){
        std::cout << "\nNombre del Paciente: " << std::endl;
        std::cin.ignore();
        std::getline(std::cin, nombre);
        std::cout << "\nEdad del Paciente: " << std::endl;
        std::cin >> edad;
        std::cout << "\nPeso del Paciente (kg): " << std::endl;
        std::cin >> peso;
        std::cout << "\nAltura del Paciente (m): " << std::endl;
        std::cin >> altura;
        std::cout << "\nCintura del paciente (cm): " << std::endl;
        std::cin >> cintura;
        std::cout << "\nCadera del paciente (cm): " << std::endl;
        std::cin >> cadera;
        std::cout <<"\nTipo de Edema del paciente (con mayuscula): "<<std::endl;
        std::cout <<"Tobillo // Rodilla // Raiz Pierna // Anasarca"<<std::endl;
        std::cin.ignore();
        std::getline(std::cin, tipo_edema);
        Paciente*e = new Edema(nombre, edad, peso, altura, cintura, cadera, 
          tipo_edema);
        historial.agregaPaciente(e);
      } 
      else if(tipo == 3) {
        std::cout << "\nNombre del Paciente: " << std::endl;
        std::cin.ignore();
        std::getline(std::cin, nombre);
        std::cout << "\nEdad del Paciente: " << std::endl;
        std::cin >> edad;
        std::cout << "\nPeso del Paciente (kg): " << std::endl;
        std::cin >> peso;
        std::cout << "\nAltura del Paciente (m): " << std::endl;
        std::cin >> altura;
        std::cout << "\nCintura del paciente (cm): " << std::endl;
        std::cin >> cintura;
        std::cout << "\nCadera del paciente (cm): " << std::endl;
        std::cin >> cadera;
        std::cout<<"\nTipo de Amputacion del paciente (con mayuscula): "<< std::endl;
        std::cout <<"Rodilla // Pierna // Antebrazo // Brazo" << std::endl;
        std::cin.ignore();
        std::getline(std::cin, tipo_ampu);
        Paciente*a = new Amputacion(nombre, edad, peso, altura, cintura, cadera, 
          tipo_ampu);
        historial.agregaPaciente(a);
      }else{
        std::cout << "Entrada invalida. Intenta de nuevo." << std::endl;
      }
    }
    else if(opcion == 2){
      historial.mostrarPacientes();
    }
    else if(opcion == 3){
      historial.mostrarIMC();
    }
    else if(opcion == 4){
      historial.mostrarICC();
    }
    else if(opcion == 5){
      break;
    }
    else {
      std::cout << "\nEntrada invalida, intenta de nuevo.\n" << std::endl;
    }
  }
  return 0;
}
