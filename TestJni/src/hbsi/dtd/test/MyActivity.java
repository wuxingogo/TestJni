package hbsi.dtd.test;

import android.os.Bundle;
import android.app.Activity;
import android.util.Log;
import android.view.Menu;
import android.view.View;

public class MyActivity extends Activity {

	
	
	public native int intMethod(int n);
	public native boolean booleanMethod(boolean bool);
	public native String stringMethod(String text);
	public native int intArrayMethod(int[] intArray);
	
	static{
		System.loadLibrary("MyActivity");
	}
	
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		
		Log.e("", "begin.\n");
		View v = new View(this);
		
		this.setContentView(v);
		
		Log.e("intMethod",""+this.intMethod(5));
		Log.e("booleanMethod",""+this.booleanMethod(true));
		Log.e("stringMethod",""+this.stringMethod("liangyuekai"));
		Log.e("", "数组第5个元素"+this.intArrayMethod(new int[]{1,2,3,4,5,6,7,8,9,0,11,12,1231,12314,15}));
		
	
	}



}
