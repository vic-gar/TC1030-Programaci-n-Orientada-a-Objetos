# TC1030-Programacion-Orientada-a-Objetos

El proyecto busca ser una plataforma que ayude a un profesional en nutrición a llevar un historial clínico de sus pacientes, dividiendolos en distintas especificaciones en base a condiciones clínicas específicas, como en el caso de presentar un edema o una amputación. Así los datos e interpretaciones de las mismas se clasificarán para tomar los valores reales para estas condiciones. Los pacientes sin ninguna condición cuentan con indices normales, mientras que los que cuentan con problemas específicos tienen otros índices dependiendo de su condición. 

## Función 
El programa permite agregar nuevos pacientes y color sus datos, así como calcular su ínice de masa corporal y su índice cintura cadera. Dando los datos para la interpretación del profesional de una forma más eficiente. 

![Diagrama de Clases del proyecto](Diagrama_de_clases.png)

## Consideraciones
El programa solo corre en la consola y esta hecho con c++ standard por lo que corre en todos los sistemas operativos

compilar con: "g++ Paciente.h Historial.h main.cpp"

correr en linux: "/a.out"

correr en windows: "a.exe"
