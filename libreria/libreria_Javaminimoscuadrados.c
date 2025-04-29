
#include <jni.h>
#include "libreria_Javaminimoscuadrados.h"
/*
 * Class:     libreria_Javaminimoscuadrados
 * Method:    suma
 * Signature: ([FI)F
 */
JNIEXPORT jfloat JNICALL Java_libreria_Javaminimoscuadrados_suma
  (JNIEnv *, jobject, jfloatArray, jint){
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
  (JNIEnv *, jobject, jfloatArray, jfloatArray, jint){jfloat *arr1 = (*env)->GetFloatArrayElements(env, vector1, NULL);
    jfloat *arr2 = (*env)->GetFloatArrayElements(env, vector2, NULL);
    jfloat suma = 0;
    for (int i = 0; i < n; i++) {
        suma += arr1[i] * arr2[i];
    }
    (*env)->ReleaseFloatArrayElements(env, vector1, arr1, 0);
    (*env)->ReleaseFloatArrayElements(env, vector2, arr2, 0);
    return suma;

}

/*
 * Class:     libreria_Javaminimoscuadrados
 * Method:    sumaCuadrados
 * Signature: ([FI)F
 */
JNIEXPORT jfloat JNICALL Java_libreria_Javaminimoscuadrados_sumaCuadrados
  (JNIEnv *, jobject, jfloatArray, jint){jfloat *arr = (*env)->GetFloatArrayElements(env, vector, NULL);
    jfloat suma = 0;
    for (int i = 0; i < n; i++) {
        suma += arr[i] * arr[i];
    }
    (*env)->ReleaseFloatArrayElements(env, vector, arr, 0);
    return suma;


}
/*
 * Class:     libreria_Javaminimoscuadrados
 * Method:    calcularPendiente
 * Signature: ([F[FI)F
 */
JNIEXPORT jfloat JNICALL Java_libreria_Javaminimoscuadrados_calcularPendiente
  (JNIEnv *, jobject, jfloatArray, jfloatArray, jint){
float *arrX = (*env)->GetFloatArrayElements(env, x, NULL);
    jfloat *arrY = (*env)->GetFloatArrayElements(env, y, NULL);

    jfloat sumaX = 0, sumaY = 0, sumaXY = 0, sumaX2 = 0;
    for (int i = 0; i < n; i++) {
        sumaX += arrX[i];
        sumaY += arrY[i];
        sumaXY += arrX[i] * arrY[i];
        sumaX2 += arrX[i] * arrX[i];
    }

    (*env)->ReleaseFloatArrayElements(env, x, arrX, 0);
    (*env)->ReleaseFloatArrayElements(env, y, arrY, 0);

    jfloat numerador = (n * sumaXY) - (sumaX * sumaY);
    jfloat denominador = (n * sumaX2) - (sumaX * sumaX);

    if (denominador == 0) return 0; // para evitar división por cero

    return numerador / denominador;
}

/*
 * Class:     libreria_Javaminimoscuadrados
 * Method:    calcularOrdenada
 * Signature: ([F[FIF)F
 */
JNIEXPORT jfloat JNICALL Java_libreria_Javaminimoscuadrados_calcularOrdenada
  (JNIEnv *, jobject, jfloatArray, jfloatArray, jint, jfloat){
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
