package com.reactlibrary;

import com.reactlibrary.Utils;

import android.util.Log;
import java.nio.charset.StandardCharsets;

import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.Promise;

public class RNSecp256k1Module extends ReactContextBaseJavaModule {
    private final ReactApplicationContext reactContext;

    public RNSecp256k1Module(ReactApplicationContext reactContext) {
        super(reactContext);
        this.reactContext = reactContext;
    }

    @Override
    public String getName() {
        return "RNSecp256k1";
    }


    @ReactMethod
    public void hexTest(String key, Promise promise) {
        try {
            Log.i(this.getName(), "receivedHex: " + key);
            byte[] data = Utils.HexStringToByteArray(key);
            final StringBuilder bldr = new StringBuilder( 2 * data.length );
            bldr.append("[ ");
            for ( final byte b : data )
            {
                bldr.append(b);
                bldr.append(" ");
            }
            bldr.append("]");
            Log.i(this.getName(), "hexToBytes: " + bldr.toString());

            String convertedBack = Utils.ByteArrayToHexString(data);
            Log.i(this.getName(), "bytesToHex: " + convertedBack);
            promise.resolve(convertedBack);
        }
        catch(Exception e) {
            promise.reject(e);
        }
    }
}
