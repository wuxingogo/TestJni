/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class hbsi_dtd_test_MyActivity */

#ifndef _Included_hbsi_dtd_opengles_MyRenderer
#define _Included_hbsi_dtd_opengles_MyRenderer
#ifdef __cplusplus
extern "C" {
#endif
	JNIEXPORT void JNICALL Java_hbsi_dtd_opengles_MyRenderer_glinit(JNIEnv *env, jobject thisz);
	JNIEXPORT void JNICALL Java_hbsi_dtd_opengles_MyRenderer_changeSize(JNIEnv *env, jobject thisz,jint w, jint h);
	JNIEXPORT void JNICALL Java_hbsi_dtd_opengles_MyRenderer_drawFrame(JNIEnv *env, jobject thisz);


	static float last_timer = 0;//��¼�ϴε�ϵͳʱ��
	static float Angle = 0;//��ת�ĽǶ�
	void display(void);//opengl es ����Ҫ���ƴ������������

#ifdef __cplusplus
}
#endif
#endif