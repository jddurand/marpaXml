#include <stdlib.h>
#include <errno.h>
#include "internal/grammar/xml_1_0.h"

static marpaWrapperBool_t _xml_1_0_buildGrammarb(xml_1_0_t *xml_1_0p, marpaWrapperOption_t *marpaWrapperOptionp);
static marpaWrapperBool_t _xml_1_0_buildSymbolsb(xml_1_0_t *xml_1_0p);
static marpaWrapperBool_t _xml_1_0_buildRulesb(xml_1_0_t *xml_1_0p);

/* Symbols */
typedef enum xml_1_0_symbol {
  /* Terminals */
  _Exclusion001 = 0   , /* _Exclusion001 ~ 'PubidChar - _Lex032' */
  _Exclusion002       , /* _Exclusion002 ~ '_Lex040_any - _Gen086' */
  _Exclusion003       , /* _Exclusion003 ~ 'Char - _Lex024' */
  _Exclusion004       , /* _Exclusion004 ~ 'Char_any - _Gen099' */
  _Exclusion005       , /* _Exclusion005 ~ 'Name - _Gen112' */
  _Exclusion006       , /* _Exclusion006 ~ 'Char_any - _Gen117' */
  _Exclusion007       , /* _Exclusion007 ~ 'Char_any - _Gen271' */
  _Lex001             , /* _Lex001 ~ [\x{9}] */
  _Lex002             , /* _Lex002 ~ [\x{a}] */
  _Lex003             , /* _Lex003 ~ [\x{d}] */
  _Lex004             , /* _Lex004 ~ [\x{20}-\x{d7ff}] */
  _Lex005             , /* _Lex005 ~ [\x{e000}-\x{fffd}] */
  _Lex006             , /* _Lex006 ~ [\x{10000}-\x{10ffff}] */
  _Lex007             , /* _Lex007 ~ [\x{20}] */
  _Lex008             , /* _Lex008 ~ ':' */
  _Lex009             , /* _Lex009 ~ [A-Z] */
  _Lex010             , /* _Lex010 ~ '_' */
  _Lex011             , /* _Lex011 ~ [a-z] */
  _Lex012             , /* _Lex012 ~ [\x{c0}-\x{d6}] */
  _Lex013             , /* _Lex013 ~ [\x{d8}-\x{f6}] */
  _Lex014             , /* _Lex014 ~ [\x{f8}-\x{2ff}] */
  _Lex015             , /* _Lex015 ~ [\x{370}-\x{37d}] */
  _Lex016             , /* _Lex016 ~ [\x{37f}-\x{1fff}] */
  _Lex017             , /* _Lex017 ~ [\x{200c}-\x{200d}] */
  _Lex018             , /* _Lex018 ~ [\x{2070}-\x{218f}] */
  _Lex019             , /* _Lex019 ~ [\x{2c00}-\x{2fef}] */
  _Lex020             , /* _Lex020 ~ [\x{3001}-\x{d7ff}] */
  _Lex021             , /* _Lex021 ~ [\x{f900}-\x{fdcf}] */
  _Lex022             , /* _Lex022 ~ [\x{fdf0}-\x{fffd}] */
  _Lex023             , /* _Lex023 ~ [\x{10000}-\x{effff}] */
  _Lex024             , /* _Lex024 ~ '-' */
  _Lex025             , /* _Lex025 ~ '.' */
  _Lex026             , /* _Lex026 ~ [0-9] */
  _Lex027             , /* _Lex027 ~ [\x{b7}] */
  _Lex028             , /* _Lex028 ~ [\x{300}-\x{36f}] */
  _Lex029             , /* _Lex029 ~ [\x{203f}-\x{2040}] */
  _Lex030             , /* _Lex030 ~ '"' */
  _Lex031             , /* _Lex031 ~ [^%&"] */
  _Lex032             , /* _Lex032 ~ ['] */
  _Lex033             , /* _Lex033 ~ [^%&'] */
  _Lex034             , /* _Lex034 ~ [^<&"] */
  _Lex035             , /* _Lex035 ~ [^<&'] */
  _Lex036             , /* _Lex036 ~ [^"] */
  _Lex037             , /* _Lex037 ~ [^'] */
  _Lex038             , /* _Lex038 ~ [a-zA-Z0-9] */
  _Lex039             , /* _Lex039 ~ [\-'()+,./:=?;!*#@$_%] */
  _Lex040             , /* _Lex040 ~ [^<&] */
  _Lex041             , /* _Lex041 ~ ']]>' */
  _Lex042             , /* _Lex042 ~ '<!--' */
  _Lex043             , /* _Lex043 ~ '-->' */
  _Lex044             , /* _Lex044 ~ '<?' */
  _Lex045             , /* _Lex045 ~ '?>' */
  _Lex046             , /* _Lex046 ~ 'X' */
  _Lex047             , /* _Lex047 ~ 'x' */
  _Lex048             , /* _Lex048 ~ 'M' */
  _Lex049             , /* _Lex049 ~ 'm' */
  _Lex050             , /* _Lex050 ~ 'L' */
  _Lex051             , /* _Lex051 ~ 'l' */
  _Lex052             , /* _Lex052 ~ '<![CDATA[' */
  _Lex053             , /* _Lex053 ~ '<?xml' */
  _Lex054             , /* _Lex054 ~ 'version' */
  _Lex055             , /* _Lex055 ~ '=' */
  _Lex056             , /* _Lex056 ~ '1.' */
  _Lex057             , /* _Lex057 ~ '<!DOCTYPE' */
  _Lex058             , /* _Lex058 ~ '[' */
  _Lex059             , /* _Lex059 ~ ']' */
  _Lex060             , /* _Lex060 ~ '>' */
  _Lex061             , /* _Lex061 ~ 'standalone' */
  _Lex062             , /* _Lex062 ~ 'yes' */
  _Lex063             , /* _Lex063 ~ 'no' */
  _Lex064             , /* _Lex064 ~ '<' */
  _Lex065             , /* _Lex065 ~ '</' */
  _Lex066             , /* _Lex066 ~ '/>' */
  _Lex067             , /* _Lex067 ~ '<!ELEMENT' */
  _Lex068             , /* _Lex068 ~ 'EMPTY' */
  _Lex069             , /* _Lex069 ~ 'ANY' */
  _Lex070             , /* _Lex070 ~ '?' */
  _Lex071             , /* _Lex071 ~ '*' */
  _Lex072             , /* _Lex072 ~ '+' */
  _Lex073             , /* _Lex073 ~ '(' */
  _Lex074             , /* _Lex074 ~ '|' */
  _Lex075             , /* _Lex075 ~ ')' */
  _Lex076             , /* _Lex076 ~ ',' */
  _Lex077             , /* _Lex077 ~ '#PCDATA' */
  _Lex078             , /* _Lex078 ~ ')*' */
  _Lex079             , /* _Lex079 ~ '<!ATTLIST' */
  _Lex080             , /* _Lex080 ~ 'CDATA' */
  _Lex081             , /* _Lex081 ~ 'ID' */
  _Lex082             , /* _Lex082 ~ 'IDREF' */
  _Lex083             , /* _Lex083 ~ 'IDREFS' */
  _Lex084             , /* _Lex084 ~ 'ENTITY' */
  _Lex085             , /* _Lex085 ~ 'ENTITIES' */
  _Lex086             , /* _Lex086 ~ 'NMTOKEN' */
  _Lex087             , /* _Lex087 ~ 'NMTOKENS' */
  _Lex088             , /* _Lex088 ~ 'NOTATION' */
  _Lex089             , /* _Lex089 ~ '#REQUIRED' */
  _Lex090             , /* _Lex090 ~ '#IMPLIED' */
  _Lex091             , /* _Lex091 ~ '#FIXED' */
  _Lex092             , /* _Lex092 ~ '<![' */
  _Lex093             , /* _Lex093 ~ 'INCLUDE' */
  _Lex094             , /* _Lex094 ~ 'IGNORE' */
  _Lex095             , /* _Lex095 ~ '&#' */
  _Lex096             , /* _Lex096 ~ ';' */
  _Lex097             , /* _Lex097 ~ '&#x' */
  _Lex098             , /* _Lex098 ~ [0-9a-fA-F] */
  _Lex099             , /* _Lex099 ~ '&' */
  _Lex100             , /* _Lex100 ~ '%' */
  _Lex101             , /* _Lex101 ~ '<!ENTITY' */
  _Lex102             , /* _Lex102 ~ 'SYSTEM' */
  _Lex103             , /* _Lex103 ~ 'PUBLIC' */
  _Lex104             , /* _Lex104 ~ 'NDATA' */
  _Lex105             , /* _Lex105 ~ 'encoding' */
  _Lex106             , /* _Lex106 ~ [A-Za-z] */
  _Lex107             , /* _Lex107 ~ [A-Za-z0-9._] */
  _Lex108             , /* _Lex108 ~ '<!NOTATION' */
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
  XMLDecl_maybe       ,
  _Gen009             ,
  _Gen009_many        ,
  _Gen038             ,
  _Gen038_any         ,
  _Gen041             ,
  _Gen041_any         ,
  _Gen044             ,
  _Gen044_many        ,
  _Gen047             ,
  _Gen047_any         ,
  _Gen050             ,
  _Gen050_any         ,
  _Gen054             ,
  _Gen054_any         ,
  _Gen060             ,
  _Gen060_any         ,
  _Gen063             ,
  _Gen063_any         ,
  _Gen069             ,
  _Gen071             ,
  _Gen075             ,
  _Gen076             ,
  _Gen076_any         ,
  _Gen086             ,
  _Gen087             ,
  _Gen089             ,
  _Gen090             ,
  _Gen091             ,
  _Gen092             ,
  _Gen093             ,
  _Gen094             ,
  _Gen094_any         ,
  _Gen099             ,
  _Gen100             ,
  _Gen101             ,
  _Gen102             ,
  _Gen102_maybe       ,
  _Gen106             ,
  _Gen108             ,
  _Gen110             ,
  _Gen112             ,
  _Gen113             ,
  _Gen117             ,
  _Gen118             ,
  _Gen119             ,
  _Gen124             ,
  _Gen124_maybe       ,
  _Gen135             ,
  _Gen144             ,
  _Gen144_maybe       ,
  _Gen147             ,
  _Gen147_maybe       ,
  _Gen153             ,
  _Gen153_any         ,
  _Gen166             ,
  _Gen166_any         ,
  _Gen171             ,
  _Gen173             ,
  _Gen174             ,
  _Gen176             ,
  _Gen177             ,
  _Gen182             ,
  _Gen182_any         ,
  _Gen189             ,
  _Gen194             ,
  _Gen194_any         ,
  _Gen197             ,
  _Gen197_any         ,
  _Gen205             ,
  _Gen207             ,
  _Gen207_maybe       ,
  _Gen213             ,
  _Gen216             ,
  _Gen216_maybe       ,
  _Gen222             ,
  _Gen222_many        ,
  _Gen225             ,
  _Gen225_any         ,
  _Gen228             ,
  _Gen228_any         ,
  _Gen248             ,
  _Gen248_any         ,
  _Gen251             ,
  _Gen251_any         ,
  _Gen254             ,
  _Gen254_maybe       ,
  _Gen257             ,
  _Gen266             ,
  _Gen266_any         ,
  _Gen269             ,
  _Gen271             ,
  _Gen272             ,
  _Gen287             ,
  _Gen299             ,
  _Gen302             ,
  _Gen302_any         ,
  _Gen306             ,
  _Lex026_many        ,
  _Lex036_any         ,
  _Lex037_any         ,
  _Lex040_any         ,
  _Lex098_many        ,
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
} xml_1_0_symbol_t;

#define XML_1_0_TERMINAL_MAX _Lex108

/*******************/
/* xml_1_0_newp  */
/*******************/
xml_1_0_t *xml_1_0_newp(marpaWrapperOption_t *marpaWrapperOptionp) {
  xml_1_0_t           *xml_1_0p;
  marpaWrapperOption_t marpaWrapperOption;

  /* Fill the defaults */
  if (marpaWrapperOptionp == NULL) {
    marpaWrapper_optionDefaultb(&marpaWrapperOption);
  } else {
    marpaWrapperOption = *marpaWrapperOptionp;
  }

  xml_1_0p = malloc(sizeof(xml_1_0_t));
  if (xml_1_0p == NULL) {
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

  xml_1_0p->marpaWrapperp = NULL;
  xml_1_0p->marpaWrapperSymbolArrayp = NULL;

  if (_xml_1_0_buildGrammarb(xml_1_0p, &marpaWrapperOption) == MARPAWRAPPER_BOOL_FALSE) {
    xml_1_0_destroyv(&xml_1_0p);
  }

  return xml_1_0p;
}

/*********************/
/* xml_1_0_destroyv  */
/*********************/
void xml_1_0_destroyv(xml_1_0_t **xml_1_0pp) {
  xml_1_0_t *xml_1_0p;

  if (xml_1_0pp != NULL) {
    xml_1_0p = *xml_1_0pp;

    if (xml_1_0p != NULL) {
      if (xml_1_0p->marpaWrapperp != NULL) {
	marpaWrapper_destroyv(&(xml_1_0p->marpaWrapperp));
      }
      if (xml_1_0p->marpaWrapperSymbolArrayp != NULL) {
	free(xml_1_0p->marpaWrapperSymbolArrayp);
      }
      free(xml_1_0p);
    }

    *xml_1_0pp = NULL;
  }
}

/**************************/
/* _xml_1_0_buildGrammarb */
/**************************/
static marpaWrapperBool_t _xml_1_0_buildGrammarb(xml_1_0_t *xml_1_0p, marpaWrapperOption_t *marpaWrapperOptionp) {

  xml_1_0p->marpaWrapperp = marpaWrapper_newp(marpaWrapperOptionp);
  if (xml_1_0p->marpaWrapperp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  if (_xml_1_0_buildSymbolsb(xml_1_0p) == MARPAWRAPPER_BOOL_FALSE) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  if (_xml_1_0_buildRulesb(xml_1_0p) == MARPAWRAPPER_BOOL_FALSE) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  if (marpaWrapper_g_precomputeb(xml_1_0p->marpaWrapperp) == MARPAWRAPPER_BOOL_FALSE) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  return MARPAWRAPPER_BOOL_TRUE;
}

/**************************/
/* _xml_1_0_buildSymbolsb */
/**************************/
static marpaWrapperBool_t _xml_1_0_buildSymbolsb(xml_1_0_t *xml_1_0p) {
  int                        i;
  marpaWrapperSymbolOption_t marpaWrapperSymbolOption;

  xml_1_0p->marpaWrapperSymbolArrayp = malloc(_SYMBOL_MAX * sizeof(marpaWrapperSymbol_t *));
  if (xml_1_0p->marpaWrapperSymbolArrayp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }

  for (i = 0; i < _SYMBOL_MAX; i++) {

    /* Fill default options */
    if (marpaWrapper_symbolOptionDefaultb(&marpaWrapperSymbolOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }

    /* Opaque data will be our "this" */
    marpaWrapperSymbolOption.datavp = xml_1_0p;

    /* Optional, but we can make ourself the terminals */
    marpaWrapperSymbolOption.terminalb = (i <= XML_1_0_TERMINAL_MAX) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;

    /* Start rule ? */
    marpaWrapperSymbolOption.startb = (i == document) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;

    /* Create the symbol */
    xml_1_0p->marpaWrapperSymbolArrayp[i] = marpaWrapper_g_addSymbolp (xml_1_0p->marpaWrapperp, &marpaWrapperSymbolOption);
    if (xml_1_0p->marpaWrapperSymbolArrayp[i] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }

  }

  return MARPAWRAPPER_BOOL_TRUE;
}

/************************/
/* _xml_1_0_buildRulesb */
/************************/
static marpaWrapperBool_t _xml_1_0_buildRulesb(xml_1_0_t *xml_1_0p) {
  marpaWrapperRuleOption_t   marpaWrapperRuleOption;


  {
    /* AttDef ::= S Name S AttType S DefaultDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_0p->marpaWrapperSymbolArrayp[S],
      xml_1_0p->marpaWrapperSymbolArrayp[Name],
      xml_1_0p->marpaWrapperSymbolArrayp[S],
      xml_1_0p->marpaWrapperSymbolArrayp[AttType],
      xml_1_0p->marpaWrapperSymbolArrayp[S],
      xml_1_0p->marpaWrapperSymbolArrayp[DefaultDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[AttDef];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* AttDef_any ::= AttDef * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[AttDef]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[AttDef_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* AttType ::= StringType  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[StringType]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[AttType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* AttType ::= TokenizedType  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[TokenizedType]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[AttType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* AttType ::= EnumeratedType  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[EnumeratedType]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[AttType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* AttValue ::= _Lex030 _Gen060_any _Lex030  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex030],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen060_any],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex030]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[AttValue];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* AttValue ::= _Lex032 _Gen063_any _Lex032  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex032],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen063_any],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex032]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[AttValue];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* AttlistDecl ::= _Lex079 S Name AttDef_any S_maybe _Lex060  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex079],
      xml_1_0p->marpaWrapperSymbolArrayp[S],
      xml_1_0p->marpaWrapperSymbolArrayp[Name],
      xml_1_0p->marpaWrapperSymbolArrayp[AttDef_any],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex060]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[AttlistDecl];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Attribute ::= Name Eq AttValue  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[Name],
      xml_1_0p->marpaWrapperSymbolArrayp[Eq],
      xml_1_0p->marpaWrapperSymbolArrayp[AttValue]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Attribute];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* CDEnd ::= _Lex041  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex041]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[CDEnd];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* CDSect ::= CDStart CData CDEnd  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[CDStart],
      xml_1_0p->marpaWrapperSymbolArrayp[CData],
      xml_1_0p->marpaWrapperSymbolArrayp[CDEnd]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[CDSect];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* CDStart ::= _Lex052  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex052]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[CDStart];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* CData ::= _Gen119  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen119]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[CData];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Char ::= _Lex001  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex001]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Char];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Char ::= _Lex002  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex002]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Char];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Char ::= _Lex003  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex003]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Char];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Char ::= _Lex004  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex004]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Char];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Char ::= _Lex005  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex005]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Char];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Char ::= _Lex006  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex006]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Char];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* CharData ::= _Gen087  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen087]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[CharData];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* CharData_maybe ::= CharData  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[CharData]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[CharData_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* CharData_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[CharData_maybe];
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* CharRef ::= _Lex095 _Lex026_many _Lex096  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex095],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex026_many],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex096]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[CharRef];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* CharRef ::= _Lex097 _Lex098_many _Lex096  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex097],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex098_many],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex096]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[CharRef];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Char_any ::= Char * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[Char]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Char_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Comment ::= _Lex042 _Gen094_any _Lex043  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex042],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen094_any],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex043]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Comment];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* DeclSep ::= PEReference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[PEReference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[DeclSep];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* DeclSep ::= S  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[S]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[DeclSep];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* DefaultDecl ::= _Lex089  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex089]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[DefaultDecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* DefaultDecl ::= _Lex090  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex090]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[DefaultDecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* DefaultDecl ::= _Gen257  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen257]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[DefaultDecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* ETag ::= _Lex065 Name S_maybe _Lex060  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex065],
      xml_1_0p->marpaWrapperSymbolArrayp[Name],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex060]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[ETag];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* EmptyElemTag ::= _Lex064 Name _Gen197_any S_maybe _Lex066  */
    marpaWrapperSymbol_t *rhsSymbolpp[5] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex064],
      xml_1_0p->marpaWrapperSymbolArrayp[Name],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen197_any],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex066]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[EmptyElemTag];
    marpaWrapperRuleOption.nRhsSymboli = 5;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* EncName ::= _Lex106 _Gen302_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex106],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen302_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[EncName];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* EncodingDecl ::= S _Lex105 Eq _Gen299  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[S],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex105],
      xml_1_0p->marpaWrapperSymbolArrayp[Eq],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen299]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[EncodingDecl];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* EncodingDecl_maybe ::= EncodingDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[EncodingDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[EncodingDecl_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* EncodingDecl_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[EncodingDecl_maybe];
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* EntityDecl ::= GEDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[GEDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[EntityDecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* EntityDecl ::= PEDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[PEDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[EntityDecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* EntityDef ::= EntityValue  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[EntityValue]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[EntityDef];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* EntityDef ::= _Gen287  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen287]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[EntityDef];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* EntityRef ::= _Lex099 Name _Lex096  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex099],
      xml_1_0p->marpaWrapperSymbolArrayp[Name],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex096]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[EntityRef];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* EntityValue ::= _Lex030 _Gen050_any _Lex030  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex030],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen050_any],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex030]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[EntityValue];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* EntityValue ::= _Lex032 _Gen054_any _Lex032  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex032],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen054_any],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex032]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[EntityValue];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* EnumeratedType ::= NotationType  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[NotationType]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[EnumeratedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* EnumeratedType ::= Enumeration  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[Enumeration]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[EnumeratedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Enumeration ::= _Lex073 S_maybe Nmtoken _Gen251_any S_maybe _Lex075  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex073],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[Nmtoken],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen251_any],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex075]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Enumeration];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Eq ::= S_maybe _Lex055 S_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex055],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Eq];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* ExternalID ::= _Lex102 S SystemLiteral  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex102],
      xml_1_0p->marpaWrapperSymbolArrayp[S],
      xml_1_0p->marpaWrapperSymbolArrayp[SystemLiteral]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[ExternalID];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* ExternalID ::= _Lex103 S PubidLiteral S SystemLiteral  */
    marpaWrapperSymbol_t *rhsSymbolpp[5] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex103],
      xml_1_0p->marpaWrapperSymbolArrayp[S],
      xml_1_0p->marpaWrapperSymbolArrayp[PubidLiteral],
      xml_1_0p->marpaWrapperSymbolArrayp[S],
      xml_1_0p->marpaWrapperSymbolArrayp[SystemLiteral]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[ExternalID];
    marpaWrapperRuleOption.nRhsSymboli = 5;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* GEDecl ::= _Lex101 S Name S EntityDef S_maybe _Lex060  */
    marpaWrapperSymbol_t *rhsSymbolpp[7] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex101],
      xml_1_0p->marpaWrapperSymbolArrayp[S],
      xml_1_0p->marpaWrapperSymbolArrayp[Name],
      xml_1_0p->marpaWrapperSymbolArrayp[S],
      xml_1_0p->marpaWrapperSymbolArrayp[EntityDef],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex060]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[GEDecl];
    marpaWrapperRuleOption.nRhsSymboli = 7;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Ignore ::= _Gen272  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen272]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Ignore];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Misc ::= Comment  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[Comment]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Misc];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Misc ::= PI  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[PI]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Misc];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Misc ::= S  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[S]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Misc];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Misc_any ::= Misc * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[Misc]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Misc_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Mixed ::= _Lex073 S_maybe _Lex077 _Gen228_any S_maybe _Lex078  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex073],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex077],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen228_any],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex078]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Mixed];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Mixed ::= _Lex073 S_maybe _Lex077 S_maybe _Lex075  */
    marpaWrapperSymbol_t *rhsSymbolpp[5] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex073],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex077],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex075]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Mixed];
    marpaWrapperRuleOption.nRhsSymboli = 5;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NDataDecl ::= S _Lex104 S Name  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[S],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex104],
      xml_1_0p->marpaWrapperSymbolArrayp[S],
      xml_1_0p->marpaWrapperSymbolArrayp[Name]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NDataDecl];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NDataDecl_maybe ::= NDataDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[NDataDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NDataDecl_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NDataDecl_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NDataDecl_maybe];
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Name ::= NameStartChar _Gen038_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[NameStartChar],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen038_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Name];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameChar ::= NameStartChar  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[NameStartChar]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameChar ::= _Lex024  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex024]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameChar ::= _Lex025  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex025]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameChar ::= _Lex026  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex026]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameChar ::= _Lex027  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex027]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameChar ::= _Lex028  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex028]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameChar ::= _Lex029  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex029]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameStartChar ::= _Lex008  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex008]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameStartChar ::= _Lex009  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex009]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameStartChar ::= _Lex010  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex010]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameStartChar ::= _Lex011  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex011]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameStartChar ::= _Lex012  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex012]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameStartChar ::= _Lex013  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex013]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameStartChar ::= _Lex014  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex014]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameStartChar ::= _Lex015  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex015]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameStartChar ::= _Lex016  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex016]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameStartChar ::= _Lex017  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex017]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameStartChar ::= _Lex018  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex018]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameStartChar ::= _Lex019  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex019]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameStartChar ::= _Lex020  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex020]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameStartChar ::= _Lex021  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex021]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameStartChar ::= _Lex022  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex022]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NameStartChar ::= _Lex023  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex023]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Names ::= Name _Gen041_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[Name],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen041_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Names];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Nmtoken ::= _Gen044_many  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen044_many]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Nmtoken];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Nmtokens ::= Nmtoken _Gen047_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[Nmtoken],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen047_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Nmtokens];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NotationDecl ::= _Lex108 S Name S _Gen306 S_maybe _Lex060  */
    marpaWrapperSymbol_t *rhsSymbolpp[7] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex108],
      xml_1_0p->marpaWrapperSymbolArrayp[S],
      xml_1_0p->marpaWrapperSymbolArrayp[Name],
      xml_1_0p->marpaWrapperSymbolArrayp[S],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen306],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex060]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NotationDecl];
    marpaWrapperRuleOption.nRhsSymboli = 7;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* NotationType ::= _Lex088 S _Lex073 S_maybe Name _Gen248_any S_maybe _Lex075  */
    marpaWrapperSymbol_t *rhsSymbolpp[8] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex088],
      xml_1_0p->marpaWrapperSymbolArrayp[S],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex073],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[Name],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen248_any],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex075]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NotationType];
    marpaWrapperRuleOption.nRhsSymboli = 8;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* PEDecl ::= _Lex101 S _Lex100 S Name S PEDef S_maybe _Lex060  */
    marpaWrapperSymbol_t *rhsSymbolpp[9] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex101],
      xml_1_0p->marpaWrapperSymbolArrayp[S],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex100],
      xml_1_0p->marpaWrapperSymbolArrayp[S],
      xml_1_0p->marpaWrapperSymbolArrayp[Name],
      xml_1_0p->marpaWrapperSymbolArrayp[S],
      xml_1_0p->marpaWrapperSymbolArrayp[PEDef],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex060]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[PEDecl];
    marpaWrapperRuleOption.nRhsSymboli = 9;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* PEDef ::= EntityValue  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[EntityValue]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[PEDef];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* PEDef ::= ExternalID  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[ExternalID]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[PEDef];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* PEReference ::= _Lex100 Name _Lex096  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex100],
      xml_1_0p->marpaWrapperSymbolArrayp[Name],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex096]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[PEReference];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* PI ::= _Lex044 PITarget _Gen102_maybe _Lex045  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex044],
      xml_1_0p->marpaWrapperSymbolArrayp[PITarget],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen102_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex045]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[PI];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* PITarget ::= _Gen113  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen113]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[PITarget];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* PubidChar ::= _Lex007  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex007]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[PubidChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* PubidChar ::= _Lex003  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex003]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[PubidChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* PubidChar ::= _Lex002  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex002]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[PubidChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* PubidChar ::= _Lex038  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex038]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[PubidChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* PubidChar ::= _Lex039  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex039]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[PubidChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* PubidChar_any ::= PubidChar * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[PubidChar]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[PubidChar_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* PubidLiteral ::= _Lex030 PubidChar_any _Lex030  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex030],
      xml_1_0p->marpaWrapperSymbolArrayp[PubidChar_any],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex030]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[PubidLiteral];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* PubidLiteral ::= _Lex032 _Gen076_any _Lex032  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex032],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen076_any],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex032]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[PubidLiteral];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* PublicID ::= _Lex103 S PubidLiteral  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex103],
      xml_1_0p->marpaWrapperSymbolArrayp[S],
      xml_1_0p->marpaWrapperSymbolArrayp[PubidLiteral]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[PublicID];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Reference ::= EntityRef  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[EntityRef]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Reference];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* Reference ::= CharRef  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[CharRef]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Reference];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* S ::= _Gen009_many  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen009_many]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[S];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* SDDecl ::= S _Lex061 Eq _Gen177  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[S],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex061],
      xml_1_0p->marpaWrapperSymbolArrayp[Eq],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen177]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[SDDecl];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* SDDecl_maybe ::= SDDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[SDDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[SDDecl_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* SDDecl_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[SDDecl_maybe];
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* STag ::= _Lex064 Name _Gen182_any S_maybe _Lex060  */
    marpaWrapperSymbol_t *rhsSymbolpp[5] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex064],
      xml_1_0p->marpaWrapperSymbolArrayp[Name],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen182_any],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex060]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[STag];
    marpaWrapperRuleOption.nRhsSymboli = 5;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* S_maybe ::= S  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[S]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[S_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* S_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[S_maybe];
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* StringType ::= _Lex080  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex080]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[StringType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* SystemLiteral ::= _Gen069  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen069]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[SystemLiteral];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* SystemLiteral ::= _Gen071  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen071]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[SystemLiteral];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* TextDecl ::= _Lex053 VersionInfo_maybe EncodingDecl S_maybe _Lex045  */
    marpaWrapperSymbol_t *rhsSymbolpp[5] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex053],
      xml_1_0p->marpaWrapperSymbolArrayp[VersionInfo_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[EncodingDecl],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex045]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[TextDecl];
    marpaWrapperRuleOption.nRhsSymboli = 5;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* TextDecl_maybe ::= TextDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[TextDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[TextDecl_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* TextDecl_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[TextDecl_maybe];
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* TokenizedType ::= _Lex081  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex081]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* TokenizedType ::= _Lex082  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex082]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* TokenizedType ::= _Lex083  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex083]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* TokenizedType ::= _Lex084  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex084]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* TokenizedType ::= _Lex085  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex085]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* TokenizedType ::= _Lex086  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex086]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* TokenizedType ::= _Lex087  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex087]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* VersionInfo ::= S _Lex054 Eq _Gen135  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[S],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex054],
      xml_1_0p->marpaWrapperSymbolArrayp[Eq],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen135]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[VersionInfo];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* VersionInfo_maybe ::= VersionInfo  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[VersionInfo]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[VersionInfo_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* VersionInfo_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[VersionInfo_maybe];
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* VersionNum ::= _Lex056 _Lex026_many  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex056],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex026_many]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[VersionNum];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* XMLDecl ::= _Lex053 VersionInfo EncodingDecl_maybe SDDecl_maybe S_maybe _Lex045  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex053],
      xml_1_0p->marpaWrapperSymbolArrayp[VersionInfo],
      xml_1_0p->marpaWrapperSymbolArrayp[EncodingDecl_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[SDDecl_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex045]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[XMLDecl];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* XMLDecl_maybe ::= XMLDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[XMLDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[XMLDecl_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* XMLDecl_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[XMLDecl_maybe];
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen009 ::= _Lex007  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex007]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen009];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen009 ::= _Lex001  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex001]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen009];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen009 ::= _Lex003  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex003]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen009];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen009 ::= _Lex002  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex002]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen009];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen009_many ::= _Gen009 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen009]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen009_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen038 ::= NameChar  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[NameChar]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen038];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen038_any ::= _Gen038 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen038]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen038_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen041 ::= _Lex007 Name  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex007],
      xml_1_0p->marpaWrapperSymbolArrayp[Name]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen041];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen041_any ::= _Gen041 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen041]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen041_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen044 ::= NameChar  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[NameChar]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen044];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen044_many ::= _Gen044 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen044]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen044_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen047 ::= _Lex007 Nmtoken  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex007],
      xml_1_0p->marpaWrapperSymbolArrayp[Nmtoken]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen047];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen047_any ::= _Gen047 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen047]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen047_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen050 ::= _Lex031  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex031]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen050];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen050 ::= PEReference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[PEReference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen050];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen050 ::= Reference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[Reference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen050];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen050_any ::= _Gen050 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen050]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen050_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen054 ::= _Lex033  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex033]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen054];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen054 ::= PEReference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[PEReference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen054];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen054 ::= Reference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[Reference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen054];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen054_any ::= _Gen054 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen054]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen054_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen060 ::= _Lex034  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex034]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen060];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen060 ::= Reference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[Reference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen060];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen060_any ::= _Gen060 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen060]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen060_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen063 ::= _Lex035  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex035]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen063];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen063 ::= Reference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[Reference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen063];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen063_any ::= _Gen063 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen063]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen063_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen069 ::= _Lex030 _Lex036_any _Lex030  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex030],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex036_any],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex030]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen069];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen071 ::= _Lex032 _Lex037_any _Lex032  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex032],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex037_any],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex032]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen071];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen075 ::= _Exclusion001  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Exclusion001]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen075];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen076 ::= _Gen075  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen075]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen076];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen076_any ::= _Gen076 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen076]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen076_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen086 ::= _Lex040_any _Lex041 _Lex040_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex040_any],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex041],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex040_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen086];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen087 ::= _Exclusion002  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Exclusion002]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen087];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen089 ::= _Exclusion003  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Exclusion003]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen089];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen090 ::= _Gen089  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen089]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen090];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen091 ::= _Exclusion003  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Exclusion003]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen091];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen092 ::= _Gen091  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen091]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen092];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen093 ::= _Lex024 _Gen092  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex024],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen092]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen093];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen094 ::= _Gen090  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen090]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen094];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen094 ::= _Gen093  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen093]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen094];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen094_any ::= _Gen094 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen094]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen094_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen099 ::= Char_any _Lex045 Char_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[Char_any],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex045],
      xml_1_0p->marpaWrapperSymbolArrayp[Char_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen099];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen100 ::= _Exclusion004  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Exclusion004]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen100];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen101 ::= _Gen100  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen100]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen101];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen102 ::= S _Gen101  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[S],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen101]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen102];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen102_maybe ::= _Gen102  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen102]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen102_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen102_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen102_maybe];
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen106 ::= _Lex046  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex046]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen106];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen106 ::= _Lex047  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex047]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen106];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen108 ::= _Lex048  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex048]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen108];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen108 ::= _Lex049  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex049]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen108];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen110 ::= _Lex050  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex050]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen110];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen110 ::= _Lex051  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex051]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen110];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen112 ::= _Gen106 _Gen108 _Gen110  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen106],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen108],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen110]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen112];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen113 ::= _Exclusion005  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Exclusion005]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen113];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen117 ::= Char_any _Lex041 Char_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[Char_any],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex041],
      xml_1_0p->marpaWrapperSymbolArrayp[Char_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen117];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen118 ::= _Exclusion006  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Exclusion006]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen118];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen119 ::= _Gen118  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen118]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen119];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen124 ::= doctypedecl Misc_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[doctypedecl],
      xml_1_0p->marpaWrapperSymbolArrayp[Misc_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen124];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen124_maybe ::= _Gen124  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen124]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen124_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen124_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen124_maybe];
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen135 ::= _Lex032 VersionNum _Lex032  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex032],
      xml_1_0p->marpaWrapperSymbolArrayp[VersionNum],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex032]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen135];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen135 ::= _Lex030 VersionNum _Lex030  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex030],
      xml_1_0p->marpaWrapperSymbolArrayp[VersionNum],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex030]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen135];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen144 ::= S ExternalID  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[S],
      xml_1_0p->marpaWrapperSymbolArrayp[ExternalID]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen144];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen144_maybe ::= _Gen144  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen144]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen144_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen144_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen144_maybe];
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen147 ::= _Lex058 intSubset _Lex059 S_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex058],
      xml_1_0p->marpaWrapperSymbolArrayp[intSubset],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex059],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen147];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen147_maybe ::= _Gen147  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen147]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen147_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen147_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen147_maybe];
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen153 ::= markupdecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[markupdecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen153];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen153 ::= DeclSep  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[DeclSep]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen153];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen153_any ::= _Gen153 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen153]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen153_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen166 ::= markupdecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[markupdecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen166];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen166 ::= conditionalSect  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[conditionalSect]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen166];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen166 ::= DeclSep  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[DeclSep]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen166];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen166_any ::= _Gen166 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen166]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen166_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen171 ::= _Lex062  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex062]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen171];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen171 ::= _Lex063  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex063]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen171];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen173 ::= _Lex032 _Gen171 _Lex032  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex032],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen171],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex032]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen173];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen174 ::= _Lex062  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex062]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen174];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen174 ::= _Lex063  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex063]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen174];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen176 ::= _Lex030 _Gen174 _Lex030  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex030],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen174],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex030]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen176];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen177 ::= _Gen173  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen173]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen177];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen177 ::= _Gen176  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen176]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen177];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen182 ::= S Attribute  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[S],
      xml_1_0p->marpaWrapperSymbolArrayp[Attribute]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen182];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen182_any ::= _Gen182 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen182]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen182_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen189 ::= element  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[element]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen189];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen189 ::= Reference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[Reference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen189];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen189 ::= CDSect  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[CDSect]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen189];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen189 ::= PI  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[PI]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen189];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen189 ::= Comment  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[Comment]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen189];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen194 ::= _Gen189 CharData_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen189],
      xml_1_0p->marpaWrapperSymbolArrayp[CharData_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen194];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen194_any ::= _Gen194 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen194]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen194_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen197 ::= S Attribute  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[S],
      xml_1_0p->marpaWrapperSymbolArrayp[Attribute]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen197];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen197_any ::= _Gen197 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen197]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen197_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen205 ::= choice  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[choice]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen205];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen205 ::= seq  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[seq]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen205];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen207 ::= _Lex070  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex070]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen207];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen207 ::= _Lex071  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex071]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen207];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen207 ::= _Lex072  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex072]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen207];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen207_maybe ::= _Gen207  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen207]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen207_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen207_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen207_maybe];
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen213 ::= Name  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[Name]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen213];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen213 ::= choice  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[choice]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen213];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen213 ::= seq  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[seq]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen213];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen216 ::= _Lex070  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex070]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen216];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen216 ::= _Lex071  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex071]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen216];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen216 ::= _Lex072  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex072]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen216];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen216_maybe ::= _Gen216  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen216]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen216_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen216_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen216_maybe];
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen222 ::= S_maybe _Lex074 S_maybe cp  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex074],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[cp]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen222];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen222_many ::= _Gen222 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen222]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen222_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen225 ::= S_maybe _Lex076 S_maybe cp  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex076],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[cp]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen225];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen225_any ::= _Gen225 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen225]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen225_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen228 ::= S_maybe _Lex074 S_maybe Name  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex074],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[Name]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen228];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen228_any ::= _Gen228 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen228]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen228_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen248 ::= S_maybe _Lex074 S_maybe Name  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex074],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[Name]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen248];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen248_any ::= _Gen248 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen248]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen248_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen251 ::= S_maybe _Lex074 S_maybe Nmtoken  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex074],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[Nmtoken]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen251];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen251_any ::= _Gen251 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen251]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen251_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen254 ::= _Lex091 S  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex091],
      xml_1_0p->marpaWrapperSymbolArrayp[S]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen254];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen254_maybe ::= _Gen254  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen254]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen254_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen254_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen254_maybe];
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen257 ::= _Gen254_maybe AttValue  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen254_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[AttValue]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen257];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen266 ::= _Lex092 ignoreSectContents _Lex041 Ignore  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex092],
      xml_1_0p->marpaWrapperSymbolArrayp[ignoreSectContents],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex041],
      xml_1_0p->marpaWrapperSymbolArrayp[Ignore]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen266];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen266_any ::= _Gen266 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen266]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen266_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen269 ::= _Lex092  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex092]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen269];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen269 ::= _Lex041  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex041]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen269];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen271 ::= Char_any _Gen269 Char_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[Char_any],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen269],
      xml_1_0p->marpaWrapperSymbolArrayp[Char_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen271];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen272 ::= _Exclusion007  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Exclusion007]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen272];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen287 ::= ExternalID NDataDecl_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[ExternalID],
      xml_1_0p->marpaWrapperSymbolArrayp[NDataDecl_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen287];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen299 ::= _Lex030 EncName _Lex030  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex030],
      xml_1_0p->marpaWrapperSymbolArrayp[EncName],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex030]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen299];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen299 ::= _Lex032 EncName _Lex032  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex032],
      xml_1_0p->marpaWrapperSymbolArrayp[EncName],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex032]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen299];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen302 ::= _Lex107  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex107]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen302];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen302 ::= _Lex024  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex024]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen302];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen302_any ::= _Gen302 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen302]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen302_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen306 ::= ExternalID  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[ExternalID]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen306];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Gen306 ::= PublicID  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[PublicID]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen306];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Lex026_many ::= _Lex026 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex026]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Lex026_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Lex036_any ::= _Lex036 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex036]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Lex036_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Lex037_any ::= _Lex037 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex037]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Lex037_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Lex040_any ::= _Lex040 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex040]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Lex040_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* _Lex098_many ::= _Lex098 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex098]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Lex098_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* children ::= _Gen205 _Gen207_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen205],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen207_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[children];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* choice ::= _Lex073 S_maybe cp _Gen222_many S_maybe _Lex075  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex073],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[cp],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen222_many],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex075]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[choice];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* conditionalSect ::= includeSect  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[includeSect]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[conditionalSect];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* conditionalSect ::= ignoreSect  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[ignoreSect]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[conditionalSect];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* content ::= CharData_maybe _Gen194_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[CharData_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen194_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[content];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* contentspec ::= _Lex068  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex068]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[contentspec];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* contentspec ::= _Lex069  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex069]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[contentspec];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* contentspec ::= Mixed  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[Mixed]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[contentspec];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* contentspec ::= children  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[children]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[contentspec];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* cp ::= _Gen213 _Gen216_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen213],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen216_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[cp];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* doctypedecl ::= _Lex057 S Name _Gen144_maybe S_maybe _Gen147_maybe _Lex060  */
    marpaWrapperSymbol_t *rhsSymbolpp[7] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex057],
      xml_1_0p->marpaWrapperSymbolArrayp[S],
      xml_1_0p->marpaWrapperSymbolArrayp[Name],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen144_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen147_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex060]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[doctypedecl];
    marpaWrapperRuleOption.nRhsSymboli = 7;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* document ::= prolog element Misc_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[prolog],
      xml_1_0p->marpaWrapperSymbolArrayp[element],
      xml_1_0p->marpaWrapperSymbolArrayp[Misc_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[document];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* element ::= EmptyElemTag  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[EmptyElemTag]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[element];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* element ::= STag content ETag  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[STag],
      xml_1_0p->marpaWrapperSymbolArrayp[content],
      xml_1_0p->marpaWrapperSymbolArrayp[ETag]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[element];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* elementdecl ::= _Lex067 S Name S contentspec S_maybe _Lex060  */
    marpaWrapperSymbol_t *rhsSymbolpp[7] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex067],
      xml_1_0p->marpaWrapperSymbolArrayp[S],
      xml_1_0p->marpaWrapperSymbolArrayp[Name],
      xml_1_0p->marpaWrapperSymbolArrayp[S],
      xml_1_0p->marpaWrapperSymbolArrayp[contentspec],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex060]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[elementdecl];
    marpaWrapperRuleOption.nRhsSymboli = 7;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* extParsedEnt ::= TextDecl_maybe content  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[TextDecl_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[content]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[extParsedEnt];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* extSubset ::= TextDecl_maybe extSubsetDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[TextDecl_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[extSubsetDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[extSubset];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* extSubsetDecl ::= _Gen166_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen166_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[extSubsetDecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* ignoreSect ::= _Lex092 S_maybe _Lex094 S_maybe _Lex058 ignoreSectContents_any _Lex041  */
    marpaWrapperSymbol_t *rhsSymbolpp[7] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex092],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex094],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex058],
      xml_1_0p->marpaWrapperSymbolArrayp[ignoreSectContents_any],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex041]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[ignoreSect];
    marpaWrapperRuleOption.nRhsSymboli = 7;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* ignoreSectContents ::= Ignore _Gen266_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[Ignore],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen266_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[ignoreSectContents];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* ignoreSectContents_any ::= ignoreSectContents * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[ignoreSectContents]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[ignoreSectContents_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* includeSect ::= _Lex092 S_maybe _Lex093 S_maybe _Lex058 extSubsetDecl _Lex041  */
    marpaWrapperSymbol_t *rhsSymbolpp[7] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex092],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex093],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex058],
      xml_1_0p->marpaWrapperSymbolArrayp[extSubsetDecl],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex041]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[includeSect];
    marpaWrapperRuleOption.nRhsSymboli = 7;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* intSubset ::= _Gen153_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen153_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[intSubset];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* markupdecl ::= elementdecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[elementdecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[markupdecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* markupdecl ::= AttlistDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[AttlistDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[markupdecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* markupdecl ::= EntityDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[EntityDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[markupdecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* markupdecl ::= NotationDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[NotationDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[markupdecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* markupdecl ::= PI  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[PI]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[markupdecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* markupdecl ::= Comment  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[Comment]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[markupdecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* prolog ::= XMLDecl_maybe Misc_any _Gen124_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[XMLDecl_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[Misc_any],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen124_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[prolog];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* seq ::= _Lex073 S_maybe cp _Gen225_any S_maybe _Lex075  */
    marpaWrapperSymbol_t *rhsSymbolpp[6] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex073],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[cp],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen225_any],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex075]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    marpaWrapperRuleOption.datavp = xml_1_0p;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[seq];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    if (marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption) == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
    return MARPAWRAPPER_BOOL_TRUE;
}
