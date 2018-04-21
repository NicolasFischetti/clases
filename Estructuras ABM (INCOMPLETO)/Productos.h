
typedef struct
{
    int id;
    char descripcion;
    int stock;
    float precioUnitario;
    int estado;
    int cant;

}eProducto;


int buscarLibre(eProducto[], int id);

eProducto pedirProducto();

int ingresarProductoEnLista(eProducto[], int id);

int modificarProducto(eProducto[], float precioUnitario, int stock, char descripcion );

int borrarProducto(eProducto[], int id, int stock);

void mostrarListaDeProductos(eProducto[],int idProducto[], char descripcion, int stock[], float precioUnitario[], int cant);

void mostrarUnProducto(eProducto);

void ordenarProductos(eProducto[], int id, int stock, int precioUnitario);
