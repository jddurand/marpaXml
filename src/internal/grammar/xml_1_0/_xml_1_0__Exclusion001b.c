/************************************************
  _Exclusion001 ~ 'PubidChar - _Lex009'
  <PubidChar> ~ [a-zA-Z0-9-'()+,./:=?;!*#@$_%\x{20}\x{d}\x{a}]
  [']
  So this is just PubidChar without the '
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Exclusion001b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  marpaWrapperBool_t rcb;
  if ((currenti >= 0x61 && currenti <= 0x7a) /* [a-z] */ ||
      (currenti >= 0x41 && currenti <= 0x5a) /* [A-Z] */ ||
      (currenti >= 0x30 && currenti <= 0x39) /* [0-9] */ ||
      (currenti == 0x2d) /* - */ ||
      /* SKIPPED (currenti == 0x27) */ /* ' */ /* || */
      (currenti == 0x28) /* ( */ ||
      (currenti == 0x29) /* ) */ ||
      (currenti == 0x2b) /* + */ ||
      (currenti == 0x2c) /* , */ ||
      (currenti == 0x2e) /* . */ ||
      (currenti == 0x2f) /* / */ ||
      (currenti == 0x3a) /* : */ ||
      (currenti == 0x3d) /* = */ ||
      (currenti == 0x3f) /* ? */ ||
      (currenti == 0x3b) /* ; */ ||
      (currenti == 0x21) /* ! */ ||
      (currenti == 0x2a) /* * */ ||
      (currenti == 0x23) /* # */ ||
      (currenti == 0x40) /* @ */ ||
      (currenti == 0x24) /* $ */ ||
      (currenti == 0x5f) /* _ */ ||
      (currenti == 0x25) /* % */ ||
      (currenti == 0x20) /* #x20 */ ||
      (currenti == 0xd) /* #xd */ ||
      (currenti == 0xa) /* #xa */) {
#ifndef MARPAXML_NTRACE
  {
      marpaXmlLog_t *marpaXmlLogp = marpaWrapper_marpaXmlLogp(xml_1_0p->marpaWrapperp);
      MARPAXML_TRACEX("_xml_1_0__Exclusion001b : Accepted character 0x%lx", (long) currenti);
  }
#endif
    *sizelp = 1;
    rcb = MARPAWRAPPER_BOOL_TRUE;
  } else {
        rcb = MARPAWRAPPER_BOOL_FALSE;
  }
  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    if (streamInUtf8_userMarkb(streamInp, xml_1_0__Exclusion001) == STREAMIN_BOOL_FALSE) {
      rcb = MARPAWRAPPER_BOOL_FALSE;
    }
  }
  return rcb;
}
