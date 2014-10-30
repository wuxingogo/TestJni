package hbsi.dtd.opengles;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.opengl.GLSurfaceView.Renderer;

public class MyRenderer implements Renderer {

	static{
		System.loadLibrary("MyRenderer");
	}
	public native void drawFrame();
	public native void changeSize(int width,int height);
	public native void glinit();
	@Override
	public void onDrawFrame(GL10 gl) {
		drawFrame();
		try {
			Thread.sleep(30);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	@Override
	public void onSurfaceChanged(GL10 gl, int width, int height) {
		changeSize(width,height);
	}

	@Override
	public void onSurfaceCreated(GL10 gl, EGLConfig eglConfig) {
		glinit();
	}


}
