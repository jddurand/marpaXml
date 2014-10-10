/************************************************
  _Exclusion002 ~ '_Lex016_many - _Gen060'
  <_Lex016_many> ~ [^<&]+
  _Gen060 ::= _Gen056 _Lex017 _Gen058
  _Gen056 ::= _Lex016_many
  _Gen056 ::=
  _Gen058 ::= _Lex018_many
  _Gen058 ::=
  <_Lex017> ~ ']]>'
  <_Lex016_many> ~ [^<&]+
  <_Lex018_many> ~ [^<&]+

  which means:

  _Exclusion002 ~ [^<&]+ minus ']]>' everywhere
  
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Exclusion002b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  size_t             sizel;
  signed int         lastthreei[3] = {0, 0, 0};

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_FALSE) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  /* Consume many Lex016 - we KNOW in advance that lex015 does not play with utf8 mark and have a size 1 */
  sizel = 0;
  while (! ((currenti == 0x3c) /* < */ || (currenti == 0x26) /* & */)) {
#ifndef MARPAXML_NTRACE
  {
      marpaXmlLog_t *marpaXmlLogp = marpaWrapper_marpaXmlLogp(xml_1_0p->marpaWrapperp);
      MARPAXML_TRACEX("_xml_1_0__Exclusion002b : Accepted character 0x%lx", (long) currenti);
  }
#endif
    /* For performance reason it is better to do the test on sizel >= 3 first: the probability      */
    /* to have three or more characters is much higher than having less than three characters       */
    if (sizel >= 3) {
      if (currenti == '>' && lastthreei[1] == ']' && lastthreei[2] == ']') {
#ifndef MARPAXML_NTRACE
        {
          marpaXmlLog_t *marpaXmlLogp = marpaWrapper_marpaXmlLogp(xml_1_0p->marpaWrapperp);
          MARPAXML_TRACE0("_xml_1_0__Exclusion002b : Got \"]]>\"");
        }
#endif
	break;
      }
      lastthreei[0] = lastthreei[1];
      lastthreei[1] = lastthreei[2];
      lastthreei[2] = currenti;
    } else if (sizel == 2) {
      if (currenti == '>' && lastthreei[0] == ']' && lastthreei[1] == ']') {
	break;
      }
      lastthreei[2] = currenti;
    } else if (sizel == 1) {
      lastthreei[1] = currenti;
    } else {
      lastthreei[0] = currenti;
    }
    sizel++;
    if (streamInUtf8_nexti(streamInp, &currenti) == STREAMIN_BOOL_FALSE) {
      break;
    }
  }

  if (sizel > 0) {
    if (streamInUtf8_userMarkPreviousb(streamInp, xml_1_0__Exclusion002) == STREAMIN_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
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
