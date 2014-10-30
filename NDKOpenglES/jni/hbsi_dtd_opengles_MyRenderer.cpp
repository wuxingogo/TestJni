#include "hbsi_dtd_opengles_MyRenderer.h"

#include <android/log.h>
#include <GLES2/gl2.h>
#include <GLES/gl.h>
#include <GLES2/gl2ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <sys/time.h>

#define  LOG_TAG    "libgljni"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

JNIEXPORT void JNICALL Java_hbsi_dtd_opengles_MyRenderer_glinit(JNIEnv *env, jobject thisz) {
    glClearColor(0, 1, 0, 1.0f);
    glEnable(GL_CULL_FACE);	//开启剔除操作效果
    glEnable(GL_DEPTH_TEST);//开启深度测试
    //LOGE("INIT");
};
JNIEXPORT void JNICALL Java_hbsi_dtd_opengles_MyRenderer_changeSize(JNIEnv *env, jobject thisz,jint w, jint h) {
    GLfloat ratio = (GLfloat) w / h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustumf(-ratio, ratio, -1.0f, 1.0f, 1.0f, 10.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //LOGE("CHANGE SIZE");
};
JNIEXPORT void JNICALL Java_hbsi_dtd_opengles_MyRenderer_drawFrame(JNIEnv *env, jobject thisz) {
	struct timeval now_timer;//时间结构体
	gettimeofday(&now_timer, NULL);
	last_timer = now_timer.tv_usec + 1000000 * now_timer.tv_sec;//获取运行diplay函数前的时间，
	display();
	gettimeofday(&now_timer, NULL);
	Angle += (now_timer.tv_usec + 1000000 * now_timer.tv_sec - last_timer);//时间差除以一个系数给角度,可以自己改变这个系数
};
void display() {
	glClearColor(0, 1, 1, 1.0f);
	//clear bit
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//LOGE("FRAME");

	static GLfloat vertices[] = { 0, 0, 1.0, //0
			0, 0, 0, //1
			0, 1.0, 0, //2
			0, 1.0, 1.0, //3
			1.0, 0, 1.0, //4
			1.0, 0, 0, //5
			1.0, 1.0, 0, //6
			1.0, 1.0, 1.0 //7
			};

	//每个面的索引，里面的数字代表这第几个坐标点
	static GLbyte frontIndices[] = { 4, 5, 6, 7 };
	static GLbyte rightIndices[] = { 1, 2, 6, 5 };
	static GLbyte bottomIndices[] = { 0, 1, 5, 4 };
	static GLbyte backIndices[] = { 0, 3, 2, 1 };
	static GLbyte leftIndices[] = { 0, 4, 7, 3 };
	static GLbyte topIndices[] = { 2, 3, 7, 6 };

	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
	//glTranslatef(0, 0, -18.0f + modelRote * 0.17);
	glTranslatef(0, 0, -3.0f);
	glRotatef(Angle * 1.2f, 0.0f, 1.0f, 0.0f);
	glRotatef(Angle * 0.9f, -1.0f, 0.0f, 0.0f);
	glTranslatef(-0.5f, -0.5f, -0.5f);
	glEnableClientState (GL_VERTEX_ARRAY);
	//glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	//glColorPointer(3, GL_FLOAT, 0, vertices);
	glDrawElements(GL_TRIANGLE_FAN, 4, GL_UNSIGNED_BYTE, frontIndices); //绘制一个面
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
