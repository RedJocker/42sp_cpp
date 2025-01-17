// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   megaphone.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: maurodri <maurodri@student.42sp...>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2024/12/12 17:38:34 by maurodri          #+#    #+#             //
//   Updated: 2024/12/13 18:15:20 by maurodri         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <cctype>
#include <string>

std::string& str_transform(std::string &str, int (*char_fun) (int c))
{
	size_t	j;

	j = -1;
	while (++j < str.length())
		str.at(j) = char_fun(static_cast<unsigned char>(str.at(j)));
	return str;
}

int main(int argc, char *argv[])
{
  int			i;
  std::string 	str;

  if (argc == 1)
  {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return (0);
  }
  i = 0;
  while (++i < argc)
  {
	str = argv[i];
	std::cout << str_transform(str, std::toupper);
  }
  std::cout << std::endl;
  return (0);
}
