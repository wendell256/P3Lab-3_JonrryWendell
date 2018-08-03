#include <iostream>

using namespace std;

void ejercicio1();

int menu();

void ejercicio2();

void ejercicio3();

int main(){
  char resp1='y';

  while(resp1=='y' || resp1=='Y'){
    int seleccion = menu();
    switch(seleccion){
      case 1:
        ejercicio1();
      break;
      case 2:
        ejercicio2();
      break;
      case 3:
        ejercicio3();
      break;
      case 4:
        cout<<"Que tengas un buen dia!"<<endl;
      break;
    }//fin switch de seleccion

    cout<<"Desea reinciar el programa?y/n"<<endl;
    cin>>resp1;
    while(resp1 != 'y' && resp1 != 'Y' && resp1 != 'N' && resp1 != 'n'){
      cout<<"Error, valor no valido. Reiniciar?y/n"<<endl;
    }//fin while verificar respuesta
  }//fin while repetir programa

return 0;
}


//funcion que imprime el menu
int menu(){
  int opcion1=1;

  cout<<"***LABORATORIO TRES***"<<endl<<"1) Ejercicio 1"<<endl<<"2) Ejercicio 2"<<endl<<"3) Ejercicio 3"
      <<endl<<"4) Salir"<<endl<<"Ingrese una opcion:"<<endl;
  cin>>opcion1;
  while(opcion1<1 || opcion1>4){
    cout<<"Error valor no valido. Ingrese opcion:"<<endl;
    cin>>opcion1;
  }//fin while verificar rango
  return opcion1;
}

void ejercicio1(){
  double* nums = new int[3];//numeros que van con x²,x¹ y el numero sin x
  
  cout<< "Ingrese el numero que va con x²:"<<endl;
  cin>> nums[0];
  cout<< "Ingrese el numero que va con x:"<<endl;
  cin>> nums[1];
  cout<< "Ingrese el numero que va sin x:"<<endl;
  cin>> nums[2];
  
  

}
