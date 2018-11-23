 

#include "clientes.h"
 
#include "productos.h"
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