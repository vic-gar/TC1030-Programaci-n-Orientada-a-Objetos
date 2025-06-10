/*
 * Proyecto Historial Clínico Profesional en Nutrición
 * Víctor Adrián García Galván
 * A01713062
 * 22/05/2025
 * versión : 2
 * Esta clase defina objeto de tipo Paciente que contiene las clases heredadas
 * Normal, Edema y Amputacion
 */

#ifndef PACIENTE_H_
#define PACIENTE_H_

#include <string>
#include <sstream>

//Declaracion de clase abstracta Paciente
class Paciente {
  protected:
    std::string nombre;
    int edad;
    float peso;
    float altura;
    float cintura;
    float cadera;

  public:
    //Constructores
    Paciente(): nombre(""), edad(0), peso(0.0), altura(0.0), cintura(0.0),
    cadera(0.0) {};
    Paciente(std::string nom, int ed,float pes,float alt, float cin, float cad):
    nombre(nom), edad(ed), peso(pes), altura(alt), cintura(cin), cadera(cad){};

    //Se declaran los métodos de la clase Paciente
    std::string get_nombre(){
      return nombre;
    }
    int get_edad(){
      return edad;
    }
    float get_peso(){
      return peso;
    }
    float get_altura(){
      return altura;
    }
    float get_cintura(){
      return cintura;
    }
    float get_cadera(){
      return cadera;
    }

    float indice_cc();

    //Métodos que se sobreescribirán
    virtual float indice_mc() = 0; //Virtual y Metodo de clase abstracta
    virtual std::string conv_str() = 0;
};

/**
* indice_cc divide el valor de la cintura entre la Cadera
*
* @return float con el resultado de la operación
*/
float Paciente::indice_cc(){
  return cintura/cadera;
}


//Declaracion de clase Normal que hereda de Paciente
class Normal: public Paciente {
  public:
    Normal():Paciente("", 0, 0.0, 0.0, 0.0, 0.0){};
    Normal(std::string nom, int ed, float pes, float alt, float cin, float cad):
    Paciente(nom, ed, pes, alt, cin, cad){};

    // Se declaran los métodos de la clase Normal
    float indice_mc();
    std::string conv_str();
};

float Normal::indice_mc(){
  return peso/(altura*altura);
}

/**
 * conv_str convierte a atributos a string.
 *
 * concatena todos los valores de los atributos en un string para ser impreso
 *
 * @return string con los valores y texto concatenado especificos para Normal
 */
std::string Normal::conv_str(){
  std::stringstream ss;
  ss <<"\nPaciente Estandar || "<< nombre << "\nEdad -> "<< edad << "\nPeso -> "
  << peso << "\nAltura -> " << altura << "\nCintura -> " << cintura <<
  "\nCadera -> "<< cadera;
  return ss.str();
}




//Declaracion de clase Edema que hereda de Paciente
class Edema: public Paciente {
  private:
    std::string tipo_edema;

  public:
    //Declaramos los constructores de la clase Edema
    Edema(): Paciente("", 0, 0.0, 0.0, 0.0, 0.0){};
    Edema(std::string nom, int ed, float pes, float alt, float cin, float cad,
    std::string tip_ed): Paciente(nom, ed, pes, alt, cin, cad),
    tipo_edema(tip_ed){};

    // Se declaran los métodos de la clase Edema
    std::string get_tipo_edema(){
      return tipo_edema;
    }
    void set_peso(float );
    float indice_mc();
    std::string conv_str();
};

void Edema::set_peso(float pes){
  peso = pes;
}

/**
* Metodo que calcula el Indice de masa Corporal en base al tipo de Edema que
* presenta el paciente
*/
float Edema::indice_mc(){
  if (tipo_edema == "Tobillo"){
    peso = peso - 1;
  }
  else if (tipo_edema == "Rodilla"){
    peso = peso - 3.5;
  }
  else if (tipo_edema == "Raiz Pierna"){
    peso = peso - 5.5;
  }
  else if (tipo_edema == "Anasarca"){
    peso = peso - 11;
  }
  return peso/(altura*altura);
}

/**
 * conv_str convierte a atributos a string.
 *
 * concatena todos los valores de los atributos en un string para ser impreso
 *
 * @return string con los valores y texto concatenado especificos para Edema
 */
std::string Edema::conv_str(){
  std::stringstream ss;
  ss<<"\nPaciente con Edema || "<< nombre << "\nEdad -> " << edad <<"\nPeso -> "
  << peso << "\nAltura -> " << altura << "\nCintura -> " << cintura <<
  "\nCadera -> "<< cadera << "\nTipo de Edema -> " << tipo_edema;
  return ss.str();
}


//Declaracion de clase Amputacion que hereda de Paciente
class Amputacion: public Paciente {
  private:
    std::string tipo_ampu;
    float peso_ajustado;

  public:
    //Declaramos los constructores de la clase Amputacion
    Amputacion(): Paciente("", 0, 0.0, 0.0, 0.0, 0.0){};
    Amputacion(std::string nom, int ed,float pes,float alt,float cin, float cad,
    std::string tip_am): Paciente(nom, ed, pes, alt, cin, cad),
    tipo_ampu(tip_am){};

    // Se declaran los métodos de la clase Amputacion
    std::string get_tipo_ampu(){
      return tipo_ampu;
    }
    float calc_peso_ajustado();
    void set_peso(float );
    float indice_mc();
    std::string conv_str();
};

void Amputacion::set_peso(float pes){
  peso = pes;
}

/**
* Metodo que calcula el peso ajustado del paciente para utilizarse por medio de
* sobrecarga en el método de indice_mc
*/
float Amputacion::calc_peso_ajustado(){
  if (tipo_ampu == "Rodilla"){
    peso_ajustado = peso * 1.063;
  }
  else if (tipo_ampu == "Pierna"){
    peso_ajustado = peso * 1.18;
  }
  else if (tipo_ampu == "Antebrazo"){
    peso_ajustado = peso * 1.022;
  }
  else if (tipo_ampu == "Brazo"){
    peso_ajustado = peso * 1.05;
  }
  return peso_ajustado;
}

/**
* Método que utiliza sobrecarga para calcular el Indice de masa Corporal del
* paciente
*/
float Amputacion::indice_mc(){
  return calc_peso_ajustado()/(altura*altura);
}

/**
 * conv_str convierte a atributos a string.
 *
 * concatena todos los valores de los atributos en un string para ser impreso
 *
 * @return string con los valores y texto concatenado especificos para
 * Amputación
 */
std::string Amputacion::conv_str(){
  std::stringstream ss;
  ss<<"\nPaciente con Amputacion || " << nombre << "\nEdad -> " << edad <<
  "\nPeso -> " << peso << "\nAltura -> " << altura << "\nCintura -> "
  << cintura << "\nCadera -> "<< cadera <<"\nTipo de Amputacion -> "<<tipo_ampu;
  return ss.str();
}

#endif
