/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class libreria_Javaminimoscuadrados */

#ifndef _Included_libreria_Javaminimoscuadrados
#define _Included_libreria_Javaminimoscuadrados
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     libreria_Javaminimoscuadrados
 * Method:    suma
 * Signature: ([FI)F
 */
JNIEXPORT jfloat JNICALL Java_libreria_Javaminimoscuadrados_suma
  (JNIEnv *, jobject, jfloatArray, jint);

/*
 * Class:     libreria_Javaminimoscuadrados
 * Method:    sumaProducto
 * Signature: ([F[FI)F
 */
JNIEXPORT jfloat JNICALL Java_libreria_Javaminimoscuadrados_sumaProducto
  (JNIEnv *, jobject, jfloatArray, jfloatArray, jint);

/*
 * Class:     libreria_Javaminimoscuadrados
 * Method:    sumaCuadrados
 * Signature: ([FI)F
 */
JNIEXPORT jfloat JNICALL Java_libreria_Javaminimoscuadrados_sumaCuadrados
  (JNIEnv *, jobject, jfloatArray, jint);

/*
 * Class:     libreria_Javaminimoscuadrados
 * Method:    calcularPendiente
 * Signature: ([F[FI)F
 */
JNIEXPORT jfloat JNICALL Java_libreria_Javaminimoscuadrados_calcularPendiente
  (JNIEnv *, jobject, jfloatArray, jfloatArray, jint);

/*
 * Class:     libreria_Javaminimoscuadrados
 * Method:    calcularOrdenada
 * Signature: ([F[FIF)F
 */
JNIEXPORT jfloat JNICALL Java_libreria_Javaminimoscuadrados_calcularOrdenada
  (JNIEnv *, jobject, jfloatArray, jfloatArray, jint, jfloat);

/*
 * Class:     libreria_Javaminimoscuadrados
 * Method:    pronosticarVentas
 * Signature: ([FFFI)[F
 */
JNIEXPORT jfloatArray JNICALL Java_libreria_Javaminimoscuadrados_pronosticarVentas
  (JNIEnv *, jobject, jfloatArray, jfloat, jfloat, jint);

#ifdef __cplusplus
}
#endif
#endif
