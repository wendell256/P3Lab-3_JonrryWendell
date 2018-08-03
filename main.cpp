#include <iostream>
#include <iomanip> 
#include <cmath>

using namespace std;

void ejercicio1();

int menu();

void ejercicio2();

void ejercicio3();

double factorial(double num);

bool verpar(int num);

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
      cin>>resp1;
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
  double* nums = new double[3];//numeros que van con x²,x¹ y el numero sin x
  //formula cuadratica: (x = -4 +/- sqrt(b² - 4ac))/2a
  double raiz = 0;//evalua lo que va dentro de la raiz para ver si la respuesta es imaginaria

  double respuestax1 = 0, respuestax2 = 0;
  cout<< "Ingrese el numero que va con x²:"<<endl;
  cin>> nums[0];
  cout<< "Ingrese el numero que va con x:"<<endl;
  cin>> nums[1];
  cout<< "Ingrese el numero que va sin x:"<<endl;
  cin>> nums[2];
  
  raiz = pow(nums[1],2) - 4*nums[0]*nums[2];

  if(raiz<0){
    cout<<"Error. La respuesta es un numero imaginario."<<endl;
  }else{
    respuestax1 = ((-nums[1]-sqrt(raiz))/(2*nums[0]));
    respuestax2 = ((-nums[1]+sqrt(raiz))/(2*nums[0]));
    cout<<"Funcion factorizada:"<<endl;
    if(respuestax1 <= 0){
      if(respuestax1 != 0){
        respuestax1*=-1;
      }
      cout<<setprecision(3)<<"(x + "<<respuestax1<< ") (";
    }else{
      cout<<setprecision(3)<<"(x - "<<respuestax1<<") (";
    }
    if(respuestax2 <= 0){
      if(respuestax2 != 0){
        respuestax2*=-1;
      }
      cout<<setprecision(3)<<"x + "<<respuestax2<<")"<<endl;
    }else{
      cout<<setprecision(3)<<"x - "<<respuestax2<<")"<<endl;
    }
        
  }
  delete[] nums;
}

double factorial(double num){
  double resp=1;
  if(num==0){
    return resp;
  }else{
    for(int i=1;i<=num;i++){
      resp*=i;
    }
    return resp;
  }
}

void ejercicio2(){
  double angulo=0,angulorad=0,respsin=0,respcos=0;
  
  cout<<"Ingrese el angulo en grados:"<<endl;
  cin>> angulo;
  //convertir grados a radian
  angulorad = angulo *(M_PI/180);
  
  //for de sin
  for(int i=0;i<150;i++){
    double formulasin = ((pow(-1,i))/factorial(2*i+1))*pow(angulorad,2*i+1);
    double formulacos = ((pow(-1,i))/factorial(2*i))*pow(angulorad,2*i);
    respsin += formulasin;
    respcos += formulacos;
  }
  cout<<"sin("<<angulo<<") = "<<respsin<<endl;
  cout<<"cos("<<angulo<<") = "<<respcos<<endl;
}

void ejercicio3(){
  int cantidad=0,espacios = 0;

  cout<< "ingrese cantidad de lineas:"<<endl;
  cin>> cantidad;
  cout<<setw(cantidad + 4)<<" o "<<setw(cantidad)<<endl;
  for(int i=1; i<=cantidad;i++){
    espacios = (cantidad-i+4)*2;
    cout<<setw((espacios)/2);
    for(int j=0; j<i;j++){
      int resp = factorial(i)/(factorial(j)*factorial(i-j));
      if(verpar(resp)){
        cout<<"+ ";
      }else{
        cout<<"o ";
      }
    }
    cout<<"o "<<endl;
     
  }
}

bool verpar(int resp){
  if(resp%2==0){
    return true;
  }else{
    return false;
  }
}

