#pragma once
#include <string>
class CAssistant {
public:
	CAssistant() {};

	// xml
	static void TinyXmlSerialize();
	static void TinyXmlDeSerialize();

	// json
	static void JsoncppSerialize();
	static void JsoncppDeSerialize();

};