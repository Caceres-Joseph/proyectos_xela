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
#include <string.h> 
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
 *  CLIENTE
 * =============================================================================
 */ 

/**
 * ===================================
 *  HEADER CLIENTE
 * ===================================
 */ 

/**
 * Es la estructura que tiene un cliente
 */
struct cliente {
    
    //datos del alumno
    char nombre[255];
    char apellido[255]; 
    char direccion[255];
    
    int edad;
    int codigo;
    int telefono;
 
    int numCompras; 
    
    //es cero si se elimina
    int estado;
};

/**
 * Metodos
 */
cliente *c_crear(
        char *nombre,
        char *apellido,  
        char *direccion,
        
        int edad,
        int codigo,
        int telefono,
        
        int numCompras, 
        int estado
        );
 
//para las ventas

void ds_menu_venta(int idCliente);
/**
 * ===================================
 *  BODY CLIENTE
 * ===================================
 */ 

cliente *c_crear(
        char *nombre,
        char *apellido,  
        char *direccion,
        
        int edad,
        int codigo,
        int telefono,
        
        int numCompras, 
        int estado
        )
{
     
    cliente *nuevo=new cliente;
     
    strcpy(nuevo->nombre, nombre);//copia la cadena
    strcpy(nuevo->apellido, apellido); 
    strcpy(nuevo->direccion, direccion); 
    
    nuevo->edad=edad;
    nuevo->codigo=codigo;
    nuevo->telefono=telefono; 

    nuevo->numCompras=numCompras; 
    nuevo->estado=estado;
 
 }

/**
 * =============================================================================
 *  CLIENTES
 * =============================================================================
 */ 

/**
 * ===================================
 *  HEADER CLIENTES
 * ===================================
 */ 

void ps_menu_crear();
void ps_insertar(
        char *nombre,
        char *apellido,  
        char *direccion,
        
        int edad,
        int codigo,
        int telefono,
        
        int numCompras, 
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
        char *direccion,
        
        int edad,
        int codigo,
        int telefono,
        
        int numCompras, 
        int estado
        );
void ps_actualizar_archivo();

//arreglo  
extern cliente *ps_lista[500];

//indica cual es la ultima posicion libre del arreglo 
extern int ps_indice;
 

//funcioen extras
void ps_buscar();
void ps_listaGeneral(); 
void ps_listaGeneralDepartamento(int idDepartamento);
 
extern string ps_nombreArchivo;


void ps_menu_venta();


//obteniendo puntero

//obteniendo seccion
cliente *ps_getItem(int indice);



void ps_clientesPotenciales();


/**
 * ===================================
 *  BODY CLIENTES
 * ===================================
 */ 
/**
 * Variables
 */
int ps_indice=0;
cliente *ps_lista[500];

 

string ps_nombreArchivo="clientes.txt";

/**
 *Menu en el que se puede crear 
 *
 */
void ps_menu_crear(){
    //Limpiando la cosola
    cout << string( 100, '\n' );

    
    //primero pedimos el nombre de la cliente
    cout << "+------------------------+"<<endl;
    cout << "| Nueva cliente          |"<<endl;
    cout << "+------------------------+"<<endl<<endl;
    


    cout << "Ingrese el nombre del cliente:"<<endl;
    //guardando el nombre del cliente
    char nombre[250];
    cin>>nombre;

    cout<<endl << "Ingrese el apellido del cliente:"<<endl;
    //guardando el nombre del cliente
    char apellido[250];
    cin>>apellido;
    
    
    cout<<endl << "Ingrese la dirección del cliente:"<<endl;
    //guardando el nombre del cliente
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
 


 
    int estado=1;
    
    //insertando el dato
    ps_insertar(nombre,
            apellido,
            direccion,
            edad,
            codigo,
            telefono, 

            0,
            estado
            );
    
    //escribiendo en el archivo
    ps_escribir(nombre,
            apellido,
            direccion,
            edad,
            codigo,
            telefono, 

            0,
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
    cout << "|  Lista de Clientes       | "<<endl;
    cout << "+--------------------------+"<<endl<<endl;
     
    ps_mlista();
}

/**
 * Modifica un item
 */
void ps_menu_modificar()
{

    //Limpiando la cosola
    cout << string( 100, '\n' );

    //primero pedimos el nombre del cliente
    cout << "+---------------------------+"<<endl;
    cout << "| Modificar cliente         |"<<endl;
    cout << "+---------------------------+"<<endl<<endl;
     
    //indice que se va modificar
    int indiceSeleccionado=-1;

    //mostrando la lista de clientes
    ps_mlista();
    cout<<endl<<"Seleccione el cliente:"<<endl;
    cin>>indiceSeleccionado;

    
    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        ps_menu_modificar();
        return;
    }
    
    //validando si se encuentra entre el rango
    if(indiceSeleccionado<ps_indice&&indiceSeleccionado>=0)
    {
        
        cliente *est=ps_lista[indiceSeleccionado];
        char respuesta;
        
        //Nombre
        char nombre[250];
        cout<<endl<< "Desea modificar el nombre (s/n)?"<<endl;
        cin>>respuesta;
        if(respuesta=='s'||respuesta=='S'){
            cout << "Ingrese el nuevo nombre de la cliente:"<<endl;
            cin>>nombre;
            strcpy(est->nombre, nombre);
        }


        //Modificando apellido
        char apellido[250];
        cout<<endl<< "Desea modificar el apellido (s/n)?"<<endl;
        cin>>respuesta;
        if(respuesta=='s'||respuesta=='S'){
            cout << "Ingrese el nuevo apellido de la cliente:"<<endl;
            cin>>apellido;
            strcpy(est->apellido, apellido);
        }
        
        
        //Modificando direccion
        char direccion[250];
        cout<<endl<< "Desea modificar la direccion (s/n)?"<<endl;
        cin>>respuesta;
        if(respuesta=='s'||respuesta=='S'){
            cout << "Ingrese la nueva direccion:"<<endl;
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
 
        //actualizando el archivo
        ps_actualizar_archivo();

        cout<<"Cliente modificado"<<endl;
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

    //primero pedimos el nombre del cliente
    cout << "+---------------------------+"<<endl;
    cout << "| Eliminar un cliente       |"<<endl;
    cout << "+---------------------------+"<<endl<<endl;
     
    //indice que se va eliminar
    int indiceSeleccionado=-1;

    //mostrando la lista de secciones
    ps_mlista();
    cout<<endl<<"Seleccione la cliente a eliminar:"<<endl;
    cin>>indiceSeleccionado;

    
    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        ps_menu_eliminar();
        return;
    }
    
    //validando si se encuentra entre el rango
    if(indiceSeleccionado<ps_indice&&indiceSeleccionado>=0)
    {
        
        cliente *est=ps_lista[indiceSeleccionado];
        est->estado=0;
        
        
        //actualizando el archivo
        ps_actualizar_archivo();
         
        cout<<endl<<"Cliente eliminado"<<endl;
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
    cout << setw(20) << left;
    cout << "Direccion";  
    cout << setw(10) << left;
    cout << "Edad";
    cout << setw(20) << left;
    cout << "Codigo";
    cout << setw(10) << left;
    cout << "Telefono";;
    cout << setw(10) << left;
    cout << "NumCompras"<<endl; 
    
    
    cout << setw(20) << left;
    cout << "---------";
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
    cout << setw(10) << left;
    cout << "---------"<<endl; 
}

void ps_mlista() {
 
    ps_lstEncabezado();
 

    int indice=0;
    for (size_t i = 0; i < ps_indice; i++) {
        cliente *est = ps_lista[i]; 
        //filtrando que este activo y pertenezca al id
        if ((est->estado)) {

            
            cout<<indice<<") ";
            cout << setw(17) << left;
            cout << est->nombre;
            cout << setw(20) << left;
            cout << est->apellido; 
            cout << setw(20) << left;
            cout << est->direccion;  
            cout << setw(10) << left;
            cout << est->edad;
            cout << setw(20) << left;
            cout << est->codigo;
            cout << setw(10) << left;
            cout << est->telefono;
            cout << setw(10) << left;
            cout << est->numCompras<<endl; 
     
        }
        indice++;
    }
}
 
void ps_insertar(
        char *nombre,
        char *apellido,  
        char *direccion,
        
        int edad,
        int codigo,
        int telefono,
        
        int numCompras, 
        int estado
        )
{
    
    //creando y guardando 
    
    ps_lista[ps_indice]=c_crear(nombre,
            apellido,
            direccion,
            edad,
            codigo,
            telefono,

            numCompras,

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
        cliente *est = ps_lista[i];
        //escribiendo en el archivo
        ps_escribir(
                est->nombre,
                est->apellido, 
                est->direccion,
                est->edad,
                est->codigo,
                est->telefono, 

                est->numCompras,
                
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
            
            
            //direccion
            string sDireccion = line.substr(100, 49);
            char *direccion = &sDireccion[0];
            f_quitarEspacios(direccion); 
             
            
            ///edad
            string sEdad = line.substr(150, 49);
            char *tEdad = &sEdad[0];
            f_quitarEspacios(tEdad);
            double edad = stod(tEdad);
            
            
            ///codigo
            string sCodigo = line.substr(200, 49);
            char *tCodigo = &sCodigo[0];
            f_quitarEspacios(tCodigo);
            double codigo = stod(tCodigo);
            
            
            ///telefono
            string sTel = line.substr(250, 49);
            char *tTel = &sTel[0];
            f_quitarEspacios(tTel);
            double telefono = stod(tTel);
            
             
            
            ///numCompras
            string sIdDepartamento = line.substr(300, 49);
            char *tIdDepartamento = &sIdDepartamento[0];
            f_quitarEspacios(tIdDepartamento);
            double idDepartamento = stod(tIdDepartamento);
            
             
 
            ///estado
            string sEstado = line.substr(350, 49);
            char *tEstado = &sEstado[0];
            f_quitarEspacios(tEstado);
            double estado = stod(tEstado);


            //insertando el dato
            ps_insertar(nombre,
                    apellido, 
                    direccion,
                    edad,
                    codigo,
                    telefono, 

                    idDepartamento, 

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
        char *direccion,
        
        int edad,
        int codigo,
        int telefono,
        
        int numCompras, 
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
        myfile << direccion;
         
        
        myfile << setw(50) << left;
        myfile << edad;
        
        myfile << setw(50) << left;
        myfile << codigo;
        
        myfile << setw(50) << left;
        myfile << telefono;
         
        
        myfile << setw(50) << left;
        myfile << numCompras;
         
        
        myfile << setw(50) << left;
        myfile << estado << endl;
        
        myfile.close();
    } else {
        cout << "No se pudo abrir el archivo" << endl;
    }
}




/*
+----------------------------------------------------+
|   Ventas
+----------------------------------------------------+
*/


void ps_menu_venta(){
    
    //Limpiando la cosola
    cout << string( 100, '\n' );
 
    cout << "+-------------------------+"<<endl;
    cout << "| Venta                   |"<<endl;
    cout << "+-------------------------+"<<endl;
    cout << "| Nueva venta"<<endl<<endl;

    //indice 
    int indiceSeleccionado=-1;

    //mostrando la lista 
    ps_mlista();
    cout<<endl<<"Seleccione el cliente:"<<endl;
    cin>>indiceSeleccionado;

    
    //validando la entrada 
    if(!esNumeroEntrada()){
        ps_menu_venta();
        return;
    }
    
    //validando si se encuentra entre el rango
    if(indiceSeleccionado<ps_indice&&indiceSeleccionado>=0)
    {
         
        //desplegando el otro menu
        ds_menu_venta(indiceSeleccionado);
        
        
    }else
    {
        cout<<"El indice seleccionado es incorrecto.";
        cualquierTecla();
        ps_menu_venta();
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
cliente *ps_getItem(int indice)
{
    cliente *dep = ps_lista[indice];
    return dep;
}

void ps_clientesPotenciales()
{
    
    //Limpiando la cosola
    cout << string( 100, '\n' );

    cout << "+-------------------------------------+"<<endl;
    cout << "|  Lista de Clientes Potenciales      | "<<endl;
    cout << "+-------------------------------------+"<<endl<<endl;
     
    ps_lstEncabezado();
 

    int indice=0;
    for (size_t i = 0; i < ps_indice; i++) {
        cliente *est = ps_lista[i]; 
        //filtrando que este activo y pertenezca al id
        if ((est->estado)&&(est->numCompras!=0)) {

            
            cout<<indice<<") ";
            cout << setw(17) << left;
            cout << est->nombre;
            cout << setw(20) << left;
            cout << est->apellido; 
            cout << setw(20) << left;
            cout << est->direccion;  
            cout << setw(10) << left;
            cout << est->edad;
            cout << setw(20) << left;
            cout << est->codigo;
            cout << setw(10) << left;
            cout << est->telefono;
            cout << setw(10) << left;
            cout << est->numCompras<<endl; 
     
        }
        indice++;
    }
}


/**
 * =============================================================================
 *  CLIENTES_MENU
 * =============================================================================
 */ 

/**
 * ===================================
 *  HEADER CLIENTES_MENU
 * ===================================
 */ 
void pm_menu(); 
void pm_menu_venta();
/**
 * ===================================
 *  BODY CLIENTES_MENU
 * ===================================
 */ 


/**
 * Menu de opciones  
 */

void pm_menu()
{ 
    //limpiando la pantalla
    cout << string( 100, '\n' );


    //Para guardar la opcion que seleccionó
    int opcionSeleccionada=0;


    cout << "+----------------------+"<<endl;
    cout << "| Clientes             |"<<endl;
    cout << "+----------------------+"<<endl<<endl;
     
    cout << "0. Salir."<<endl;
    cout << "1. Mostrar clientes"<<endl;
    cout << "2. Crear un nuevo cliente."<<endl;
    cout << "3. Modificar una cliente."<<endl;
    cout << "4. Eliminar un cliente"<<endl<<endl;
    cout << "5. Lista de clientes potenciales"<<endl<<endl<<endl<<endl<<endl<<endl;
    
    
    cin >> opcionSeleccionada;
 
    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        pm_menu();
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
    case 5:
        if(!ps_indice==0){
            ps_clientesPotenciales(); 
        }else{
            cout<<"No hay personas"<<endl;
        }
        break;
    default:
        cout<<"Opcion incorrecta"<<endl;

        break;
    }

    cualquierTecla();
    pm_menu(); 
}



/**
 * Despliega un menu para las ventas
 */

void pm_menu_venta()
{
    
    //limpiando la pantalla
    cout << string( 100, '\n' );


    //Para guardar la opcion que seleccionó
    int opcionSeleccionada=0;
 
    cout << "+----------------------+"<<endl;
    cout << "| Venta                |"<<endl;
    cout << "+----------------------+"<<endl<<endl;

    cout << "0. Salir."<<endl;
    cout << "1. Seleccionar cliente"<<endl<<endl<<endl<<endl<<endl;
    
    cin >> opcionSeleccionada;

    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        pm_menu_venta();
        return;
    }
     
    switch (opcionSeleccionada)
    {
    case 0:
        return;
    case 1:
        if(!ps_indice==0){
             ps_menu_venta();
        }else{
            cout<<"No hay clientes"<<endl;
        }
        break;
    default:
        cout<<"Opcion incorrecta"<<endl; 
        break;
    }

    cualquierTecla();
    pm_menu_venta();

}
 




/**
 * =============================================================================
 *  PRODUCTO
 * =============================================================================
 */ 

/**
 * ===================================
 *  HEADER PRODUCTO
 * ===================================
 */ 

/**
 * Es la estructura que tiene un depa
 */
struct producto { 
    
    //nombre 
    char nombre[255]; 
    //codigo
    int codigo;
    //precio
    double precio;
    //stock
    int stock;
    //Ventas
    int numVentas;
     
    //es cero si se elimina
    int estado;
};


/**
 * Metodos
 */
producto *d_crear(char *nombre,
        int codigo,
        double precio,
        int stock,
        int numVentas,
        int estado);




/**
 * ===================================
 *  BODY PRODUCTO
 * ===================================
 */ 

  /**
  * 
  * @param nombre
  * @param estado
  * @return Retorna una estructura de tipo 
  */
producto *d_crear(char *nombre,
        int codigo,
        double precio,
        int stock,
        int numVentas,
        int estado)
{
     
    producto *nuevo=new producto;
    strcpy(nuevo->nombre, nombre); 
    nuevo->codigo=codigo;
    nuevo->precio=precio;
    nuevo->stock=stock;
    nuevo->numVentas=numVentas;
    //estado activo
    nuevo->estado=estado;

    return nuevo;
}

 

/**
 * =============================================================================
 *  PRODUCTOS
 * =============================================================================
 */ 

/**
 * ===================================
 *  HEADER PRODUCTOS
 * ===================================
 */ 

//Para depas
void ds_menu_crear();
void ds_menu_mostrar();
void ds_menu_modificar();
void ds_menu_eliminar();

//funciones
void ds_mlista();

//lectura y escritura del archivo
void ds_leer(); 
void ds_escribir(char *nombre,
        int codigo,
        double precio,
        int stock,
        int numVentas,
        int estado);

void ds_insertar(char *nombre,
        int codigo,
        double precio,
        int stock,
        int numVentas,
        int estado);

void ds_actualizar_archivo();

//arreglo de carreras 
extern producto *ds_lista[500];

//indica cual es la ultima posicion libre del arreglo 
extern int ds_indice;





//de donde pertenece
extern int ds_indice_cliente;


//otras opciones
void ds_productosMasVendidos();
void ds_productosExistentes();
void ds_buscar();
/**
 * ===================================
 *  BODY PRODUCTOS
 * ===================================
 */ 


/**
 * Variables
 */
int ds_indice=0;
producto *ds_lista[500];
string ds_nombreArchivo="productos.txt";
int ds_indice_cliente=-1;
/**
 * Elimina un producto
 */
void ds_menu_eliminar(){
    
    //Limpiando la cosola
    cout << string( 100, '\n' );

    //primero pedimos el nombre del producto
    cout << "+--------------------------+"<<endl;
    cout << "| Eliminar un producto     |"<<endl;
    cout << "+--------------------------+"<<endl<<endl;

    //indice que se va eliminar
    int indiceSeleccionado=-1;

    //mostrando la lista  
    ds_mlista();
    cout<<endl<<"Seleccione el producto a eliminar:"<<endl;
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
        producto *dep=ds_lista[indiceSeleccionado];
        dep->estado=0;
        
        
        //actualizando el archivo
        ds_actualizar_archivo();
        
        
        cout<<"Producto eliminado"<<endl;
    }else
    {
        cout<<"El indice seleccionado es incorrecto.";
        cualquierTecla();
        ds_menu_eliminar();
    }
}

/**
 * Modifica un producto
 */
void ds_menu_modificar()
{
    
    //Limpiando la cosola
    cout << string( 100, '\n' );

    //primero pedimos el nombre del producto
    cout << "+---------------------------+"<<endl;
    cout << "| Modificar un producto     |"<<endl;
    cout << "+---------------------------+"<<endl<<endl;

    //indice que se va eliminar
    int indiceSeleccionado=-1;

    //mostrando la lista de carreras
    ds_mlista();
    cout<<endl<<"Seleccione el producto:"<<endl;
    cin>>indiceSeleccionado;

    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        ds_menu_modificar();
        return;
    }
    
    
    //validando si se encuentra entre el rango
    if(indiceSeleccionado<ds_indice&&indiceSeleccionado>=0)
    {
        
        producto *dep=ds_lista[indiceSeleccionado];
        char respuesta;
        
        
        //Nombre
        char nombre[250];
        cout<<endl<< "Desea modificar el nombre (s/n)?"<<endl;
        cin>>respuesta;
        if(respuesta=='s'||respuesta=='S'){
            cout << "Ingrese el nuevo nombre:"<<endl;
            cin>>nombre;
            strcpy(dep->nombre, nombre);
        }

 

        //mdificando codigo
        int codigo=0;
        cout<<endl<< "Desea modificar el codigo (s/n)?"<<endl;
        cin>>respuesta;
        if(respuesta=='s'||respuesta=='S'){
            cout << "Ingrese el nuevo  codigo:"<<endl;
            cin>>codigo;
            dep->codigo=codigo;
        }
        
        
        
        //mdificando precio
        double precio=0;
        cout<<endl<< "Desea modificar el precio (s/n)?"<<endl;
        cin>>respuesta;
        if(respuesta=='s'||respuesta=='S'){
            cout << "Ingrese el nuevo  precio:"<<endl;
            cin>>precio;
            dep->precio=precio;
        }
        
        
        
        //mdificando stock
        int stock=0;
        cout<<endl<< "Desea modificar el stock (s/n)?"<<endl;
        cin>>respuesta;
        if(respuesta=='s'||respuesta=='S'){
            cout << "Ingrese el nuevo  stock:"<<endl;
            cin>>stock;
            dep->stock=stock;
        }
        
         
        
        //actualizando el archivo
        ds_actualizar_archivo();

        cout<<"Producto modificado"<<endl;
    }else
    {
        cout<<"El indice seleccionado es incorrecto.";
        cualquierTecla();
        ds_menu_modificar();
    }
     
}
/**
 *Menu en el que se puede crear un nuevo producto
 *
 */
void ds_menu_crear(){
    //Limpiando la cosola
    cout << string( 100, '\n' );

    //primero pedimos el nombre del producto
    cout << "+----------------------+"<<endl;
    cout << "| Nuevo Producto       |"<<endl;
    cout << "+----------------------+"<<endl;
    
    cout <<endl<< "Ingrese el nombre del nuevo producto:"<<endl;
    char nombre[250];
    cin>>nombre;
    
    cout<<endl<< "Ingrese el codigo:"<<endl;
    int codigo=0.0;
    cin>>codigo;
     
    cout<<endl<< "Ingrese el precio:"<<endl;
    double precio=0.0;
    cin>>precio;
    
    
    cout<<endl<< "Ingrese el stock:"<<endl;
    int stock=0.0;
    cin>>stock;
    
    
    int estado=1;
    int numVentas=0;
    
    //insertando el dato
    ds_insertar(nombre, 
            codigo,
            precio,
            stock,
            numVentas,
            estado 
            );
    
    //escribiendo en el archivo
    ds_escribir(nombre, 
            codigo,
            precio,
            stock,
            numVentas,
            estado );
    
    //mensaje de éxito
    
    cout<<endl << "Producto " << nombre <<" creado con éxito." <<endl; 
}

void ds_insertar(char *nombre,
        int codigo,
        double precio,
        int stock,
        int numVentas,
        int estado) 
{

    //creando y guardando 

    ds_lista[ds_indice] = d_crear(nombre,
            codigo,
            precio,
            stock,
            numVentas,
            estado);

    ds_indice++; //incrementando el indice

}


/**
 * Despliega los productos con un encabezado
 */
void ds_menu_mostrar()
{

    //Limpiando la cosola
    cout << string( 100, '\n' );
 
    cout << "+--------------------------+"<<endl;
    cout << "| Lista de Productos       |"<<endl;
    cout << "+--------------------------+"<<endl;
    
    
    ds_mlista();
}

/**
 * Muestra lo que hay en el arreglo
 */
void ds_mlista() {

     
    cout << setw(20) << left;
    cout << "Nombre";
    cout << setw(20) << left;
    cout << "Codigo";
    cout << setw(20) << left;
    cout << "Precio";
    cout << setw(20) << left;
    cout << "Stock";
    cout << setw(20) << left;
    cout << "Num.Ventas" << endl;

    cout << setw(20) << left;
    cout << "------------------";
    cout << setw(20) << left;
    cout << "------------------";
    cout << setw(20) << left;
    cout << "------------------";
    cout << setw(20) << left;
    cout << "------------------";
    cout << setw(20) << left;
    cout << "------------------" << endl;

    int indice=0;
    for (size_t i = 0; i < ds_indice; i++) {
        producto *dep = ds_lista[i]; 
        if ((dep->estado)) {
            cout<<indice<<") ";
            cout << setw(17) << left;
            cout << dep->nombre;
            cout << setw(20) << left;
            cout << dep->codigo;
            cout << setw(20) << left;
            cout << dep->precio;
            cout << setw(20) << left;
            cout << dep->stock;
            cout << setw(20) << left;
            cout << dep->numVentas<<endl;
             
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
void ds_actualizar_archivo()
{
    //limpiando el archivo
    ofstream myfile (ds_nombreArchivo);
    if (myfile.is_open()) { 
        myfile.close();
    } 
    
    for (size_t i = 0; i < ds_indice; i++) {
        producto *pro = ds_lista[i]; 
        ds_escribir(pro->nombre,
                pro->codigo,
                pro->precio,
                pro->stock,
                pro->numVentas,
                pro->estado);
    }
}

/**
 * Escribe los datos en el archivo de texto
 * @param nombre 
 */

void ds_escribir(char *nombre,
        int codigo,
        double precio,
        int stock,
        int numVentas,
        int estado) 
{
     
    //abriendo un archivo y agregando contenido
    ofstream myfile (ds_nombreArchivo, std::ofstream::app);
    if (myfile.is_open()) {
       
        myfile << setw(50)<<left;
        myfile << nombre; 
        myfile << setw(50)<<left;
        myfile << codigo; 
        myfile << setw(50)<<left;
        myfile << precio; 
        myfile << setw(50)<<left;
        myfile << stock; 
        myfile << setw(50)<<left;
        myfile << numVentas; 
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

 
            
            ///codigo
            string sCodigo = line.substr(50, 49);
            char *tCodigo = &sCodigo[0];
            f_quitarEspacios(tCodigo);
            double codigo = stod(tCodigo);
            
            
            ///precio
            string sPrecio = line.substr(100, 49);
            char *tPrecio = &sPrecio[0];
            f_quitarEspacios(tPrecio);
            double precio = stod(tPrecio);
            
            
            ///stock
            string sStock = line.substr(150, 49);
            char *tStock = &sStock[0];
            f_quitarEspacios(tStock);
            double stock = stod(tStock);
            
            
            ///numVentas
            string sVentas = line.substr(200, 49);
            char *tVentas = &sVentas[0];
            f_quitarEspacios(tVentas);
            double numVentas = stod(tVentas);
            
            ///estado
            string sEstado = line.substr(250, 49);
            char *tEstado = &sEstado[0];
            f_quitarEspacios(tEstado);
            double estado = stod(tEstado);
             
 
            //insertando el dato
            ds_insertar(nombre2,
                    codigo,
                    precio,
                    stock,
                    numVentas,
                    estado);
             
        }
        myfile.close();
    }
     

}




/*
+----------------------------------------------------+
|   Ventas
+----------------------------------------------------+
*/


void ds_menu_venta(int idCliente){
     
    cliente *cli=ps_getItem(idCliente);
             
    ds_indice_cliente=idCliente;
    //Limpiando la cosola
    cout << string( 100, '\n' );
 
    cout << "+-------------------------+"<<endl;
    cout << "| Venta                   |"<<endl;
    cout << "+-------------------------+"<<endl;
    cout << "| Nueva venta al cliente:"<<cli->nombre<<endl<<endl;

    //indice  
    int indiceSeleccionado=-1;

    //mostrando la lista  
    ds_mlista();
    cout<<endl<<"Seleccione el producto a vender:"<<endl;
    cin>>indiceSeleccionado;

    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        ds_menu_venta(idCliente);
        return;
    }
 
    //validando si se encuentra entre el rango
    if(indiceSeleccionado<ds_indice&&indiceSeleccionado>=0)
    {
         producto *pro=ds_lista[indiceSeleccionado];
        //ahora pido la cantidad

        int cantidadProductos=0;
        cout<<endl<<"Cantidad de productos que desea vender?"<<endl;
        cin>>cantidadProductos;
        
        //ahora se valida si existe esa cantidad
        
        if(cantidadProductos > pro->stock){
            
            cout<<endl<<"No se pudo realizar la venta, debido a que faltaron: "<<cantidadProductos-(pro->stock)<< " productos"<<endl;
            return;
        }else{
            

            pro->stock=pro->stock-cantidadProductos;
            pro->numVentas=pro->numVentas+cantidadProductos;
            cli->numCompras=cli->numCompras+cantidadProductos;
            cout<<endl<<"               -------------"<<endl;
            cout<<"Total a cobrar: Q."<<pro->precio*cantidadProductos<<endl;
             
        }
        
        //actualizando el archivo
        ds_actualizar_archivo();
        ps_actualizar_archivo();
        
        cout<<endl<<"Venta realizada exitosamente"<<endl;
        
    }else
    {
        cout<<"El indice seleccionado es incorrecto.";
        cualquierTecla();
        ds_menu_venta(idCliente);
    }
}


/*
+----------------------------------------------------+
|   Funciones extras
+----------------------------------------------------+
*/


void ds_productosMasVendidos()
{
    
    //Limpiando la cosola
    cout << string( 100, '\n' );
 
    cout << "+---------------------------------------+"<<endl;
    cout << "| Lista de Productos mas vendidos       |"<<endl;
    cout << "+---------------------------------------+"<<endl;
    
    cout << setw(20) << left;
    cout << "Nombre";
    cout << setw(20) << left;
    cout << "Codigo";
    cout << setw(20) << left;
    cout << "Precio";
    cout << setw(20) << left;
    cout << "Stock";
    cout << setw(20) << left;
    cout << "Num.Ventas" << endl;

    cout << setw(20) << left;
    cout << "------------------";
    cout << setw(20) << left;
    cout << "------------------";
    cout << setw(20) << left;
    cout << "------------------";
    cout << setw(20) << left;
    cout << "------------------";
    cout << setw(20) << left;
    cout << "------------------" << endl;

    int indice=0;
    for (size_t i = 0; i < ds_indice; i++) {
        producto *dep = ds_lista[i]; 
        if ((dep->estado)&&(dep->numVentas!=0)) {
            cout<<indice<<") ";
            cout << setw(17) << left;
            cout << dep->nombre;
            cout << setw(20) << left;
            cout << dep->codigo;
            cout << setw(20) << left;
            cout << dep->precio;
            cout << setw(20) << left;
            cout << dep->stock;
            cout << setw(20) << left;
            cout << dep->numVentas<<endl;
             
        }
        indice++;
    }
}

void ds_productosExistentes(){
     
    //Limpiando la cosola
    cout << string( 100, '\n' );
 
    cout << "+---------------------------------------+"<<endl;
    cout << "| Lista de Productos Existentes         |"<<endl;
    cout << "+---------------------------------------+"<<endl;
    
    cout << setw(20) << left;
    cout << "Nombre";
    cout << setw(20) << left;
    cout << "Codigo";
    cout << setw(20) << left;
    cout << "Precio";
    cout << setw(20) << left;
    cout << "Stock";
    cout << setw(20) << left;
    cout << "Num.Ventas" << endl;

    cout << setw(20) << left;
    cout << "------------------";
    cout << setw(20) << left;
    cout << "------------------";
    cout << setw(20) << left;
    cout << "------------------";
    cout << setw(20) << left;
    cout << "------------------";
    cout << setw(20) << left;
    cout << "------------------" << endl;

    int indice=0;
    for (size_t i = 0; i < ds_indice; i++) {
        producto *dep = ds_lista[i]; 
        if ((dep->estado)&&(dep->stock!=0)) {
            cout<<indice<<") ";
            cout << setw(17) << left;
            cout << dep->nombre;
            cout << setw(20) << left;
            cout << dep->codigo;
            cout << setw(20) << left;
            cout << dep->precio;
            cout << setw(20) << left;
            cout << dep->stock;
            cout << setw(20) << left;
            cout << dep->numVentas<<endl; 
        }
        indice++;
    }
}



void ds_buscar(){
     
    //Limpiando la cosola
    cout << string( 100, '\n' );
 
    cout << "+---------------------------------------+"<<endl;
    cout << "| Buscar Producto                       |"<<endl;
    cout << "+---------------------------------------+"<<endl;
    cout << "| Buscando producto por codigo: "<<endl<<endl;
    
    
    //indice que se va eliminar
    int codigo=-1; 
    cout<<endl<<"Escriba el código para buscar:"<<endl;
    cin>>codigo;
    
    
    //validando la entrada si es valida
    if(!esNumeroEntrada()){
        ds_buscar();
        return;
    }
    
    
    cout << setw(20) << left;
    cout << "Nombre";
    cout << setw(20) << left;
    cout << "Codigo";
    cout << setw(20) << left;
    cout << "Precio";
    cout << setw(20) << left;
    cout << "Stock";
    cout << setw(20) << left;
    cout << "Num.Ventas" << endl;

    cout << setw(20) << left;
    cout << "------------------";
    cout << setw(20) << left;
    cout << "------------------";
    cout << setw(20) << left;
    cout << "------------------";
    cout << setw(20) << left;
    cout << "------------------";
    cout << setw(20) << left;
    cout << "------------------" << endl;

    int indice=0;
    for (size_t i = 0; i < ds_indice; i++) {
        producto *dep = ds_lista[i]; 
        if ((dep->estado)&&(dep->codigo==codigo)) {
            cout<<indice<<") ";
            cout << setw(17) << left;
            cout << dep->nombre;
            cout << setw(20) << left;
            cout << dep->codigo;
            cout << setw(20) << left;
            cout << dep->precio;
            cout << setw(20) << left;
            cout << dep->stock;
            cout << setw(20) << left;
            cout << dep->numVentas<<endl; 
        }
        indice++;
    }
}

/**
 * =============================================================================
 *  PRODUCTOS_MENU
 * =============================================================================
 */ 

/**
 * ===================================
 *  HEADER PRODUCTOS_MENU
 * ===================================
 */ 


void dm_menu(); 
/**
 * ===================================
 *  BODY PRODUCTOS_MENU
 * ===================================
 */ 

void dm_menu()
{

    //limpiando la pantalla
    cout << string( 100, '\n' );


    //Para guardar la opcion que seleccionó
    int opcionSeleccionada=0;


    cout << "+----------------------+"<<endl;
    cout << "| Productos            |"<<endl;
    cout << "+----------------------+"<<endl;
    cout << "| Seleccione una opción por favor."<<endl<<endl;

    cout << "0. Salir."<<endl;
    cout << "1. Lista general de productos."<<endl;
    cout << "2. Crear un nuevo producto."<<endl;
    cout << "3. Modificar un producto."<<endl;
    cout << "4. Eliminar un producto."<<endl<<endl;
    
     
    cout << "5. Listado de productos más vendidos"<<endl;
    cout << "6. Listado de productos existentes"<<endl;
    cout << "7. Buscar producto por codigo"<<endl<<endl<<endl<<endl<<endl<<endl;
    
    
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
            cout<<"No hay productos registradas"<<endl;
        } 
        break;
    case 4:
        
         if(!ds_indice==0){
             ds_menu_eliminar();
        }else{
            cout<<"No hay productos registradas"<<endl;
        } 
        break;
    case 5:
        
         if(!ds_indice==0){
             ds_productosMasVendidos();
        }else{
            cout<<"No hay productos registradas"<<endl;
        } 
        break;
    case 6:
        
         if(!ds_indice==0){
             ds_productosExistentes();
        }else{
            cout<<"No hay productos registradas"<<endl;
        } 
        break;
    case 7:
        
         if(!ds_indice==0){
             ds_buscar();
        }else{
            cout<<"No hay productos registradas"<<endl;
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
 * =============================================================================
 *  PRINCIPAL
 * =============================================================================
 */ 

void cargandoArchivos(){ 
    ps_leer();
    ds_leer();
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



    cout << "**********************************"<<endl;
    cout << "* FERRETERIA <<EL CAMALEON>>     *"<<endl;
    cout << "**********************************"<<endl;


    cout << "+----------------------+"<<endl;
    cout << "| MENU PRINCIPAL       |"<<endl;
    cout << "+----------------------+"<<endl;
    cout << "| Seleccione una opción por favor."<<endl<<endl;

    cout << "0. Salir."<<endl;
    cout << "1. Productos."<<endl;
    cout << "2. Clientes"<<endl;
    cout << "3. Realizar Venta"<<endl<<endl<<endl<<endl<<endl<<endl;

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
        pm_menu();
        break;
    case 3:
        pm_menu_venta();
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

