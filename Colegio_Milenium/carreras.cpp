  
#include "carreras.h"
 

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