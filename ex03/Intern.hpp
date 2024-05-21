/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:08:58 by okraus            #+#    #+#             */
/*   Updated: 2024/05/21 15:23:47 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef INTEERN_HPP
# define INTEERN_HPP
# include <iostream>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

# define LOWGRADE 150
# define HIGHGRADE 1

class AForm;

class Intern
{
	public:
		Intern(void);
		Intern(const Intern& copy);
		Intern &operator=(const Intern& c);
		~Intern(void);

		AForm*	makeForm(std::string form, std::string target);
		AForm*	createForm(std::string form, std::string target);
		
		class FormNotRealException : public std::exception
		{
			public:
				const char*		what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &o, const Intern &b);

#endif