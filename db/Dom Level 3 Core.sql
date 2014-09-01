

/* Create Tables */

-- attributes is implemented a live query DOMNode
-- childNodes is implemented a live query DOMNode
CREATE TABLE [DOMNode]
(
	[id] integer NOT NULL UNIQUE PRIMARY KEY AUTOINCREMENT,
	[name] text,
	[value] text,
	[nodeType] integer,
	[parent_id] integer,
	[namespaceURI] text,
	[prefix] text,
	[localName] text,
	[baseURI] text,
	[textContent] text,
	[prevId] integer,
	[nextId] integer,
	PRIMARY KEY ([id]),
	FOREIGN KEY ([nextId])
	REFERENCES [DOMNode] ([id]),
	FOREIGN KEY ([parent_id])
	REFERENCES [DOMNode] ([id]),
	FOREIGN KEY ([prevId])
	REFERENCES [DOMNode] ([id])
);


-- getElementsByTagName is a view on top of DOMNode
-- getElementsByTagNameNS is a view on top of DOMNode
CREATE TABLE [DOMElement]
(
	[id] integer NOT NULL UNIQUE PRIMARY KEY AUTOINCREMENT,
	[DOMNode_id] integer NOT NULL UNIQUE,
	[tagName] text,
	PRIMARY KEY ([id]),
	FOREIGN KEY ([DOMNode_id])
	REFERENCES [DOMNode] ([id])
);


CREATE TABLE [DOMTypeInfo]
(
	[id] integer NOT NULL UNIQUE PRIMARY KEY AUTOINCREMENT,
	[typeName] text,
	[typeNamespace] text,
	PRIMARY KEY ([id])
);


CREATE TABLE [DOMAttr]
(
	[id] integer NOT NULL UNIQUE PRIMARY KEY AUTOINCREMENT,
	[DOMNode_id] integer NOT NULL UNIQUE,
	[name] text,
	[specified] integer,
	[value] text,
	[ownerElement_id] integer NOT NULL UNIQUE,
	[isId] integer,
	[schemaTypeInfo_id] integer NOT NULL UNIQUE,
	PRIMARY KEY ([id]),
	FOREIGN KEY ([DOMNode_id])
	REFERENCES [DOMNode] ([id]),
	FOREIGN KEY ([ownerElement_id])
	REFERENCES [DOMElement] ([id]),
	FOREIGN KEY ([schemaTypeInfo_id])
	REFERENCES [DOMTypeInfo] ([id])
);


CREATE TABLE [DOMCharacterData]
(
	[id] integer NOT NULL UNIQUE PRIMARY KEY AUTOINCREMENT,
	[DOMNode_id] integer NOT NULL UNIQUE,
	[data] text,
	[length] integer,
	PRIMARY KEY ([id]),
	FOREIGN KEY ([DOMNode_id])
	REFERENCES [DOMNode] ([id])
);


CREATE TABLE [DOMText]
(
	[id] integer NOT NULL UNIQUE PRIMARY KEY AUTOINCREMENT,
	[DOMCharacterData_id] integer NOT NULL UNIQUE,
	[isElementContentWhitespace] integer,
	[wholeText] text,
	PRIMARY KEY ([id]),
	FOREIGN KEY ([DOMCharacterData_id])
	REFERENCES [DOMCharacterData] ([id])
);


CREATE TABLE [DOMCDATASection]
(
	[id] integer NOT NULL UNIQUE PRIMARY KEY AUTOINCREMENT,
	[DOMText_id] integer NOT NULL UNIQUE,
	PRIMARY KEY ([id]),
	FOREIGN KEY ([DOMText_id])
	REFERENCES [DOMText] ([id])
);


CREATE TABLE [DOMComment]
(
	[id] integer NOT NULL UNIQUE PRIMARY KEY AUTOINCREMENT,
	[DOMCharacterData_id] integer NOT NULL UNIQUE,
	PRIMARY KEY ([id]),
	FOREIGN KEY ([DOMCharacterData_id])
	REFERENCES [DOMCharacterData] ([id])
);


-- Because DOM spec says item should be unique, no need for hashing here.
-- In theory a castastrophy to index on a TEXT, in practice, there is absolutely NO problem because we talk about a very small table, with very small values.
-- In addition, DOM does NOT provide DELETE on this data, i.e. id is enough for ordering (could have used item as well)
CREATE TABLE [DOMString]
(
	[id] integer NOT NULL PRIMARY KEY AUTOINCREMENT,
	[item] text,
	PRIMARY KEY ([id])
);


CREATE TABLE [DOMConfiguration]
(
	[id] integer NOT NULL UNIQUE PRIMARY KEY AUTOINCREMENT,
	[parameterNames_id] integer NOT NULL,
	PRIMARY KEY ([id]),
	FOREIGN KEY ([parameterNames_id])
	REFERENCES [DOMString] ([id])
);


CREATE TABLE [DOMCounters]
(
	[id] integer NOT NULL UNIQUE PRIMARY KEY AUTOINCREMENT,
	[objectName] text,
	[objectCount] integer,
	PRIMARY KEY ([id])
);


-- entities and notations are implemented like a view on DOMNode
CREATE TABLE [DOMDocumentType]
(
	[id] integer NOT NULL UNIQUE PRIMARY KEY AUTOINCREMENT,
	[name] text,
	[publicId] text,
	[systemId] text,
	[internalSubset] text,
	[DOMNode_id] integer NOT NULL UNIQUE,
	PRIMARY KEY ([id]),
	FOREIGN KEY ([DOMNode_id])
	REFERENCES [DOMNode] ([id])
);


CREATE TABLE [DOMImplementation]
(
	[id] integer NOT NULL UNIQUE PRIMARY KEY AUTOINCREMENT,
	[feature] text,
	[version] text,
	PRIMARY KEY ([id])
);


-- getElementsByTagName is a live query DOMNode
-- getElementsByTagNameNS is a live query DOMNode
CREATE TABLE [DOMDocument]
(
	[id] integer NOT NULL UNIQUE PRIMARY KEY AUTOINCREMENT,
	[DOMNode_id] integer NOT NULL UNIQUE,
	[doctype_id] integer NOT NULL UNIQUE,
	[implementation_id] integer NOT NULL UNIQUE,
	[documentElement_id] integer NOT NULL UNIQUE,
	[inputEncoding] text,
	[xmlEncoding] text,
	[xmlStandalone] integer,
	[xmlVersion] text,
	[strictErrorChecking] integer,
	[documentURI] text,
	[domConfig_id] integer NOT NULL UNIQUE,
	PRIMARY KEY ([id]),
	FOREIGN KEY ([domConfig_id])
	REFERENCES [DOMConfiguration] ([id]),
	FOREIGN KEY ([DOMNode_id])
	REFERENCES [DOMNode] ([id]),
	FOREIGN KEY ([documentElement_id])
	REFERENCES [DOMElement] ([id]),
	FOREIGN KEY ([doctype_id])
	REFERENCES [DOMDocumentType] ([id]),
	FOREIGN KEY ([implementation_id])
	REFERENCES [DOMImplementation] ([id])
);


CREATE TABLE [DOMDocumentFragment]
(
	[id] integer NOT NULL UNIQUE PRIMARY KEY AUTOINCREMENT,
	[DOMNode_id] integer NOT NULL UNIQUE,
	PRIMARY KEY ([id]),
	FOREIGN KEY ([DOMNode_id])
	REFERENCES [DOMNode] ([id])
);


CREATE TABLE [DOMEntity]
(
	[id] integer NOT NULL UNIQUE,
	[DOMNode_id] integer NOT NULL UNIQUE,
	[publicId] text,
	[systemId] text,
	[notationName] text,
	[inputEncoding] text,
	[xmlEncoding] text,
	[xmlVersion] text,
	PRIMARY KEY ([id]),
	FOREIGN KEY ([DOMNode_id])
	REFERENCES [DOMNode] ([id])
);


CREATE TABLE [DOMEntityReference]
(
	[id] integer NOT NULL UNIQUE PRIMARY KEY AUTOINCREMENT,
	[DOMNode_id] integer NOT NULL UNIQUE,
	PRIMARY KEY ([id]),
	FOREIGN KEY ([DOMNode_id])
	REFERENCES [DOMNode] ([id])
);


CREATE TABLE [DOMLocator]
(
	[id] integer NOT NULL UNIQUE PRIMARY KEY AUTOINCREMENT,
	[lineNumber] integer,
	[columnNumber] integer,
	[byteOffset] integer,
	[utf16Offset] integer,
	[relatedNode_id] integer NOT NULL UNIQUE,
	[uri] text,
	PRIMARY KEY ([id]),
	FOREIGN KEY ([relatedNode_id])
	REFERENCES [DOMNode] ([id])
);


CREATE TABLE [DOMException]
(
	[id] integer NOT NULL PRIMARY KEY AUTOINCREMENT,
	[code] integer,
	[message] text,
	PRIMARY KEY ([id])
);


CREATE TABLE [DOMError]
(
	[id] integer NOT NULL UNIQUE PRIMARY KEY AUTOINCREMENT,
	[severity] integer,
	[message] text,
	[_type] text,
	[relatedException_id] integer NOT NULL UNIQUE,
	[relatedData_id] integer NOT NULL UNIQUE,
	[location_id] integer NOT NULL UNIQUE,
	PRIMARY KEY ([id]),
	FOREIGN KEY ([relatedData_id])
	REFERENCES [DOMNode] ([id]),
	FOREIGN KEY ([location_id])
	REFERENCES [DOMLocator] ([id]),
	FOREIGN KEY ([relatedException_id])
	REFERENCES [DOMException] ([id])
);


CREATE TABLE [DOMImplementationSource]
(
	[id] integer NOT NULL UNIQUE PRIMARY KEY AUTOINCREMENT,
	[DOMImplementation_id] integer NOT NULL UNIQUE,
	PRIMARY KEY ([id]),
	FOREIGN KEY ([DOMImplementation_id])
	REFERENCES [DOMImplementation] ([id])
);


CREATE TABLE [DOMNotation]
(
	[id] integer NOT NULL UNIQUE PRIMARY KEY AUTOINCREMENT,
	[DOMNode_id] integer NOT NULL UNIQUE,
	[publicId] text,
	[systemId] text,
	PRIMARY KEY ([id]),
	FOREIGN KEY ([DOMNode_id])
	REFERENCES [DOMNode] ([id])
);


CREATE TABLE [DOMProcessingInstruction]
(
	[id] integer NOT NULL UNIQUE PRIMARY KEY AUTOINCREMENT,
	[DOMNode_id] integer NOT NULL UNIQUE,
	[target] text,
	[data] text,
	PRIMARY KEY ([id]),
	FOREIGN KEY ([DOMNode_id])
	REFERENCES [DOMNode] ([id])
);


CREATE TABLE [DOMUserDataHandler]
(
	[id] integer NOT NULL UNIQUE PRIMARY KEY AUTOINCREMENT,
	[handle] integer,
	PRIMARY KEY ([id])
);


CREATE TABLE [DOMUserDataKey]
(
	[id] integer NOT NULL UNIQUE PRIMARY KEY AUTOINCREMENT,
	[string] text,
	[data] integer,
	[DOMUserDataHandler_id] integer NOT NULL UNIQUE,
	PRIMARY KEY ([id]),
	FOREIGN KEY ([DOMUserDataHandler_id])
	REFERENCES [DOMUserDataHandler] ([id])
);


CREATE TABLE [DomUserDataParameter]
(
	[id] integer NOT NULL UNIQUE PRIMARY KEY AUTOINCREMENT,
	[name] text,
	[DOMUserDataHandler_id] integer NOT NULL UNIQUE,
	PRIMARY KEY ([id]),
	FOREIGN KEY ([DOMUserDataHandler_id])
	REFERENCES [DOMUserDataHandler] ([id])
);


CREATE TABLE [RDOMConfigurationUserDataParameter]
(
	[DOMUserDataParameter_id] integer NOT NULL UNIQUE,
	[DOMConfiguration_id] integer NOT NULL UNIQUE,
	FOREIGN KEY ([DOMUserDataParameter_id])
	REFERENCES [DomUserDataParameter] ([id]),
	FOREIGN KEY ([DOMConfiguration_id])
	REFERENCES [DOMConfiguration] ([id])
);


CREATE TABLE [RDOMNodeUserDataKey]
(
	[DOMUserDataKey_id] integer NOT NULL UNIQUE,
	[DOMNode_id] integer NOT NULL UNIQUE,
	FOREIGN KEY ([DOMNode_id])
	REFERENCES [DOMNode] ([id]),
	FOREIGN KEY ([DOMUserDataKey_id])
	REFERENCES [DOMUserDataKey] ([id])
);



/* Create Views */

CREATE VIEW [DOMImplementationList] AS [select *, (select count(*) from DOMImplementation b where a.id >= b.id) as _order from DOMImplementation a];
CREATE VIEW [DOMNodeList] AS [select *, (select count(*) from DOMNode b where a.id >= b.id) as _order from DOMNode a];
CREATE VIEW [DOMStringList] AS [select *, (select count(*) from DOMString b where a.id >= b.id) as _order from DOMString a];



