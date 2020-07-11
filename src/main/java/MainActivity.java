package com.example.myapp;

import android.app.Activity;
import android.os.Bundle;
import android.view.Window;
import android.webkit.WebSettings;
import android.widget.TextView;
import android.webkit.WebView;
import android.webkit.JavascriptInterface;

public class MainActivity extends Activity
{
    @Override
    public void onCreate(Bundle savedInstanceState) {
    	requestWindowFeature(Window.FEATURE_NO_TITLE);
        super.onCreate(savedInstanceState);

        WebView webview = new WebView(this);
        WebSettings settings = webview.getSettings();
		settings.setJavaScriptEnabled(true);

		settings.setBuiltInZoomControls(true);
		settings.setDomStorageEnabled(true);
		settings.setLoadWithOverviewMode(true);
		webview.loadUrl("file:///android_asset/index.html");

		webview.addJavascriptInterface(new backend(), "b");

        setContentView(webview);
    }

	// Access like "b.test()"
	public class backend {
		@JavascriptInterface
		public String stringStuffs() {
			return stringFromJNI();
		}
	}

	public native String  stringFromJNI();
	public native String  unimplementedStringFromJNI();

	static {
        System.loadLibrary("hello-jni");
    }
}
