package com.reactlibrary;

public class Utils {
    static final String HEXMAP = "0123456789ABCDEF";
    static final String HEXMAP_LOWER = "0123456789abcdef";


    public static byte[] HexStringToByteArray(String hexString)
    {
        int hexStringLength = hexString.length();
        byte[] data = new byte[hexStringLength / 2];
        for (int i = 0; i < hexStringLength; i += 2)
        {
            data[i / 2] = (byte) ((Character.digit(hexString.charAt(i), 16) << 4) + Character.digit(hexString.charAt(i+1), 16));
        }
        return data;
    }

    public static String ByteArrayToHexString(byte[] data)
    {
        if (data == null)
        {
            return null;
        }
        final StringBuilder hexStringBuilder = new StringBuilder( 2 * data.length );
        for ( final byte b : data )
        {
            hexStringBuilder.append(HEXMAP_LOWER.charAt((b & 0xF0) >> 4)).append(HEXMAP_LOWER.charAt((b & 0x0F)));
        }
        return hexStringBuilder.toString();
    }
}
