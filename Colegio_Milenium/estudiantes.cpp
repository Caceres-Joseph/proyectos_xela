#include "estudiantes.h"

#include "carreras.h"
#include "secciones.h"
 
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