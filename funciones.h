#ifndef FUNCIONES_H
#define FUNCIONES_H

// Definir las estructuras
typedef struct {
    char nombre[50];
    int cantidad;
    float precio;
} Producto;

typedef struct {
    int id;
    char cedula[11]; // 10 dígitos + '\0'
    char nombreCliente[50];
    Producto productos[100];
    int totalProductos;
} Factura;

// Funciones
void agregarFactura(Factura *facturas, int *numFacturas);
void buscarFactura(Factura *facturas, int numFacturas);
void eliminarFactura(Factura *facturas, int *numFacturas);
void guardarFacturasEnArchivo(Factura *facturas, int numFacturas, const char *nombreArchivo);
void cargarFacturasDesdeArchivo(Factura *facturas, int *numFacturas, const char *nombreArchivo);
void guardarCedulasEnArchivo(Factura *facturas, int numFacturas, const char *nombreArchivo);
void guardarProductosEnArchivo(Factura *facturas, int numFacturas, const char *nombreArchivo);

#endif

