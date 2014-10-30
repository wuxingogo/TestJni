package hbsi.dtd.opengles;

import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;

public class MainActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		
		GLSurfaceView view = new GLSurfaceView(this);
		this.setContentView(view);
		
		view.setRenderer(new MyRenderer());
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}
	

}
