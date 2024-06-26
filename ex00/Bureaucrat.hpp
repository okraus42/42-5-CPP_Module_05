/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:08:58 by okraus            #+#    #+#             */
/*   Updated: 2024/05/19 11:34:27 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>

# define LOWGRADE 150
# define HIGHGRADE 1

class Bureaucrat
{
	private:
		const std::string	_name;
		unsigned int		_grade;

	public:
		Bureaucrat(void);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat &operator=(const Bureaucrat& c);
		~Bureaucrat(void);

		Bureaucrat(const std::string name, unsigned int grade);

		unsigned int	getGrade(void) const;
		std::string		getName(void) const;

		void			increment(void);
		void			decrement(void);

		class GradeTooHighException : public std::exception
		{
			public:
				const char*		what() const throw();
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				const char*		what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &b);

#endif