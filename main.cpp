#include <iostream>
#include <fstream>

#include "TextQuery.h"
#include "TextResult.h"
class TestTextQuerty {
public:
	/*≤‚ ‘≤È—Ø*/
	void testTextQuery() const;
private:
	void runQuery(std::ifstream& infile) const;

};

int main() {
	std::cout << "-------------------------------Text Query-------------------------------" << std::endl;
	try
	{
		TestTextQuerty test;
		test.testTextQuery();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}

void TestTextQuerty::testTextQuery() const
{
	std::ifstream infile("E:/code/C++/c++Primer/mtjCode/TextQuery/in.data");
	runQuery(infile);
	infile.close();
}

void TestTextQuerty::runQuery(std::ifstream& infile) const
{
	TextQuery tq(infile);
	std::string s;

	for (;;) {
		std::cout << "enter word to look for, or q to quit: ";
		if (!(std::cin >> s) || s == "q") break;
		print(std::cout, tq.query(s)) << std::endl;
	}
}
