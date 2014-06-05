#include <stdlib.h>
#include <errno.h>
#include "internal/grammar/xml_1_0.h"

static marpaWrapperBool_t _xml_1_0_buildGrammarb(xml_1_0_t *xml_1_0p, marpaWrapperOption_t *marpaWrapperOptionp);
static marpaWrapperBool_t _xml_1_0_buildSymbolsb(xml_1_0_t *xml_1_0p);
static marpaWrapperBool_t _xml_1_0_buildSymbols_withStartb(xml_1_0_t *xml_1_0p, int starti);
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

/* Rules */
typedef enum xml_1_0_rule {
  Misc_any_001 = 0    , /* Misc_any ::= Misc * */
  document_001        , /* document ::= prolog element Misc_any  */
  Char_001            , /* Char ::= _Lex001  */
  Char_002            , /* Char ::= _Lex002  */
  Char_003            , /* Char ::= _Lex003  */
  Char_004            , /* Char ::= _Lex004  */
  Char_005            , /* Char ::= _Lex005  */
  Char_006            , /* Char ::= _Lex006  */
  _Gen009_001         , /* _Gen009 ::= _Lex007  */
  _Gen009_002         , /* _Gen009 ::= _Lex001  */
  _Gen009_003         , /* _Gen009 ::= _Lex003  */
  _Gen009_004         , /* _Gen009 ::= _Lex002  */
  _Gen009_many_001    , /* _Gen009_many ::= _Gen009 + */
  S_001               , /* S ::= _Gen009_many  */
  NameStartChar_001   , /* NameStartChar ::= _Lex008  */
  NameStartChar_002   , /* NameStartChar ::= _Lex009  */
  NameStartChar_003   , /* NameStartChar ::= _Lex010  */
  NameStartChar_004   , /* NameStartChar ::= _Lex011  */
  NameStartChar_005   , /* NameStartChar ::= _Lex012  */
  NameStartChar_006   , /* NameStartChar ::= _Lex013  */
  NameStartChar_007   , /* NameStartChar ::= _Lex014  */
  NameStartChar_008   , /* NameStartChar ::= _Lex015  */
  NameStartChar_009   , /* NameStartChar ::= _Lex016  */
  NameStartChar_010   , /* NameStartChar ::= _Lex017  */
  NameStartChar_011   , /* NameStartChar ::= _Lex018  */
  NameStartChar_012   , /* NameStartChar ::= _Lex019  */
  NameStartChar_013   , /* NameStartChar ::= _Lex020  */
  NameStartChar_014   , /* NameStartChar ::= _Lex021  */
  NameStartChar_015   , /* NameStartChar ::= _Lex022  */
  NameStartChar_016   , /* NameStartChar ::= _Lex023  */
  NameChar_001        , /* NameChar ::= NameStartChar  */
  NameChar_002        , /* NameChar ::= _Lex024  */
  NameChar_003        , /* NameChar ::= _Lex025  */
  NameChar_004        , /* NameChar ::= _Lex026  */
  NameChar_005        , /* NameChar ::= _Lex027  */
  NameChar_006        , /* NameChar ::= _Lex028  */
  NameChar_007        , /* NameChar ::= _Lex029  */
  _Gen038_001         , /* _Gen038 ::= NameChar  */
  _Gen038_any_001     , /* _Gen038_any ::= _Gen038 * */
  Name_001            , /* Name ::= NameStartChar _Gen038_any  */
  _Gen041_001         , /* _Gen041 ::= _Lex007 Name  */
  _Gen041_any_001     , /* _Gen041_any ::= _Gen041 * */
  Names_001           , /* Names ::= Name _Gen041_any  */
  _Gen044_001         , /* _Gen044 ::= NameChar  */
  _Gen044_many_001    , /* _Gen044_many ::= _Gen044 + */
  Nmtoken_001         , /* Nmtoken ::= _Gen044_many  */
  _Gen047_001         , /* _Gen047 ::= _Lex007 Nmtoken  */
  _Gen047_any_001     , /* _Gen047_any ::= _Gen047 * */
  Nmtokens_001        , /* Nmtokens ::= Nmtoken _Gen047_any  */
  _Gen050_001         , /* _Gen050 ::= _Lex031  */
  _Gen050_002         , /* _Gen050 ::= PEReference  */
  _Gen050_003         , /* _Gen050 ::= Reference  */
  _Gen050_any_001     , /* _Gen050_any ::= _Gen050 * */
  _Gen054_001         , /* _Gen054 ::= _Lex033  */
  _Gen054_002         , /* _Gen054 ::= PEReference  */
  _Gen054_003         , /* _Gen054 ::= Reference  */
  _Gen054_any_001     , /* _Gen054_any ::= _Gen054 * */
  EntityValue_001     , /* EntityValue ::= _Lex030 _Gen050_any _Lex030  */
  EntityValue_002     , /* EntityValue ::= _Lex032 _Gen054_any _Lex032  */
  _Gen060_001         , /* _Gen060 ::= _Lex034  */
  _Gen060_002         , /* _Gen060 ::= Reference  */
  _Gen060_any_001     , /* _Gen060_any ::= _Gen060 * */
  _Gen063_001         , /* _Gen063 ::= _Lex035  */
  _Gen063_002         , /* _Gen063 ::= Reference  */
  _Gen063_any_001     , /* _Gen063_any ::= _Gen063 * */
  AttValue_001        , /* AttValue ::= _Lex030 _Gen060_any _Lex030  */
  AttValue_002        , /* AttValue ::= _Lex032 _Gen063_any _Lex032  */
  _Lex036_any_001     , /* _Lex036_any ::= _Lex036 * */
  _Gen069_001         , /* _Gen069 ::= _Lex030 _Lex036_any _Lex030  */
  _Lex037_any_001     , /* _Lex037_any ::= _Lex037 * */
  _Gen071_001         , /* _Gen071 ::= _Lex032 _Lex037_any _Lex032  */
  SystemLiteral_001   , /* SystemLiteral ::= _Gen069  */
  SystemLiteral_002   , /* SystemLiteral ::= _Gen071  */
  PubidChar_any_001   , /* PubidChar_any ::= PubidChar * */
  _Gen075_001         , /* _Gen075 ::= _Exclusion001  */
  _Gen076_001         , /* _Gen076 ::= _Gen075  */
  _Gen076_any_001     , /* _Gen076_any ::= _Gen076 * */
  PubidLiteral_001    , /* PubidLiteral ::= _Lex030 PubidChar_any _Lex030  */
  PubidLiteral_002    , /* PubidLiteral ::= _Lex032 _Gen076_any _Lex032  */
  PubidChar_001       , /* PubidChar ::= _Lex007  */
  PubidChar_002       , /* PubidChar ::= _Lex003  */
  PubidChar_003       , /* PubidChar ::= _Lex002  */
  PubidChar_004       , /* PubidChar ::= _Lex038  */
  PubidChar_005       , /* PubidChar ::= _Lex039  */
  _Lex040_any_001     , /* _Lex040_any ::= _Lex040 * */
  _Gen086_001         , /* _Gen086 ::= _Lex040_any _Lex041 _Lex040_any  */
  _Gen087_001         , /* _Gen087 ::= _Exclusion002  */
  CharData_001        , /* CharData ::= _Gen087  */
  _Gen089_001         , /* _Gen089 ::= _Exclusion003  */
  _Gen090_001         , /* _Gen090 ::= _Gen089  */
  _Gen091_001         , /* _Gen091 ::= _Exclusion003  */
  _Gen092_001         , /* _Gen092 ::= _Gen091  */
  _Gen093_001         , /* _Gen093 ::= _Lex024 _Gen092  */
  _Gen094_001         , /* _Gen094 ::= _Gen090  */
  _Gen094_002         , /* _Gen094 ::= _Gen093  */
  _Gen094_any_001     , /* _Gen094_any ::= _Gen094 * */
  Comment_001         , /* Comment ::= _Lex042 _Gen094_any _Lex043  */
  Char_any_001        , /* Char_any ::= Char * */
  _Gen099_001         , /* _Gen099 ::= Char_any _Lex045 Char_any  */
  _Gen100_001         , /* _Gen100 ::= _Exclusion004  */
  _Gen101_001         , /* _Gen101 ::= _Gen100  */
  _Gen102_001         , /* _Gen102 ::= S _Gen101  */
  _Gen102_maybe_001   , /* _Gen102_maybe ::= _Gen102  */
  _Gen102_maybe_002   , /* _Gen102_maybe ::=   */
  PI_001              , /* PI ::= _Lex044 PITarget _Gen102_maybe _Lex045  */
  _Gen106_001         , /* _Gen106 ::= _Lex046  */
  _Gen106_002         , /* _Gen106 ::= _Lex047  */
  _Gen108_001         , /* _Gen108 ::= _Lex048  */
  _Gen108_002         , /* _Gen108 ::= _Lex049  */
  _Gen110_001         , /* _Gen110 ::= _Lex050  */
  _Gen110_002         , /* _Gen110 ::= _Lex051  */
  _Gen112_001         , /* _Gen112 ::= _Gen106 _Gen108 _Gen110  */
  _Gen113_001         , /* _Gen113 ::= _Exclusion005  */
  PITarget_001        , /* PITarget ::= _Gen113  */
  CDSect_001          , /* CDSect ::= CDStart CData CDEnd  */
  CDStart_001         , /* CDStart ::= _Lex052  */
  _Gen117_001         , /* _Gen117 ::= Char_any _Lex041 Char_any  */
  _Gen118_001         , /* _Gen118 ::= _Exclusion006  */
  _Gen119_001         , /* _Gen119 ::= _Gen118  */
  CData_001           , /* CData ::= _Gen119  */
  CDEnd_001           , /* CDEnd ::= _Lex041  */
  XMLDecl_maybe_001   , /* XMLDecl_maybe ::= XMLDecl  */
  XMLDecl_maybe_002   , /* XMLDecl_maybe ::=   */
  _Gen124_001         , /* _Gen124 ::= doctypedecl Misc_any  */
  _Gen124_maybe_001   , /* _Gen124_maybe ::= _Gen124  */
  _Gen124_maybe_002   , /* _Gen124_maybe ::=   */
  prolog_001          , /* prolog ::= XMLDecl_maybe Misc_any _Gen124_maybe  */
  EncodingDecl_maybe_001, /* EncodingDecl_maybe ::= EncodingDecl  */
  EncodingDecl_maybe_002, /* EncodingDecl_maybe ::=   */
  SDDecl_maybe_001    , /* SDDecl_maybe ::= SDDecl  */
  SDDecl_maybe_002    , /* SDDecl_maybe ::=   */
  S_maybe_001         , /* S_maybe ::= S  */
  S_maybe_002         , /* S_maybe ::=   */
  XMLDecl_001         , /* XMLDecl ::= _Lex053 VersionInfo EncodingDecl_maybe SDDecl_maybe S_maybe _Lex045  */
  _Gen135_001         , /* _Gen135 ::= _Lex032 VersionNum _Lex032  */
  _Gen135_002         , /* _Gen135 ::= _Lex030 VersionNum _Lex030  */
  VersionInfo_001     , /* VersionInfo ::= S _Lex054 Eq _Gen135  */
  Eq_001              , /* Eq ::= S_maybe _Lex055 S_maybe  */
  _Lex026_many_001    , /* _Lex026_many ::= _Lex026 + */
  VersionNum_001      , /* VersionNum ::= _Lex056 _Lex026_many  */
  Misc_001            , /* Misc ::= Comment  */
  Misc_002            , /* Misc ::= PI  */
  Misc_003            , /* Misc ::= S  */
  _Gen144_001         , /* _Gen144 ::= S ExternalID  */
  _Gen144_maybe_001   , /* _Gen144_maybe ::= _Gen144  */
  _Gen144_maybe_002   , /* _Gen144_maybe ::=   */
  _Gen147_001         , /* _Gen147 ::= _Lex058 intSubset _Lex059 S_maybe  */
  _Gen147_maybe_001   , /* _Gen147_maybe ::= _Gen147  */
  _Gen147_maybe_002   , /* _Gen147_maybe ::=   */
  doctypedecl_001     , /* doctypedecl ::= _Lex057 S Name _Gen144_maybe S_maybe _Gen147_maybe _Lex060  */
  DeclSep_001         , /* DeclSep ::= PEReference  */
  DeclSep_002         , /* DeclSep ::= S  */
  _Gen153_001         , /* _Gen153 ::= markupdecl  */
  _Gen153_002         , /* _Gen153 ::= DeclSep  */
  _Gen153_any_001     , /* _Gen153_any ::= _Gen153 * */
  intSubset_001       , /* intSubset ::= _Gen153_any  */
  markupdecl_001      , /* markupdecl ::= elementdecl  */
  markupdecl_002      , /* markupdecl ::= AttlistDecl  */
  markupdecl_003      , /* markupdecl ::= EntityDecl  */
  markupdecl_004      , /* markupdecl ::= NotationDecl  */
  markupdecl_005      , /* markupdecl ::= PI  */
  markupdecl_006      , /* markupdecl ::= Comment  */
  TextDecl_maybe_001  , /* TextDecl_maybe ::= TextDecl  */
  TextDecl_maybe_002  , /* TextDecl_maybe ::=   */
  extSubset_001       , /* extSubset ::= TextDecl_maybe extSubsetDecl  */
  _Gen166_001         , /* _Gen166 ::= markupdecl  */
  _Gen166_002         , /* _Gen166 ::= conditionalSect  */
  _Gen166_003         , /* _Gen166 ::= DeclSep  */
  _Gen166_any_001     , /* _Gen166_any ::= _Gen166 * */
  extSubsetDecl_001   , /* extSubsetDecl ::= _Gen166_any  */
  _Gen171_001         , /* _Gen171 ::= _Lex062  */
  _Gen171_002         , /* _Gen171 ::= _Lex063  */
  _Gen173_001         , /* _Gen173 ::= _Lex032 _Gen171 _Lex032  */
  _Gen174_001         , /* _Gen174 ::= _Lex062  */
  _Gen174_002         , /* _Gen174 ::= _Lex063  */
  _Gen176_001         , /* _Gen176 ::= _Lex030 _Gen174 _Lex030  */
  _Gen177_001         , /* _Gen177 ::= _Gen173  */
  _Gen177_002         , /* _Gen177 ::= _Gen176  */
  SDDecl_001          , /* SDDecl ::= S _Lex061 Eq _Gen177  */
  element_001         , /* element ::= EmptyElemTag  */
  element_002         , /* element ::= STag content ETag  */
  _Gen182_001         , /* _Gen182 ::= S Attribute  */
  _Gen182_any_001     , /* _Gen182_any ::= _Gen182 * */
  STag_001            , /* STag ::= _Lex064 Name _Gen182_any S_maybe _Lex060  */
  Attribute_001       , /* Attribute ::= Name Eq AttValue  */
  ETag_001            , /* ETag ::= _Lex065 Name S_maybe _Lex060  */
  CharData_maybe_001  , /* CharData_maybe ::= CharData  */
  CharData_maybe_002  , /* CharData_maybe ::=   */
  _Gen189_001         , /* _Gen189 ::= element  */
  _Gen189_002         , /* _Gen189 ::= Reference  */
  _Gen189_003         , /* _Gen189 ::= CDSect  */
  _Gen189_004         , /* _Gen189 ::= PI  */
  _Gen189_005         , /* _Gen189 ::= Comment  */
  _Gen194_001         , /* _Gen194 ::= _Gen189 CharData_maybe  */
  _Gen194_any_001     , /* _Gen194_any ::= _Gen194 * */
  content_001         , /* content ::= CharData_maybe _Gen194_any  */
  _Gen197_001         , /* _Gen197 ::= S Attribute  */
  _Gen197_any_001     , /* _Gen197_any ::= _Gen197 * */
  EmptyElemTag_001    , /* EmptyElemTag ::= _Lex064 Name _Gen197_any S_maybe _Lex066  */
  elementdecl_001     , /* elementdecl ::= _Lex067 S Name S contentspec S_maybe _Lex060  */
  contentspec_001     , /* contentspec ::= _Lex068  */
  contentspec_002     , /* contentspec ::= _Lex069  */
  contentspec_003     , /* contentspec ::= Mixed  */
  contentspec_004     , /* contentspec ::= children  */
  _Gen205_001         , /* _Gen205 ::= choice  */
  _Gen205_002         , /* _Gen205 ::= seq  */
  _Gen207_001         , /* _Gen207 ::= _Lex070  */
  _Gen207_002         , /* _Gen207 ::= _Lex071  */
  _Gen207_003         , /* _Gen207 ::= _Lex072  */
  _Gen207_maybe_001   , /* _Gen207_maybe ::= _Gen207  */
  _Gen207_maybe_002   , /* _Gen207_maybe ::=   */
  children_001        , /* children ::= _Gen205 _Gen207_maybe  */
  _Gen213_001         , /* _Gen213 ::= Name  */
  _Gen213_002         , /* _Gen213 ::= choice  */
  _Gen213_003         , /* _Gen213 ::= seq  */
  _Gen216_001         , /* _Gen216 ::= _Lex070  */
  _Gen216_002         , /* _Gen216 ::= _Lex071  */
  _Gen216_003         , /* _Gen216 ::= _Lex072  */
  _Gen216_maybe_001   , /* _Gen216_maybe ::= _Gen216  */
  _Gen216_maybe_002   , /* _Gen216_maybe ::=   */
  cp_001              , /* cp ::= _Gen213 _Gen216_maybe  */
  _Gen222_001         , /* _Gen222 ::= S_maybe _Lex074 S_maybe cp  */
  _Gen222_many_001    , /* _Gen222_many ::= _Gen222 + */
  choice_001          , /* choice ::= _Lex073 S_maybe cp _Gen222_many S_maybe _Lex075  */
  _Gen225_001         , /* _Gen225 ::= S_maybe _Lex076 S_maybe cp  */
  _Gen225_any_001     , /* _Gen225_any ::= _Gen225 * */
  seq_001             , /* seq ::= _Lex073 S_maybe cp _Gen225_any S_maybe _Lex075  */
  _Gen228_001         , /* _Gen228 ::= S_maybe _Lex074 S_maybe Name  */
  _Gen228_any_001     , /* _Gen228_any ::= _Gen228 * */
  Mixed_001           , /* Mixed ::= _Lex073 S_maybe _Lex077 _Gen228_any S_maybe _Lex078  */
  Mixed_002           , /* Mixed ::= _Lex073 S_maybe _Lex077 S_maybe _Lex075  */
  AttDef_any_001      , /* AttDef_any ::= AttDef * */
  AttlistDecl_001     , /* AttlistDecl ::= _Lex079 S Name AttDef_any S_maybe _Lex060  */
  AttDef_001          , /* AttDef ::= S Name S AttType S DefaultDecl  */
  AttType_001         , /* AttType ::= StringType  */
  AttType_002         , /* AttType ::= TokenizedType  */
  AttType_003         , /* AttType ::= EnumeratedType  */
  StringType_001      , /* StringType ::= _Lex080  */
  TokenizedType_001   , /* TokenizedType ::= _Lex081  */
  TokenizedType_002   , /* TokenizedType ::= _Lex082  */
  TokenizedType_003   , /* TokenizedType ::= _Lex083  */
  TokenizedType_004   , /* TokenizedType ::= _Lex084  */
  TokenizedType_005   , /* TokenizedType ::= _Lex085  */
  TokenizedType_006   , /* TokenizedType ::= _Lex086  */
  TokenizedType_007   , /* TokenizedType ::= _Lex087  */
  EnumeratedType_001  , /* EnumeratedType ::= NotationType  */
  EnumeratedType_002  , /* EnumeratedType ::= Enumeration  */
  _Gen248_001         , /* _Gen248 ::= S_maybe _Lex074 S_maybe Name  */
  _Gen248_any_001     , /* _Gen248_any ::= _Gen248 * */
  NotationType_001    , /* NotationType ::= _Lex088 S _Lex073 S_maybe Name _Gen248_any S_maybe _Lex075  */
  _Gen251_001         , /* _Gen251 ::= S_maybe _Lex074 S_maybe Nmtoken  */
  _Gen251_any_001     , /* _Gen251_any ::= _Gen251 * */
  Enumeration_001     , /* Enumeration ::= _Lex073 S_maybe Nmtoken _Gen251_any S_maybe _Lex075  */
  _Gen254_001         , /* _Gen254 ::= _Lex091 S  */
  _Gen254_maybe_001   , /* _Gen254_maybe ::= _Gen254  */
  _Gen254_maybe_002   , /* _Gen254_maybe ::=   */
  _Gen257_001         , /* _Gen257 ::= _Gen254_maybe AttValue  */
  DefaultDecl_001     , /* DefaultDecl ::= _Lex089  */
  DefaultDecl_002     , /* DefaultDecl ::= _Lex090  */
  DefaultDecl_003     , /* DefaultDecl ::= _Gen257  */
  conditionalSect_001 , /* conditionalSect ::= includeSect  */
  conditionalSect_002 , /* conditionalSect ::= ignoreSect  */
  includeSect_001     , /* includeSect ::= _Lex092 S_maybe _Lex093 S_maybe _Lex058 extSubsetDecl _Lex041  */
  ignoreSectContents_any_001, /* ignoreSectContents_any ::= ignoreSectContents * */
  ignoreSect_001      , /* ignoreSect ::= _Lex092 S_maybe _Lex094 S_maybe _Lex058 ignoreSectContents_any _Lex041  */
  _Gen266_001         , /* _Gen266 ::= _Lex092 ignoreSectContents _Lex041 Ignore  */
  _Gen266_any_001     , /* _Gen266_any ::= _Gen266 * */
  ignoreSectContents_001, /* ignoreSectContents ::= Ignore _Gen266_any  */
  _Gen269_001         , /* _Gen269 ::= _Lex092  */
  _Gen269_002         , /* _Gen269 ::= _Lex041  */
  _Gen271_001         , /* _Gen271 ::= Char_any _Gen269 Char_any  */
  _Gen272_001         , /* _Gen272 ::= _Exclusion007  */
  Ignore_001          , /* Ignore ::= _Gen272  */
  _Lex098_many_001    , /* _Lex098_many ::= _Lex098 + */
  CharRef_001         , /* CharRef ::= _Lex095 _Lex026_many _Lex096  */
  CharRef_002         , /* CharRef ::= _Lex097 _Lex098_many _Lex096  */
  Reference_001       , /* Reference ::= EntityRef  */
  Reference_002       , /* Reference ::= CharRef  */
  EntityRef_001       , /* EntityRef ::= _Lex099 Name _Lex096  */
  PEReference_001     , /* PEReference ::= _Lex100 Name _Lex096  */
  EntityDecl_001      , /* EntityDecl ::= GEDecl  */
  EntityDecl_002      , /* EntityDecl ::= PEDecl  */
  GEDecl_001          , /* GEDecl ::= _Lex101 S Name S EntityDef S_maybe _Lex060  */
  PEDecl_001          , /* PEDecl ::= _Lex101 S _Lex100 S Name S PEDef S_maybe _Lex060  */
  NDataDecl_maybe_001 , /* NDataDecl_maybe ::= NDataDecl  */
  NDataDecl_maybe_002 , /* NDataDecl_maybe ::=   */
  _Gen287_001         , /* _Gen287 ::= ExternalID NDataDecl_maybe  */
  EntityDef_001       , /* EntityDef ::= EntityValue  */
  EntityDef_002       , /* EntityDef ::= _Gen287  */
  PEDef_001           , /* PEDef ::= EntityValue  */
  PEDef_002           , /* PEDef ::= ExternalID  */
  ExternalID_001      , /* ExternalID ::= _Lex102 S SystemLiteral  */
  ExternalID_002      , /* ExternalID ::= _Lex103 S PubidLiteral S SystemLiteral  */
  NDataDecl_001       , /* NDataDecl ::= S _Lex104 S Name  */
  VersionInfo_maybe_001, /* VersionInfo_maybe ::= VersionInfo  */
  VersionInfo_maybe_002, /* VersionInfo_maybe ::=   */
  TextDecl_001        , /* TextDecl ::= _Lex053 VersionInfo_maybe EncodingDecl S_maybe _Lex045  */
  extParsedEnt_001    , /* extParsedEnt ::= TextDecl_maybe content  */
  _Gen299_001         , /* _Gen299 ::= _Lex030 EncName _Lex030  */
  _Gen299_002         , /* _Gen299 ::= _Lex032 EncName _Lex032  */
  EncodingDecl_001    , /* EncodingDecl ::= S _Lex105 Eq _Gen299  */
  _Gen302_001         , /* _Gen302 ::= _Lex107  */
  _Gen302_002         , /* _Gen302 ::= _Lex024  */
  _Gen302_any_001     , /* _Gen302_any ::= _Gen302 * */
  EncName_001         , /* EncName ::= _Lex106 _Gen302_any  */
  _Gen306_001         , /* _Gen306 ::= ExternalID  */
  _Gen306_002         , /* _Gen306 ::= PublicID  */
  NotationDecl_001    , /* NotationDecl ::= _Lex108 S Name S _Gen306 S_maybe _Lex060  */
  PublicID_001        , /* PublicID ::= _Lex103 S PubidLiteral  */
  _RULE_MAX
} xml_1_0_rule_t;


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
  xml_1_0p->marpaWrapperSymbolArrayLengthi = 0;
  xml_1_0p->marpaWrapperRuleArrayp = NULL;
  xml_1_0p->marpaWrapperRuleArrayLengthi = 0;

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
      if (xml_1_0p->marpaWrapperRuleArrayp != NULL) {
	free(xml_1_0p->marpaWrapperRuleArrayp);
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
  return _xml_1_0_buildSymbols_withStartb(xml_1_0p, document);
}

/**************************/
/* _xml_1_0_buildSymbols_withStartb */
/**************************/
static marpaWrapperBool_t _xml_1_0_buildSymbols_withStartb(xml_1_0_t *xml_1_0p, int starti) {
  int                        i;
  marpaWrapperSymbolOption_t marpaWrapperSymbolOption;

  xml_1_0p->marpaWrapperSymbolArrayp = malloc(_SYMBOL_MAX * sizeof(marpaWrapperSymbol_t *));
  if (xml_1_0p->marpaWrapperSymbolArrayp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }
  xml_1_0p->marpaWrapperSymbolArrayLengthi = _SYMBOL_MAX;

  for (i = 0; i < _SYMBOL_MAX; i++) {

    /* Fill default options */
    if (marpaWrapper_symbolOptionDefaultb(&marpaWrapperSymbolOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }

    /* Opaque data associated to symbol will be the symbol enum */
    marpaWrapperSymbolOption.datavp = (void *) i;

    /* Optional, but we can make ourself the terminals */
    marpaWrapperSymbolOption.terminalb = (i <= XML_1_0_TERMINAL_MAX) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;

    /* Start rule ? */
    marpaWrapperSymbolOption.startb = (i == starti) ? MARPAWRAPPER_BOOL_TRUE : MARPAWRAPPER_BOOL_FALSE;

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

  xml_1_0p->marpaWrapperRuleArrayp = malloc(_RULE_MAX * sizeof(marpaWrapperRule_t *));
  if (xml_1_0p->marpaWrapperRuleArrayp == NULL) {
    return MARPAWRAPPER_BOOL_FALSE;
  }
  xml_1_0p->marpaWrapperRuleArrayLengthi = _RULE_MAX;

  {
    /* [Misc_any_001] Misc_any ::= Misc * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[Misc]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Misc_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Misc_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[Misc_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[Misc_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [document_001] document ::= prolog element Misc_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[prolog],
      xml_1_0p->marpaWrapperSymbolArrayp[element],
      xml_1_0p->marpaWrapperSymbolArrayp[Misc_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) document_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[document];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[document_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[document_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Char_001] Char ::= _Lex001  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex001]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Char_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Char];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[Char_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[Char_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Char_002] Char ::= _Lex002  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex002]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Char_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Char];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[Char_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[Char_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Char_003] Char ::= _Lex003  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex003]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Char_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Char];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[Char_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[Char_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Char_004] Char ::= _Lex004  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex004]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Char_004;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Char];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[Char_004] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[Char_004] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Char_005] Char ::= _Lex005  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex005]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Char_005;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Char];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[Char_005] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[Char_005] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Char_006] Char ::= _Lex006  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex006]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Char_006;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Char];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[Char_006] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[Char_006] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen009_001] _Gen009 ::= _Lex007  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex007]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen009_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen009];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen009_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen009_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen009_002] _Gen009 ::= _Lex001  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex001]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen009_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen009];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen009_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen009_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen009_003] _Gen009 ::= _Lex003  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex003]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen009_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen009];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen009_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen009_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen009_004] _Gen009 ::= _Lex002  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex002]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen009_004;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen009];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen009_004] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen009_004] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen009_many_001] _Gen009_many ::= _Gen009 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen009]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen009_many_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen009_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen009_many_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen009_many_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [S_001] S ::= _Gen009_many  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen009_many]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) S_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[S];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[S_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[S_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameStartChar_001] NameStartChar ::= _Lex008  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex008]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameStartChar_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[NameStartChar_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[NameStartChar_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameStartChar_002] NameStartChar ::= _Lex009  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex009]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameStartChar_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[NameStartChar_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[NameStartChar_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameStartChar_003] NameStartChar ::= _Lex010  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex010]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameStartChar_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[NameStartChar_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[NameStartChar_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameStartChar_004] NameStartChar ::= _Lex011  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex011]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameStartChar_004;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[NameStartChar_004] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[NameStartChar_004] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameStartChar_005] NameStartChar ::= _Lex012  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex012]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameStartChar_005;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[NameStartChar_005] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[NameStartChar_005] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameStartChar_006] NameStartChar ::= _Lex013  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex013]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameStartChar_006;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[NameStartChar_006] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[NameStartChar_006] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameStartChar_007] NameStartChar ::= _Lex014  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex014]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameStartChar_007;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[NameStartChar_007] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[NameStartChar_007] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameStartChar_008] NameStartChar ::= _Lex015  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex015]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameStartChar_008;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[NameStartChar_008] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[NameStartChar_008] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameStartChar_009] NameStartChar ::= _Lex016  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex016]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameStartChar_009;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[NameStartChar_009] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[NameStartChar_009] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameStartChar_010] NameStartChar ::= _Lex017  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex017]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameStartChar_010;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[NameStartChar_010] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[NameStartChar_010] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameStartChar_011] NameStartChar ::= _Lex018  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex018]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameStartChar_011;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[NameStartChar_011] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[NameStartChar_011] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameStartChar_012] NameStartChar ::= _Lex019  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex019]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameStartChar_012;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[NameStartChar_012] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[NameStartChar_012] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameStartChar_013] NameStartChar ::= _Lex020  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex020]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameStartChar_013;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[NameStartChar_013] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[NameStartChar_013] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameStartChar_014] NameStartChar ::= _Lex021  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex021]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameStartChar_014;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[NameStartChar_014] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[NameStartChar_014] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameStartChar_015] NameStartChar ::= _Lex022  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex022]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameStartChar_015;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[NameStartChar_015] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[NameStartChar_015] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameStartChar_016] NameStartChar ::= _Lex023  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex023]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameStartChar_016;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameStartChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[NameStartChar_016] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[NameStartChar_016] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameChar_001] NameChar ::= NameStartChar  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[NameStartChar]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameChar_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[NameChar_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[NameChar_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameChar_002] NameChar ::= _Lex024  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex024]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameChar_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[NameChar_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[NameChar_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameChar_003] NameChar ::= _Lex025  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex025]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameChar_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[NameChar_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[NameChar_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameChar_004] NameChar ::= _Lex026  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex026]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameChar_004;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[NameChar_004] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[NameChar_004] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameChar_005] NameChar ::= _Lex027  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex027]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameChar_005;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[NameChar_005] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[NameChar_005] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameChar_006] NameChar ::= _Lex028  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex028]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameChar_006;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[NameChar_006] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[NameChar_006] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NameChar_007] NameChar ::= _Lex029  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex029]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NameChar_007;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NameChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[NameChar_007] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[NameChar_007] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen038_001] _Gen038 ::= NameChar  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[NameChar]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen038_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen038];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen038_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen038_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen038_any_001] _Gen038_any ::= _Gen038 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen038]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen038_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen038_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen038_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen038_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Name_001] Name ::= NameStartChar _Gen038_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[NameStartChar],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen038_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Name_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Name];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[Name_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[Name_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen041_001] _Gen041 ::= _Lex007 Name  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex007],
      xml_1_0p->marpaWrapperSymbolArrayp[Name]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen041_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen041];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen041_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen041_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen041_any_001] _Gen041_any ::= _Gen041 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen041]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen041_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen041_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen041_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen041_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Names_001] Names ::= Name _Gen041_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[Name],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen041_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Names_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Names];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[Names_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[Names_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen044_001] _Gen044 ::= NameChar  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[NameChar]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen044_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen044];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen044_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen044_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen044_many_001] _Gen044_many ::= _Gen044 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen044]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen044_many_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen044_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen044_many_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen044_many_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Nmtoken_001] Nmtoken ::= _Gen044_many  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen044_many]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Nmtoken_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Nmtoken];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[Nmtoken_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[Nmtoken_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen047_001] _Gen047 ::= _Lex007 Nmtoken  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex007],
      xml_1_0p->marpaWrapperSymbolArrayp[Nmtoken]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen047_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen047];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen047_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen047_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen047_any_001] _Gen047_any ::= _Gen047 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen047]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen047_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen047_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen047_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen047_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Nmtokens_001] Nmtokens ::= Nmtoken _Gen047_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[Nmtoken],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen047_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Nmtokens_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Nmtokens];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[Nmtokens_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[Nmtokens_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen050_001] _Gen050 ::= _Lex031  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex031]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen050_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen050];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen050_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen050_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen050_002] _Gen050 ::= PEReference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[PEReference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen050_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen050];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen050_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen050_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen050_003] _Gen050 ::= Reference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[Reference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen050_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen050];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen050_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen050_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen050_any_001] _Gen050_any ::= _Gen050 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen050]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen050_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen050_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen050_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen050_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen054_001] _Gen054 ::= _Lex033  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex033]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen054_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen054];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen054_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen054_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen054_002] _Gen054 ::= PEReference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[PEReference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen054_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen054];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen054_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen054_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen054_003] _Gen054 ::= Reference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[Reference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen054_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen054];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen054_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen054_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen054_any_001] _Gen054_any ::= _Gen054 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen054]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen054_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen054_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen054_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen054_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [EntityValue_001] EntityValue ::= _Lex030 _Gen050_any _Lex030  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex030],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen050_any],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex030]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) EntityValue_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[EntityValue];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[EntityValue_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[EntityValue_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [EntityValue_002] EntityValue ::= _Lex032 _Gen054_any _Lex032  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex032],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen054_any],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex032]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) EntityValue_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[EntityValue];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[EntityValue_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[EntityValue_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen060_001] _Gen060 ::= _Lex034  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex034]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen060_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen060];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen060_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen060_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen060_002] _Gen060 ::= Reference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[Reference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen060_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen060];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen060_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen060_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen060_any_001] _Gen060_any ::= _Gen060 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen060]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen060_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen060_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen060_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen060_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen063_001] _Gen063 ::= _Lex035  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex035]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen063_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen063];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen063_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen063_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen063_002] _Gen063 ::= Reference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[Reference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen063_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen063];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen063_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen063_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen063_any_001] _Gen063_any ::= _Gen063 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen063]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen063_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen063_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen063_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen063_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [AttValue_001] AttValue ::= _Lex030 _Gen060_any _Lex030  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex030],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen060_any],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex030]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) AttValue_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[AttValue];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[AttValue_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[AttValue_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [AttValue_002] AttValue ::= _Lex032 _Gen063_any _Lex032  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex032],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen063_any],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex032]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) AttValue_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[AttValue];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[AttValue_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[AttValue_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Lex036_any_001] _Lex036_any ::= _Lex036 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex036]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Lex036_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Lex036_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Lex036_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Lex036_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen069_001] _Gen069 ::= _Lex030 _Lex036_any _Lex030  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex030],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex036_any],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex030]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen069_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen069];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen069_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen069_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Lex037_any_001] _Lex037_any ::= _Lex037 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex037]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Lex037_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Lex037_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Lex037_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Lex037_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen071_001] _Gen071 ::= _Lex032 _Lex037_any _Lex032  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex032],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex037_any],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex032]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen071_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen071];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen071_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen071_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [SystemLiteral_001] SystemLiteral ::= _Gen069  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen069]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) SystemLiteral_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[SystemLiteral];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[SystemLiteral_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[SystemLiteral_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [SystemLiteral_002] SystemLiteral ::= _Gen071  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen071]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) SystemLiteral_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[SystemLiteral];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[SystemLiteral_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[SystemLiteral_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [PubidChar_any_001] PubidChar_any ::= PubidChar * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[PubidChar]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) PubidChar_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[PubidChar_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[PubidChar_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[PubidChar_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen075_001] _Gen075 ::= _Exclusion001  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Exclusion001]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen075_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen075];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen075_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen075_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen076_001] _Gen076 ::= _Gen075  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen075]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen076_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen076];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen076_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen076_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen076_any_001] _Gen076_any ::= _Gen076 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen076]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen076_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen076_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen076_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen076_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [PubidLiteral_001] PubidLiteral ::= _Lex030 PubidChar_any _Lex030  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex030],
      xml_1_0p->marpaWrapperSymbolArrayp[PubidChar_any],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex030]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) PubidLiteral_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[PubidLiteral];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[PubidLiteral_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[PubidLiteral_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [PubidLiteral_002] PubidLiteral ::= _Lex032 _Gen076_any _Lex032  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex032],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen076_any],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex032]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) PubidLiteral_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[PubidLiteral];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[PubidLiteral_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[PubidLiteral_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [PubidChar_001] PubidChar ::= _Lex007  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex007]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) PubidChar_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[PubidChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[PubidChar_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[PubidChar_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [PubidChar_002] PubidChar ::= _Lex003  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex003]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) PubidChar_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[PubidChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[PubidChar_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[PubidChar_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [PubidChar_003] PubidChar ::= _Lex002  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex002]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) PubidChar_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[PubidChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[PubidChar_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[PubidChar_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [PubidChar_004] PubidChar ::= _Lex038  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex038]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) PubidChar_004;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[PubidChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[PubidChar_004] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[PubidChar_004] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [PubidChar_005] PubidChar ::= _Lex039  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex039]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) PubidChar_005;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[PubidChar];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[PubidChar_005] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[PubidChar_005] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Lex040_any_001] _Lex040_any ::= _Lex040 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex040]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Lex040_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Lex040_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Lex040_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Lex040_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen086_001] _Gen086 ::= _Lex040_any _Lex041 _Lex040_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex040_any],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex041],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex040_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen086_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen086];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen086_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen086_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen087_001] _Gen087 ::= _Exclusion002  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Exclusion002]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen087_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen087];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen087_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen087_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [CharData_001] CharData ::= _Gen087  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen087]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) CharData_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[CharData];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[CharData_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[CharData_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen089_001] _Gen089 ::= _Exclusion003  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Exclusion003]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen089_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen089];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen089_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen089_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen090_001] _Gen090 ::= _Gen089  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen089]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen090_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen090];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen090_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen090_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen091_001] _Gen091 ::= _Exclusion003  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Exclusion003]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen091_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen091];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen091_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen091_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen092_001] _Gen092 ::= _Gen091  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen091]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen092_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen092];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen092_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen092_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen093_001] _Gen093 ::= _Lex024 _Gen092  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex024],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen092]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen093_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen093];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen093_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen093_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen094_001] _Gen094 ::= _Gen090  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen090]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen094_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen094];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen094_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen094_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen094_002] _Gen094 ::= _Gen093  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen093]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen094_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen094];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen094_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen094_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen094_any_001] _Gen094_any ::= _Gen094 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen094]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen094_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen094_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen094_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen094_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Comment_001] Comment ::= _Lex042 _Gen094_any _Lex043  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex042],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen094_any],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex043]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Comment_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Comment];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[Comment_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[Comment_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Char_any_001] Char_any ::= Char * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[Char]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Char_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Char_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[Char_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[Char_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen099_001] _Gen099 ::= Char_any _Lex045 Char_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[Char_any],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex045],
      xml_1_0p->marpaWrapperSymbolArrayp[Char_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen099_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen099];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen099_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen099_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen100_001] _Gen100 ::= _Exclusion004  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Exclusion004]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen100_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen100];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen100_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen100_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen101_001] _Gen101 ::= _Gen100  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen100]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen101_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen101];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen101_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen101_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen102_001] _Gen102 ::= S _Gen101  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[S],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen101]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen102_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen102];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen102_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen102_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen102_maybe_001] _Gen102_maybe ::= _Gen102  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen102]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen102_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen102_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen102_maybe_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen102_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen102_maybe_002] _Gen102_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen102_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen102_maybe];
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen102_maybe_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen102_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [PI_001] PI ::= _Lex044 PITarget _Gen102_maybe _Lex045  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex044],
      xml_1_0p->marpaWrapperSymbolArrayp[PITarget],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen102_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex045]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) PI_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[PI];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[PI_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[PI_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen106_001] _Gen106 ::= _Lex046  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex046]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen106_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen106];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen106_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen106_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen106_002] _Gen106 ::= _Lex047  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex047]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen106_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen106];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen106_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen106_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen108_001] _Gen108 ::= _Lex048  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex048]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen108_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen108];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen108_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen108_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen108_002] _Gen108 ::= _Lex049  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex049]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen108_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen108];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen108_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen108_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen110_001] _Gen110 ::= _Lex050  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex050]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen110_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen110];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen110_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen110_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen110_002] _Gen110 ::= _Lex051  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex051]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen110_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen110];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen110_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen110_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen112_001] _Gen112 ::= _Gen106 _Gen108 _Gen110  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen106],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen108],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen110]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen112_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen112];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen112_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen112_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen113_001] _Gen113 ::= _Exclusion005  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Exclusion005]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen113_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen113];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen113_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen113_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [PITarget_001] PITarget ::= _Gen113  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen113]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) PITarget_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[PITarget];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[PITarget_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[PITarget_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [CDSect_001] CDSect ::= CDStart CData CDEnd  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[CDStart],
      xml_1_0p->marpaWrapperSymbolArrayp[CData],
      xml_1_0p->marpaWrapperSymbolArrayp[CDEnd]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) CDSect_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[CDSect];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[CDSect_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[CDSect_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [CDStart_001] CDStart ::= _Lex052  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex052]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) CDStart_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[CDStart];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[CDStart_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[CDStart_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen117_001] _Gen117 ::= Char_any _Lex041 Char_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[Char_any],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex041],
      xml_1_0p->marpaWrapperSymbolArrayp[Char_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen117_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen117];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen117_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen117_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen118_001] _Gen118 ::= _Exclusion006  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Exclusion006]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen118_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen118];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen118_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen118_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen119_001] _Gen119 ::= _Gen118  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen118]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen119_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen119];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen119_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen119_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [CData_001] CData ::= _Gen119  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen119]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) CData_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[CData];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[CData_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[CData_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [CDEnd_001] CDEnd ::= _Lex041  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex041]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) CDEnd_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[CDEnd];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[CDEnd_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[CDEnd_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [XMLDecl_maybe_001] XMLDecl_maybe ::= XMLDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[XMLDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) XMLDecl_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[XMLDecl_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[XMLDecl_maybe_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[XMLDecl_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [XMLDecl_maybe_002] XMLDecl_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) XMLDecl_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[XMLDecl_maybe];
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[XMLDecl_maybe_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[XMLDecl_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen124_001] _Gen124 ::= doctypedecl Misc_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[doctypedecl],
      xml_1_0p->marpaWrapperSymbolArrayp[Misc_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen124_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen124];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen124_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen124_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen124_maybe_001] _Gen124_maybe ::= _Gen124  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen124]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen124_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen124_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen124_maybe_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen124_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen124_maybe_002] _Gen124_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen124_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen124_maybe];
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen124_maybe_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen124_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [prolog_001] prolog ::= XMLDecl_maybe Misc_any _Gen124_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[XMLDecl_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[Misc_any],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen124_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) prolog_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[prolog];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[prolog_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[prolog_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [EncodingDecl_maybe_001] EncodingDecl_maybe ::= EncodingDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[EncodingDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) EncodingDecl_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[EncodingDecl_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[EncodingDecl_maybe_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[EncodingDecl_maybe_001] == NULL) {
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
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[EncodingDecl_maybe];
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[EncodingDecl_maybe_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[EncodingDecl_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [SDDecl_maybe_001] SDDecl_maybe ::= SDDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[SDDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) SDDecl_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[SDDecl_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[SDDecl_maybe_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[SDDecl_maybe_001] == NULL) {
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
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[SDDecl_maybe];
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[SDDecl_maybe_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[SDDecl_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [S_maybe_001] S_maybe ::= S  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[S]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) S_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[S_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[S_maybe_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[S_maybe_001] == NULL) {
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
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[S_maybe];
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[S_maybe_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[S_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [XMLDecl_001] XMLDecl ::= _Lex053 VersionInfo EncodingDecl_maybe SDDecl_maybe S_maybe _Lex045  */
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
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) XMLDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[XMLDecl];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[XMLDecl_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[XMLDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen135_001] _Gen135 ::= _Lex032 VersionNum _Lex032  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex032],
      xml_1_0p->marpaWrapperSymbolArrayp[VersionNum],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex032]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen135_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen135];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen135_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen135_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen135_002] _Gen135 ::= _Lex030 VersionNum _Lex030  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex030],
      xml_1_0p->marpaWrapperSymbolArrayp[VersionNum],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex030]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen135_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen135];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen135_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen135_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [VersionInfo_001] VersionInfo ::= S _Lex054 Eq _Gen135  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[S],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex054],
      xml_1_0p->marpaWrapperSymbolArrayp[Eq],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen135]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) VersionInfo_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[VersionInfo];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[VersionInfo_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[VersionInfo_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Eq_001] Eq ::= S_maybe _Lex055 S_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex055],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Eq_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Eq];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[Eq_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[Eq_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Lex026_many_001] _Lex026_many ::= _Lex026 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex026]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Lex026_many_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Lex026_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Lex026_many_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Lex026_many_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [VersionNum_001] VersionNum ::= _Lex056 _Lex026_many  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex056],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex026_many]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) VersionNum_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[VersionNum];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[VersionNum_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[VersionNum_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Misc_001] Misc ::= Comment  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[Comment]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Misc_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Misc];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[Misc_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[Misc_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Misc_002] Misc ::= PI  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[PI]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Misc_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Misc];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[Misc_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[Misc_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Misc_003] Misc ::= S  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[S]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Misc_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Misc];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[Misc_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[Misc_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen144_001] _Gen144 ::= S ExternalID  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[S],
      xml_1_0p->marpaWrapperSymbolArrayp[ExternalID]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen144_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen144];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen144_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen144_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen144_maybe_001] _Gen144_maybe ::= _Gen144  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen144]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen144_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen144_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen144_maybe_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen144_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen144_maybe_002] _Gen144_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen144_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen144_maybe];
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen144_maybe_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen144_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen147_001] _Gen147 ::= _Lex058 intSubset _Lex059 S_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex058],
      xml_1_0p->marpaWrapperSymbolArrayp[intSubset],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex059],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen147_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen147];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen147_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen147_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen147_maybe_001] _Gen147_maybe ::= _Gen147  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen147]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen147_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen147_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen147_maybe_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen147_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen147_maybe_002] _Gen147_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen147_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen147_maybe];
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen147_maybe_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen147_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [doctypedecl_001] doctypedecl ::= _Lex057 S Name _Gen144_maybe S_maybe _Gen147_maybe _Lex060  */
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
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) doctypedecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[doctypedecl];
    marpaWrapperRuleOption.nRhsSymboli = 7;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[doctypedecl_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[doctypedecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [DeclSep_001] DeclSep ::= PEReference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[PEReference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) DeclSep_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[DeclSep];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[DeclSep_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[DeclSep_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [DeclSep_002] DeclSep ::= S  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[S]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) DeclSep_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[DeclSep];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[DeclSep_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[DeclSep_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen153_001] _Gen153 ::= markupdecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[markupdecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen153_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen153];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen153_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen153_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen153_002] _Gen153 ::= DeclSep  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[DeclSep]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen153_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen153];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen153_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen153_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen153_any_001] _Gen153_any ::= _Gen153 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen153]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen153_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen153_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen153_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen153_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [intSubset_001] intSubset ::= _Gen153_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen153_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) intSubset_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[intSubset];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[intSubset_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[intSubset_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [markupdecl_001] markupdecl ::= elementdecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[elementdecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) markupdecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[markupdecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[markupdecl_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[markupdecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [markupdecl_002] markupdecl ::= AttlistDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[AttlistDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) markupdecl_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[markupdecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[markupdecl_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[markupdecl_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [markupdecl_003] markupdecl ::= EntityDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[EntityDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) markupdecl_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[markupdecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[markupdecl_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[markupdecl_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [markupdecl_004] markupdecl ::= NotationDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[NotationDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) markupdecl_004;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[markupdecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[markupdecl_004] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[markupdecl_004] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [markupdecl_005] markupdecl ::= PI  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[PI]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) markupdecl_005;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[markupdecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[markupdecl_005] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[markupdecl_005] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [markupdecl_006] markupdecl ::= Comment  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[Comment]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) markupdecl_006;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[markupdecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[markupdecl_006] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[markupdecl_006] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [TextDecl_maybe_001] TextDecl_maybe ::= TextDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[TextDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) TextDecl_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[TextDecl_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[TextDecl_maybe_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[TextDecl_maybe_001] == NULL) {
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
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[TextDecl_maybe];
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[TextDecl_maybe_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[TextDecl_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [extSubset_001] extSubset ::= TextDecl_maybe extSubsetDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[TextDecl_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[extSubsetDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) extSubset_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[extSubset];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[extSubset_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[extSubset_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen166_001] _Gen166 ::= markupdecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[markupdecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen166_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen166];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen166_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen166_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen166_002] _Gen166 ::= conditionalSect  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[conditionalSect]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen166_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen166];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen166_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen166_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen166_003] _Gen166 ::= DeclSep  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[DeclSep]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen166_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen166];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen166_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen166_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen166_any_001] _Gen166_any ::= _Gen166 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen166]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen166_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen166_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen166_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen166_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [extSubsetDecl_001] extSubsetDecl ::= _Gen166_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen166_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) extSubsetDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[extSubsetDecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[extSubsetDecl_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[extSubsetDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen171_001] _Gen171 ::= _Lex062  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex062]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen171_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen171];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen171_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen171_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen171_002] _Gen171 ::= _Lex063  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex063]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen171_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen171];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen171_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen171_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen173_001] _Gen173 ::= _Lex032 _Gen171 _Lex032  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex032],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen171],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex032]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen173_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen173];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen173_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen173_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen174_001] _Gen174 ::= _Lex062  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex062]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen174_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen174];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen174_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen174_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen174_002] _Gen174 ::= _Lex063  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex063]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen174_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen174];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen174_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen174_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen176_001] _Gen176 ::= _Lex030 _Gen174 _Lex030  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex030],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen174],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex030]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen176_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen176];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen176_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen176_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen177_001] _Gen177 ::= _Gen173  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen173]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen177_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen177];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen177_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen177_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen177_002] _Gen177 ::= _Gen176  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen176]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen177_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen177];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen177_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen177_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [SDDecl_001] SDDecl ::= S _Lex061 Eq _Gen177  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[S],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex061],
      xml_1_0p->marpaWrapperSymbolArrayp[Eq],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen177]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) SDDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[SDDecl];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[SDDecl_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[SDDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [element_001] element ::= EmptyElemTag  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[EmptyElemTag]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) element_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[element];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[element_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[element_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [element_002] element ::= STag content ETag  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[STag],
      xml_1_0p->marpaWrapperSymbolArrayp[content],
      xml_1_0p->marpaWrapperSymbolArrayp[ETag]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) element_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[element];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[element_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[element_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen182_001] _Gen182 ::= S Attribute  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[S],
      xml_1_0p->marpaWrapperSymbolArrayp[Attribute]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen182_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen182];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen182_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen182_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen182_any_001] _Gen182_any ::= _Gen182 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen182]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen182_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen182_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen182_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen182_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [STag_001] STag ::= _Lex064 Name _Gen182_any S_maybe _Lex060  */
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
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) STag_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[STag];
    marpaWrapperRuleOption.nRhsSymboli = 5;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[STag_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[STag_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Attribute_001] Attribute ::= Name Eq AttValue  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[Name],
      xml_1_0p->marpaWrapperSymbolArrayp[Eq],
      xml_1_0p->marpaWrapperSymbolArrayp[AttValue]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Attribute_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Attribute];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[Attribute_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[Attribute_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [ETag_001] ETag ::= _Lex065 Name S_maybe _Lex060  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex065],
      xml_1_0p->marpaWrapperSymbolArrayp[Name],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex060]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) ETag_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[ETag];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[ETag_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[ETag_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [CharData_maybe_001] CharData_maybe ::= CharData  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[CharData]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) CharData_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[CharData_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[CharData_maybe_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[CharData_maybe_001] == NULL) {
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
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[CharData_maybe];
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[CharData_maybe_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[CharData_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen189_001] _Gen189 ::= element  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[element]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen189_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen189];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen189_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen189_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen189_002] _Gen189 ::= Reference  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[Reference]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen189_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen189];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen189_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen189_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen189_003] _Gen189 ::= CDSect  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[CDSect]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen189_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen189];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen189_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen189_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen189_004] _Gen189 ::= PI  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[PI]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen189_004;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen189];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen189_004] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen189_004] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen189_005] _Gen189 ::= Comment  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[Comment]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen189_005;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen189];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen189_005] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen189_005] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen194_001] _Gen194 ::= _Gen189 CharData_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen189],
      xml_1_0p->marpaWrapperSymbolArrayp[CharData_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen194_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen194];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen194_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen194_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen194_any_001] _Gen194_any ::= _Gen194 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen194]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen194_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen194_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen194_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen194_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [content_001] content ::= CharData_maybe _Gen194_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[CharData_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen194_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) content_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[content];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[content_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[content_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen197_001] _Gen197 ::= S Attribute  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[S],
      xml_1_0p->marpaWrapperSymbolArrayp[Attribute]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen197_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen197];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen197_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen197_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen197_any_001] _Gen197_any ::= _Gen197 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen197]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen197_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen197_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen197_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen197_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [EmptyElemTag_001] EmptyElemTag ::= _Lex064 Name _Gen197_any S_maybe _Lex066  */
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
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) EmptyElemTag_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[EmptyElemTag];
    marpaWrapperRuleOption.nRhsSymboli = 5;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[EmptyElemTag_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[EmptyElemTag_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [elementdecl_001] elementdecl ::= _Lex067 S Name S contentspec S_maybe _Lex060  */
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
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) elementdecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[elementdecl];
    marpaWrapperRuleOption.nRhsSymboli = 7;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[elementdecl_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[elementdecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [contentspec_001] contentspec ::= _Lex068  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex068]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) contentspec_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[contentspec];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[contentspec_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[contentspec_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [contentspec_002] contentspec ::= _Lex069  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex069]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) contentspec_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[contentspec];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[contentspec_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[contentspec_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [contentspec_003] contentspec ::= Mixed  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[Mixed]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) contentspec_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[contentspec];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[contentspec_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[contentspec_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [contentspec_004] contentspec ::= children  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[children]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) contentspec_004;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[contentspec];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[contentspec_004] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[contentspec_004] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen205_001] _Gen205 ::= choice  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[choice]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen205_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen205];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen205_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen205_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen205_002] _Gen205 ::= seq  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[seq]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen205_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen205];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen205_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen205_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen207_001] _Gen207 ::= _Lex070  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex070]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen207_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen207];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen207_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen207_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen207_002] _Gen207 ::= _Lex071  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex071]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen207_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen207];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen207_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen207_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen207_003] _Gen207 ::= _Lex072  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex072]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen207_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen207];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen207_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen207_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen207_maybe_001] _Gen207_maybe ::= _Gen207  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen207]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen207_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen207_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen207_maybe_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen207_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen207_maybe_002] _Gen207_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen207_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen207_maybe];
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen207_maybe_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen207_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [children_001] children ::= _Gen205 _Gen207_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen205],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen207_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) children_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[children];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[children_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[children_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen213_001] _Gen213 ::= Name  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[Name]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen213_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen213];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen213_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen213_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen213_002] _Gen213 ::= choice  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[choice]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen213_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen213];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen213_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen213_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen213_003] _Gen213 ::= seq  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[seq]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen213_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen213];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen213_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen213_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen216_001] _Gen216 ::= _Lex070  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex070]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen216_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen216];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen216_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen216_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen216_002] _Gen216 ::= _Lex071  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex071]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen216_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen216];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen216_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen216_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen216_003] _Gen216 ::= _Lex072  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex072]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen216_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen216];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen216_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen216_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen216_maybe_001] _Gen216_maybe ::= _Gen216  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen216]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen216_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen216_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen216_maybe_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen216_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen216_maybe_002] _Gen216_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen216_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen216_maybe];
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen216_maybe_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen216_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [cp_001] cp ::= _Gen213 _Gen216_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen213],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen216_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) cp_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[cp];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[cp_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[cp_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen222_001] _Gen222 ::= S_maybe _Lex074 S_maybe cp  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex074],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[cp]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen222_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen222];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen222_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen222_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen222_many_001] _Gen222_many ::= _Gen222 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen222]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen222_many_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen222_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen222_many_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen222_many_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [choice_001] choice ::= _Lex073 S_maybe cp _Gen222_many S_maybe _Lex075  */
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
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) choice_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[choice];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[choice_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[choice_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen225_001] _Gen225 ::= S_maybe _Lex076 S_maybe cp  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex076],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[cp]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen225_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen225];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen225_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen225_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen225_any_001] _Gen225_any ::= _Gen225 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen225]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen225_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen225_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen225_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen225_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [seq_001] seq ::= _Lex073 S_maybe cp _Gen225_any S_maybe _Lex075  */
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
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) seq_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[seq];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[seq_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[seq_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen228_001] _Gen228 ::= S_maybe _Lex074 S_maybe Name  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex074],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[Name]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen228_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen228];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen228_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen228_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen228_any_001] _Gen228_any ::= _Gen228 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen228]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen228_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen228_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen228_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen228_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Mixed_001] Mixed ::= _Lex073 S_maybe _Lex077 _Gen228_any S_maybe _Lex078  */
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
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Mixed_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Mixed];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[Mixed_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[Mixed_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Mixed_002] Mixed ::= _Lex073 S_maybe _Lex077 S_maybe _Lex075  */
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
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Mixed_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Mixed];
    marpaWrapperRuleOption.nRhsSymboli = 5;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[Mixed_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[Mixed_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [AttDef_any_001] AttDef_any ::= AttDef * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[AttDef]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) AttDef_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[AttDef_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[AttDef_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[AttDef_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [AttlistDecl_001] AttlistDecl ::= _Lex079 S Name AttDef_any S_maybe _Lex060  */
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
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) AttlistDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[AttlistDecl];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[AttlistDecl_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[AttlistDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [AttDef_001] AttDef ::= S Name S AttType S DefaultDecl  */
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
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) AttDef_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[AttDef];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[AttDef_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[AttDef_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [AttType_001] AttType ::= StringType  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[StringType]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) AttType_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[AttType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[AttType_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[AttType_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [AttType_002] AttType ::= TokenizedType  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[TokenizedType]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) AttType_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[AttType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[AttType_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[AttType_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [AttType_003] AttType ::= EnumeratedType  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[EnumeratedType]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) AttType_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[AttType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[AttType_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[AttType_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [StringType_001] StringType ::= _Lex080  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex080]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) StringType_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[StringType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[StringType_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[StringType_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [TokenizedType_001] TokenizedType ::= _Lex081  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex081]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) TokenizedType_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[TokenizedType_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[TokenizedType_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [TokenizedType_002] TokenizedType ::= _Lex082  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex082]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) TokenizedType_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[TokenizedType_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[TokenizedType_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [TokenizedType_003] TokenizedType ::= _Lex083  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex083]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) TokenizedType_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[TokenizedType_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[TokenizedType_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [TokenizedType_004] TokenizedType ::= _Lex084  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex084]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) TokenizedType_004;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[TokenizedType_004] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[TokenizedType_004] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [TokenizedType_005] TokenizedType ::= _Lex085  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex085]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) TokenizedType_005;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[TokenizedType_005] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[TokenizedType_005] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [TokenizedType_006] TokenizedType ::= _Lex086  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex086]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) TokenizedType_006;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[TokenizedType_006] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[TokenizedType_006] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [TokenizedType_007] TokenizedType ::= _Lex087  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex087]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) TokenizedType_007;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[TokenizedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[TokenizedType_007] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[TokenizedType_007] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [EnumeratedType_001] EnumeratedType ::= NotationType  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[NotationType]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) EnumeratedType_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[EnumeratedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[EnumeratedType_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[EnumeratedType_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [EnumeratedType_002] EnumeratedType ::= Enumeration  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[Enumeration]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) EnumeratedType_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[EnumeratedType];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[EnumeratedType_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[EnumeratedType_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen248_001] _Gen248 ::= S_maybe _Lex074 S_maybe Name  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex074],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[Name]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen248_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen248];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen248_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen248_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen248_any_001] _Gen248_any ::= _Gen248 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen248]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen248_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen248_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen248_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen248_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NotationType_001] NotationType ::= _Lex088 S _Lex073 S_maybe Name _Gen248_any S_maybe _Lex075  */
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
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NotationType_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NotationType];
    marpaWrapperRuleOption.nRhsSymboli = 8;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[NotationType_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[NotationType_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen251_001] _Gen251 ::= S_maybe _Lex074 S_maybe Nmtoken  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex074],
      xml_1_0p->marpaWrapperSymbolArrayp[S_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[Nmtoken]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen251_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen251];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen251_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen251_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen251_any_001] _Gen251_any ::= _Gen251 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen251]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen251_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen251_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen251_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen251_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Enumeration_001] Enumeration ::= _Lex073 S_maybe Nmtoken _Gen251_any S_maybe _Lex075  */
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
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Enumeration_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Enumeration];
    marpaWrapperRuleOption.nRhsSymboli = 6;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[Enumeration_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[Enumeration_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen254_001] _Gen254 ::= _Lex091 S  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex091],
      xml_1_0p->marpaWrapperSymbolArrayp[S]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen254_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen254];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen254_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen254_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen254_maybe_001] _Gen254_maybe ::= _Gen254  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen254]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen254_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen254_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen254_maybe_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen254_maybe_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen254_maybe_002] _Gen254_maybe ::=   */
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen254_maybe_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen254_maybe];
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen254_maybe_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen254_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen257_001] _Gen257 ::= _Gen254_maybe AttValue  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen254_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[AttValue]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen257_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen257];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen257_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen257_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [DefaultDecl_001] DefaultDecl ::= _Lex089  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex089]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) DefaultDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[DefaultDecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[DefaultDecl_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[DefaultDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [DefaultDecl_002] DefaultDecl ::= _Lex090  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex090]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) DefaultDecl_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[DefaultDecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[DefaultDecl_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[DefaultDecl_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [DefaultDecl_003] DefaultDecl ::= _Gen257  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen257]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) DefaultDecl_003;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[DefaultDecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[DefaultDecl_003] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[DefaultDecl_003] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [conditionalSect_001] conditionalSect ::= includeSect  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[includeSect]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) conditionalSect_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[conditionalSect];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[conditionalSect_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[conditionalSect_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [conditionalSect_002] conditionalSect ::= ignoreSect  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[ignoreSect]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) conditionalSect_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[conditionalSect];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[conditionalSect_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[conditionalSect_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [includeSect_001] includeSect ::= _Lex092 S_maybe _Lex093 S_maybe _Lex058 extSubsetDecl _Lex041  */
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
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) includeSect_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[includeSect];
    marpaWrapperRuleOption.nRhsSymboli = 7;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[includeSect_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[includeSect_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [ignoreSectContents_any_001] ignoreSectContents_any ::= ignoreSectContents * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[ignoreSectContents]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) ignoreSectContents_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[ignoreSectContents_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[ignoreSectContents_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[ignoreSectContents_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [ignoreSect_001] ignoreSect ::= _Lex092 S_maybe _Lex094 S_maybe _Lex058 ignoreSectContents_any _Lex041  */
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
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) ignoreSect_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[ignoreSect];
    marpaWrapperRuleOption.nRhsSymboli = 7;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[ignoreSect_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[ignoreSect_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen266_001] _Gen266 ::= _Lex092 ignoreSectContents _Lex041 Ignore  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex092],
      xml_1_0p->marpaWrapperSymbolArrayp[ignoreSectContents],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex041],
      xml_1_0p->marpaWrapperSymbolArrayp[Ignore]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen266_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen266];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen266_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen266_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen266_any_001] _Gen266_any ::= _Gen266 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen266]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen266_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen266_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen266_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen266_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [ignoreSectContents_001] ignoreSectContents ::= Ignore _Gen266_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[Ignore],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen266_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) ignoreSectContents_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[ignoreSectContents];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[ignoreSectContents_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[ignoreSectContents_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen269_001] _Gen269 ::= _Lex092  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex092]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen269_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen269];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen269_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen269_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen269_002] _Gen269 ::= _Lex041  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex041]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen269_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen269];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen269_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen269_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen271_001] _Gen271 ::= Char_any _Gen269 Char_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[Char_any],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen269],
      xml_1_0p->marpaWrapperSymbolArrayp[Char_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen271_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen271];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen271_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen271_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen272_001] _Gen272 ::= _Exclusion007  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Exclusion007]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen272_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen272];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen272_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen272_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Ignore_001] Ignore ::= _Gen272  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen272]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Ignore_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Ignore];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[Ignore_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[Ignore_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Lex098_many_001] _Lex098_many ::= _Lex098 + */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex098]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Lex098_many_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Lex098_many];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Lex098_many_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Lex098_many_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [CharRef_001] CharRef ::= _Lex095 _Lex026_many _Lex096  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex095],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex026_many],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex096]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) CharRef_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[CharRef];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[CharRef_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[CharRef_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [CharRef_002] CharRef ::= _Lex097 _Lex098_many _Lex096  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex097],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex098_many],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex096]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) CharRef_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[CharRef];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[CharRef_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[CharRef_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Reference_001] Reference ::= EntityRef  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[EntityRef]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Reference_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Reference];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[Reference_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[Reference_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [Reference_002] Reference ::= CharRef  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[CharRef]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) Reference_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[Reference];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[Reference_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[Reference_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [EntityRef_001] EntityRef ::= _Lex099 Name _Lex096  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex099],
      xml_1_0p->marpaWrapperSymbolArrayp[Name],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex096]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) EntityRef_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[EntityRef];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[EntityRef_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[EntityRef_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [PEReference_001] PEReference ::= _Lex100 Name _Lex096  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex100],
      xml_1_0p->marpaWrapperSymbolArrayp[Name],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex096]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) PEReference_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[PEReference];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[PEReference_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[PEReference_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [EntityDecl_001] EntityDecl ::= GEDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[GEDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) EntityDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[EntityDecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[EntityDecl_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[EntityDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [EntityDecl_002] EntityDecl ::= PEDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[PEDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) EntityDecl_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[EntityDecl];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[EntityDecl_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[EntityDecl_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [GEDecl_001] GEDecl ::= _Lex101 S Name S EntityDef S_maybe _Lex060  */
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
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) GEDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[GEDecl];
    marpaWrapperRuleOption.nRhsSymboli = 7;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[GEDecl_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[GEDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [PEDecl_001] PEDecl ::= _Lex101 S _Lex100 S Name S PEDef S_maybe _Lex060  */
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
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) PEDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[PEDecl];
    marpaWrapperRuleOption.nRhsSymboli = 9;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[PEDecl_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[PEDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NDataDecl_maybe_001] NDataDecl_maybe ::= NDataDecl  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[NDataDecl]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NDataDecl_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NDataDecl_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[NDataDecl_maybe_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[NDataDecl_maybe_001] == NULL) {
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
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NDataDecl_maybe];
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[NDataDecl_maybe_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[NDataDecl_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen287_001] _Gen287 ::= ExternalID NDataDecl_maybe  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[ExternalID],
      xml_1_0p->marpaWrapperSymbolArrayp[NDataDecl_maybe]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen287_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen287];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen287_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen287_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [EntityDef_001] EntityDef ::= EntityValue  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[EntityValue]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) EntityDef_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[EntityDef];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[EntityDef_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[EntityDef_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [EntityDef_002] EntityDef ::= _Gen287  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen287]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) EntityDef_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[EntityDef];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[EntityDef_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[EntityDef_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [PEDef_001] PEDef ::= EntityValue  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[EntityValue]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) PEDef_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[PEDef];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[PEDef_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[PEDef_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [PEDef_002] PEDef ::= ExternalID  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[ExternalID]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) PEDef_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[PEDef];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[PEDef_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[PEDef_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [ExternalID_001] ExternalID ::= _Lex102 S SystemLiteral  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex102],
      xml_1_0p->marpaWrapperSymbolArrayp[S],
      xml_1_0p->marpaWrapperSymbolArrayp[SystemLiteral]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) ExternalID_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[ExternalID];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[ExternalID_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[ExternalID_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [ExternalID_002] ExternalID ::= _Lex103 S PubidLiteral S SystemLiteral  */
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
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) ExternalID_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[ExternalID];
    marpaWrapperRuleOption.nRhsSymboli = 5;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[ExternalID_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[ExternalID_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NDataDecl_001] NDataDecl ::= S _Lex104 S Name  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[S],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex104],
      xml_1_0p->marpaWrapperSymbolArrayp[S],
      xml_1_0p->marpaWrapperSymbolArrayp[Name]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NDataDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NDataDecl];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[NDataDecl_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[NDataDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [VersionInfo_maybe_001] VersionInfo_maybe ::= VersionInfo  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[VersionInfo]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) VersionInfo_maybe_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[VersionInfo_maybe];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[VersionInfo_maybe_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[VersionInfo_maybe_001] == NULL) {
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
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[VersionInfo_maybe];
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[VersionInfo_maybe_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[VersionInfo_maybe_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [TextDecl_001] TextDecl ::= _Lex053 VersionInfo_maybe EncodingDecl S_maybe _Lex045  */
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
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) TextDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[TextDecl];
    marpaWrapperRuleOption.nRhsSymboli = 5;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[TextDecl_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[TextDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [extParsedEnt_001] extParsedEnt ::= TextDecl_maybe content  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[TextDecl_maybe],
      xml_1_0p->marpaWrapperSymbolArrayp[content]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) extParsedEnt_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[extParsedEnt];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[extParsedEnt_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[extParsedEnt_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen299_001] _Gen299 ::= _Lex030 EncName _Lex030  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex030],
      xml_1_0p->marpaWrapperSymbolArrayp[EncName],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex030]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen299_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen299];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen299_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen299_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen299_002] _Gen299 ::= _Lex032 EncName _Lex032  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex032],
      xml_1_0p->marpaWrapperSymbolArrayp[EncName],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex032]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen299_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen299];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen299_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen299_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [EncodingDecl_001] EncodingDecl ::= S _Lex105 Eq _Gen299  */
    marpaWrapperSymbol_t *rhsSymbolpp[4] = {
      xml_1_0p->marpaWrapperSymbolArrayp[S],
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex105],
      xml_1_0p->marpaWrapperSymbolArrayp[Eq],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen299]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) EncodingDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[EncodingDecl];
    marpaWrapperRuleOption.nRhsSymboli = 4;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[EncodingDecl_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[EncodingDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen302_001] _Gen302 ::= _Lex107  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex107]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen302_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen302];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen302_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen302_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen302_002] _Gen302 ::= _Lex024  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex024]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen302_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen302];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen302_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen302_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen302_any_001] _Gen302_any ::= _Gen302 * */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen302]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen302_any_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen302_any];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen302_any_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen302_any_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [EncName_001] EncName ::= _Lex106 _Gen302_any  */
    marpaWrapperSymbol_t *rhsSymbolpp[2] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex106],
      xml_1_0p->marpaWrapperSymbolArrayp[_Gen302_any]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) EncName_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[EncName];
    marpaWrapperRuleOption.nRhsSymboli = 2;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[EncName_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[EncName_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen306_001] _Gen306 ::= ExternalID  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[ExternalID]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen306_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen306];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen306_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen306_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [_Gen306_002] _Gen306 ::= PublicID  */
    marpaWrapperSymbol_t *rhsSymbolpp[1] = {
      xml_1_0p->marpaWrapperSymbolArrayp[PublicID]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) _Gen306_002;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[_Gen306];
    marpaWrapperRuleOption.nRhsSymboli = 1;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[_Gen306_002] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[_Gen306_002] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [NotationDecl_001] NotationDecl ::= _Lex108 S Name S _Gen306 S_maybe _Lex060  */
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
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) NotationDecl_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[NotationDecl];
    marpaWrapperRuleOption.nRhsSymboli = 7;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[NotationDecl_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[NotationDecl_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
  {
    /* [PublicID_001] PublicID ::= _Lex103 S PubidLiteral  */
    marpaWrapperSymbol_t *rhsSymbolpp[3] = {
      xml_1_0p->marpaWrapperSymbolArrayp[_Lex103],
      xml_1_0p->marpaWrapperSymbolArrayp[S],
      xml_1_0p->marpaWrapperSymbolArrayp[PubidLiteral]
    };
    if (marpaWrapper_ruleOptionDefaultb(&marpaWrapperRuleOption) == MARPAWRAPPER_BOOL_FALSE) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
    /* Opaque data associated to rule will be the lhs symbol enum */
    marpaWrapperRuleOption.datavp = (void *) PublicID_001;
    marpaWrapperRuleOption.lhsSymbolp = xml_1_0p->marpaWrapperSymbolArrayp[PublicID];
    marpaWrapperRuleOption.nRhsSymboli = 3;
    marpaWrapperRuleOption.rhsSymbolpp = rhsSymbolpp;
    /* Create the rule */
    xml_1_0p->marpaWrapperRuleArrayp[PublicID_001] = marpaWrapper_g_addRulep(xml_1_0p->marpaWrapperp, &marpaWrapperRuleOption);
    if (xml_1_0p->marpaWrapperRuleArrayp[PublicID_001] == NULL) {
      return MARPAWRAPPER_BOOL_FALSE;
    }
  }
    return MARPAWRAPPER_BOOL_TRUE;
}
