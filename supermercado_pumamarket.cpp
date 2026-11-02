#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// ==========================================
// FUNCIONES ESPECIFICADAS EN EL ALGORITMO
// ==========================================

// 1. FUNCION POR VALOR: Calcula el subtotal (precio * cantidad)
double calcularSubtotal(double precio, double cantidad) {
    return precio * cantidad;
}

// 2. FUNCION POR VALOR: Calcula el descuento según un porcentaje
double calcularDescuento(double subtotal, double porcentaje) {
    return subtotal * porcentaje;
}

// 3. FUNCION POR REFERENCIA: Modifica los acumuladores generales y de unidades/libras vendidas
void acumularVenta(double &subtotalGeneral, double &totalVendidas, double subtotal, double cantidad) {
    subtotalGeneral += subtotal;
    totalVendidas += cantidad;
}

// 4. FUNCION POR REFERENCIA: Calcula los impuestos ISV general (15%) y adicional en licores (3%)
void calcularImpuestos(double base, double baseLicores, double &impuestoISV, double &impuestoLicores) {
    impuestoISV = base * 0.15;
    impuestoLicores = baseLicores * 0.03;
}

// 5. FUNCION POR VALOR: Valida si la cantidad supera el stock disponible
bool validarStock(double cantidad, double stockTotal) {
    return cantidad > stockTotal;
}

int main() {
    // Declaración de variables de entrada
    int edadCliente, tipoCliente, diaSemana;
    char continuarCompra = 's';

    cout << "=== SISTEMA DE VENTAS SUPERMERCADO ===\n";
    cout << "Ingrese la edad del cliente: ";
    cin >> edadCliente;

    // Validación de rango de edad según algoritmo
    if (edadCliente < 15 || edadCliente > 100) {
        cout << "[SALIDA] Edad fuera de rango.\n";
        return 0;
    }

    cout << "Tipo de cliente (1. Cliente estrella, 2. Cliente Regular, 3. Cliente nuevo): ";
    cin >> tipoCliente;

    cout << "Dia de la semana (1=Lunes, 2=Martes, 3=Miercoles, 4=Jueves, 5=Viernes, 6=Sabado, 7=Domingo): ";
    cin >> diaSemana;

    // Stocks iniciales (100 para cada producto según algoritmo)
    double stockTomates = 100, stockRepollo = 100, stockPapas = 100;
    double stockCarneMolida = 100, stockCarneDeCerdo = 100, stockCarneAsar = 100;
    double stockCervezaN = 100, stockCervezaE = 100, stockVino = 100, stockVodka = 100;

    // Acumuladores de Clientes (libras/unidades)
    double librasTomatesCliente = 0, librasRepolloCliente = 0, librasPapazCliente = 0;
    double librasCarneMolidaCliente = 0, librasCarneDeCerdoCliente = 0, librasCarneAsarCliente = 0;
    double unidadesCervezaNCliente = 0, unidadesCervezaECliente = 0, unidadesVinoCliente = 0, unidadesVodkaCliente = 0;

    // Acumuladores de Subtotales por producto
    double subtotalTomates = 0, subtotalRepollo = 0, subtotalPapas = 0;
    double subtotalCarneMolida = 0, subtotalCarneDeCerdo = 0, subtotalCarneAsar = 0;
    double subtotalCervezaN = 0, subtotalCervezaE = 0, subtotalVino = 0, subtotalVodka = 0;

    // Totales vendidos generales
    double totalLibrosTomates = 0, totalLibrosRepollo = 0, totalLibrosPapas = 0;
    double totalLibrosCarneMolida = 0, totalLibrosCarneDeCerdo = 0, totalLibrosCarneAsar = 0;
    double totalUnidadesCervezaN = 0, totalUnidadesCervezaE = 0, totalUnidadesVino = 0, totalUnidadesVodka = 0;

    int contadorCarnes = 0; // Para controlar el descuento del segundo producto de carnes

    while (continuarCompra == 's' || continuarCompra == 'S') {
        char opcionMenu;
        cout << "\n--- MODULO 1: SELECCION DE PRODUCTO ---\n";
        cout << "Seleccione area (V = Verduras, C = Carnes, L = Licores): ";
        cin >> opcionMenu;

        if (opcionMenu == 'V' || opcionMenu == 'v') {
            int opcionVerduras;
            cout << "1- Tomates (L. 10)\n2- Repollo (L. 15)\n3- Papas (L. 17)\nElija opcion: ";
            cin >> opcionVerduras;

            double cantidad;
            cout << "Ingrese la cantidad en libras: ";
            cin >> cantidad;

            if (opcionVerduras == 1) {
                if (validarStock(cantidad, stockTomates)) {
                    cout << "\"Cantidad supera el stock\"\n";
                } else {
                    librasTomatesCliente += cantidad;
                    subtotalTomates = calcularSubtotal(10.0, librasTomatesCliente);
                    acumularVenta(totalLibrosTomates, totalLibrosTomates, subtotalTomates, cantidad); // Ajuste según lógica
                }
            } else if (opcionVerduras == 2) {
                if (validarStock(cantidad, stockRepollo)) {
                    cout << "\"Cantidad supera el stock\"\n";
                } else {
                    librasRepolloCliente += cantidad;
                    subtotalRepollo = calcularSubtotal(15.0, librasRepolloCliente);
                }
            } else if (opcionVerduras == 3) {
                if (validarStock(cantidad, stockPapas)) {
                    cout << "\"Cantidad supera el stock\"\n";
                } else {
                    librasPapazCliente += cantidad;
                    subtotalPapas = calcularSubtotal(17.0, librasPapazCliente);
                }
            } else {
                cout << "\"Opcion para verduras incorrecta\"\n";
            }

        } else if (opcionMenu == 'C' || opcionMenu == 'c') {
            int opcionCarnes;
            cout << "1- Carne Molida (L. 50)\n2- Carne de Cerdo (L. 70)\n3- Carne para Asar (L. 75)\nElija opcion: ";
            cin >> opcionCarnes;

            double cantidad;
            cout << "Ingrese la cantidad en libras: ";
            cin >> cantidad;

            contadorCarnes++; // Cuenta cuántos tipos de carne va comprando

            if (opcionCarnes == 1) {
                if (validarStock(cantidad, stockCarneMolida)) {
                    cout << "\"Cantidad supera el stock\"\n";
                } else {
                    librasCarneMolidaCliente += cantidad;
                    subtotalCarneMolida = calcularSubtotal(50.0, librasCarneMolidaCliente);
                }
            } else if (opcionCarnes == 2) {
                if (validarStock(cantidad, stockCarneDeCerdo)) {
                    cout << "\"Cantidad supera el stock\"\n";
                } else {
                    librasCarneDeCerdoCliente += cantidad;
                    subtotalCarneDeCerdo = calcularSubtotal(70.0, librasCarneDeCerdoCliente);
                }
            } else if (opcionCarnes == 3) {
                if (validarStock(cantidad, stockCarneAsar)) {
                    cout << "\"Cantidad supera el stock\"\n";
                } else {
                    librasCarneAsarCliente += cantidad;
                    subtotalCarneAsar = calcularSubtotal(75.0, librasCarneAsarCliente);
                }
            } else {
                cout << "\"Opcion para carne incorrecta\"\n";
            }

        } else if (opcionMenu == 'L' || opcionMenu == 'l') {
            // Validar edad para licores
            if (edadCliente < 18) {
                cout << "\"Prohibido vender licores a menores de 18 anos\"\n";
                continue;
            }

            int opcionLicores;
            cout << "1- Cerveza Nacional (L. 50)\n2- Cerveza Extranjera (L. 80)\n3- Vino (L. 200)\n4- Vodka (L. 100)\nElija opcion: ";
            cin >> opcionLicores;

            double cantidad;
            cout << "Ingrese la cantidad en unidades/botellas: ";
            cin >> cantidad;

            if (opcionLicores == 1) {
                if (validarStock(cantidad, stockCervezaN)) {
                    cout << "\"Cantidad supera el stock\"\n";
                } else {
                    unidadesCervezaNCliente += cantidad;
                    subtotalCervezaN = calcularSubtotal(50.0, unidadesCervezaNCliente);
                }
            } else if (opcionLicores == 2) {
                if (validarStock(cantidad, stockCervezaE)) {
                    cout << "\"Cantidad supera el stock\"\n";
                } else {
                    unidadesCervezaECliente += cantidad;
                    subtotalCervezaE = calcularSubtotal(80.0, unidadesCervezaECliente);
                }
            } else if (opcionLicores == 3) {
                if (validarStock(cantidad, stockVino)) {
                    cout << "\"Cantidad supera el stock\"\n";
                } else {
                    unidadesVinoCliente += cantidad;
                    subtotalVino = calcularSubtotal(200.0, unidadesVinoCliente);
                }
            } else if (opcionLicores == 4) {
                if (validarStock(cantidad, stockVodka)) {
                    cout << "\"Cantidad supera el stock\"\n";
                } else {
                    unidadesVodkaCliente += cantidad;
                    subtotalVodka = calcularSubtotal(100.0, unidadesVodkaCliente);
                }
            } else {
                cout << "\"Opcion incorrecta de Licores\"\n";
            }
        } else {
            cout << "\"Opcion de menu incorrecta\"\n";
        }

        cout << "Desea seguir comprando? (S/N): ";
        cin >> continuarCompra;
    }

    // ==========================================
    // PROCESAMIENTO DE TOTALES Y DESCUENTOS
    // ==========================================
    double subtotalVerduras = subtotalTomates + subtotalRepollo + subtotalPapas;
    double subtotalCarnes = subtotalCarneMolida + subtotalCarneDeCerdo + subtotalCarneAsar;
    double subtotalLicores = subtotalCervezaN + subtotalCervezaE + subtotalVino + subtotalVodka;
    double subtotalCliente = subtotalVerduras + subtotalCarnes + subtotalLicores;

    double descuentoClienteEstrella = 0;
    double descuentoClienteRegular = 0;
    double descuentoClienteNuevo = 0;
    double descuentoDiaSemana = 0;
    double descuentoViernes = 0;
    double descuentoSegundoProducto = 0;
    double descuentoSixpack = 0;

    // Descuento por tipo de cliente
    if (tipoCliente == 1) {
        descuentoClienteEstrella = calcularDescuento(subtotalCarnes + subtotalVerduras, 0.04);
    } else if (tipoCliente == 2) {
        descuentoClienteRegular = calcularDescuento(subtotalCarnes, 0.03);
    } else if (tipoCliente == 3) {
        descuentoClienteNuevo = calcularDescuento(subtotalLicores, 0.02);
    }

    // Descuento por día (Lunes = 1 o Miercoles = 3)
    if (diaSemana == 1 || diaSemana == 3) {
        descuentoDiaSemana = calcularDescuento(subtotalCliente, 0.03);
    }

    // Descuento Viernes para tercera edad (Viernes = 5)
    if (diaSemana == 5 && edadCliente >= 65) {
        descuentoViernes = calcularDescuento(subtotalCliente, 0.10);
    }

    // Descuento segundo producto en carnes (50%)
    if (contadorCarnes >= 2) {
        descuentoSegundoProducto = subtotalCarnes * 0.50; // Simplificado según estructura de celdas
    }

    // Descuento Six-pack de cerveza (L. 10 por cada 6 cervezas)
    double totalCervezas = unidadesCervezaNCliente + unidadesCervezaECliente;
    descuentoSixpack = (static_cast<int>(totalCervezas) / 6) * 10.0;

    // Total Descuentos
    double descuentoTotal = descuentoClienteEstrella + descuentoClienteRegular + descuentoClienteNuevo +
                            descuentoDiaSemana + descuentoViernes + descuentoSegundoProducto + descuentoSixpack;

    double subtotalConDescuento = subtotalCliente - descuentoTotal;

    // Impuestos (Llamada a función por referencia)
    double impuestoISV = 0, impuestoLicores = 0;
    calcularImpuestos(subtotalConDescuento, subtotalLicores, impuestoISV, impuestoLicores);
    double impuestoTotal = impuestoISV + impuestoLicores;

    double totalPagarLempiras = subtotalConDescuento + impuestoTotal;
    double tipoCambio = 24.5;
    double totalDolares = totalPagarLempiras / tipoCambio;

    // ==========================================
    // SALIDA (FACTURA)
    // ==========================================
    cout << "\n========================================\n";
    cout << "           FACTURA SUPERMERCADO         \n";
    cout << "========================================\n";
    cout << fixed << setprecision(2);
    cout << " Subtotal:          L. " << subtotalCliente << endl;
    cout << " Descuentos:        L. " << descuentoTotal << endl;
    cout << " Impuestos:         L. " << impuestoTotal << endl;
    cout << " Total a pagar:     L. " << totalPagarLempiras << endl;
    cout << " Total en Dolares:  $  " << totalDolares << endl;
    cout << "========================================\n";

    return 0;
}
