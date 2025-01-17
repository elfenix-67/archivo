#include "funciones.h"
#include <string.h>

void agregarFactura(Factura *facturas, int *numFacturas) {
    Factura nuevaFactura;

    // Validar ID
    do {
        printf("Ingrese ID de la factura (solo positivo): ");
        scanf("%d", &nuevaFactura.id);
        if (nuevaFactura.id <= 0) {
            printf("Error: El ID debe ser positivo.\n");
        }
    } while (nuevaFactura.id <= 0);

    // Validar cédula
    do {
        printf("Ingrese número de cédula (10 dígitos): ");
        scanf("%s", nuevaFactura.cedula);
        if (strlen(nuevaFactura.cedula) != 10) {
            printf("Error: La cédula debe tener 10 dígitos.\n");
        }
    } while (strlen(nuevaFactura.cedula) != 10);

    // Ingresar nombre del cliente
    printf("Ingrese el nombre del cliente: ");
    scanf(" %[^\n]", nuevaFactura.nombreCliente);

    // Validar cantidad de productos
    do {
        printf("Ingrese la cantidad de productos: ");
        scanf("%d", &nuevaFactura.totalProductos);
        if (nuevaFactura.totalProductos <= 0) {
            printf("Error: La cantidad debe ser positiva.\n");
        }
    } while (nuevaFactura.totalProductos <= 0);

    // Ingresar los datos de cada producto
    for (int i = 0; i < nuevaFactura.totalProductos; i++) {
        printf("Producto %d:\n", i + 1);

        // Ingresar nombre del producto
        printf("  Ingrese nombre del producto: ");
        scanf(" %[^\n]", nuevaFactura.productos[i].nombre);

        // Validar cantidad del producto
        do {
            printf("  Ingrese cantidad del producto: ");
            scanf("%d", &nuevaFactura.productos[i].cantidad);
            if (nuevaFactura.productos[i].cantidad <= 0) {
                printf("  Error: La cantidad debe ser positiva.\n");
            }
        } while (nuevaFactura.productos[i].cantidad <= 0);

        // Validar precio del producto
        do {
            printf("  Ingrese precio del producto: ");
            scanf("%f", &nuevaFactura.productos[i].precio);
            if (nuevaFactura.productos[i].precio <= 0) {
                printf("  Error: El precio debe ser positivo.\n");
            }
        } while (nuevaFactura.productos[i].precio <= 0);
    }

    // Agregar factura a la lista
    facturas[*numFacturas] = nuevaFactura;
    (*numFacturas)++;
    printf("Factura agregada con éxito.\n");
}

void buscarFactura(Factura *facturas, int numFacturas) {
    int id;
    printf("Ingrese el ID de la factura a buscar: ");
    scanf("%d", &id);

    for (int i = 0; i < numFacturas; i++) {
        if (facturas[i].id == id) {
            printf("\nFactura encontrada:\n");
            printf("ID: %d\n", facturas[i].id);
            printf("Cliente: %s\n", facturas[i].nombreCliente);
            printf("Cédula: %s\n", facturas[i].cedula);
            printf("\n+------------+----------------------+----------+----------+\n");
            printf("| Cantidad   | Producto             | Precio   | Subtotal |\n");
            printf("+------------+----------------------+----------+----------+\n");

            float total = 0.0;
            for (int j = 0; j < facturas[i].totalProductos; j++) {
                float subtotal = facturas[i].productos[j].cantidad * facturas[i].productos[j].precio;
                total += subtotal;
                printf("| %-10d | %-20s | %-8.2f | %-8.2f |\n",
                       facturas[i].productos[j].cantidad,
                       facturas[i].productos[j].nombre,
                       facturas[i].productos[j].precio,
                       subtotal);
            }
            printf("+------------+----------------------+----------+----------+\n");
            printf("| TOTAL                                        | %-8.2f   |\n", total);
            printf("+------------+----------------------+----------+----------+\n");
            return;
        }
    }

    printf("Factura no encontrada.\n");
}


void eliminarFactura(Factura *facturas, int *numFacturas) {
    int id;
    printf("Ingrese el ID de la factura a eliminar: ");
    scanf("%d", &id);

    for (int i = 0; i < *numFacturas; i++) {
        if (facturas[i].id == id) {
            for (int j = i; j < *numFacturas - 1; j++) {
                facturas[j] = facturas[j + 1];
            }
            (*numFacturas)--;
            printf("Factura eliminada con éxito.\n");
            return;
        }
    }
    printf("Factura no encontrada.\n");
}

void guardarFacturasEnArchivo(Factura *facturas, int numFacturas, const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "w");
    if (!archivo) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    for (int i = 0; i < numFacturas; i++) {
        fprintf(archivo, "ID=%d, Cédula=%s, Cliente=%s\n",
                facturas[i].id, facturas[i].cedula, facturas[i].nombreCliente);
        for (int j = 0; j < facturas[i].totalProductos; j++) {
            fprintf(archivo, "%d,%s,%.2f\n",
                    facturas[i].productos[j].cantidad,
                    facturas[i].productos[j].nombre,
                    facturas[i].productos[j].precio);
        }
    }

    fclose(archivo);
    printf("Facturas guardadas en el archivo '%s'.\n", nombreArchivo);
}




