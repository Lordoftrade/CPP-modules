#include "replace.hpp"

Replace::Replace(const std::string& line, const std::string& s1_, const  std::string& s2_) : filename(line), s1(s1_), s2(s2_) {}

std::string Replace::replace_s1_to_s2(const std::string& line, const std::string& s1, const  std::string& s2) const
{
	std::string finishLine;
	size_t position = 0;
	size_t entryFound;

	entryFound = line.find(s1, position);
	while (entryFound != std::string::npos)
	{
		finishLine.append(line, position, entryFound - position);
		finishLine.append(s2);
		position = entryFound + s1.length();
		entryFound = line.find(s1, position);
	}

	finishLine.append(line, position, std::string::npos);
	return (finishLine);
}

bool Replace::check_and_open() const
{
	if (filename.empty())
	{
		std::cerr << "Error: FILE EMPTY" << std::endl;
		return false;
	}

	if (s1.empty())
	{
		std::cerr << "Error: The search string (s1) cannot be empty." << std::endl;
		return false;
	}

	std::ifstream infile(filename.c_str());

	if (!infile.is_open())
	{
		std::cerr << "Error: Cannot open file " << filename << std::endl;
		return false;
	}

	std::ofstream outfile((filename + ".replace").c_str());

	if (!outfile.is_open())
	{
		std::cerr << "Error: Cannot create output file " << filename << ".replace" << std::endl;
		infile.close();
		return false;
	}

	std::string line;
	while (std::getline(infile, line))
	{
		outfile << replace_s1_to_s2(line, s1, s2) << std::endl;
	}

	infile.close();
	outfile.close();

	return true;
}
