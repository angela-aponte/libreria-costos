package aplicacion;

import libreria.Javaminimoscuadrados;

public class Aplicacion {

    // Declaramos un objeto que represente a la biblioteca de mínimos cuadrados
    Javaminimoscuadrados minimosCuadrados = null;

    static {
        try {
            System.loadLibrary("mincuadrados"); // Asegúrate que el nombre coincida con tu .so o .dll generado
        } catch (UnsatisfiedLinkError e) {
            System.err.println("Error al cargar la biblioteca nativa 'mincuadrados': " + e);
            System.exit(1);
        }
    }

    public Aplicacion() {
        this.minimosCuadrados = new Javaminimoscuadrados();

        float[] vector1 = {1f, 2f, 3f, 4f, 5f, 6f};
	float[] vector2 = {1500f, 2000f, 2200f, 2400f, 2800f, 3000f};
        int n = vector1.length;

        float sumaVector1 = minimosCuadrados.suma(vector1, n);
        System.out.println("La suma del vector1 es: " + sumaVector1);

        float sumaProducto = minimosCuadrados.sumaProducto(vector1, vector2, n);
        System.out.println("La suma del producto de los vectores es: " + sumaProducto);

        float sumaCuadradosVector1 = minimosCuadrados.sumaCuadrados(vector1, n);
        System.out.println("La suma de los cuadrados del vector1 es: " + sumaCuadradosVector1);

        float pendiente = minimosCuadrados.calcularPendiente(vector1, vector2, n);
        System.out.println("La pendiente de la regresión lineal es: " + pendiente);

        float ordenada = minimosCuadrados.calcularOrdenada(vector1, vector2, n, pendiente);
        System.out.println("La ordenada al origen de la regresión lineal es: " + ordenada);
	float[] pronosticos = minimosCuadrados.pronosticarVentas(new float[]{7f, 8f, 9f, 10f, 11f, 12f}, pendiente, ordenada, 6);
	for(int i = 0; i < 6; i++) System.out.println(pronosticos[i]);
    }

    public static void main(String[] args) {
        new Aplicacion();
    }
}
