package aplicacion;

import libreria.Javaminimoscuadrados;

public class Aplicacion {

    // Declaramos un objeto que represente a la biblioteca de mínimos cuadrados
    Javaminimoscuadrados minimosCuadrados = null;

    static {
        try {
            System.loadLibrary("mincuadrados"); // Asegúrate que el nombre coincida con tu .so o .dll generado
        } catch (UnsatisfiedLinkError e) {
            System.err.println("Error al cargar la biblioteca nativa 'minimoscuadrados': " + e);
            System.exit(1);
        }
    }

    public Aplicacion() {
        this.minimosCuadrados = new Javaminimoscuadrados();

        float[] vector1 = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
        float[] vector2 = {2.0f, 4.0f, 5.0f, 4.0f, 5.0f};
        int n = vector1.length;

        float sumaVector1 = minimosCuadrados.suma(vector1, n);
        System.out.println("La suma del vector1 es: " + sumaVector1);

        float sumaProducto = minimosCuadrados.sumaProducto(vector1, vector2, n);
        System.out.println("La suma del producto de los vectores es: " + sumaProducto);

        float sumaCuadradosVector1 = minimosCuadrados.sumaCuadrados(vector1, n);
        System.out.println("La suma de los cuadrados del vector1 es: " + sumaCuadradosVector1);

        // Datos de ejemplo para regresión lineal
        float[] xData = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
        float[] yData = {2.1f, 3.9f, 6.2f, 8.1f, 9.8f};
        int numPuntos = xData.length;

        float pendiente = minimosCuadrados.calcularPendiente(xData, yData, numPuntos);
        System.out.println("La pendiente de la regresión lineal es: " + pendiente);

        float ordenada = minimosCuadrados.calcularOrdenada(xData, yData, numPuntos, pendiente);
        System.out.println("La ordenada al origen de la regresión lineal es: " + ordenada);
    }

    public static void main(String[] args) {
        new Aplicacion();
    }
}
