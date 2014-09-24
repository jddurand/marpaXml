/************************************************
  discard orthogonal rule
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__discardb(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (_xml_1_0__Lex002b(xml_1_0p, currenti, streamInp, sizelp) == MARPAWRAPPER_BOOL_TRUE) {
    signed int nexti;
    size_t     sizel = 0;
#ifndef MARPAXML_NTRACE
    marpaXmlLog_t *marpaXmlLogp = xml_1_0p->marpaXmlLogp;

    MARPAXML_TRACEX("Discarding, length %lld\n", (unsigned long) *sizelp);
#endif
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
