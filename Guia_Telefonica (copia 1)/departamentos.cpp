 

#include "departamentos.h"


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
 * Menu para la seccion
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