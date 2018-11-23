 

#include "secciones.h"
#include "carreras.h"

 
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