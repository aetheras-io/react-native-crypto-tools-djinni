// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from greeting.djinni

package io.aetheras.djinni;

public final class Greeting {


    /*package*/ final String mMessage;

    /*package*/ final GreetingColor mColor;

    public Greeting(
            String message,
            GreetingColor color) {
        this.mMessage = message;
        this.mColor = color;
    }

    public String getMessage() {
        return mMessage;
    }

    public GreetingColor getColor() {
        return mColor;
    }

    @Override
    public String toString() {
        return "Greeting{" +
                "mMessage=" + mMessage +
                "," + "mColor=" + mColor +
        "}";
    }

}