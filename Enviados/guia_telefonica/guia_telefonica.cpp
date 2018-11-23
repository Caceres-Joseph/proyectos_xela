/**
 * =============================================================================
 *  FUNC
 * =============================================================================
 */ 

/**
 * ===================================
 *  HEADER FUNC
 * ===================================
 */ 
#include <cstdlib>
#include <iostream>
#include <list>
#include <string.h>
#include<limits>
#include <string>
 
// writing on a text file
#include <iostream>
#include <fstream>

//para tabular
#include <iomanip>
//espacios
#include <algorithm>
using namespace std;
 

void cualquierTecla();
int esNumeroEntrada();
void f_quitarEspacios(char *str) ;
/**
 * ===================================
 *  BODY FUNC
 * ===================================
 */ 


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



/**
 * =============================================================================
 *  DEPARTAMENTO
 * =============================================================================
 */ 

/**
 * ===================================
 *  HEADER DEPARTAMENTO
 * ===================================
 */ 
/**
 * Es la estructura que tiene un depa
 */
struct departamento { 
    
    //nombre 
    char nombre[255]; 
    //es cero si se elimina
    int estado;
};


/**
 * Metodos
 */
departamento *d_crear(char *nombre, int estado);

//obteniendo depa
departamento ds_getItem(int indice);

/**
 * ===================================
 *  BODY DEPARTAMENTO
 * ===================================
 */ 

 
 /**
  * 
  * @param nombre
  * @param estado
  * @return Retorna una estructura de tipo depa
  */
departamento *d_crear(char *nombre, int estado){
     
    departamento *nuevo=new departamento;
    strcpy(nuevo->nombre, nombre); 
    //estado activo
    nuevo->estado=estado;

    return nuevo;
}

 

/**
 * =============================================================================
 *  MUNICIPIO
 * =============================================================================
 */ 

/**
 * ===================================
 *  HEADER MUNICIPIO
 * ===================================
 */ 

/**
 * Es la estructura que tiene un municipio
 */
struct municipio {
    //nombre de la carrera
    char nombre[255];
    int idDepartamento;
    //es cero si se elimina
    int estado;
};


/**
 * Metodos
 */
municipio *m_crear(char *nombre,int idDepartamento ,int estado);

municipio ms_getItem(int indice);

//de donde pertenece
extern int mm_indice_departamento;

//de donde pertenece
extern int ms_indice_departamento;

/**
 * ===================================
 *  BODY MUNICIPIO
 * ===================================
 */ 

 
/**
 * Retorna una estructura con los datos indicados
 * @param nombre
 * @param estado
 * @return 
 */
municipio *m_crear(char *nombre,int idDepartamento,int estado){
     
    municipio *nuevo=new municipio;
    
    strcpy(nuevo->nombre, nombre);
    nuevo->estado=estado;
    nuevo->idDepartamento=idDepartamento;
    
    return nuevo;
}



/**
 * =============================================================================
 *  PERSONA
 * =============================================================================
 */ 

/**
 * ===================================
 *  HEADER PERSONA
 * ===================================
 */ 


/**
 * Es la estructura que tiene una persona
 */
struct persona {
    
    //datos del alumno
    char nombre[255];
    char apellido[255]; 
    int edad;
    int codigo;
    int telefono;
 
         
    int idDepartamento;
    int idMunicipio;
    
    //es cero si se elimina
    int estado;
};

/**
 * Metodos
 */
persona *p_crear(
        char *nombre,
        char *apellido,  
        int edad,
        int codigo,
        int telefono,
        
        int idDepartamento,
        int idMunicipio,
        int estado
        );


//de donde pertenece
extern int pm_indice_departamento;
extern int pm_indice_municipio;


/**
 * ===================================
 *  BODY PERSONA
 * ===================================
 */ 

 persona *p_crear(
        char *nombre,
        char *apellido,  
        int edad,
        int codigo,
        int telefono,
        
        int idDepartamento,
        int idMunicipio,
        int estado
        )
 {
     
    persona *nuevo=new persona;
     
    strcpy(nuevo->nombre, nombre);//copia la cadena
    strcpy(nuevo->apellido, apellido); 
    
    nuevo->edad=edad;
    nuevo->codigo=codigo;
    nuevo->telefono=telefono; 

    nuevo->idDepartamento=idDepartamento;
    nuevo->idMunicipio=idMunicipio;
    nuevo->estado=estado;
 
 }


/**
 * =============================================================================
 *  PERSONAS
 * =============================================================================
 */ 

/**
 * ===================================
 *  HEADER PERSONAS
 * ===================================
 */ 

void ps_menu_crear();
void ps_insertar(
        char *nombre,
        char *apellido,  
        int edad,
        int codigo,
        int telefono,
        
        int idDepartamento,
        int idMunicipio,
        int estado
        );
void ps_menu_mostrar();
void ps_menu_modificar();
void ps_menu_eliminar();

//funciones
void ps_mlista();
void ps_lstEncabezado();

//lectura y escritura del archivo
void ps_leer(); 
void ps_escribir(
        char *nombre,
        char *apellido,  
        int edad,
        int codigo,
        int telefono,
        
        int idDepartamento,
        int idMunicipio,
        int estado
        );
void ps_actualizar_archivo();

//arreglo  
extern persona *ps_lista[500];

//indica cual es la ultima posicion libre del arreglo 
extern int ps_indice;
 

//funcioen extras
void ps_buscar();
void ps_listaGeneral(); 
void ps_listaGeneralDepartamento(int idDepartamento);
 
extern string ps_nombreArchivo;
/**
 * ===================================
 *  BODY PERSONAS
 * ===================================
 */ 

/**
 * Variables
 */
int ps_indice=0;
persona *ps_lista[500];

 

string ps_nombreArchivo="personas.txt";

/**
 *Menu en el que se puede crear 
 *
 */
void ps_menu_crear(){
    //Limpiando la cosola
    cout << string( 100, '\n' );

    
    //primero pedimos el nombre de la persona
    cout << "+------------------------+"<<endl;
    cout << "| Nueva persona          |"<<endl;
    cout << "+------------------------+"<<endl;
    cout << "| Departamento: "<<ds_getItem(pm_indice_departamento).nombre<<endl;
    cout << "| Municipio: "<<ms_getItem(pm_indice_municipio).nombre<<endl<<endl;


    cout << "Ingrese el nombre de la persona:"<<endl;
    //guardando el nombre de la persona
    char nombre[250];
    cin>>nombre;

    cout<<endl << "Ingrese el apellido de la persona:"<<endl;
    //guardando el nombre de la persona
    char apellido[250];
    cin>>apellido;

  

    cout<<endl << "Ingrese la edad:"<<endl;
    int edad=0;
    cin>>edad;


    cout <<endl<< "Ingrese el codigo:"<<endl;
    int codigo=0;
    cin>>codigo;


    cout <<endl<< "Ingrese el teléfono:"<<endl;
    int telefono=0;
    cin>>telefono;
 


 
    int estado=1;
    
    //insertando el dato
    ps_insertar(nombre,
            apellido, 
            edad,
            codigo,
            telefono, 

            pm_indice_departamento,
            pm_indice_municipio,

            estado
            );
    
    //escribiendo en el archivo
    ps_escribir(nombre,
            apellido, 
            edad,
            codigo,
            telefono, 

            pm_indice_departamento,
            pm_indice_municipio,

            estado
            );
    
    //mensaje de éxito
    cout<<endl << "Persona guardada con éxito." <<endl;
}



/**
 * Despliega la lista con un encabezado
 */
void ps_menu_mostrar()
{

    //Limpiando la cosola
    cout << string( 100, '\n' );

    cout << "+--------------------------+"<<endl;
    cout << "|  Lista de Personas       | "<<endl;
    cout << "+--------------------------+"<<endl;
    cout << "| Departamento: "<<ds_getItem(pm_indice_departamento).nombre<<endl;
    cout << "| Municipio: "<<ms_getItem(pm_indice_municipio).nombre<<endl<<endl;

    ps_mlista();
}

/**
 * Modifica un item
 */
void ps_menu_modificar()
{

    //Limpiando la cosola
    cout << string( 100, '\n' );

    //primero pedimos el nombre del persona
    cout << "+---------------------------+"<<endl;
    cout << "| Modificar persona         |"<<endl;
    cout << "+---------------------------+"<<endl;
    cout << "| Departamento: "<<ds_getItem(pm_indice_departamento).nombre<<endl;
    cout << "| Municipio: "<<ms_getItem(pm_indice_municipio).nombre<<endl<<endl;

    //indice que se va modificar
    int indiceSeleccionado=-1;

    //mostrando la lista de personas
    ps_mlista();
    cout<<endl<<"Seleccione la persona:"<<endl;
    cin>>indiceSeleccionado;

    
    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        ps_menu_modificar();
        return;
    }
    
    //validando si se encuentra entre el rango
    if(indiceSeleccionado<ps_indice&&indiceSeleccionado>=0)
    {
        
        persona *est=ps_lista[indiceSeleccionado];
        char respuesta;
        
        //Nombre
        char nombre[250];
        cout<<endl<< "Desea modificar el nombre (s/n)?"<<endl;
        cin>>respuesta;
        if(respuesta=='s'||respuesta=='S'){
            cout << "Ingrese el nuevo nombre de la persona:"<<endl;
            cin>>nombre;
            strcpy(est->nombre, nombre);
        }


        //Modificando apellido
        char apellido[250];
        cout<<endl<< "Desea modificar el apellido (s/n)?"<<endl;
        cin>>respuesta;
        if(respuesta=='s'||respuesta=='S'){
            cout << "Ingrese el nuevo apellido de la persona:"<<endl;
            cin>>apellido;
            strcpy(est->apellido, apellido);
        }

 
 



        //Modificando edad
        int edad=0;
        cout<<endl<< "Desea modificar la edad (s/n)?"<<endl;
        cin>>respuesta;
        if(respuesta=='s'||respuesta=='S'){
            cout << "Ingrese la nueva edad:"<<endl;
            cin>>edad;
            est->edad=edad;
        }

        //mdificando codigo
        int codigo=0;
        cout<<endl<< "Desea modificar el codigo (s/n)?"<<endl;
        cin>>respuesta;
        if(respuesta=='s'||respuesta=='S'){
            cout << "Ingrese el nuevo  codigo:"<<endl;
            cin>>codigo;
            est->codigo=codigo;
        }


        //modificando telefono
        int telefono=0;
        cout<<endl<< "Desea modificar el teléfono (s/n)?"<<endl;
        cin>>respuesta;
        if(respuesta=='s'||respuesta=='S'){
            cout << "Ingrese el nuevo teléfono:"<<endl;
            cin>>telefono;
            est->telefono=telefono;
        }
 
        //actualizando el archivo
        ps_actualizar_archivo();

        cout<<"Persona modificada"<<endl;
    }else
    {
        cout<<"El indice seleccionado es incorrecto.";
        cualquierTecla();
        ps_menu_modificar();
    }
      
}
/**
 * Elimina un item
 */
void ps_menu_eliminar(){
    
    //Limpiando la cosola
    cout << string( 100, '\n' );

    //primero pedimos el nombre del persona
    cout << "+----------------------------"<<endl;
    cout << "| Eliminar una persona    |"<<endl;
    cout << "+----------------------------"<<endl<<endl;
    cout << "| Departamento: "<<ds_getItem(pm_indice_departamento).nombre<<endl;
    cout << "| Municipio: "<<ms_getItem(pm_indice_municipio).nombre<<endl<<endl;

    //indice que se va eliminar
    int indiceSeleccionado=-1;

    //mostrando la lista de secciones
    ps_mlista();
    cout<<endl<<"Seleccione la persona a eliminar:"<<endl;
    cin>>indiceSeleccionado;

    
    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        ps_menu_eliminar();
        return;
    }
    
    //validando si se encuentra entre el rango
    if(indiceSeleccionado<ps_indice&&indiceSeleccionado>=0)
    {
        
        persona *est=ps_lista[indiceSeleccionado];
        est->estado=0;
        
        
        //actualizando el archivo
        ps_actualizar_archivo();
         
        cout<<endl<<"Persona eliminada"<<endl;
    }else
    {
        cout<<"El indice seleccionado es incorrecto.";
        cualquierTecla();
        ps_menu_eliminar();
    }
    
}

/**
 * Muestra lo que hay en el arreglo
 */
void ps_lstEncabezado(){
    
    cout << setw(20) << left;
    cout << "Nombre";
    cout << setw(20) << left;
    cout << "Apellido";  
    cout << setw(10) << left;
    cout << "Edad";
    cout << setw(20) << left;
    cout << "Codigo";
    cout << setw(10) << left;
    cout << "Telefono"<<endl; 
    
    
    cout << setw(20) << left;
    cout << "---------";
    cout << setw(20) << left;
    cout << "---------";
    cout << setw(10) << left;
    cout << "---------";
    cout << setw(20) << left;
    cout << "---------";
    cout << setw(10) << left;
    cout << "---------"<<endl; 
}
void ps_mlista() {
 
    ps_lstEncabezado();
 

    int indice=0;
    for (size_t i = 0; i < ps_indice; i++) {
        persona *est = ps_lista[i]; 
        //filtrando que este activo y pertenezca al id
        if ((est->estado)&&(est->idDepartamento==pm_indice_departamento)&&(est->idMunicipio==pm_indice_municipio)) {

            
            cout<<indice<<") ";
            cout << setw(17) << left;
            cout << est->nombre;
            cout << setw(20) << left;
            cout << est->apellido;  
            cout << setw(10) << left;
            cout << est->edad;
            cout << setw(20) << left;
            cout << est->codigo;
            cout << setw(10) << left;
            cout << est->telefono<<endl; 
     
        }
        indice++;
    }
}
 
void ps_insertar(
        char *nombre,
        char *apellido,  
        int edad,
        int codigo,
        int telefono,
        
        int idDepartamento,
        int idMunicipio,
        int estado
        )
{
    
    //creando y guardando 
    
    ps_lista[ps_indice]=p_crear(nombre,
            apellido,
            edad,
            codigo,
            telefono,

            idDepartamento,
            idMunicipio,

            estado
            );
    
    ps_indice++; //incrementando el indice
  
}


/*
+----------------------------------------------------+
|   Escritura Lectura
+----------------------------------------------------+
*/
//escribe lo que hay en el arreglo en el archivo
void ps_actualizar_archivo()
{
    //limpiando el archivo
    ofstream myfile (ps_nombreArchivo);
    if (myfile.is_open()) { 
        myfile.close();
    } 

    for (size_t i = 0; i < ps_indice; i++) {
        persona *est = ps_lista[i];
        //escribiendo en el archivo
        ps_escribir(
                est->nombre,
                est->apellido, 
                est->edad,
                est->codigo,
                est->telefono, 

                est->idDepartamento,
                est->idMunicipio,

                est->estado
                );

    }
}

/**
 * Carga el archivo al inicio
 */
void ps_leer() {
    string line;
    ifstream myfile(ps_nombreArchivo);
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            
            

            //nombre
            string sNombre = line.substr(0, 49);
            char *nombre = &sNombre[0];
            f_quitarEspacios(nombre); 
            
            //apellido
            string sApellido = line.substr(50, 49);
            char *apellido = &sApellido[0];
            f_quitarEspacios(apellido); 
             
            
            ///edad
            string sEdad = line.substr(100, 49);
            char *tEdad = &sEdad[0];
            f_quitarEspacios(tEdad);
            double edad = stod(tEdad);
            
            
            ///codigo
            string sCodigo = line.substr(150, 49);
            char *tCodigo = &sCodigo[0];
            f_quitarEspacios(tCodigo);
            double codigo = stod(tCodigo);
            
            
            ///telefono
            string sTel = line.substr(200, 49);
            char *tTel = &sTel[0];
            f_quitarEspacios(tTel);
            double telefono = stod(tTel);
            
             
            
            ///idDepartamento
            string sIdDepartamento = line.substr(250, 49);
            char *tIdDepartamento = &sIdDepartamento[0];
            f_quitarEspacios(tIdDepartamento);
            double idDepartamento = stod(tIdDepartamento);
            
            
            ///idMunicipio
            string sIdMunicipio = line.substr(300, 49);
            char *tIdMunicipio = &sIdMunicipio[0];
            f_quitarEspacios(tIdMunicipio);
            double idMunicipio = stod(tIdMunicipio);
 
 
            ///estado
            string sEstado = line.substr(350, 49);
            char *tEstado = &sEstado[0];
            f_quitarEspacios(tEstado);
            double estado = stod(tEstado);


            //insertando el dato
            ps_insertar(nombre,
                    apellido, 
                    edad,
                    codigo,
                    telefono, 

                    idDepartamento,
                    idMunicipio,

                    estado
                    ); 
        }
        myfile.close();
    }

}
/**
 * Escribe los datos en el archivo de texto
 * @param nombre
 * @param precio
 */
void ps_escribir(
        char *nombre,
        char *apellido,  
        int edad,
        int codigo,
        int telefono,
        
        int idDepartamento,
        int idMunicipio,
        int estado
        ) {


    //abriendo un archivo y agregando contenido
    ofstream myfile(ps_nombreArchivo, std::ofstream::app);
    if (myfile.is_open()) {

        myfile << setw(50) << left;
        myfile << nombre;
        
        myfile << setw(50) << left;
        myfile << apellido;
         
        
        myfile << setw(50) << left;
        myfile << edad;
        
        myfile << setw(50) << left;
        myfile << codigo;
        
        myfile << setw(50) << left;
        myfile << telefono;
         
        
        myfile << setw(50) << left;
        myfile << idDepartamento;
        
        myfile << setw(50) << left;
        myfile << idMunicipio; 
        
        myfile << setw(50) << left;
        myfile << estado << endl;
        myfile.close();
    } else {
        cout << "No se pudo abrir el archivo" << endl;
    }
}
 
/**
 * Busca item por codigo
 * @param codigo
 */
void ps_buscar()
{
    
    //Limpiando la cosola
    cout << string( 100, '\n' );

    cout << "+--------------------------+"<<endl;
    cout << "| Personas                 | "<<endl;
    cout << "+--------------------------+"<<endl;
    cout << "| Buscando persona: "<<endl<<endl;

    
    
    //indice que se va eliminar
    int codigo=-1; 
    cout<<endl<<"Escriba el código para buscar:"<<endl;
    cin>>codigo;

    
    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        ps_buscar();
        return;
    }
    
     
    cout << setw(20) << left;
    cout << "Nombre";
    cout << setw(20) << left;
    cout << "Apellido";
    cout << setw(20) << left;
    cout << "Departamento";
    cout << setw(20) << left;
    cout << "Municipio"<<endl;
    
    
    
    cout << setw(20) << left;
    cout << "---------";
    cout << setw(20) << left;
    cout << "---------"; 
    cout << setw(20) << left;
    cout << "---------"; 
    cout << setw(20) << left;
    cout << "---------"<<endl;
    
    
    int indice=0;
    for (size_t i = 0; i < ps_indice; i++) {
        persona *est = ps_lista[i]; 
        //filtrando que este activo y pertenezca al id
        if ((est->estado)&&(est->codigo==codigo)) {
 
            cout<<indice<<") ";
            cout << setw(17) << left;
            cout << est->nombre;
            cout << setw(20) << left;
            cout << est->apellido; 
            cout << setw(20) << left;
            cout << ds_getItem(est->idDepartamento).nombre;
            cout << setw(20) << left;
            cout << ms_getItem(est->idMunicipio).nombre<<endl; 
        }
        indice++;
    }
}
  
/**
 *
 * @param listaGeneral
 */
void ps_listaGeneral()
{
    
    //Limpiando la cosola
    cout << string( 100, '\n' );

    cout << "+----------------------------------------------+"<<endl;
    cout << "| Listado General de Personas                  |"<<endl;
    cout << "+----------------------------------------------+"<<endl;
    cout << "| Por dpto. y municipio "<<endl<<endl;

     
    
     
    int indice=0;
    int idDepartamento=-1;
    int idMunicipio=-1;
    for (size_t i = 0; i < ps_indice; i++) {
        persona *est = ps_lista[i]; 
        //filtrando que este activo y pertenezca al id
        if ((est->estado)) {
 
            if(idDepartamento!=est->idDepartamento){
                 
                cout << "+----------------------"<<endl;
                cout << "|Departamento: "<<ds_getItem(est->idDepartamento).nombre<<endl;
                cout << "+----------------------"<<endl; 
                 
                //ps_lstEncabezado(); 
                idDepartamento=est->idDepartamento;
            }
            
            if(idMunicipio!=est->idMunicipio){
                cout << "+-----------"<<endl;
                cout << "|Municipio: "<<ms_getItem(est->idMunicipio).nombre<<endl;
                cout << "+-----------"<<endl<<endl; 
                ps_lstEncabezado(); 
                idMunicipio=est->idMunicipio;
            }
            
             
            cout<<indice<<") ";
            cout << setw(17) << left;
            cout << est->nombre;
            cout << setw(20) << left;
            cout << est->apellido; 
            cout << setw(10) << left;
            cout << est->edad;
            cout << setw(20) << left;
            cout << est->codigo;
            cout << setw(10) << left;
            cout << est->telefono<<endl;
        }
        indice++;
    }
}



/**
 *
 * @param noAprobados
 */
void ps_listaGeneralDepartamento(int idDepartamento)
{
    
    //Limpiando la cosola
    cout << string( 100, '\n' );

    cout << "+----------------------------------------------+"<<endl;
    cout << "| Listado de Personas                          |"<<endl;
    cout << "+----------------------------------------------+"<<endl;
    cout << "| Del departamento de  "<< ds_getItem(idDepartamento).nombre<<endl<<endl;

      
    int indice=0; 
    int idMunicipio=-1;
    for (size_t i = 0; i < ps_indice; i++) {
        persona *est = ps_lista[i]; 
        //filtrando que este activo y pertenezca al id
        if ((est->estado)&&(est->idDepartamento)==idDepartamento) {
 
         
            if(idMunicipio!=est->idMunicipio){
                cout << "+-----------"<<endl;
                cout << "|Municipio: "<<ms_getItem(est->idMunicipio).nombre<<endl;
                cout << "+-----------"<<endl<<endl; 
                ps_lstEncabezado(); 
                idMunicipio=est->idMunicipio;
            }
            
             
            cout<<indice<<") ";
            cout << setw(17) << left;
            cout << est->nombre;
            cout << setw(20) << left;
            cout << est->apellido; 
            cout << setw(10) << left;
            cout << est->edad;
            cout << setw(20) << left;
            cout << est->codigo;
            cout << setw(10) << left;
            cout << est->telefono<<endl; 
        }
        indice++;
    }
}

 


/**
 * =============================================================================
 *  PERSONAS_MENU
 * =============================================================================
 */ 

/**
 * ===================================
 *  HEADER PERSONAS_MENU
 * ===================================
 */ 
void pm_menu(int idDepartamento, int idMunicipio); 



/**
 * ===================================
 *  BODY PERSONAS_MENU
 * ===================================
 */ 


/**
 * Variables
 */
int pm_indice_departamento=-1;
int pm_indice_municipio=-1;

/**
 * Menu de opciones  
 */

void pm_menu(int idDepartamento, int idMunicipio)
{
    pm_indice_departamento=idDepartamento;
    pm_indice_municipio=idMunicipio;
    
    //limpiando la pantalla
    cout << string( 100, '\n' );


    //Para guardar la opcion que seleccionó
    int opcionSeleccionada=0;


    cout << "+----------------------+"<<endl;
    cout << "| Personas             |"<<endl;
    cout << "+----------------------+"<<endl;
    cout << "| Departamento: "<<ds_getItem(pm_indice_departamento).nombre<<endl;
    cout << "| Municipio: "<<ms_getItem(pm_indice_municipio).nombre<<endl<<endl;

    cout << "0. Salir."<<endl;
    cout << "1. Mostrar personas"<<endl;
    cout << "2. Crear una nueva persona."<<endl;
    cout << "3. Modificar una persona."<<endl;
    cout << "4. Eliminar una persona"<<endl<<endl<<endl<<endl<<endl<<endl;

    cin >> opcionSeleccionada;
 
    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        pm_menu(idDepartamento,idMunicipio);
        return;
    }

    
    
    switch (opcionSeleccionada)
    {
    case 0:
        return;
    case 1:
        ps_menu_mostrar();
        break;
    case 2:
        ps_menu_crear(); 
        break;
    case 3:
        if(!ps_indice==0){
            ps_menu_modificar(); 
        }else{
            cout<<"No hay personas"<<endl;
        }

        break;
    case 4:
        if(!ps_indice==0){
            ps_menu_eliminar(); 
        }else{
            cout<<"No hay personas"<<endl;
        }
        break;
    default:
        cout<<"Opcion incorrecta"<<endl;

        break;
    }

    cualquierTecla();
    pm_menu(idDepartamento,idMunicipio);


}

 
/**
 * =============================================================================
 *  MUNICIPIOS
 * =============================================================================
 */ 

/**
 * ===================================
 *  HEADER MUNICIPIOS
 * ===================================
 */ 

//Para muni
void ms_menu_crear();
void ms_insertar(char *nombre, int idDepartamento, int estado);
void ms_menu_mostrar();
void ms_menu_modificar();
void ms_menu_eliminar();

//funciones
void ms_mlista();


//lectura y escritura del archivo
void ms_leer(); 
void ms_escribir(char *nombre, int idDepartamento, int estado);
void ms_actualizar_archivo();

//arreglo de municipios 
extern municipio *ms_lista[500];

//indica cual es la ultima posicion libre del arreglo 
extern int ms_indice;


extern string ms_nombreArchivo;



//para parsona
void ms_menu_persona();


/**
 * ===================================
 *  BODY MUNICIPIOS
 * ===================================
 */ 


/**
 * Variables
 */
int ms_indice=0;
municipio *ms_lista[500];
int ms_indice_departamento=-1;

string ms_nombreArchivo="municipios.txt";
/**
 *Menu en el que se puede crear un nuevo municipio
 *
 */

void ms_menu_crear(){
    //Limpiando la cosola
    cout << string( 100, '\n' );

    //primero pedimos el nombre del municipio
    cout << "+------------------------+"<<endl;
    cout << "| Nuevo Municipio        | "<<endl;
    cout << "+------------------------+"<<endl;
    cout << "| Departamento: "<<ds_getItem(mm_indice_departamento).nombre<<endl<<endl;


    cout << " Ingrese el nombre de la municipio."<<endl<<endl;


    //guardando el nombre del nuevo  municipio
    char nombre[250];
    cin>>nombre;
 
    int estado=1;
    
    //insertando el dato
    ms_insertar(nombre, mm_indice_departamento, estado);
    
    //escribiendo en el archivo
    ms_escribir(nombre, mm_indice_departamento, estado);
    
    //mensaje de éxito
    cout<<endl<< "Municipio " << nombre <<" creado con éxito." <<endl;
}

void ms_insertar(char *nombre, int idDepartamento, int estado){
    
    //creando y guardando
    
    ms_lista[ms_indice]=m_crear(nombre,idDepartamento, estado);
    
    ms_indice++; //incrementando el indice
  
}


/**
 * Despliega la lista con un encabezado
 */
void ms_menu_mostrar()
{

    //Limpiando la cosola
    cout << string( 100, '\n' );

    cout << "+--------------------------+"<<endl;
    cout << "| Lista de Municipios       |"<<endl;
    cout << "+--------------------------+"<<endl;
    cout << "| Departamento: "<<ds_getItem(mm_indice_departamento).nombre<<endl<<endl;

    ms_mlista();
}


/**
 * Modifica un item
 */
void ms_menu_modificar()
{

    //Limpiando la cosola
    cout << string( 100, '\n' );

    //primero pedimos el nombre del municipio
    cout << "+---------------------------+"<<endl;
    cout << "| Modificar Municipio       |"<<endl;
    cout << "+---------------------------+"<<endl;
    cout << "| Departamento: "<<ds_getItem(mm_indice_departamento).nombre<<endl<<endl;

    //indice que se va eliminar
    int indiceSeleccionado=-1;

    //mostrando la lista 
    ms_mlista();
    cout<<"Seleccione el municipio:"<<endl;
    cin>>indiceSeleccionado;

    
    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        ms_menu_modificar();
        return;
    }
    
    //validando si se encuentra entre el rango
    if(indiceSeleccionado<ms_indice&&indiceSeleccionado>=0)
    {
        
        municipio *sec=ms_lista[indiceSeleccionado];
         
        cout<<endl<<"Ingrese el nuevo nombre del municipio:"<<endl;
        char nombre[250];
        cin>>nombre;

 
        //modificando el nombre del carrera
        strcpy(sec->nombre, nombre);
        
        
        //actualizando el archivo
        ms_actualizar_archivo();

        cout<<endl<<"Municipio modificado"<<endl;
    }else
    {
        cout<<"El indice seleccionado es incorrecto.";
        cualquierTecla();
        ms_menu_modificar();
    }
      
}
/**
 * Elimina un item
 */
void ms_menu_eliminar(){
    

    //Limpiando la cosola
    cout << string( 100, '\n' );

    //primero pedimos el nombre del municipio
    cout << "+--------------------------+"<<endl;
    cout << "| Eliminar Municipio       | "<<endl;
    cout << "+--------------------------+"<<endl;
    cout << "| Departamento: "<<ds_getItem(mm_indice_departamento).nombre<<endl<<endl;

    //indice que se va eliminar
    int indiceSeleccionado=-1;

    //mostrando la lista 
    ms_mlista();
    cout<<"Seleccione el municipio:"<<endl;
    cin>>indiceSeleccionado;

    
    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        ms_menu_eliminar();
        return;
    }
    
    //validando si se encuentra entre el rango
    if(indiceSeleccionado<ms_indice&&indiceSeleccionado>=0)
    {
        
        municipio *sec=ms_lista[indiceSeleccionado];
        sec->estado=0;
        
        
        //actualizando el archivo
        ms_actualizar_archivo();
        
        
        cout<<"Municipio eliminado"<<endl;
    }else
    {
        cout<<"El indice seleccionado es incorrecto.";
        cualquierTecla();
        ms_menu_eliminar();
    }
    
}
/**
 * Muestra lo que hay en el arreglo
 */
void ms_mlista() {
 
    cout << setw(30) << left;
    cout << "Nombre: " << endl;
 
    cout << setw(30) << left;
    cout << "--------------------" << endl;


    int indice=0;
    for (size_t i = 0; i < ms_indice; i++) {
        municipio *sec = ms_lista[i]; 
        //filtrando que este activo y pertenezca al id
        if ((sec->estado)&&(sec->idDepartamento==mm_indice_departamento)) {
//        if ((sec->estado)) {
            cout<<indice<<") ";
            cout << setw(30) << left;
            cout << sec->nombre<<endl; 
        }
        indice++;
    }
}


/*
+----------------------------------------------------+
|   Escritura Lectura
+----------------------------------------------------+
*/

//escribe lo que hay en el arreglo en el archivo
void ms_actualizar_archivo()
{
    //limpiando el archivo
    ofstream myfile (ms_nombreArchivo);
    if (myfile.is_open()) { 
        myfile.close();
    } 
    
    for (size_t i = 0; i < ms_indice; i++) {
        municipio *sec = ms_lista[i]; 
        ms_escribir(sec->nombre, sec->idDepartamento, sec->estado);
    }
}
/**
 * Carga el archivo al inicio
 */
void ms_leer() {
    string line;
    ifstream myfile(ms_nombreArchivo);
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            
            

            //nombre
            string sNombre = line.substr(0, 49);
            char *tNombre = &sNombre[0];
            f_quitarEspacios(tNombre); 

            
            ///idDepartamento
            string sIdDepartamento = line.substr(50, 49);
            char *tIdDepartamento = &sIdDepartamento[0];
            f_quitarEspacios(tIdDepartamento);
            double idDepartamento = stod(tIdDepartamento);
 


            
            ///estado
            string sEstado = line.substr(100, 49);
            char *tEstado = &sEstado[0];
            f_quitarEspacios(tEstado);
            double estado = stod(tEstado);


            //insertando el dato
            ms_insertar(tNombre, idDepartamento, estado);
        }
        myfile.close();
    }

}

/**
 * Escribe los datos en el archivo de texto
 * @param nombre 
 */
void ms_escribir(char *nombre, int idDepartamento, int estado) {


    //abriendo un archivo y agregando contenido
    ofstream myfile(ms_nombreArchivo, std::ofstream::app);
    if (myfile.is_open()) {

        myfile << setw(50) << left;
        myfile << nombre;
        myfile << setw(50) << left;
        myfile << idDepartamento;
        myfile << setw(50) << left;
        myfile << estado << endl;
        myfile.close();
    } else {
        cout << "No se pudo abrir el archivo" << endl;
    }

}
 /*
+----------------------------------------------------+
|   Funciones
+----------------------------------------------------+
*/

/**
 * Devuelve la estructura del tipo 
 */
municipio ms_getItem(int indice)
{
    municipio *sec = ms_lista[indice];  
    return *sec;
}

/*
+----------------------------------------------------+
|   Menu Estudiante
+----------------------------------------------------+
*/

void ms_menu_persona()
{
    //limpiando la pantalla
    cout << string( 100, '\n' );
 

    cout << "+----------------------+"<<endl;
    cout << "| Persona           | "<<endl;
    cout << "+----------------------+"<<endl;
    cout << "| Departamento: "<<ds_getItem(mm_indice_departamento).nombre<<endl<<endl;
    
    //indice que se va eliminar
    int indiceSeleccionado=-1;

    //mostrando la lista 
    ms_mlista();
    cout<<endl<<"Seleccione el municipio:"<<endl;
    cin>>indiceSeleccionado;

    
    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        ms_menu_persona(); 
        return;
    }
    
    //validando si se encuentra entre el rango
    if(indiceSeleccionado<ms_indice&&indiceSeleccionado>=0)
    {
        
        //desplegando el otro menu
        
        pm_menu(mm_indice_departamento, indiceSeleccionado);
    }else
    {
        cout<<"El indice seleccionado es incorrecto.";
        cualquierTecla();
        ms_menu_persona();
    }
}

/**
 * =============================================================================
 *  MUNICIPIOS_MENU
 * =============================================================================
 */ 

/**
 * ===================================
 *  HEADER MUNICIPIOS_MENU
 * ===================================
 */ 
void mm_menu(int indice);
void mm_menu_persona(int indice);


/**
 * ===================================
 *  BODY MUNICIPIOS_MENU
 * ===================================
 */ 

/**
 * Variables
 */
int mm_indice_departamento=-1;
 
/**
 * Menu de opciones 
 */
void mm_menu(int indice){
    mm_indice_departamento=indice;
    
    //limpiando la pantalla
    cout << string( 100, '\n' );


    //Para guardar la opcion que seleccionó
    int opcionSeleccionada=0;
 
    cout << "+----------------------+"<<endl;
    cout << "| Municipios           |"<<endl;
    cout << "+----------------------+"<<endl;
    cout << "| Departamento: "<<ds_getItem(mm_indice_departamento).nombre<<endl<<endl;

    
    cout << "0. Salir."<<endl;
    cout << "1. Mostrar municipios."<<endl;
    cout << "2. Crear un nuevo municipio."<<endl;
    cout << "3. Modificar un municipio."<<endl;
    cout << "4. Eliminar un municipio."<<endl<<endl<<endl<<endl<<endl<<endl;
    cin >> opcionSeleccionada;


    
    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        mm_menu(indice);
        return;
    }

    
    
    switch (opcionSeleccionada)
    {
    case 0:
        return;
    case 1:
        ms_menu_mostrar();
        break;
    case 2:
        ms_menu_crear(); 
        break;
    case 3:
        if(!ms_indice==0){
            ms_menu_modificar(); 
        }else{
            cout<<"No hay municipios"<<endl;
        }

        break;
    case 4:
        if(!ms_indice==0){
            ms_menu_eliminar(); 
        }else{
            cout<<"No hay municipios"<<endl;
        } 
        break;
    default:
        cout<<"Opcion incorrecta"<<endl; 
        break;
    }

    cualquierTecla();
    mm_menu(indice);


}

void mm_menu_persona(int indice)
{
    mm_indice_departamento=indice;
    
    //limpiando la pantalla
    cout << string( 100, '\n' );


    //Para guardar la opcion que seleccionó
    int opcionSeleccionada=0;



    cout << "+----------------------+"<<endl;
    cout << "| Persona              | "<<endl;
    cout << "+----------------------+"<<endl;
    cout << "| Departamento: "<<ds_getItem(mm_indice_departamento).nombre<<endl<<endl;
    cout << " Seleccione una opción por favor."<<endl<<endl;

    
    cout << "0. Salir."<<endl;
    cout << "1. Seleccionar un municipio"<<endl;
    cout << "2. Lista de personas de: "<<ds_getItem(mm_indice_departamento).nombre<<endl<<endl<<endl<<endl<<endl<<endl;

    
    
    cin >> opcionSeleccionada;

    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        mm_menu_persona(indice);
        return;
    }
 
    switch (opcionSeleccionada)
    {
    case 0:
        return;
    case 1:
        
        if(!ms_indice==0){
            ms_menu_persona(); 
        }else{
            cout<<"No hay secciones"<<endl;
        }  
        break;
        
    case 2:
        
        if(!ms_indice==0){
            ps_listaGeneralDepartamento(mm_indice_departamento);
        }else{
            cout<<"No hay secciones"<<endl;
        }  
        break;
    default:
        cout<<"Opcion incorrecta"<<endl;

        break;
    }
    
    cualquierTecla();
    mm_menu_persona(indice); 
}

 

/**
 * =============================================================================
 *  DEPARTAMENTOS
 * =============================================================================
 */ 

/**
 * ===================================
 *  HEADER DEPARTAMENTOS
 * ===================================
 */ 
//Para depas
void ds_menu_crear();
void ds_insertar(char *nombre,int estado);
void ds_menu_mostrar();
void ds_menu_modificar();
void ds_menu_eliminar();

//funciones
void ds_mlista();

//lectura y escritura del archivo
void ds_leer(); 
void ds_escribir(char *nombre, int estado);
void ds_insertar(char *nombre, int estado);

void ds_actualizar_archivo();

//arreglo de carreras 
extern departamento *ds_lista[500];

//indica cual es la ultima posicion libre del arreglo 
extern int ds_indice;



//Para la depa y alumnos
void ds_menu_municipio();
void ds_menu_persona();



extern string ds_nombreArchivo;
/**
 * ===================================
 *  BODY DEPARTAMENTOS
 * ===================================
 */ 

/**
 * Variables
 */
int ds_indice=0;
departamento *ds_lista[500];
string ds_nombreArchivo="departamentos.txt";
/**
 * Elimina un departamento
 */
void ds_menu_eliminar(){
    
    //Limpiando la cosola
    cout << string( 100, '\n' );

    //primero pedimos el nombre del departamento
    cout << "+--------------------------+"<<endl;
    cout << "| Eliminar un departamento |"<<endl;
    cout << "+--------------------------+"<<endl<<endl;

    //indice que se va eliminar
    int indiceSeleccionado=-1;

    //mostrando la lista de depas
    ds_mlista();
    cout<<endl<<"Seleccione el departamento a eliminar:"<<endl;
    cin>>indiceSeleccionado;

    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        ds_menu_eliminar();
        return;
    }
 
    //validando si se encuentra entre el rango
    if(indiceSeleccionado<ds_indice&&indiceSeleccionado>=0)
    {
        //se coloca el estado en cero para indicar que se eliminó
        departamento *dep=ds_lista[indiceSeleccionado];
        dep->estado=0;
        
        
        //actualizando el archivo
        ds_actualizar_archivo();
        
        
        cout<<"Departamento eliminado"<<endl;
    }else
    {
        cout<<"El indice seleccionado es incorrecto.";
        cualquierTecla();
        ds_menu_eliminar();
    }
}

/**
 * Modifica un departament
 */
void ds_menu_modificar()
{
    
    //Limpiando la cosola
    cout << string( 100, '\n' );

    //primero pedimos el nombre del departamento
    cout << "+---------------------------+"<<endl;
    cout << "| Modificar un departamento |"<<endl;
    cout << "+---------------------------+"<<endl<<endl;

    //indice que se va eliminar
    int indiceSeleccionado=-1;

    //mostrando la lista de carreras
    ds_mlista();
    cout<<endl<<"Seleccione el departamento:"<<endl;
    cin>>indiceSeleccionado;

    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        ds_menu_modificar();
        return;
    }
    
    
    //validando si se encuentra entre el rango
    if(indiceSeleccionado<ds_indice&&indiceSeleccionado>=0)
    {
        
        departamento *dep=ds_lista[indiceSeleccionado];
        
        
        
        cout<<endl<<"Ingrese el nuevo nombre del departamento:"<<endl;
        char nombre[250];
        cin>>nombre;
 
        strcpy(dep->nombre, nombre); 
        
        
        //actualizando el archivo
        ds_actualizar_archivo();

        cout<<"Departamento modificado"<<endl;
    }else
    {
        cout<<"El indice seleccionado es incorrecto.";
        cualquierTecla();
        ds_menu_modificar();
    }
     
}
/**
 *Menu en el que se puede crear un nuevo departamento
 *
 */
void ds_menu_crear(){
    //Limpiando la cosola
    cout << string( 100, '\n' );

    //primero pedimos el nombre del departamento
    cout << "+----------------------+"<<endl;
    cout << "| Nuevo Departamento   |"<<endl;
    cout << "+----------------------+"<<endl;
    
    cout <<endl<< "Ingrese el nombre del nuevo departamento:"<<endl;
    char nombre[250];
    cin>>nombre;
    
     
    
    int estado=1;
    
    //insertando el dato
    ds_insertar(nombre, estado);
    
    //escribiendo en el archivo
    ds_escribir(nombre, estado);
    
    //mensaje de éxito
    
    cout<<endl << "Departamento " << nombre <<" creado con éxito." <<endl; 
}

void ds_insertar(char *nombre,  int estado){
    
    //creando y guardando l 
    
    ds_lista[ds_indice]=d_crear(nombre, estado);
    
    ds_indice++; //incrementando el indice
  
}


/**
 * Despliega los departamentos con un encabezado
 */
void ds_menu_mostrar()
{

    //Limpiando la cosola
    cout << string( 100, '\n' );

    //primero pedimos el nombre del departamento
    cout << "+--------------------------+"<<endl;
    cout << "| Lista de Departamentos   |"<<endl;
    cout << "+--------------------------+"<<endl;
    
    
    ds_mlista();
}

/**
 * Muestra lo que hay en el arreglo
 */
void ds_mlista() {

     
    cout << setw(30) << left;
    cout << "Nombre"<<endl; 
 
    cout << setw(30) << left;
    cout << "--------------------" << endl;
 
    int indice=0;
    for (size_t i = 0; i < ds_indice; i++) {
        departamento *dep = ds_lista[i]; 
        if ((dep->estado)) {
            cout<<indice<<") ";
            cout << setw(30) << left;
            cout << dep->nombre<<endl; 
        }
        indice++;
    }
}

/*
+----------------------------------------------------+
|   Municipio
+----------------------------------------------------+
*/
/**
 * Menu para la depa
 */
void ds_menu_municipio(){
    
    //Limpiando la cosola
    cout << string( 100, '\n' );
 
    cout << "+-------------------------+"<<endl;
    cout << "| Municipios              |"<<endl;
    cout << "+-------------------------+"<<endl<<endl;

    //indice
    int indiceSeleccionado=-1;

    //mostrando la lista  
    ds_mlista();
    cout<<endl<<"Seleccione el departamento:"<<endl;
    cin>>indiceSeleccionado;

    //validando la entrada 
    if(!esNumeroEntrada()){
        ds_menu_municipio();
        return;
    }
    
    
    //validando si se encuentra entre el rango
    if(indiceSeleccionado<ds_indice&&indiceSeleccionado>=0)
    {
        
        //desplegando el otro menu
        mm_menu(indiceSeleccionado);
        
    }else
    {
        cout<<"El indice seleccionado es incorrecto.";
        cualquierTecla();
        ds_menu_municipio();
    }
    
}
/**
 * Menu para persona
 */
void ds_menu_persona()
{
    
    //Limpiando la cosola
    cout << string( 100, '\n' );
 
    cout << "+-------------------------+"<<endl;
    cout << "| Persona                 |"<<endl;
    cout << "+-------------------------+"<<endl<<endl;

    //indice  
    int indiceSeleccionado=-1;

    //mostrando la lista  
    ds_mlista();
    cout<<endl<<"Seleccione el departamento"<<endl;
    cin>>indiceSeleccionado;
    
    
    //validando la entrada 
    if(!esNumeroEntrada()){
        ds_menu_persona();
        return;
    }
    
    
    //validando si se encuentra entre el rango
    if(indiceSeleccionado<ds_indice&&indiceSeleccionado>=0)
    {
        
        //desplegando el otro menu
        mm_menu_persona(indiceSeleccionado);
        
         
    }else
    {
        cout<<"El indice seleccionado es incorrecto.";
        cualquierTecla();
        ds_menu_persona();
    }
}

/*
+----------------------------------------------------+
|   Funciones
+----------------------------------------------------+
*/

/**
 * Devuelve la estructura del tipo 
 */
departamento ds_getItem(int indice)
{
    departamento *dep = ds_lista[indice];
    return *dep;
}

/*
+----------------------------------------------------+
|   Escritura Lectura
+----------------------------------------------------+
*/

//escribe lo que hay en el arreglo en el archivo
void ds_actualizar_archivo()
{
    //limpiando el archivo
    ofstream myfile (ds_nombreArchivo);
    if (myfile.is_open()) { 
        myfile.close();
    } 
    
    for (size_t i = 0; i < ds_indice; i++) {
        departamento *carrera = ds_lista[i]; 
        ds_escribir(carrera->nombre, carrera->estado);
    }
}

/**
 * Escribe los datos en el archivo de texto
 * @param nombre 
 */

void ds_escribir(char *nombre, int estado) {
     
    //abriendo un archivo y agregando contenido
    ofstream myfile (ds_nombreArchivo, std::ofstream::app);
    if (myfile.is_open()) {
       
        myfile << setw(50)<<left;
        myfile << nombre; 
        myfile << setw(50)<<left;
        myfile << estado<<endl;
        
        myfile.close();
    }else{
        cout<<"No se pudo abrir el archivo"<<endl;
    }
     
}

/**
 * Carga la carreras al inicio
 */
void ds_leer() { 
    string line;
    ifstream myfile(ds_nombreArchivo);
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            
            
            //nombre
            string nombre = line.substr(0, 49);
            char *nombre2 = &nombre[0];
            f_quitarEspacios(nombre2);

 
            
            ///estado
            string sEstado = line.substr(50, 49);
            char *tEstado = &sEstado[0];
            f_quitarEspacios(tEstado);
            double estado = stod(tEstado);
             

            //insertando el dato
            ds_insertar(nombre2, estado);
             
        }
        myfile.close();
    }
     

}


/**
 * =============================================================================
 *  DEPARTAMENTOS_MENU
 * =============================================================================
 */ 

/**
 * ===================================
 *  HEADER DEPARTAMENTOS_MENU
 * ===================================
 */ 


void dm_menu();
void dm_menu_municipio();
void dm_menu_persona();

/**
 * ===================================
 *  BODY DEPARTAMENTOS_MENU
 * ===================================
 */ 


void dm_menu()
{

    //limpiando la pantalla
    cout << string( 100, '\n' );


    //Para guardar la opcion que seleccionó
    int opcionSeleccionada=0;


    cout << "+----------------------+"<<endl;
    cout << "| Departamentos        |"<<endl;
    cout << "+----------------------+"<<endl;
    cout << "| Seleccione una opción por favor."<<endl<<endl;

    cout << "0. Salir."<<endl;
    cout << "1. Mostrar departamentos."<<endl;
    cout << "2. Crear un nuevo departamento."<<endl;
    cout << "3. Modificar un departamento."<<endl;
    cout << "4. Eliminar un departamento."<<endl<<endl<<endl<<endl<<endl<<endl;
    cin >> opcionSeleccionada;


    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        dm_menu();
        return;
    }

    switch (opcionSeleccionada)
    {
    case 0:
        return;
    case 1:
        ds_menu_mostrar(); 
        break;
    case 2:  
        ds_menu_crear(); 
        break;
    case 3:
        
         if(!ds_indice==0){
             ds_menu_modificar();
        }else{
            cout<<"No hay departamentos registradas"<<endl;
        } 
        break;
    case 4:
        
         if(!ds_indice==0){
             ds_menu_eliminar();
        }else{
            cout<<"No hay departamentos registradas"<<endl;
        } 
        break;
    default:
        cout<<"Opcion incorrecta"<<endl; 
        break;
    }

    cualquierTecla();
    dm_menu();
 }

/**
 * Despliega un menu 
 */

void dm_menu_municipio()
{
    
    //limpiando la pantalla
    cout << string( 100, '\n' );


    //Para guardar la opcion que seleccionó
    int opcionSeleccionada=0;
 
    cout << "+----------------------+"<<endl;
    cout << "| Municipios           |"<<endl;
    cout << "+----------------------+"<<endl;
    cout << "| Seleccione una opción por favor."<<endl<<endl;

    cout << "0. Salir."<<endl;
    cout << "1. Seleccionar un departamento"<<endl<<endl<<endl<<endl<<endl<<endl;

    cin >> opcionSeleccionada;

    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        dm_menu_municipio();
        return;
    }
     
    switch (opcionSeleccionada)
    {
    case 0:
        return;
    case 1:
         if(!ds_indice==0){
             ds_menu_municipio();
        }else{
            cout<<"No hay carreras registradas"<<endl;
        }
        break;
    default:
        cout<<"Opcion incorrecta"<<endl; 
        break;
    }

    cualquierTecla();
    dm_menu_municipio();

}

/**
 * Menu para estudiantes
 */
void dm_menu_persona()
{
    
    //limpiando la pantalla
    cout << string( 100, '\n' );


    //Para guardar la opcion que seleccionó
    int opcionSeleccionada=0;
 
    cout << "+----------------------+"<<endl;
    cout << "| Persona              | "<<endl;
    cout << "+----------------------+"<<endl;
    cout << "| Seleccione una opción por favor."<<endl<<endl;

    cout << "0. Salir."<<endl;
    cout << "1. Seleccionar un departamento"<<endl;
    cout << "2. Lista general de personas"<<endl;
    cout << "3. Buscar persona por codigo"<<endl<<endl<<endl<<endl<<endl<<endl;
    
    cin >> opcionSeleccionada;


    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        dm_menu_persona();
        return;
    }

    switch (opcionSeleccionada)
    {
    case 0:
        return;
    case 1:
         
        if(!ds_indice==0){
            ds_menu_persona(); 
        }else{
            cout<<"No hay carreras registradas"<<endl;
        }
        break; 
    case 2:
        
        if(!ds_indice==0){
            ps_listaGeneral(); 
        }else{
            cout<<"No hay carreras registradas"<<endl;
        }
        break;
    case 3: 
        if(!ds_indice==0){
            ps_buscar(); 
        }else{
            cout<<"No hay carreras registradas"<<endl;
        }
        break;
    default:
        cout<<"Opcion incorrecta"<<endl; 
        break;
    }
    
    cualquierTecla();
    dm_menu_persona();
}



/**
 * =============================================================================
 *  PRINCIPAL
 * =============================================================================
 */ 
 
void cargandoArchivos(){
    ds_leer();
    ms_leer();
    ps_leer();
    
}


/**
 * Muestra el menú principal
 */
void menu_principal()
{

    //limpiando la pantalla
    cout << string( 100, '\n' );


    //Para guardar la opcion que seleccionó
    int opcionSeleccionada=0;



    cout << "********************************"<<endl;
    cout << "* GUIA TELEFONICA              *"<<endl;
    cout << "********************************"<<endl;


    cout << "+----------------------+"<<endl;
    cout << "| MENU PRINCIPAL       |"<<endl;
    cout << "+----------------------+"<<endl;
    cout << "| Seleccione una opción por favor."<<endl<<endl;

    
    cout << "0. Salir."<<endl;
    cout << "1. Departamentos."<<endl;
    cout << "2. Municipios"<<endl;
    cout << "3. Personas"<<endl<<endl<<endl<<endl<<endl<<endl;

    cin >> opcionSeleccionada;


    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        menu_principal();
        return;
    }

    switch (opcionSeleccionada)
    {
    case 0:
        return;
    case 1:
        
        dm_menu();
        break;
    case 2:
        dm_menu_municipio();
        break;
    case 3:
        dm_menu_persona(); 
        break;
    default:
        cout<<"Opcion incorrecta"<<endl;
        break;
    }
 
    cualquierTecla();
    menu_principal();
 }

 
int main(int argc, char** argv) {

    //cargando los archivos
    cargandoArchivos();
    menu_principal(); 
    return 0;
}

