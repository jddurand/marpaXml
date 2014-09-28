/************************************************
  discard orthogonal rule
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_1__discardb(xml_1_1_t *xml_1_1p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (_xml_1_1__Lex003b(xml_1_1p, currenti, streamInp, sizelp) == MARPAWRAPPER_BOOL_TRUE) {
    signed int nexti;
    size_t     sizel = 0;

    /* Make sure the pointer in the stream move by *sizelp characters */
    while (sizel++ <= *sizelp) {
      if (streamInUtf8_nexti(streamInp, &nexti) == STREAMIN_BOOL_FALSE) {
        return MARPAWRAPPER_BOOL_FALSE;
      }
    }
    *sizelp = 0;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
