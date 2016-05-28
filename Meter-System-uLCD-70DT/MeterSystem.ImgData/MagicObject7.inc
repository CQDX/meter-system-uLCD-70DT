//
// Added 2/20/2016 8:18:37 PM
//
func rMagicObject7(var action, var object, var newVal, var *ptr)

    var bytes[4];

    if (action != WRITE_MAGIC_BYTES || newVal != 4) goto exit;  // check command and number of bytes

    // arrange the received bytes
    bytes[1] := ptr[0] << 8 + ptr[1];
    bytes[0] := ptr[2] << 8 + ptr[3];

    writeToLeddigits(bytes, 7, UNSIGNED);
exit:
    seroutX(ACK) ;
endfunc
