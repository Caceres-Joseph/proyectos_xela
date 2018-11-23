


/**
 * =====================================================================
 *  FUNC
 * =====================================================================
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
 * =====================================================================
 *  CARRERA
 * =====================================================================
 */ 



/**
 * Es la estructura que tiene una carrera
 */
struct c_carrera {
    //idCarrera
    int idCarrera;
    //nombre de la carrera
    char nombre[255];
    //precio de la carrera
    double precio;
    //es cero si se elimina
    int estado;
};


/**
 * Metodos
 */
c_carrera *crearCarrera(int idCarrera, char *nombre, double precio, int estado);

//obteniendo la carrera 
c_carrera c_getCarrera(int indice);



 /**
  * 
  * @param nombre
  * @param precio
  * @return Retorna una estructura de tipo carrera
  */
c_carrera *crearCarrera(int idCarrera , char *nombre, double precio, int estado){
     
    c_carrera *nuevaCarera=new c_carrera;
    strcpy(nuevaCarera->nombre, nombre);
    nuevaCarera->precio=precio;
    //estado activo
    nuevaCarera->estado=estado;
    nuevaCarera->idCarrera=idCarrera;
    //escribiendo
    
    return nuevaCarera;
}



/**
 * =====================================================================
 *  SECCION
 * =====================================================================
 */ 


/**
 * Es la estructura que tiene una seccion
 */
struct seccion {
    //nombre de la carrera
    char nombre[255];
    int idCarrera;
    //es cero si se elimina
    int estado;
};


/**
 * Metodos
 */
seccion *s_crear(char *nombre,int idCarrera ,int estado);
seccion ss_getItem(int indice);


/**
 * Retorna una estructura con los datos iddicados
 * @param nombre
 * @param estado
 * @return 
 */
seccion *s_crear(char *nombre,int idCarrera,int estado){
     
    seccion *nuevo=new seccion;
    
    strcpy(nuevo->nombre, nombre);
    nuevo->estado=estado;
    nuevo->idCarrera=idCarrera;
    
    return nuevo;
}


 
/**
 * =====================================================================
 *  ESTUDIANTE
 * =====================================================================
 */ 



/**
 * Es la estructura que tiene un estudiante
 */
struct estudiante {
    
    //datos del alumno
    char nombre[255];
    char apellido[255];
    char sexo[255];
    char direccion[255];
    int edad;
    int codigo;
    int telefono;

    int aprobado=-1;
         
    int idCarrera;
    int idSeccion;
    
    //es cero si se elimina
    int estado;
};

/**
 * Metodos
 */
estudiante *e_crear(
        char *nombre,
        char *apellido,
        char *sexo,
        char *direccion,
        int edad,
        int codigo,
        int telefono,
        int aprobado,
        int idCarrera,
        int idSeccion,
        int estado
        );

 estudiante *e_crear(
        char *nombre,
        char *apellido,
        char *sexo,
        char *direccion,
        int edad,
        int codigo,
        int telefono,
        int aprobado,
        int idCarrera,
        int idSeccion,
        int estado
        )
 {
     
    estudiante *nuevo=new estudiante;
     
    strcpy(nuevo->nombre, nombre);//copia la cadena
    strcpy(nuevo->apellido, apellido);
    strcpy(nuevo->sexo, sexo);
    strcpy(nuevo->direccion, direccion);
    
    nuevo->edad=edad;
    nuevo->codigo=codigo;
    nuevo->telefono=telefono;
    nuevo->aprobado=aprobado;

    nuevo->idCarrera=idCarrera;
    nuevo->idSeccion=idSeccion;
    nuevo->estado=estado;
 
 }

/**
 * =====================================================================
 *  ESTUDIANTES
 * =====================================================================
 */ 
//Para seccioens
void es_menu_crear();
void es_insertar(
        char *nombre,
        char *apellido,
        char *sexo,
        char *direccion,
        int edad,
        int codigo,
        int telefono,
        int aprobado,
        int idCarrera,
        int idSeccion,
        int estado
        );
void es_menu_mostrar();
void es_menu_modificar();
void es_menu_eliminar();

//funciones
void es_mlista();
void es_lstEncabezado();

//lectura y escritura del archivo
void es_leer(); 
void es_escribir(
        char *nombre,
        char *apellido,
        char *sexo,
        char *direccion,
        int edad,
        int codigo,
        int telefono,
        int aprobado,
        int idCarrera,
        int idSeccion,
        int estado
        );
void es_actualizar_archivo();

//arreglo  
extern estudiante *es_lista[500];

//indica cual es la ultima posicion libre del arreglo 
extern int es_indice;
 

//funcioen extras

void es_buscar();
void es_listaGeneral();
void es_listaGeneralAprobados();
void es_listaGeneralNoAprobados();
void es_cantidad();
void es_cuota();

extern string es_nombreArchivo;


//de donde pertenece
extern int em_indice_carrera;
extern int em_indice_seccion;


/**
 * Variables
 */
int es_indice=0;
estudiante *es_lista[500];

 

string es_nombreArchivo="estudiantes.txt";

/**
 *Menu en el que se puede crear 
 *
 */
void es_menu_crear(){
    //Limpiando la cosola
    cout << string( 100, '\n' );

    //primero pedimos el nombre del estudiante
    cout << "+------------------------+"<<endl;
    cout << "| Nuevo Estudiante       |"<<endl;
    cout << "+------------------------+"<<endl;
    cout << "| Carrera: "<<c_getCarrera(em_indice_carrera).nombre<<endl;
    cout << "| Seccion: "<<ss_getItem(em_indice_seccion).nombre<<endl<<endl;


    cout << "Ingrese el nombre del estudiante:"<<endl;
    //guardando el nombre del estudiante
    char nombre[250];
    cin>>nombre;

    cout<<endl << "Ingrese el apellido del estudiante:"<<endl;
    //guardando el nombre del estudiante
    char apellido[250];
    cin>>apellido;


    cout<<endl << "Ingrese el sexo del estudiante (M/F):"<<endl;
    //guardando el sexo del estudiante
    char sexo[250];
    cin>>sexo;

    cout<<endl << "Ingrese la direccion del estudiante :"<<endl;
    char direccion[250];
    cin>>direccion;


    cout<<endl << "Ingrese la edad:"<<endl;
    int edad=0;
    cin>>edad;


    cout <<endl<< "Ingrese el codigo:"<<endl;
    int codigo=0;
    cin>>codigo;


    cout <<endl<< "Ingrese el teléfono:"<<endl;
    int telefono=0;
    cin>>telefono;


    cout<<endl << "Aprobó el estudiante (0=no, 1=si) ? :"<<endl;
    int aprobado=0;
    cin>>aprobado;


 
    int estado=1;
    
    //insertando el dato
    es_insertar(nombre,
            apellido,
            sexo,
            direccion,
            edad,
            codigo,
            telefono,
            aprobado,

            em_indice_carrera,
            em_indice_seccion,

            estado
            );
    
    //escribiendo en el archivo
    es_escribir(nombre,
            apellido,
            sexo,
            direccion,
            edad,
            codigo,
            telefono,
            aprobado,

            em_indice_carrera,
            em_indice_seccion,

            estado
            );
    
    //mensaje de éxito
    cout<<endl << "Estudiante guardado con éxito." <<endl;
}



/**
 * Despliega la lista con un encabezado
 */
void es_menu_mostrar()
{

    //Limpiando la cosola
    cout << string( 100, '\n' );

    cout << "+--------------------------+"<<endl;
    cout << "| Lista de Estudiantes     | "<<endl;
    cout << "+--------------------------+"<<endl;
    cout << "| Carrera: "<<c_getCarrera(em_indice_carrera).nombre<<endl;
    cout << "| Seccion: "<<ss_getItem(em_indice_seccion).nombre<<endl<<endl;

    es_mlista();
}

/**
 * Modifica un item
 */
void es_menu_modificar()
{

    //Limpiando la cosola
    cout << string( 100, '\n' );

    //primero pedimos el nombre del estudiante
    cout << "+---------------------------+"<<endl;
    cout << "| Modificar estudiante      |"<<endl;
    cout << "+---------------------------+"<<endl;
    cout << "| Carrera: "<<c_getCarrera(em_indice_carrera).nombre<<endl;
    cout << "| Seccion: "<<ss_getItem(em_indice_seccion).nombre<<endl<<endl;

    //indice que se va eliminar
    int indiceSeleccionado=-1;

    //mostrando la lista de secciones
    es_mlista();
    cout<<"Seleccione el estudiante:"<<endl;
    cin>>indiceSeleccionado;

    
    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        es_menu_modificar();
        return;
    }
    
    //validando si se encuentra entre el rango
    if(indiceSeleccionado<es_indice&&indiceSeleccionado>=0)
    {
        
        estudiante *est=es_lista[indiceSeleccionado];
        char respuesta;
        
        //Nombre
        char nombre[250];
        cout<<endl<< "Desea modificar el nombre (s/n)?"<<endl;
        cin>>respuesta;
        if(respuesta=='s'||respuesta=='S'){
            cout << "Ingrese el nuevo nombre del estudiante:"<<endl;
            cin>>nombre;
            strcpy(est->nombre, nombre);
        }


        //Modificando apellido
        char apellido[250];
        cout<<endl<< "Desea modificar el apellido (s/n)?"<<endl;
        cin>>respuesta;
        if(respuesta=='s'||respuesta=='S'){
            cout << "Ingrese el nuevo apellido del estudiante:"<<endl;
            cin>>apellido;
            strcpy(est->apellido, apellido);
        }


        //modificando sexo
        char sexo[250];
        cout<<endl<< "Desea modificar el sexo (s/n)?"<<endl;
        cin>>respuesta;
        if(respuesta=='s'||respuesta=='S'){
            cout << "Ingrese el nuevo sexo del estudiante (M/F):"<<endl;
            cin>>sexo;
            strcpy(est->sexo, sexo);
        }

        //modificando direccion
        char direccion[250];
        cout<<endl<< "Desea modificar la direccion (s/n)?"<<endl;
        cin>>respuesta;
        if(respuesta=='s'||respuesta=='S'){
            cout << "Ingrese la nueva direccion del estudiante :"<<endl;
            cin>>direccion;
            strcpy(est->direccion, direccion);
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


        //modificando aprobado
        int aprobado=0;
        cout<<endl<< "Desea modificar la aprobación (s/n)?"<<endl;
        cin>>respuesta;
        if(respuesta=='s'||respuesta=='S'){
            cout << "Aprobó el estudiante (0=no, 1=si) ? :"<<endl;
            cin>>aprobado;
            est->aprobado=aprobado;
        }

 
        //actualizando el archivo
        es_actualizar_archivo();

        cout<<endl<<"Estudiante modificado"<<endl;
    }else
    {
        cout<<"El indice seleccionado es incorrecto.";
        cualquierTecla();
        es_menu_modificar();
    }
      
}
/**
 * Elimina un item
 */
void es_menu_eliminar(){
    
    //Limpiando la cosola
    cout << string( 100, '\n' );

    //primero pedimos el nombre del estudiante
    cout << "+----------------------------"<<endl;
    cout << "| Eliminar una estudiante    |"<<endl;
    cout << "+----------------------------"<<endl<<endl;
    cout << "| Carrera: "<<c_getCarrera(em_indice_carrera).nombre<<endl;
    cout << "| Seccion: "<<ss_getItem(em_indice_seccion).nombre<<endl<<endl;

    //indice que se va eliminar
    int indiceSeleccionado=-1;

    //mostrando la lista de secciones
    es_mlista();
    cout<<endl<<"Seleccione el estudiante a eliminar:"<<endl;
    cin>>indiceSeleccionado;

    
    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        es_menu_eliminar();
        return;
    }
    
    //validando si se encuentra entre el rango
    if(indiceSeleccionado<es_indice&&indiceSeleccionado>=0)
    {
        
        estudiante *est=es_lista[indiceSeleccionado];
        est->estado=0;
        
        
        //actualizando el archivo
        es_actualizar_archivo();
        
        
        cout<<endl<<"Estudiante eliminado"<<endl;
    }else
    {
        cout<<"El indice seleccionado es incorrecto.";
        cualquierTecla();
        es_menu_eliminar();
    }
    
}
/**
 * Muestra lo que hay en el arreglo
 */
void es_lstEncabezado(){
    
    cout << setw(20) << left;
    cout << "Nombre";
    cout << setw(20) << left;
    cout << "Apellido";
    cout << setw(10) << left;
    cout << "Sexo";
    cout << setw(20) << left;
    cout << "Direccion";
    cout << setw(10) << left;
    cout << "Edad";
    cout << setw(20) << left;
    cout << "Codigo";
    cout << setw(10) << left;
    cout << "Telefono";
    cout << setw(20) << left;
    cout << "Aprobado"<<endl;
    
    
    cout << setw(20) << left;
    cout << "---------";
    cout << setw(20) << left;
    cout << "---------";
    cout << setw(10) << left;
    cout << "---------";
    cout << setw(20) << left;
    cout << "---------";
    cout << setw(10) << left;
    cout << "---------";
    cout << setw(20) << left;
    cout << "---------";
    cout << setw(10) << left;
    cout << "---------";
    cout << setw(20) << left;
    cout << "---------"<<endl;
}
void es_mlista() {
 
    es_lstEncabezado();
 

    int indice=0;
    for (size_t i = 0; i < es_indice; i++) {
        estudiante *est = es_lista[i]; 
        //filtrando que este activo y pertenezca al id
        if ((est->estado)&&(est->idCarrera==em_indice_carrera)&&(est->idSeccion==em_indice_seccion)) {
//        if ((sec->estado)) {
            
            //
            cout<<indice<<") ";
            cout << setw(17) << left;
            cout << est->nombre;
            cout << setw(20) << left;
            cout << est->apellido;
            cout << setw(10) << left;
            cout << est->sexo;
            cout << setw(20) << left;
            cout << est->direccion;
            cout << setw(10) << left;
            cout << est->edad;
            cout << setw(20) << left;
            cout << est->codigo;
            cout << setw(10) << left;
            cout << est->telefono;
            cout << setw(20) << left;
            cout << est->aprobado<<endl;
     
        }
        indice++;
    }
}


void es_insertar(
        char *nombre,
        char *apellido,
        char *sexo,
        char *direccion,
        int edad,
        int codigo,
        int telefono,
        int aprobado,
        int idCarrera,
        int idSeccion,
        int estado
        )
{
    
    //creando y guardando la carrera
    
    es_lista[es_indice]=e_crear(nombre,
            apellido,
            sexo,
            direccion,
            edad,
            codigo,
            telefono,
            aprobado,

            idCarrera,
            idSeccion,

            estado
            );
    
    es_indice++; //incrementando el indice
  
}


/*
+----------------------------------------------------+
|   Escritura Lectura
+----------------------------------------------------+
*/
//escribe lo que hay en el arreglo en el archivo
void es_actualizar_archivo()
{
    //limpiando el archivo
    ofstream myfile (es_nombreArchivo);
    if (myfile.is_open()) { 
        myfile.close();
    } 

    for (size_t i = 0; i < es_indice; i++) {
        estudiante *est = es_lista[i];
        //escribiendo en el archivo
        es_escribir(
                est->nombre,
                est->apellido,
                est->sexo,
                est->direccion,
                est->edad,
                est->codigo,
                est->telefono,
                est->aprobado,

                est->idCarrera,
                est->idSeccion,

                est->estado
                );

    }
}

/**
 * Carga el archivo al inicio
 */
void es_leer() {
    string line;
    ifstream myfile(es_nombreArchivo);
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
            
            //sexo
            string sSexo = line.substr(100, 49);
            char *sexo = &sSexo[0];
            f_quitarEspacios(sexo); 
            
            //direccion
            string sDireccion = line.substr(150, 49);
            char *direccion = &sDireccion[0];
            f_quitarEspacios(direccion); 

            
            ///edad
            string sEdad = line.substr(200, 49);
            char *tEdad = &sEdad[0];
            f_quitarEspacios(tEdad);
            double edad = stod(tEdad);
            
            
            ///codigo
            string sCodigo = line.substr(250, 49);
            char *tCodigo = &sCodigo[0];
            f_quitarEspacios(tCodigo);
            double codigo = stod(tCodigo);
            
            
            ///telefono
            string sTel = line.substr(300, 49);
            char *tTel = &sTel[0];
            f_quitarEspacios(tTel);
            double telefono = stod(tTel);
            
            
            ///aprobado
            string sAprobado = line.substr(350, 49);
            char *tAprobado = &sAprobado[0];
            f_quitarEspacios(tAprobado);
            double aprobado = stod(tAprobado);
            
            
            ///idCarrera
            string sIdCarrera = line.substr(400, 49);
            char *tIdCarrera = &sIdCarrera[0];
            f_quitarEspacios(tIdCarrera);
            double idCarrera = stod(tIdCarrera);
            
            
            ///idSeccion
            string sIdSeccion = line.substr(450, 49);
            char *tIdSeccion = &sIdSeccion[0];
            f_quitarEspacios(tIdSeccion);
            double idSeccion = stod(tIdSeccion);
 
 
            ///estado
            string sEstado = line.substr(500, 49);
            char *tEstado = &sEstado[0];
            f_quitarEspacios(tEstado);
            double estado = stod(tEstado);


            //insertando el dato
            es_insertar(nombre,
                    apellido,
                    sexo,
                    direccion,
                    edad,
                    codigo,
                    telefono,
                    aprobado,

                    idCarrera,
                    idSeccion,

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
void es_escribir(
        char *nombre,
        char *apellido,
        char *sexo,
        char *direccion,
        int edad,
        int codigo,
        int telefono,
        int aprobado,
        int idCarrera,
        int idSeccion,
        int estado
        ) {


    //abriendo un archivo y agregando contenido
    ofstream myfile(es_nombreArchivo, std::ofstream::app);
    if (myfile.is_open()) {

        myfile << setw(50) << left;
        myfile << nombre;
        
        myfile << setw(50) << left;
        myfile << apellido;
        
        myfile << setw(50) << left;
        myfile << sexo;
        
        myfile << setw(50) << left;
        myfile << direccion;
        
        myfile << setw(50) << left;
        myfile << edad;
        
        myfile << setw(50) << left;
        myfile << codigo;
        
        myfile << setw(50) << left;
        myfile << telefono;
        
        myfile << setw(50) << left;
        myfile << aprobado;
        
        myfile << setw(50) << left;
        myfile << idCarrera;
        
        myfile << setw(50) << left;
        myfile << idSeccion; 
        
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
void es_buscar()
{
    
    //Limpiando la cosola
    cout << string( 100, '\n' );

    cout << "+--------------------------+"<<endl;
    cout << "| Estudiantes              | "<<endl;
    cout << "+--------------------------+"<<endl;
    cout << "| Buscando estudiante: "<<endl<<endl;

    
    
    //indice que se va eliminar
    int codigo=-1; 
    cout<<endl<<"Escriba el código para buscar:"<<endl;
    cin>>codigo;

    
    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        es_buscar();
        return;
    }
    
    
    
    cout << setw(20) << left;
    cout << "Nombre";
    cout << setw(20) << left;
    cout << "Apellido";
    cout << setw(20) << left;
    cout << "Carrera";
    cout << setw(20) << left;
    cout << "Seccion"<<endl;
    
    
    
    cout << setw(20) << left;
    cout << "---------";
    cout << setw(20) << left;
    cout << "---------"; 
    cout << setw(20) << left;
    cout << "---------"; 
    cout << setw(20) << left;
    cout << "---------"<<endl;
    
    
    int indice=0;
    for (size_t i = 0; i < es_indice; i++) {
        estudiante *est = es_lista[i]; 
        //filtrando que este activo y pertenezca al id
        if ((est->estado)&&(est->codigo==codigo)) {
 
            cout<<indice<<") ";
            cout << setw(17) << left;
            cout << est->nombre;
            cout << setw(20) << left;
            cout << est->apellido; 
            cout << setw(20) << left;
            cout << c_getCarrera(est->idCarrera).nombre;
            cout << setw(20) << left;
            cout << ss_getItem(est->idSeccion).nombre<<endl; 
        }
        indice++;
    }
}

 
/**
 * Busca item por codigo
 * @param codigo
 */
void es_listaGeneral()
{
    
    //Limpiando la cosola
    cout << string( 100, '\n' );

    cout << "+---------------------------+"<<endl;
    cout << "| Estudiantes por Carreras  | "<<endl;
    cout << "+---------------------------+"<<endl;
    cout << "| Lista general de estudiantes "<<endl<<endl;

     
    
     
    int indice=0;
    int idCarrera=-1;
    for (size_t i = 0; i < es_indice; i++) {
        estudiante *est = es_lista[i]; 
        //filtrando que este activo y pertenezca al id
        if ((est->estado)) {
 
            if(idCarrera!=est->idCarrera){
                 
                cout << "+-----------"<<endl;
                cout << "|Carera: "<<c_getCarrera(est->idCarrera).nombre<<endl;
                cout << "+-----------"<<endl; 
                 
                es_lstEncabezado(); 
                idCarrera=est->idCarrera;
            }
             
            cout<<indice<<") ";
            cout << setw(17) << left;
            cout << est->nombre;
            cout << setw(20) << left;
            cout << est->apellido;
            cout << setw(10) << left;
            cout << est->sexo;
            cout << setw(20) << left;
            cout << est->direccion;
            cout << setw(10) << left;
            cout << est->edad;
            cout << setw(20) << left;
            cout << est->codigo;
            cout << setw(10) << left;
            cout << est->telefono;
            cout << setw(20) << left;
            cout << est->aprobado<<endl;
        }
        indice++;
    }
}


/**
 *
 * @param aprobados
 */
void es_listaGeneralAprobados()
{
    
    //Limpiando la cosola
    cout << string( 100, '\n' );

    cout << "+----------------------------------------------+"<<endl;
    cout << "| Listado General de Estudiantes Aprobados     |"<<endl;
    cout << "+----------------------------------------------+"<<endl;
    cout << "| Por carrera y seccion "<<endl<<endl;

     
    
     
    int indice=0;
    int idCarrera=-1;
    int idSeccion=-1;
    for (size_t i = 0; i < es_indice; i++) {
        estudiante *est = es_lista[i]; 
        //filtrando que este activo y pertenezca al id
        if ((est->estado)&&(est->aprobado)==1) {
 
            if(idCarrera!=est->idCarrera){
                 
                cout << "+----------------------"<<endl;
                cout << "|Carera: "<<c_getCarrera(est->idCarrera).nombre<<endl;
                cout << "+----------------------"<<endl; 
                 
                //es_lstEncabezado(); 
                idCarrera=est->idCarrera;
            }
            
            if(idSeccion!=est->idSeccion){
                cout << "+-----------"<<endl;
                cout << "|Sección: "<<ss_getItem(est->idSeccion).nombre<<endl;
                cout << "+-----------"<<endl<<endl; 
                es_lstEncabezado(); 
                idSeccion=est->idSeccion;
            }
            
             
            cout<<indice<<") ";
            cout << setw(17) << left;
            cout << est->nombre;
            cout << setw(20) << left;
            cout << est->apellido;
            cout << setw(10) << left;
            cout << est->sexo;
            cout << setw(20) << left;
            cout << est->direccion;
            cout << setw(10) << left;
            cout << est->edad;
            cout << setw(20) << left;
            cout << est->codigo;
            cout << setw(10) << left;
            cout << est->telefono;
            cout << setw(20) << left;
            cout << est->aprobado<<endl;
        }
        indice++;
    }
}



/**
 *
 * @param noAprobados
 */
void es_listaGeneralNoAprobados()
{
    
    //Limpiando la cosola
    cout << string( 100, '\n' );

    cout << "+----------------------------------------------+"<<endl;
    cout << "| Listado General de Estudiantes Reprobados    |"<<endl;
    cout << "+----------------------------------------------+"<<endl;
    cout << "| Por carrera y seccion "<<endl<<endl;

     
    
     
    int indice=0;
    int idCarrera=-1;
    int idSeccion=-1;
    for (size_t i = 0; i < es_indice; i++) {
        estudiante *est = es_lista[i]; 
        //filtrando que este activo y pertenezca al id
        if ((est->estado)&&(est->aprobado)==0) {
 
            if(idCarrera!=est->idCarrera){
                 
                cout << "+----------------------"<<endl;
                cout << "|Carera: "<<c_getCarrera(est->idCarrera).nombre<<endl;
                cout << "+----------------------"<<endl; 
                 
                //es_lstEncabezado(); 
                idCarrera=est->idCarrera;
            }
            
            if(idSeccion!=est->idSeccion){
                cout << "+-----------"<<endl;
                cout << "|Sección: "<<ss_getItem(est->idSeccion).nombre<<endl;
                cout << "+-----------"<<endl<<endl; 
                es_lstEncabezado(); 
                idSeccion=est->idSeccion;
            }
            
             
            cout<<indice<<") ";
            cout << setw(17) << left;
            cout << est->nombre;
            cout << setw(20) << left;
            cout << est->apellido;
            cout << setw(10) << left;
            cout << est->sexo;
            cout << setw(20) << left;
            cout << est->direccion;
            cout << setw(10) << left;
            cout << est->edad;
            cout << setw(20) << left;
            cout << est->codigo;
            cout << setw(10) << left;
            cout << est->telefono;
            cout << setw(20) << left;
            cout << est->aprobado<<endl;
        }
        indice++;
    }
}


/**
 *
 * @param cantidadEstudiantes
 */
void es_cantidad()
{
    
    //Limpiando la cosola
    cout << string( 100, '\n' );

    cout << "+----------------------------------------------+"<<endl;
    cout << "| Cantidad de estudiantes por seccion          |"<<endl;
    cout << "+----------------------------------------------+"<<endl;
    cout << "| Por carrera y seccion "<<endl<<endl;

     
    
     
    int indice=0;
    int idCarrera=-1;
    int idSeccion=-1;
    
    
    for (size_t i = 0; i < es_indice; i++) {
        estudiante *est = es_lista[i]; 
        //filtrando que este activo y pertenezca al id
        if ((est->estado)) {
  
            
            
            if(idCarrera!=est->idCarrera){
                
                //aqui hay que hacer otro for para comprobar la cantidad por seccion
                 
                int contCarrera=0;
                //recorrer todos los estudiantes con idCarrera
                for (size_t i2 = 0; i2 < es_indice; i2++) {
                    estudiante *est2 = es_lista[i2]; 
                    if ((est2->estado)&&(est2->idCarrera==est->idCarrera)) {
                        contCarrera++;
                    }
                }
                 
                cout << "+-------------------------"<<endl;
                cout << "| Carera: "<<c_getCarrera(est->idCarrera).nombre<<endl;
                cout << "+-------------------------"<<endl; 
                cout << "| Total:"<<contCarrera<<endl<<endl;
                  
                idCarrera=est->idCarrera; 
            }
            
            if(idSeccion!=est->idSeccion){
                int contSecc=0;
                //recorrer todos los estudiantes con idSeccion
                for (size_t i2 = 0; i2 < es_indice; i2++) {
                    estudiante *est2 = es_lista[i2]; 
                    if ((est2->estado)&&(est2->idSeccion==est->idSeccion)) {
                        contSecc++;
                    }
                }
                
                
                cout << "+-----------"<<endl;
                cout << "| Sección: "<<ss_getItem(est->idSeccion).nombre<<endl;
                cout << "+-----------"<<endl; 
                cout << "| Sub-Total:"<<contSecc<<endl<<endl;
                
                idSeccion=est->idSeccion; 
            }
            
        }
        indice++;
    }
}




/**
 *
 * @param cuot
 */
void es_cuota()
{
    
    //Limpiando la cosola
    cout << string( 100, '\n' );

    //primero pedimos el nombre del carrera
    cout << "+------------------------------------+"<<endl;
    cout << "| Cuotas por carrera y seccion       |"<<endl;
    cout << "+------------------------------------+"<<endl;
    cout << "| Por carrera y seccion "<<endl<<endl;

     
    
     
    int indice=0;
    int idCarrera=-1;
    int idSeccion=-1;
    
    
    for (size_t i = 0; i < es_indice; i++) {
        estudiante *est = es_lista[i]; 
        //filtrando que este activo y pertenezca al id
        if ((est->estado)) {
   
            if(idCarrera!=est->idCarrera){
                
                //aqui hay que hacer otro for para comprobar la cantidad por seccion
                 
                double pCarrera=0;
                //recorrer todos los estudiantes con idCarrera
                for (size_t i2 = 0; i2 < es_indice; i2++) {
                    estudiante *est2 = es_lista[i2]; 
                    if ((est2->estado)&&(est2->idCarrera==est->idCarrera)) {
                        pCarrera+=c_getCarrera(est->idCarrera).precio;
                    }
                }
                 
                cout << "+-------------------------"<<endl;
                cout << "| Carera: "<<c_getCarrera(est->idCarrera).nombre<<endl;
                cout << "+-------------------------"<<endl; 
                cout << "| Total: Q."<<pCarrera<<endl<<endl;
                  
                idCarrera=est->idCarrera; 
            }
            
            if(idSeccion!=est->idSeccion){
                double pSecc=0;
                //recorrer todos los estudiantes con idSeccion
                for (size_t i2 = 0; i2 < es_indice; i2++) {
                    estudiante *est2 = es_lista[i2]; 
                    if ((est2->estado)&&(est2->idSeccion==est->idSeccion)) {
                        pSecc+=c_getCarrera(est->idCarrera).precio;
                    }
                }
                
                
                cout << "+-----------"<<endl;
                cout << "| Sección: "<<ss_getItem(est->idSeccion).nombre<<endl;
                cout << "+-----------"<<endl; 
                cout << "| Sub-Total: Q."<<pSecc<<endl<<endl;
                
                idSeccion=est->idSeccion; 
            }
            
        }
        indice++;
    }
}


/**
 * =====================================================================
 *  ESTUDIANTE_MENU
 * =====================================================================
 */ 
void em_menu(int idCarrera, int idSeccion); 



/**
 * Variables
 */
int em_indice_carrera=-1;
int em_indice_seccion=-1;

/**
 * Menu de opciones para la seccion
 */

void em_menu(int idCarrera, int idSeccion)
{
    em_indice_carrera=idCarrera;
    em_indice_seccion=idSeccion;
    
    //limpiando la pantalla
    cout << string( 100, '\n' );


    //Para guardar la opcion que seleccionó
    int opcionSeleccionada=0;


    cout << "+----------------------+"<<endl;
    cout << "| Estudiantes          |"<<endl;
    cout << "+----------------------+"<<endl;
    cout << "| Carrera: "<<c_getCarrera(em_indice_carrera).nombre<<endl;
    cout << "| Seccion: "<<ss_getItem(em_indice_seccion).nombre<<endl<<endl;

    cout << "0. Salir."<<endl;
    cout << "1. Mostrar estudiantes de la sección: "<<ss_getItem(em_indice_seccion).nombre<<endl;
    cout << "2. Crear un nuevo estudiantes."<<endl;
    cout << "3. Modificar un estudiante."<<endl;
    cout << "4. Eliminar un estudiante"<<endl<<endl<<endl<<endl<<endl<<endl;
 
    cin >> opcionSeleccionada;
 
    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        em_menu(idCarrera,idSeccion);
        return;
    }

    
    
    switch (opcionSeleccionada)
    {
    case 0:
        return;
    case 1:
        es_menu_mostrar(); 
        break;
    case 2:
        es_menu_crear(); 
        break;
    case 3:
        if(!es_indice==0){
            es_menu_modificar(); 
        }else{
            cout<<"No hay estudiantes"<<endl;
        }

        break;
    case 4:
        if(!es_indice==0){
            es_menu_eliminar(); 
        }else{
            cout<<"No hay estudiantes"<<endl;
        }
        break;
    default:
        cout<<"Opcion incorrecta"<<endl;

        break;
    }

    cualquierTecla();
    em_menu(idCarrera,idSeccion);


}

 

/**
 * =====================================================================
 *  SECCIONES
 * =====================================================================
 */ 


//Para seccioens
void ss_menu_crear();
void ss_insertar(char *nombre, int carrera, int estado);
void ss_menu_mostrar();
void ss_menu_modificar();
void ss_menu_eliminar();

//funciones
void ss_mlista();


//lectura y escritura del archivo
void ss_leer(); 
void ss_escribir(char *nombre, int carrera, int estado);
void ss_actualizar_archivo();

//arreglo de carreras 
extern seccion *ss_lista[500];

//indica cual es la ultima posicion libre del arreglo 
extern int ss_indice;

//de donde pertenece
extern int ss_indice_carrera;

extern string ss_nombreArchivo;



//para el estudiante
void ss_menu_estudiante();


//de donde pertenece
extern int sm_indice_carrera;


 
/**
 * Variables
 */
int ss_indice=0;
seccion *ss_lista[500];
int ss_indice_carrera=-1;
string ss_nombreArchivo="secciones.txt";
/**
 *Menu en el que se puede crear un nuevo departamento
 *
 */
void ss_menu_crear(){
    //Limpiando la cosola
    cout << string( 100, '\n' );

    //primero pedimos el nombre del seccion
    cout << "+------------------------+"<<endl;
    cout << "| Nueva Seccion          | "<<endl;
    cout << "+------------------------+"<<endl;
    cout << "| Carrera: "<<c_getCarrera(sm_indice_carrera).nombre<<endl<<endl;


    cout << " Ingrese el nombre de la seccion."<<endl<<endl;


    //guardando el nombre del nuevo  seccion
    char nombre[250];
    cin>>nombre;
 
    int estado=1;
    
    //insertando el dato
    ss_insertar(nombre, sm_indice_carrera, estado);
    
    //escribiendo en el archivo
    ss_escribir(nombre, sm_indice_carrera, estado);
    
    //mensaje de éxito
    cout<<endl<< "Carrera " << nombre <<" creada con éxito." <<endl;
}

void ss_insertar(char *nombre, int carrera, int estado){
    
    //creando y guardando la carrera
    
    ss_lista[ss_indice]=s_crear(nombre,carrera, estado);
    
    ss_indice++; //incrementando el indice
  
}


/**
 * Despliega la lista con un encabezado
 */
void ss_menu_mostrar()
{

    //Limpiando la cosola
    cout << string( 100, '\n' );

    cout << "+--------------------------+"<<endl;
    cout << "| Lista de Secciones       |"<<endl;
    cout << "+--------------------------+"<<endl;
    cout << "| Carrera: "<<c_getCarrera(sm_indice_carrera).nombre<<endl<<endl;

    ss_mlista();
}


/**
 * Modifica un item
 */
void ss_menu_modificar()
{

    //Limpiando la cosola
    cout << string( 100, '\n' );

    //primero pedimos el nombre del seccion
    cout << "+---------------------------+"<<endl;
    cout << "| Modificar Seccion         |"<<endl;
    cout << "+---------------------------+"<<endl;
    cout << "| Carrera: "<<c_getCarrera(sm_indice_carrera).nombre<<endl<<endl;

    //indice que se va eliminar
    int indiceSeleccionado=-1;

    //mostrando la lista de secciones
    ss_mlista();
    cout<<"Seleccione la seccion:"<<endl;
    cin>>indiceSeleccionado;

    
    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        ss_menu_modificar();
        return;
    }
    
    //validando si se encuentra entre el rango
    if(indiceSeleccionado<ss_indice&&indiceSeleccionado>=0)
    {
        
        seccion *sec=ss_lista[indiceSeleccionado];
         
        cout<<endl<<"Ingrese el nuevo nombre de la seccion:"<<endl;
        char nombre[250];
        cin>>nombre;

 
        //modificando el nombre del carrera
        strcpy(sec->nombre, nombre);
        
        
        //actualizando el archivo
        ss_actualizar_archivo();

        cout<<endl<<"Seccion modificada"<<endl;
    }else
    {
        cout<<"El indice seleccionado es incorrecto.";
        cualquierTecla();
        ss_menu_modificar();
    }
      
}
/**
 * Elimina un item
 */
void ss_menu_eliminar(){
    

    //Limpiando la cosola
    cout << string( 100, '\n' );

    //primero pedimos el nombre del seccion
    cout << "+--------------------------+"<<endl;
    cout << "| Eliminar Seccion         | "<<endl;
    cout << "+--------------------------+"<<endl;
    cout << "| Carrera: "<<c_getCarrera(sm_indice_carrera).nombre<<endl<<endl;

    //indice que se va eliminar
    int indiceSeleccionado=-1;

    //mostrando la lista de secciones
    ss_mlista();
    cout<<"Seleccione la seccion:"<<endl;
    cin>>indiceSeleccionado;

    
    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        ss_menu_eliminar();
        return;
    }
    
    //validando si se encuentra entre el rango
    if(indiceSeleccionado<ss_indice&&indiceSeleccionado>=0)
    {
        
        seccion *sec=ss_lista[indiceSeleccionado];
        sec->estado=0;
        
        
        //actualizando el archivo
        ss_actualizar_archivo();
        
        
        cout<<endl<<"Seccion eliminada"<<endl;
    }else
    {
        cout<<"El indice seleccionado es incorrecto.";
        cualquierTecla();
        ss_menu_eliminar();
    }
    
}
/**
 * Muestra lo que hay en el arreglo
 */
void ss_mlista() {
 
    cout << setw(30) << left;
    cout << "Nombre: " << endl;
 
    cout << setw(30) << left;
    cout << "--------------------" << endl;


    int indice=0;
    for (size_t i = 0; i < ss_indice; i++) {
        seccion *sec = ss_lista[i]; 
        //filtrando que este activo y pertenezca al id
        if ((sec->estado)&&(sec->idCarrera==sm_indice_carrera)) {
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
void ss_actualizar_archivo()
{
    //limpiando el archivo
    ofstream myfile (ss_nombreArchivo);
    if (myfile.is_open()) { 
        myfile.close();
    } 
    
    for (size_t i = 0; i < ss_indice; i++) {
        seccion *sec = ss_lista[i]; 
        ss_escribir(sec->nombre, sec->idCarrera, sec->estado);
    }
}
/**
 * Carga el archivo al inicio
 */
void ss_leer() {
    string line;
    ifstream myfile(ss_nombreArchivo);
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            
            

            //nombre
            string sNombre = line.substr(0, 49);
            char *tNombre = &sNombre[0];
            f_quitarEspacios(tNombre); 

            
            ///idCarrera
            string sIdCarrera = line.substr(50, 49);
            char *tIdCarrera = &sIdCarrera[0];
            f_quitarEspacios(tIdCarrera);
            double idcarrera = stod(tIdCarrera);
 


            
            ///estado
            string sEstado = line.substr(100, 49);
            char *tEstado = &sEstado[0];
            f_quitarEspacios(tEstado);
            double estado = stod(tEstado);


            //insertando el dato
            ss_insertar(tNombre, idcarrera, estado);
        }
        myfile.close();
    }

}

/**
 * Escribe los datos en el archivo de texto
 * @param nombre
 * @param precio
 */
void ss_escribir(char *nombre, int carrera, int estado) {


    //abriendo un archivo y agregando contenido
    ofstream myfile(ss_nombreArchivo, std::ofstream::app);
    if (myfile.is_open()) {

        myfile << setw(50) << left;
        myfile << nombre;
        myfile << setw(50) << left;
        myfile << carrera;
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
seccion ss_getItem(int indice)
{
    seccion *sec = ss_lista[indice];  
    return *sec;
}

/*
+----------------------------------------------------+
|   Menu Estudiante
+----------------------------------------------------+
*/

void ss_menu_estudiante()
{
    //limpiando la pantalla
    cout << string( 100, '\n' );
 

    cout << "+----------------------+"<<endl;
    cout << "| Estudiante           | "<<endl;
    cout << "+----------------------+"<<endl;
    cout << "| Carrera: "<<c_getCarrera(sm_indice_carrera).nombre<<endl<<endl;
    
    //indice que se va eliminar
    int indiceSeleccionado=-1;

    //mostrando la lista de secciones
    ss_mlista();
    cout<<endl<<"Seleccione la seccion:"<<endl;
    cin>>indiceSeleccionado;

    
    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        ss_menu_estudiante();
        return;
    }
    
    //validando si se encuentra entre el rango
    if(indiceSeleccionado<ss_indice&&indiceSeleccionado>=0)
    {
        
        //desplegando el otro menu
        em_menu(sm_indice_carrera,indiceSeleccionado);
         
    }else
    {
        cout<<"El indice seleccionado es incorrecto.";
        cualquierTecla();
        ss_menu_estudiante();
    }
}


/**
 * =====================================================================
 *  SECCION_MENU
 * =====================================================================
 */ 

void sm_menu(int indice);
void sm_menu_estudiante(int indice);




/**
 * Variables
 */
int sm_indice_carrera=-1;
 
/**
 * Menu de opciones para la seccion
 */
void sm_menu(int indice){
    sm_indice_carrera=indice;
    
    //limpiando la pantalla
    cout << string( 100, '\n' );


    //Para guardar la opcion que seleccionó
    int opcionSeleccionada=0;



    cout << "+----------------------+"<<endl;
    cout << "| Secciones            |"<<endl;
    cout << "+----------------------+"<<endl;
    cout << "| Carrera: "<<c_getCarrera(sm_indice_carrera).nombre<<endl<<endl;

    cout << "0. Salir."<<endl;
    cout << "1. Mostrar secciones."<<endl;
    cout << "2. Crear una nueva seccion."<<endl;
    cout << "3. Modificar una seccion."<<endl;
    cout << "4. Eliminar una seccion."<<endl<<endl<<endl<<endl<<endl<<endl;
    cin >> opcionSeleccionada;


    
    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        sm_menu(indice);
        return;
    }

    
    
    switch (opcionSeleccionada)
    {
    case 0:
        return;
    case 1:
        ss_menu_mostrar();
        break;
    case 2:
        ss_menu_crear(); 
        break;
    case 3:
        if(!ss_indice==0){
            ss_menu_modificar(); 
        }else{
            cout<<"No hay secciones"<<endl;
        }

        break;
    case 4:
        if(!ss_indice==0){
            ss_menu_eliminar(); 
        }else{
            cout<<"No hay secciones"<<endl;
        } 
        break;
    default:
        cout<<"Opcion incorrecta"<<endl;

        break;
    }

    cualquierTecla();
    sm_menu(indice);


}

void sm_menu_estudiante(int indice)
{
    sm_indice_carrera=indice;
    
    //limpiando la pantalla
    cout << string( 100, '\n' );


    //Para guardar la opcion que seleccionó
    int opcionSeleccionada=0;



    cout << "+----------------------+"<<endl;
    cout << "| Estudiante           | "<<endl;
    cout << "+----------------------+"<<endl;
    cout << "| Carrera: "<<c_getCarrera(sm_indice_carrera).nombre<<endl<<endl;
    cout << " Seleccione una opción por favor."<<endl<<endl;

    cout << "0. Salir."<<endl;
    cout << "1. Seleccionar una seccion"<<endl<<endl<<endl<<endl<<endl<<endl;

    cin >> opcionSeleccionada;

    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        sm_menu_estudiante(indice);
        return;
    }
 
    switch (opcionSeleccionada)
    {
    case 0:
        return;
    case 1:
        
        if(!ss_indice==0){
            ss_menu_estudiante(); 
        }else{
            cout<<"No hay secciones"<<endl;
        }  
        break;
    default:
        cout<<"Opcion incorrecta"<<endl;

        break;
    }
    
    cualquierTecla();
    sm_menu_estudiante(indice); 
}


/**
 * =====================================================================
 *  CARRERAS
 * =====================================================================
 */ 


//Para carreras
void c_menu_crearCarrera();
void c_insertar(char *nombre, double precio, int estado);
void c_menu_mostrarCarreras();
void c_menu_modificarCarrera();
void c_menu_eliminarCarrera();

//funciones
void c_mlistaCarreras();

//lectura y escritura del archivo
void c_leer(); 
void c_escribir(char *nombre, double precio, int estado);
void c_actualizar_archivo();

//arreglo de carreras 
extern c_carrera *c_listaCarreras[500];

//indica cual es la ultima posicion libre del arreglo 
extern int c_listaCarreraIndice;



//Para la seccion y alumnos
void c_menu_seccion();
void c_menu_estudiante();





/**
 * Variables
 */
int c_listaCarreraIndice=0;
c_carrera *c_listaCarreras[500];

/**
 * Elimina una carrera
 */
void c_menu_eliminarCarrera(){
    
    //Limpiando la cosola
    cout << string( 100, '\n' );

    //primero pedimos el nombre del carrera
    cout << "+--------------------------+"<<endl;
    cout << "| Eliminar una carrera     |"<<endl;
    cout << "+--------------------------+"<<endl<<endl;

    //indice que se va eliminar
    int indiceSeleccionado=-1;

    //mostrando la lista de carreras
    c_mlistaCarreras();
    cout<<endl<<"Seleccione la carrera a eliminar:"<<endl;
    cin>>indiceSeleccionado;

    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        c_menu_eliminarCarrera();
        return;
    }
 
    //validando si se encuentra entre el rango
    if(indiceSeleccionado<c_listaCarreraIndice&&indiceSeleccionado>=0)
    {
        //se coloca el estado en cero para indicar que se eliminó
        c_carrera *carrera=c_listaCarreras[indiceSeleccionado];
        carrera->estado=0;
        
        
        //actualizando el archivo
        c_actualizar_archivo();
        
        
        cout<<"Carrera eliminada"<<endl;
    }else
    {
        cout<<"El indice seleccionado es incorrecto.";
        cualquierTecla();
        c_menu_eliminarCarrera();
    }
}

/**
 * Modifica una carrera
 */
void c_menu_modificarCarrera(){
    
    //Limpiando la cosola
    cout << string( 100, '\n' );

    //primero pedimos el nombre del carrera
    cout << "+---------------------------+"<<endl;
    cout << "| Modificar una carrera     |"<<endl;
    cout << "+---------------------------+"<<endl<<endl;

    //indice que se va eliminar
    int indiceSeleccionado=-1;

    //mostrando la lista de carreras
    c_mlistaCarreras();
    cout<<endl<<"Seleccione la carrera:"<<endl;
    cin>>indiceSeleccionado;

    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        c_menu_modificarCarrera();
        return;
    }
    
    
    //validando si se encuentra entre el rango
    if(indiceSeleccionado<c_listaCarreraIndice&&indiceSeleccionado>=0)
    {
        
        c_carrera *carrera=c_listaCarreras[indiceSeleccionado];
        
        
        
        cout<<endl<<"Ingrese el nuevo nombre de la carrera:"<<endl;
        char nombre[250];
        cin>>nombre;



        cout <<endl<< "Ingrese la nueva cuota :"<<endl;
        double precio=0;
        cin>>precio;


        //modificando el nombre del carrera
        strcpy(carrera->nombre, nombre);
        carrera->precio=precio;
        
        //actualizando el archivo
        c_actualizar_archivo();

        cout<<"Carrera modificada"<<endl;
    }else
    {
        cout<<"El indice seleccionado es incorrecto.";
        cualquierTecla();
        c_menu_modificarCarrera();
    }
    
    
    
}
 /**
  * Muestra un menú para crear una nueva carrera
  */
void c_menu_crearCarrera(){
    //Limpiando la cosola
    cout << string( 100, '\n' );

    //primero pedimos el nombre del carrera
    cout << "+----------------------+"<<endl;
    cout << "| Nueva Carrera        |"<<endl;
    cout << "+----------------------+"<<endl<<endl;
    
    cout <<endl<< "Ingrese el nombre de la nueva carrera:"<<endl;
    char nombre[250];
    cin>>nombre;
    
    

    cout<<endl<< "Ingrese la cuota:"<<endl;
    double precio=0.0;
    cin>>precio;
    
    
    int estado=1;
    
    //insertando el dato
    c_insertar(nombre, precio, estado);
    
    //escribiendo en el archivo
    c_escribir(nombre, precio, estado);
    
    //mensaje de éxito
    cout<<endl<< "Carrera " << nombre <<" creada con éxito." <<endl;
}

void c_insertar(char *nombre, double precio, int estado){
    
    //creando y guardando la carrera
    
    c_listaCarreras[c_listaCarreraIndice]=crearCarrera(c_listaCarreraIndice,nombre,precio, estado);
    
    c_listaCarreraIndice++; //incrementando el indice
  
}


/**
 * Despliega los carreras con un encabezado
 */
void c_menu_mostrarCarreras()
{

    //Limpiando la cosola
    cout << string( 100, '\n' );

    //primero pedimos el nombre del carrera
    cout << "+--------------------------+"<<endl;
    cout << "| Lista de Carreras        |"<<endl;
    cout << "+--------------------------+"<<endl;

    c_mlistaCarreras();
}

/**
 * Muestra lo que hay en el arreglo
 */
void c_mlistaCarreras() {

    
    
    cout << setw(30) << left;
    cout << "Nombre";
    cout << setw(30) << left;
    cout << "Cuota" << endl;

    cout << setw(30) << left;
    cout << "--------------------";
    cout << setw(30) << left;
    cout << "--------------------" << endl;


    int indice=0;
    for (size_t i = 0; i < c_listaCarreraIndice; i++) {
        c_carrera *carrera = c_listaCarreras[i]; 
        if ((carrera->estado)) {
            cout<<indice<<") ";
            cout << setw(30) << left;
            cout << carrera->nombre;
            cout << "Q." << carrera->precio << endl;
        }
        indice++;
    }
}

/*
+----------------------------------------------------+
|   Seccion
+----------------------------------------------------+
*/
/**
 * Menu para la seccion
 */
void c_menu_seccion(){
    
    //Limpiando la cosola
    cout << string( 100, '\n' );

    //primero pedimos el nombre del carrera
    cout << "+-------------------------+"<<endl;
    cout << "| Secciones               |"<<endl;
    cout << "+-------------------------+"<<endl<<endl;

    //indice que se va eliminar
    int indiceSeleccionado=-1;

    //mostrando la lista de carreras
    c_mlistaCarreras();
    cout<<endl<<"Seleccione la carrera:"<<endl;
    cin>>indiceSeleccionado;

    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        c_menu_seccion();
        return;
    }
    
    
    //validando si se encuentra entre el rango
    if(indiceSeleccionado<c_listaCarreraIndice&&indiceSeleccionado>=0)
    {
        
        //desplegando el otro menu
        sm_menu(indiceSeleccionado);
        
        
    }else
    {
        cout<<"El indice seleccionado es incorrecto.";
        cualquierTecla();
        c_menu_seccion();
    }
    
}
/**
 * Menu para el estudiante
 */
void c_menu_estudiante()
{
    
    //Limpiando la cosola
    cout << string( 100, '\n' );

    //primero pedimos el nombre del carrera
    cout << "+-------------------------+"<<endl;
    cout << "| Estudiante              |"<<endl;
    cout << "+-------------------------+"<<endl<<endl;

    //indice que se va eliminar
    int indiceSeleccionado=-1;

    //mostrando la lista de carreras
    c_mlistaCarreras();
    cout<<endl<<"Seleccione la carrera"<<endl;
    cin>>indiceSeleccionado;
    
    
    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        c_menu_estudiante();
        return;
    }
    
    
    //validando si se encuentra entre el rango
    if(indiceSeleccionado<c_listaCarreraIndice&&indiceSeleccionado>=0)
    {
        
        //desplegando el otro menu
        sm_menu_estudiante(indiceSeleccionado);
         
    }else
    {
        cout<<"El indice seleccionado es incorrecto.";
        cualquierTecla();
        c_menu_estudiante();
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
c_carrera c_getCarrera(int indice)
{
    c_carrera *carrera = c_listaCarreras[indice];
    return *carrera;
}

/*
+----------------------------------------------------+
|   Escritura Lectura
+----------------------------------------------------+
*/

//escribe lo que hay en el arreglo en el archivo
void c_actualizar_archivo()
{
    //limpiando el archivo
    ofstream myfile ("carreras.txt");
    if (myfile.is_open()) { 
        myfile.close();
    } 
    
    for (size_t i = 0; i < c_listaCarreraIndice; i++) {
        c_carrera *carrera = c_listaCarreras[i]; 
        c_escribir(carrera->nombre, carrera->precio, carrera->estado);
    }
}

/**
 * Escribe los datos en el archivo de texto
 * @param nombre
 * @param precio
 */

void c_escribir(char *nombre, double precio, int estado) {
    
    
    //abriendo un archivo y agregando contenido
    ofstream myfile ("carreras.txt",std::ofstream::app);
    if (myfile.is_open()) {
       
        myfile << setw(50)<<left;
        myfile << nombre;
        myfile << setw(50)<<left;
        myfile << precio;
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
void c_leer() { 
    string line;
    ifstream myfile("carreras.txt");
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            
            
            //nombre
            string nombre = line.substr(0, 49);
            char *nombre2 = &nombre[0];
            f_quitarEspacios(nombre2);


            ///precio
            string precio = line.substr(50, 49);
            char *precio2 = &precio[0];
            f_quitarEspacios(precio2);
            double val = stod(precio2);
            
            
            ///estado
            string sEstado = line.substr(100, 49);
            char *tEstado = &sEstado[0];
            f_quitarEspacios(tEstado);
            double estado = stod(tEstado);
            
            

            //insertando el dato
            c_insertar(nombre2, val, estado);
            
            
            //string precio= line.substr(50,99);
            //f_quitarEspacios(precio);
            cout << nombre2 << "." << '\n';
            cout << val << "." << '\n';
        }
        myfile.close();
    }
     

}



/**
 * =====================================================================
 *  CARRERA_MENU
 * =====================================================================
 */ 
void c_menu();
void cm_menu_seccion();
void cm_menu_estudiante();



void c_menu()
{

    //limpiando la pantalla
    cout << string( 100, '\n' );


    //Para guardar la opcion que seleccionó
    int opcionSeleccionada=0;

    cout << "+----------------------+"<<endl;
    cout << "| Carreras             |"<<endl;
    cout << "+----------------------+"<<endl;
    cout << "| Seleccione una opción por favor."<<endl<<endl;

    cout << "0. Salir."<<endl;
    cout << "1. Mostrar las carreras."<<endl;
    cout << "2. Crear una nueva carrera."<<endl;
    cout << "3. Modificar una carrera."<<endl;
    cout << "4. Eliminar una carrera."<<endl<<endl<<endl<<endl<<endl<<endl;
    cin >> opcionSeleccionada;


    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        c_menu();
        return;
    }

    switch (opcionSeleccionada)
    {
    case 0:
        return;
    case 1:
        c_menu_mostrarCarreras();
        break;
    case 2:  
        c_menu_crearCarrera();
        break;
    case 3:
        c_menu_modificarCarrera(); 
        break;
    case 4:
        c_menu_eliminarCarrera();
        break;
    default:
        cout<<"Opcion incorrecta"<<endl; 
        break;
    }

    cualquierTecla();
    c_menu();
 }

/**
 * Despliega un menu para la seccion
 */

void cm_menu_seccion()
{
    
    //limpiando la pantalla
    cout << string( 100, '\n' );


    //Para guardar la opcion que seleccionó
    int opcionSeleccionada=0;
 
    cout << "+----------------------+"<<endl;
    cout << "| Secciones            |"<<endl;
    cout << "+----------------------+"<<endl;
    cout << "| Seleccione una opción por favor."<<endl<<endl;

    cout << "0. Salir."<<endl;
    cout << "1. Seleccionar una carrera"<<endl<<endl<<endl<<endl<<endl<<endl;

    cin >> opcionSeleccionada;

    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        cm_menu_seccion();
        return;
    }
     
    switch (opcionSeleccionada)
    {
    case 0:
        return;
    case 1:
         if(!c_listaCarreraIndice==0){
             c_menu_seccion();
        }else{
            cout<<"No hay carreras registradas"<<endl;
        }
        break;
    default:
        cout<<"Opcion incorrecta"<<endl; 
        break;
    }

    cualquierTecla();
    cm_menu_seccion();

}

/**
 * Menu para estudiantes
 */
void cm_menu_estudiante()
{
    
    //limpiando la pantalla
    cout << string( 100, '\n' );


    //Para guardar la opcion que seleccionó
    int opcionSeleccionada=0;
 
    cout << "+----------------------+"<<endl;
    cout << "| Estudiante           | "<<endl;
    cout << "+----------------------+"<<endl;
    cout << "| Seleccione una opción por favor."<<endl<<endl;

    cout << "0. Salir."<<endl;
    cout << "1. Seleccionar una carrera"<<endl<<endl; 
    cout << "-----------------------------"<<endl;
    cout << "2. Buscar estudiante por codigo"<<endl;
    cout << "3. Lista general de estudiantes por carreras"<<endl;
    cout << "4. Lista general de estudiantes aprobados por carrera y seccion"<<endl;
    cout << "5. Lista general de estudiantes reprobados por carrera y seccion"<<endl;
    cout << "6. Cantidad de estudiantes por cada sección en carrera"<<endl;
    cout << "7. Total general de ingresos mensuales por carrera y secciones"<<endl<<endl<<endl<<endl<<endl;

    cin >> opcionSeleccionada;


    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        cm_menu_estudiante();
        return;
    }

    switch (opcionSeleccionada)
    {
    case 0:
        return;
    case 1:
         
        if(!c_listaCarreraIndice==0){
            c_menu_estudiante(); 
        }else{
            cout<<"No hay carreras registradas"<<endl;
        }
        break;
    case 2:
        if(!es_indice==0){
            es_buscar();
        }else{
            cout<<"No hay estudiantes registrados"<<endl;
        }
        break;

    case 3:
        if(!es_indice==0){
            es_listaGeneral();
        }else{
            cout<<"No hay estudiantes registrados"<<endl;
        }
        break;
    case 4:
        if(!es_indice==0){
            es_listaGeneralAprobados(); 
        }else{
            cout<<"No hay estudiantes registrados"<<endl;
        }
        break;
    case 5:
        if(!es_indice==0){
            es_listaGeneralNoAprobados();
        }else{
            cout<<"No hay estudiantes registrados"<<endl;
        }
        break;
    case 6:
        if(!es_indice==0){
            es_cantidad();
        }else{
            cout<<"No hay estudiantes registrados"<<endl;
        }
        break;
    case 7:
        if(!es_indice==0){
            es_cuota();
        }else{
            cout<<"No hay estudiantes registrados"<<endl;
        }
        break;
    default:
        cout<<"Opcion incorrecta"<<endl; 
        break;
    }
    
    cualquierTecla();
    cm_menu_estudiante();
}


/**
 * =====================================================================
 *  PRINCIPAL
 * =====================================================================
 */ 


void cargandoArchivos(){
    c_leer();
    ss_leer();
    es_leer();
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
    cout << "* COLEGIO << MILENUM >>        *"<<endl;
    cout << "********************************"<<endl;


    cout << "+----------------------+"<<endl;
    cout << "| MENU PRINCIPAL       |"<<endl;
    cout << "+----------------------+"<<endl;
    cout << "| Seleccione una opción por favor."<<endl<<endl;

    cout << "0. Salir."<<endl;
    cout << "1. Carreras."<<endl;
    cout << "2. Secciones"<<endl;
    cout << "3. Estudiantes"<<endl<<endl<<endl<<endl<<endl<<endl;


    cin >> opcionSeleccionada;


    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        c_menu();
        return;
    }

    switch (opcionSeleccionada)
    {
    case 0:
        return;
    case 1:
        //despliega el menu de las carreras
        c_menu();
        break;
    case 2:
        cm_menu_seccion();
        break;
    case 3:
        
        cm_menu_estudiante();
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

