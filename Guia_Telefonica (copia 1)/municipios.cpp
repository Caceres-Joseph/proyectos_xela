

#include "municipios.h"


#include "departamentos.h"
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