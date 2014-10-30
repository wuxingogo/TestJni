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
 *	jni�в�����ֱ�ӵõ�����ĳ��ȣ�����JNIEvn�������̵߳�ָ�룬��������ȡ��������ĳ���
 *
		����						Java ��������		��������
		GetBooleanArrayElements	jbooleanArray	jboolean
		GetByteArrayElements	jbyteArray		jbyte
		GetCharArrayElements	jcharArray		jchar
		GetShortArrayElements	jshortArray		jshort
		GetIntArrayElements		jintArray		jint
		GetLongArrayElements	jlongArray		jlong
		GetFloatArrayElements	jfloatArray		jfloat
		GetDoubleArrayElements	jdoubleArray	jdouble


		�õ�����Ԫ�ص�ָ��ķ�����Ҫ��GetIntArrayElements��GetIntArrayRegion
		evn->
 *
 *
 *
 *
 */
