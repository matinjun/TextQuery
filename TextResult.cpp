#include "TextResult.h"

std::ostream& print(std::ostream& os, const TextResult& textResult)
{
	os << "element occurs " << textResult.lines->size() << " times" << std::endl;
	for (auto i : (*textResult.lines)) {
		os << std::endl << "(line " << i << ")";
		for (auto str : (*textResult.content)[i]) {
			os << " " << str;
		}
		os << std::endl;
	}
	return os;
}
