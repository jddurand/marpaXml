/************************************************
  discard orthogonal rule
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__discardb(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  if (_xml_1_0__Lex002b(xml_1_0p, currenti, streamInp, sizelp) == MARPAWRAPPER_BOOL_TRUE) {
#ifndef MARPAXML_NTRACE
    marpaXmlLog_t *marpaXmlLogp = xml_1_0p->marpaXmlLogp;

    MARPAXML_TRACEX("Discarding, length %lld\n", (unsigned long) *sizelp);
#endif
    *sizelp = 0;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
