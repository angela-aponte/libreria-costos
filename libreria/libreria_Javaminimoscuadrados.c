
#include <jni.h>
#include <stdlib.h>
#include "libreria_Javaminimoscuadrados.h"
/*
 * Class:     libreria_Javaminimoscuadrados
 * Method:    suma
 * Signature: ([FI)F
 */
JNIEXPORT jfloat JNICALL Java_libreria_Javaminimoscuadrados_suma
  (JNIEnv *env, jobject obj, jfloatArray vector, jint n) {

    jfloat *arr = (*env)->GetFloatArrayElements(env, vector, NULL);
    jfloat suma = 0;

    for (int i = 0; i < n; i++) {
        suma += arr[i];
    }

    (*env)->ReleaseFloatArrayElements(env, vector, arr, 0);
    return suma;
}

/*
 * Class:     libreria_Javaminimoscuadrados
 * Method:    sumaProducto
 * Signature: ([F[FI)F
 */
JNIEXPORT jfloat JNICALL Java_libreria_Javaminimoscuadrados_sumaProducto
  (JNIEnv *env, jobject obj, jfloatArray vector1, jfloatArray vector2, jint n) {

    jfloat *arr1 = (*env)->GetFloatArrayElements(env, vector1, NULL);
    jfloat *arr2 = (*env)->GetFloatArrayElements(env, vector2, NULL);
    jfloat sumaProducto = 0;

    for (int i = 0; i < n; i++) {
        sumaProducto += arr1[i] * arr2[i];
    }

    (*env)->ReleaseFloatArrayElements(env, vector1, arr1, 0);
    (*env)->ReleaseFloatArrayElements(env, vector2, arr2, 0);
    return sumaProducto;
}

/*
 * Class:     libreria_Javaminimoscuadrados
 * Method:    sumaCuadrados
 * Signature: ([FI)F
 */
JNIEXPORT jfloat JNICALL Java_libreria_Javaminimoscuadrados_sumaCuadrados
  (JNIEnv *env, jobject obj, jfloatArray vector, jint n) {

    jfloat *arr = (*env)->GetFloatArrayElements(env, vector, NULL);
    jfloat sumaCuadrados = 0;

    for (int i = 0; i < n; i++) {
        sumaCuadrados += arr[i] * arr[i];
    }

    (*env)->ReleaseFloatArrayElements(env, vector, arr, 0);
    return sumaCuadrados;
}
/*
 * Class:     libreria_Javaminimoscuadrados
 * Method:    calcularPendiente
 * Signature: ([F[FI)F
 */
JNIEXPORT jfloat JNICALL Java_libreria_Javaminimoscuadrados_calcularPendiente
  (JNIEnv *env, jobject obj, jfloatArray x, jfloatArray y, jint n) {

    jfloat *arrX = (*env)->GetFloatArrayElements(env, x, NULL);
    jfloat *arrY = (*env)->GetFloatArrayElements(env, y, NULL);
    jfloat sumaXY = 0, sumaX = 0, sumaY = 0, sumaX2 = 0;

    for (int i = 0; i < n; i++) {
        sumaXY += arrX[i] * arrY[i];
        sumaX += arrX[i];
        sumaY += arrY[i];
        sumaX2 += arrX[i] * arrX[i];
    }

    (*env)->ReleaseFloatArrayElements(env, x, arrX, 0);
    (*env)->ReleaseFloatArrayElements(env, y, arrY, 0);

    return (n * sumaXY - sumaX * sumaY) / (n * sumaX2 - sumaX * sumaX);
}
/*
 * Class:     libreria_Javaminimoscuadrados
 * Method:    calcularOrdenada
 * Signature: ([F[FIF)F
 */
JNIEXPORT jfloat JNICALL Java_libreria_Javaminimoscuadrados_calcularOrdenada
  (JNIEnv *env, jobject obj, jfloatArray x, jfloatArray y, jint n, jfloat pendiente) {

    jfloat *arrX = (*env)->GetFloatArrayElements(env, x, NULL);
    jfloat *arrY = (*env)->GetFloatArrayElements(env, y, NULL);
    jfloat sumaX = 0, sumaY = 0;

    for (int i = 0; i < n; i++) {
        sumaX += arrX[i];
        sumaY += arrY[i];
    }

    (*env)->ReleaseFloatArrayElements(env, x, arrX, 0);
    (*env)->ReleaseFloatArrayElements(env, y, arrY, 0);

    return (sumaY - pendiente * sumaX) / n;
}
/*
 * Class:     libreria_Javaminimoscuadrados
 * Method:    pronosticarVentas
 * Signature: ([FFFI)[F
 */
JNIEXPORT jfloatArray JNICALL Java_libreria_Javaminimoscuadrados_pronosticarVentas
  (JNIEnv *env, jobject obj, jfloatArray meses, jfloat pendiente, jfloat ordenada, jint n) {

    jfloat *xMeses = (*env)->GetFloatArrayElements(env, meses, 0);

    jfloatArray resultado = (*env)->NewFloatArray(env, n);
    jfloat *yVentas =(jfloat*) malloc(n * sizeof(jfloat));

    for (int i = 0; i < n; i++) {
        yVentas[i] = ordenada + pendiente * xMeses[i]; // Y = a + bX
    }

    (*env)->SetFloatArrayRegion(env, resultado, 0, n, yVentas);

    // Liberar memoria
    free(yVentas);
    (*env)->ReleaseFloatArrayElements(env, meses, xMeses, 0);

    return resultado;
}
