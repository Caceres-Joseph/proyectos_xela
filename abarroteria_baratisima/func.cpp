 
#include "func.h"
 

/**
 * Muestra un mensaje esperando que se presione una tecla
 */
void cualquierTecla()
{
    cout<<endl<<"Presione Enter para continuar ..."<<endl;
    cin.ignore();
    cin.get();
}

/**
 * Verificando si el número de entrada es válido
 * @return  Retorna un 1 si es correo, de lo contrario un cero
 */
int esNumeroEntrada(){

    if(cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Debe ingresar un número valido"<<endl;
        //cualquierTecla();
        return 0;
    }else{
        return 1;
    }
}

/**
 * Quita los espacioes de una cadena
 * @param str
 */
void f_quitarEspacios(char *str) 
{   
    int count = 0; 
   
    for (int i = 0; str[i]; i++) 
        if (str[i] != ' ') 
            str[count++] = str[i];  
                                    
    str[count] = '\0'; 
}

