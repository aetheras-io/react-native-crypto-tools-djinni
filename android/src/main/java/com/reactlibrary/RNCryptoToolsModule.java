package com.reactlibrary;

import java.util.ArrayList;
import java.util.Arrays;
import android.util.Log;

import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.Callback;

import io.aetheras.djinni.GreetingService;

public class RNCryptoToolsModule extends ReactContextBaseJavaModule {
    private final ReactApplicationContext reactContext;
    private final GreetingService greetingService;

    public RNCryptoToolsModule(ReactApplicationContext reactContext) {
        super(reactContext);
        this.reactContext = reactContext;
        this.greetingService = GreetingService.createService();
    }

    @Override
    public String getName() {
        return "RNCryptoTools";
    }

    @ReactMethod
    public void whatsup(String stringArgument, Callback callback) {
        // TODO: Implement
        Log.i("RNCryptoToolsModule", "Argument:" + stringArgument);
        ArrayList<String> list = new ArrayList<String>(Arrays.asList(stringArgument.split(",")));
        Log.i("RNCryptoToolsModule-R",greetingService.greet(list));
        //callback.invoke(greetingService.greet(list));
    }
}