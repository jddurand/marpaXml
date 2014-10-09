/************************************************
  discard orthogonal rule
  This is basically a lighter version of S that
  can move the stream forward
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__discardb(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  size_t sizel = 0;

  do {
    if ((currenti == 0x20) /* #x20 */ ||
      (currenti == 0x9) /* #x9 */ ||
      (currenti == 0xd) /* #xd */ ||
      (currenti == 0xa) /* #xa */) {
      sizel++;
    
    } else {
          break;
    }
  } while (streamInUtf8_nexti(streamInp, &currenti) == STREAMIN_BOOL_TRUE);

  if (sizel > 0) {
    *sizelp = 0;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
