 
#include "productos.h"
#include "clientes.h"


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