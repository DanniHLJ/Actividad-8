#include <iostream>
using namespace std;
const char *nombre_archivo = "Archivo.dat";
struct Estudiante {

    int codigo; 
    char nombres[50];
    char apellidos [50];
    int telefono;

};
void Leer ();
void Crear();
void Actualizar ();
void Borrar ();
main (){
    //C >> C++
    //Archivos 


	Leer ();
    Crear();
    Borrar ();
    Actualizar ();
    
    system ("Pause");
}
void Leer (){
	system ("cls");
	FILE*Archivo = fopen(nombre_archivo,"rb");
	if (!Archivo){
		Archivo = fopen(nombre_archivo,"w+b");
	}
	Estudiante estudiante;
	int id = 0; //indice o pocision del registro(fila) dentro del archivo
	fread (&estudiante,sizeof(Estudiante),1,Archivo);
	cout<<"_________________________"<<endl;
	cout<<"ID"<<"|"<<"Codigo"<<"|"<<"    Nombres"    <<"|"<<"    Apellidos    "<<"|"<<"Telefono"<<"|"<<endl;
	
	do{
		cout<<id<<"|"<<estudiante.codigo<<"|"<<estudiante.nombres<<"|"<<estudiante.apellidos<<"|"<<estudiante.telefono<<"|"<<endl;
		fread (&estudiante,sizeof(Estudiante),1,Archivo);
		id+=1;
	}while(feof(Archivo)==0);
	 fclose(Archivo);
}
void Crear(){
    FILE*Archivo = fopen(nombre_archivo,"a+b");
    char res;

    Estudiante estudiante; 


    do {
        fflush(stdin);
        cout<<"Ingrese Codigo:";
        cin>>estudiante.codigo;
        cin.ignore();

        cout<<"Ingrese Nombres:";
        cin.getline(estudiante.nombres,50);

        cout<<"Ingrese Apellidos:";
        cin.getline(estudiante.apellidos,50);

        cout<<"Ingrese Telefono:";
        cin>>estudiante.telefono;

		fwrite(&estudiante,sizeof(Estudiante),1,Archivo);

        cout<<"Desea ingresar otro estudiante (s/n)";
        cin>>res;

    }while (res == 's'|| res == 'S');
	
	


    fclose(Archivo);
    Leer();
}

void Actualizar (){ // crea y borra 

	FILE*Archivo = fopen(nombre_archivo,"r+b");
    Estudiante estudiante;
	
	int id=0;
		cout<<"Ingrese el ID que desea modificar:";
		cin>>id;
		fseek(Archivo,id * sizeof(Estudiante),SEEK_SET);
	
        cout<<"Ingrese Codigo:";
        cin>>estudiante.codigo;
        cin.ignore();

        cout<<"Ingrese Nombres:";
        cin.getline(estudiante.nombres,50);

        cout<<"Ingrese Apellidos:";
        cin.getline(estudiante.apellidos,50);

        cout<<"Ingrese Telefono:";
        cin>>estudiante.telefono;

		fwrite(&estudiante,sizeof(Estudiante),1,Archivo);

    

    fclose(Archivo);
    Leer();
}

void Borrar (){
	const char *nombre_archivo_temp = "Archivo_temp.dat";
	FILE*Archivo_temp = fopen(nombre_archivo_temp,"w+b");
	FILE*Archivo = fopen(nombre_archivo,"rb");
	
	Estudiante estudiante; 
	int id=0, id_n=0;
	
	cout<<"Ingrese el ID a eliminar:";
	cin>>id;
	
	while(fread (&estudiante,sizeof(Estudiante),1,Archivo)){
		if (id_n != id){
			fwrite(&estudiante,sizeof(Estudiante),1,Archivo_temp);
		}
		id_n++;
	}
	fclose (Archivo);
	fclose (Archivo_temp);
	
	Archivo_temp = fopen(nombre_archivo_temp,"rb");
	Archivo = fopen(nombre_archivo,"w+b");
	while(fread (&estudiante,sizeof(Estudiante),1,Archivo_temp)){
		fwrite(&estudiante,sizeof(Estudiante),1,Archivo);
	}
	fclose (Archivo);
	fclose (Archivo_temp);
	Leer();
}


