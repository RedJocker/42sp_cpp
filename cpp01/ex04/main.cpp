// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42.fr>          +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2025/01/17 19:48:54 by maurodri          #+#    #+#             //
/*   Updated: 2025/01/23 21:59:25 by maurodri         ###   ########.fr       */
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <fstream>
#include <string>

// Create a program that takes three parameters in the following order: a filename and
// two strings, s1 and s2.
// It will open the file <filename> and copies its content into a new file
// <filename>.replace, replacing every occurrence of s1 with s2.
// Using C file manipulation functions is forbidden and will be considered cheating. All
// the member functions of the class std::string are allowed, except replace. Use them
// wisely!
// Of course, handle unexpected inputs and errors. You have to create and turn in your
// own tests to ensure your program works as expected.

void sed()
{
	
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Invalid number of arguments" << std::endl
		          << "Usage: wsed <filename> <target> <replacement>" << std::endl;
		return (1);
	}
	const std::string filename = argv[1];
	const std::string target = argv[2];
	const std::string replacement = argv[3];

	std::ifstream file_in;
	file_in.open(filename.c_str());
	if (!file_in.is_open())
	{
		std::cout << "could not open file with filename " << filename << std::endl;
		return (2);
	}
	std::string out_filename = filename + ".replacement";
	std::ofstream file_out;
	file_out.open(out_filename.c_str());
	if (!file_out.is_open())
	{
		std::cout << "could not open file with filename " << out_filename << std::endl;
		return (2);
	}
	std::string input_line;
	while (std::getline(file_in, input_line))
	{
		std::string::size_type cur = 0;
		while (1)
		{
			std::string::size_type next = input_line.find(target, cur);
			std::string out;
			if (next == std::string::npos) {
				out = input_line.substr(cur);
				file_out << out;
				break;
			}
			else
			{
				out = input_line.substr(cur, next - cur);
				file_out << out
						 << replacement;
			}
			cur = next + target.length();
		}
		if (file_in.eof())
			break;
		file_out << std::endl;
	}
	file_in.close();
	file_out.close();
	return (0);
}
