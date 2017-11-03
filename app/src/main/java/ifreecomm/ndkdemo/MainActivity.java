package ifreecomm.ndkdemo;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = "MainActivity";

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(stringFromJNI() + "\n" + fuck());
    }


    public void byJni(View view) {

        jniCallC();     //c++ 调用非静态java方法
//      staticJniCallC();   //c++ 调用静态java方法
    }

    public static void staticMethodByJni(String jString) {
        Log.e(TAG, "methodByJni:" + jString);
    }

    public void methodByJni(String jString) {
        Log.e(TAG, "methodByJni:" + jString);
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public native String fuck();

    public native void jniCallC();

    public native void staticJniCallC();
}
