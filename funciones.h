#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>

// Estructura para un producto
typedef struct {
    int cantidad;
    char nombre[50];
    float precio;
} Producto;

// Estructura para una factura
typedef struct {
    int id;
    char cedula[11]; // 10 dígitos + carácter nulo
    char nombreCliente[50];
    Producto productos[100];
    int totalProductos;
} Factura;

// Prototipos de funciones
void agregarFactura(Factura *facturas, int *numFacturas);
void buscarFactura(Factura *facturas, int numFacturas);
void eliminarFactura(Factura *facturas, int *numFacturas);
void guardarFacturasEnArchivo(Factura *facturas, int numFacturas, const char *nombreArchivo);
void cargarFacturasDesdeArchivo(Factura *facturas, int *numFacturas, const char *nombreArchivo);

#endif
