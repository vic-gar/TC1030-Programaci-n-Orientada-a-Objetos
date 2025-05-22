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

int main(){

  float peso_aj;

  // Ejemplos de objetos

  //Objeto de la Clase Normal
  Normal paciente_1("Jose Miguel", 37, 73.3, 1.75, 73, 69);
  std::cout << paciente_1.conv_str() << std::endl;
  std::cout << "Indice Cintura Cadera: " << paciente_1.indice_cc() << std::endl;
  std::cout << "Indice Masa Corporal: " << paciente_1.indice_mc() << "\n" << std::endl;

  //Objeto de la Clase Edema
  Edema paciente_2("Josefina", 48, 68.1, 1.62, 68, 72, "Raiz Pierna");
  std::cout << paciente_2.conv_str() << std::endl;
  std::cout << "Indice Cintura Cadera: " << paciente_2.indice_cc() << std::endl;
  std::cout << "Indice Masa Corporal: " << paciente_2.indice_mc() << "\n" << std::endl;

  //Objeto de la Clase Amputacion
  Amputacion paciente_3("Guadalupe", 62, 55.8, 1.52, 50, 55, "Pierna");
  peso_aj = paciente_3.calc_peso_ajustado();
  std::cout << paciente_3.conv_str() << std::endl;
  std::cout << "Indice Cintura Cadera: " << paciente_3.indice_cc() << std::endl;
  std::cout << "Peso ajustado: " << peso_aj << std::endl;
  std::cout << "Indice Masa Corporal: " << paciente_3.indice_mc(peso_aj) << "\n" << std::endl;

  return 0;
}
