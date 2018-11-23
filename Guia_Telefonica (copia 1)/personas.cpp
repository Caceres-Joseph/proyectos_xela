 
#include "personas.h"
 

#include "departamentos.h"
#include "municipios.h"
 
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

 