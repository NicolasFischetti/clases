
typedef struct
{
    int id;
    char descripcion;
    int stock;
    float precioUnitario;
    int estado = 1; /* checkear como se define*/
    int cant;

}eProducto;


int buscarLibre(eProducto[], int tam);

eProducto pedirProducto();

int ingresarProductoEnLista(eProducto[], int id, int tam);

int modificarProducto(eProducto[], float precioUnitario, int stock, char descripcion, int tam );

int borrarProducto(eProducto[], int id, int stock);

void mostrarListaDeProductos(eProducto[],int idProducto[], char descripcion, int stock[], float precioUnitario[], int cant);

void mostrarUnProducto(eProducto);

void ordenarProductos(eProducto[], int id, int stock, int precioUnitario);
