package com.example.myapp;

import android.app.Activity;
import android.os.Bundle;
import android.view.Window;
import android.webkit.WebSettings;
import android.widget.TextView;
import android.webkit.WebView;
import android.webkit.JavascriptInterface;
import android.text.TextUtils;

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
			return TextUtils.join(", ", arrayTest());
		}
	}

	public native String stringFromJNI();
	public native String[] arrayTest();

	static {
        System.loadLibrary("hello-jni");
    }
}
