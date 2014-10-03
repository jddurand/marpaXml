/************************************************
  _Exclusion001 ~ 'PubidChar - _Lex008'
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Exclusion001b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  size_t             sizePubidCharl;
  size_t             sizeLex008l;
  marpaWrapperBool_t PubidCharb = _xml_1_0_PubidCharb(xml_1_0p, currenti, streamInp, &sizePubidCharl);
  marpaWrapperBool_t Lex008b    = _xml_1_0__Lex008b(xml_1_0p, currenti, streamInp, &sizeLex008l);

  if (PubidCharb == MARPAWRAPPER_BOOL_TRUE && Lex008b == MARPAWRAPPER_BOOL_FALSE) {
    if (streamInUtf8_userMarkb(streamInp, xml_1_0__Exclusion001) == STREAMIN_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    } else {
      *sizelp = sizePubidCharl;
      return MARPAWRAPPER_BOOL_TRUE;
    }
  } else {
    return MARPAWRAPPER_BOOL_FALSE;
  }
}
