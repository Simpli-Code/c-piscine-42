/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_sed.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chruhin <chruhin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:09:41 by chruhin           #+#    #+#             */
/*   Updated: 2024/04/01 12:08:50 by chruhin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_sed.hpp"

My_Sed::My_Sed(const std::string &filename, const std::string &s1, const std::string &s2) : _filename(filename), _s1(s1), _s2(s2) {}

std::string My_Sed::replaceString(const std::string &str) const
{
	size_t end;
	std::string newStr;
	static size_t start = 0;

	while ((end = str.find(_s1, start)) != std::string::npos)
	{
		newStr += str.substr(start, end - start);
		newStr += _s2;
		start = end + _s1.length();
	}
	newStr += str.substr(start);
	if (newStr.find(_s1, start) != std::string::npos)
	{
		newStr += replaceString(newStr);
	}

	return newStr;
}

void My_Sed::replaceInFile()
{
	std::ifstream inputFile(_filename.c_str());
	if (!inputFile)
	{
		std::cerr << RED << OPEN << RST << PIN << _filename << RST << std::endl;
		return;
	}
	std::string outputFilename = _filename + ".replace";
	std::ofstream outputFile(outputFilename.c_str());
	if (!outputFile)
	{
		std::cerr << RED << CREATE << RST << PIN << outputFilename << RST << std::endl;
		if (inputFile)
			inputFile.close();
		return;
	}
	std::string line;
	std::string lines;
	while (std::getline(inputFile, line))
	{
		lines += line;
		if (!inputFile.eof())
		{
			lines += '\n';
		}
	}
	if (lines.find(_s1, 0) == std::string::npos)
	{
		std::cout << RED << NOSTR << _s1 << RST << std::endl;
		if (inputFile)
			inputFile.close();
		if (outputFile)
			outputFile.close();
		return;
	}
	outputFile << replaceString(lines);
	std::cout << YEL << COMPL << RST << PIN << outputFilename << RST << std::endl;
	if (inputFile)
		inputFile.close();
	if (outputFile)
		outputFile.close();
}
