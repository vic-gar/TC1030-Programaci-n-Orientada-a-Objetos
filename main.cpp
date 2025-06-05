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

int main(){
  Historial historial(6); //Declaramos un historial con capacidad de 6 pacientes

  //Creación de objetos ejemplo para el programa
  historial.creaPacientesEjemplos();

  //Agregamos pacientes al Historial. Creación dinámica de objetos de diferentes tipos
  Paciente* normal2 = new Normal("Victor", 20, 68.2, 1.78, 69, 72);
  Paciente* edema2 = new Edema("Jorge", 53, 85, 1.83, 88, 92, "Tobillo");
  Paciente* amputacion2 = new Amputacion("Jessica", 37, 67, 1.63, 52, 60, "Pierna");

  // Agregamos pacientes al historial
  historial.agregaPaciente(normal2);
  historial.agregaPaciente(edema2);
  historial.agregaPaciente(amputacion2);

  //Mostramos a las personas en el historial
  historial.mostrarPacientes();

  //Mostramos los indices de cada paciente que se encuentra en el historial
  historial.mostrarIMC();
  historial.mostrarICC();

  return 0;
}
