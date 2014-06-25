/************************************************
  _Exclusion004 ~ 'Name - _Gen074'
  Name ::= NameStartChar _Gen012_any
  _Gen012 ::= NameChar
  NameChar ::= NameStartChar
  NameChar ::= _Lex004
  _Gen074 ::= _Gen068 _Gen070 _Gen072
  _Gen068 ::= _Lex021
  _Gen068 ::= _Lex022
  _Gen070 ::= _Lex023
  _Gen070 ::= _Lex024
  _Gen072 ::= _Lex025
  _Gen072 ::= _Lex026
  _Lex021 ~ 'X'
  _Lex022 ~ 'x'
  _Lex023 ~ 'M'
  _Lex024 ~ 'm'
  _Lex025 ~ 'L'
  _Lex026 ~ 'l'

  which means:

  _Exclusion003 ~ Name minus [xX][mM][lL]
  
 ************************************************/
static C_INLINE marpaWrapperBool_t _xml_1_0__Exclusion004b(xml_1_0_t *xml_1_0p, signed int currenti, streamIn_t *streamInp, size_t *sizelp) {
  signed int           got = currenti;
  size_t               sizel = 0;
  size_t               dummySizel = 0;
  marpaWrapperBool_t   rcb = MARPAWRAPPER_BOOL_FALSE;
  marpaWrapperBool_t   xb = MARPAWRAPPER_BOOL_FALSE;
  marpaWrapperBool_t   mb = MARPAWRAPPER_BOOL_FALSE;
  marpaWrapperBool_t   lb = MARPAWRAPPER_BOOL_FALSE;

  /* We will move current character, so we want to restore it */
  if (streamInUtf8_markb(streamInp) == STREAMIN_BOOL_FALSE) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  do {
    if (sizel == 0) {
      if (_xml_1_0__Lex021b(xml_1_0p, currenti, streamInp, &dummySizel) == MARPAWRAPPER_BOOL_TRUE ||
          _xml_1_0__Lex022b(xml_1_0p, currenti, streamInp, &dummySizel) == MARPAWRAPPER_BOOL_TRUE) {
        /* Per def Lex021b or Lex022b also matched NameStartCharb */
        xb = MARPAWRAPPER_BOOL_TRUE;
        sizel++;
      } else if (_xml_1_0_NameStartCharb(xml_1_0p, currenti, streamInp, &dummySizel) == MARPAWRAPPER_BOOL_FALSE) {
        rcb = MARPAWRAPPER_BOOL_FALSE;
        break;
      }
    } else if (sizel == 1) {
      if (xb == MARPAWRAPPER_BOOL_TRUE) {
        if (_xml_1_0__Lex023b(xml_1_0p, currenti, streamInp, &dummySizel) == MARPAWRAPPER_BOOL_TRUE ||
            _xml_1_0__Lex024b(xml_1_0p, currenti, streamInp, &dummySizel) == MARPAWRAPPER_BOOL_TRUE) {
          /* Per def Lex021b or Lex022b also matched NameStartCharb */
          mb = MARPAWRAPPER_BOOL_TRUE;
          sizel++;
        } else if (_xml_1_0_NameStartCharb(xml_1_0p, currenti, streamInp, &sizel) == MARPAWRAPPER_BOOL_TRUE ||
                   _xml_1_0__Lex004b(xml_1_0p, currenti, streamInp, &sizel) == MARPAWRAPPER_BOOL_TRUE) {
          sizel++;
        }
      } else if (_xml_1_0_NameStartCharb(xml_1_0p, currenti, streamInp, &sizel) == MARPAWRAPPER_BOOL_TRUE ||
                 _xml_1_0__Lex004b(xml_1_0p, currenti, streamInp, &sizel) == MARPAWRAPPER_BOOL_TRUE) {
        sizel++;
      }
    } else if (sizel == 2) {
      if (mb == MARPAWRAPPER_BOOL_TRUE) {
        if (_xml_1_0__Lex025b(xml_1_0p, currenti, streamInp, &dummySizel) == MARPAWRAPPER_BOOL_TRUE ||
            _xml_1_0__Lex026b(xml_1_0p, currenti, streamInp, &dummySizel) == MARPAWRAPPER_BOOL_TRUE) {
          /* Per def Lex021b or Lex022b also matched NameStartCharb */
          rcb = MARPAWRAPPER_BOOL_FALSE;
          break;
        } else if (_xml_1_0_NameStartCharb(xml_1_0p, currenti, streamInp, &sizel) == MARPAWRAPPER_BOOL_TRUE ||
                   _xml_1_0__Lex004b(xml_1_0p, currenti, streamInp, &sizel) == MARPAWRAPPER_BOOL_TRUE) {
          sizel++;
        }
      } else if (_xml_1_0_NameStartCharb(xml_1_0p, currenti, streamInp, &sizel) == MARPAWRAPPER_BOOL_TRUE ||
                 _xml_1_0__Lex004b(xml_1_0p, currenti, streamInp, &sizel) == MARPAWRAPPER_BOOL_TRUE) {
        sizel++;
      }
    } else if (_xml_1_0_NameStartCharb(xml_1_0p, currenti, streamInp, &sizel) == MARPAWRAPPER_BOOL_TRUE ||
               _xml_1_0__Lex004b(xml_1_0p, currenti, streamInp, &sizel) == MARPAWRAPPER_BOOL_TRUE) {
      sizel++;
    }
    currenti = streamInUtf8_nexti(streamInp);
  } while (currenti >= 0);

  if (streamInUtf8_currentFromMarkedb(streamInp) == STREAMIN_BOOL_FALSE) {
    rcb = MARPAWRAPPER_BOOL_FALSE;
  }

  if (rcb == MARPAWRAPPER_BOOL_TRUE) {
    *sizelp = sizel;
  }

  return rcb;
}
