int informar_ConsultaFacturacion(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas, char* cuit);
int informar_ListarContrataciones(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas);


int informar_ListarCantidadContratacionesImporte(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas);

int informes_ordenar_pantalla_Nombre_Precio(Pantalla* array, int limite);
int pantallasMenoresIguales(Pantalla* array, int limite);
int pantallasMayoresDiez(Pantalla* array, int limite);
int promedioPantallas(Pantalla *array, int limite);
int informar_pantallasSuperandoPromedioPrecio(Pantalla* pantallas, int lenpantallas);
int informar_pantallasNoSuperandoPromedioPrecio(Pantalla* pantallas, int lenpantallas);
int cant_contratacionesMenorIgualDiez(Contratacion* contrataciones, int limite, Pantalla* array, int limitePantalla, int idPantalla);
int contador_Contrataciones(Contratacion* contrataciones, int limite, Pantalla* array, int limitePantalla, int idPantalla);
int cant_pantallasConMasContrataciones(Contratacion* contrataciones, int limite, Pantalla* array, int limitePantalla, int idPantalla);
