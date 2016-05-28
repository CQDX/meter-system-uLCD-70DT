
func rMagicObject1(var action, var object, var newVal, var *ptr)

    var bytes[4];

    if (action != WRITE_MAGIC_BYTES || newVal != 4) goto exit;  // check command and number of bytes

    // arrange the received bytes
    bytes[1] := ptr[0] << 8 + ptr[1];
    bytes[0] := ptr[2] << 8 + ptr[3];

    writeToLeddigits(bytes, 1, UNSIGNED);  //SIGNED ALSO GOES TO Leddigits index 0 - mdorough 2/16/2016

exit:
    seroutX(ACK) ;
endfunc
