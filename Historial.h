/*
 * Proyecto Historial Clínico Profesional en Nutrición
 * Víctor Adrián García Galván
 * A01713062
 * 22/05/2025
 * versión : 2
 * Esta clase defina objeto de tipo Historial que contiene el arreglo de
 * Pacientes para nuestro programa
 */

 #ifndef HISTORIAL_H_
 #define HISTORIAL_H_

 #include <string>
 #include <sstream>
 #include <iostream>
 #include <iomanip>

 #include "Paciente.h" //Biblioteca con mis objetos

class Historial {
  private:
    Paciente** pacientes; //Arreglo de punteros a objetos Paciente
    int nPacientes; //Máximo de pacientes posibles
    int contador; //Contador para el numero de pacientes actuales en el histroial

  public:
    Historial(int np);
    void creaPacientesEjemplos();
    void agregaPaciente(Paciente* paciente); //Puntero
    void mostrarPacientes();
    void mostrarIMC();
    void mostrarICC();
};

/* Constructor de la clase Historial
* Inicializa el arreglo de Pacientes donde llevaremos el
* conteo de los pacientes dependiendo del numero de pacientes
* que se indiquen.
*/
Historial::Historial(int np): nPacientes(np), contador(0){
  pacientes = new Paciente*[nPacientes];
}

/**
 * creaPacientesEjemplos genera objetos en pacientes[]
 *
 * genera objetos de tipo Normal, Edema y Amputacion y los
 * guarda en pacientes[] (arreglo de pacientes)
 * para poder hacer pruebas. No usar esta función si se va a usar el programa
 * en producción, ya que los datos son falsos.
 */
void Historial::creaPacientesEjemplos(){
  pacientes[contador] = new Normal("Jose Miguel", 37, 73.3, 1.75, 73, 69);
  contador++;
  pacientes[contador] = new Edema("Josefina", 48, 68.1, 1.62, 68, 72, "Raiz Pierna");
  contador++;
  pacientes[contador] = new Amputacion("Guadalupe", 62, 55.8, 1.52, 50, 55, "Pierna");
  contador++;
}

/**
 * agregaPaciente agrega un objeto creado al arreglo de pacientes[]
 * Utiliza agregación para su creación, al llamar al objeto ya previamnete hecho
 * y guardandolo en nuestro arreglo
 */
void Historial::agregaPaciente(Paciente* paciente){
  if (contador < nPacientes){
    pacientes[contador] = paciente;//Se agrega el puntero del paciente al arreglo
    contador++;
  } else {
    std::cout << "Llegaste al limite de Pacientes disponibles. Para continuar necesitas la version Pro" << std::endl;
  }
}

/**
 * mostrarPacientes() regresa el método conv_str de cada paciente dependiendo de
 * que tipo de paciente son.
 */
void Historial::mostrarPacientes(){
  std::cout << "\n==========================================" << std::endl;
  std::cout << "Pacientes en el Historial Clinico" << std::endl;
  std::cout << "==========================================" << std::endl;
  for (int i = 0; i < contador; i++){
    std::cout << pacientes[i] -> conv_str() << std::endl;
  }
}

/**
 * mostrarIMC() regresa el método indice_mc de cada paciente dependiendo de que
 * tipo de paciente son.
 */
void Historial::mostrarIMC(){
  std::cout << "\n==========================================" << std::endl;
  std::cout << "Indice Masa Corporal de cada Paciente" << std::endl;
  std::cout << "==========================================\n" << std::endl;
  for (int i = 0; i < contador; i++){
    std::cout << pacientes[i] -> get_nombre() << ":" << std::fixed <<
    std::setprecision(2) << pacientes[i] -> indice_mc() << std::endl;
  }
}

/**
 * mostrarICC() regresa el método indice_cc de cada paciente dependiendo de que
 * tipo de paciente son.
 */
void Historial::mostrarICC(){
  std::cout << "\n==========================================" << std::endl;
  std::cout << "Indice Cintura Cadera de cada Paciente" << std::endl;
  std::cout << "==========================================\n" << std::endl;
  for (int i = 0; i < contador; i++){
    std::cout << pacientes[i] -> get_nombre() << ":" << std::fixed <<
    std::setprecision(2) << pacientes[i] -> indice_cc() << std::endl;
  }
}

 #endif
