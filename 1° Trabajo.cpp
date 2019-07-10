///Autor: Danilo Abellá.
///Carrera: Licenciatura en Ciencias de la Computación (LCC).
///Profesora: Rosa Berrero.
///Windows 8.0 / SO de 64 bits.
///Compilador: Code-Blocks.
///Fecha de entrega: 30/05/2014.


#include <iostream>
#include <fstream>

using namespace std;

///Funciones

void datos ();                      ///Muestra el contenido del archivo seleccionado.
void codificacion ();               ///Codifica el archivo.
void decodificacion ();             ///Decodifica.
void forma ();                      ///Explica el procedimiento usado para codificar y decodificar.

///----------------------------------------------------------------------------------------------------------------///
///Programa Principal

int main ()
{
    int a;
    cout<<""<<endl;
    cout<<"Introdusca el numero correspondiente a cada tarea y presione Enter: \n"<<endl;
    cout<<"Tareas:"<<endl;
    cout<<"(1)Leer Archivo."<<endl;
    cout<<"(2)Codificar."<<endl;
    cout<<"(3)Decodificar."<<endl;
    cout<<"(4)Mostrar metodo de Codificacion."<<endl;
    cout<<"(Cualquier tecla)Salir. \n"<<endl;
    cout<<"Ralizar tarea numero:";
    while (a)                                        ///Ciclo que permite al usuario elegir una tarea seguido de otra.
    {cin>>a;
    cout<<""<<endl;
    switch (a)                                       ///Crea un menú con todo lo pedido para el trabajo.
        {
    case 1:                                          ///Caso que lleva a leer el archivo.
        datos();
        break;
    case 2:                                          ///Caso que codifica el archivo.
        codificacion();
        break;
    case 3:                                          ///Caso que decodifica el archivo.
        decodificacion();
        break;
    case 4:                                          ///Caso que explica la forma de codificación utilizada.
        forma();
        break;
    default:
        a=0;
        break;
        }
    }
return 0;
}


///----------------------------------------------------------------------------------------------------------------///
///Funciones:


///----------------------------------------------------------------------------------------------------------------///
///Funcion 1:


void datos()
    {
    char n[30],c;
    ifstream f;                                        ///Declara la variable "f" para el archivo a leer.
    cout<<"(1)Ingrese Nombre del Archivo:";
    cin>>n;                                            ///Se lee la variable que toma el nombre del archivo.
    f.open(n);                                         ///Abre el archivo asignado a la variable "n".
    if (f.fail())                                      ///Comprueba si el archivo falla o no existe y asigna una tarea según el caso.
    {   cout<<"\n\n\n              Archivo no existe"<<endl;
        cout<<""<<endl;
    }
    else
    {   cout<<""<<endl;
        cout<<"Lectura del Archivo Original:"<<endl;
        cout<<""<<endl;
        while(!f.eof())                                ///Permite realizar la lectura desde el 1° caracter hasta el ultimo.
        {   f.get(c);                                  ///Lee cada caracter del archivo.
            if(!f.eof())                               ///Evita que el ultimo caracter se repita mas de lo necesario.
            cout<<c;                                   ///Muestra en panatalla el contenido del archivo.
        }
        cout<<"\n\n"<<endl;
    }
    f.close();                                        ///Termina de trabajar con el archivo.
    cout<<"\nSi decea realizar otra tarea presione el numero correspondiente:";

}


///----------------------------------------------------------------------------------------------------------------///
///Función 2:


void codificacion ()
{
    char d[30],c,n[30];
    ifstream f;                                           ///Declara la variable "f" para el archivo original.
    ofstream a;                                           ///Declara la variable "a" para el nuevo archivo llamado "Codificado.txt".
    cout<<"(2)Ingrese Nombre del Archivo a Codificar:";
    cin>>n;                                               ///Se lee la variable que toma el nombre del archivo a codificar.
    f.open(n);                                            ///Abre el archivo original.
    if (f.fail())                                         ///Comprueba si el archivo falla o no existe y asigna una tarea según el caso.
    {   cout<<"\n\n\n              Archivo no existe"<<endl;
        cout<<""<<endl;
    }
    else
    {   cout<<"\nComo quiere que se llame su nuevo archivo codificado?\n(Considere extencion de archivo)\nNombre:";
        cin>>d;
        a.open(d);                         ///Abre el nuevo archivo donde se guardarán los nuevos datos codificados.
        cout<<""<<endl;
        cout<<"Su Archivo ha sido Codificado con exito! \nSe ha creado un nuevo archivo codificado con el nombre '"<<d<<"' en la misma direccion donde se encuentra el archivo original."<<endl;
        cout<<""<<endl;
        while(!f.eof())                                   ///Permite realizar la codificación desde el 1° caracter hasta el ultimo.
        {   f.get(c);                                     ///Lee cada caracter del archivo.
            c=c+10;                                       ///Le suma 10 a cada caracter (Codifica).
            if(!f.eof())                                  ///Evita que el ultimo caracter se repita mas de lo necesario.
            a<<c;                                        ///Coloca uno por uno a los nuevos caracteres codificados en el nuevo archivo "Codificado.txt".

        }
        a.close ();                                       ///Cierra el nuevo archivo.
    }
    f.close();                                            ///Termina de trabajar con el archivo original.
    cout<<"\nSi decea realizar otra tarea presione el numero correspondiente:";

}


///----------------------------------------------------------------------------------------------------------------///
///Función 3:


void decodificacion ()
{
    char d[30],c,n[30];
    ifstream f;                                                  ///Declara la variable "f" para el archivo a decodificar.
    ofstream a;                                                  ///Declara la variable "a" para el nuevo archivo llamado "Decodificado.txt".
    cout<<""<<endl;
    cout<<"(3)Ingrese Nombre del Archivo a Decodificar:";
    cin>>n;                                                      ///Se lee la variable que toma el nombre del archivo a decodificar.
    f.open(n);                                                   ///Abre el archivo a decodificar.
    if (f.fail())                                                ///Chequea que el archivo exista.
    {   cout<<"\n\n\n              Archivo no existe"<<endl;
        cout<<""<<endl;
    }
    else
    {   cout<<"\nComo quiere que se llame su nuevo archivo decodificado?\n(Considere extencion de archivo)\nNombre:";
        cin>>d;
        a.open(d);                             ///Abre el nuevo archivo donde se guardarán los datos decodificados.
        cout<<""<<endl;
        cout<<"Su Archivo ha sido Decodificado con exito! \nSe ha creado un nuevo archivo decodificado con el nombre '"<<d<<"' en la misma direccion donde se encuentra el archivo codificado."<<endl;
        cout<<""<<endl;
        while(!f.eof())                                         ///Permite realizar la codificación desde el 1° caracter hasta el ultimo.
        {   f.get(c);                                           ///Lee cada caracter del archivo.
            c=c-10;                                             ///Le resta 10 a cada caracter (Decodifica).
            if(!f.eof())                                        ///Evita que el ultimo caracter se repita mas de lo necesario.
            a<<c;                                               ///Coloca uno por uno a los nuevos caracteres decodificados en el nuevo archivo " Decodificado.txt".

        }
        a.close ();                                             ///Cierra el nuevo archivo.
        cout<<""<<endl;
    }
    f.close();                                                  ///Cierra archivo a decodificar.
    cout<<"\nSi decea realizar otra tarea presione el numero correspondiente:";
}


///----------------------------------------------------------------------------------------------------------------///
///Función 4

void forma()
{
cout<<"Codifiacion...\n\nLa forma de Codificacion es la siguiente: \n1.Al abrir el archivo, el programa empieza a leer caracter por caracter. \n2.A medida que va leyendo los caracteres va realizando la operacion:C+10  \nEn otras palabras, le va sumando 10 a cada caracter. \n"<<endl;
cout<<"Decodifiacion...\n\nLa forma de Decodificacion es la siguiente: \n1.Al abrir el archivo codificado, el programa empieza a leer caracter por caracter (Igual que en la Codificacion). \n2.A medida que va leyendo los caracteres va realizando la operacion:C-10  \nEn otras palabras, le va restando 10 a cada caracter. \nEsto es para que el archivo vuelva a ser lo que era antes, es como 'quitarle' los 10 que tenian los caracteres codificados. \n"<<endl;
cout<<"NOTA:\nLos archivos originales NO se los debe asignar para la tarea 'Decodificacion', si llega a realizar esta tarea , va a probocar una codificacion distinta a la pretendida por el programa, haciendole mas dificil el trabajo para usted mismo.";
cout<<"\n\n\nSi decea realizar otra tarea presione el numero correspondiente:";
}
