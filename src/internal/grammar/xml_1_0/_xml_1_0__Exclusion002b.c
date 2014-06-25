/************************************************
  _Exclusion002 ~ '_Lex015_any - _Gen056'
  _Gen056 ::= _Lex015_any _Lex016 _Lex015_any
  _Lex016 ~ ']]>'

  which means:

  _Exclusion002 ~ _Lex015_any minus _Lex016
  
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Exclusion002b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  size_t             sizeLex015l;
  size_t             sizeLex016l;
  size_t             sizel;

  if (_xml_1_0__Lex016b(xml_1_0p, currenti, streamInp, &sizeLex016l) == MARPAWRAPPER_BOOL_TRUE) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_FALSE) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  /* Consume any Lex015 */
  sizel = 0;
  while(_xml_1_0__Lex015b(xml_1_0p, currenti, streamInp, &sizeLex015l) == MARPAWRAPPER_BOOL_TRUE) {
    sizel += sizeLex015l;
    currenti = streamInUtf8_nexti(streamInp);
  }
  if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  if (sizel > 0) {
    *sizelp = sizel;
    return MARPAWRAPPER_BOOL_TRUE;
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
