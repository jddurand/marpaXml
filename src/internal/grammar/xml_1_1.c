#include <stdlib.h>
#include <errno.h>
#include "internal/grammar/xml_1_1.h"

static marpaWrapperBool_t _xml_1_1_buildGrammarb(xml_1_1_t *xml_1_1p, marpaWrapperOption_t *marpaWrapperOptionp);
static marpaWrapperBool_t _xml_1_1_buildSymbolsb(xml_1_1_t *xml_1_1p);
static marpaWrapperBool_t _xml_1_1_buildSymbols_withStartb(xml_1_1_t *xml_1_1p, int starti);
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

/* Rules */
typedef enum xml_1_1_rule {
  Misc_any_001 = 0    , /* Misc_any ::= Misc * */
  _Gen002_001         , /* _Gen002 ::= prolog element Misc_any  */
  Char_any_001        , /* Char_any ::= Char * */
  _Gen004_001         , /* _Gen004 ::= Char_any RestrictedChar Char_any  */
  _Gen005_001         , /* _Gen005 ::= _Exclusion001  */
  document_001        , /* document ::= _Gen005  */
  Char_001            , /* Char ::= _Lex001  */
  Char_002            , /* Char ::= _Lex002  */
  Char_003            , /* Char ::= _Lex003  */
  RestrictedChar_001  , /* RestrictedChar ::= _Lex004  */
  RestrictedChar_002  , /* RestrictedChar ::= _Lex005  */
  RestrictedChar_003  , /* RestrictedChar ::= _Lex006  */
  RestrictedChar_004  , /* RestrictedChar ::= _Lex007  */
  RestrictedChar_005  , /* RestrictedChar ::= _Lex008  */
  _Gen015_001         , /* _Gen015 ::= _Lex009  */
  _Gen015_002         , /* _Gen015 ::= _Lex010  */
  _Gen015_003         , /* _Gen015 ::= _Lex011  */
  _Gen015_004         , /* _Gen015 ::= _Lex012  */
  _Gen015_many_001    , /* _Gen015_many ::= _Gen015 + */
  S_001               , /* S ::= _Gen015_many  */
  NameStartChar_001   , /* NameStartChar ::= _Lex013  */
  NameStartChar_002   , /* NameStartChar ::= _Lex014  */
  NameStartChar_003   , /* NameStartChar ::= _Lex015  */
  NameStartChar_004   , /* NameStartChar ::= _Lex016  */
  NameStartChar_005   , /* NameStartChar ::= _Lex017  */
  NameStartChar_006   , /* NameStartChar ::= _Lex018  */
  NameStartChar_007   , /* NameStartChar ::= _Lex019  */
  NameStartChar_008   , /* NameStartChar ::= _Lex020  */
  NameStartChar_009   , /* NameStartChar ::= _Lex021  */
  NameStartChar_010   , /* NameStartChar ::= _Lex022  */
  NameStartChar_011   , /* NameStartChar ::= _Lex023  */
  NameStartChar_012   , /* NameStartChar ::= _Lex024  */
  NameStartChar_013   , /* NameStartChar ::= _Lex025  */
  NameStartChar_014   , /* NameStartChar ::= _Lex026  */
  NameStartChar_015   , /* NameStartChar ::= _Lex027  */
  NameStartChar_016   , /* NameStartChar ::= _Lex028  */
  NameChar_001        , /* NameChar ::= NameStartChar  */
  NameChar_002        , /* NameChar ::= _Lex029  */
  NameChar_003        , /* NameChar ::= _Lex030  */
  NameChar_004        , /* NameChar ::= _Lex031  */
  NameChar_005        , /* NameChar ::= _Lex032  */
  NameChar_006        , /* NameChar ::= _Lex033  */
  NameChar_007        , /* NameChar ::= _Lex034  */
  _Gen044_001         , /* _Gen044 ::= NameChar  */
  _Gen044_any_001     , /* _Gen044_any ::= _Gen044 * */
  Name_001            , /* Name ::= NameStartChar _Gen044_any  */
  _Gen047_001         , /* _Gen047 ::= _Lex009 Name  */
  _Gen047_any_001     , /* _Gen047_any ::= _Gen047 * */
  Names_001           , /* Names ::= Name _Gen047_any  */
  _Gen050_001         , /* _Gen050 ::= NameChar  */
  _Gen050_many_001    , /* _Gen050_many ::= _Gen050 + */
  Nmtoken_001         , /* Nmtoken ::= _Gen050_many  */
  _Gen053_001         , /* _Gen053 ::= _Lex009 Nmtoken  */
  _Gen053_any_001     , /* _Gen053_any ::= _Gen053 * */
  Nmtokens_001        , /* Nmtokens ::= Nmtoken _Gen053_any  */
  _Gen056_001         , /* _Gen056 ::= _Lex036  */
  _Gen056_002         , /* _Gen056 ::= PEReference  */
  _Gen056_003         , /* _Gen056 ::= Reference  */
  _Gen056_any_001     , /* _Gen056_any ::= _Gen056 * */
  _Gen060_001         , /* _Gen060 ::= _Lex038  */
  _Gen060_002         , /* _Gen060 ::= PEReference  */
  _Gen060_003         , /* _Gen060 ::= Reference  */
  _Gen060_any_001     , /* _Gen060_any ::= _Gen060 * */
  EntityValue_001     , /* EntityValue ::= _Lex035 _Gen056_any _Lex035  */
  EntityValue_002     , /* EntityValue ::= _Lex037 _Gen060_any _Lex037  */
  _Gen066_001         , /* _Gen066 ::= _Lex039  */
  _Gen066_002         , /* _Gen066 ::= Reference  */
  _Gen066_any_001     , /* _Gen066_any ::= _Gen066 * */
  _Gen069_001         , /* _Gen069 ::= _Lex040  */
  _Gen069_002         , /* _Gen069 ::= Reference  */
  _Gen069_any_001     , /* _Gen069_any ::= _Gen069 * */
  AttValue_001        , /* AttValue ::= _Lex035 _Gen066_any _Lex035  */
  AttValue_002        , /* AttValue ::= _Lex037 _Gen069_any _Lex037  */
  _Lex041_any_001     , /* _Lex041_any ::= _Lex041 * */
  _Gen075_001         , /* _Gen075 ::= _Lex035 _Lex041_any _Lex035  */
  _Lex042_any_001     , /* _Lex042_any ::= _Lex042 * */
  _Gen077_001         , /* _Gen077 ::= _Lex037 _Lex042_any _Lex037  */
  SystemLiteral_001   , /* SystemLiteral ::= _Gen075  */
  SystemLiteral_002   , /* SystemLiteral ::= _Gen077  */
  PubidChar_any_001   , /* PubidChar_any ::= PubidChar * */
  _Gen081_001         , /* _Gen081 ::= _Exclusion002  */
  _Gen082_001         , /* _Gen082 ::= _Gen081  */
  _Gen082_any_001     , /* _Gen082_any ::= _Gen082 * */
  PubidLiteral_001    , /* PubidLiteral ::= _Lex035 PubidChar_any _Lex035  */
  PubidLiteral_002    , /* PubidLiteral ::= _Lex037 _Gen082_any _Lex037  */
  PubidChar_001       , /* PubidChar ::= _Lex009  */
  PubidChar_002       , /* PubidChar ::= _Lex011  */
  PubidChar_003       , /* PubidChar ::= _Lex012  */
  PubidChar_004       , /* PubidChar ::= _Lex043  */
  PubidChar_005       , /* PubidChar ::= _Lex044  */
  _Lex045_any_001     , /* _Lex045_any ::= _Lex045 * */
  _Gen092_001         , /* _Gen092 ::= _Lex045_any _Lex046 _Lex045_any  */
  _Gen093_001         , /* _Gen093 ::= _Exclusion003  */
  CharData_001        , /* CharData ::= _Gen093  */
  _Gen095_001         , /* _Gen095 ::= _Exclusion004  */
  _Gen096_001         , /* _Gen096 ::= _Gen095  */
  _Gen097_001         , /* _Gen097 ::= _Exclusion004  */
  _Gen098_001         , /* _Gen098 ::= _Gen097  */
  _Gen099_001         , /* _Gen099 ::= _Lex029 _Gen098  */
  _Gen100_001         , /* _Gen100 ::= _Gen096  */
  _Gen100_002         , /* _Gen100 ::= _Gen099  */
  _Gen100_any_001     , /* _Gen100_any ::= _Gen100 * */
  Comment_001         , /* Comment ::= _Lex047 _Gen100_any _Lex048  */
  _Gen104_001         , /* _Gen104 ::= Char_any _Lex050 Char_any  */
  _Gen105_001         , /* _Gen105 ::= _Exclusion005  */
  _Gen106_001         , /* _Gen106 ::= _Gen105  */
  _Gen107_001         , /* _Gen107 ::= S _Gen106  */
  _Gen107_maybe_001   , /* _Gen107_maybe ::= _Gen107  */
  _Gen107_maybe_002   , /* _Gen107_maybe ::=   */
  PI_001              , /* PI ::= _Lex049 PITarget _Gen107_maybe _Lex050  */
  _Gen111_001         , /* _Gen111 ::= _Lex051  */
  _Gen111_002         , /* _Gen111 ::= _Lex052  */
  _Gen113_001         , /* _Gen113 ::= _Lex053  */
  _Gen113_002         , /* _Gen113 ::= _Lex054  */
  _Gen115_001         , /* _Gen115 ::= _Lex055  */
  _Gen115_002         , /* _Gen115 ::= _Lex056  */
  _Gen117_001         , /* _Gen117 ::= _Gen111 _Gen113 _Gen115  */
  _Gen118_001         , /* _Gen118 ::= _Exclusion006  */
  PITarget_001        , /* PITarget ::= _Gen118  */
  CDSect_001          , /* CDSect ::= CDStart CData CDEnd  */
  CDStart_001         , /* CDStart ::= _Lex057  */
  _Gen122_001         , /* _Gen122 ::= Char_any _Lex046 Char_any  */
  _Gen123_001         , /* _Gen123 ::= _Exclusion007  */
  _Gen124_001         , /* _Gen124 ::= _Gen123  */
  CData_001           , /* CData ::= _Gen124  */
  CDEnd_001           , /* CDEnd ::= _Lex046  */
  _Gen127_001         , /* _Gen127 ::= doctypedecl Misc_any  */
  _Gen127_maybe_001   , /* _Gen127_maybe ::= _Gen127  */
  _Gen127_maybe_002   , /* _Gen127_maybe ::=   */
  prolog_001          , /* prolog ::= XMLDecl Misc_any _Gen127_maybe  */
  EncodingDecl_maybe_001, /* EncodingDecl_maybe ::= EncodingDecl  */
  EncodingDecl_maybe_002, /* EncodingDecl_maybe ::=   */
  SDDecl_maybe_001    , /* SDDecl_maybe ::= SDDecl  */
  SDDecl_maybe_002    , /* SDDecl_maybe ::=   */
  S_maybe_001         , /* S_maybe ::= S  */
  S_maybe_002         , /* S_maybe ::=   */
  XMLDecl_001         , /* XMLDecl ::= _Lex058 VersionInfo EncodingDecl_maybe SDDecl_maybe S_maybe _Lex050  */
  _Gen138_001         , /* _Gen138 ::= _Lex037 VersionNum _Lex037  */
  _Gen138_002         , /* _Gen138 ::= _Lex035 VersionNum _Lex035  */
  VersionInfo_001     , /* VersionInfo ::= S _Lex059 Eq _Gen138  */
  Eq_001              , /* Eq ::= S_maybe _Lex060 S_maybe  */
  VersionNum_001      , /* VersionNum ::= _Lex061  */
  Misc_001            , /* Misc ::= Comment  */
  Misc_002            , /* Misc ::= PI  */
  Misc_003            , /* Misc ::= S  */
  _Gen146_001         , /* _Gen146 ::= S ExternalID  */
  _Gen146_maybe_001   , /* _Gen146_maybe ::= _Gen146  */
  _Gen146_maybe_002   , /* _Gen146_maybe ::=   */
  _Gen149_001         , /* _Gen149 ::= _Lex063 intSubset _Lex064 S_maybe  */
  _Gen149_maybe_001   , /* _Gen149_maybe ::= _Gen149  */
  _Gen149_maybe_002   , /* _Gen149_maybe ::=   */
  doctypedecl_001     , /* doctypedecl ::= _Lex062 S Name _Gen146_maybe S_maybe _Gen149_maybe _Lex065  */
  DeclSep_001         , /* DeclSep ::= PEReference  */
  DeclSep_002         , /* DeclSep ::= S  */
  _Gen155_001         , /* _Gen155 ::= markupdecl  */
  _Gen155_002         , /* _Gen155 ::= DeclSep  */
  _Gen155_any_001     , /* _Gen155_any ::= _Gen155 * */
  intSubset_001       , /* intSubset ::= _Gen155_any  */
  markupdecl_001      , /* markupdecl ::= elementdecl  */
  markupdecl_002      , /* markupdecl ::= AttlistDecl  */
  markupdecl_003      , /* markupdecl ::= EntityDecl  */
  markupdecl_004      , /* markupdecl ::= NotationDecl  */
  markupdecl_005      , /* markupdecl ::= PI  */
  markupdecl_006      , /* markupdecl ::= Comment  */
  TextDecl_maybe_001  , /* TextDecl_maybe ::= TextDecl  */
  TextDecl_maybe_002  , /* TextDecl_maybe ::=   */
  extSubset_001       , /* extSubset ::= TextDecl_maybe extSubsetDecl  */
  _Gen168_001         , /* _Gen168 ::= markupdecl  */
  _Gen168_002         , /* _Gen168 ::= conditionalSect  */
  _Gen168_003         , /* _Gen168 ::= DeclSep  */
  _Gen168_any_001     , /* _Gen168_any ::= _Gen168 * */
  extSubsetDecl_001   , /* extSubsetDecl ::= _Gen168_any  */
  _Gen173_001         , /* _Gen173 ::= _Lex067  */
  _Gen173_002         , /* _Gen173 ::= _Lex068  */
  _Gen175_001         , /* _Gen175 ::= _Lex037 _Gen173 _Lex037  */
  _Gen176_001         , /* _Gen176 ::= _Lex067  */
  _Gen176_002         , /* _Gen176 ::= _Lex068  */
  _Gen178_001         , /* _Gen178 ::= _Lex035 _Gen176 _Lex035  */
  _Gen179_001         , /* _Gen179 ::= _Gen175  */
  _Gen179_002         , /* _Gen179 ::= _Gen178  */
  SDDecl_001          , /* SDDecl ::= S _Lex066 Eq _Gen179  */
  element_001         , /* element ::= EmptyElemTag  */
  element_002         , /* element ::= STag content ETag  */
  _Gen184_001         , /* _Gen184 ::= S Attribute  */
  _Gen184_any_001     , /* _Gen184_any ::= _Gen184 * */
  STag_001            , /* STag ::= _Lex069 Name _Gen184_any S_maybe _Lex065  */
  Attribute_001       , /* Attribute ::= Name Eq AttValue  */
  ETag_001            , /* ETag ::= _Lex070 Name S_maybe _Lex065  */
  CharData_maybe_001  , /* CharData_maybe ::= CharData  */
  CharData_maybe_002  , /* CharData_maybe ::=   */
  _Gen191_001         , /* _Gen191 ::= element  */
  _Gen191_002         , /* _Gen191 ::= Reference  */
  _Gen191_003         , /* _Gen191 ::= CDSect  */
  _Gen191_004         , /* _Gen191 ::= PI  */
  _Gen191_005         , /* _Gen191 ::= Comment  */
  _Gen196_001         , /* _Gen196 ::= _Gen191 CharData_maybe  */
  _Gen196_any_001     , /* _Gen196_any ::= _Gen196 * */
  content_001         , /* content ::= CharData_maybe _Gen196_any  */
  _Gen199_001         , /* _Gen199 ::= S Attribute  */
  _Gen199_any_001     , /* _Gen199_any ::= _Gen199 * */
  EmptyElemTag_001    , /* EmptyElemTag ::= _Lex069 Name _Gen199_any S_maybe _Lex071  */
  elementdecl_001     , /* elementdecl ::= _Lex072 S Name S contentspec S_maybe _Lex065  */
  contentspec_001     , /* contentspec ::= _Lex073  */
  contentspec_002     , /* contentspec ::= _Lex074  */
  contentspec_003     , /* contentspec ::= Mixed  */
  contentspec_004     , /* contentspec ::= children  */
  _Gen207_001         , /* _Gen207 ::= choice  */
  _Gen207_002         , /* _Gen207 ::= seq  */
  _Gen209_001         , /* _Gen209 ::= _Lex075  */
  _Gen209_002         , /* _Gen209 ::= _Lex076  */
  _Gen209_003         , /* _Gen209 ::= _Lex077  */
  _Gen209_maybe_001   , /* _Gen209_maybe ::= _Gen209  */
  _Gen209_maybe_002   , /* _Gen209_maybe ::=   */
  children_001        , /* children ::= _Gen207 _Gen209_maybe  */
  _Gen215_001         , /* _Gen215 ::= Name  */
  _Gen215_002         , /* _Gen215 ::= choice  */
  _Gen215_003         , /* _Gen215 ::= seq  */
  _Gen218_001         , /* _Gen218 ::= _Lex075  */
  _Gen218_002         , /* _Gen218 ::= _Lex076  */
  _Gen218_003         , /* _Gen218 ::= _Lex077  */
  _Gen218_maybe_001   , /* _Gen218_maybe ::= _Gen218  */
  _Gen218_maybe_002   , /* _Gen218_maybe ::=   */
  cp_001              , /* cp ::= _Gen215 _Gen218_maybe  */
  _Gen224_001         , /* _Gen224 ::= S_maybe _Lex079 S_maybe cp  */
  _Gen224_many_001    , /* _Gen224_many ::= _Gen224 + */
  choice_001          , /* choice ::= _Lex078 S_maybe cp _Gen224_many S_maybe _Lex080  */
  _Gen227_001         , /* _Gen227 ::= S_maybe _Lex081 S_maybe cp  */
  _Gen227_any_001     , /* _Gen227_any ::= _Gen227 * */
  seq_001             , /* seq ::= _Lex078 S_maybe cp _Gen227_any S_maybe _Lex080  */
  _Gen230_001         , /* _Gen230 ::= S_maybe _Lex079 S_maybe Name  */
  _Gen230_any_001     , /* _Gen230_any ::= _Gen230 * */
  Mixed_001           , /* Mixed ::= _Lex078 S_maybe _Lex082 _Gen230_any S_maybe _Lex083  */
  Mixed_002           , /* Mixed ::= _Lex078 S_maybe _Lex082 S_maybe _Lex080  */
  AttDef_any_001      , /* AttDef_any ::= AttDef * */
  AttlistDecl_001     , /* AttlistDecl ::= _Lex084 S Name AttDef_any S_maybe _Lex065  */
  AttDef_001          , /* AttDef ::= S Name S AttType S DefaultDecl  */
  AttType_001         , /* AttType ::= StringType  */
  AttType_002         , /* AttType ::= TokenizedType  */
  AttType_003         , /* AttType ::= EnumeratedType  */
  StringType_001      , /* StringType ::= _Lex085  */
  TokenizedType_001   , /* TokenizedType ::= _Lex086  */
  TokenizedType_002   , /* TokenizedType ::= _Lex087  */
  TokenizedType_003   , /* TokenizedType ::= _Lex088  */
  TokenizedType_004   , /* TokenizedType ::= _Lex089  */
  TokenizedType_005   , /* TokenizedType ::= _Lex090  */
  TokenizedType_006   , /* TokenizedType ::= _Lex091  */
  TokenizedType_007   , /* TokenizedType ::= _Lex092  */
  EnumeratedType_001  , /* EnumeratedType ::= NotationType  */
  EnumeratedType_002  , /* EnumeratedType ::= Enumeration  */
  _Gen250_001         , /* _Gen250 ::= S_maybe _Lex079 S_maybe Name  */
  _Gen250_any_001     , /* _Gen250_any ::= _Gen250 * */
  NotationType_001    , /* NotationType ::= _Lex093 S _Lex078 S_maybe Name _Gen250_any S_maybe _Lex080  */
  _Gen253_001         , /* _Gen253 ::= S_maybe _Lex079 S_maybe Nmtoken  */
  _Gen253_any_001     , /* _Gen253_any ::= _Gen253 * */
  Enumeration_001     , /* Enumeration ::= _Lex078 S_maybe Nmtoken _Gen253_any S_maybe _Lex080  */
  _Gen256_001         , /* _Gen256 ::= _Lex096 S  */
  _Gen256_maybe_001   , /* _Gen256_maybe ::= _Gen256  */
  _Gen256_maybe_002   , /* _Gen256_maybe ::=   */
  _Gen259_001         , /* _Gen259 ::= _Gen256_maybe AttValue  */
  DefaultDecl_001     , /* DefaultDecl ::= _Lex094  */
  DefaultDecl_002     , /* DefaultDecl ::= _Lex095  */
  DefaultDecl_003     , /* DefaultDecl ::= _Gen259  */
  conditionalSect_001 , /* conditionalSect ::= includeSect  */
  conditionalSect_002 , /* conditionalSect ::= ignoreSect  */
  includeSect_001     , /* includeSect ::= _Lex097 S_maybe _Lex098 S_maybe _Lex063 extSubsetDecl _Lex046  */
  ignoreSectContents_any_001, /* ignoreSectContents_any ::= ignoreSectContents * */
  ignoreSect_001      , /* ignoreSect ::= _Lex097 S_maybe _Lex099 S_maybe _Lex063 ignoreSectContents_any _Lex046  */
  _Gen268_001         , /* _Gen268 ::= _Lex097 ignoreSectContents _Lex046 Ignore  */
  _Gen268_any_001     , /* _Gen268_any ::= _Gen268 * */
  ignoreSectContents_001, /* ignoreSectContents ::= Ignore _Gen268_any  */
  _Gen271_001         , /* _Gen271 ::= _Lex097  */
  _Gen271_002         , /* _Gen271 ::= _Lex046  */
  _Gen273_001         , /* _Gen273 ::= Char_any _Gen271 Char_any  */
  _Gen274_001         , /* _Gen274 ::= _Exclusion008  */
  Ignore_001          , /* Ignore ::= _Gen274  */
  _Lex031_many_001    , /* _Lex031_many ::= _Lex031 + */
  _Lex103_many_001    , /* _Lex103_many ::= _Lex103 + */
  CharRef_001         , /* CharRef ::= _Lex100 _Lex031_many _Lex101  */
  CharRef_002         , /* CharRef ::= _Lex102 _Lex103_many _Lex101  */
  Reference_001       , /* Reference ::= EntityRef  */
  Reference_002       , /* Reference ::= CharRef  */
  EntityRef_001       , /* EntityRef ::= _Lex104 Name _Lex101  */
  PEReference_001     , /* PEReference ::= _Lex105 Name _Lex101  */
  EntityDecl_001      , /* EntityDecl ::= GEDecl  */
  EntityDecl_002      , /* EntityDecl ::= PEDecl  */
  GEDecl_001          , /* GEDecl ::= _Lex106 S Name S EntityDef S_maybe _Lex065  */
  PEDecl_001          , /* PEDecl ::= _Lex106 S _Lex105 S Name S PEDef S_maybe _Lex065  */
  NDataDecl_maybe_001 , /* NDataDecl_maybe ::= NDataDecl  */
  NDataDecl_maybe_002 , /* NDataDecl_maybe ::=   */
  _Gen290_001         , /* _Gen290 ::= ExternalID NDataDecl_maybe  */
  EntityDef_001       , /* EntityDef ::= EntityValue  */
  EntityDef_002       , /* EntityDef ::= _Gen290  */
  PEDef_001           , /* PEDef ::= EntityValue  */
  PEDef_002           , /* PEDef ::= ExternalID  */
  ExternalID_001      , /* ExternalID ::= _Lex107 S SystemLiteral  */
  ExternalID_002      , /* ExternalID ::= _Lex108 S PubidLiteral S SystemLiteral  */
  NDataDecl_001       , /* NDataDecl ::= S _Lex109 S Name  */
  VersionInfo_maybe_001, /* VersionInfo_maybe ::= VersionInfo  */
  VersionInfo_maybe_002, /* VersionInfo_maybe ::=   */
  TextDecl_001        , /* TextDecl ::= _Lex058 VersionInfo_maybe EncodingDecl S_maybe _Lex050  */
  _Gen301_001         , /* _Gen301 ::= TextDecl_maybe content  */
  _Gen302_001         , /* _Gen302 ::= Char_any RestrictedChar Char_any  */
  _Gen303_001         , /* _Gen303 ::= _Exclusion009  */
  extParsedEnt_001    , /* extParsedEnt ::= _Gen303  */
  _Gen305_001         , /* _Gen305 ::= _Lex035 EncName _Lex035  */
  _Gen305_002         , /* _Gen305 ::= _Lex037 EncName _Lex037  */
  EncodingDecl_001    , /* EncodingDecl ::= S _Lex110 Eq _Gen305  */
  _Gen308_001         , /* _Gen308 ::= _Lex112  */
  _Gen308_002         , /* _Gen308 ::= _Lex029  */
  _Gen308_any_001     , /* _Gen308_any ::= _Gen308 * */
  EncName_001         , /* EncName ::= _Lex111 _Gen308_any  */
  _Gen312_001         , /* _Gen312 ::= ExternalID  */
  _Gen312_002         , /* _Gen312 ::= PublicID  */
  NotationDecl_001    , /* NotationDecl ::= _Lex113 S Name S _Gen312 S_maybe _Lex065  */
  PublicID_001        , /* PublicID ::= _Lex108 S PubidLiteral  */
  _RULE_MAX
} xml_1_1_rule_t;


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
  xml_1_1p->marpaWrapperSymbolArrayLengthi = 0;
  xml_1_1p->marpaWrapperRuleArrayp = NULL;
  xml_1_1p->marpaWrapperRuleArrayLengthi = 0;

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
      if (xml_1_1p->marpaWrapperRuleArrayp != NULL) {
	free(xml_1_1p->marpaWrapperRuleArrayp);
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
  return _xml_1_1_buildSymbols_withStartb(xml_1_1p, document);
}

/**************************/
/* _xml_1_1_buildSymbols_withStartb */
/**************************/
static marpaWrapperBool_t _xml_1_1_buildSymbols_withStartb(xml_1_1_t *xml_1_1p, int starti) {
  int                        i;
  marpaWrapperSymbolOption_t marpaWrapperSymbolOption;

  xml_1_1p->marpaWrapperSymbolArrayp = malloc(_SYMBOL_MAX * sizeof(marpaWrapperSymbol_t *));
  if (xml_1_1p->marpaWrapperSymbolArrayp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }
  xml_1_1p->marpaWrapperSymbolArrayLengthi = _SYMBOL_MAX;

  for (i = 0; i < _SYMBOL_MAX; i++) {

    /* Fill default options */
    if (marpaWrapper_symbolOptionDefaultb(&marpaWrapperSymbolOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }

    /* Opaque data associated to symbol will be the symbol enum */
    marpaWrapperSymbolOption.datavp = (void *) i;

    /* Optional, but we can make ourself the terminals */
    marpaWrapperSymbolOption.terminalb = (i <= XML_1_1_TERMINAL_MAX) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;

    /* Start rule ? */
    marpaWrapperSymbolOption.startb = (i == starti) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;

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

  xml_1_1p->marpaWrapperRuleArrayp = malloc(_RULE_MAX * sizeof(marpaWrapperRule_t *));
  if (xml_1_1p->marpaWrapperRuleArrayp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }
  xml_1_1p->marpaWrapperRuleArrayLengthi = _RULE_MAX;

  {
    /* [Misc_any_001] Misc_any ::= Misc * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Misc]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Misc_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Misc_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[Misc_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[Misc_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen002_001] _Gen002 ::= prolog element Misc_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[prolog],
      xml_1_1p->marpaWrapperSymbolArrayp[element],
      xml_1_1p->marpaWrapperSymbolArrayp[Misc_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen002_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen002];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen002_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen002_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Char_any_001] Char_any ::= Char * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Char]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Char_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Char_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[Char_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[Char_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen004_001] _Gen004 ::= Char_any RestrictedChar Char_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Char_any],
      xml_1_1p->marpaWrapperSymbolArrayp[RestrictedChar],
      xml_1_1p->marpaWrapperSymbolArrayp[Char_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen004_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen004];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen004_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen004_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen005_001] _Gen005 ::= _Exclusion001  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Exclusion001]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen005_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen005];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen005_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen005_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [document_001] document ::= _Gen005  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen005]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) document_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[document];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[document_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[document_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Char_001] Char ::= _Lex001  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex001]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Char_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Char];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[Char_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[Char_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Char_002] Char ::= _Lex002  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex002]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Char_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Char];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[Char_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[Char_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Char_003] Char ::= _Lex003  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex003]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Char_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Char];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[Char_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[Char_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [RestrictedChar_001] RestrictedChar ::= _Lex004  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex004]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) RestrictedChar_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[RestrictedChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[RestrictedChar_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[RestrictedChar_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [RestrictedChar_002] RestrictedChar ::= _Lex005  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex005]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) RestrictedChar_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[RestrictedChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[RestrictedChar_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[RestrictedChar_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [RestrictedChar_003] RestrictedChar ::= _Lex006  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex006]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) RestrictedChar_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[RestrictedChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[RestrictedChar_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[RestrictedChar_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [RestrictedChar_004] RestrictedChar ::= _Lex007  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex007]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) RestrictedChar_004;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[RestrictedChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[RestrictedChar_004] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[RestrictedChar_004] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [RestrictedChar_005] RestrictedChar ::= _Lex008  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex008]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) RestrictedChar_005;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[RestrictedChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[RestrictedChar_005] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[RestrictedChar_005] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen015_001] _Gen015 ::= _Lex009  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex009]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen015_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen015];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen015_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen015_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen015_002] _Gen015 ::= _Lex010  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex010]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen015_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen015];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen015_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen015_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen015_003] _Gen015 ::= _Lex011  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex011]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen015_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen015];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen015_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen015_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen015_004] _Gen015 ::= _Lex012  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex012]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen015_004;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen015];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen015_004] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen015_004] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen015_many_001] _Gen015_many ::= _Gen015 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen015]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen015_many_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen015_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen015_many_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen015_many_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [S_001] S ::= _Gen015_many  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen015_many]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) S_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[S];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[S_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[S_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameStartChar_001] NameStartChar ::= _Lex013  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex013]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameStartChar_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[NameStartChar_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[NameStartChar_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameStartChar_002] NameStartChar ::= _Lex014  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex014]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameStartChar_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[NameStartChar_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[NameStartChar_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameStartChar_003] NameStartChar ::= _Lex015  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex015]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameStartChar_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[NameStartChar_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[NameStartChar_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameStartChar_004] NameStartChar ::= _Lex016  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex016]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameStartChar_004;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[NameStartChar_004] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[NameStartChar_004] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameStartChar_005] NameStartChar ::= _Lex017  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex017]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameStartChar_005;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[NameStartChar_005] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[NameStartChar_005] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameStartChar_006] NameStartChar ::= _Lex018  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex018]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameStartChar_006;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[NameStartChar_006] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[NameStartChar_006] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameStartChar_007] NameStartChar ::= _Lex019  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex019]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameStartChar_007;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[NameStartChar_007] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[NameStartChar_007] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameStartChar_008] NameStartChar ::= _Lex020  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex020]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameStartChar_008;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[NameStartChar_008] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[NameStartChar_008] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameStartChar_009] NameStartChar ::= _Lex021  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex021]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameStartChar_009;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[NameStartChar_009] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[NameStartChar_009] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameStartChar_010] NameStartChar ::= _Lex022  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex022]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameStartChar_010;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[NameStartChar_010] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[NameStartChar_010] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameStartChar_011] NameStartChar ::= _Lex023  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex023]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameStartChar_011;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[NameStartChar_011] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[NameStartChar_011] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameStartChar_012] NameStartChar ::= _Lex024  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex024]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameStartChar_012;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[NameStartChar_012] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[NameStartChar_012] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameStartChar_013] NameStartChar ::= _Lex025  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex025]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameStartChar_013;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[NameStartChar_013] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[NameStartChar_013] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameStartChar_014] NameStartChar ::= _Lex026  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex026]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameStartChar_014;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[NameStartChar_014] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[NameStartChar_014] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameStartChar_015] NameStartChar ::= _Lex027  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex027]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameStartChar_015;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[NameStartChar_015] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[NameStartChar_015] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameStartChar_016] NameStartChar ::= _Lex028  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex028]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameStartChar_016;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[NameStartChar_016] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[NameStartChar_016] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameChar_001] NameChar ::= NameStartChar  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[NameStartChar]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameChar_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[NameChar_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[NameChar_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameChar_002] NameChar ::= _Lex029  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex029]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameChar_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[NameChar_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[NameChar_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameChar_003] NameChar ::= _Lex030  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex030]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameChar_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[NameChar_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[NameChar_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameChar_004] NameChar ::= _Lex031  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex031]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameChar_004;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[NameChar_004] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[NameChar_004] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameChar_005] NameChar ::= _Lex032  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex032]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameChar_005;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[NameChar_005] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[NameChar_005] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameChar_006] NameChar ::= _Lex033  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex033]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameChar_006;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[NameChar_006] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[NameChar_006] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameChar_007] NameChar ::= _Lex034  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex034]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameChar_007;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[NameChar_007] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[NameChar_007] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen044_001] _Gen044 ::= NameChar  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[NameChar]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen044_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen044];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen044_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen044_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen044_any_001] _Gen044_any ::= _Gen044 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen044]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen044_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen044_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen044_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen044_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Name_001] Name ::= NameStartChar _Gen044_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[NameStartChar],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen044_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Name_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Name];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[Name_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[Name_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen047_001] _Gen047 ::= _Lex009 Name  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex009],
      xml_1_1p->marpaWrapperSymbolArrayp[Name]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen047_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen047];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen047_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen047_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen047_any_001] _Gen047_any ::= _Gen047 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen047]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen047_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen047_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen047_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen047_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Names_001] Names ::= Name _Gen047_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Name],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen047_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Names_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Names];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[Names_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[Names_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen050_001] _Gen050 ::= NameChar  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[NameChar]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen050_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen050];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen050_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen050_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen050_many_001] _Gen050_many ::= _Gen050 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen050]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen050_many_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen050_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen050_many_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen050_many_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Nmtoken_001] Nmtoken ::= _Gen050_many  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen050_many]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Nmtoken_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Nmtoken];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[Nmtoken_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[Nmtoken_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen053_001] _Gen053 ::= _Lex009 Nmtoken  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex009],
      xml_1_1p->marpaWrapperSymbolArrayp[Nmtoken]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen053_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen053];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen053_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen053_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen053_any_001] _Gen053_any ::= _Gen053 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen053]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen053_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen053_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen053_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen053_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Nmtokens_001] Nmtokens ::= Nmtoken _Gen053_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Nmtoken],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen053_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Nmtokens_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Nmtokens];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[Nmtokens_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[Nmtokens_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen056_001] _Gen056 ::= _Lex036  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex036]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen056_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen056];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen056_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen056_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen056_002] _Gen056 ::= PEReference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[PEReference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen056_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen056];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen056_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen056_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen056_003] _Gen056 ::= Reference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Reference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen056_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen056];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen056_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen056_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen056_any_001] _Gen056_any ::= _Gen056 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen056]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen056_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen056_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen056_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen056_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen060_001] _Gen060 ::= _Lex038  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex038]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen060_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen060];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen060_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen060_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen060_002] _Gen060 ::= PEReference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[PEReference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen060_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen060];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen060_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen060_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen060_003] _Gen060 ::= Reference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Reference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen060_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen060];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen060_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen060_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen060_any_001] _Gen060_any ::= _Gen060 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen060]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen060_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen060_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen060_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen060_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [EntityValue_001] EntityValue ::= _Lex035 _Gen056_any _Lex035  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex035],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen056_any],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex035]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) EntityValue_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[EntityValue];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[EntityValue_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[EntityValue_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [EntityValue_002] EntityValue ::= _Lex037 _Gen060_any _Lex037  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex037],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen060_any],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex037]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) EntityValue_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[EntityValue];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[EntityValue_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[EntityValue_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen066_001] _Gen066 ::= _Lex039  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex039]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen066_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen066];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen066_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen066_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen066_002] _Gen066 ::= Reference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Reference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen066_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen066];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen066_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen066_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen066_any_001] _Gen066_any ::= _Gen066 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen066]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen066_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen066_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen066_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen066_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen069_001] _Gen069 ::= _Lex040  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex040]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen069_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen069];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen069_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen069_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen069_002] _Gen069 ::= Reference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Reference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen069_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen069];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen069_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen069_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen069_any_001] _Gen069_any ::= _Gen069 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen069]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen069_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen069_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen069_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen069_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [AttValue_001] AttValue ::= _Lex035 _Gen066_any _Lex035  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex035],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen066_any],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex035]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) AttValue_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[AttValue];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[AttValue_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[AttValue_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [AttValue_002] AttValue ::= _Lex037 _Gen069_any _Lex037  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex037],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen069_any],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex037]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) AttValue_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[AttValue];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[AttValue_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[AttValue_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Lex041_any_001] _Lex041_any ::= _Lex041 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex041]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Lex041_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Lex041_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Lex041_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Lex041_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen075_001] _Gen075 ::= _Lex035 _Lex041_any _Lex035  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex035],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex041_any],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex035]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen075_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen075];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen075_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen075_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Lex042_any_001] _Lex042_any ::= _Lex042 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex042]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Lex042_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Lex042_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Lex042_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Lex042_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen077_001] _Gen077 ::= _Lex037 _Lex042_any _Lex037  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex037],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex042_any],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex037]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen077_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen077];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen077_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen077_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [SystemLiteral_001] SystemLiteral ::= _Gen075  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen075]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) SystemLiteral_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[SystemLiteral];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[SystemLiteral_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[SystemLiteral_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [SystemLiteral_002] SystemLiteral ::= _Gen077  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen077]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) SystemLiteral_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[SystemLiteral];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[SystemLiteral_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[SystemLiteral_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [PubidChar_any_001] PubidChar_any ::= PubidChar * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[PubidChar]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) PubidChar_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[PubidChar_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[PubidChar_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[PubidChar_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen081_001] _Gen081 ::= _Exclusion002  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Exclusion002]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen081_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen081];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen081_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen081_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen082_001] _Gen082 ::= _Gen081  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen081]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen082_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen082];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen082_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen082_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen082_any_001] _Gen082_any ::= _Gen082 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen082]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen082_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen082_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen082_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen082_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [PubidLiteral_001] PubidLiteral ::= _Lex035 PubidChar_any _Lex035  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex035],
      xml_1_1p->marpaWrapperSymbolArrayp[PubidChar_any],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex035]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) PubidLiteral_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[PubidLiteral];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[PubidLiteral_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[PubidLiteral_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [PubidLiteral_002] PubidLiteral ::= _Lex037 _Gen082_any _Lex037  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex037],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen082_any],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex037]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) PubidLiteral_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[PubidLiteral];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[PubidLiteral_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[PubidLiteral_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [PubidChar_001] PubidChar ::= _Lex009  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex009]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) PubidChar_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[PubidChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[PubidChar_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[PubidChar_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [PubidChar_002] PubidChar ::= _Lex011  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex011]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) PubidChar_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[PubidChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[PubidChar_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[PubidChar_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [PubidChar_003] PubidChar ::= _Lex012  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex012]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) PubidChar_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[PubidChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[PubidChar_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[PubidChar_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [PubidChar_004] PubidChar ::= _Lex043  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex043]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) PubidChar_004;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[PubidChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[PubidChar_004] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[PubidChar_004] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [PubidChar_005] PubidChar ::= _Lex044  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex044]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) PubidChar_005;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[PubidChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[PubidChar_005] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[PubidChar_005] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Lex045_any_001] _Lex045_any ::= _Lex045 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex045]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Lex045_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Lex045_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Lex045_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Lex045_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen092_001] _Gen092 ::= _Lex045_any _Lex046 _Lex045_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex045_any],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex046],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex045_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen092_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen092];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen092_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen092_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen093_001] _Gen093 ::= _Exclusion003  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Exclusion003]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen093_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen093];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen093_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen093_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [CharData_001] CharData ::= _Gen093  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen093]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) CharData_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[CharData];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[CharData_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[CharData_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen095_001] _Gen095 ::= _Exclusion004  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Exclusion004]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen095_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen095];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen095_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen095_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen096_001] _Gen096 ::= _Gen095  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen095]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen096_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen096];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen096_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen096_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen097_001] _Gen097 ::= _Exclusion004  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Exclusion004]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen097_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen097];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen097_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen097_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen098_001] _Gen098 ::= _Gen097  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen097]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen098_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen098];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen098_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen098_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen099_001] _Gen099 ::= _Lex029 _Gen098  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex029],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen098]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen099_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen099];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen099_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen099_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen100_001] _Gen100 ::= _Gen096  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen096]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen100_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen100];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen100_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen100_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen100_002] _Gen100 ::= _Gen099  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen099]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen100_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen100];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen100_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen100_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen100_any_001] _Gen100_any ::= _Gen100 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen100]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen100_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen100_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen100_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen100_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Comment_001] Comment ::= _Lex047 _Gen100_any _Lex048  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex047],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen100_any],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex048]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Comment_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Comment];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[Comment_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[Comment_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen104_001] _Gen104 ::= Char_any _Lex050 Char_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Char_any],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex050],
      xml_1_1p->marpaWrapperSymbolArrayp[Char_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen104_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen104];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen104_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen104_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen105_001] _Gen105 ::= _Exclusion005  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Exclusion005]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen105_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen105];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen105_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen105_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen106_001] _Gen106 ::= _Gen105  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen105]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen106_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen106];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen106_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen106_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen107_001] _Gen107 ::= S _Gen106  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[S],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen106]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen107_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen107];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen107_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen107_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen107_maybe_001] _Gen107_maybe ::= _Gen107  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen107]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen107_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen107_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen107_maybe_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen107_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen107_maybe_002] _Gen107_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen107_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen107_maybe];
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen107_maybe_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen107_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [PI_001] PI ::= _Lex049 PITarget _Gen107_maybe _Lex050  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex049],
      xml_1_1p->marpaWrapperSymbolArrayp[PITarget],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen107_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex050]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) PI_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[PI];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[PI_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[PI_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen111_001] _Gen111 ::= _Lex051  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex051]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen111_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen111];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen111_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen111_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen111_002] _Gen111 ::= _Lex052  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex052]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen111_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen111];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen111_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen111_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen113_001] _Gen113 ::= _Lex053  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex053]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen113_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen113];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen113_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen113_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen113_002] _Gen113 ::= _Lex054  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex054]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen113_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen113];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen113_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen113_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen115_001] _Gen115 ::= _Lex055  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex055]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen115_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen115];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen115_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen115_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen115_002] _Gen115 ::= _Lex056  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex056]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen115_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen115];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen115_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen115_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen117_001] _Gen117 ::= _Gen111 _Gen113 _Gen115  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen111],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen113],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen115]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen117_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen117];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen117_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen117_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen118_001] _Gen118 ::= _Exclusion006  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Exclusion006]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen118_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen118];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen118_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen118_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [PITarget_001] PITarget ::= _Gen118  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen118]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) PITarget_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[PITarget];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[PITarget_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[PITarget_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [CDSect_001] CDSect ::= CDStart CData CDEnd  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[CDStart],
      xml_1_1p->marpaWrapperSymbolArrayp[CData],
      xml_1_1p->marpaWrapperSymbolArrayp[CDEnd]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) CDSect_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[CDSect];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[CDSect_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[CDSect_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [CDStart_001] CDStart ::= _Lex057  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex057]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) CDStart_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[CDStart];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[CDStart_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[CDStart_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen122_001] _Gen122 ::= Char_any _Lex046 Char_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Char_any],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex046],
      xml_1_1p->marpaWrapperSymbolArrayp[Char_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen122_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen122];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen122_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen122_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen123_001] _Gen123 ::= _Exclusion007  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Exclusion007]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen123_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen123];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen123_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen123_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen124_001] _Gen124 ::= _Gen123  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen123]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen124_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen124];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen124_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen124_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [CData_001] CData ::= _Gen124  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen124]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) CData_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[CData];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[CData_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[CData_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [CDEnd_001] CDEnd ::= _Lex046  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex046]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) CDEnd_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[CDEnd];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[CDEnd_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[CDEnd_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen127_001] _Gen127 ::= doctypedecl Misc_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[doctypedecl],
      xml_1_1p->marpaWrapperSymbolArrayp[Misc_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen127_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen127];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen127_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen127_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen127_maybe_001] _Gen127_maybe ::= _Gen127  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen127]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen127_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen127_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen127_maybe_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen127_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen127_maybe_002] _Gen127_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen127_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen127_maybe];
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen127_maybe_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen127_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [prolog_001] prolog ::= XMLDecl Misc_any _Gen127_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[XMLDecl],
      xml_1_1p->marpaWrapperSymbolArrayp[Misc_any],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen127_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) prolog_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[prolog];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[prolog_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[prolog_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [EncodingDecl_maybe_001] EncodingDecl_maybe ::= EncodingDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[EncodingDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) EncodingDecl_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[EncodingDecl_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[EncodingDecl_maybe_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[EncodingDecl_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [EncodingDecl_maybe_002] EncodingDecl_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) EncodingDecl_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[EncodingDecl_maybe];
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[EncodingDecl_maybe_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[EncodingDecl_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [SDDecl_maybe_001] SDDecl_maybe ::= SDDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[SDDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) SDDecl_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[SDDecl_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[SDDecl_maybe_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[SDDecl_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [SDDecl_maybe_002] SDDecl_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) SDDecl_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[SDDecl_maybe];
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[SDDecl_maybe_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[SDDecl_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [S_maybe_001] S_maybe ::= S  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[S]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) S_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[S_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[S_maybe_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[S_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [S_maybe_002] S_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) S_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[S_maybe];
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[S_maybe_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[S_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [XMLDecl_001] XMLDecl ::= _Lex058 VersionInfo EncodingDecl_maybe SDDecl_maybe S_maybe _Lex050  */
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
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) XMLDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[XMLDecl];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[XMLDecl_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[XMLDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen138_001] _Gen138 ::= _Lex037 VersionNum _Lex037  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex037],
      xml_1_1p->marpaWrapperSymbolArrayp[VersionNum],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex037]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen138_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen138];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen138_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen138_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen138_002] _Gen138 ::= _Lex035 VersionNum _Lex035  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex035],
      xml_1_1p->marpaWrapperSymbolArrayp[VersionNum],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex035]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen138_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen138];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen138_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen138_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [VersionInfo_001] VersionInfo ::= S _Lex059 Eq _Gen138  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[S],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex059],
      xml_1_1p->marpaWrapperSymbolArrayp[Eq],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen138]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) VersionInfo_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[VersionInfo];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[VersionInfo_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[VersionInfo_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Eq_001] Eq ::= S_maybe _Lex060 S_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex060],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Eq_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Eq];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[Eq_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[Eq_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [VersionNum_001] VersionNum ::= _Lex061  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex061]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) VersionNum_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[VersionNum];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[VersionNum_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[VersionNum_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Misc_001] Misc ::= Comment  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Comment]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Misc_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Misc];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[Misc_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[Misc_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Misc_002] Misc ::= PI  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[PI]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Misc_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Misc];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[Misc_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[Misc_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Misc_003] Misc ::= S  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[S]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Misc_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Misc];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[Misc_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[Misc_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen146_001] _Gen146 ::= S ExternalID  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[S],
      xml_1_1p->marpaWrapperSymbolArrayp[ExternalID]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen146_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen146];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen146_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen146_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen146_maybe_001] _Gen146_maybe ::= _Gen146  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen146]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen146_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen146_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen146_maybe_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen146_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen146_maybe_002] _Gen146_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen146_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen146_maybe];
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen146_maybe_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen146_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen149_001] _Gen149 ::= _Lex063 intSubset _Lex064 S_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex063],
      xml_1_1p->marpaWrapperSymbolArrayp[intSubset],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex064],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen149_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen149];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen149_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen149_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen149_maybe_001] _Gen149_maybe ::= _Gen149  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen149]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen149_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen149_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen149_maybe_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen149_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen149_maybe_002] _Gen149_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen149_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen149_maybe];
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen149_maybe_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen149_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [doctypedecl_001] doctypedecl ::= _Lex062 S Name _Gen146_maybe S_maybe _Gen149_maybe _Lex065  */
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
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) doctypedecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[doctypedecl];
    marpaWrapperRuleOption.nRhsSymboli = 7;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[doctypedecl_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[doctypedecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [DeclSep_001] DeclSep ::= PEReference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[PEReference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) DeclSep_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[DeclSep];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[DeclSep_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[DeclSep_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [DeclSep_002] DeclSep ::= S  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[S]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) DeclSep_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[DeclSep];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[DeclSep_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[DeclSep_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen155_001] _Gen155 ::= markupdecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[markupdecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen155_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen155];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen155_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen155_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen155_002] _Gen155 ::= DeclSep  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[DeclSep]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen155_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen155];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen155_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen155_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen155_any_001] _Gen155_any ::= _Gen155 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen155]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen155_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen155_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen155_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen155_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [intSubset_001] intSubset ::= _Gen155_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen155_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) intSubset_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[intSubset];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[intSubset_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[intSubset_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [markupdecl_001] markupdecl ::= elementdecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[elementdecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) markupdecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[markupdecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[markupdecl_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[markupdecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [markupdecl_002] markupdecl ::= AttlistDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[AttlistDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) markupdecl_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[markupdecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[markupdecl_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[markupdecl_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [markupdecl_003] markupdecl ::= EntityDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[EntityDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) markupdecl_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[markupdecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[markupdecl_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[markupdecl_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [markupdecl_004] markupdecl ::= NotationDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[NotationDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) markupdecl_004;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[markupdecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[markupdecl_004] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[markupdecl_004] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [markupdecl_005] markupdecl ::= PI  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[PI]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) markupdecl_005;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[markupdecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[markupdecl_005] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[markupdecl_005] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [markupdecl_006] markupdecl ::= Comment  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Comment]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) markupdecl_006;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[markupdecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[markupdecl_006] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[markupdecl_006] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [TextDecl_maybe_001] TextDecl_maybe ::= TextDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[TextDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) TextDecl_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[TextDecl_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[TextDecl_maybe_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[TextDecl_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [TextDecl_maybe_002] TextDecl_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) TextDecl_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[TextDecl_maybe];
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[TextDecl_maybe_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[TextDecl_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [extSubset_001] extSubset ::= TextDecl_maybe extSubsetDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[TextDecl_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[extSubsetDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) extSubset_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[extSubset];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[extSubset_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[extSubset_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen168_001] _Gen168 ::= markupdecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[markupdecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen168_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen168];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen168_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen168_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen168_002] _Gen168 ::= conditionalSect  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[conditionalSect]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen168_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen168];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen168_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen168_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen168_003] _Gen168 ::= DeclSep  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[DeclSep]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen168_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen168];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen168_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen168_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen168_any_001] _Gen168_any ::= _Gen168 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen168]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen168_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen168_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen168_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen168_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [extSubsetDecl_001] extSubsetDecl ::= _Gen168_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen168_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) extSubsetDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[extSubsetDecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[extSubsetDecl_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[extSubsetDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen173_001] _Gen173 ::= _Lex067  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex067]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen173_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen173];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen173_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen173_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen173_002] _Gen173 ::= _Lex068  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex068]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen173_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen173];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen173_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen173_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen175_001] _Gen175 ::= _Lex037 _Gen173 _Lex037  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex037],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen173],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex037]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen175_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen175];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen175_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen175_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen176_001] _Gen176 ::= _Lex067  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex067]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen176_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen176];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen176_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen176_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen176_002] _Gen176 ::= _Lex068  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex068]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen176_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen176];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen176_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen176_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen178_001] _Gen178 ::= _Lex035 _Gen176 _Lex035  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex035],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen176],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex035]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen178_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen178];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen178_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen178_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen179_001] _Gen179 ::= _Gen175  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen175]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen179_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen179];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen179_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen179_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen179_002] _Gen179 ::= _Gen178  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen178]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen179_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen179];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen179_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen179_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [SDDecl_001] SDDecl ::= S _Lex066 Eq _Gen179  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[S],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex066],
      xml_1_1p->marpaWrapperSymbolArrayp[Eq],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen179]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) SDDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[SDDecl];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[SDDecl_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[SDDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [element_001] element ::= EmptyElemTag  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[EmptyElemTag]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) element_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[element];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[element_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[element_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [element_002] element ::= STag content ETag  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[STag],
      xml_1_1p->marpaWrapperSymbolArrayp[content],
      xml_1_1p->marpaWrapperSymbolArrayp[ETag]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) element_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[element];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[element_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[element_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen184_001] _Gen184 ::= S Attribute  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[S],
      xml_1_1p->marpaWrapperSymbolArrayp[Attribute]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen184_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen184];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen184_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen184_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen184_any_001] _Gen184_any ::= _Gen184 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen184]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen184_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen184_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen184_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen184_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [STag_001] STag ::= _Lex069 Name _Gen184_any S_maybe _Lex065  */
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
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) STag_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[STag];
    marpaWrapperRuleOption.nRhsSymboli = 5;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[STag_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[STag_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Attribute_001] Attribute ::= Name Eq AttValue  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Name],
      xml_1_1p->marpaWrapperSymbolArrayp[Eq],
      xml_1_1p->marpaWrapperSymbolArrayp[AttValue]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Attribute_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Attribute];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[Attribute_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[Attribute_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [ETag_001] ETag ::= _Lex070 Name S_maybe _Lex065  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex070],
      xml_1_1p->marpaWrapperSymbolArrayp[Name],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex065]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) ETag_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[ETag];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[ETag_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[ETag_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [CharData_maybe_001] CharData_maybe ::= CharData  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[CharData]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) CharData_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[CharData_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[CharData_maybe_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[CharData_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [CharData_maybe_002] CharData_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) CharData_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[CharData_maybe];
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[CharData_maybe_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[CharData_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen191_001] _Gen191 ::= element  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[element]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen191_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen191];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen191_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen191_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen191_002] _Gen191 ::= Reference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Reference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen191_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen191];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen191_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen191_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen191_003] _Gen191 ::= CDSect  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[CDSect]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen191_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen191];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen191_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen191_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen191_004] _Gen191 ::= PI  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[PI]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen191_004;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen191];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen191_004] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen191_004] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen191_005] _Gen191 ::= Comment  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Comment]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen191_005;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen191];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen191_005] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen191_005] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen196_001] _Gen196 ::= _Gen191 CharData_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen191],
      xml_1_1p->marpaWrapperSymbolArrayp[CharData_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen196_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen196];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen196_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen196_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen196_any_001] _Gen196_any ::= _Gen196 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen196]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen196_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen196_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen196_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen196_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [content_001] content ::= CharData_maybe _Gen196_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[CharData_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen196_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) content_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[content];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[content_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[content_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen199_001] _Gen199 ::= S Attribute  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[S],
      xml_1_1p->marpaWrapperSymbolArrayp[Attribute]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen199_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen199];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen199_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen199_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen199_any_001] _Gen199_any ::= _Gen199 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen199]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen199_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen199_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen199_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen199_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [EmptyElemTag_001] EmptyElemTag ::= _Lex069 Name _Gen199_any S_maybe _Lex071  */
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
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) EmptyElemTag_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[EmptyElemTag];
    marpaWrapperRuleOption.nRhsSymboli = 5;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[EmptyElemTag_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[EmptyElemTag_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [elementdecl_001] elementdecl ::= _Lex072 S Name S contentspec S_maybe _Lex065  */
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
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) elementdecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[elementdecl];
    marpaWrapperRuleOption.nRhsSymboli = 7;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[elementdecl_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[elementdecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [contentspec_001] contentspec ::= _Lex073  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex073]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) contentspec_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[contentspec];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[contentspec_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[contentspec_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [contentspec_002] contentspec ::= _Lex074  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex074]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) contentspec_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[contentspec];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[contentspec_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[contentspec_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [contentspec_003] contentspec ::= Mixed  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Mixed]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) contentspec_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[contentspec];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[contentspec_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[contentspec_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [contentspec_004] contentspec ::= children  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[children]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) contentspec_004;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[contentspec];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[contentspec_004] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[contentspec_004] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen207_001] _Gen207 ::= choice  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[choice]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen207_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen207];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen207_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen207_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen207_002] _Gen207 ::= seq  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[seq]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen207_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen207];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen207_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen207_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen209_001] _Gen209 ::= _Lex075  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex075]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen209_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen209];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen209_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen209_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen209_002] _Gen209 ::= _Lex076  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex076]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen209_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen209];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen209_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen209_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen209_003] _Gen209 ::= _Lex077  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex077]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen209_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen209];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen209_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen209_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen209_maybe_001] _Gen209_maybe ::= _Gen209  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen209]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen209_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen209_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen209_maybe_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen209_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen209_maybe_002] _Gen209_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen209_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen209_maybe];
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen209_maybe_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen209_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [children_001] children ::= _Gen207 _Gen209_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen207],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen209_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) children_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[children];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[children_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[children_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen215_001] _Gen215 ::= Name  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Name]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen215_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen215];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen215_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen215_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen215_002] _Gen215 ::= choice  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[choice]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen215_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen215];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen215_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen215_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen215_003] _Gen215 ::= seq  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[seq]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen215_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen215];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen215_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen215_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen218_001] _Gen218 ::= _Lex075  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex075]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen218_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen218];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen218_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen218_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen218_002] _Gen218 ::= _Lex076  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex076]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen218_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen218];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen218_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen218_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen218_003] _Gen218 ::= _Lex077  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex077]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen218_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen218];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen218_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen218_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen218_maybe_001] _Gen218_maybe ::= _Gen218  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen218]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen218_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen218_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen218_maybe_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen218_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen218_maybe_002] _Gen218_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen218_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen218_maybe];
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen218_maybe_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen218_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [cp_001] cp ::= _Gen215 _Gen218_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen215],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen218_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) cp_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[cp];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[cp_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[cp_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen224_001] _Gen224 ::= S_maybe _Lex079 S_maybe cp  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex079],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[cp]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen224_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen224];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen224_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen224_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen224_many_001] _Gen224_many ::= _Gen224 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen224]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen224_many_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen224_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen224_many_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen224_many_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [choice_001] choice ::= _Lex078 S_maybe cp _Gen224_many S_maybe _Lex080  */
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
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) choice_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[choice];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[choice_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[choice_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen227_001] _Gen227 ::= S_maybe _Lex081 S_maybe cp  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex081],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[cp]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen227_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen227];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen227_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen227_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen227_any_001] _Gen227_any ::= _Gen227 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen227]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen227_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen227_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen227_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen227_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [seq_001] seq ::= _Lex078 S_maybe cp _Gen227_any S_maybe _Lex080  */
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
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) seq_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[seq];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[seq_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[seq_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen230_001] _Gen230 ::= S_maybe _Lex079 S_maybe Name  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex079],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[Name]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen230_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen230];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen230_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen230_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen230_any_001] _Gen230_any ::= _Gen230 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen230]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen230_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen230_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen230_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen230_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Mixed_001] Mixed ::= _Lex078 S_maybe _Lex082 _Gen230_any S_maybe _Lex083  */
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
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Mixed_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Mixed];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[Mixed_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[Mixed_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Mixed_002] Mixed ::= _Lex078 S_maybe _Lex082 S_maybe _Lex080  */
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
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Mixed_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Mixed];
    marpaWrapperRuleOption.nRhsSymboli = 5;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[Mixed_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[Mixed_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [AttDef_any_001] AttDef_any ::= AttDef * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[AttDef]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) AttDef_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[AttDef_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[AttDef_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[AttDef_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [AttlistDecl_001] AttlistDecl ::= _Lex084 S Name AttDef_any S_maybe _Lex065  */
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
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) AttlistDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[AttlistDecl];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[AttlistDecl_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[AttlistDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [AttDef_001] AttDef ::= S Name S AttType S DefaultDecl  */
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
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) AttDef_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[AttDef];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[AttDef_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[AttDef_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [AttType_001] AttType ::= StringType  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[StringType]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) AttType_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[AttType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[AttType_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[AttType_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [AttType_002] AttType ::= TokenizedType  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[TokenizedType]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) AttType_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[AttType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[AttType_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[AttType_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [AttType_003] AttType ::= EnumeratedType  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[EnumeratedType]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) AttType_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[AttType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[AttType_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[AttType_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [StringType_001] StringType ::= _Lex085  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex085]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) StringType_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[StringType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[StringType_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[StringType_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [TokenizedType_001] TokenizedType ::= _Lex086  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex086]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) TokenizedType_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[TokenizedType_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[TokenizedType_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [TokenizedType_002] TokenizedType ::= _Lex087  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex087]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) TokenizedType_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[TokenizedType_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[TokenizedType_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [TokenizedType_003] TokenizedType ::= _Lex088  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex088]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) TokenizedType_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[TokenizedType_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[TokenizedType_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [TokenizedType_004] TokenizedType ::= _Lex089  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex089]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) TokenizedType_004;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[TokenizedType_004] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[TokenizedType_004] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [TokenizedType_005] TokenizedType ::= _Lex090  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex090]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) TokenizedType_005;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[TokenizedType_005] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[TokenizedType_005] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [TokenizedType_006] TokenizedType ::= _Lex091  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex091]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) TokenizedType_006;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[TokenizedType_006] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[TokenizedType_006] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [TokenizedType_007] TokenizedType ::= _Lex092  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex092]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) TokenizedType_007;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[TokenizedType_007] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[TokenizedType_007] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [EnumeratedType_001] EnumeratedType ::= NotationType  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[NotationType]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) EnumeratedType_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[EnumeratedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[EnumeratedType_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[EnumeratedType_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [EnumeratedType_002] EnumeratedType ::= Enumeration  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Enumeration]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) EnumeratedType_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[EnumeratedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[EnumeratedType_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[EnumeratedType_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen250_001] _Gen250 ::= S_maybe _Lex079 S_maybe Name  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex079],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[Name]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen250_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen250];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen250_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen250_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen250_any_001] _Gen250_any ::= _Gen250 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen250]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen250_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen250_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen250_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen250_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NotationType_001] NotationType ::= _Lex093 S _Lex078 S_maybe Name _Gen250_any S_maybe _Lex080  */
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
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NotationType_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NotationType];
    marpaWrapperRuleOption.nRhsSymboli = 8;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[NotationType_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[NotationType_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen253_001] _Gen253 ::= S_maybe _Lex079 S_maybe Nmtoken  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex079],
      xml_1_1p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[Nmtoken]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen253_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen253];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen253_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen253_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen253_any_001] _Gen253_any ::= _Gen253 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen253]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen253_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen253_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen253_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen253_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Enumeration_001] Enumeration ::= _Lex078 S_maybe Nmtoken _Gen253_any S_maybe _Lex080  */
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
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Enumeration_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Enumeration];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[Enumeration_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[Enumeration_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen256_001] _Gen256 ::= _Lex096 S  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex096],
      xml_1_1p->marpaWrapperSymbolArrayp[S]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen256_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen256];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen256_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen256_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen256_maybe_001] _Gen256_maybe ::= _Gen256  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen256]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen256_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen256_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen256_maybe_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen256_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen256_maybe_002] _Gen256_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen256_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen256_maybe];
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen256_maybe_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen256_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen259_001] _Gen259 ::= _Gen256_maybe AttValue  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen256_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[AttValue]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen259_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen259];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen259_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen259_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [DefaultDecl_001] DefaultDecl ::= _Lex094  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex094]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) DefaultDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[DefaultDecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[DefaultDecl_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[DefaultDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [DefaultDecl_002] DefaultDecl ::= _Lex095  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex095]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) DefaultDecl_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[DefaultDecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[DefaultDecl_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[DefaultDecl_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [DefaultDecl_003] DefaultDecl ::= _Gen259  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen259]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) DefaultDecl_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[DefaultDecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[DefaultDecl_003] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[DefaultDecl_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [conditionalSect_001] conditionalSect ::= includeSect  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[includeSect]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) conditionalSect_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[conditionalSect];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[conditionalSect_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[conditionalSect_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [conditionalSect_002] conditionalSect ::= ignoreSect  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[ignoreSect]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) conditionalSect_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[conditionalSect];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[conditionalSect_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[conditionalSect_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [includeSect_001] includeSect ::= _Lex097 S_maybe _Lex098 S_maybe _Lex063 extSubsetDecl _Lex046  */
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
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) includeSect_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[includeSect];
    marpaWrapperRuleOption.nRhsSymboli = 7;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[includeSect_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[includeSect_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [ignoreSectContents_any_001] ignoreSectContents_any ::= ignoreSectContents * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[ignoreSectContents]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) ignoreSectContents_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[ignoreSectContents_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[ignoreSectContents_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[ignoreSectContents_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [ignoreSect_001] ignoreSect ::= _Lex097 S_maybe _Lex099 S_maybe _Lex063 ignoreSectContents_any _Lex046  */
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
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) ignoreSect_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[ignoreSect];
    marpaWrapperRuleOption.nRhsSymboli = 7;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[ignoreSect_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[ignoreSect_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen268_001] _Gen268 ::= _Lex097 ignoreSectContents _Lex046 Ignore  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex097],
      xml_1_1p->marpaWrapperSymbolArrayp[ignoreSectContents],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex046],
      xml_1_1p->marpaWrapperSymbolArrayp[Ignore]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen268_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen268];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen268_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen268_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen268_any_001] _Gen268_any ::= _Gen268 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen268]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen268_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen268_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen268_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen268_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [ignoreSectContents_001] ignoreSectContents ::= Ignore _Gen268_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Ignore],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen268_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) ignoreSectContents_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[ignoreSectContents];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[ignoreSectContents_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[ignoreSectContents_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen271_001] _Gen271 ::= _Lex097  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex097]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen271_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen271];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen271_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen271_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen271_002] _Gen271 ::= _Lex046  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex046]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen271_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen271];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen271_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen271_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen273_001] _Gen273 ::= Char_any _Gen271 Char_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Char_any],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen271],
      xml_1_1p->marpaWrapperSymbolArrayp[Char_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen273_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen273];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen273_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen273_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen274_001] _Gen274 ::= _Exclusion008  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Exclusion008]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen274_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen274];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen274_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen274_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Ignore_001] Ignore ::= _Gen274  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen274]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Ignore_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Ignore];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[Ignore_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[Ignore_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Lex031_many_001] _Lex031_many ::= _Lex031 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex031]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Lex031_many_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Lex031_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Lex031_many_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Lex031_many_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Lex103_many_001] _Lex103_many ::= _Lex103 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex103]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Lex103_many_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Lex103_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Lex103_many_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Lex103_many_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [CharRef_001] CharRef ::= _Lex100 _Lex031_many _Lex101  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex100],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex031_many],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex101]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) CharRef_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[CharRef];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[CharRef_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[CharRef_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [CharRef_002] CharRef ::= _Lex102 _Lex103_many _Lex101  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex102],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex103_many],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex101]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) CharRef_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[CharRef];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[CharRef_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[CharRef_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Reference_001] Reference ::= EntityRef  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[EntityRef]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Reference_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Reference];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[Reference_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[Reference_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Reference_002] Reference ::= CharRef  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[CharRef]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Reference_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[Reference];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[Reference_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[Reference_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [EntityRef_001] EntityRef ::= _Lex104 Name _Lex101  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex104],
      xml_1_1p->marpaWrapperSymbolArrayp[Name],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex101]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) EntityRef_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[EntityRef];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[EntityRef_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[EntityRef_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [PEReference_001] PEReference ::= _Lex105 Name _Lex101  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex105],
      xml_1_1p->marpaWrapperSymbolArrayp[Name],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex101]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) PEReference_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[PEReference];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[PEReference_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[PEReference_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [EntityDecl_001] EntityDecl ::= GEDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[GEDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) EntityDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[EntityDecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[EntityDecl_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[EntityDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [EntityDecl_002] EntityDecl ::= PEDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[PEDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) EntityDecl_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[EntityDecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[EntityDecl_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[EntityDecl_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [GEDecl_001] GEDecl ::= _Lex106 S Name S EntityDef S_maybe _Lex065  */
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
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) GEDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[GEDecl];
    marpaWrapperRuleOption.nRhsSymboli = 7;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[GEDecl_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[GEDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [PEDecl_001] PEDecl ::= _Lex106 S _Lex105 S Name S PEDef S_maybe _Lex065  */
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
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) PEDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[PEDecl];
    marpaWrapperRuleOption.nRhsSymboli = 9;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[PEDecl_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[PEDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NDataDecl_maybe_001] NDataDecl_maybe ::= NDataDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[NDataDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NDataDecl_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NDataDecl_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[NDataDecl_maybe_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[NDataDecl_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NDataDecl_maybe_002] NDataDecl_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NDataDecl_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NDataDecl_maybe];
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[NDataDecl_maybe_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[NDataDecl_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen290_001] _Gen290 ::= ExternalID NDataDecl_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[ExternalID],
      xml_1_1p->marpaWrapperSymbolArrayp[NDataDecl_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen290_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen290];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen290_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen290_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [EntityDef_001] EntityDef ::= EntityValue  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[EntityValue]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) EntityDef_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[EntityDef];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[EntityDef_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[EntityDef_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [EntityDef_002] EntityDef ::= _Gen290  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen290]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) EntityDef_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[EntityDef];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[EntityDef_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[EntityDef_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [PEDef_001] PEDef ::= EntityValue  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[EntityValue]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) PEDef_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[PEDef];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[PEDef_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[PEDef_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [PEDef_002] PEDef ::= ExternalID  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[ExternalID]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) PEDef_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[PEDef];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[PEDef_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[PEDef_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [ExternalID_001] ExternalID ::= _Lex107 S SystemLiteral  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex107],
      xml_1_1p->marpaWrapperSymbolArrayp[S],
      xml_1_1p->marpaWrapperSymbolArrayp[SystemLiteral]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) ExternalID_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[ExternalID];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[ExternalID_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[ExternalID_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [ExternalID_002] ExternalID ::= _Lex108 S PubidLiteral S SystemLiteral  */
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
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) ExternalID_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[ExternalID];
    marpaWrapperRuleOption.nRhsSymboli = 5;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[ExternalID_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[ExternalID_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NDataDecl_001] NDataDecl ::= S _Lex109 S Name  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[S],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex109],
      xml_1_1p->marpaWrapperSymbolArrayp[S],
      xml_1_1p->marpaWrapperSymbolArrayp[Name]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NDataDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NDataDecl];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[NDataDecl_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[NDataDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [VersionInfo_maybe_001] VersionInfo_maybe ::= VersionInfo  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[VersionInfo]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) VersionInfo_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[VersionInfo_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[VersionInfo_maybe_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[VersionInfo_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [VersionInfo_maybe_002] VersionInfo_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) VersionInfo_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[VersionInfo_maybe];
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[VersionInfo_maybe_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[VersionInfo_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [TextDecl_001] TextDecl ::= _Lex058 VersionInfo_maybe EncodingDecl S_maybe _Lex050  */
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
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) TextDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[TextDecl];
    marpaWrapperRuleOption.nRhsSymboli = 5;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[TextDecl_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[TextDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen301_001] _Gen301 ::= TextDecl_maybe content  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[TextDecl_maybe],
      xml_1_1p->marpaWrapperSymbolArrayp[content]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen301_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen301];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen301_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen301_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen302_001] _Gen302 ::= Char_any RestrictedChar Char_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[Char_any],
      xml_1_1p->marpaWrapperSymbolArrayp[RestrictedChar],
      xml_1_1p->marpaWrapperSymbolArrayp[Char_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen302_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen302];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen302_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen302_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen303_001] _Gen303 ::= _Exclusion009  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Exclusion009]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen303_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen303];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen303_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen303_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [extParsedEnt_001] extParsedEnt ::= _Gen303  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen303]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) extParsedEnt_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[extParsedEnt];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[extParsedEnt_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[extParsedEnt_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen305_001] _Gen305 ::= _Lex035 EncName _Lex035  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex035],
      xml_1_1p->marpaWrapperSymbolArrayp[EncName],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex035]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen305_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen305];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen305_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen305_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen305_002] _Gen305 ::= _Lex037 EncName _Lex037  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex037],
      xml_1_1p->marpaWrapperSymbolArrayp[EncName],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex037]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen305_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen305];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen305_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen305_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [EncodingDecl_001] EncodingDecl ::= S _Lex110 Eq _Gen305  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_1p->marpaWrapperSymbolArrayp[S],
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex110],
      xml_1_1p->marpaWrapperSymbolArrayp[Eq],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen305]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) EncodingDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[EncodingDecl];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[EncodingDecl_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[EncodingDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen308_001] _Gen308 ::= _Lex112  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex112]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen308_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen308];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen308_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen308_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen308_002] _Gen308 ::= _Lex029  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex029]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen308_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen308];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen308_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen308_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen308_any_001] _Gen308_any ::= _Gen308 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen308]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen308_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen308_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen308_any_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen308_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [EncName_001] EncName ::= _Lex111 _Gen308_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex111],
      xml_1_1p->marpaWrapperSymbolArrayp[_Gen308_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) EncName_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[EncName];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[EncName_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[EncName_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen312_001] _Gen312 ::= ExternalID  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[ExternalID]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen312_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen312];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen312_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen312_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen312_002] _Gen312 ::= PublicID  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_1p->marpaWrapperSymbolArrayp[PublicID]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen312_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[_Gen312];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[_Gen312_002] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[_Gen312_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NotationDecl_001] NotationDecl ::= _Lex113 S Name S _Gen312 S_maybe _Lex065  */
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
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NotationDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[NotationDecl];
    marpaWrapperRuleOption.nRhsSymboli = 7;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[NotationDecl_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[NotationDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [PublicID_001] PublicID ::= _Lex108 S PubidLiteral  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_1p->marpaWrapperSymbolArrayp[_Lex108],
      xml_1_1p->marpaWrapperSymbolArrayp[S],
      xml_1_1p->marpaWrapperSymbolArrayp[PubidLiteral]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) PublicID_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_1p->marpaWrapperSymbolArrayp[PublicID];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_1p->marpaWrapperRuleArrayp[PublicID_001] = marpaWrapper_g_addRulep(xml_1_1p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_1p->marpaWrapperRuleArrayp[PublicID_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
    return MARPAWRAPPER_BOOL_TRUE;
}
