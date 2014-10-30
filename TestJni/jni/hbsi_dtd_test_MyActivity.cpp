#include "hbsi_dtd_test_MyActivity.h"

JNIEXPORT jint JNICALL Java_hbsi_dtd_test_MyActivity_intMethod
(JNIEnv *, jobject, jint){
    return 5;
}

JNIEXPORT jboolean JNICALL Java_hbsi_dtd_test_MyActivity_booleanMethod
(JNIEnv *, jobject, jboolean){
    return false;
}

JNIEXPORT jstring JNICALL Java_hbsi_dtd_test_MyActivity_stringMethod
(JNIEnv *, jobject, jstring str){
    return str;
}

JNIEXPORT jint JNICALL Java_hbsi_dtd_test_MyActivity_intArrayMethod
(JNIEnv * evn, jobject, jintArray array){

	jint* arr;
	arr =evn->GetIntArrayElements(array,JNI_FALSE);
	return arr[5];
//    return evn->GetArrayLength(array);
}

/*
 *	jni中不可以直接得到数组的长度，利用JNIEvn是所在线程的指针，由他来获取各种数组的长度
 *
		函数						Java 数组类型		本地类型
		GetBooleanArrayElements	jbooleanArray	jboolean
		GetByteArrayElements	jbyteArray		jbyte
		GetCharArrayElements	jcharArray		jchar
		GetShortArrayElements	jshortArray		jshort
		GetIntArrayElements		jintArray		jint
		GetLongArrayElements	jlongArray		jlong
		GetFloatArrayElements	jfloatArray		jfloat
		GetDoubleArrayElements	jdoubleArray	jdouble


		得到数组元素的指针的方法主要有GetIntArrayElements与GetIntArrayRegion
		evn->
 *
 *
 *
 *
 */
