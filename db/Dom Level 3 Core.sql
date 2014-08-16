

/* Create Tables */

-- attributes is implemented a live query DOMNode
-- childNodes is implemented a live query DOMNode
CREATE TABLE [DOMNode]
(
	[id] integer NOT NULL PRIMARY KEY AUTOINCREMENT,
	[name] text,
	[value] text,
	[nodeType] integer,
	[parent_id] integer,
	[namespaceURI] text,
	[prefix] text,
	[localName] text,
	[baseURI] text,
	[textContent] text,
	PRIMARY KEY ([id]),
	FOREIGN KEY ([parent_id])
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
	FOREIGN KEY ([ownerElement_id])
	REFERENCES [DOMElement] ([id]),
	FOREIGN KEY ([schemaTypeInfo_id])
	REFERENCES [DOMTypeInfo] ([id]),
	FOREIGN KEY ([DOMNode_id])
	REFERENCES [DOMNode] ([id])
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


CREATE TABLE [DOMStringList]
(
	[id] integer NOT NULL PRIMARY KEY AUTOINCREMENT,
	[item] text,
	[_order] integer,
	PRIMARY KEY ([id]),
	CONSTRAINT DOMStringListOrder_PK UNIQUE ([id], [_order])
);


CREATE TABLE [DOMConfiguration]
(
	[id] integer NOT NULL UNIQUE PRIMARY KEY AUTOINCREMENT,
	[parameterNames_id] integer NOT NULL,
	PRIMARY KEY ([id]),
	FOREIGN KEY ([parameterNames_id])
	REFERENCES [DOMStringList] ([id])
);


CREATE TABLE [DOMImplementation]
(
	[id] integer NOT NULL UNIQUE PRIMARY KEY AUTOINCREMENT,
	[feature] text,
	[version] text,
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
	FOREIGN KEY ([documentElement_id])
	REFERENCES [DOMElement] ([id]),
	FOREIGN KEY ([implementation_id])
	REFERENCES [DOMImplementation] ([id]),
	FOREIGN KEY ([DOMNode_id])
	REFERENCES [DOMNode] ([id]),
	FOREIGN KEY ([doctype_id])
	REFERENCES [DOMDocumentType] ([id])
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


CREATE TABLE [DOMImplementationList]
(
	[id] integer NOT NULL PRIMARY KEY AUTOINCREMENT,
	[DOMImplementation_id] integer NOT NULL UNIQUE,
	[_order] integer,
	PRIMARY KEY ([id]),
	FOREIGN KEY ([DOMImplementation_id])
	REFERENCES [DOMImplementation] ([id]),
	CONSTRAINT DOMImplementationList_PK UNIQUE ([id], [_order])
);


CREATE TABLE [DOMImplementationSource]
(
	[id] integer NOT NULL UNIQUE PRIMARY KEY AUTOINCREMENT,
	[DOMImplementation_id] integer NOT NULL UNIQUE,
	[DOMImplementationList_id] integer NOT NULL UNIQUE,
	PRIMARY KEY ([id]),
	FOREIGN KEY ([DOMImplementationList_id])
	REFERENCES [DOMImplementationList] ([id]),
	FOREIGN KEY ([DOMImplementation_id])
	REFERENCES [DOMImplementation] ([id])
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
	FOREIGN KEY ([DOMConfiguration_id])
	REFERENCES [DOMConfiguration] ([id]),
	FOREIGN KEY ([DOMUserDataParameter_id])
	REFERENCES [DomUserDataParameter] ([id])
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



