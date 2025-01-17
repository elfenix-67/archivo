#include "funciones.h"

int main() {
    Factura facturas[100];
    int numFacturas = 0;

    int opcion;
    do {
        printf("\n--- Menú ---\n");
        printf("1. Agregar factura\n");
        printf("2. Buscar factura\n");
        printf("3. Eliminar factura\n");
        printf("4. Guardar en archivo\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarFactura(facturas, &numFacturas);
                break;
            case 2:
                buscarFactura(facturas, numFacturas);
                break;
            case 3:
                eliminarFactura(facturas, &numFacturas);
                break;
            case 4:
                guardarFacturasEnArchivo(facturas, numFacturas, "facturas.txt");
                break;
            case 5:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (opcion != 5);

    return 0;
}
