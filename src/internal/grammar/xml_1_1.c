#include <stdlib.h>
#include <errno.h>
#include "internal/grammar/xml_1_1.h"

static marpaWrapperBool_t _xml_1_1_buildGrammarb(xml_1_1_t *xml_1_1p, marpaWrapperOption_t *marpaWrapperOptionp);
static marpaWrapperBool_t _xml_1_1_buildSymbolsb(xml_1_1_t *xml_1_1p);
static marpaWrapperBool_t _xml_1_1_buildRulesb(xml_1_1_t *xml_1_1p);

/* Symbols */
typedef enum xml_1_1_symbol {
  /* Terminals */
  _Exclusion001 = 0   , /* _Exclusion001 ~ '_Gen002 - _Gen004' */
  _Exclusion002       , /* _Exclusion002 ~ 'PubidChar - _Lex037' */
  _Exclusion003       , /* _Exclusion003 ~ '_Lex045_any - _Gen092' */
  _Exclusion004       , /* _Exclusion004 ~ 'Char - _Lex029' */
  _Exclusion005       , /* _Exclusion005 ~ 'Char_any - _Gen104' */
  _Exclusion006       , /* _Exclusion006 ~ 'Name - _Gen117' */
  _Exclusion007       , /* _Exclusion007 ~ 'Char_any - _Gen122' */
  _Exclusion008       , /* _Exclusion008 ~ 'Char_any - _Gen273' */
  _Exclusion009       , /* _Exclusion009 ~ '_Gen301 - _Gen302' */
  _Lex001             , /* _Lex001 ~ [\x{1}-\x{d7ff}] */
  _Lex002             , /* _Lex002 ~ [\x{e000}-\x{fffd}] */
  _Lex003             , /* _Lex003 ~ [\x{10000}-\x{10ffff}] */
  _Lex004             , /* _Lex004 ~ [\x{1}-\x{8}] */
  _Lex005             , /* _Lex005 ~ [\x{b}-\x{c}] */
  _Lex006             , /* _Lex006 ~ [\x{e}-\x{1f}] */
  _Lex007             , /* _Lex007 ~ [\x{7f}-\x{84}] */
  _Lex008             , /* _Lex008 ~ [\x{86}-\x{9f}] */
  _Lex009             , /* _Lex009 ~ [\x{20}] */
  _Lex010             , /* _Lex010 ~ [\x{9}] */
  _Lex011             , /* _Lex011 ~ [\x{d}] */
  _Lex012             , /* _Lex012 ~ [\x{a}] */
  _Lex013             , /* _Lex013 ~ ':' */
  _Lex014             , /* _Lex014 ~ [A-Z] */
  _Lex015             , /* _Lex015 ~ '_' */
  _Lex016             , /* _Lex016 ~ [a-z] */
  _Lex017             , /* _Lex017 ~ [\x{c0}-\x{d6}] */
  _Lex018             , /* _Lex018 ~ [\x{d8}-\x{f6}] */
  _Lex019             , /* _Lex019 ~ [\x{f8}-\x{2ff}] */
  _Lex020             , /* _Lex020 ~ [\x{370}-\x{37d}] */
  _Lex021             , /* _Lex021 ~ [\x{37f}-\x{1fff}] */
  _Lex022             , /* _Lex022 ~ [\x{200c}-\x{200d}] */
  _Lex023             , /* _Lex023 ~ [\x{2070}-\x{218f}] */
  _Lex024             , /* _Lex024 ~ [\x{2c00}-\x{2fef}] */
  _Lex025             , /* _Lex025 ~ [\x{3001}-\x{d7ff}] */
  _Lex026             , /* _Lex026 ~ [\x{f900}-\x{fdcf}] */
  _Lex027             , /* _Lex027 ~ [\x{fdf0}-\x{fffd}] */
  _Lex028             , /* _Lex028 ~ [\x{10000}-\x{effff}] */
  _Lex029             , /* _Lex029 ~ '-' */
  _Lex030             , /* _Lex030 ~ '.' */
  _Lex031             , /* _Lex031 ~ [0-9] */
  _Lex032             , /* _Lex032 ~ [\x{b7}] */
  _Lex033             , /* _Lex033 ~ [\x{300}-\x{36f}] */
  _Lex034             , /* _Lex034 ~ [\x{203f}-\x{2040}] */
  _Lex035             , /* _Lex035 ~ '"' */
  _Lex036             , /* _Lex036 ~ [^%&"] */
  _Lex037             , /* _Lex037 ~ ['] */
  _Lex038             , /* _Lex038 ~ [^%&'] */
  _Lex039             , /* _Lex039 ~ [^<&"] */
  _Lex040             , /* _Lex040 ~ [^<&'] */
  _Lex041             , /* _Lex041 ~ [^"] */
  _Lex042             , /* _Lex042 ~ [^'] */
  _Lex043             , /* _Lex043 ~ [a-zA-Z0-9] */
  _Lex044             , /* _Lex044 ~ [\-'()+,./:=?;!*#@$_%] */
  _Lex045             , /* _Lex045 ~ [^<&] */
  _Lex046             , /* _Lex046 ~ ']]>' */
  _Lex047             , /* _Lex047 ~ '<!--' */
  _Lex048             , /* _Lex048 ~ '-->' */
  _Lex049             , /* _Lex049 ~ '<?' */
  _Lex050             , /* _Lex050 ~ '?>' */
  _Lex051             , /* _Lex051 ~ 'X' */
  _Lex052             , /* _Lex052 ~ 'x' */
  _Lex053             , /* _Lex053 ~ 'M' */
  _Lex054             , /* _Lex054 ~ 'm' */
  _Lex055             , /* _Lex055 ~ 'L' */
  _Lex056             , /* _Lex056 ~ 'l' */
  _Lex057             , /* _Lex057 ~ '<![CDATA[' */
  _Lex058             , /* _Lex058 ~ '<?xml' */
  _Lex059             , /* _Lex059 ~ 'version' */
  _Lex060             , /* _Lex060 ~ '=' */
  _Lex061             , /* _Lex061 ~ '1.1' */
  _Lex062             , /* _Lex062 ~ '<!DOCTYPE' */
  _Lex063             , /* _Lex063 ~ '[' */
  _Lex064             , /* _Lex064 ~ ']' */
  _Lex065             , /* _Lex065 ~ '>' */
  _Lex066             , /* _Lex066 ~ 'standalone' */
  _Lex067             , /* _Lex067 ~ 'yes' */
  _Lex068             , /* _Lex068 ~ 'no' */
  _Lex069             , /* _Lex069 ~ '<' */
  _Lex070             , /* _Lex070 ~ '</' */
  _Lex071             , /* _Lex071 ~ '/>' */
  _Lex072             , /* _Lex072 ~ '<!ELEMENT' */
  _Lex073             , /* _Lex073 ~ 'EMPTY' */
  _Lex074             , /* _Lex074 ~ 'ANY' */
  _Lex075             , /* _Lex075 ~ '?' */
  _Lex076             , /* _Lex076 ~ '*' */
  _Lex077             , /* _Lex077 ~ '+' */
  _Lex078             , /* _Lex078 ~ '(' */
  _Lex079             , /* _Lex079 ~ '|' */
  _Lex080             , /* _Lex080 ~ ')' */
  _Lex081             , /* _Lex081 ~ ',' */
  _Lex082             , /* _Lex082 ~ '#PCDATA' */
  _Lex083             , /* _Lex083 ~ ')*' */
  _Lex084             , /* _Lex084 ~ '<!ATTLIST' */
  _Lex085             , /* _Lex085 ~ 'CDATA' */
  _Lex086             , /* _Lex086 ~ 'ID' */
  _Lex087             , /* _Lex087 ~ 'IDREF' */
  _Lex088             , /* _Lex088 ~ 'IDREFS' */
  _Lex089             , /* _Lex089 ~ 'ENTITY' */
  _Lex090             , /* _Lex090 ~ 'ENTITIES' */
  _Lex091             , /* _Lex091 ~ 'NMTOKEN' */
  _Lex092             , /* _Lex092 ~ 'NMTOKENS' */
  _Lex093             , /* _Lex093 ~ 'NOTATION' */
  _Lex094             , /* _Lex094 ~ '#REQUIRED' */
  _Lex095             , /* _Lex095 ~ '#IMPLIED' */
  _Lex096             , /* _Lex096 ~ '#FIXED' */
  _Lex097             , /* _Lex097 ~ '<![' */
  _Lex098             , /* _Lex098 ~ 'INCLUDE' */
  _Lex099             , /* _Lex099 ~ 'IGNORE' */
  _Lex100             , /* _Lex100 ~ '&#' */
  _Lex101             , /* _Lex101 ~ ';' */
  _Lex102             , /* _Lex102 ~ '&#x' */
  _Lex103             , /* _Lex103 ~ [0-9a-fA-F] */
  _Lex104             , /* _Lex104 ~ '&' */
  _Lex105             , /* _Lex105 ~ '%' */
  _Lex106             , /* _Lex106 ~ '<!ENTITY' */
  _Lex107             , /* _Lex107 ~ 'SYSTEM' */
  _Lex108             , /* _Lex108 ~ 'PUBLIC' */
  _Lex109             , /* _Lex109 ~ 'NDATA' */
  _Lex110             , /* _Lex110 ~ 'encoding' */
  _Lex111             , /* _Lex111 ~ [A-Za-z] */
  _Lex112             , /* _Lex112 ~ [A-Za-z0-9._] */
  _Lex113             , /* _Lex113 ~ '<!NOTATION' */
  /* Non-terminals */
  AttDef              ,
  AttDef_any          ,
  AttType             ,
  AttValue            ,
  AttlistDecl         ,
  Attribute           ,
  CDEnd               ,
  CDSect              ,
  CDStart             ,
  CData               ,
  Char                ,
  CharData            ,
  CharData_maybe      ,
  CharRef             ,
  Char_any            ,
  Comment             ,
  DeclSep             ,
  DefaultDecl         ,
  ETag                ,
  EmptyElemTag        ,
  EncName             ,
  EncodingDecl        ,
  EncodingDecl_maybe  ,
  EntityDecl          ,
  EntityDef           ,
  EntityRef           ,
  EntityValue         ,
  EnumeratedType      ,
  Enumeration         ,
  Eq                  ,
  ExternalID          ,
  GEDecl              ,
  Ignore              ,
  Misc                ,
  Misc_any            ,
  Mixed               ,
  NDataDecl           ,
  NDataDecl_maybe     ,
  Name                ,
  NameChar            ,
  NameStartChar       ,
  Names               ,
  Nmtoken             ,
  Nmtokens            ,
  NotationDecl        ,
  NotationType        ,
  PEDecl              ,
  PEDef               ,
  PEReference         ,
  PI                  ,
  PITarget            ,
  PubidChar           ,
  PubidChar_any       ,
  PubidLiteral        ,
  PublicID            ,
  Reference           ,
  RestrictedChar      ,
  S                   ,
  SDDecl              ,
  SDDecl_maybe        ,
  STag                ,
  S_maybe             ,
  StringType          ,
  SystemLiteral       ,
  TextDecl            ,
  TextDecl_maybe      ,
  TokenizedType       ,
  VersionInfo         ,
  VersionInfo_maybe   ,
  VersionNum          ,
  XMLDecl             ,
  _Gen002             ,
  _Gen004             ,
  _Gen005             ,
  _Gen015             ,
  _Gen015_many        ,
  _Gen044             ,
  _Gen044_any         ,
  _Gen047             ,
  _Gen047_any         ,
  _Gen050             ,
  _Gen050_many        ,
  _Gen053             ,
  _Gen053_any         ,
  _Gen056             ,
  _Gen056_any         ,
  _Gen060             ,
  _Gen060_any         ,
  _Gen066             ,
  _Gen066_any         ,
  _Gen069             ,
  _Gen069_any         ,
  _Gen075             ,
  _Gen077             ,
  _Gen081             ,
  _Gen082             ,
  _Gen082_any         ,
  _Gen092             ,
  _Gen093             ,
  _Gen095             ,
  _Gen096             ,
  _Gen097             ,
  _Gen098             ,
  _Gen099             ,
  _Gen100             ,
  _Gen100_any         ,
  _Gen104             ,
  _Gen105             ,
  _Gen106             ,
  _Gen107             ,
  _Gen107_maybe       ,
  _Gen111             ,
  _Gen113             ,
  _Gen115             ,
  _Gen117             ,
  _Gen118             ,
  _Gen122             ,
  _Gen123             ,
  _Gen124             ,
  _Gen127             ,
  _Gen127_maybe       ,
  _Gen138             ,
  _Gen146             ,
  _Gen146_maybe       ,
  _Gen149             ,
  _Gen149_maybe       ,
  _Gen155             ,
  _Gen155_any         ,
  _Gen168             ,
  _Gen168_any         ,
  _Gen173             ,
  _Gen175             ,
  _Gen176             ,
  _Gen178             ,
  _Gen179             ,
  _Gen184             ,
  _Gen184_any         ,
  _Gen191             ,
  _Gen196             ,
  _Gen196_any         ,
  _Gen199             ,
  _Gen199_any         ,
  _Gen207             ,
  _Gen209             ,
  _Gen209_maybe       ,
  _Gen215             ,
  _Gen218             ,
  _Gen218_maybe       ,
  _Gen224             ,
  _Gen224_many        ,
  _Gen227             ,
  _Gen227_any         ,
  _Gen230             ,
  _Gen230_any         ,
  _Gen250             ,
  _Gen250_any         ,
  _Gen253             ,
  _Gen253_any         ,
  _Gen256             ,
  _Gen256_maybe       ,
  _Gen259             ,
  _Gen268             ,
  _Gen268_any         ,
  _Gen271             ,
  _Gen273             ,
  _Gen274             ,
  _Gen290             ,
  _Gen301             ,
  _Gen302             ,
  _Gen303             ,
  _Gen305             ,
  _Gen308             ,
  _Gen308_any         ,
  _Gen312             ,
  _Lex031_many        ,
  _Lex041_any         ,
  _Lex042_any         ,
  _Lex045_any         ,
  _Lex103_many        ,
  children            ,
  choice              ,
  conditionalSect     ,
  content             ,
  contentspec         ,
  cp                  ,
  doctypedecl         ,
  document            ,
  element             ,
  elementdecl         ,
  extParsedEnt        ,
  extSubset           ,
  extSubsetDecl       ,
  ignoreSect          ,
  ignoreSectContents  ,
  ignoreSectContents_any,
  includeSect         ,
  intSubset           ,
  markupdecl          ,
  prolog              ,
  seq                 ,
  _SYMBOL_MAX
} xml_1_1_symbol_t;

#define XML_1_1_TERMINAL_MAX _Lex113

/*******************/
/* xml_1_1_newp  */
/*******************/
xml_1_1_t *xml_1_1_newp(marpaWrapperOption_t *marpaWrapperOptionp) {
  xml_1_1_t           *xml_1_1p;
  marpaWrapperOption_t marpaWrapperOption;

  /* Fill the defaults */
  if (marpaWrapperOptionp == NULL) {
    marpaWrapper_optionDefaultb(&marpaWrapperOption);
  } else {
    marpaWrapperOption = *marpaWrapperOptionp;
  }

  xml_1_1p = malloc(sizeof(xml_1_1_t));
  if (xml_1_1p == NULL) {
    marpaWrapper_log(marpaWrapperOption.logCallbackp,
		     marpaWrapperOption.logCallbackDatavp,
		     NULL,
		     marpaWrapperOption.logLevelWantedi,
		     MARPAWRAPPERERRORORIGIN_SYSTEM,
		     errno,
		     "malloc()",
		     MARPAWRAPPER_LOGLEVEL_ERROR);
    return NULL;
  }

  xml_1_1p->marpaWrapperp = NULL;
  xml_1_1p->marpaWrapperSymbolArrayp = NULL;

  if (_xml_1_1_buildGrammarb(xml_1_1p, &marpaWrapperOption) == MARPAWRAPPER_BOOL_FALSE) {
    xml_1_1_destroyv(&xml_1_1p);
  }

  return xml_1_1p;
}

/*********************/
/* xml_1_1_destroyv  */
/*********************/
void xml_1_1_destroyv(xml_1_1_t **xml_1_1pp) {
  xml_1_1_t *xml_1_1p;

  if (xml_1_1pp != NULL) {
    xml_1_1p = *xml_1_1pp;

    if (xml_1_1p != NULL) {
      if (xml_1_1p->marpaWrapperp != NULL) {
	marpaWrapper_destroyv(&(xml_1_1p->marpaWrapperp));
      }
      if (xml_1_1p->marpaWrapperSymbolArrayp != NULL) {
	free(xml_1_1p->marpaWrapperSymbolArrayp);
      }
      free(xml_1_1p);
    }

    *xml_1_1pp = NULL;
  }
}

/**************************/
/* _xml_1_1_buildGrammarb */
/**************************/
static marpaWrapperBool_t _xml_1_1_buildGrammarb(xml_1_1_t *xml_1_1p, marpaWrapperOption_t *marpaWrapperOptionp) {

  xml_1_1p->marpaWrapperp = marpaWrapper_newp(marpaWrapperOptionp);
  if (xml_1_1p->marpaWrapperp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  if (_xml_1_1_buildSymbolsb(xml_1_1p) == MARPAWRAPPER_BOOL_FALSE) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  if (_xml_1_1_buildRulesb(xml_1_1p) == MARPAWRAPPER_BOOL_FALSE) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  if (marpaWrapper_g_precomputeb(xml_1_1p->marpaWrapperp) == MARPAWRAPPER_BOOL_FALSE) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  return MARPAWRAPPER_BOOL_TRUE;
}

/**************************/
/* _xml_1_1_buildSymbolsb */
/**************************/
static marpaWrapperBool_t _xml_1_1_buildSymbolsb(xml_1_1_t *xml_1_1p) {
  int                        i;
  marpaWrapperSymbolOption_t marpaWrapperSymbolOption;

  xml_1_1p->marpaWrapperSymbolArrayp = malloc(_SYMBOL_MAX * sizeof(marpaWrapperSymbol_t *));
  if (xml_1_1p->marpaWrapperSymbolArrayp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  for (i = 0; i < _SYMBOL_MAX; i++) {

    /* Fill default options */
    if (marpaWrapper_symbolOptionDefaultb(&marpaWrapperSymbolOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }

    /* Opaque data will be our "this" */
    marpaWrapperSymbolOption.datavp = xml_1_1p;

    /* Optional, but we can make ourself the terminals */
    marpaWrapperSymbolOption.terminalb = (i <= XML_1_1_TERMINAL_MAX) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;

    /* Start rule ? */
    marpaWrapperSymbolOption.startb = (i == document) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;

    /* Create the symbol */
    xml_1_1p->marpaWrapperSymbolArrayp[i] = marpaWrapper_g_addSymbolp (xml_1_1p->marpaWrapperp, &marpaWrapperSymbolOption);
    if (xml_1_1p->marpaWrapperSymbolArrayp[i] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }

  }

  return MARPAWRAPPER_BOOL_TRUE;
}

/************************/
/* _xml_1_1_buildRulesb */
/************************/
static marpaWrapperBool_t _xml_1_1_buildRulesb(xml_1_1_t *xml_1_1p) {
  marpaWrapperRuleOption_t   marpaWrapperRuleOption;


  {
    /* AttDef ::= S Name S AttType S DefaultDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_1p->marpaWrapperSymbolArrayp[S],
      xml_1_1p->marpaWrapperSymbolArrayp[Name],
      xml_1_1p->marpaWrapperSymbolArrayp[S],
      xml_1_1p->marpaWrapperSymbolArrayp[AttType],
      xml_1_1p->marpaWrapperSymbolArrayp[S],
      xml_1_1p->marpaWrapperSymbolArrayp[DefaultDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[AttDef];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* AttDef_any ::= AttDef * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[AttDef]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[AttDef_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* AttType ::= StringType  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[StringType]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[AttType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* AttType ::= TokenizedType  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[TokenizedType]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[AttType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* AttType ::= EnumeratedType  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[EnumeratedType]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[AttType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* AttValue ::= _Lex035 _Gen066_any _Lex035  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex035],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen066_any],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex035]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[AttValue];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* AttValue ::= _Lex037 _Gen069_any _Lex037  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex037],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen069_any],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex037]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[AttValue];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* AttlistDecl ::= _Lex084 S Name AttDef_any S_maybe _Lex065  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex084],
      xml_1_1p->marpaWrapperSymbolArrayp[S],
      xml_1_1p->marpaWrapperSymbolArrayp[Name],
      xml_1_1p->marpaWrapperSymbolArrayp[AttDef_any],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex065]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[AttlistDecl];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Attribute ::= Name Eq AttValue  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Name],
      xml_1_1p->marpaWrapperSymbolArrayp[Eq],
      xml_1_1p->marpaWrapperSymbolArrayp[AttValue]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Attribute];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* CDEnd ::= _Lex046  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex046]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[CDEnd];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* CDSect ::= CDStart CData CDEnd  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[CDStart],
      xml_1_1p->marpaWrapperSymbolArrayp[CData],
      xml_1_1p->marpaWrapperSymbolArrayp[CDEnd]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[CDSect];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* CDStart ::= _Lex057  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex057]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[CDStart];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* CData ::= _Gen124  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen124]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[CData];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Char ::= _Lex001  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex001]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Char];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Char ::= _Lex002  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex002]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Char];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Char ::= _Lex003  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex003]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Char];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* CharData ::= _Gen093  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen093]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[CharData];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* CharData_maybe ::= CharData  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[CharData]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[CharData_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* CharData_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[CharData_maybe];
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* CharRef ::= _Lex100 _Lex031_many _Lex101  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex100],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex031_many],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex101]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[CharRef];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* CharRef ::= _Lex102 _Lex103_many _Lex101  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex102],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex103_many],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex101]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[CharRef];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Char_any ::= Char * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Char]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Char_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Comment ::= _Lex047 _Gen100_any _Lex048  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex047],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen100_any],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex048]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Comment];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* DeclSep ::= PEReference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[PEReference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[DeclSep];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* DeclSep ::= S  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[S]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[DeclSep];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* DefaultDecl ::= _Lex094  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex094]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[DefaultDecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* DefaultDecl ::= _Lex095  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex095]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[DefaultDecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* DefaultDecl ::= _Gen259  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen259]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[DefaultDecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* ETag ::= _Lex070 Name S_maybe _Lex065  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex070],
      xml_1_1p->marpaWrapperSymbolArrayp[Name],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex065]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[ETag];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* EmptyElemTag ::= _Lex069 Name _Gen199_any S_maybe _Lex071  */
    marpaWrapperSymbol_t *rhsSymbolpp[5] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex069],
      xml_1_1p->marpaWrapperSymbolArrayp[Name],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen199_any],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex071]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[EmptyElemTag];
    marpaWrapperRuleOption.nRhsSymboli = 5;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* EncName ::= _Lex111 _Gen308_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex111],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen308_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[EncName];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* EncodingDecl ::= S _Lex110 Eq _Gen305  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[S],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex110],
      xml_1_1p->marpaWrapperSymbolArrayp[Eq],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen305]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[EncodingDecl];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* EncodingDecl_maybe ::= EncodingDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[EncodingDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[EncodingDecl_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* EncodingDecl_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[EncodingDecl_maybe];
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* EntityDecl ::= GEDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[GEDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[EntityDecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* EntityDecl ::= PEDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[PEDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[EntityDecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* EntityDef ::= EntityValue  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[EntityValue]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[EntityDef];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* EntityDef ::= _Gen290  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen290]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[EntityDef];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* EntityRef ::= _Lex104 Name _Lex101  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex104],
      xml_1_1p->marpaWrapperSymbolArrayp[Name],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex101]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[EntityRef];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* EntityValue ::= _Lex035 _Gen056_any _Lex035  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex035],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen056_any],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex035]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[EntityValue];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* EntityValue ::= _Lex037 _Gen060_any _Lex037  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex037],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen060_any],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex037]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[EntityValue];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* EnumeratedType ::= NotationType  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[NotationType]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[EnumeratedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* EnumeratedType ::= Enumeration  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Enumeration]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[EnumeratedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Enumeration ::= _Lex078 S_maybe Nmtoken _Gen253_any S_maybe _Lex080  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex078],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[Nmtoken],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen253_any],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex080]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Enumeration];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Eq ::= S_maybe _Lex060 S_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex060],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Eq];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* ExternalID ::= _Lex107 S SystemLiteral  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex107],
      xml_1_1p->marpaWrapperSymbolArrayp[S],
      xml_1_1p->marpaWrapperSymbolArrayp[SystemLiteral]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[ExternalID];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* ExternalID ::= _Lex108 S PubidLiteral S SystemLiteral  */
    marpaWrapperSymbol_t *rhsSymbolpp[5] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex108],
      xml_1_1p->marpaWrapperSymbolArrayp[S],
      xml_1_1p->marpaWrapperSymbolArrayp[PubidLiteral],
      xml_1_1p->marpaWrapperSymbolArrayp[S],
      xml_1_1p->marpaWrapperSymbolArrayp[SystemLiteral]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[ExternalID];
    marpaWrapperRuleOption.nRhsSymboli = 5;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* GEDecl ::= _Lex106 S Name S EntityDef S_maybe _Lex065  */
    marpaWrapperSymbol_t *rhsSymbolpp[7] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex106],
      xml_1_1p->marpaWrapperSymbolArrayp[S],
      xml_1_1p->marpaWrapperSymbolArrayp[Name],
      xml_1_1p->marpaWrapperSymbolArrayp[S],
      xml_1_1p->marpaWrapperSymbolArrayp[EntityDef],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex065]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[GEDecl];
    marpaWrapperRuleOption.nRhsSymboli = 7;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Ignore ::= _Gen274  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen274]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Ignore];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Misc ::= Comment  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Comment]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Misc];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Misc ::= PI  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[PI]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Misc];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Misc ::= S  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[S]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Misc];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Misc_any ::= Misc * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Misc]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Misc_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Mixed ::= _Lex078 S_maybe _Lex082 _Gen230_any S_maybe _Lex083  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex078],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex082],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen230_any],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex083]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Mixed];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Mixed ::= _Lex078 S_maybe _Lex082 S_maybe _Lex080  */
    marpaWrapperSymbol_t *rhsSymbolpp[5] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex078],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex082],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex080]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Mixed];
    marpaWrapperRuleOption.nRhsSymboli = 5;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NDataDecl ::= S _Lex109 S Name  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[S],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex109],
      xml_1_1p->marpaWrapperSymbolArrayp[S],
      xml_1_1p->marpaWrapperSymbolArrayp[Name]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NDataDecl];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NDataDecl_maybe ::= NDataDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[NDataDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NDataDecl_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NDataDecl_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NDataDecl_maybe];
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Name ::= NameStartChar _Gen044_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[NameStartChar],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen044_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Name];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameChar ::= NameStartChar  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[NameStartChar]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameChar ::= _Lex029  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex029]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameChar ::= _Lex030  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex030]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameChar ::= _Lex031  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex031]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameChar ::= _Lex032  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex032]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameChar ::= _Lex033  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex033]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameChar ::= _Lex034  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex034]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameStartChar ::= _Lex013  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex013]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameStartChar ::= _Lex014  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex014]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameStartChar ::= _Lex015  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex015]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameStartChar ::= _Lex016  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex016]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameStartChar ::= _Lex017  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex017]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameStartChar ::= _Lex018  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex018]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameStartChar ::= _Lex019  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex019]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameStartChar ::= _Lex020  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex020]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameStartChar ::= _Lex021  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex021]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameStartChar ::= _Lex022  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex022]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameStartChar ::= _Lex023  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex023]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameStartChar ::= _Lex024  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex024]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameStartChar ::= _Lex025  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex025]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameStartChar ::= _Lex026  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex026]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameStartChar ::= _Lex027  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex027]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameStartChar ::= _Lex028  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex028]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Names ::= Name _Gen047_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Name],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen047_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Names];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Nmtoken ::= _Gen050_many  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen050_many]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Nmtoken];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Nmtokens ::= Nmtoken _Gen053_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Nmtoken],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen053_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Nmtokens];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NotationDecl ::= _Lex113 S Name S _Gen312 S_maybe _Lex065  */
    marpaWrapperSymbol_t *rhsSymbolpp[7] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex113],
      xml_1_1p->marpaWrapperSymbolArrayp[S],
      xml_1_1p->marpaWrapperSymbolArrayp[Name],
      xml_1_1p->marpaWrapperSymbolArrayp[S],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen312],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex065]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NotationDecl];
    marpaWrapperRuleOption.nRhsSymboli = 7;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NotationType ::= _Lex093 S _Lex078 S_maybe Name _Gen250_any S_maybe _Lex080  */
    marpaWrapperSymbol_t *rhsSymbolpp[8] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex093],
      xml_1_1p->marpaWrapperSymbolArrayp[S],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex078],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[Name],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen250_any],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex080]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NotationType];
    marpaWrapperRuleOption.nRhsSymboli = 8;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* PEDecl ::= _Lex106 S _Lex105 S Name S PEDef S_maybe _Lex065  */
    marpaWrapperSymbol_t *rhsSymbolpp[9] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex106],
      xml_1_1p->marpaWrapperSymbolArrayp[S],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex105],
      xml_1_1p->marpaWrapperSymbolArrayp[S],
      xml_1_1p->marpaWrapperSymbolArrayp[Name],
      xml_1_1p->marpaWrapperSymbolArrayp[S],
      xml_1_1p->marpaWrapperSymbolArrayp[PEDef],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex065]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[PEDecl];
    marpaWrapperRuleOption.nRhsSymboli = 9;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* PEDef ::= EntityValue  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[EntityValue]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[PEDef];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* PEDef ::= ExternalID  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[ExternalID]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[PEDef];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* PEReference ::= _Lex105 Name _Lex101  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex105],
      xml_1_1p->marpaWrapperSymbolArrayp[Name],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex101]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[PEReference];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* PI ::= _Lex049 PITarget _Gen107_maybe _Lex050  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex049],
      xml_1_1p->marpaWrapperSymbolArrayp[PITarget],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen107_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex050]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[PI];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* PITarget ::= _Gen118  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen118]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[PITarget];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* PubidChar ::= _Lex009  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex009]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[PubidChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* PubidChar ::= _Lex011  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex011]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[PubidChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* PubidChar ::= _Lex012  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex012]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[PubidChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* PubidChar ::= _Lex043  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex043]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[PubidChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* PubidChar ::= _Lex044  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex044]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[PubidChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* PubidChar_any ::= PubidChar * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[PubidChar]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[PubidChar_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* PubidLiteral ::= _Lex035 PubidChar_any _Lex035  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex035],
      xml_1_1p->marpaWrapperSymbolArrayp[PubidChar_any],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex035]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[PubidLiteral];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* PubidLiteral ::= _Lex037 _Gen082_any _Lex037  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex037],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen082_any],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex037]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[PubidLiteral];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* PublicID ::= _Lex108 S PubidLiteral  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex108],
      xml_1_1p->marpaWrapperSymbolArrayp[S],
      xml_1_1p->marpaWrapperSymbolArrayp[PubidLiteral]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[PublicID];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Reference ::= EntityRef  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[EntityRef]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Reference];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Reference ::= CharRef  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[CharRef]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Reference];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* RestrictedChar ::= _Lex004  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex004]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[RestrictedChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* RestrictedChar ::= _Lex005  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex005]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[RestrictedChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* RestrictedChar ::= _Lex006  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex006]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[RestrictedChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* RestrictedChar ::= _Lex007  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex007]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[RestrictedChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* RestrictedChar ::= _Lex008  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex008]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[RestrictedChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* S ::= _Gen015_many  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen015_many]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[S];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* SDDecl ::= S _Lex066 Eq _Gen179  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[S],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex066],
      xml_1_1p->marpaWrapperSymbolArrayp[Eq],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen179]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[SDDecl];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* SDDecl_maybe ::= SDDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[SDDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[SDDecl_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* SDDecl_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[SDDecl_maybe];
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* STag ::= _Lex069 Name _Gen184_any S_maybe _Lex065  */
    marpaWrapperSymbol_t *rhsSymbolpp[5] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex069],
      xml_1_1p->marpaWrapperSymbolArrayp[Name],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen184_any],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex065]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[STag];
    marpaWrapperRuleOption.nRhsSymboli = 5;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* S_maybe ::= S  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[S]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[S_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* S_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[S_maybe];
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* StringType ::= _Lex085  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex085]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[StringType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* SystemLiteral ::= _Gen075  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen075]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[SystemLiteral];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* SystemLiteral ::= _Gen077  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen077]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[SystemLiteral];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* TextDecl ::= _Lex058 VersionInfo_maybe EncodingDecl S_maybe _Lex050  */
    marpaWrapperSymbol_t *rhsSymbolpp[5] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex058],
      xml_1_1p->marpaWrapperSymbolArrayp[VersionInfo_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[EncodingDecl],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex050]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[TextDecl];
    marpaWrapperRuleOption.nRhsSymboli = 5;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* TextDecl_maybe ::= TextDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[TextDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[TextDecl_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* TextDecl_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[TextDecl_maybe];
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* TokenizedType ::= _Lex086  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex086]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* TokenizedType ::= _Lex087  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex087]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* TokenizedType ::= _Lex088  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex088]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* TokenizedType ::= _Lex089  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex089]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* TokenizedType ::= _Lex090  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex090]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* TokenizedType ::= _Lex091  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex091]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* TokenizedType ::= _Lex092  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex092]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* VersionInfo ::= S _Lex059 Eq _Gen138  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[S],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex059],
      xml_1_1p->marpaWrapperSymbolArrayp[Eq],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen138]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[VersionInfo];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* VersionInfo_maybe ::= VersionInfo  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[VersionInfo]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[VersionInfo_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* VersionInfo_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[VersionInfo_maybe];
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* VersionNum ::= _Lex061  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex061]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[VersionNum];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* XMLDecl ::= _Lex058 VersionInfo EncodingDecl_maybe SDDecl_maybe S_maybe _Lex050  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex058],
      xml_1_1p->marpaWrapperSymbolArrayp[VersionInfo],
      xml_1_1p->marpaWrapperSymbolArrayp[EncodingDecl_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[SDDecl_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex050]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[XMLDecl];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen002 ::= prolog element Misc_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[prolog],
      xml_1_1p->marpaWrapperSymbolArrayp[element],
      xml_1_1p->marpaWrapperSymbolArrayp[Misc_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen002];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen004 ::= Char_any RestrictedChar Char_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Char_any],
      xml_1_1p->marpaWrapperSymbolArrayp[RestrictedChar],
      xml_1_1p->marpaWrapperSymbolArrayp[Char_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen004];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen005 ::= _Exclusion001  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Exclusion001]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen005];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen015 ::= _Lex009  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex009]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen015];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen015 ::= _Lex010  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex010]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen015];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen015 ::= _Lex011  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex011]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen015];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen015 ::= _Lex012  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex012]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen015];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen015_many ::= _Gen015 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen015]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen015_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen044 ::= NameChar  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[NameChar]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen044];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen044_any ::= _Gen044 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen044]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen044_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen047 ::= _Lex009 Name  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex009],
      xml_1_1p->marpaWrapperSymbolArrayp[Name]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen047];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen047_any ::= _Gen047 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen047]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen047_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen050 ::= NameChar  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[NameChar]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen050];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen050_many ::= _Gen050 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen050]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen050_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen053 ::= _Lex009 Nmtoken  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex009],
      xml_1_1p->marpaWrapperSymbolArrayp[Nmtoken]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen053];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen053_any ::= _Gen053 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen053]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen053_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen056 ::= _Lex036  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex036]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen056];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen056 ::= PEReference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[PEReference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen056];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen056 ::= Reference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Reference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen056];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen056_any ::= _Gen056 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen056]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen056_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen060 ::= _Lex038  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex038]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen060];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen060 ::= PEReference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[PEReference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen060];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen060 ::= Reference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Reference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen060];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen060_any ::= _Gen060 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen060]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen060_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen066 ::= _Lex039  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex039]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen066];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen066 ::= Reference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Reference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen066];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen066_any ::= _Gen066 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen066]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen066_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen069 ::= _Lex040  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex040]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen069];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen069 ::= Reference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Reference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen069];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen069_any ::= _Gen069 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen069]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen069_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen075 ::= _Lex035 _Lex041_any _Lex035  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex035],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex041_any],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex035]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen075];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen077 ::= _Lex037 _Lex042_any _Lex037  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex037],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex042_any],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex037]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen077];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen081 ::= _Exclusion002  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Exclusion002]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen081];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen082 ::= _Gen081  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen081]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen082];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen082_any ::= _Gen082 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen082]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen082_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen092 ::= _Lex045_any _Lex046 _Lex045_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex045_any],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex046],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex045_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen092];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen093 ::= _Exclusion003  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Exclusion003]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen093];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen095 ::= _Exclusion004  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Exclusion004]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen095];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen096 ::= _Gen095  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen095]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen096];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen097 ::= _Exclusion004  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Exclusion004]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen097];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen098 ::= _Gen097  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen097]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen098];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen099 ::= _Lex029 _Gen098  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex029],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen098]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen099];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen100 ::= _Gen096  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen096]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen100];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen100 ::= _Gen099  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen099]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen100];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen100_any ::= _Gen100 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen100]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen100_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen104 ::= Char_any _Lex050 Char_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Char_any],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex050],
      xml_1_1p->marpaWrapperSymbolArrayp[Char_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen104];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen105 ::= _Exclusion005  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Exclusion005]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen105];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen106 ::= _Gen105  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen105]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen106];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen107 ::= S _Gen106  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[S],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen106]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen107];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen107_maybe ::= _Gen107  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen107]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen107_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen107_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen107_maybe];
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen111 ::= _Lex051  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex051]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen111];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen111 ::= _Lex052  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex052]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen111];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen113 ::= _Lex053  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex053]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen113];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen113 ::= _Lex054  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex054]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen113];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen115 ::= _Lex055  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex055]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen115];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen115 ::= _Lex056  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex056]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen115];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen117 ::= _Gen111 _Gen113 _Gen115  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen111],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen113],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen115]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen117];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen118 ::= _Exclusion006  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Exclusion006]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen118];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen122 ::= Char_any _Lex046 Char_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Char_any],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex046],
      xml_1_1p->marpaWrapperSymbolArrayp[Char_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen122];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen123 ::= _Exclusion007  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Exclusion007]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen123];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen124 ::= _Gen123  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen123]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen124];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen127 ::= doctypedecl Misc_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[doctypedecl],
      xml_1_1p->marpaWrapperSymbolArrayp[Misc_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen127];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen127_maybe ::= _Gen127  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen127]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen127_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen127_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen127_maybe];
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen138 ::= _Lex037 VersionNum _Lex037  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex037],
      xml_1_1p->marpaWrapperSymbolArrayp[VersionNum],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex037]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen138];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen138 ::= _Lex035 VersionNum _Lex035  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex035],
      xml_1_1p->marpaWrapperSymbolArrayp[VersionNum],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex035]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen138];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen146 ::= S ExternalID  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[S],
      xml_1_1p->marpaWrapperSymbolArrayp[ExternalID]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen146];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen146_maybe ::= _Gen146  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen146]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen146_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen146_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen146_maybe];
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen149 ::= _Lex063 intSubset _Lex064 S_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex063],
      xml_1_1p->marpaWrapperSymbolArrayp[intSubset],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex064],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen149];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen149_maybe ::= _Gen149  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen149]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen149_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen149_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen149_maybe];
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen155 ::= markupdecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[markupdecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen155];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen155 ::= DeclSep  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[DeclSep]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen155];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen155_any ::= _Gen155 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen155]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen155_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen168 ::= markupdecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[markupdecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen168];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen168 ::= conditionalSect  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[conditionalSect]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen168];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen168 ::= DeclSep  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[DeclSep]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen168];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen168_any ::= _Gen168 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen168]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen168_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen173 ::= _Lex067  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex067]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen173];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen173 ::= _Lex068  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex068]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen173];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen175 ::= _Lex037 _Gen173 _Lex037  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex037],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen173],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex037]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen175];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen176 ::= _Lex067  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex067]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen176];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen176 ::= _Lex068  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex068]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen176];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen178 ::= _Lex035 _Gen176 _Lex035  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex035],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen176],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex035]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen178];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen179 ::= _Gen175  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen175]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen179];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen179 ::= _Gen178  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen178]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen179];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen184 ::= S Attribute  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[S],
      xml_1_1p->marpaWrapperSymbolArrayp[Attribute]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen184];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen184_any ::= _Gen184 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen184]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen184_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen191 ::= element  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[element]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen191];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen191 ::= Reference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Reference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen191];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen191 ::= CDSect  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[CDSect]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen191];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen191 ::= PI  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[PI]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen191];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen191 ::= Comment  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Comment]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen191];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen196 ::= _Gen191 CharData_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen191],
      xml_1_1p->marpaWrapperSymbolArrayp[CharData_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen196];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen196_any ::= _Gen196 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen196]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen196_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen199 ::= S Attribute  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[S],
      xml_1_1p->marpaWrapperSymbolArrayp[Attribute]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen199];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen199_any ::= _Gen199 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen199]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen199_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen207 ::= choice  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[choice]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen207];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen207 ::= seq  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[seq]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen207];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen209 ::= _Lex075  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex075]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen209];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen209 ::= _Lex076  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex076]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen209];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen209 ::= _Lex077  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex077]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen209];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen209_maybe ::= _Gen209  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen209]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen209_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen209_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen209_maybe];
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen215 ::= Name  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Name]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen215];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen215 ::= choice  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[choice]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen215];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen215 ::= seq  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[seq]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen215];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen218 ::= _Lex075  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex075]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen218];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen218 ::= _Lex076  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex076]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen218];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen218 ::= _Lex077  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex077]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen218];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen218_maybe ::= _Gen218  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen218]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen218_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen218_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen218_maybe];
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen224 ::= S_maybe _Lex079 S_maybe cp  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex079],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[cp]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen224];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen224_many ::= _Gen224 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen224]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen224_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen227 ::= S_maybe _Lex081 S_maybe cp  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex081],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[cp]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen227];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen227_any ::= _Gen227 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen227]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen227_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen230 ::= S_maybe _Lex079 S_maybe Name  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex079],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[Name]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen230];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen230_any ::= _Gen230 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen230]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen230_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen250 ::= S_maybe _Lex079 S_maybe Name  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex079],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[Name]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen250];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen250_any ::= _Gen250 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen250]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen250_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen253 ::= S_maybe _Lex079 S_maybe Nmtoken  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex079],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[Nmtoken]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen253];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen253_any ::= _Gen253 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen253]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen253_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen256 ::= _Lex096 S  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex096],
      xml_1_1p->marpaWrapperSymbolArrayp[S]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen256];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen256_maybe ::= _Gen256  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen256]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen256_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen256_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen256_maybe];
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen259 ::= _Gen256_maybe AttValue  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen256_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[AttValue]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen259];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen268 ::= _Lex097 ignoreSectContents _Lex046 Ignore  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex097],
      xml_1_1p->marpaWrapperSymbolArrayp[ignoreSectContents],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex046],
      xml_1_1p->marpaWrapperSymbolArrayp[Ignore]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen268];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen268_any ::= _Gen268 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen268]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen268_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen271 ::= _Lex097  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex097]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen271];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen271 ::= _Lex046  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex046]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen271];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen273 ::= Char_any _Gen271 Char_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Char_any],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen271],
      xml_1_1p->marpaWrapperSymbolArrayp[Char_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen273];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen274 ::= _Exclusion008  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Exclusion008]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen274];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen290 ::= ExternalID NDataDecl_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[ExternalID],
      xml_1_1p->marpaWrapperSymbolArrayp[NDataDecl_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen290];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen301 ::= TextDecl_maybe content  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[TextDecl_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[content]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen301];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen302 ::= Char_any RestrictedChar Char_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Char_any],
      xml_1_1p->marpaWrapperSymbolArrayp[RestrictedChar],
      xml_1_1p->marpaWrapperSymbolArrayp[Char_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen302];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen303 ::= _Exclusion009  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Exclusion009]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen303];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen305 ::= _Lex035 EncName _Lex035  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex035],
      xml_1_1p->marpaWrapperSymbolArrayp[EncName],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex035]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen305];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen305 ::= _Lex037 EncName _Lex037  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex037],
      xml_1_1p->marpaWrapperSymbolArrayp[EncName],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex037]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen305];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen308 ::= _Lex112  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex112]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen308];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen308 ::= _Lex029  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex029]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen308];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen308_any ::= _Gen308 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen308]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen308_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen312 ::= ExternalID  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[ExternalID]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen312];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen312 ::= PublicID  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[PublicID]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen312];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Lex031_many ::= _Lex031 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex031]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Lex031_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Lex041_any ::= _Lex041 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex041]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Lex041_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Lex042_any ::= _Lex042 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex042]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Lex042_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Lex045_any ::= _Lex045 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex045]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Lex045_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Lex103_many ::= _Lex103 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex103]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Lex103_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* children ::= _Gen207 _Gen209_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen207],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen209_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[children];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* choice ::= _Lex078 S_maybe cp _Gen224_many S_maybe _Lex080  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex078],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[cp],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen224_many],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex080]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[choice];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* conditionalSect ::= includeSect  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[includeSect]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[conditionalSect];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* conditionalSect ::= ignoreSect  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[ignoreSect]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[conditionalSect];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* content ::= CharData_maybe _Gen196_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[CharData_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen196_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[content];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* contentspec ::= _Lex073  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex073]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[contentspec];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* contentspec ::= _Lex074  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex074]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[contentspec];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* contentspec ::= Mixed  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Mixed]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[contentspec];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* contentspec ::= children  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[children]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[contentspec];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* cp ::= _Gen215 _Gen218_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen215],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen218_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[cp];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* doctypedecl ::= _Lex062 S Name _Gen146_maybe S_maybe _Gen149_maybe _Lex065  */
    marpaWrapperSymbol_t *rhsSymbolpp[7] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex062],
      xml_1_1p->marpaWrapperSymbolArrayp[S],
      xml_1_1p->marpaWrapperSymbolArrayp[Name],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen146_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen149_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex065]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[doctypedecl];
    marpaWrapperRuleOption.nRhsSymboli = 7;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* document ::= _Gen005  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen005]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[document];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* element ::= EmptyElemTag  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[EmptyElemTag]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[element];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* element ::= STag content ETag  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[STag],
      xml_1_1p->marpaWrapperSymbolArrayp[content],
      xml_1_1p->marpaWrapperSymbolArrayp[ETag]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[element];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* elementdecl ::= _Lex072 S Name S contentspec S_maybe _Lex065  */
    marpaWrapperSymbol_t *rhsSymbolpp[7] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex072],
      xml_1_1p->marpaWrapperSymbolArrayp[S],
      xml_1_1p->marpaWrapperSymbolArrayp[Name],
      xml_1_1p->marpaWrapperSymbolArrayp[S],
      xml_1_1p->marpaWrapperSymbolArrayp[contentspec],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex065]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[elementdecl];
    marpaWrapperRuleOption.nRhsSymboli = 7;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* extParsedEnt ::= _Gen303  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen303]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[extParsedEnt];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* extSubset ::= TextDecl_maybe extSubsetDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[TextDecl_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[extSubsetDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[extSubset];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* extSubsetDecl ::= _Gen168_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen168_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[extSubsetDecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* ignoreSect ::= _Lex097 S_maybe _Lex099 S_maybe _Lex063 ignoreSectContents_any _Lex046  */
    marpaWrapperSymbol_t *rhsSymbolpp[7] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex097],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex099],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex063],
      xml_1_1p->marpaWrapperSymbolArrayp[ignoreSectContents_any],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex046]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[ignoreSect];
    marpaWrapperRuleOption.nRhsSymboli = 7;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* ignoreSectContents ::= Ignore _Gen268_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Ignore],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen268_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[ignoreSectContents];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* ignoreSectContents_any ::= ignoreSectContents * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[ignoreSectContents]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[ignoreSectContents_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* includeSect ::= _Lex097 S_maybe _Lex098 S_maybe _Lex063 extSubsetDecl _Lex046  */
    marpaWrapperSymbol_t *rhsSymbolpp[7] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex097],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex098],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex063],
      xml_1_1p->marpaWrapperSymbolArrayp[extSubsetDecl],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex046]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[includeSect];
    marpaWrapperRuleOption.nRhsSymboli = 7;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* intSubset ::= _Gen155_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen155_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[intSubset];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* markupdecl ::= elementdecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[elementdecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[markupdecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* markupdecl ::= AttlistDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[AttlistDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[markupdecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* markupdecl ::= EntityDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[EntityDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[markupdecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* markupdecl ::= NotationDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[NotationDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[markupdecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* markupdecl ::= PI  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[PI]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[markupdecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* markupdecl ::= Comment  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Comment]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[markupdecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* prolog ::= XMLDecl Misc_any _Gen127_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[XMLDecl],
      xml_1_1p->marpaWrapperSymbolArrayp[Misc_any],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen127_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[prolog];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* seq ::= _Lex078 S_maybe cp _Gen227_any S_maybe _Lex080  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex078],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[cp],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen227_any],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex080]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_1p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[seq];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
    return MARPAWRAPPER_BOOL_TRUE;
}
