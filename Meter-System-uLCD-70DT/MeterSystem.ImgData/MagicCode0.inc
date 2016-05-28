
// MagicCode0
//
#DATA
    word uSDidx
    iiLeddigits0,
    iiLeddigits1
#END

#constant UNSIGNED 0
#constant SIGNED 1

func writeToLeddigits(var address, var index, var format)
    var ledDigitsPr;         // pointer to access properties of a LED digits object
    var left, digits, width;
    var i, j, k, c, lb, x;
    var length;
    var buffer[15];

    ledDigitsPr := oLedDigitsn + 10 * index;        // set to RAM location, so Ofs_Digits_* values are valid

    left    := ledDigitsPr[Ofs_Digits_Left];        // get the x coordinate of a LED digits object
    digits  := ledDigitsPr[Ofs_Digits_Digits];      // get the number of digits of a LED digits object
    width   := ledDigitsPr[Ofs_Digits_Widthdigit];  // get the width of a digit of a LED digits object

    j := str_Ptr(address);

    if(format == UNSIGNED)
        to(buffer); str_Printf(&j, "%lu");  // format: long decimal, unsigned
    else if(format == SIGNED)
        to(buffer); str_Printf(&j, "%ld");  // format: long decimal, signed
    endif

    k := str_Ptr(buffer);
    length := str_Length(k);

    if(length > digits) goto exit;

    lb := 0;

    x := left + (width * (digits - length));
    for (i := 0; i < length; i++)
        c := str_GetByte(k++);
        if ((c == 0x30) && (lb))        // also check mindigits
            c := 10 ;
            lb := 0 ;
        else if (c == '-')
            c := 11 ;
        else
            c &= 0x0F ;
        endif
        img_SetWord(hndl, uSDidx[index], IMAGE_INDEX, c);
        img_SetWord(hndl, uSDidx[index], IMAGE_XPOS, x) ;
        img_Show(hndl, uSDidx[index]);
        x += width ;
    next

    // clear leading figures
    x := left;
    for(i := 0; i < (digits - length); i++)
        img_SetWord(hndl, uSDidx[index], IMAGE_INDEX, 10);
        img_SetWord(hndl, uSDidx[index], IMAGE_XPOS, x) ;
        img_Show(hndl, uSDidx[index]);
        x += width ;
    next
exit:
    return;
endfunc
